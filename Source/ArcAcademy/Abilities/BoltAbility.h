// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAbility.h"
#include "BoltAbility.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ARCACADEMY_API UBoltAbility : public UBaseAbility
{
	GENERATED_BODY()

public:
	virtual bool Activate(FVector Location) override;

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AProjectile> ProjectileClass;
	
};
