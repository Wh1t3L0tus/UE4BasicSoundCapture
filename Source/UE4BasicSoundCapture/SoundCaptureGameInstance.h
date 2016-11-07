#pragma once

#include "Engine/GameInstance.h"
#include "OnlineSessionInterface.h"
#include "SoundCaptureGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE4BASICSOUNDCAPTURE_API USoundCaptureGameInstance : public UGameInstance
{
	GENERATED_BODY()

	USoundCaptureGameInstance();
	virtual void StartGameInstance() override;
	bool HostSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLAN, bool bIsPresence, int32 MaxNumPlayers);
	void OnStartOnlineGameComplete(FName SessionName, bool bWasSuccessful);
	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);

private:

	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	FOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;
	FDelegateHandle OnCreateSessionCompleteDelegateHandle;
	FDelegateHandle OnStartSessionCompleteDelegateHandle;
	TSharedPtr<class FOnlineSessionSettings> SessionSettings;
	
};
