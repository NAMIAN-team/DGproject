#pragma once

#include "EnumLibrary.generated.h"

UENUM(BlueprintType)
enum class ELocomotionState : uint8
{
	ELS_Idle UMETA(DisplayName = "Idle"),
	ELS_Walk UMETA(DisplayName = "Walk"),
	ELS_Run UMETA(DisplayName = "Run")
};