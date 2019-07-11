// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformGameInstance.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"

UPuzzlePlatformGameInstance::UPuzzlePlatformGameInstance(const FObjectInitializer & ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GAME INSTANCE CONTRUCTOR"))
}

void UPuzzlePlatformGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GAME INSTANCE INIT"))
}

void UPuzzlePlatformGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine)) { return; }
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting!"));

	UWorld* World = GetWorld(); 
	if(!ensure(World)) { return; }
	World->ServerTravel("/Game/Maps/Level_01?Listen");
}

void UPuzzlePlatformGameInstance::Join(const FString Address)
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine)) { return; }
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining: %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController)) { return; }

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
