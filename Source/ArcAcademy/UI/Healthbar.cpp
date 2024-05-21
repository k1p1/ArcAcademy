// Fill out your copyright notice in the Description page of Project Settings.


#include "Healthbar.h"
#include "Components/ProgressBar.h"

void UHealthbar::SetPercent(float InPercent)
{
  float Percent = FMath::Max(FMath::Min(InPercent, 1.0), 0.0f);
  HealthProgressBar->SetPercent(Percent);
}