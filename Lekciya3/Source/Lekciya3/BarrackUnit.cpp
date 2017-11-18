// Fill out your copyright notice in the Description page of Project Settings.

#include "BarrackUnit.h"
#include "Movement.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
ABarrackUnit::ABarrackUnit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Meshe = CreateDefaultSubobject<UStaticMeshComponent>("Meshe");

	ConstructorHelpers::FObjectFinder<UStaticMesh>LoadedMesh(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));

	if (LoadedMesh.Object != nullptr)
	{
		Meshe->SetStaticMesh(LoadedMesh.Object);
	}

	RootComponent = Meshe;

	MymovementComponent = CreateDefaultSubobject<UMovement>(TEXT("Randommovement"));

}

// Called when the game starts or when spawned
void ABarrackUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABarrackUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}