// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "PokeType.generated.h"

/**
 * 
 */
#define SET_POKETYPE_COEFF(Type, Coeff) {FGameplayTag::RequestGameplayTag(*FString::Printf(TEXT("Pokemon.Type.%s"), Type)), Coeff}

USTRUCT()
struct FTypeMultiplierPair
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) FGameplayTag Type;

	UPROPERTY(EditAnywhere) float Multiplier = 1;
};

USTRUCT()
struct FPokeCorrelations: public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) FGameplayTag TypeAttack;

	UPROPERTY(EditAnywhere) TArray<FTypeMultiplierPair> Type_Coeff;

	FPokeCorrelations()
		: Type_Coeff({
			SET_POKETYPE_COEFF(TEXT("Rock"),1.f),
			{FGameplayTag::RequestGameplayTag(TEXT("Pokemon.Type.Normal")),1.f},
			{FGameplayTag::RequestGameplayTag(TEXT("Pokemon.Type.Fire")),1.f},
			{FGameplayTag::RequestGameplayTag(TEXT("Pokemon.Type.Water")),1.f},
			{FGameplayTag::RequestGameplayTag(TEXT("Pokemon.Type.Grass")),1.f},
		})
	{
		FGameplayTag TypeTag = FGameplayTag::RequestGameplayTag(TEXT("Pokemon.Type"));
	}
};