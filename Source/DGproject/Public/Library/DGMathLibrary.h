// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DGMathLibrary.generated.h"

/**
 * 
 */
UCLASS()
class DGPROJECT_API UDGMathLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Math Utils")
	static float ClampJoystickAxis(float Axis, float MinClamp, float MaxClamp);

};
