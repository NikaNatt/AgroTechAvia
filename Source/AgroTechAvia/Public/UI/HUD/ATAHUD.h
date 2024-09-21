// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ATAHUD.generated.h"

class UATA_UserWidget;
/**
 * 
 */
UCLASS()
class AGROTECHAVIA_API AATA_HUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TObjectPtr<UATA_UserWidget> MainWidgetRef;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> MainWidgetSubclass;
};
