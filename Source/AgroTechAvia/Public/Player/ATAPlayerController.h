// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ATAPlayerController.generated.h"

class IStudyObjectInterface;
class UInputMappingContext;
class UInputAction;
/**
 * 
 */
UCLASS()
class AGROTECHAVIA_API AATAPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void PlayerTick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

private:
	void Select(const struct FInputActionValue& InputActionValue);

	void CursorTrace();
	
private:
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputMappingContext> DefaultContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> SelectAction;

	UObject* SelectedActor;
};
