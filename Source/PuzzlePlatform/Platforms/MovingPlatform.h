// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

class ATrigger;
/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();
	virtual void BeginPlay()override;
	virtual void Tick(float DeltaTime)override;

	UPROPERTY(EditAnywhere)
	float Speed = 20.0f;
	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	void AddActiveTrigger();
	void RemoveActiveTrigger();

private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;

	UPROPERTY(EditAnywhere, Category = "SetUp")
	int32 ActiveTriggers = 1;
};
