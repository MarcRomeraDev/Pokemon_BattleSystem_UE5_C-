// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS_Pokemon/Public/Pokemon/Pokemon.h"


// Sets default values
APokemon::APokemon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APokemon::BeginPlay()
{
	Super::BeginPlay();
	
}

void APokemon::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer=GameplayTypes;
}

FGameplayTagContainer& APokemon::GetTags()
{
	return GameplayTypes;
}

// Called every frame
void APokemon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

