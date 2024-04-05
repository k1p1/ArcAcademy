// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTrigger.h"
#include "SlowTrigger.generated.h"

/**
 * 
 */
UCLASS()
class ARCACADEMY_API ASlowTrigger : public ABaseTrigger
{
	GENERATED_BODY()

protected:
	virtual void ActionStart(AActor* InTarget);
	virtual void ActionEnd(AActor* InTarget);
	
	UPROPERTY(EditAnywhere)
	float MaxWalkSpeed;

	float TargetMaxWalkSpeed;
};
