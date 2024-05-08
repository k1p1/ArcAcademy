// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ActivateAbility.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../ArcAcademyCharacter.h"

EBTNodeResult::Type UBTTask_ActivateAbility::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory)
{
  AAIController* AIController = Cast<AAIController>(OwnerComponent.GetOwner());
  if (IsValid(AIController) == false)
  {
    return EBTNodeResult::Failed;
  }

  AArcAcademyCharacter* PossesedCharacter = Cast<AArcAcademyCharacter>(AIController->GetPawn());
  if (IsValid(PossesedCharacter) == false)
  {
    return EBTNodeResult::Failed;
  }

  UBlackboardComponent* BlackboardComponent = OwnerComponent.GetBlackboardComponent();
  if (IsValid(BlackboardComponent) == false)
  {
    return EBTNodeResult::Failed;
  }

  AActor* Target = Cast<AActor>(BlackboardComponent->GetValueAsObject(FName("Target")));
  if (IsValid(Target) == false)
  {
    return EBTNodeResult::Failed;
  }

  PossesedCharacter->ActivateAbility(Target->GetActorLocation());

  return EBTNodeResult::Succeeded;
}

