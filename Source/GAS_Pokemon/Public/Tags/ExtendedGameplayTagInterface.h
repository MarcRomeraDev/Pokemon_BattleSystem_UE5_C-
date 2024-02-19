// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "UObject/Interface.h"
#include "ExtendedGameplayTagInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UExtendedGameplayTagInterface : public UGameplayTagAssetInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAS_POKEMON_API IExtendedGameplayTagInterface : public IGameplayTagAssetInterface 
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual FGameplayTagContainer& GetTags() =0;
	virtual bool AddGameplayTag(const FGameplayTag& InTag);
	virtual bool RemoveGameplayTag(const FGameplayTag& InTag);

};
