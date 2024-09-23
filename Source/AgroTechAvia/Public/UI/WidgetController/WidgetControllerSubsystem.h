// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WidgetControllerSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLessonActivated, FGameplayTag, StudyObjectTag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLessonDeactivated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPartFocused, FGameplayTag, PartTag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnViewTargetChanged, FGameplayTag, Actor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLessonSelected, FGameplayTag, StudyObjectTag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLessonUnselected);

/**
 * 
 */
UCLASS()
class AGROTECHAVIA_API UWidgetControllerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnLessonActivated OnLessonActivated;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnLessonDeactivated OnLessonDeactivated;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnPartFocused OnPartFocused;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnViewTargetChanged OnViewTargetChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnLessonSelected OnLessonSelected;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnLessonUnselected OnLessonUnselected;
};
