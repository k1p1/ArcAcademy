// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArcAcademyGameMode.h"
#include "ArcAcademyPlayerController.h"
#include "ArcAcademyCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "ArcAcademy.h"

AArcAcademyGameMode::AArcAcademyGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AArcAcademyPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}

void AArcAcademyGameMode::EndGame(bool IsWin)
{
	if (IsWin)
	{
		UE_LOG(LogArcAcademy, Log, TEXT("Win"));
	}
	else
	{
		UE_LOG(LogArcAcademy, Log, TEXT("Lose"));
	}
}
