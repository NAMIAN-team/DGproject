// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Library/EnumLibrary.h"
#include "Library/StructLibrary.h"

#include "BaseCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class DGPROJECT_API UBaseCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_UCLASS_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Settings)
	FMovementSettings MovementSettings;

public:
	UFUNCTION(BlueprintCallable, Category = "Custom Movement")
	void SetLocomotionState(ELocomotionState NewState);

	UFUNCTION(BlueprintCallable, Category = "Custom Movement")
	ELocomotionState GetLocomotionState();

	
};
