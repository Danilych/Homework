// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/HUD.h"
#include "Lek4Hud.generated.h"


UCLASS(config = Game)
class ALek4Hud : public AHUD
{
	GENERATED_BODY()

public:
	ALek4Hud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface
};
