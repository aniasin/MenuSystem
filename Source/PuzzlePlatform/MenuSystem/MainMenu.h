// SillikOne, UE4.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize() override;

	UPROPERTY(meta = (BindWidget))
	class UButton* HostBtn;
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinBtn;
	UPROPERTY(meta = (BindWidget))
	class UButton* BackBtn;
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinIPBtn;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitch;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;
	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;
	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* IPAddressField;


	IMenuInterface* MenuInterface;

	UFUNCTION()
	void JoinServer();
	UFUNCTION()
	void HostServer();
	UFUNCTION()
	void OpenJoinMenu();
	UFUNCTION()
	void MenuBack();


public:
	void SetMenuInterface(IMenuInterface* MenuInterface);

	void SetUp();
	void TearDown();
};
