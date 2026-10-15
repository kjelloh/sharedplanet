# Todo: C++ Visual Studio - Consider ways to separate source files and output files in the same way Xcode does (enabling projects to be synced excluding the generated files)

```#14271c3e``` *As of 2017-03-18 16:05*

[mail plain/text](mail.txt)

{% raw %}
It seems we will have a hard time to sync Visual Studio projects, e.g., using Sync or DropBox, as Visual Studio puts all generated files in sub-folders of the folder with the solution and source files?

1) Consider we want to sync only the project source files (not the overhead of the generated files like object files, linker files and project database files)?

2) Consider to configure Visual Studio projects to put generated files locally while having source files Synced (shared)?

==&gt; Consider this page as having good leads to Visual Studio configuration macros (<https://msdn.microsoft.com/en-us/library/c02as0cs.aspx>)?

==&gt; It seems we may at least see all available macros in any &lt;Edit&gt; dialog of a project property?

![](<Visual Studio Macro Value Listing.tiff>)

3) Consider to understand a Visual Studio Project folder structure?

==&gt; This seems to be the contents of a fresh (newly created) solution for a console win32 application?

> C:\\Users\\kjell-olovhogdahl\\Documents\\Visual Studio 2017\\Projects\\ConsoleApplication2&gt;tree /F  
> Folder PATH listing  
> Volume serial number is 000000B7 D49B:BB89  
> C:.  
> │ ConsoleApplication2.sln  
> │  
> ├───.vs  
> │ └───ConsoleApplication2  
> │ └───v15  
> │ │ .suo  
> │ │ Browse.VC.db  
> │ │ Browse.VC.opendb  
> │ │  
> │ └───ipch  
> │ └───AutoPCH  
> │ └───CONSOLEAPPLICATION2-88a163c  
> │ └───CONSOLEAPPLICATION2-247358f3  
> │ CONSOLEAPPLICATION2.ipch  
> │  
> └───ConsoleApplication2  
> ConsoleApplication2.cpp  
> ConsoleApplication2.vcxproj  
> ConsoleApplication2.vcxproj.filters  
> ReadMe.txt  
> stdafx.cpp  
> stdafx.h  
> targetver.h

> C:\\Users\\kjell-olovhogdahl\\Documents\\Visual Studio 2017\\Projects\\ConsoleApplication2&gt;

==&gt; NOTE: The .vs folder seems to be created a “Hidden” and “Read Only” by Visual Studio (at least I did have to remove the Hidden attribute to be able to use Tree to list it)?

==&gt; Its seems if I remove the .vs folder then Visual Studio recreates it (or crashes)?

==&gt; At least it was re-cerated when removed for this simple console application.

==&gt; But for the project below VS crashes if I removed the .vs folder (more elaborate dependency on the database in that project?)

==&gt; This seems to be the contents of a “cleaned” solution folder?

> C:\\Users\\kjell-olovhogdahl\\Documents\\Visual Studio 2017\\Projects\\Cppcon2016McNellisCoroutine_co_await&gt;tree /F  
> Folder PATH listing  
> Volume serial number is 00000092 D49B:BB89  
> C:.  
> │ Cppcon2016McNellisCoroutine_co_await.sln  
> │  
> ├───.vs  
> │ └───Cppcon2016McNellisCoroutine_co_await  
> │ └───v15  
> │ │ Browse.VC.db  
> │ │ Solution.VC.db  
> │ │ Solution.VC.db-shm  
> │ │ Solution.VC.db-wal  
> │ │  
> │ └───ipch  
> │ └───AutoPCH  
> │ └───RESUMABLE_GENERATOR_T_EXAMPLE-b41d13d3  
> │ └───RESUMABLE_GENERATOR_T_EXAMPLE-c091230a  
> ├───Cppcon2016McNellisCoroutine_co_await  
> │ │ Cppcon2016McNellisCoroutine_co_await.cpp  
> │ │ Cppcon2016McNellisCoroutine_co_await.vcxproj  
> │ │ Cppcon2016McNellisCoroutine_co_await.vcxproj.filters  
> │ │ ReadMe.txt  
> │ │ stdafx.cpp  
> │ │ stdafx.h  
> │ │ targetver.h  
> │ │  
> │ └───Debug  
> │ │ Cppcon2016McNellisCoroutine_co_await.Build.CppClean.log  
> │ │ Cppcon2016McNellisCoroutine_co_await.log  
> │ │  
> │ └───Cppcon20.D5A112AA.tlog  
> └───Debug

> C:\\Users\\kjell-olovhogdahl\\Documents\\Visual Studio 2017\\Projects\\Cppcon2016McNellisCoroutine_co_await&gt;

==&gt; Consider to understand what determines the location and content of the “.vs” folder?

==&gt; It seems all the project source files are in the project sub-folder (In this case Cppcon2016McNellisCoroutine_co_await)?

==&gt; Consider to understand what determines the location and content of the project sub-folder “Debug” (It is a “Configuration” sub-folder)?

==&gt; Consider to understand what determines the location and content of the solution sub-folder “Debug” (It is a “Configuration” sub-folder)?

3) Consider we will not be able to relocate the “intermediate” folder path because this is always relative the solution folder?

==&gt; Consider we may try to use an intermediate folder a “couple of levels up” to make it excluded from the shared directory tree?

==&gt; Kind of awkward and we will still be unable to have intermediate folder local to the virtual machine (separated from the VM host OS synced folder)?

{% endraw %}
