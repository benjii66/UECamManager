// Fill out your copyright notice in the Description page of Project Settings.


#include "UCM_CameraManager.h"

// Sets default values
AUCM_CameraManager::AUCM_CameraManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUCM_CameraManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUCM_CameraManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

#pragma region Add

void AUCM_CameraManager::Add(AUCM_CameraBehaviour* _camera)
{
	if (Exist(_camera->ID()))
		UE_LOG(LogTemp, Error, TEXT("Camera already Exist"));
	allCameras.Add(_camera->ID(), _camera);
}

#pragma endregion

#pragma region Remove

void AUCM_CameraManager::Remove(AUCM_CameraBehaviour* _camera)
{
	if (!Exist(_camera))
	{
		UE_LOG(LogTemp, Error, TEXT("Cam doesn't exist"));
		return;
	}
	allCameras.Remove(_camera->ID());
	UE_LOG(LogTemp, Warning, TEXT("camera correctly remove"));

}

void AUCM_CameraManager::Remove(FString _id)
{
	if (!Exist(_id))
	{
		UE_LOG(LogTemp, Error, TEXT("Cam doesn't exist"));
		return;
	}
	allCameras.Remove(_id);
	UE_LOG(LogTemp, Warning, TEXT("camera correctly remove"));

}

#pragma endregion

#pragma region Exist

bool AUCM_CameraManager::Exist(AUCM_CameraBehaviour* _camera)
{
	bool _exist = allCameras.Contains(_camera->ID());
	if (!_exist)
		UE_LOG(LogTemp, Error, TEXT("Cam doesn't exist"));

	return _exist;
}

bool AUCM_CameraManager::Exist(FString _id)
{
	return allCameras.Contains(_id);
}

#pragma endregion

#pragma region Get

AUCM_CameraBehaviour* AUCM_CameraManager::Get(FString _id)
{
	if (!Exist(_id))
	{
		UE_LOG(LogTemp, Error, TEXT("camera doesn't exist"));
		return nullptr;
	}
	return allCameras[_id];
}

AUCM_CameraBehaviour* AUCM_CameraManager::Get(AUCM_CameraBehaviour* _camera)
{
	if (!Exist(_camera->ID()))
	{
		UE_LOG(LogTemp, Error, TEXT("camera doesn't exist"));
		return nullptr;
	}
	return allCameras[_camera->ID()];
}

#pragma endregion

#pragma region Enable

void AUCM_CameraManager::Enable(FString _id)
{
	if (!Exist(_id))return;
	for (const TPair<FString, AUCM_CameraBehaviour*>& _camera : allCameras)
		_camera.Value->Disable();
	Get(_id)->Enable(allCameras[_id]);
}

void AUCM_CameraManager::Enable(AUCM_CameraBehaviour* _cameraToEnable)
{
	if (!Exist(_cameraToEnable->ID()))return;
	for(const TPair<FString, AUCM_CameraBehaviour*>& _camera : allCameras)
		_camera.Value->Disable();
	Get(_cameraToEnable->ID())->Enable(allCameras[_cameraToEnable->ID()]);
}

#pragma endregion

#pragma region Disable

void AUCM_CameraManager::Disable(AUCM_CameraBehaviour* _cameraToDisable)
{
	if (!Exist(_cameraToDisable->ID()))return;
	Get(_cameraToDisable->ID())->Disable();
}

void AUCM_CameraManager::Disable(FString _id)
{
	if (!Exist(_id))return;
	Get(_id)->Disable();
}

#pragma endregion




