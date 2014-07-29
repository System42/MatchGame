// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "MatchGame.h"
#include "MatchGamePlayerController.h"

AMatchGamePlayerController::AMatchGamePlayerController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}
