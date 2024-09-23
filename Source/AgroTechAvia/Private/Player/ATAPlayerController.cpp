// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ATAPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Interaction/StudyObjectInterface.h"

void AATAPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AATAPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(DefaultContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(DefaultContext, 0);

	bShowMouseCursor = true;
	
	SetInputMode(MainMenuInputModeData);
}

void AATAPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(SelectAction, ETriggerEvent::Started, this, &AATAPlayerController::Select);
}


void AATAPlayerController::Select(const FInputActionValue& InputActionValue)
{
	if (SelectedActor)
	{
		IStudyObjectInterface::Execute_OnObjectSelected(SelectedActor);
	}
}

void AATAPlayerController::CursorTrace()
{
	FHitResult  CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	UObject* CurrentActor = nullptr;

	if (CursorHit.GetActor() && CursorHit.GetActor()->Implements<UStudyObjectInterface>())
	{
		CurrentActor = CursorHit.GetActor();
	}

	if (SelectedActor == nullptr)
	{
		if (CurrentActor != nullptr)
		{
			SelectedActor = CurrentActor;
		}
		else
		{
			// Do nothing
		}
	}
	else // SelectedActor is valid
	{
		if (CurrentActor == nullptr)
		{
			SelectedActor = nullptr;
		}
		else // Both actors are valid
		{
			if (CurrentActor != SelectedActor)
			{
				SelectedActor = CurrentActor;
			}
			else // Actors are the same
			{
				// Do nothing
			}
		}
	}
	
}

void AATAPlayerController::ToggleInputMode(bool IsMainMenu)
{
	if(IsMainMenu)
	{
		SetInputMode(MainMenuInputModeData);
	}
	else
	{
		SetInputMode(InLessonInputModeData);
	}
}
