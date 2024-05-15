// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcAcademyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "ArcAcademyCharacter.h"

AArcAcademyAIController::AArcAcademyAIController()
{
  BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
  BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
}

void AArcAcademyAIController::OnPossess(APawn* InPawn)
{
  Super::OnPossess(InPawn);

  AArcAcademyCharacter* PossessedCharacter = Cast<AArcAcademyCharacter>(InPawn);
  if (IsValid(PossessedCharacter))
  {
    UBehaviorTree* Tree = PossessedCharacter->GetBehaviorTree();
    if (IsValid(Tree))
    {
      BlackboardComponent->InitializeBlackboard(*Tree->GetBlackboardAsset());
      BehaviorTreeComponent->StartTree(*Tree);
    }
  }

}

void AArcAcademyAIController::OnUnPossess()
{
  Super::OnUnPossess();

  BehaviorTreeComponent->StopTree();
}