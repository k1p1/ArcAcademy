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
	virtual void Action(AActor* InTarget) override;
	UPROPERTY(EditAnywhere)
	float Damage = 1.0f;
};
