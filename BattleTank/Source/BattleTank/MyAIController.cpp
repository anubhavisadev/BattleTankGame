// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAIController.h"


ATank* AMyAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController::BeginPlay found player %s"), *(PlayerTank->GetName()));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't find any player's tank."));

	}
	
}

ATank* AMyAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}