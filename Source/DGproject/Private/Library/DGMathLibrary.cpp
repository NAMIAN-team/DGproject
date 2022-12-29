// Fill out your copyright notice in the Description page of Project Settings.


#include "Library/DGMathLibrary.h"

float UDGMathLibrary::ClampJoystickAxis(float Axis, float MinClamp, float MaxClamp)
{
	float ReturnAxis = FMath::Clamp(FMath::Abs(Axis), MinClamp, MaxClamp);

	if (Axis < 0.f)
	{
		ReturnAxis *= -1;
	}

	return ReturnAxis;
}
