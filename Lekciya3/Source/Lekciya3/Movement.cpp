// Fill out your copyright notice in the Description page of Project Settings.

#include "Movement.h"


// Sets default values for this component's properties
UMovement::UMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	MovementRadius = 10.0f;
	MoveNum = 0;
	// ...
}


// Called when the game starts
void UMovement::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Parent = GetOwner();

	if (Parent)
	{
		MoveNum = (FMath::RandRange(1, 3));
		if (MoveNum == 1)
		{
			Parent->SetActorLocation(Parent->GetActorLocation() + FVector(FMath::FRandRange(-1, 1) * MovementRadius,0,0));
		}

		if (MoveNum == 2)
		{
			Parent->SetActorLocation(Parent->GetActorLocation() + FVector(0,FMath::FRandRange(-1, 1) * MovementRadius, 0));
		}

		if (MoveNum == 3)
		{
			Parent->SetActorLocation(Parent->GetActorLocation() + FVector(0,0,FMath::FRandRange(-1, 1) * MovementRadius));
		}
	}
}

