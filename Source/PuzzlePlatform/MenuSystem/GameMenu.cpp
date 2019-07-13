// SillikOne, UE4.


#include "GameMenu.h"
#include "MenuInterface.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"



bool UGameMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!QuitBtn) { return false; }
	if (!BackBtn) { return false; }
	if (!QuitConfirmBtn) { return false; }
	if (!BackConfirmBtn) { return false; }
	if (!MenuSwitch) { return false; }

	QuitBtn->OnClicked.AddDynamic(this, &UGameMenu::OpenPopupMenu);
	BackBtn->OnClicked.AddDynamic(this, &UGameMenu::Back);
	QuitConfirmBtn->OnClicked.AddDynamic(this, &UGameMenu::Quit);
	BackConfirmBtn->OnClicked.AddDynamic(this, &UGameMenu::Back);
	return true;
}

void UGameMenu::SetUp()
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

void UGameMenu::SetMenuInterface(IMenuInterface* MenuInterface)
{
	this->MenuInterface = MenuInterface;
}

void UGameMenu::Quit()
{
	
}

void UGameMenu::Back()
{
	TearDown();
}

void UGameMenu::TearDown()
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

void UGameMenu::OpenPopupMenu()
{
	MenuSwitch->SetActiveWidget(PopupMenu);
}
