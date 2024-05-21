// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Healthbar.generated.h"

/**
 * 
 */
UCLASS()
class ARCACADEMY_API UHealthbar : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthProgressBar;

public:
	void SetPercent(float InPercent);
	
};
