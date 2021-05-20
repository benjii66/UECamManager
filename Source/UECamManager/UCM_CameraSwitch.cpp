

#include "UCM_CameraSwitch.h"
#include "UCM_CameraFPS.h"
#include "UCM_CameraTPS.h"

AUCM_CameraSwitch::AUCM_CameraSwitch()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AUCM_CameraSwitch::BeginPlay()
{
	Super::BeginPlay();

}

void AUCM_CameraSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SwitchCamera();

}



void AUCM_CameraSwitch::SwitchCamera()
{
	if (!IsValid())return;
	if (isFPS)
	{
		for (int i = 0; i < cameraBehaviour.Num(); i++)
		{
			cameraBehaviour[i]->Enable(cameraBehaviour[i]);
			cameraBehaviour[i++]->Disable(cameraBehaviour[i++]); //works
		}
		UE_LOG(LogTemp, Warning, TEXT("FPS enabled"));
		SetFPS(true);

	}

	else
	{
		for (int i = 0; i < cameraBehaviour.Num(); i++)
		{
			cameraBehaviour[i]->Disable(cameraBehaviour[i]);			
			cameraBehaviour[i]->Enable(cameraBehaviour[i]); 
		}
		UE_LOG(LogTemp, Error, TEXT("TPS enabled"));
		SetFPS(false);

	}

}

