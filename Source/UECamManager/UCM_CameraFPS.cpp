// Fill out your copyright notice in the Description page of Project Settings.


#include "UCM_CameraFPS.h"
#include "DrawDebugHelpers.h"

#include "Kismet/KismetMathLibrary.h"

AUCM_CameraFPS::AUCM_CameraFPS()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	cameraComponent->SetupAttachment(RootComponent);
}

void AUCM_CameraFPS::BeginPlay()
{
	Super::BeginPlay();
	InitCamera();

	//TODO Switch Component ? 
	Enable(this);
}

void AUCM_CameraFPS::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SmoothFollow(DeltaTime);
	SmoothLookAt(DeltaTime);

	DrawGizmos();
}

void AUCM_CameraFPS::SmoothLookAt(float _deltaTime)
{
	if (!IsValid() || !settings.IsLookAt())return;
	FVector _forward = settings.TargetPosition();
	SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), _forward));

}

void AUCM_CameraFPS::SmoothFollow(float _deltaTime)
{
	if (!IsValid() || !settings.IsMoving())return;
	SetActorLocation(FMath::Lerp(GetActorLocation(), CameraFinalPosition(), _deltaTime * settings.cameraSpeed));

}

void AUCM_CameraFPS::DrawGizmos()
{
	DrawDebugCamera(GetWorld(), GetActorLocation(), GetActorRotation(), 90, 4, FColor::Red, false, -1, 10);
	DrawDebugLine(GetWorld(), GetActorLocation(), settings.TargetPosition(), FColor::Blue, false, -1, 0, 1);
	DrawDebugSphere(GetWorld(), settings.TargetPosition(), 100, 20, FColor::Emerald, false, -1, 0, 1);
}

