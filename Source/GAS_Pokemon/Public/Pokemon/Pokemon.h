// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Tags/ExtendedGameplayTagInterface.h"
#include "Pokemon.generated.h"

UCLASS()
class GAS_POKEMON_API APokemon : public AActor, public IExtendedGameplayTagInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APokemon();

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
	virtual FGameplayTagContainer& GetTags() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//FGameplayTag GameplayTypes;
	FGameplayTagContainer GameplayTypes;
	float HP;

	void ApplyDamage(float Damage) { HP -= Damage;}
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
