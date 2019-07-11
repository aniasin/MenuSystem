// SillikOne, UE4.


#include "MainMenu.h"
#include "Components/Button.h"

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	// can be nullptr if we haven't created it in the
	// Blueprint subclass
	/*if (JoinBtn)
	{
		JoinBtn->FOnButtonClickedEvent
	}

	if (HostBtn)
	{
		HostBtn->SetText(TEXT("world!"));
	}*/
}
