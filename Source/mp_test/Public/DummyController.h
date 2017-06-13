// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "DummyController.generated.h"

/**
 * 
 */
UCLASS()
class MP_TEST_API ADummyController : public AController
{
	GENERATED_BODY()
	
  ADummyController();
	
protected:
  virtual void Tick(float DeltaSeconds) override;
};
