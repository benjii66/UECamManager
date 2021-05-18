// Fill out your copyright notice in the Description page of Project Settings.


#include "UCM_CameraBehaviour.h"
#include "UCM_GameMode.h"
#include "DrawDebugHelpers.h"

#include "Kismet/KismetMathLibrary.h"


AUCM_CameraBehaviour::AUCM_CameraBehaviour()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	cameraComponent->SetupAttachment(RootComponent);
}

void AUCM_CameraBehaviour::BeginPlay()
{
	Super::BeginPlay();
	InitCamera();

	//TODO ENABLE IN CAMERA SWITCH WHEN ISSOK
	Enable();
}

void AUCM_CameraBehaviour::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SmoothFollow(DeltaTime);
	SmoothLookAt(DeltaTime);

	DrawGizmos();
}

void AUCM_CameraBehaviour::Enable()
{
	if (!IsValid())return;
	UE_LOG(LogTemp, Warning, TEXT("Enable"));
	cameraComponent->Activate();
	//Permets de voir à travers la caméra
	GetWorld()->GetFirstPlayerController()->SetViewTarget(this);
	isEnabled = true;
}

void AUCM_CameraBehaviour::Disable()
{
	if (!IsValid())return;
	cameraComponent->Deactivate();
	isEnabled = false;
}

void AUCM_CameraBehaviour::InitHandleItem()
{
	if (!IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Need an id"));
		return;
	}
	AUCM_GameMode* _gameMode = Cast<AUCM_GameMode>(GetWorld()->GetAuthGameMode());
	if (!_gameMode) return;

	_gameMode->GetCameraManager()->Add(this);
}

void AUCM_CameraBehaviour::RemoveHandleItem()
{
	AUCM_GameMode* _gameMode = Cast<AUCM_GameMode>(GetWorld()->GetAuthGameMode());
	if (!_gameMode) return;

	_gameMode->GetCameraManager()->Remove(this);
}

void AUCM_CameraBehaviour::SmoothLookAt(float _deltaTime)
{
	if (!IsValid() || !settings.IsLookAt())return;
	FVector _forward = settings.TargetPosition();
	SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), _forward));
}

void AUCM_CameraBehaviour::SmoothFollow(float _deltaTime)
{
	if (!IsValid() || !settings.IsMoving())return;
	SetActorLocation(FMath::Lerp(GetActorLocation(), CameraFinalPosition(), _deltaTime * settings.cameraSpeed));
}

void AUCM_CameraBehaviour::DrawGizmos()
{
	if (settings.IsValidSettings())
	{
		DrawDebugCamera(GetWorld(), GetActorLocation(), GetActorRotation(), 90, 4, FColor::Red, false, -1, 10);
		DrawDebugLine(GetWorld(), GetActorLocation(), settings.TargetPosition(), FColor::Blue, false, -1, 0, 1);
		DrawDebugSphere(GetWorld(), settings.TargetPosition(), 100, 20, FColor::Emerald, false, -1, 0, 1);


		DrawDebugSphere(GetWorld(), settings.Target()->GetActorForwardVector(), 20, 20, FColor::Red, false, -1, 0, 1);
		DrawDebugSphere(GetWorld(), settings.Target()->GetActorRightVector(), 20, 20, FColor::Magenta, false, -1, 0, 1);
		DrawDebugSphere(GetWorld(), settings.Target()->GetActorUpVector(), 20, 20, FColor::Orange, false, -1, 0, 1);


		DrawDebugLine(GetWorld(), settings.TargetPosition(), settings.target->GetActorForwardVector(), FColor::Red, false, -1, 0, 1);
		DrawDebugLine(GetWorld(), settings.TargetPosition(), settings.target->GetActorRightVector(), FColor::Magenta, false, -1, 0, 1);
		DrawDebugLine(GetWorld(), settings.TargetPosition(), settings.target->GetActorUpVector(), FColor::Orange, false, -1, 0, 1);
	}
}



