# Todo: Programming - Consider to find out and document the "best" way to install and use C++ boost libraries with Visual Studio?

```#6872134d``` *As of 2016-09-05 17:49*

[mail plain/text](mail.txt)

{% raw %}
Consider it is a good idea to find out and document the “best” way to install and use the C++ Boost Libraries with Visual Studio C++ projects?

==&gt; Also see “[Todo: Programming - It seems C++ boost for Visual Studio is available using NuGet package manager?](../ed3ed911/chime.md)”

==&gt; Note: NuGet Boost Package does NOT seem to be a good idea?

1) Found information on boost web-site about ready-to-install files for windows (<https://sourceforge.net/projects/boost/files/boost-binaries/>)

==&gt; 160905 - Installed 1.61 with 64-bit binaries as provided by installer (<https://sourceforge.net/projects/boost/files/boost-binaries/1.61.0/boost_1_61_0-msvc-14.0-64.exe/download>)

==&gt; 160905 - Installed 1.61 with 32-bit binaries as provided by installer (<https://sourceforge.net/projects/boost/files/boost-binaries/1.61.0/boost_1_61_0-msvc-14.0-32.exe/download>)

==&gt; Note: it seems to work to install them “on top” of each other (See installer text below)?

==&gt; Note: mdvc-14 seem to refer to Visual Studio 2015 (which is version 14 for some curious reason)?

2) The Pre-built C++ Boost library for 1.61 seems to be the way to go?

==&gt; The 1.61 version seem to install to “C:\\local\\boost_1_61_0”?

==&gt; Note: The installer dialog seem to confirm in text that it is allowed to install multiple architecture versions of Boost into the same location?

![](<MSVC Boost 1.61 Install location.tiff>)

==&gt; The “Extract Files” seems to take a long time?

![](<MSVC Boost 1.61 Extracting Files takes a long time.tiff>)

2) To use Boost library in Visual Studio C++ project it seems we need to define Additional Include file path AND link to correct 32-bit/64-bit Boost binary (library)?

==&gt; 1) To compile using boost headers - set the Project Property &lt;C/C++&gt;/&lt;General&gt; “Additional Include Directories” to “C:\\local\\boost_1_61_0” (The root folder of the installed Boost package)

![](<Visual Studio Boost 1.61 Additional Includes setting.tiff>)

==&gt; 2.a) To link with 32-bit Boost 1.61 binaries - Set the Project Properties &lt;Linker&gt;/&lt;General&gt; “Additional Library Directories” to “C:\\local\\boost_1_61_0\\lib32-msvc-14.0” (the 64-bit binaries folder of the installed boost package)

![](<Visual Studio Boost 1.61 32-bit Additional Library path setting.tiff>)

==&gt; 2.b) To link with 64-bit Boost 1.61 binaries (NOT for windows 32-bit console apps) - Set the Project Properties &lt;Linker&gt;/&lt;General&gt; “Additional Library Directories” to “C:\\local\\boost_1_61_0\\lib64-msvc-14.0” (the 64-bit binaries folder of the installed boost package)

![](<Visual Studio Boost Library 1.61 Additional Library setting.tiff>)

==&gt; Note: Failure to define for Visual Studio how to link will result in a link error (not finding the Boost library required)

![](<Visual Studio Boost 1.61 link error when Bost linking is not correctly defined.tiff>)

==&gt; Example of link error when boost filesystem library is required to build a C++ project target (e.g., the filesystem example console application)

==&gt; Consider to use this simple (32 bit) Console Application to test boost compile-time and linkage to the installed Boost Libraries?

> #include "stdafx.h"

> #include &lt;iostream&gt;  
> #include &lt;boost/filesystem.hpp&gt;

> using namespace boost::filesystem;

> int main(int argc, char\* argv&#91;&#93;)  
> {  
> if (argc &lt; 2)  
> {  
> std::cout &lt;&lt; "Usage: tut1 path\\n";  
> return 1;  
> }  
> std::cout &lt;&lt; argv&#91;1&#93; &lt;&lt; " " &lt;&lt; boost::filesystem::file_size(argv&#91;1&#93;) &lt;&lt; '\\n';  
> return 0;  
> }

==&gt; If this program compiles and links without errors, then the Visual Studio settings should be correct?

…

These steps seem to work. Consider to update when needed for future versions of Visual Studio?

{% endraw %}
