// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestTechnique : ModuleRules
{
	public TestTechnique(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay",
			"AIModule",
			//"GameplayTask",
			"NavigationSystem"
		});
	}
}
