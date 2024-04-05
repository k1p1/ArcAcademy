// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowTrigger.h"
#include "../ArcAcademyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void ASlowTrigger::ActionStart(AActor* InTarget)
{
  AArcAcademyCharacter* Character = Cast<AArcAcademyCharacter>(InTarget);
  if (IsValid(Character))
  {
    UCharacterMovementComponent* MovementComponent = Character->GetCharacterMovement();
    if (IsValid(MovementComponent))
    {
      TargetMaxWalkSpeed = MovementComponent->MaxWalkSpeed;
      MovementComponent->MaxWalkSpeed = MaxWalkSpeed;
    }
  }
}

void ASlowTrigger::ActionEnd(AActor* InTarget)
{
  AArcAcademyCharacter* Character = Cast<AArcAcademyCharacter>(InTarget);
  if (IsValid(Character))
  {
    UCharacterMovementComponent* MovementComponent = Character->GetCharacterMovement();
    if (IsValid(MovementComponent))
    {
      MovementComponent->MaxWalkSpeed = TargetMaxWalkSpeed;
    }
  }
}
