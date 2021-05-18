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

void AUCM_CameraManager::Add(AUCM_CameraBehaviour* _camera)
{

}

void AUCM_CameraManager::Add(FString _id)
{

}

void AUCM_CameraManager::Remove(AUCM_CameraBehaviour* _camera)
{

}

void AUCM_CameraManager::Remove(FString _id)
{

}

bool AUCM_CameraManager::Exist(AUCM_CameraBehaviour* _camera)
{
	return false;
}

bool AUCM_CameraManager::Exist(FString _id)
{
	return false;
}

AUCM_CameraBehaviour* AUCM_CameraManager::Get(FString _id)
{
	return nullptr;
}

AUCM_CameraBehaviour* AUCM_CameraManager::Get(AUCM_CameraBehaviour* _camera)
{
	return nullptr;
}

void AUCM_CameraManager::Enable(FString _id, bool _disableOtherCamera)
{

}

void AUCM_CameraManager::Enable(AUCM_CameraBehaviour* _cameraToEnable, bool _disableOtherCamera)
{

}

void AUCM_CameraManager::Disable(AUCM_CameraBehaviour* _cameraToEnable, bool _disableOtherCamera)
{

}

void AUCM_CameraManager::Disable(FString _id)
{

}

void AUCM_CameraManager::DisableAll()
{

}

