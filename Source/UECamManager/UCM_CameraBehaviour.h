// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"


#include "UCM_CameraBehaviour.generated.h"

class UCM_CameraManager;

USTRUCT()

struct FUCM_CameraSettings
{
	GENERATED_BODY()

public:

#pragma region UPROPERTIES

	UPROPERTY(EditAnywhere, Category = "Target To Follow")
		AActor* target = nullptr;
	UPROPERTY(EditAnywhere, Category = "Speed")
		float cameraSpeed = 1;
	UPROPERTY(EditAnywhere, Category = "Speed")
		float rotationSpeed = 1;
	UPROPERTY(EditAnywhere, Category = "offset")
		float xOffset = 0;
	UPROPERTY(EditAnywhere, Category = "offset")
		float yOffset = 0;
	UPROPERTY(EditAnywhere, Category = "offset")
		float zOffset = 0;

	UPROPERTY(EditAnywhere, Category = "Clamp")
		bool useClampValue = true;
	UPROPERTY(EditAnywhere, Category = "Clamp")
		float clampMaxValue = 0;
	UPROPERTY(EditAnywhere, Category = "Clamp")
		float clampMinValue = 0;

	UPROPERTY(EditAnywhere, Category = "Allowance")
		bool isLookAt = true;
	UPROPERTY(EditAnywhere, Category = "Allowance")
		bool isMoving = true;

#pragma endregion


#pragma region Accessors

	FORCEINLINE AActor* Target() { return target; };

	FORCEINLINE FVector Offset() { return FVector(xOffset, yOffset, zOffset); };

	FORCEINLINE FRotator TargetRotation() { return target->GetActorRotation(); }

	FORCEINLINE FVector TargetPosition() { return target->GetActorLocation(); };
	FORCEINLINE FVector TargetLocalPosition() { return target->GetActorLocation(); };

	FORCEINLINE float CameraSpeed() { return cameraSpeed; };
	FORCEINLINE float RotationSpeed() { return rotationSpeed; };

	FORCEINLINE float XOffset() { return xOffset; };
	FORCEINLINE float YOffset() { return yOffset; };
	FORCEINLINE float ZOffset() { return zOffset; };

	FORCEINLINE bool IsLookAt() { return isLookAt; };
	FORCEINLINE bool IsMoving() { return isMoving; };
	FORCEINLINE bool IsValidSettings() { return target != nullptr; };

	FORCEINLINE void SetOffset(float _xOffset, float _yOffset, float _zOffset) { xOffset = _xOffset; yOffset = _yOffset; zOffset = _zOffset; };

	FORCEINLINE FVector SetOffset(FVector _offset) {return Offset() = _offset;};

#pragma endregion

};


UCLASS()
class UECAMMANAGER_API AUCM_CameraBehaviour : public AActor
{
	GENERATED_BODY()

#pragma region Events

	DECLARE_EVENT(FUpdateCameraName, FUpdateCameraEvent)
	FUpdateCameraEvent OnUpdateCameraEvent;

	DECLARE_EVENT(FUpdateDebugName, FUpdateCameraDebugEvent)
	FUpdateCameraDebugEvent OnUpdateCameraDebugEvent;

#pragma endregion


#pragma region UPROPERTIES

	UPROPERTY(EditAnywhere, Category = "Camera")
		FString id = "Camera";

	UPROPERTY(VisibleAnywhere)
		bool isEnabled = true;

	UPROPERTY(EditAnywhere, Category = "Camera")
		UCameraComponent* cameraComponent = nullptr;

	UPROPERTY(EditAnywhere, Category = "Camera Settings")
		FUCM_CameraSettings settings = FUCM_CameraSettings();

#pragma endregion


public:
	AUCM_CameraBehaviour();

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:

#pragma region Accessors

	FORCEINLINE FVector CameraFinalPosition() { return settings.TargetPosition() + settings.Offset(); };
	FORCEINLINE FVector CameraPosition() { return GetActorLocation(); };

	FORCEINLINE UCameraComponent* CameraComponent() { return cameraComponent; };
	FORCEINLINE FUCM_CameraSettings Settings() { return settings; };

	FORCEINLINE bool IsValid() { return !id.IsEmpty() && cameraComponent != nullptr && settings.IsValidSettings(); };
	FORCEINLINE bool IsEnabled() { return isEnabled; };

	FORCEINLINE FString ID() { return id; };

#pragma endregion

	FORCEINLINE void InitCamera() { InitHandleItem(); };

	void Enable();
	void Disable();

	void InitHandleItem();
	void RemoveHandleItem();

	void SmoothLookAt(float _deltaTime);
	void SmoothFollow(float _deltaTime);

	void SetDaOffset();

	void DrawGizmos();

#pragma region Setters

	FORCEINLINE void SetTarget(AActor* _target) { settings.target = _target; };
	FORCEINLINE void SetID(FString _id) { if (!id.IsEmpty())id = _id; };
	FORCEINLINE void SetCameraComponent(UCameraComponent* _newCameraComponent) { cameraComponent = _newCameraComponent; };

#pragma endregion

};
