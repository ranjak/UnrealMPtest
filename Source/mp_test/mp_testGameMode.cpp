// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "mp_testGameMode.h"
#include "mp_testCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Private/InputDispatcher.h"

Amp_testGameMode::Amp_testGameMode()
{
	// set default pawn class to our Blueprinted character
//	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
//	if (PlayerPawnBPClass.Class != NULL)
//	{
//		DefaultPawnClass = PlayerPawnBPClass.Class;
//	}

  DefaultPawnClass = AInputDispatcher::StaticClass();
}
