// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"

#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

		ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	bool GetWorldLocationPoint(FVector& LocationPoint);
	
private:
	UPROPERTY(EditAnyWhere)
		float RatioX = 0.5f;
	UPROPERTY(EditAnyWhere)
		float RatioY = 0.33333f;
	UPROPERTY(EditAnyWhere)
		int32 Range = 1000000;
	ATank* ControlledTank = nullptr;
};
