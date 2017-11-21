// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTriggerActor.h"
#include "Lek4GameMode.h"
#include "UObject/ConstructorHelpers.h"


// Sets default values
AMyTriggerActor::AMyTriggerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerZone = CreateDefaultSubobject<UBoxComponent>("RootTrigger");

	MyOMesh = CreateDefaultSubobject<UStaticMeshComponent>("ObstacleMesh");
	ConstructorHelpers::FObjectFinder<UStaticMesh>LoadedMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (LoadedMesh.Object != nullptr)
	{
		MyOMesh->SetStaticMesh(LoadedMesh.Object);
	}

	
}

// Called when the game starts or when spawned
void AMyTriggerActor::BeginPlay()
{
	Super::BeginPlay();
	MyOMesh->SetHiddenInGame(true);
	MyOMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

// Called every frame
void AMyTriggerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTriggerActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	MyOMesh->SetHiddenInGame(false);
	MyOMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	AGameModeBase* StartGameMode = GetWorld()->GetAuthGameMode();
	ALek4GameMode* MyGameMode = Cast<ALek4GameMode>(StartGameMode);
	if (MyGameMode != nullptr)
	{
		MyGameMode->MyTriggerDel.ExecuteIfBound();
	}

	FTimerHandle ObstacleTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(ObstacleTimerHandle, this, &AMyTriggerActor::DestroyObstacle, 4.0f, false);
}



void AMyTriggerActor::NotifyActorEndOverlap(AActor* OtherActor)
{

}

void AMyTriggerActor::DestroyObstacle()
{
	MyOMesh->SetHiddenInGame(true);
	MyOMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

