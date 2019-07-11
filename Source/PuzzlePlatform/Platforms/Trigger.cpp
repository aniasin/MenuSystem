// Fill out your copyright notice in the Description page of Project Settings.


#include "Trigger.h"
#include "Components/BoxComponent.h"
#include "Platforms/MovingPlatform.h"

// Sets default values
ATrigger::ATrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PressurePlate = CreateDefaultSubobject<UStaticMeshComponent>(FName("PressurePlate"));
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(FName("TriggerBox"));
	TriggerBox->SetupAttachment(PressurePlate);
	TriggerBox->SetGenerateOverlapEvents(true);

}

// Called when the game starts or when spawned
void ATrigger::BeginPlay()
{
	Super::BeginPlay();

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ATrigger::OnOverlapBegin);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ATrigger::OnOverlapEnd);

}

// Called every frame
void ATrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	for (int Index = 0; Index < PlatformsToTrigger.Num(); Index++)
	{
		PlatformsToTrigger[Index]->AddActiveTrigger();
	}
}

void ATrigger::OnOverlapEnd(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex)
{
	for (int Index = 0; Index < PlatformsToTrigger.Num(); Index++)
	{
		PlatformsToTrigger[Index]->RemoveActiveTrigger();
	}
}
