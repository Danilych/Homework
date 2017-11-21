// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Lek4GameMode.h"
#include "Lek4Pawn.h"
#include "Lek4Hud.h"

ALek4GameMode::ALek4GameMode()
{
	DefaultPawnClass = ALek4Pawn::StaticClass();
	HUDClass = ALek4Hud::StaticClass();
}
