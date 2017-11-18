// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrackUnit.h"
#include "Barrack.generated.h"

UCLASS()
class LEKCIYA3_API ABarrack : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY()
	ABarrackUnit* TheActorToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	// Sets default values for this actor's properties
	ABarrack();

	UFUNCTION()
	void SpawnByTimer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
