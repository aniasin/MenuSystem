// SillikOne, UE4.


#include "MainMenu.h"
#include "MenuInterface.h"
#include "Components/Button.h"

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;



	// can be nullptr if we haven't created it in the
	// Blueprint subclass
	if (!JoinBtn) { return false; }
	//JoinBtn->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

	if (!HostBtn) { return false; }
	HostBtn->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	return true;
}

void UMainMenu::SetUp()
{
	UWorld* World = GetWorld();
	if (!World) { return; }

	// Set InputMode UI only and show Mouse Cursor
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!PlayerController) { return; }
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}



void UMainMenu::TearDown()
{
	this->RemoveFromViewport();

	UWorld* World = GetWorld();
	if (!World) { return; }
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!PlayerController) { return; }

	FInputModeGameOnly InputModeData;
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = false;

}

void UMainMenu::SetMenuInterface(IMenuInterface* MenuInterface)
{
	// get a reference to MenuInterface
	this->MenuInterface = MenuInterface;
}

void UMainMenu::JoinServer(FString Address)
{
	if (!MenuInterface) { return; }
	MenuInterface->JoinServer(Address);
}

void UMainMenu::HostServer()
{
	if (!MenuInterface) { return; }
	MenuInterface->HostServer();
}
