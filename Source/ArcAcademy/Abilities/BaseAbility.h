// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseAbility.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ARCACADEMY_API UBaseAbility : public UObject
{
	GENERATED_BODY()

public:
	virtual bool Activate(FVector Location);
	
private:
	UFUNCTION()
	void OnCooldownTimerEnded();

	UPROPERTY(EditDefaultsOnly)
	float CooldownTime;
	bool IsInCooldown = false;
	FTimerHandle CooldownTimerHandle;
};
