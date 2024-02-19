// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GAS_Pokemon : ModuleRules
{
	public GAS_Pokemon(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput", "GameplayAbilities"  });
    
	PrivateDependencyModuleNames.AddRange(new string[]
	{
		"GameplayAbilities", "GameplayTags", "GameplayTasks"
	});
        
	PublicIncludePaths.Add("GAS_Pokemon/Public");
	}
}
