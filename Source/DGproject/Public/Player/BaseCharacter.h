// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UBaseCharacterMovementComponent;


UCLASS()
class DGPROJECT_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Camera)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Camera)
	UCameraComponent* PlayerCamera;

protected:
	UPROPERTY()
	TObjectPtr<UBaseCharacterMovementComponent> MyCharacterMovementComponent;

public:
	ABaseCharacter(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION(BlueprintCallable, Category = "Movement")
	FORCEINLINE UBaseCharacterMovementComponent* GetMyMovementComponent() const
	{
		return MyCharacterMovementComponent;
	}

private:
#pragma region Input
	void LookUpInput(float Axis);
	void TurnInput(float Axis);

	void MoveForward(float Axis);
	void MoveRight(float Axis);

	void SprintPressedInput();
	void SprintReleasedInput();
#pragma endregion

};
