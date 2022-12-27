#pragma once

#include "StructLibrary.generated.h"


USTRUCT(BlueprintType)
struct FMovementSettings
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float IdleSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WalkSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RunSpeed;
    
};