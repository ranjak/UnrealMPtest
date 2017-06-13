// Fill out your copyright notice in the Description page of Project Settings.


#include "InputDispatcher.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"
#include "DummyController.h"


// Sets default values
AInputDispatcher::AInputDispatcher()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
  bReplicates = true;
}

// Called when the game starts or when spawned
void AInputDispatcher::BeginPlay()
{
	Super::BeginPlay();

}

void AInputDispatcher::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
  DOREPLIFETIME(AInputDispatcher, OwnedPawns);
}

// Called every frame
void AInputDispatcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AInputDispatcher::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
  Super::SetupPlayerInputComponent(PlayerInputComponent);
  PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AInputDispatcher::ForwardJumpDown);
  PlayerInputComponent->BindAction("Jump", IE_Released, this, &AInputDispatcher::ForwardJumpUp);
}

void AInputDispatcher::AddInputReceiver(APawn* receiver)
{
  // The pawn isn't updated if it doesn't have a controller
  FActorSpawnParameters params;
  params.Owner = this;
  ADummyController* ctrl = GetWorld()->SpawnActor<ADummyController>(ADummyController::StaticClass(), params);
  ctrl->Possess(receiver);

  if (GetRemoteRole() == ROLE_AutonomousProxy)
  {
    ctrl->SetAutonomousProxy(true);
    receiver->SetAutonomousProxy(true);
  }
  OwnedPawns.Add(receiver);
}

void AInputDispatcher::ForwardJumpDown()
{
  for (APawn* receiver : OwnedPawns)
  {
    if (receiver && receiver->IsA(ACharacter::StaticClass()))
    {
      Cast<ACharacter>(receiver)->Jump();
    }
  }
}

void AInputDispatcher::ForwardJumpUp()
{
  for (APawn* receiver : OwnedPawns)
  {
    if (receiver && receiver->IsA(ACharacter::StaticClass()))
    {
      Cast<ACharacter>(receiver)->StopJumping();
    }
  }
}
