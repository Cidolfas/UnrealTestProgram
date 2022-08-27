// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestProgramApp.h"

#include "DataStore.h"
#include "RequiredProgramMainCPPInclude.h"
#include "TabManager.h"
#include "Framework/Application/SlateApplication.h"
#include "Slate/Public/Slate.h"


IMPLEMENT_APPLICATION(TestProgram, "TestProgram");

#define LOCTEXT_NAMESPACE "TestProgram"

int RunTestProgram( const TCHAR* CommandLine )
{
	FTaskTagScope TaskTagScope(ETaskTag::EGameThread);

	// start up the main loop
	GEngineLoop.PreInit(CommandLine);

	// Make sure all UObject classes are registered and default properties have been initialized
	ProcessNewlyLoadedUObjects();

	// Tell the module manager it may now process newly-loaded UObjects when new C++ modules are loaded
	FModuleManager::Get().StartProcessingNewlyLoadedObjects();

	// crank up a normal Slate application using the platform's standalone renderer
	FSlateApplication::InitializeAsStandaloneApplication(GetStandardStandaloneRenderer());

	FSlateApplication::InitHighDPI(true);

	// set the application name
	FGlobalTabmanager::Get()->SetApplicationTitle(LOCTEXT("AppTitle", "Slate Viewer"));

	////////
	/// This creates the actual slate window down below
	/// We've also had success removing all the Sate code and using Dear ImGui's DX11 example for the UI layer
	////////
	CreateSlateUI();

	////////
	/// You can create UObjects to use here, no problem
	/// In this case it may be right to use the dreaded singleton pattern
	////////
	UDataStore* dataStore = NewObject<UDataStore>();

	// loop while the server does the rest
	while (!IsEngineExitRequested())
	{
		////////
		/// If you have any exit conditions other than closing the slate window, check them here
		/// (This example is contrived)
		////////
		// if (dataStore->RunningTime > 100.f)
		// {
		// 	RequestEngineExit(TEXT("Hit the time limit"));
		// }

		// In case something flagged "should request exit" but didn't flag "requesting exit"
		BeginExitIfRequested();

		// In case any of the above triggered an exit condition, we don't want to run the main loop again
		if (IsEngineExitRequested())
		{
			continue;
		}

		////////
		/// If you have any work to do inside the main loop, here's the place
		////////
		// dataStore->RunningTime += FApp::GetDeltaTime();

		// Let the game thread and slate application tick
		FTaskGraphInterface::Get().ProcessThreadUntilIdle(ENamedThreads::GameThread);
		FStats::AdvanceFrame(false);
		FTSTicker::GetCoreTicker().Tick(FApp::GetDeltaTime());
		FSlateApplication::Get().PumpMessages();
		FSlateApplication::Get().Tick();
		FPlatformProcess::Sleep(0.01);

		GFrameCounter++;
	}

	FCoreDelegates::OnExit.Broadcast();
	FSlateApplication::Shutdown();
	FModuleManager::Get().UnloadModulesAtShutdown();

	GEngineLoop.AppPreExit();
	GEngineLoop.AppExit();

	return 0;
}

void CreateSlateUI()
{
	const TSharedRef<SWindow> testWindow = SNew(SWindow)
	.ClientSize(FVector2D(640,480))
	.AutoCenter(EAutoCenter::PrimaryWorkArea)
	[
		SNew(STextBlock)
		.Text(FText::FromString(TEXT("Hello world!")))
	];
	FSlateApplication::Get().AddWindow( testWindow );
}

#undef LOCTEXT_NAMESPACE
