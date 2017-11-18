// Fill out your copyright notice in the Description page of Project Settings.

#include "Barrack.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
ABarrack::ABarrack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	ConstructorHelpers::FObjectFinder<UStaticMesh>LoadedMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));

	if (LoadedMesh.Object != nullptr)
	{
		Mesh->SetStaticMesh(LoadedMesh.Object);
	}

	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ABarrack::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &ABarrack::SpawnByTimer, 5, true);
}

void ABarrack::SpawnByTimer()
{
	FTransform SpawnPoint;
	SpawnPoint = GetActorTransform();
	TheActorToSpawn = (ABarrackUnit*)GetWorld()->SpawnActor(ABarrackUnit::StaticClass(), &SpawnPoint);
}

// Called every frame
void ABarrack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

