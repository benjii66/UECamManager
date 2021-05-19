// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/InputComponent.h"

#include "UCM_CameraSwitch.generated.h"

class AUCM_CameraBehaviour;
class AUCM_CameraTPS;
class AUCM_CameraFPS;

UCLASS()
class UECAMMANAGER_API AUCM_CameraSwitch : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		AUCM_CameraBehaviour* cameraBehaviour = nullptr;

	UPROPERTY(EditAnywhere)
		AUCM_CameraTPS* cameraTPS = nullptr;

	UPROPERTY(EditAnywhere)
		AUCM_CameraFPS* cameraFPS = nullptr;

	UPROPERTY(VisibleAnywhere)
		bool isFPS = false;

	bool IsValid() { return cameraTPS != nullptr && cameraFPS != nullptr; };

	FORCEINLINE void SetFPS(bool _value) { isFPS = _value; };

public:
	// Sets default values for this actor's properties
	AUCM_CameraSwitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void SwitchCamera();

};
