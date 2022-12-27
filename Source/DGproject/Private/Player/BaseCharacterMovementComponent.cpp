// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BaseCharacterMovementComponent.h"

#include "Kismet/KismetMathLibrary.h"

UBaseCharacterMovementComponent::UBaseCharacterMovementComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UBaseCharacterMovementComponent::SetLocomotionState(ELocomotionState NewState)
{
	switch (NewState) {
	case ELocomotionState::ELS_Walk:
		MaxWalkSpeed = MovementSettings.WalkSpeed;
		break;
	case ELocomotionState::ELS_Run:
		MaxWalkSpeed = MovementSettings.RunSpeed;
		break;
	default: break;
	}
}

ELocomotionState UBaseCharacterMovementComponent::GetLocomotionState()
{
	FVector NormalizeAcceleration = Acceleration;
	UKismetMathLibrary::Vector_Normalize(NormalizeAcceleration);

	FVector NormalizeVelocity = Velocity;
	UKismetMathLibrary::Vector_Normalize(NormalizeVelocity);

	double dot = UKismetMathLibrary::Dot_VectorVector(NormalizeAcceleration, NormalizeVelocity);

	if(dot < -0.2)
	{
		return ELocomotionState::ELS_Idle;
	}

	{
		const bool CorrectSpeed = Velocity.Size() > 1.0;
		const bool CorrectMaxSpeed = GetMaxSpeed() == MovementSettings.RunSpeed;
		const bool CorrectAcceleration = Acceleration.Size() > 0.5;

		if (CorrectSpeed && CorrectMaxSpeed && CorrectAcceleration)
		{
			return ELocomotionState::ELS_Run;
		}
	}
	{
		const bool CorrectSpeed = Velocity.Size() > 1.0;
		const bool CorrectMaxSpeed = GetMaxSpeed() > 0;
		const bool CorrectAcceleration = Acceleration.Size() > 0.01;

		if (CorrectSpeed && CorrectMaxSpeed && CorrectAcceleration)
		{
			return ELocomotionState::ELS_Walk;
		}
	}
	
	return ELocomotionState::ELS_Idle;
}
