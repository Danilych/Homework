// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameModeBase.h"
#include "Lek4GameMode.generated.h"

DECLARE_DELEGATE(FMyTriggerDelegate)

UCLASS(minimalapi)
class ALek4GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ALek4GameMode();

	FMyTriggerDelegate MyTriggerDel;
};



