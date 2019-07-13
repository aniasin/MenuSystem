// SillikOne, UE4.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API UPuzzlePlatformGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
	UPuzzlePlatformGameInstance(const FObjectInitializer & ObjectInitializer);

	virtual void Init();

	UFUNCTION(BlueprintCallable, Category = "MenuSystem")
		void LoadMenu();
	UFUNCTION(BlueprintCallable, Category = "MenuSystem")
		void OpenGameMenu();

	UFUNCTION()
		virtual void HostServer()override;

	UFUNCTION()
		virtual void JoinServer(const FString Address)override;

private:
	TSubclassOf<class UUserWidget> MainMenuWidget;
	TSubclassOf<class UUserWidget> GameMenuWidget;

	class UMainMenu* Menu;
	class UGameMenu* GameMenu;
};
