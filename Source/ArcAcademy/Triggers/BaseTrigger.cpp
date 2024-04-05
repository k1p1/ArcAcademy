// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTrigger.h"
#include "../ArcAcademyCharacter.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseTrigger::ABaseTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollisionComponent"));
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	SphereComponent->SetupAttachment(RootComponent);

	SphereComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &ABaseTrigger::OnBeginOverlap);
	SphereComponent->OnComponentEndOverlap.AddUniqueDynamic(this, &ABaseTrigger::OnEndOverlap);
}

// Called when the game starts or when spawned
void ABaseTrigger::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseTrigger::ActionStart(AActor* InTarget)
{

}

void ABaseTrigger::ActionEnd(AActor* InTarget)
{

}

void ABaseTrigger::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ActionStart(Other);
}

void ABaseTrigger::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ActionEnd(Other);
}

