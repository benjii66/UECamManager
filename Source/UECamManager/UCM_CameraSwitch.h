// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/InputComponent.h"

#include "UCM_CameraSwitch.generated.h"



class AUCM_CameraBehaviour; //pour forward déclaration toujours déclarer dans le cpp quand-même

UCLASS()
class UECAMMANAGER_API AUCM_CameraSwitch : public AActor
{
	GENERATED_BODY()



		

	UPROPERTY(EditAnywhere)
		TArray<AUCM_CameraBehaviour*> cameraBehaviour = TArray<AUCM_CameraBehaviour*>();

	UPROPERTY(EditAnywhere)
		bool isFPS = false;

	bool IsValid() { return cameraBehaviour.Num() != 0; };

	FORCEINLINE void SetFPS(bool _value) { isFPS = _value; };

public:
	AUCM_CameraSwitch();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	void SwitchCamera();


};
