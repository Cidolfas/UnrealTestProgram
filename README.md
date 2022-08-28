This is a pretty minimal "Hello world!" version of a standalone Unreal program showing a Slate window.

NO WARRANTY PROVIDED THIS IS FOR EXPERIMENTAL PURPOSES ONLY

## Instructions

Drop contents of this folder into a [Project Folder]/Source/TestProgram directory, go back up to your game's .uproject, right-click and Generate Project Files.

In your IDE set TestProgram as your build project and hit Run or Debug to build/run it. The generated .exe will be at [Project Folder]/Binaries/Win64/TestProgram.exe

This only works if you're building the engine from source, even though it does not require any modifications to the engine to work. The Unreal build system doesn't allow you to build program targets if you're using an installed engine.

Most of this code is based around the SlateViewer program in the Engine/Source/Programs directory.

You can omit the Slate code entirely and it will work as a headless application. I've had luck using it headless along with Dear ImGui.

Of note, this is NOT set up to include the core Unreal engine module when building - so while you can use UObjects without issue features that are defined in the Engine module (like FTickableGameObject) are not available.

This is provided as an example working implementation. I'm sure there are plenty of other restrictions and weird cases I've not run into yet, and will likely not be able to help you figure out. When in doubt: build it in Debug|Win64 profile, hook up the debugger, and step through code until you find what's not working right.

Good luck!


## Packaging

If you want to zip this up so that it can be executed like a standalone program - and not just as a tool in your game project - you have to set up the file structure very specifically. This is because things with the Program build target (like our standalone app) assume they can find UnrealEngine files at ../../../Engine relative to the executable. So you'll want to emulate that file structure in your standalone folder, and then copy over some corresponding folders from the engine source.

```
[Root Directory]
├───Engine
│   ├───Content
│   │   ├───Internationalization
│   │   │   └───icudt64l            <--- Copy this folder
│   │   ├───Slate                   <--- I don't know how much of this folder is needed
│   │   └───SlateDebug              <--- Same here
│   └───Shaders
│       └───StandaloneRenderer      <--- Copy this folder
└───[Project Name]
    └───Binaries
        └───Win64                   <--- Put your built .exe here (I also copied everything else in the binaries folder that shared a name with it)
```

Of those, you only need to include the Internationalization files over if you're running without Slate. The app will just crash without error if it cannot find those.
