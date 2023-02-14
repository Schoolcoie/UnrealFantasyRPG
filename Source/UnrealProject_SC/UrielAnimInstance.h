// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "UrielAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_SC_API UUrielAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (BlueprintThreadSafe))
	float GetPawnCurrentSpeed();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (BlueprintThreadSafe))
		float GetPawnCurrentDirection();
	
};
