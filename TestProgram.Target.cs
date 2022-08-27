// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Desktop)]
public class TestProgramTarget : TargetRules
{
	public TestProgramTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Program; // This setting is what makes it work as a program!
		LinkType = TargetLinkType.Monolithic;

		LaunchModuleName = "TestProgram";
		ExtraModuleNames.Add("EditorStyle");

		bBuildDeveloperTools = false;

		// TestProgram doesn't ever compile with the engine linked in
		bCompileAgainstEngine = false;

		// We need CoreUObject compiled in as the source code access module requires it
		bCompileAgainstCoreUObject = true;

		// TestProgram.exe has no exports, so no need to verify that a .lib and .exp file was emitted by
		// the linker.
		bHasExports = false;

		// Make sure to get all code in SlateEditorStyle compiled in
        bBuildDeveloperTools = true;
	}
}
