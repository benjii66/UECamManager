// Fill out your copyright notice in the Description page of Project Settings.


#include "UCM_CameraSwitch.h"

// Sets default values
AUCM_CameraSwitch::AUCM_CameraSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUCM_CameraSwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUCM_CameraSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AUCM_CameraSwitch::SwitchCamera()
{
	if (!IsValid())return;
	if (isFPS)
	{
		UE_LOG(LogTemp, Error, TEXT("FPS enabled"));
		/*AUCM_GameMode* _gameMode = Cast<AUCM_GameMode>(GetWorld()->GetAuthGameMode());
		if (!_gameMode) return;*/

		/*cameraFPS->EnableFPS();
		cameraTPS->DisableTPS();*/
		

		SetFPS(true);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("TPS enabled"));
		//cameraTPS->EnableTPS();
		//cameraFPS->DisableFPS();
		SetFPS(false);
	}

}

