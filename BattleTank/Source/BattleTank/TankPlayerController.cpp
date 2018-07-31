// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController::BeginPlay Called from %s"), *(ControlledTank->GetName()));

	} 
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't get any tanks to control!!"));

	}
	
	}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}


