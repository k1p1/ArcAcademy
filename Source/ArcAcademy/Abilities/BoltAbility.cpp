// Fill out your copyright notice in the Description page of Project Settings.


#include "BoltAbility.h"
#include "../Projectiles/Projectile.h"
#include "../ArcAcademyAnimInstance.h"
#include "../ArcAcademy.h"

#include "GameFramework/Character.h"

bool UBoltAbility::Activate(FVector Location)
{
  if (Super::Activate(Location) == false)
  {
    return false;
  }

  UWorld* World = GetWorld();
  ACharacter* Owner = Cast<ACharacter>(GetOuter());
  if (IsValid(Owner) == false)
  {
    UE_LOG(LogArcAcademy, Error, TEXT("IsValid(Owner) == false"));
    return false;
  }

  USkeletalMeshComponent* SkeletalMesh = Owner->GetMesh();
  if (IsValid(SkeletalMesh))
  {
    UArcAcademyAnimInstance* AnimInstance = Cast<UArcAcademyAnimInstance>(SkeletalMesh->GetAnimInstance());
    if (IsValid(AnimInstance))
    {
      AnimInstance->PlayAttackAnimation();
    }
  }

  FActorSpawnParameters SpawnParameters;
  SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

  FVector Direction = Location - Owner->GetActorLocation();
  Direction.Z = 0.0f;
  Direction.Normalize();

  FVector SpawnLocation = Owner->GetActorLocation() + Direction * 100.0f;

  AActor* Projectile = World->SpawnActor<AActor>(ProjectileClass, SpawnLocation, Direction.Rotation(), SpawnParameters);
  if (IsValid(Projectile) == false)
  {
    UE_LOG(LogArcAcademy, Error, TEXT("IsValid(Projectile) == false"));
    return false;
  }
  return true;
}
