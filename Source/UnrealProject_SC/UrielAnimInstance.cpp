// Fill out your copyright notice in the Description page of Project Settings.


#include "UrielAnimInstance.h"

float UUrielAnimInstance::GetPawnCurrentSpeed()
{
	const APawn* pawn = TryGetPawnOwner();
	if (pawn)
	{
		const FVector velocity = pawn->GetVelocity();
		return velocity.Size();
	}

	return 0.0f;
}

float UUrielAnimInstance::GetPawnCurrentDirection()
{
	return 0.0f;

	//In character, get IsCrouching
}
