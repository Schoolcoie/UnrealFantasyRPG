// Fill out your copyright notice in the Description page of Project Settings.


#include "Uriel_Controller.h"
#include "GameFramework/Character.h"

void AUriel_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindAxis("MoveForward", this, &AUriel_Controller::MoveForward);
		InputComponent->BindAxis("MoveRight", this, &AUriel_Controller::MoveRight);

		InputComponent->BindAction("Crouch", IE_Pressed, this, &AUriel_Controller::BeginCrouch);
		InputComponent->BindAction("Crouch", IE_Released, this, &AUriel_Controller::EndCrouch);
	}
}

void AUriel_Controller::MoveForward(float AxisValue)
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	FVector forward = ControlledPawn->GetActorForwardVector();

	ControlledPawn->AddMovementInput(forward, AxisValue);

}
void AUriel_Controller::MoveRight(float AxisValue)
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	FVector right = ControlledPawn->GetActorRightVector();

	ControlledPawn->AddMovementInput(right, AxisValue);
}
void AUriel_Controller::BeginCrouch()
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	ACharacter* MyCharacter = Cast<ACharacter>(ControlledPawn);
	if (!MyCharacter) return;

	MyCharacter->Crouch();
}
void AUriel_Controller::EndCrouch()
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	ACharacter* MyCharacter = Cast<ACharacter>(ControlledPawn);
	if (!MyCharacter) return;

	MyCharacter->UnCrouch();
}