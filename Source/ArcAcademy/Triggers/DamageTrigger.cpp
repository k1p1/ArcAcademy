// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageTrigger.h"
#include "Engine/DamageEvents.h"


void ADamageTrigger::Action(AActor* InTarget)
{
  InTarget->TakeDamage(Damage, FDamageEvent(UDamageType::StaticClass()), nullptr, nullptr);
}