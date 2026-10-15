# Todo: Programming - Consider to study contemporary available IDEs for C++ programming?

```#9c1df47d``` *As of 2016-07-16 18:43*

[mail plain/text](mail.txt)

{% raw %}
Watching a key node about CMake being the most popular make tool for C++ (<http://www.kitware.com/blog/home/post/983>) I noted one slide listing IDEs compatible with CMake.

-3) This open-source (build-to-use) Cross-platform C++ IDE “jucipp” may be worth testing out (<https://github.com/cppit/jucipp>)?

==&gt; 160716, Seems to be in interest now (appeared in the news os cppcast episode ([Episode 63: IncludeOS with Alfred Bratterud](http://cppcast.com/2016/07/alfred-bratterud/)))?

**WE ARE HERE...**

==&gt; Seems like we need to also install MSYS2 (a cygwin “predecessor” for native windows development) and use it to get/build/install jucipp (<https://github.com/cppit/jucipp/blob/master/docs/install.md>)?

==&gt; It seems to be based on clang AST?

==&gt; MSYS2 seem to be available as windows install package here (<http://msys2.github.io>)?

==&gt; The MSYS2 environment seems to be described at this wiki (<https://sourceforge.net/p/msys2/wiki/Home/>)?

“The name is a contraction of Minimal SYStem 2, and aims to provide support to facilitate using the bash shell, Autotools, revision control systems and the like for building native Windows applications using MinGW-w64 toolchains."

-2) Consider this page as a good source on contemporary IDE:s for C++ (Only Visual Studio Code is missing) (<http://www.slant.co/topics/796/compare/~microsoft-visual-studio_vs_code-blocks_vs_clion>)?

==&gt; Microsoft Visual Studio

==&gt; Code::Blocks

==&gt; Clion

==&gt; CodeLite

==&gt; Netbeans IDE

==&gt; KDevelop

==&gt; Eclipse CDT

-1) Imagine to model IDE:s as “cross world” tools for source-code-to-run-time chains of transformations?

==&gt; The IDE is an entity in an OS World.

==&gt; This entity can communicate with entities in the sub-worlds of the code chain?

==&gt; The source-code world pre-processor

==&gt; The translation-unit world compiler

==&gt; The run-time world debugger

==&gt; The debugger is normally able to bridge binary code back to the translation-unit world (bridged back to source-code world by the IDE)

==&gt; Optional source-code world refactoring tools

…

==&gt; This seem like a good model baed on a metaphor that is “easily” understandable and that reflects the problematic aspects of programming?

...

1) Decide on what Tool-chains to install on Windows

==&gt; Installed Visual Studio 2015 first (Seems tool-chains, e.g. LLVM/CLang, tries to integrate on installation)

==&gt; First launch activated product and Team Services using msn account log-in ([kjell-olov.hogdahl@itfied.se](mailto:kjell-olov.hogdahl@itfied.se) account)

==&gt; Installed the LLVM/CLang 3.8 tool chain that seem to be available here (<http://llvm.org/releases/3.8.0/LLVM-3.8.0-win64.exe>)

==&gt; Unknown Publisher (The LLVM installation is not code signed)

==&gt; Installed LLVM/CLang to “**C:\\Program Files\\LLVM**” (64-bit application)

==&gt; Release notes seem to be published here (<http://llvm.org/releases/3.8.0/docs/index.html>)

==&gt; Installed CMake that seem to be available here (<https://cmake.org/files/v3.5/cmake-3.5.0-win32-x86.msi>)

==&gt; Only 32-bit seems available for windows?

==&gt; Installed to “**C:\\Program Files (x86)\\CMake\\**” (32-bit application)

==&gt; CMake installer shows Unknown Publisher (Not code signed)

==&gt; Installed TDM-GCC GNU Toolchain for Windows that seem to be here ([http://sourceforge.net/projects/tdm-gcc/files/TDM-GCC%20Installer/tdm64-gcc-5.1.0-2.exe/download](<http://sourceforge.net/projects/tdm-gcc/files/TDM-GCC Installer/tdm64-gcc-5.1.0-2.exe/download>))

==&gt; The installation is not code signed (unknown publisher)

==&gt; They state that GCC on windows uses thread-library that requires License to be posted with distributed code?

“Additionally, threaded applications must ship with a freely distributable thread support DLL, provided as part of MinGW itself” (<http://www.mingw.org>)

==&gt; Installed to “**C:\\TDM-GCC-64**”

==&gt; This seem to be good leads to different GCC tool-chains on Windows (<http://stackoverflow.com/questions/21980774/what-is-the-difference-between-orwells-mingw-and-tdm-dev-c-versions>)

MinGW (Only 32-bit and dynamically linked runtime libraries?)

MinGW-w64 (64-bit but still dynamically linked runtime?)  
TDM-GCC (static linkage of runtime?)

2) Visual Studio 2015

==&gt; They seem to support Clang fronted in “Clang with Codegen in VS 2015 Update 1” (<https://blogs.msdn.microsoft.com/vcblog/2015/12/04/clang-with-microsoft-codegen-in-vs-2015-update-1/>)

==&gt; Consider to try it out?

**WE ARE HERE...**

3) RAD Studio 10 Seattle

==&gt; Seem to provide the “same” Clang features as XE8 ([http://docwiki.embarcadero.com/RADStudio/XE8/en/C%2B%2B11_Features_Supported_by_RAD_Studio_Clang-based_C%2B%2B_Compilers](http://docwiki.embarcadero.com/RADStudio/XE8/en/C++11_Features_Supported_by_RAD_Studio_Clang-based_C++_Compilers))?

==&gt; Seem to use Clang 3.3 for 32 and 64 bit windows ([http://docwiki.embarcadero.com/RADStudio/Seattle/en/Clang-enhanced_C%2B%2B_Compilers](http://docwiki.embarcadero.com/RADStudio/Seattle/en/Clang-enhanced_C++_Compilers))

4) Eclipse (<https://www.eclipse.org>)

==&gt; The base plug-in for C++ development seem to be the CDT?

==&gt; This seem to be the page where available Eclipse package downloads are published (<https://www.eclipse.org/downloads/>)?

==&gt; Installed C++ package for Windows 64 bit ([https://www.eclipse.org/downloads/download.php?file=/oomph/epp/mars/R2/eclipse-inst-win64.exe](https://www.eclipse.org/downloads/download.php?file=/technology/epp/downloads/release/mars/2/eclipse-cpp-mars-2-win32-x86_64.zip))

==&gt; Fun fact: Donation is accepted also in Bitcoins :)

==&gt; It comes with Mylyn integration (<http://www.eclipse.org/mylyn/>)

“Mylyn's task-focused interface reduces information overload and makes multitasking easy"

**WE ARE HERE...**

==&gt; What other plug-ins are available for Eclipse?

...

5) Cevelop free C++ IDE used by Peter Sommerland that seem to indicate it is a good up-to-date and alive C++11/14/17 IDE (<https://www.cevelop.com>)?

==&gt; Stumbled cross this Eclipse.based as it was used in talk “Peter Sommerlad “Variable Templates and Compile-Time Computation with C++14”” (<https://www.youtube.com/watch?v=DM-RXeiSCmc>)

“Cevelop extends Eclipse CDT with many additional features”.

==&gt; Installed cevelop Eclipse extension as available here (<https://www.cevelop.com/download/>), explicitly (<https://www.cevelop.com/cevelop/downloads/cevelop-1.4.0-201512021228-win32.win32.x86_64.zip>)

==&gt; This seem to be the installation instructions (<https://www.cevelop.com/cevelop/repara/tools/cevelop-installation-guide.pdf>)?

==&gt; The download page also shows instructions (simply download, extract and run from extracted folder)

==&gt; Thus - we need to manually copy the unzipped folder to a fix location.

==&gt; I moved the folder to “"

==&gt; Cevelop seem to start as an App of its own (does not start Eclipse IDE)?

==&gt; Develop requires its own configuration of compiler to use.

==&gt; It does NOT mention LLVM/Clang in its Help for compiler selection.

“For windows, MinGW and Cygwin are the two main platform choices for acquiring the GNU toolchain. It is important to understand the difference between them. Cygwin produces executables that use the Cygwin POSIX runtime. Note that this runtime is GPL licensed. MinGW produces native Windows executables that do not require a separate runtime.”

==&gt; It seems to find the MinGW tool-chain (lists it when creating a new C++ project)

==&gt; Q: How do we get the LLVM into Cedevelop?

==&gt; It shows C++14 support by default (creating Project using the wizard and the MinGW toolchain)

==&gt; Made it compile and run - but it did NOT by default (had to wrestle to setup and run-configuration)

==&gt; Why does it not “know” what to run?

==&gt; I had may project that builds an exe so why does it not default to running the exe?

==&gt; I had to manually set the exe to be the one to run in my created runtime configuration.

… Still far from an ideal IDE in my opinion?

6) Consider Emacs as C++ IDE (<https://www.gnu.org/software/emacs/>)?

==&gt; Consider to be inspired by this talk “Emacs as a C++ IDE" (<https://channel9.msdn.com/Events/CPP/CppCon-2015/CPPConD02V009>)?

==&gt; At 4:00 “Why not Emacs?”

==&gt; You need to tinker with it to make it work

==&gt; Out-of-the-box experience less than ideal.

==&gt; At 05:00 IDEs for Emacs

==&gt; CTags, ETags, CScope “no-good” (can’t handle large projects and are not compilers nor build environments = knows to little)

==&gt; rtags is awesome (leverage on clang and runs as a local server)

==&gt; Ask CMake about project settings to correctly understand the code (search paths, macros, compiler settings)

==&gt; At 9:00 - Átila neves contribution “make-ide”

==&gt; It is available at github (<https://github.com/atilaneves/cmake-ide>)

> > “cmake-ide is a package to enable IDE-like features on Emacs for CMake projects. This includes autocompletion and on-the-fly syntax checking in Emacs for CMake projects with minimal configuration. It uses other packages to do its heavy lifting, in a combination of:

> > • rtags

> > • flycheck

> > • auto-complete-clang

> > • company-clang

> > • irony"

==&gt; It calls CMake to generate a "compilation database" in Json-format (and then use it)

==&gt; This means the IDE gets “Compiler IDE” features (it knows the code in the same way CMake/Compiler knows it)

==&gt; At 12:30 he shows IDE access to pre-processing results

==&gt; Seem to engage the rtags-server?

==&gt; The rtags for Emacs seem to live at Github here (<https://github.com/Andersbakken/rtags>)?

“A c/c++ client/server indexer for c/c++/objc&#91;++&#93; with integration for Emacs based on clang.”

==&gt; Seem to rely on clang diagnostics (<http://clang.llvm.org/diagnostics.html>)?

==&gt; At 14:30 about setting-up cmake-ide to use rtags server/client

==&gt; Just need to compile/install rtags and have them accessible in the PATH - and cmake-ide will find and call them automatically.

**WE ARE HERE...**

7) Sublime Text (<http://www.sublimetext.com>)

==&gt; 64 bit installer for Sublime Text 3 9-Feb 2016 seem to be available here ([https://download.sublimetext.com/Sublime%20Text%20Build%203103%20x64%20Setup.exe](<https://download.sublimetext.com/Sublime Text Build 3103 x64 Setup.exe>))?

==&gt; Installer is Code Signed “Sublime HQ Pty Ltd” ok.

==&gt; Installs to “**C:\\Program Files\\Sublime Text 3**”

==&gt; First try kind of disappointing.

==&gt; Look nice but not evident how it handles projects and workspaces.

==&gt; Adding a folder to project added ALL files (Who do we tell it what files are source)?

==&gt; Where should we store project and workspace files?

==&gt; How do we configure a tool-chain?

==&gt; This youtube video seem to show how to use Sublime Text for coding in C++ (<https://youtu.be/XUChvqDj59Q>)?

==&gt; The Tool-chain must be in the PATH environment (the bin-folder of the tool-chain)?

==&gt; Is that enough?

==&gt; How do we configure different tool chains?

==&gt; How do we build complete projects?

==&gt; Do we need to write make-scripts?

==&gt; This may be a good start to understand Sublime text (<https://www.sublimetext.com/docs/3/projects.html>)?

“Projects in Sublime Text are made up of two files: the sublime-project file, which contains the project definition, and the sublime-workspace file, which contains user specific data, such as the open files and the modifications to each. As a general rule, the sublime-project file would be checked into version control, while the sublime-workspace file would not.”

==&gt; The build system seem to refer to this site (<http://docs.sublimetext.info/en/latest/>)?

==&gt; Hm, Sublime Text seem to be under development and the build system as (so far) primitive to say the least (<https://forum.sublimetext.com/t/build-systems/14435>)?

**CONSIDER TO USE SUBLIME TEXT FOR EDITING ONLY?**

*“Sublime Text is available for OS X, Windows and Linux. “*

==&gt; Seem to have some really cool context aware (like changing all references to a c++ identifier whilst changing the declared name)?

==&gt; This seem like a good page with video tutorials showing its capabilities (<http://code.tutsplus.com/courses/perfect-workflow-in-sublime-text-2>)?

==&gt; Costs 70 USD (per user, fre number of computers and platforms) (<https://www.sublimetext.com/buy> )

8) JetBrains CLion (<https://www.jetbrains.com/clion/>)

==&gt; They have a 30 days free trial.

==&gt; This thread seem to have good leads about usability of Lion (<http://clang-developers.42468.n3.nabble.com/Review-CLion-a-great-way-to-develop-on-clang-td4043928.html>)?

==&gt; CLion C++ seem to be based on CMake (it synchronises with CMake files/environment)?

==&gt; CLion is written in Java and has its own C++ parser (not LLVM AST)?

...

9) KDevelop (<https://www.kdevelop.org>)

==&gt; IDE for Unix flavours and descendants including MAC OS X (not Windows)

==&gt; Seems tightly integrated with LLVM and CMake?

10) Kate (<http://kate-editor.org>)

*“Kate is a multi-document editor part of KDE since release 2.2. Being a KDE application, Kate ships with network transparency, as well as integration with the outstanding features of KDE. Choose it for viewing HTML sources from konqueror, editing configuration files, writing new applications or any other text editing task. You still need just one running instance of Kate.”*

==&gt; Seem to focus on Unix flavours and descendants including MC OS X (<http://kate-editor.org/get-it/>)

==&gt; Kate seem to be part of KDE () (<https://en.wikipedia.org/wiki/KDE>)?

==&gt; “K Desktop Environment (KDE) was founded in 1996 by Matthias Ettrich”

==&gt; KDE is based on the QT Framework (<https://en.wikipedia.org/wiki/Qt_(software)> )

==&gt; “Qt is used mainly for developing application software with graphical user interfaces (GUIs)"

==&gt; The KDE community seem to be active (<https://forum.kde.org/viewforum.php?f=105>)?

==&gt; KDE for windows has not been updated since may 2013, version 4.10.2 (<https://windows.kde.org>)

12) Code::Blocks (<http://www.codeblocks.org>)

==&gt; First start-up kind of a disappointment.

==&gt; It failed to find by actual 64-bit LLVM

==&gt; It failed to let me “auto-import” the LLVM tool-chain (Seems I have to configure every thing manually for a compiler it failed to find itself)?

==&gt; It has a kind of “old school” in GUI design (cluttered and “old primitive windows” controls)?

**WAIT WITH USING CODEBLOCKS FOR NOW...**

==&gt; All downloads for Codeblocks 16.01 seem to be listed here (<http://www.codeblocks.org/downloads/26>)?

==&gt; Binary install for Windows seem to be available here (<http://sourceforge.net/projects/codeblocks/files/Binaries/16.01/Windows/codeblocks-16.01-setup.exe>)?

==&gt; Win32 version?

==&gt; Install file not code signed (unknown publisher)

==&gt; Installed to “**C:\\Program Files (x86)\\CodeBlocks**” (Uninstalled again - see above)

==&gt; Autoconfig detects some, but not all compilers installed on the machine.

==&gt; It finds LLVM compiler of RAD Studio (!)

==&gt; It does NOT find the installed LLVM 3.8 (?)

==&gt; Probably because RAD Studio occurs before LLVM in the PATH variable?

==&gt; The Ubuntu distribution seem to be available here (<https://launchpad.net/~damien-moore/+archive/ubuntu/codeblocks-stable>)?

==&gt; Lastest update 7/12 2015

“Code::Blocks is a free C, C++ and Fortran IDE built to meet the most demanding needs of its users. It is designed to be very extensible and fully configurable. Finally, an IDE with all the features you need, having a consistent look, feel and operation across platforms.”

13) CodeLite (<http://codelite.org>)

**==&gt; CODELITE IS NOT COMPATIBLE WITH DEFAULT WINDOWS INSTALL PATH IDIOM - SKIP THIS PRODUCT UNTIL IT FIX THIS**

“When installing a compiler under Windows, DO NOT INSTALL IT IN A FOLDER WITH A SPACE IN ITS PATH”

==&gt; Latest Weekly build 29 Feb 2016 to Windows 10 Machine (<http://downloads.codelite.org/downloads.php?windows_weekly_64>)

==&gt; It has a Setup Wizard that seems able to scan for installed compilers.

==&gt; What Compilers do CodeLite integrate with?

==&gt; It seem to integrate with GCC and Clang (<http://codelite.org/AddNewCompiler/AddNewCompiler>)

==&gt; They recommend TDM-GCC GNU Toolchain for Windows that seem to be here ([http://sourceforge.net/projects/tdm-gcc/files/TDM-GCC%20Installer/tdm64-gcc-5.1.0-2.exe/download](<http://sourceforge.net/projects/tdm-gcc/files/TDM-GCC Installer/tdm64-gcc-5.1.0-2.exe/download>))

==&gt; They recommend LLVM/CLang 3.5 that seem to be available here (<http://www.llvm.org/releases/3.5.0/LLVM-3.5.0-win32.exe>)

"A Free, open source, cross platform C,C++,PHP and Node.js IDE”

“Generic support for compilers with built-in support for GCC/clang/VC++”

==&gt; Seem to have some nice refactoring skills for C++ (<http://codelite.org/Main/ReadMore>)

...

Consider to study and try out these IDEs to see how they are compared to RAD Studio and Visual Studio for core c++ work?

a) Sublime Text is the one that rally gets me curious! **\*\* WE ARE HERE \*\***

{% endraw %}
