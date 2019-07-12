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

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	class UButton* HostBtn;
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinBtn;

	IMenuInterface* MenuInterface;

	UFUNCTION()
	void JoinServer(FString Address);
	UFUNCTION()
	void HostServer();

public:
	void SetMenuInterface(IMenuInterface* MenuInterface);

};
