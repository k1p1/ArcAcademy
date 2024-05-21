// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArcAcademyCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "Abilities/BaseAbility.h"
#include "ArcAcademyGameMode.h"
#include "ArcAcademyPlayerController.h"
#include "ArcAcademy.h"
#include "UI/Healthbar.h"

AArcAcademyCharacter::AArcAcademyCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetCastShadow(false);
	WidgetComponent->SetReceivesDecals(false);
	WidgetComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WidgetComponent->SetupAttachment(RootComponent);

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	OnTakeAnyDamage.AddDynamic(this, &AArcAcademyCharacter::TakeAnyDamage);
}

void AArcAcademyCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (IsValid(WidgetComponent->GetWidgetClass()))
	{
		WidgetComponent->InitWidget();
		HealthbarWidget = Cast<UHealthbar>(WidgetComponent->GetUserWidgetObject());
	}
}

void AArcAcademyCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilityInstance = NewObject<UBaseAbility>(this, AbilityTemplate);

	if (IsValid(HealthbarWidget))
	{
		float HealthPercent = Health / MaxHealth;
		HealthbarWidget->SetPercent(HealthPercent);
	}
}

void AArcAcademyCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

		UWorld* World = GetWorld();
		if (IsValid(World))
		{
			FHitResult HitResult;
			FVector TraceStartLocation = GetActorLocation();
			FVector TraceEndLocation = GetActorLocation() + GetActorForwardVector() * 300.0f;
			FCollisionQueryParams Params;
			Params.AddIgnoredActor(this);
			if (World->LineTraceSingleByChannel(HitResult, TraceStartLocation, TraceEndLocation, ECollisionChannel::ECC_WorldDynamic, Params))
			{
				UE_LOG(LogArcAcademy, Log, TEXT("TraceHit Actor: %s, Component: %s"), *HitResult.GetActor()->GetName(), *HitResult.GetComponent()->GetName());
			}
		}

}

void AArcAcademyCharacter::ActivateAbility(FVector Location)
{
	if (IsValid(AbilityInstance))
	{
		AbilityInstance->Activate(Location);
	}
}

void AArcAcademyCharacter::TakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	Health -= Damage;
	UE_LOG(LogArcAcademy, Log, TEXT("Health %f"), Health);
	if (IsValid(HealthbarWidget))
	{
		float HealthPercent = Health / MaxHealth;
		HealthbarWidget->SetPercent(HealthPercent);
	}
	if (Health <= 0.0f)
	{
		Death();
	}
}

void AArcAcademyCharacter::Death()
{
	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		return;
	}

	AArcAcademyGameMode* GameMode = Cast<AArcAcademyGameMode>(GetWorld()->GetAuthGameMode());
	if (IsValid(GameMode))
	{
		GameMode->EndGame(false);
	}

	AArcAcademyPlayerController* PlayerController = Cast<AArcAcademyPlayerController>(GetController());
	if (IsValid(PlayerController))
	{
		PlayerController->OnPlayerDied();
	}

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	FVector Location = GetActorLocation();
	FRotator Rotation = GetActorRotation();
	AActor* AfterDeathActor = World->SpawnActor(AfterDeathSpawnActorClass, &Location, &Rotation, SpawnParameters);
	if (IsValid(AfterDeathActor) == false)
	{
		UE_LOG(LogArcAcademy, Log, TEXT("IsValid(AfterDeathActor) == false"));
	}
	Destroy();
}
