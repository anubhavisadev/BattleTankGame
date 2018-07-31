// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Kismet/GameplayStatics.h"

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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector LocationPoint;
	if (GetWorldLocationPoint(LocationPoint))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *LocationPoint.ToString());
	}

}

bool ATankPlayerController::GetWorldLocationPoint(FVector& LocationPoint)
{
	int32 X;
	int32 Y;
	GetViewportSize(X, Y);
	FVector2D CrosshairScreenLocation = FVector2D(X*0.5, Y*0.33333);
	FVector WorldLocation;
	if (DeprojectScreenPositionToWorld(CrosshairScreenLocation.X, CrosshairScreenLocation.Y, WorldLocation, LocationPoint))
	{
		return true;
	}
	else 
	{
		return false;
	}
}