// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "PokeAttack.generated.h"

/**
 * 
 */
UCLASS()
class GAS_POKEMON_API UPokeAttack : public UObject
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category ="Attack", meta = (AllowPrivateAccess = true))
	UDataTable* PokeTypeCorrelation;
	
protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category ="Attack", meta = (AllowPrivateAccess = true))
	FGameplayTag Type;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category ="Attack", meta = (AllowPrivateAccess = true))
	float BaseDamage;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category ="Attack", meta = (AllowPrivateAccess = true))
	int32 MaxPP;

	//UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category ="Attack", meta = (AllowPrivateAccess = true))
	//TArray<class UpokeDebuff*> Debuff;
public:

	virtual void Attack(class APokemon* Instigator, APokemon* Receiver);



};
