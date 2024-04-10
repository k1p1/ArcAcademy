// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAbility.h"

bool UBaseAbility::Activate(FVector Location)
{
  UWorld* World = GetWorld();
  if (IsValid(World) == false)
  {
    return false;
  }

  if (IsInCooldown)
  {
    return false;
  }
  
  IsInCooldown = true;

  if (CooldownTime == 0.0f)
  {
    OnCooldownTimerEnded();
  }
  else
  {
    World->GetTimerManager().SetTimer(CooldownTimerHandle, this, &UBaseAbility::OnCooldownTimerEnded, CooldownTime);
  }
  return true;
}

void UBaseAbility::OnCooldownTimerEnded()
{
  IsInCooldown = false;
}
