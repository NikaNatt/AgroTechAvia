// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ATAPlayerController.h"

void AATAPlayerController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;
	
	FInputModeUIOnly InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputModeData);
}
