// Fill out your copyright notice in the Description page of Project Settings.

#include "TrafficLight.h"
#include "UObject/ConstructorHelpers.h"
#include "Lek4GameMode.h"
#include "Materials/Material.h"


// Sets default values
ATrafficLight::ATrafficLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Mesh
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>("TrafficMesh");
    ConstructorHelpers::FObjectFinder<UStaticMesh>LoadedMesh(TEXT("StaticMesh'/Game/ExampleContent/NetworkFeatures/Meshes/SM_Traffic_Light.SM_Traffic_Light'"));
	if (LoadedMesh.Object != nullptr)
	{
		MyMesh->SetStaticMesh(LoadedMesh.Object);
	}
	RootComponent = MyMesh;

	StreetlightScalar = 0.0f;
	GreenScalar = 0.0f;
	RedScalar = 1.0f;
	YellowScalar = 0.5f;
	StreetlightScalarParamName = "State";


}

// Called when the game starts or when spawned
void ATrafficLight::BeginPlay()
{
	Super::BeginPlay();
	
	UMaterialInstanceDynamic* StreetlightMID = MyMesh->CreateDynamicMaterialInstance(1);
	StreetlightMID->SetScalarParameterValue(StreetlightScalarParamName, GreenScalar);

	AGameModeBase* StartGameMode = GetWorld()->GetAuthGameMode();
	ALek4GameMode* MyGameMode = Cast<ALek4GameMode>(StartGameMode);
	if (MyGameMode != nullptr)
	{
		MyGameMode->MyTriggerDel.BindUObject(this, &ATrafficLight::EnableRedLight);
	}
}

// Called every frame
void ATrafficLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATrafficLight::EnableRedLight()
{
	//GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "RedLightGo");
	UMaterialInstanceDynamic* StreetlightMID = MyMesh->CreateDynamicMaterialInstance(1);
	StreetlightMID->SetScalarParameterValue(StreetlightScalarParamName, RedScalar);
	FTimerHandle TrafficTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TrafficTimerHandle, this, &ATrafficLight::EnableYellowLight, 3.0f, false);
}

void ATrafficLight::EnableYellowLight()
{
	UMaterialInstanceDynamic* StreetlightMID = MyMesh->CreateDynamicMaterialInstance(1);
	StreetlightMID->SetScalarParameterValue(StreetlightScalarParamName, YellowScalar);
	FTimerHandle TrafficTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TrafficTimerHandle, this, &ATrafficLight::EnableGreenLight, 1.0f, false);
}

void ATrafficLight::EnableGreenLight()
{
	UMaterialInstanceDynamic* StreetlightMID = MyMesh->CreateDynamicMaterialInstance(1);
	StreetlightMID->SetScalarParameterValue(StreetlightScalarParamName, GreenScalar);
}
