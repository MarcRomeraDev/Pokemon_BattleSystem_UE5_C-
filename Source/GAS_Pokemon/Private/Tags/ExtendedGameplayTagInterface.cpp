// Fill out your copyright notice in the Description page of Project Settings.


#include "Tags/ExtendedGameplayTagInterface.h"


bool IExtendedGameplayTagInterface::AddGameplayTag(const FGameplayTag& InTag)
{
	if(GetTags().HasTag(InTag))
		return false;
	GetTags().AddTag(InTag);
		return true;;
}

bool IExtendedGameplayTagInterface::RemoveGameplayTag(const FGameplayTag& InTag)
{
	return GetTags().RemoveTag(InTag);
}
