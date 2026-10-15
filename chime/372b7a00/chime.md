# Todo: Programming - Consider to compare 3D-Programming using Unity versus Unreal?

```#372b7a00``` *As of 2016-04-02 23:11*

[mail plain/text](mail.txt)

{% raw %}
So, what can we learn from studying how to 3D-program in Unity versus Unreal?

1) Seems Unreal is free and aims cross-platform at 3D C++ programming (<https://www.unrealengine.com/what-is-unreal-engine-4>)

“The 5% royalty starts after the first $3,000 of revenue per product per quarter. Pay no royalty for film projects, contracting and consulting projects such as architecture, simulation and visualisation.”

==&gt; Downloaded unreal installation from (<https://www.unrealengine.com/download?dismiss=%2Fdashboard>)

==&gt; Downloaded and installed Unreal to Windows 10 machine “C:\\Program Files (x86)\\Epic Games”

==&gt; Consider this page to start a simple C++ unreal project (<https://docs.unrealengine.com/latest/INT/Programming/QuickStart/index.html>)?

“

\* Create an Epic Games Account (if you don't already have one)  
\* Download and Run the Installer (Epic Games Launcher Set-Up Program)  
\* Sign into the Epic Games Launcher  
\* Install Unreal Engine  
\* Launch Unreal Engine "

==&gt; UE4 seem to be able to create a Visual Studio 2015 project (<https://docs.unrealengine.com/latest/INT/Programming/QuickStart/1/index.html>)

==&gt; The generated VS 2015 project seem to build a dll and a lib and exp file?

> 1&gt;------ Build started: Project: UE4, Configuration: BuiltWithUnrealBuildTool Win32 ------  
> 2&gt;------ Build started: Project: MyFirstUnrealProject, Configuration: Development_Editor x64 ------  
> 2&gt; Creating makefile for hot reloading MyFirstUnrealProjectEditor (game project files are newer)  
> 2&gt; Compiling game modules for hot reload  
> 2&gt; Parsing headers for MyFirstUnrealProjectEditor  
> 2&gt; Running UnrealHeaderTool "C:\\Users\\kjell-olovhogdahl\\Documents\\Unreal Projects\\MyFirstUnrealProject\\MyFirstUnrealProject.uproject" "C:\\Users\\kjell-olovhogdahl\\Documents\\Unreal Projects\\MyFirstUnrealProject\\Intermediate\\Build\\Win64\\MyFirstUnrealProjectEditor\\Development\\UnrealHeaderTool.manifest" -LogCmds="loginit warning, logexit warning, logdatabase error" -Unattended -WarningsAsErrors -installed  
> 2&gt; Reflection code generated for MyFirstUnrealProjectEditor in 2.9464339 seconds  
> 2&gt; Performing 3 actions (2 in parallel)  
> 2&gt; FloatingActor.cpp  
> 2&gt; MyFirstUnrealProject.generated.cpp  
> 2&gt; &#91;3/3&#93; Link UE4Editor-MyFirstUnrealProject-1225.dll  
> 2&gt; Creating library C:\\Users\\kjell-olovhogdahl\\Documents\\Unreal Projects\\MyFirstUnrealProject\\Intermediate\\Build\\Win64\\UE4Editor\\Development\\UE4Editor-MyFirstUnrealProject-1225.lib and object C:\\Users\\kjell-olovhogdahl\\Documents\\Unreal Projects\\MyFirstUnrealProject\\Intermediate\\Build\\Win64\\UE4Editor\\Development\\UE4Editor-MyFirstUnrealProject-1225.exp  
> 2&gt; -------- End Detailed Actions Stats -----------------------------------------------------------  
> 2&gt; Total build time: 14.24 seconds  
> ========== Build: 2 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========

==&gt; The exe-file seem to contain the exported symbols needed to statically link the dll as defined by the lib (<http://stackoverflow.com/questions/2727020/what-is-use-of-exp-and-what-is-the-difference-between-lib-and-dll>)?

==&gt; It seems Unreal (and other game engines) provide the graphical rendering of the “world” as driven by “scripts” in plug-ins (as for Unreal C++ written Dll:s)?

==&gt; The space-time and objects of the world are defined in and by the engine.

==&gt; The dynamic behaviour (actors) are defined by the scripts.

==&gt; Q: Why does not the world render in Windows 10 Parallel machine?

==&gt; When running the example “game” the window is black (the parallels machine is not correctly configured to output rendering on the visible screen)?

==&gt; This thread seem to state that Unreal Editor is untested under Windows on Parallels (<https://answers.unrealengine.com/questions/14433/editor-crash-on-launch.html>)?

==&gt; One comment is actually that VS requires Windows - and the reply seem to be to use MAC and Xcode instead?

*“We don't support running Windows version under Parallels. We've never tried that, I think. Is there any reason why can't you use Mac version of the editor?"*

**CONSIDER TO NOT USE GAMIMG ENGINES FOR NOW? **

==&gt; This does not seem the best way to implement 3D graphical user interface for other purposes (it is specialised for Games)?

*==&gt; The do not allow definition of graphical objects look-and-feel from code?*

*==&gt; It would be overkill for the Pandora C?+ view of code?*

*==&gt; Also, for Pandora, we need to be able to define the objects on-the-fly (very little we can pre-define and put into the engine?*

2) Unity seem to be mainly for c# and C++ requires a paid-for version (<https://www.quora.com/Can-I-use-C++-with-Unity3D-instead-of-C>)

==&gt; Visual Studio Community (Free) 2015 comes with configuration for Unity (in C#?) (<https://www.visualstudio.com/en-us/features/unitytools-vs.aspx>)?  
==&gt; Unity comes in Personal Edition (Free) and Professional Edition monthly subscription (<http://unity3d.com/get-unity>)?

==&gt; They seem to call programming for “Scripting”?

“SCRIPTING

• C# and JavaScript  
• Native Visual Studio integration  
• AI features with advanced automated path finding and Navigation Meshes”  
…

Consider to delve into features and possibilities and optionally try out C++ 3D-programming in Unreal?  
...

{% endraw %}
