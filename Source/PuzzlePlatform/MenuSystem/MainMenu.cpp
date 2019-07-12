// SillikOne, UE4.


#include "MainMenu.h"
#include "MenuInterface.h"
#include "Components/Button.h"

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	// can be nullptr if we haven't created it in the
	// Blueprint subclass
	if (!JoinBtn) { return; }
	//JoinBtn->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

	if (!HostBtn) { return; }
	HostBtn->OnClicked.AddDynamic(this, &UMainMenu::HostServer);
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
