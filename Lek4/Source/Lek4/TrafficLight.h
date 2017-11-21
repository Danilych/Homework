// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrafficLight.generated.h"

UCLASS()
class LEK4_API ATrafficLight : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	ATrafficLight();

	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	UStaticMeshComponent* MyMesh;

	UPROPERTY(BlueprintReadOnly)
	float StreetlightScalar;

	UPROPERTY(BlueprintReadOnly)
	float GreenScalar;

	UPROPERTY(BlueprintReadOnly)
	float RedScalar;

	UPROPERTY(BlueprintReadOnly)
	float YellowScalar;

	UPROPERTY(BlueprintReadOnly)
	FName StreetlightScalarParamName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void EnableRedLight();

	UFUNCTION()
	void EnableYellowLight();

	UFUNCTION()
	void EnableGreenLight();

	
	
};
