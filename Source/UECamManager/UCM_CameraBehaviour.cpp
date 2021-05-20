// Fill out your copyright notice in the Description page of Project Settings.


#include "UCM_CameraBehaviour.h"
#include "UCM_GameMode.h"
#include "DrawDebugHelpers.h"

#include "Kismet/KismetMathLibrary.h"


AUCM_CameraBehaviour::AUCM_CameraBehaviour()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AUCM_CameraBehaviour::BeginPlay()
{
	Super::BeginPlay();
	InitCamera();		
}

void AUCM_CameraBehaviour::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AUCM_CameraBehaviour::Enable(AActor* _this)
{
	if (!IsValid())return;
	UE_LOG(LogTemp, Warning, TEXT("Enable"));
	cameraComponent->Activate();

	//Permets de voir à travers la caméra
	GetWorld()->GetFirstPlayerController()->SetViewTarget(_this);
	isEnabled = true;
	isActive = true;
}

void AUCM_CameraBehaviour::Disable(AActor* _this)
{
	if (!IsValid())return;
	cameraComponent->Deactivate();
	GetWorld()->GetFirstPlayerController()->SetViewTarget(_this);
	isEnabled = false;
	isActive = false;

}

void AUCM_CameraBehaviour::Disable()
{
	if (!IsValid())return;
	cameraComponent->Deactivate();
	isEnabled = false;
	isActive = false;

}

void AUCM_CameraBehaviour::InitHandleItem(AUCM_CameraBehaviour* _this)
{
	if (!IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Need an id"));
		return;
	}
	AUCM_GameMode* _gameMode = Cast<AUCM_GameMode>(GetWorld()->GetAuthGameMode());
	if (!_gameMode) return;

	_gameMode->GetCameraManager()->Add(_this);
}

void AUCM_CameraBehaviour::RemoveHandleItem(AUCM_CameraBehaviour* _this)
{
	AUCM_GameMode* _gameMode = Cast<AUCM_GameMode>(GetWorld()->GetAuthGameMode());
	if (!_gameMode) return;

	_gameMode->GetCameraManager()->Remove(_this);

}








