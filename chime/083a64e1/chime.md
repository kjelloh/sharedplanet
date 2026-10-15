# Todo: Programming - Find a way to use lastest boost libraries in RAD Studio

```#083a64e1``` *As of 2015-12-12 20:03*

[mail plain/text](mail.txt)

{% raw %}
RAD Studio XE7 ships with Boost 1.39 for Win32 and 1.55 for WIn64. And RAD Studio 10 ships with boost 1.55 for both win32 and win64 (by using Clang compiler 3.3 for both target environments). But what if we would like to use the latest boost library (1.59 as of dec 2015)?

A) Try using CMake to build boost libraries with the latest Clang compiler for windows (should enable linking from RAD Studio Clang projects)?

==&gt; Boost Build seem to define a toolset for Clang (although does it work on windows)?

==&gt; Install CLang on Windows machine (See “odo: Programming - Consider to understand and try out the LLVM tool chain on windows?”)

==&gt; Try to build the boost libraries using clang toolset

a) Boost build does not seem to list a clang toolset (<http://www.boost.org/build/doc/html/bbv2/reference/tools.html>)

b) Buit this thread talks about toolset=clang on MAC (<http://stackoverflow.com/questions/17884344/why-does-boost-compilation-fails-with-clang>)

c) It refers to this site about toolset=clang (<http://hnrkptrsn.github.io/2013/02/26/c11-and-boost-setup-guide/>)

d) Tried a shot in the dark

&gt;cd C:\\temp\\boost_1_59_0

&gt;b2 toolset=clang

==&gt; Failed with a lot of errors (make seem broken by missing correct reference to include header files?)

e) Clue? C:\\temp\\boost_1_59_0\\tools\\build\\src\\tools\\clang.jam chooses between clang-darwin and clang-linux?

feature.extend toolset : clang ;  
feature.subfeature toolset clang : platform : : propagated link-incompatible ;

rule init ( \* : \* )  
{  
if &#91; os.name &#93; = MACOSX  
{  
toolset.using clang-darwin :  
$(1) : $(2) : $(3) : $(4) : $(5) : $(6) : $(7) : $(8) : $(9) ;  
}  
else  
{  
toolset.using clang-linux :  
$(1) : $(2) : $(3) : $(4) : $(5) : $(6) : $(7) : $(8) : $(9) ;  
}  
}

f) Clue? C:\\temp\\boost_1_59_0\\tools\\build\\src\\tools\\clang-win.jam seem to extend msvc (Visual Studio)= toolset?

…

feature.extend-subfeature toolset clang : platform : win ;

…

toolset.inherit-generators clang-win &lt;toolset&gt;clang &lt;toolset-clang:platform&gt;win : msvc ;  
toolset.inherit-flags clang-win : msvc : &lt;debug-symbols&gt;on/&lt;debug-store&gt;object &lt;asynch-exceptions&gt;off &lt;asynch-exceptions&gt;on : YLOPTION ;  
toolset.inherit-rules clang-win : msvc ;  
…

g) Seems very unclear if this file is even viable anymore?

h) Clue? May we tamper with C:\\temp\\boost_1_59_0\\tools\\build\\src\\tools\\borland.jam?

feature.extend toolset : borland ;

rule init ( version ? : command \* : options \* )  
{  
local condition = &#91; common.check-init-parameters borland :  
version $(version) &#93; ;

local command = &#91; common.get-invocation-command borland : bcc32.exe  
: $(command) &#93; ;

common.handle-options borland : $(condition) : $(command) : $(options) ;

if $(command)  
{  
command = &#91; common.get-absolute-tool-path $(command&#91;-1&#93;) &#93; ;  
}  
root = $(command:D) ;

flags borland.compile STDHDRS $(condition) : $(root)/include/ ;  
flags borland.link STDLIBPATH $(condition) : $(root)/lib ;  
flags borland.link RUN_PATH $(condition) : $(root)/bin ;  
flags borland .root $(condition) : $(root)/bin/ ;  
}

i) What happens if we define the compiler to be the RAD Studio clang compiler BCC64?

borland.compile.c++ bin.v2\\libs\\atomic\\build\\borland\\debug\\link-static\\threading-multi\\lockpool.obj  
bcc64: warning: unknown warning option '-WM-'  
bcc64: error: unsupported option '-V x-'  
bcc64: error: unsupported option '-V e-'  
bcc64: error: unsupported option '-b -'  
Embarcadero Technologies Inc. bcc64 version 3.1 (34288.0798eef.b47f481) (based on LLVM 3.1svn)  
Target: x86_64-pc-win32-elf  
Thread model: posix

"bcc64.exe" -j5 -g255 -q -c -P -a8 -Vx- -Ve- -b- -v -Od -tWC -tWR -tWC -WM- -tWM -DBOOST_ALL_NO_LIB=1 -DBOOST_ATOMIC_SOURCE -DBOOST_ATOMIC_STATIC_LINK=1 -DBOOST_USE_WINDOWS_H -D_WIN32_WINNT=0x0500 -I"." -I"C:\\Program Files (x86)\\Embarcadero\\Studio\\15.0/include/" -o"bin.v2\\libs\\atomic\\build\\borland\\debug\\link-static\\threading-multi\\lockpool.obj" "libs\\atomic\\src\\lockpool.cpp"

...failed borland.compile.c++ bin.v2\\libs\\atomic\\build\\borland\\debug\\link-static\\threading-multi\\lockpool.obj...  
...skipped &lt;pbin.v2\\libs\\atomic\\build\\borland\\debug\\link-static\\threading-multi&gt;libboost_atomic-bcb-mt-d-1_59.lib for lack of &lt;pbin.v2\\libs\\atomic\\build\\borland\\debug\\link-static\\threading-multi&gt;lockpool.obj...  
...skipped &lt;pstage\\lib&gt;libboost_atomic-bcb-mt-d-1_59.lib for lack of &lt;pbin.v2\\libs\\atomic\\build\\borland\\debug\\link-static\\threading-multi&gt;libboost_atomic-bcb-mt-d-1_59.lib...  
borland.compile.c++ bin.v2\\libs\\system\\build\\borland\\debug\\link-static\\threading-multi\\error_code.obj  
bcc64: error: unsupported option '-V x-'  
bcc64: error: unsupported option '-V e-'  
bcc64: error: unsupported option '-b -'  
Embarcadero Technologies Inc. bcc64 version 3.1 (34288.0798eef.b47f481) (based on LLVM 3.1svn)  
Target: x86_64-pc-win32-elf  
Thread model: posix

j) So bcc64 is now called (edited had effect)!

k) But bcc64 does not accept provided options and it is instructed to generate obj-files?

actions compile.c++

{

"$(CONFIG_COMMAND)" -j5 -g255 -q -c -P -a8 -Vx- -Ve- -b- $(OPTIONS) -D$(DEFINES) -I"$(INCLUDES)" -I"$(STDHDRS)" -o"$(&lt;)" "$(&gt;)"

}

l) We conclude:

CONFIG_COMMAND == “bcc64"

OPTIONS = "-v -Od -tWC -tWR -tWC -WM- -tWM"

DEFINES = "BOOST_ALL_NO_LIB=1 BOOST_ATOMIC_SOURCE BOOST_ATOMIC_STATIC_LINK=1 BOOST_USE_WINDOWS_H _WIN32_WINNT=0x0500"

(i.e. -D$(DEFINES) == "-DBOOST_ALL_NO_LIB=1 -DBOOST_ATOMIC_SOURCE -DBOOST_ATOMIC_STATIC_LINK=1 -DBOOST_USE_WINDOWS_H -D_WIN32_WINNT=0x0500")

INCLUDES == . C:\\Program Files (x86)\\Embarcadero\\Studio\\15.0/include/

STDHDRS ==

(i.e. -I"$(INCLUDES)” = -I"." -I"C:\\Program Files (x86)\\Embarcadero\\Studio\\15.0/include/" -I"$(STDHDRS)")

-o"$(&lt;)” == -o"bin.v2\\libs\\atomic\\build\\borland\\debug\\link-static\\threading-multi\\lockpool.obj"

"$(&gt;)” = "libs\\atomic\\src\\lockpool.cpp"

*… \*consider to continue from here\*… ??*

==&gt; The build libraries should be compatible with RAD Studio (allowing code to link to generated boost libraries)?

B) Try using CMake to generate Borland Make files to build boost libraries using RAD Studio?

==&gt; Find the CMake attempts to build boost libraries (there seem to be work done and a vision to use CMake in future boost directory structure)  
==&gt; The use CMake to generate Borland MAKE files for boost library build (install Clang and set compiler CC to BCC32C or BCC64)  
==&gt; Now try to build boost libraries using MAKE?

==&gt; The build libraries now surely is linkable from RAD Studio code?

C) Try using RAD Studio to compile VCL/Fmx patrs and CLang to build boost library/C++11 parts and link using CMake LLVM C++ linker?

==&gt; Consider to use RAD Studio to build VCL/Fmx code bases only  
==&gt; Have RAD Studio parts interface externally build C++11/Boost based code  
==&gt; Use CMake to compile external C++11/boost based code and link with RAD Studio VCL/Fmx code.  
==&gt; Note: Would we be able to debug such code in RAD Studio (i.e. does externally compiled code provide correct debug info to enable debugger to show source code)?

==&gt; CMake (or other windows RAD environment) must now be used as the build environment (RAD Studio only for VCL/Fmx parts)

...

Consider to try these paths to see if some (or any) would work to enable RAD Studio development using the lastest boost libraries?  
...

{% endraw %}
