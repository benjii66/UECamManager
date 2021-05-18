// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "UCM_CameraManager.h"

#include "UCM_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class UECAMMANAGER_API AUCM_GameMode : public AGameModeBase
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TSoftObjectPtr<AUCM_CameraManager> cameraManager = nullptr;

public :
	FORCEINLINE AUCM_CameraManager* GetCameraManager() { return cameraManager.Get(); };
};
