// Copyright Epic Games, Inc. All Rights Reserved.


#include "TestProgramApp.h"
#include "Windows/WindowsHWrapper.h"

////////
/// This is the entry point for the application on Windows platforms
/// If you want to support other platforms, look at SlateViewer in the engine projects
////////

/**
 * WinMain, called when the application is started
 */
int WINAPI WinMain( _In_ HINSTANCE hInInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR, _In_ int nCmdShow )
{
	// do the slate viewer thing
	RunTestProgram(GetCommandLineW());

	return 0;
}
