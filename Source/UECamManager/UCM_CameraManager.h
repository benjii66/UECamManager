// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "UCM_CameraBehaviour.h"

#include "UCM_CameraManager.generated.h"

UCLASS()
class UECAMMANAGER_API AUCM_CameraManager : public AActor
{
	GENERATED_BODY()

	DECLARE_EVENT(FUpdateCameraManager, FUpdateCameraManagerEvent)
	FUpdateCameraManagerEvent OnUpdateCameraManagerEvent;

	UPROPERTY(EditAnywhere)
		TMap<FString, AUCM_CameraBehaviour*> allCameras;


public:	
	AUCM_CameraManager();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:	
	FUpdateCameraManagerEvent& OnUpdateCameraManager() { return OnUpdateCameraManagerEvent; };

	void Add(AUCM_CameraBehaviour* _camera);
	void Add(FString _id);

	void Remove(AUCM_CameraBehaviour* _camera);
	void Remove(FString _id);

	bool Exist(AUCM_CameraBehaviour* _camera);
	bool Exist(FString _id);
	AUCM_CameraBehaviour* Get(FString _id);
	AUCM_CameraBehaviour* Get(AUCM_CameraBehaviour* _camera);

	void Enable(FString _id, bool _disableOtherCamera);
	void Enable(AUCM_CameraBehaviour* _cameraToEnable, bool _disableOtherCamera);

	void Disable(AUCM_CameraBehaviour* _cameraToEnable, bool _disableOtherCamera);
	void Disable(FString _id);

	void DisableAll();
};
