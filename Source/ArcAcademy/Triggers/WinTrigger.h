// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTrigger.h"
#include "WinTrigger.generated.h"

/**
 * 
 */
UCLASS()
class ARCACADEMY_API AWinTrigger : public ABaseTrigger
{
	GENERATED_BODY()

protected:
	virtual void Action(AActor* InTarget) override;
	
};
