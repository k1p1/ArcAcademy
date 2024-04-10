// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcAcademyAnimInstance.h"

void UArcAcademyAnimInstance::PlayAttackAnimation()
{
  PlaySlotAnimationAsDynamicMontage(AttackAnimation, FName(TEXT("UpperBody")));
}

void UArcAcademyAnimInstance::AnimNotify_AttackFinished()
{
  //Do smth
}