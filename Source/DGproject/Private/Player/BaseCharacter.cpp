// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BaseCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Player/BaseCharacterMovementComponent.h"

ABaseCharacter::ABaseCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UBaseCharacterMovementComponent>(CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = false;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>("PlayerCamera");
	PlayerCamera->SetupAttachment(SpringArmComponent, SpringArmComponent->SocketName);

}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	MyCharacterMovementComponent = Cast<UBaseCharacterMovementComponent>(Super::GetMovementComponent());
}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("LookUp", this, &ABaseCharacter::LookUpInput);
	PlayerInputComponent->BindAxis("Turn", this, &ABaseCharacter::TurnInput);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ABaseCharacter::SprintPressedInput);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ABaseCharacter::SprintReleasedInput);

}

void ABaseCharacter::LookUpInput(float Axis)
{
	if (Axis == 0.0f) return;

	AddControllerPitchInput(Axis);
}

void ABaseCharacter::TurnInput(float Axis)
{
	if (Axis == 0.0f) return;

	AddControllerYawInput(Axis);
}

void ABaseCharacter::MoveForward(float Axis)
{
	if (Axis == 0.0f) return;

	const FVector ForwardVector = UKismetMathLibrary::GetForwardVector(FRotator(0.0, GetControlRotation().Yaw, 0.0));

	AddMovementInput(ForwardVector, Axis);
}

void ABaseCharacter::MoveRight(float Axis)
{
	if (Axis == 0.0f) return;

	const FRotator ControlRotation = GetControlRotation();
	const FVector RightVector = UKismetMathLibrary::GetRightVector(FRotator(0.0, ControlRotation.Yaw, ControlRotation.Roll));

	AddMovementInput(RightVector, Axis);
}

void ABaseCharacter::SprintPressedInput()
{
	MyCharacterMovementComponent->SetLocomotionState(ELocomotionState::ELS_Run);
}

void ABaseCharacter::SprintReleasedInput()
{
	MyCharacterMovementComponent->SetLocomotionState(ELocomotionState::ELS_Walk);
}

