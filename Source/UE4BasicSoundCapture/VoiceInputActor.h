#pragma once

#include "Voice.h"
#include "OnlineSubsystemUtils.h"
#include "Sound/SoundWaveProcedural.h"
#include "GameFramework/Actor.h"
#include "VoiceInputActor.generated.h"

UCLASS()
class UE4BASICSOUNDCAPTURE_API AVoiceInputActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVoiceInputActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;


private:

	UPROPERTY()
	float VoiceCaptureVolume;

	UPROPERTY()
	bool VoiceCaptureTest;

	UPROPERTY()
	bool PlayVoiceCaptureFlag;

	UPROPERTY()
	FTimerHandle VoiceCaptureTickTimer;

	UPROPERTY()
	FTimerHandle PlayVoiceCaptureTimer;

	TSharedPtr<class IVoiceCapture> VoiceCapture;

	USoundWaveProcedural* VoiceCaptureSoundWaveProcedural;

	UPROPERTY()
	UAudioComponent* VoiceCaptureAudioComponent;

	UPROPERTY()
	TArray<uint8> VoiceCaptureBuffer;

	UFUNCTION()
	void VoiceCaptureTick();

	UFUNCTION()
	void PlayVoiceCapture();

};
