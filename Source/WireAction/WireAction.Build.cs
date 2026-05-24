// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WireAction : ModuleRules
{
	public WireAction(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"WireAction",
			"WireAction/Variant_Platforming",
			"WireAction/Variant_Platforming/Animation",
			"WireAction/Variant_Combat",
			"WireAction/Variant_Combat/AI",
			"WireAction/Variant_Combat/Animation",
			"WireAction/Variant_Combat/Gameplay",
			"WireAction/Variant_Combat/Interfaces",
			"WireAction/Variant_Combat/UI",
			"WireAction/Variant_SideScrolling",
			"WireAction/Variant_SideScrolling/AI",
			"WireAction/Variant_SideScrolling/Gameplay",
			"WireAction/Variant_SideScrolling/Interfaces",
			"WireAction/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
