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
	/*Enable();*/
}

void AUCM_CameraBehaviour::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SmoothFollow(DeltaTime);
	SmoothLookAt(DeltaTime);

	DrawGizmos();
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



