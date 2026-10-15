# Todo: Programming - Consider tro build c++ boost libraries from source?

```#3439a8b8``` *As of 2015-12-12 14:30*

[mail plain/text](mail.txt)

{% raw %}
Would it not be nice to be able to build the latest boost c++ libraries from source in both Visual Studion and RAD Studio?

1) Boost libraries are build using Boost.Build (jam scripting language files) and regression tested using extended framework based on Git (get source files), b2 (jam based build) and Python (execute regression testing)

==&gt; See “[Todo: Programming - Consider to set up and run regression tests for boost on VS 2015 and RAD Studio XE7 (10)?](../20eb2a57/chime.md)” for boost library regression testing.

2) So what compilers are supported?

==&gt; (<http://www.boost.org/users/history/version_1_59_0.html>)

“Compilers Tested

Boost's primary test compilers are:

• Linux:

• Clang: 3.4

• Clang, C++14: 3.6

• GCC: 4.4.7, 4.8.2, 4.9.3

• GCC, C++11: 4.4.7

• GCC, C++14: 4.9.3

• Intel: 15.0

• Windows:

• Visual C++: 8.0, 9.0, 10.0, 11.0, 12.0, 14.0

• Android:

• Clang: 3.6

• GCC: 4.8, 4.9

• SunOS:

• Sun: 6.0

• QNX:

• QCC: 4.4.2"

3) RAD Studion uses the Clang Compiler (<http://docwiki.embarcadero.com/RADStudio/Seattle/en/Clang-enhanced_C%2B%2B_Compilers>)

CompilerPlatformClang VersionLLVM Version[BCC32C](http://docwiki.embarcadero.com/RADStudio/Seattle/en/BCC32C)32-bit Windows3.33.3[BCC64](http://docwiki.embarcadero.com/RADStudio/Seattle/en/BCC64)64-bit Windows3.33.3[BCCIOSARM](http://docwiki.embarcadero.com/RADStudio/Seattle/en/BCCIOSARM)32-bit iOS3.13.1[BCCIOSARM64](http://docwiki.embarcadero.com/RADStudio/Seattle/en/BCCIOSARM64)64-bit iOS3.33.5[BCCAARM](http://docwiki.embarcadero.com/RADStudio/Seattle/en/BCCAARM)Android3.13.3

==&gt; They are one or more version behind then (boost 1.59 tested on Clang 3.4 and 3.6)?

4) This seem like a good starting point for windows boost (<http://www.boost.org/doc/libs/1_59_0/more/getting_started/windows.html>)?

==&gt; The final boost installation is documented to look like this

This is a sketch of the resulting directory structure:

**boost_1_59_0\\** .................*The “boost root directory”*

**index.htm** .........*A copy of [www.boost.org](http://www.boost.org) starts here*

**boost\\** .........................*All Boost Header files*

**lib\\** .....................*precompiled library binaries*

**libs\\** ............*Tests, .cpp*s*, docs, etc., by library*

**index.html** ........*Library documentation starts here*

**algorithm\\**

**any\\**

**array\\**

*…more libraries…*

**status\\** .........................*Boost-wide test suite*

**tools\\** ...........*Utilities, e.g. Boost.Build, quickbook, bcp*

**more\\** ..........................*Policy documents, etc.*

**doc\\** ...............*A subset of all Boost library docs*

5) First try to download and unzip 1.59 distribution (<http://sourceforge.net/projects/boost/files/boost/1.59.0/boost_1_59_0.zip/download> )

==&gt; Failed unzipping to “C:\\Users\\kjell-olov\\Documents\\Visual Studio 2015\\Projects\\boost_1_59_0” (path to long error).

==&gt; Success unzipping to “C:\\temp\\boost_1_59_0”

6) Boost libraries are built using the tool Boost.Build (<http://www.boost.org/build/doc/html/index.html>)

7) Building the actual boost libraries are made using the b2 command (that engages the Boost.Build application) (<http://www.boost.org/build/tutorial.html>)

==&gt; “What b2 does is interpreting Jamfiles”

==&gt; b2 starts of to find boost-build.jam in the current working directory (<http://www.boost.org/build/tutorial.html>)

BOOST_ROOT = $(.boost-build-file:D) ;  
BOOST_BUILD = &#91; MATCH --boost-build=(.\*) : $(ARGV) &#93; ;  
BOOST_BUILD ?= tools/build/src ;  
boost-build $(BOOST_BUILD) ;

==&gt; “The path after boost-build must refer to a directory which contains a file called bootstrap.jam” (i.e. in this case “tools/build/src” by default?)

8) Seems we may have to actually look into the source code of b2 to understand who “toolset” is defined?

==&gt; Download of latest b2 source seems to be here (<https://github.com/boostorg/build/releases/tag/2014.10>)

==&gt; Downloaded to “W:\\downloads\\boost-build”

== &gt;Copied to “C:\\Users\\kjell-olov\\Documents\\Visual Studio 2015\\Projects” for view in Visual Studio 2015.

==&gt; Here seem to be a good site for configuration of boost jam configuration (<http://www.boost.org/build/doc/html/bbv2/overview/configuration.html>)?

“On startup, Boost.Build searches and reads two configuration files: site-config.jam and user-config.jam. The first one is usually installed and maintained by a system administrator, and the second is for the user to modify. You can edit the one in the top-level directory of your Boost.Build installation or create a copy in your home directory and edit the copy.”.

9) This page seem to define some interesting leads to the build process using Visual Studio (<http://stackoverflow.com/questions/29450634/compile-boost-python-tutorial-with-vs-2015-ctp-5-and-python-3-5a-on-windows-10-t>)?

==&gt; The thread talks about editing “D:\\boost\\boost_1_59_0\\tools\\build\\src\\tools\\msvc.jam"

10) So, can we build the boost libraries using Visual Studio (<http://www.boost.org/doc/libs/1_59_0/more/getting_started/windows.html>)?

a) “5.1 Simplified Build from Source"

"If you wish to build from source with Visual C++, you can use a simple build procedure described in this section. Open the command prompt and change your current directory to the Boost root directory.”

“bootstrap.bat" command prepares the Boost.Build system for use. The “.\\b2" command invokes Boost.Build to build the separately-compiled Boost libraries.

&gt;cd C:\\temp\\boost_1_59_0

&gt;bootstrap

==&gt; The following happens:

C:\\temp\\boost_1_59_0&gt;bootstrap  
Building Boost.Build engine

Bootstrapping is done. To build, run:

.\\b2

To adjust configuration, edit 'project-config.jam'.  
Further information:

- Command line help:  
.\\b2 --help

- Getting started guide:  
<http://boost.org/more/getting_started/windows.html>

- Boost.Build documentation:  
<http://www.boost.org/build/doc/html/index.html>

C:\\temp\\boost_1_59_0&gt;

==&gt; And b2.exe, bjam.exe are created.

![](boost_bootstrap_result.tiff)

==&gt; I now initiated b2 to build the boost libraries (defaults to toolset msvc as I understand it)

&gt;.\\b2

b) The script succeeded and all librarries seem to be build

==&gt; Libraries are in “C:\\temp\\boost_1_59_0\\stage\\lib”

2015-12-10 15:11 8ˇ422 libboost_atomic-vc140-mt-1_59.lib  
2015-12-10 15:07 55ˇ620 libboost_atomic-vc140-mt-gd-1_59.lib  
2015-12-10 15:11 309ˇ854 libboost_chrono-vc140-mt-1_59.lib  
2015-12-10 15:07 2ˇ032ˇ020 libboost_chrono-vc140-mt-gd-1_59.lib  
2015-12-10 15:11 54ˇ984 libboost_container-vc140-mt-1_59.lib  
2015-12-10 15:07 192ˇ590 libboost_container-vc140-mt-gd-1_59.lib  
2015-12-10 15:11 304ˇ314 libboost_context-vc140-mt-1_59.lib  
2015-12-10 15:07 2ˇ166ˇ442 libboost_context-vc140-mt-gd-1_59.lib  
2015-12-10 15:11 332ˇ528 libboost_coroutine-vc140-mt-1_59.lib  
2015-12-10 15:07 2ˇ571ˇ206 libboost_coroutine-vc140-mt-gd-1_59.lib  
2015-12-10 15:11 712ˇ002 libboost_date_time-vc140-mt-1_59.lib  
2015-12-10 15:07 2ˇ941ˇ406 libboost_date_time-vc140-mt-gd-1_59.lib  
2015-12-10 15:11 1ˇ478 libboost_exception-vc140-mt-1_59.lib  
2015-12-10 15:07 29ˇ114 libboost_exception-vc140-mt-gd-1_59.lib  
2015-12-10 15:11 871ˇ938 libboost_filesystem-vc140-mt-1_59.lib  
2015-12-10 15:07 5ˇ927ˇ934 libboost_filesystem-vc140-mt-gd-1_59.lib  
2015-12-10 15:12 6ˇ555ˇ148 libboost_graph-vc140-mt-1_59.lib  
2015-12-10 15:07 16ˇ110ˇ586 libboost_graph-vc140-mt-gd-1_59.lib  
2015-12-10 15:12 474ˇ710 libboost_iostreams-vc140-mt-1_59.lib  
2015-12-10 15:07 1ˇ793ˇ570 libboost_iostreams-vc140-mt-gd-1_59.lib  
2015-12-10 15:12 8ˇ104ˇ870 libboost_locale-vc140-mt-1_59.lib  
2015-12-10 15:07 28ˇ718ˇ244 libboost_locale-vc140-mt-gd-1_59.lib  
2015-12-10 15:13 14ˇ820ˇ158 libboost_log-vc140-mt-1_59.lib  
2015-12-10 15:08 62ˇ344ˇ442 libboost_log-vc140-mt-gd-1_59.lib  
2015-12-10 15:14 24ˇ323ˇ224 libboost_log_setup-vc140-mt-1_59.lib  
2015-12-10 15:09 68ˇ719ˇ538 libboost_log_setup-vc140-mt-gd-1_59.lib  
2015-12-10 15:15 631ˇ862 libboost_math_c99-vc140-mt-1_59.lib  
2015-12-10 15:09 3ˇ748ˇ626 libboost_math_c99-vc140-mt-gd-1_59.lib  
2015-12-10 15:15 635ˇ302 libboost_math_c99f-vc140-mt-1_59.lib  
2015-12-10 15:09 3ˇ728ˇ294 libboost_math_c99f-vc140-mt-gd-1_59.lib  
2015-12-10 15:15 612ˇ376 libboost_math_c99l-vc140-mt-1_59.lib  
2015-12-10 15:09 3ˇ701ˇ304 libboost_math_c99l-vc140-mt-gd-1_59.lib  
2015-12-10 15:14 10ˇ440ˇ932 libboost_math_tr1-vc140-mt-1_59.lib  
2015-12-10 15:09 25ˇ509ˇ908 libboost_math_tr1-vc140-mt-gd-1_59.lib  
2015-12-10 15:15 10ˇ747ˇ402 libboost_math_tr1f-vc140-mt-1_59.lib  
2015-12-10 15:09 26ˇ053ˇ106 libboost_math_tr1f-vc140-mt-gd-1_59.lib  
2015-12-10 15:15 10ˇ378ˇ830 libboost_math_tr1l-vc140-mt-1_59.lib  
2015-12-10 15:09 25ˇ365ˇ564 libboost_math_tr1l-vc140-mt-gd-1_59.lib  
2015-12-10 15:17 260ˇ232 libboost_prg_exec_monitor-vc140-mt-1_59.lib  
2015-12-10 15:11 1ˇ914ˇ772 libboost_prg_exec_monitor-vc140-mt-gd-1_59.lib  
2015-12-10 15:15 8ˇ020ˇ022 libboost_program_options-vc140-mt-1_59.lib  
2015-12-10 15:09 24ˇ516ˇ316 libboost_program_options-vc140-mt-gd-1_59.lib  
2015-12-10 15:16 5ˇ193ˇ324 libboost_python-vc140-mt-1_59.lib  
2015-12-10 15:10 25ˇ033ˇ334 libboost_python-vc140-mt-gd-1_59.lib  
2015-12-10 15:16 131ˇ162 libboost_random-vc140-mt-1_59.lib  
2015-12-10 15:10 694ˇ706 libboost_random-vc140-mt-gd-1_59.lib  
2015-12-10 15:12 13ˇ012ˇ830 libboost_regex-vc140-mt-1_59.lib  
2015-12-10 15:07 41ˇ058ˇ180 libboost_regex-vc140-mt-gd-1_59.lib  
2015-12-10 15:16 9ˇ555ˇ330 libboost_serialization-vc140-mt-1_59.lib  
2015-12-10 15:10 31ˇ936ˇ074 libboost_serialization-vc140-mt-gd-1_59.lib  
2015-12-10 15:17 1ˇ047ˇ318 libboost_signals-vc140-mt-1_59.lib  
2015-12-10 15:10 5ˇ157ˇ190 libboost_signals-vc140-mt-gd-1_59.lib  
2015-12-10 15:11 75ˇ954 libboost_system-vc140-mt-1_59.lib  
2015-12-10 15:07 611ˇ998 libboost_system-vc140-mt-gd-1_59.lib  
2015-12-10 15:17 10ˇ711ˇ324 libboost_test_exec_monitor-vc140-mt-1_59.lib  
2015-12-10 15:11 35ˇ217ˇ748 libboost_test_exec_monitor-vc140-mt-gd-1_59.lib  
2015-12-10 15:11 1ˇ153ˇ248 libboost_thread-vc140-mt-1_59.lib  
2015-12-10 15:07 3ˇ893ˇ572 libboost_thread-vc140-mt-gd-1_59.lib  
2015-12-10 15:17 145ˇ098 libboost_timer-vc140-mt-1_59.lib  
2015-12-10 15:11 1ˇ229ˇ048 libboost_timer-vc140-mt-gd-1_59.lib  
2015-12-10 15:17 10ˇ626ˇ564 libboost_unit_test_framework-vc140-mt-1_59.lib  
2015-12-10 15:11 34ˇ253ˇ450 libboost_unit_test_framework-vc140-mt-gd-1_59.lib  
2015-12-10 15:17 39ˇ020ˇ556 libboost_wave-vc140-mt-1_59.lib  
2015-12-10 15:11 93ˇ458ˇ310 libboost_wave-vc140-mt-gd-1_59.lib  
2015-12-10 15:17 7ˇ345ˇ740 libboost_wserialization-vc140-mt-1_59.lib  
2015-12-10 15:10 22ˇ231ˇ364 libboost_wserialization-vc140-mt-gd-1_59.lib

10) So, how do we repeat this feat using RAD Studio Clang compiler?

…

11) There seem to be a move to go from Bost.Build (jam-files) to Boost.CMake (<https://svn.boost.org/trac/boost/wiki/CMakeModularizationStatus>)?

==&gt; This seem to be CMake home page (<https://cmake.org>)?

==&gt; It seems the CMake approach is “on halt” until the new superstructure of boost is in place (<https://github.com/boostorg/>)?

12) There is an ongoing project to make the boost libraries modular (<https://svn.boost.org/trac/boost/wiki/TryModBoost#InstallingModularBoost>)

==&gt; Modular boost still seem to use jam-build?

==&gt; CMake project is separate and seems to be on hold?

13) CMake seem kind of “sexy” and a future candidate to replace Boost.Build using jam (<https://cmake.org>)

14) Consider som paths to build boost libraries with/for RAD Studio

a) Try using CMake to generate Borland Make files to build boost libraries using RAD Studio?

b) Try using CMake to build boost libraries with the latest Clang compiler for windows (should enable linking from RAD Studio Clang projects)?

c) Try using RAD Studio to compile VCL/Fmx patrs and CLang to build boost library/C++11 parts and link using CMake LLVM C++ linker?

==&gt; Continued ==&gt; ”Todo: Programming - Find a way to use lastest boost libraries in RAD Studio"

…

Consider to continue this try in building boost libraries from source?

...

{% endraw %}
