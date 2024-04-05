// Fill out your copyright notice in the Description page of Project Settings.


#include "WinTrigger.h"
#include "../ArcAcademyGameMode.h"

void AWinTrigger::ActionStart(AActor* InTarget)
{
	AArcAcademyGameMode* GameMode = Cast<AArcAcademyGameMode>(GetWorld()->GetAuthGameMode());
	if (IsValid(GameMode))
	{
		GameMode->EndGame(true);
	}
}