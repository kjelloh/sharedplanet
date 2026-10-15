# Todo: Programming - Consider to understand and try out the LLVM tool chain on windows?

```#fa1f3850``` *As of 2015-12-12 18:21*

[mail plain/text](mail.txt)

{% raw %}
The LLVM project seem like a vital and interesting way to go to build on different platsforms, for different platforms, from different c-like languages (including fortran) to native machine code (e.g. exe on windows)?

1) RAD Studio now seem to use open source LLVM as its back-bone for C++ (for delphi to)?

2) Here seem to be a good place to read about building the llvm for windows using Visual Studio (<http://llvm.org/docs/GettingStartedVS.html>)?

==&gt; Download llvm source  
==&gt; Use CMake to generate Visual Studio solution files  
==&gt; Open generated solution file in Visual Studio and build the LLVM for windows.

3) Here seem to be “An Example Using the LLVM Tool Chain” (<http://llvm.org/docs/GettingStartedVS.html#id7>)

==&gt; Write hello.c program  
==&gt; Call clang to compile into hello.bc (llvm internal byte code)

&gt; C:\\..&gt; clang -c hello.c -emit-llvm -o hello.bc

==&gt; Run the byte code using the llvm

&gt; C:\\..&gt; lli hello.bc

==&gt; Compile byte code to native windows obj-code

&gt; C:\\..&gt; llc -filetype=obj hello.bc

==&gt; Link to exe-file using Visual Studio linker

&gt; C:\\..&gt; link hello.obj -defaultlib:libcmt

==&gt; The resulting exe-file may now be run in Windows from command prompt

&gt; C:\\..&gt; hello.exe

4) Clang seem to be available as installable for windows (both 32/64 bit) (<http://llvm.org/releases/download.html>)

==&gt; See “<http://llvm.org/releases/3.7.0/LLVM-3.7.0-win32.exe>”

==&gt; See “<http://llvm.org/releases/3.7.0/LLVM-3.7.0-win64.exe>”

![](LLVM_Install_not_signed.tiff)

==&gt; The LLVM install is not signed (approved anyway)

![](LLVM_Install_Add_to_PATH.tiff)

==&gt; Selected PATH to be updated with path to LLVM

==&gt; Installed to default “C:\\Program Files\\LLVM”

==&gt; The installation succeeded (e.g. clang)

5) Consider to build the LLVM from source using Visual Studio (<http://llvm.org/docs/GettingStartedVS.html#id6>)

&gt;cd C:\\subversion\\external

&gt;svn co <http://llvm.org/svn/llvm-project/llvm/trunk> llvm\\trunk

&gt;cd llvm

&gt;cd trunk

==&gt; The source code in repository <http://llvm.org/svn/llvm-project/llvm/trunk> is checked out to C:\\subversion\\external\\llvm\\trunk

Checked out revision 255432.

C:\\subversion\\external&gt;

==&gt; It took a couple of minutes and resulted in checked out folder of 323 MB.

![](llvm_subversion_folder_size.tiff)

==&gt; Installed CMake as documented in “Todo: Programming - Consider to understand and try out the LLVM tool chain on windows?”

==&gt; Started “cmake-gui.exe”

a) Selected “C:/subversion/external/llvm/trunk” as &lt;Where is the source code&gt;

b) pressed &lt;Configure&gt; and selected Generator “Visual Studio 14 2015” (The default one for current environment)

c) Pressed OK and CMake immediately started using &lt;Where to build the binaries&gt; set to “C:/Program Files (x86)/CMake/bin”

d) This fails (tries to write to C:/Program Files (x86)/CMake/bin for which it is not authorised as this is the windows install dierectory)

![](CMake-GUI_VS14_generate_to_deafult_bin_output_fails.tiff)

e) Changed &lt;Where to build the binaries&gt; to “C:\\subversion\\external\\llvm\\build”

==&gt; Now Configure caused CMake to run and work.

==&gt; It still showed RED errors but they disappeared when pressing configure again (it now run without errors).

*==&gt; Status: Tried command line below (not yet tried Visual Studio Solution generated here by CMake-GUI)... *

f) Tried the command line to have CMake build llvm (<http://llvm.org/docs/CMake.html>)

&gt;mkdir C:\\subversion\\external\\llvm\\build

&gt;cd C:\\subversion\\external\\llvm\\build

&gt;cmake C:/subversion/external/llvm/trunk

g) This seem to work (although console log showed a lot of “Not Found” and tests that failed)

-- Build files have been written to: C:/subversion/external/llvm/build

C:\\subversion\\external\\llvm\\build&gt;

![](CMake_generated_LLVM_Visual_Studio_Solution.tiff)

h) Started created solution LLVM-sln ok in Visual Studio

i) The Visual Studio project carries a log of projects and property files!

j) Made Visual Studio build the BUILD_ALL.

==&gt; It seems to go on and build all kinds of cross-platform tools (e.g. ARM processor stuff)

==&gt; Maybe there is some way to only build for C++ source and Windows target (32/64 bit) platforms?

==&gt; This build takes a very long time!

...

------ Build started: Project: ALL_BUILD, Configuration: Debug Win32 ------

Building Custom Rule C:/subversion/external/llvm/trunk/CMakeLists.txt  
CMake does not need to re-run because C:\\subversion\\external\\llvm\\build\\CMakeFiles\\generate.stamp is up-to-date.  
========== Build: 180 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========

==&gt; And “C:\\subversion\\external\\llvm\\build\\Debug\\bin” now carries all generated exe-files

==&gt; Note: The solution was by default set to Debug, Win32 (sigh - did not se that coming)

==&gt; NOTE: Clang does not seem to have been built (no clang.exe and no clang mentioned in Visual Studio build log)?

…

Consider to delve deeper into the LLVM framework on windows to see how it works and how useful it may turn out to be?

…

{% endraw %}
