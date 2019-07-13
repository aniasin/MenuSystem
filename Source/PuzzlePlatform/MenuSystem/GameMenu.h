// SillikOne, UE4.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "GameMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API UGameMenu : public UUserWidget
{
	GENERATED_BODY()
	
	virtual bool Initialize() override;

	UPROPERTY(meta = (BindWidget))
	class UButton* BackBtn;
	UPROPERTY(meta = (BindWidget))
	class UButton* QuitBtn;
	UPROPERTY(meta = (BindWidget))
	class UButton* BackConfirmBtn;
	UPROPERTY(meta = (BindWidget))
	class UButton* QuitConfirmBtn;

	IMenuInterface* MenuInterface;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitch;

	UPROPERTY(meta = (BindWidget))
	class UWidget* GameMenu;
	UPROPERTY(meta = (BindWidget))
	class UWidget* PopupMenu;

	UFUNCTION()
	void Quit();
	UFUNCTION()
	void Back();

public:
	void SetMenuInterface(IMenuInterface* MenuInterface);
	void SetUp();
	void TearDown();
	void OpenPopupMenu();
};
