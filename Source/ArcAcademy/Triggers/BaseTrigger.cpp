// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTrigger.h"
#include "../ArcAcademyCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseTrigger::ABaseTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AArcAcademyCharacter::StaticClass(), Actors);
	if (Actors.Num() > 0)
	{
		Target = Actors[0];
	}

	FTimerHandle CustomTickTimerHandle;

	UWorld* World = GetWorld();
	if (IsValid(World))
	{
		World->GetTimerManager().SetTimer(CustomTickTimerHandle, this, &ABaseTrigger::CustomTick, CustomTickRate, true);
	}
}

void ABaseTrigger::Action(AActor* InTarget)
{

}

void ABaseTrigger::CustomTick()
{
	if (IsValid(Target))
	{
		if ((GetActorLocation() - Target->GetActorLocation()).Length() < Range)
		{
			Action(Target);
		}
	}
}

// Called every frame
void ABaseTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

