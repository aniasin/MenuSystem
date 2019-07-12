// SillikOne, UE4.


#include "PuzzlePlatformGameInstance.h"
#include "GameFramework/PlayerController.h"
#include "Platforms/Trigger.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "MenuSystem/MainMenu.h"

UPuzzlePlatformGameInstance::UPuzzlePlatformGameInstance(const FObjectInitializer & ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MainMenuWidgetClass(TEXT("/Game/MenuSystem/W_MainMenu"));
	
	if (!ensure(MainMenuWidgetClass.Class)) { return; }
	MainMenuWidget = MainMenuWidgetClass.Class;
}

void UPuzzlePlatformGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Found Class: %s"), *MainMenuWidget->GetName())
}

void UPuzzlePlatformGameInstance::LoadMenu()
{
	// Create and show Menu
	if (!MainMenuWidget) { return; }
	UMainMenu* Menu = CreateWidget<UMainMenu>(this, MainMenuWidget);
	Menu->AddToViewport();

	// Set InputMode UI only and show Mouse Cursor
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!PlayerController) { return; }
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(Menu->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;

	Menu->SetMenuInterface(this);
}

void UPuzzlePlatformGameInstance::HostServer()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine)) { return; }
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting!"));

	UWorld* World = GetWorld(); 
	if(!ensure(World)) { return; }
	World->ServerTravel("/Game/Maps/Level_01?Listen");
}

void UPuzzlePlatformGameInstance::JoinServer(FString Address)
{
	Address = "192.168.0.35";
	UEngine* Engine = GetEngine();
	if (!ensure(Engine)) { return; }
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining: %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController)) { return; }

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
