// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAIController.h"


ATank* AMyAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController::BeginPlay Called from %s"), *(ControlledTank->GetName()));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't get any tanks to control!!"));

	}
	
}
