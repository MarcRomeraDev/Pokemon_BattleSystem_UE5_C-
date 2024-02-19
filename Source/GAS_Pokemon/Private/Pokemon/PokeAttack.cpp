// Fill out your copyright notice in the Description page of Project Settings.


#include "Pokemon/PokeAttack.h"

#include "Pokemon/Pokemon.h"
#include "Pokemon/PokeType.h"

void UPokeAttack::Attack(APokemon* Instigator, APokemon* Receiver)
{
	float Damage = BaseDamage;
	if(PokeTypeCorrelation)
	{
		TArray<FPokeCorrelations*> OutRows;
		PokeTypeCorrelation->GetAllRows<FPokeCorrelations>(TEXT("Attack"),OutRows);

		FPokeCorrelations** Row = OutRows.FindByPredicate([this](FPokeCorrelations* Corr)
		{
			return Corr->TypeAttack.MatchesTag(Type);
		});
		FTypeMultiplierPair* TypePair= (*Row)->Type_Coeff.FindByPredicate([Receiver](const FTypeMultiplierPair& InTypePair)
		{
			return Receiver->GameplayTypes.MatchesTag(InTypePair.Type);
		});
		if(TypePair)
		{
			Damage *= TypePair->Multiplier;
		}
	}
	Receiver->ApplyDamage(Damage);
}
