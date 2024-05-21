// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcAcademyHUD.h"
#include "Kismet/GameplayStatics.h"
#include "UI/EndGameWidget.h"

void AArcAcademyHUD::BeginPlay()
{
  Super::BeginPlay();

  APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
  if (IsValid(PlayerController))
  {
    EndGameWidget = CreateWidget<UEndGameWidget>(PlayerController, EndGameWidgetClass);
    if (IsValid(EndGameWidget))
    {
      EndGameWidget->AddToViewport();
      EndGameWidget->SetVisibility(ESlateVisibility::Collapsed);
    }
  }
}

void AArcAcademyHUD::ShowEndGameScreen()
{
  if (IsValid(EndGameWidget))
  {
    EndGameWidget->SetVisibility(ESlateVisibility::Visible);
  }
}