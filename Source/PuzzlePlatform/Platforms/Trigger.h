// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Trigger.generated.h"

class UBoxComponent;
class AMovingPlatform;

UCLASS()
class PUZZLEPLATFORM_API ATrigger : public AActor
{
	GENERATED_BODY()
	
	// Sets default values for this actor's properties
	ATrigger();
	UPROPERTY(VisibleAnywhere, Category = "SetUp")
	UBoxComponent* TriggerBox;
	UPROPERTY(VisibleAnywhere, Category = "SetUp")
	UStaticMeshComponent* PressurePlate;

	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(
			UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere, Category = "SetUp")
	TArray <AMovingPlatform*> PlatformsToTrigger;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
