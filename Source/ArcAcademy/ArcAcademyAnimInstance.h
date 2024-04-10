// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ArcAcademyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARCACADEMY_API UArcAcademyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	void PlayAttackAnimation();
	UFUNCTION(BlueprintCallable)
	void AnimNotify_AttackFinished();
	
protected:
	UPROPERTY(EditDefaultsOnly)
	UAnimSequenceBase* AttackAnimation;
};
