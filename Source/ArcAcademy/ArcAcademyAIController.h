// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ArcAcademyAIController.generated.h"

/**
 * 
 */
UCLASS()
class ARCACADEMY_API AArcAcademyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AArcAcademyAIController();

protected:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	UPROPERTY()
	class UBlackboardComponent* BlackboardComponent;
	UPROPERTY()
	class UBehaviorTreeComponent* BehaviorTreeComponent;
};
