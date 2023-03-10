// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"

// Sets default values
ABasePlayer::ABasePlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ABasePlayer::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ABasePlayer::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ABasePlayer::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ABasePlayer::AddControllerPitchInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ABasePlayer::Jump);
	/*PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Pressed, this, &ABasePlayer::Crouch);*/
}

void ABasePlayer::MoveForward(float AxisVal)
{
	AddMovementInput(GetActorForwardVector() * AxisVal);
}

void ABasePlayer::MoveRight(float AxisVal)
{
	AddMovementInput(GetActorRightVector() * AxisVal);


}

