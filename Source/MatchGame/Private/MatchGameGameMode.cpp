// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "MatchGame.h"
#include "MatchGameGameMode.h"
#include "MatchGamePlayerController.h"

AMatchGameGameMode::AMatchGameGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// no pawn by default
	DefaultPawnClass = NULL;
	// use our own player controller class
	PlayerControllerClass = AMatchGamePlayerController::StaticClass();
}
