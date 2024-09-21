// Fill out your copyright notice in the Description page of Project Settings.


#include "..\..\..\Public\UI\HUD\ATAHUD.h"

#include "Blueprint/UserWidget.h"

void AATA_HUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), MainWidgetSubclass);
	Widget->AddToViewport();
}
