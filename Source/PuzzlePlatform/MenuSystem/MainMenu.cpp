// SillikOne, UE4.


#include "MainMenu.h"
#include "MenuInterface.h"
#include "Components/Button.h"
#include "Components/Widget.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!JoinBtn) { return false; }
	if (!HostBtn) { return false; }
	if (!BackBtn) { return false; }
	if (!JoinIPBtn) { return false; }
	if (!MenuSwitch) { return false; }
	if (!MainMenu) { return false; }
	if (!JoinMenu) { return false; }

	JoinBtn->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);
	HostBtn->OnClicked.AddDynamic(this, &UMainMenu::HostServer);
	BackBtn->OnClicked.AddDynamic(this, &UMainMenu::MenuBack);
	JoinIPBtn->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);
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
	this->MenuInterface = MenuInterface;
}

void UMainMenu::JoinServer()
{
	if (!MenuInterface) { return; }
	const FString& Address = IPAddressField->GetText().ToString();
	MenuInterface->JoinServer(Address);
}

void UMainMenu::HostServer()
{
	if (!MenuInterface) { return; }
	MenuInterface->HostServer();
}

void UMainMenu::OpenJoinMenu()
{
	MenuSwitch->SetActiveWidget(JoinMenu);
}

void UMainMenu::MenuBack()
{
	UWidget* CurrentWidget = MenuSwitch->GetActiveWidget();
	if (CurrentWidget == JoinMenu)
	{
		MenuSwitch->SetActiveWidget(MainMenu);
	}
}

