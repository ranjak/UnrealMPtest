// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "IInputReceiver.h"

#include "InputDispatcher.generated.h"

UCLASS()
class AInputDispatcher : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AInputDispatcher();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

  virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

  UFUNCTION(BlueprintCallable)
  void AddInputReceiver(APawn* receiver);

private:

  void ForwardJumpDown();
  void ForwardJumpUp();

  UPROPERTY(Replicated)
  TArray<APawn*> OwnedPawns;
};
