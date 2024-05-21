// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ArcAcademyHUD.generated.h"

/**
 * 
 */
UCLASS()
class ARCACADEMY_API AArcAcademyHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	void ShowEndGameScreen();

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UEndGameWidget> EndGameWidgetClass;

	UPROPERTY()
	class UEndGameWidget* EndGameWidget;
};
