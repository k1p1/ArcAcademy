// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageTrigger.h"
#include "Engine/DamageEvents.h"


void ADamageTrigger::ActionStart(AActor* InTarget)
{
  Target = InTarget;
  UWorld* World = GetWorld();
  if (IsValid(World))
  {
    World->GetTimerManager().SetTimer(DamageTimerHandle, this, &ADamageTrigger::DamageTick, DamageTickRate, true);
  }
}

void ADamageTrigger::ActionEnd(AActor* InTarget)
{
  Target = nullptr;
  UWorld* World = GetWorld();
  if (IsValid(World))
  {
    World->GetTimerManager().ClearTimer(DamageTimerHandle);
  }
}

void ADamageTrigger::DamageTick()
{
  if (IsValid(Target))
  {
    Target->TakeDamage(Damage, FDamageEvent(UDamageType::StaticClass()), nullptr, nullptr);
  }
}
