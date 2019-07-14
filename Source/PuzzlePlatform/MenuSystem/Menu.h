// SillikOne, UE4.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "Menu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API UMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	IMenuInterface* MenuInterface;

public:
	void SetMenuInterface(IMenuInterface* MenuInterfaceToSet);
	void SetUp();
	void TearDown();
};
