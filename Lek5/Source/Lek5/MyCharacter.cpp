// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"
#include "MyProjectile.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	TurnRate = 45.f;
	LookUpRate = 45.f;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
	GetCharacterMovement()->JumpZVelocity = 550.f;
	GetCharacterMovement()->AirControl = 0.2f;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CamerBoom"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.f;
	SpringArm->bUsePawnControlRotation = true;

	CameraFollow = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraFollow->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	CameraFollow->bUsePawnControlRotation = false;

	IsShoot = false;
	CanShoot = false;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump",IE_Pressed, this,&ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released , this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMyCharacter::MTurnRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMyCharacter::MLookUpRate);

	PlayerInputComponent->BindAction("Shot", IE_Pressed, this, &AMyCharacter::Shot);
	PlayerInputComponent->BindAction("Shot", IE_Released, this, &AMyCharacter::StopShot);
}

void AMyCharacter::MoveForward(float AxisValue)
{
	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, AxisValue);
	}
}

void AMyCharacter::MoveRight(float AxisValue)
{
	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, AxisValue);
	}
}

void AMyCharacter::MTurnRate(float Rate)
{
	AddControllerYawInput(Rate * TurnRate * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::MLookUpRate(float Rate)
{
	AddControllerPitchInput(Rate * LookUpRate * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::Shot()
{
	if (CanShoot)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Black, "Shot");
		IsShoot = true;
		if (ProjectileClass != NULL)
		{
			// Get the camera transform
			FVector MuzzleLoc;
			FRotator MRot = GetActorRotation();
			UWorld* const World = GetWorld();

			FVector SocketLocation = GetMesh()->GetSocketLocation("MuzzleS");


			if (World)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.Owner = this;
				SpawnParams.Instigator = Instigator;
				// spawn the projectile at the muzzle
				AMyProjectile* const Projectile = World->SpawnActor<AMyProjectile>(ProjectileClass, SocketLocation, GetActorRotation(), SpawnParams);
				if (Projectile)
				{
					// find launch direction
				    FVector const Rot = MRot.Vector();
					Projectile->InitVelocity(Rot);
				}
			}
		}
	}
}

void AMyCharacter::StopShot()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Black, "Stop");
	IsShoot = false;
}