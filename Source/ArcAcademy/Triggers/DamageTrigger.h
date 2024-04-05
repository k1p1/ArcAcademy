// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTrigger.h"
#include "DamageTrigger.generated.h"

/**
 * 
 */
UCLASS()
class ARCACADEMY_API ADamageTrigger : public ABaseTrigger
{
	GENERATED_BODY()

protected:
	virtual void ActionStart(AActor* InTarget) override;
	virtual void ActionEnd(AActor* InTarget) override;
	UFUNCTION()
	void DamageTick();

	UPROPERTY(EditAnywhere)
	float Damage = 1.0f;
	UPROPERTY(EditAnywhere)
	float DamageTickRate = 1.0f;
	UPROPERTY()
	AActor* Target;

	FTimerHandle DamageTimerHandle;
};
