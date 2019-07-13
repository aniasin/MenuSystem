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

	UFUNCTION(BlueprintCallable, Category = "MainMenu")
		void LoadMenu();

	UFUNCTION()
		virtual void HostServer()override;

	UFUNCTION()
		virtual void JoinServer(FString Address)override;

private:
	TSubclassOf<class UUserWidget> MainMenuWidget;

	class UMainMenu* Menu;
};
