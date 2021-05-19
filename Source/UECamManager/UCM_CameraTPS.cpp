// Fill out your copyright notice in the Description page of Project Settings.


#include "UCM_CameraTPS.h"
#include "DrawDebugHelpers.h"

#include "Kismet/KismetMathLibrary.h"


AUCM_CameraTPS::AUCM_CameraTPS()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	cameraComponent->SetupAttachment(RootComponent);
}



void AUCM_CameraTPS::BeginPlay()
{
	Super::BeginPlay();
	InitCamera();

	//TODO In the Switch component(Future Feature)
	EnableTPS();
}

void AUCM_CameraTPS::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SmoothFollow(DeltaTime);
	SmoothLookAt(DeltaTime);

	DrawGizmos();

}

void AUCM_CameraTPS::EnableTPS()
{
	Enable(this);
}

void AUCM_CameraTPS::DisableTPS()
{
	Disable();
}

void AUCM_CameraTPS::SmoothLookAt(float _deltaTime)
{
	if (!IsValid() || !settings.IsLookAt())return;
	FVector _forward = settings.TargetPosition();
	SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), _forward));
}

void AUCM_CameraTPS::SmoothFollow(float _deltaTime)
{
	if (!IsValid() || !settings.IsMoving())return;
	SetActorLocation(FMath::Lerp(GetActorLocation(), CameraFinalPosition(), _deltaTime * settings.cameraSpeed));

}

void AUCM_CameraTPS::DrawGizmos()
{
	if (settings.IsValidSettings())
	{
		DrawDebugCamera(GetWorld(), GetActorLocation(), GetActorRotation(), 90, 4, FColor::Red, false, -1, 10);
		DrawDebugLine(GetWorld(), GetActorLocation(), settings.TargetPosition(), FColor::Blue, false, -1, 0, 1);
		DrawDebugSphere(GetWorld(), settings.TargetPosition(), 100, 20, FColor::Emerald, false, -1, 0, 1);
	}

}




