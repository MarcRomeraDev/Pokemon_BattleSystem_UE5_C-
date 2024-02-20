// Fill out your copyright notice in the Description page of Project Settings.


#include "Pokemon/PokeAttack.h"

#include "Pokemon/Pokemon.h"
#include "Pokemon/PokeType.h"

void UPokeAttack::Attack(APokemon* Instigator, APokemon* Receiver)
{
	float Damage = BaseDamage;
	if (PokeTypeCorrelation)
	{
		TArray<FPokeCorrelations*> OutRows;
		PokeTypeCorrelation->GetAllRows<FPokeCorrelations>(TEXT("Attack"), OutRows);

		// find the row of the movement type
		FPokeCorrelations** Row = OutRows.FindByPredicate([this](FPokeCorrelations* Corr)
		{
			return Corr->TypeAttack.MatchesTag(Type);
		});

		// For each type of the enemy pokemon, apply the dmg multiplier depending on the movement type
		for (TArray<TArray<FTypeMultiplierPair>::ElementType> TypePairs =
			     (*Row)->Type_Coeff.FilterByPredicate(
				     [Receiver](const FTypeMultiplierPair& InTypePair)
				     {
					     return Receiver->GameplayTypes.HasTag(InTypePair.Type);
				     }); const auto [Type, Multiplier] : TypePairs)
		{
			Damage *= Multiplier;
		}
	}
	Receiver->ApplyDamage(Damage);
}
