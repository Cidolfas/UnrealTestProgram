// Copyright Epic Games, Inc. All Rights Reserved.

using EpicGames.Core;
using UnrealBuildBase;
using UnrealBuildTool;

public class TestProgram : ModuleRules
{
	public TestProgram(ReadOnlyTargetRules Target) : base(Target)
	{
		var runtimeLaunchDir = DirectoryReference.Combine(Unreal.EngineDirectory, "Source", "Runtime", "Launch");

		PublicIncludePaths.Add(DirectoryReference.Combine(runtimeLaunchDir, "Public").FullName);

		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"AppFramework",
				"Core",
				"ApplicationCore",
				"Projects",
				"Slate",
				"SlateCore",
				"StandaloneRenderer",
			}
		);

		PrivateIncludePaths.Add(DirectoryReference.Combine(runtimeLaunchDir, "Private").FullName);		// For LaunchEngineLoop.cpp include
	}
}
