// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UCM_CameraBehaviour.h"
#include "UCM_CameraTPS.generated.h"

/**
 *
 */
UCLASS()
class UECAMMANAGER_API AUCM_CameraTPS : public AUCM_CameraBehaviour
{
	GENERATED_BODY()

public:
	AUCM_CameraTPS();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


	virtual void SmoothLookAt(float _deltaTime) override;
	virtual void SmoothFollow(float _deltaTime) override;

	virtual void DrawGizmos() override;
	

};
