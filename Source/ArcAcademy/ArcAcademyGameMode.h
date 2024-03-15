// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ArcAcademyGameMode.generated.h"

UCLASS(minimalapi)
class AArcAcademyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AArcAcademyGameMode();
	void EndGame(bool IsWin);
};



