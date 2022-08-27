This is a pretty minimal "Hello world!" version of a standalone Unreal program showing a Slate window.

To use drop this whole folder into the LyraStaterGame/Source folder, go back up a folder to the LyraStarterGame.uproject, right-click and Generate Project Files. In your editor set TestProgram as your build target and hit Run or Debug.

Most of this code is based around the SlateViewer program in the Engine/Source/Programs directory.

You can omit the Slate code entirely and it will work as a headless application.

Of note, this does NOT include the core Unreal engine module - so while you can use UObjects without issue some features that are defined in the Engine module (such as FTickableGameObject) are not available.

This is provided as an example working implementation. I'm sure there are plenty of other restrictions and weird cases I've not run into yet, and will likely not be able to help you figure out.

Good luck!