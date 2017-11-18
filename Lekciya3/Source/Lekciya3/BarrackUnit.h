// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrackUnit.generated.h"

UCLASS()
class LEKCIYA3_API ABarrackUnit : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Meshe;

	UPROPERTY()
	class UMovement* MymovementComponent;

	// Sets default values for this actor's properties
	ABarrackUnit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;	
	
};
