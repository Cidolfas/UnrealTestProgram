// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "DataStore.generated.h"

/**
 * 
 */
UCLASS()
class UDataStore : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float RunningTime;
};
