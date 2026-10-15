# Todo: Programming - Consider to study the POCO C++ standard Internet protocol library (ftp, pop3)

```#3117a644``` *As of 2015-12-17 18:28*

[mail plain/text](mail.txt)

{% raw %}
Consider to check out the C++ POCO library for Internet protocol implementation?

1) This seem to be their home page (<http://pocoproject.org>)?

==&gt; Downloaded (<http://pocoproject.org/releases/poco-1.6.1/poco-1.6.1.zip>)

==&gt; Unzipped and placed at “C:\\temp\\poco-1.6.1” for a first try-out

2) This seem to be project home on source forge (<http://sourceforge.net/projects/poco/?source=directory>)?  
3) Is this library the way to go to implement ftp in Testbench app?

4) Tried to build the poco-libraries for windows

==&gt; Found info in “C:\\temp\\poco-1.6.1\\README” (opened in worded to handle unix linefeeds)

The basic directory layout is as follows:

build/ the build system for Unix/OpenVMS and additional utility scripts  
config/ build configurations for various Unix platforms  
rules/ common build rules for all platforms  
scripts/ build and utility scripts  
vms/ OpenVMS build system scripts  
vxconfig/ VxWorks build configurations

bin/ all executables (dynamic link libraries on Windows)  
bin64/ all 64-bit executables (and DLLs)

doc/ additional documentation

lib/ all libraries (import libraries on Windows)  
lib64/ all 64-bit libraries

CppUnit/ project and make/build files for the CppUnit unit testing framework  
doc/ additional documentation  
include/  
CppUnit/ header files for CppUnit  
src/ source files for CppUnit  
WinTestRunner/ Windows GUI for CppUnit

Foundation/ project and make/build files for the Foundation library  
include/  
Poco/ header files for the Foundation library  
src/ source files for the Foundation library  
testsuite/ project and make/build files for the Foundation testsuite  
src/ source files for the Foundation testsuite  
bin/ test suite executables  
samples/ sample applications for the Foundation library

XML/ project and make/build files for the XML library  
include/  
Poco/  
XML/ header files for the core XML library  
SAX/ header files for SAX support  
DOM/ header files for DOM support  
src/ source files for the XML library  
testsuite/ project and make/build files for the XML testsuite  
src/ source files for the XML testsuite  
bin/ test suite executables  
samples/ sample applications for the XML library

Net/ project and make/build files for the Net library  
include/  
Poco/  
Net/ header files for the Net library  
src/ source files for the Net library  
testsuite/ project and make/build files for the Net testsuite  
src/ source files for the Net testsuite  
bin/ test suite executables  
samples/ sample applications for the Net library

==&gt; “*To build from the command line, start the*

*Visual Studio .NET 2003 (or 2005/2008/2010) Command Prompt and cd to the directory where you  
have extracted the POCO C++ Libraries sources. Then, simply start the buildwin.cmd script  
*

*and pass as argument the version of visual studio (71, 80, 90 or 100)*”

==&gt; Started MSBuild Command prompt from Visual Studio installation (windows 8 Start Pane of apps)

==&gt; CD:ed to “C:\\temp\\poco-1.6.1\\”

&gt;cd \\temp\\poco-1.6.1\\

==&gt; Started command

&gt;buildwin 140

==&gt; The build executed (Note that Id did not edit the file “components” to disable/remove OpenSLL, MySQL ro any other add-on components)

==&gt; Seems to have succeeded (note that is seems to defaulted to win32 build, no 64-bit binaries built)

Directory of C:\\temp\\poco-1.6.1\\bin

2015-12-15 13:24 60ÿ928 CppUnit.dll  
2015-12-15 13:24 217ÿ600 CppUnitd.dll  
2015-12-15 13:28 1ÿ198ÿ592 PocoFoundation.dll  
2015-12-15 13:26 3ÿ452ÿ928 PocoFoundationd.dll  
2015-12-15 13:36 189ÿ440 PocoJSON.dll  
2015-12-15 13:36 712ÿ192 PocoJSONd.dll  
2015-12-15 13:41 706ÿ048 PocoNet.dll  
2015-12-15 13:40 1ÿ802ÿ752 PocoNetd.dll  
2015-12-15 13:38 313ÿ856 PocoUtil.dll  
2015-12-15 13:37 958ÿ464 PocoUtild.dll  
2015-12-15 13:34 406ÿ016 PocoXML.dll  
2015-12-15 13:33 1ÿ008ÿ640 PocoXMLd.dll

Directory of C:\\temp\\poco-1.6.1\\lib

2015-12-15 13:24 50ÿ292 CppUnit.lib  
2015-12-15 13:24 50ÿ420 CppUnitd.lib  
2015-12-15 13:25 890ÿ770 CppUnitmd.lib  
2015-12-15 13:25 2ÿ253ÿ898 CppUnitmdd.lib  
2015-12-15 13:25 1ÿ425ÿ800 CppUnitmt.lib  
2015-12-15 13:25 2ÿ859ÿ374 CppUnitmtd.lib  
2015-12-15 13:28 1ÿ499ÿ118 PocoFoundation.lib  
2015-12-15 13:26 1ÿ502ÿ782 PocoFoundationd.lib  
2015-12-15 13:33 7ÿ645ÿ602 PocoFoundationmd.lib  
2015-12-15 13:31 42ÿ283ÿ804 PocoFoundationmdd.lib  
2015-12-15 13:30 10ÿ893ÿ714 PocoFoundationmt.lib  
2015-12-15 13:29 50ÿ436ÿ090 PocoFoundationmtd.lib  
2015-12-15 13:36 104ÿ958 PocoJSON.lib  
2015-12-15 13:36 105ÿ190 PocoJSONd.lib  
2015-12-15 13:37 1ÿ692ÿ886 PocoJSONmd.lib  
2015-12-15 13:37 8ÿ515ÿ446 PocoJSONmdd.lib  
2015-12-15 13:37 2ÿ088ÿ590 PocoJSONmt.lib  
2015-12-15 13:36 9ÿ351ÿ192 PocoJSONmtd.lib  
2015-12-15 13:41 987ÿ880 PocoNet.lib  
2015-12-15 13:40 990ÿ130 PocoNetd.lib  
2015-12-15 13:44 5ÿ569ÿ014 PocoNetmd.lib  
2015-12-15 13:43 28ÿ319ÿ822 PocoNetmdd.lib  
2015-12-15 13:42 7ÿ469ÿ738 PocoNetmt.lib  
2015-12-15 13:42 33ÿ232ÿ174 PocoNetmtd.lib  
2015-12-15 13:38 316ÿ042 PocoUtil.lib  
2015-12-15 13:37 316ÿ664 PocoUtild.lib  
2015-12-15 13:39 2ÿ497ÿ770 PocoUtilmd.lib  
2015-12-15 13:39 16ÿ062ÿ126 PocoUtilmdd.lib  
2015-12-15 13:38 2ÿ831ÿ782 PocoUtilmt.lib  
2015-12-15 13:38 16ÿ613ÿ764 PocoUtilmtd.lib  
2015-12-15 13:34 531ÿ476 PocoXML.lib  
2015-12-15 13:33 532ÿ640 PocoXMLd.lib  
2015-12-15 13:36 2ÿ337ÿ678 PocoXMLmd.lib  
2015-12-15 13:35 13ÿ077ÿ402 PocoXMLmdd.lib  
2015-12-15 13:35 2ÿ659ÿ908 PocoXMLmt.lib  
2015-12-15 13:34 13ÿ543ÿ794 PocoXMLmtd.lib

==&gt; Built for 64-bit windows (note that the build win.cmd file carries REM:s describing possible parameters)

rem Usage:  
rem ------  
rem buildwin VS_VERSION &#91;ACTION&#93; &#91;LINKMODE&#93; &#91;CONFIGURATION&#93; &#91;PLATFORM&#93; &#91;SAMPLES&#93; &#91;TESTS&#93; &#91;TOOL&#93;  
rem VS_VERSION: 90|100|110|120|140  
rem ACTION: build|rebuild|clean  
rem LINKMODE: static_mt|static_md|shared|all  
rem CONFIGURATION: release|debug|both  
rem PLATFORM: Win32|x64|WinCE|WEC2013  
rem SAMPLES: samples|nosamples  
rem TESTS: tests|notests  
rem TOOL: devenv|vcexpress|wdexpress|msbuild  
rem  
rem VS_VERSION is required argument. Default is build all.

&gt;buildwin 140 clean

&gt;buildwin 140 build all both x64 nosamples

==&gt; Note: buildwin identifies parameters by its position (x64 must be parameter no. 5). Thus we have to provide preceding parameters to define the x64 target.

1. VS_VERSION = 140 (Visual Studio 2015. i.e version 14.0)
2. ACTION = clean, then build
3. LINKMODE = all (static_mt, static_md, shared, i.e. libs with and without C libraries and dlls)
4. CONFIGURATION = both (release and debug)
5. PLATFORM = x64
6. SAMPLES = nosamples

==&gt; Note: configurations xxx_md and xxx_mt seem to refer to /MD /MT switch of Visual Studio linker (<http://stackoverflow.com/questions/757418/should-i-compile-with-md-or-mt>)

“If you use /MT, your executable won't depend on a DLL being present on the target system.”

==&gt; The build succeeded and “C:\\temp\\poco-1.6.1\\lib64” was created.

2015-12-17 11:26 51ÿ444 CppUnit.lib  
2015-12-17 11:26 51ÿ568 CppUnitd.lib  
2015-12-17 11:26 1ÿ066ÿ434 CppUnitmd.lib  
2015-12-17 11:26 3ÿ207ÿ100 CppUnitmdd.lib  
2015-12-17 11:26 1ÿ708ÿ846 CppUnitmt.lib  
2015-12-17 11:26 4ÿ132ÿ038 CppUnitmtd.lib  
2015-12-17 11:29 1ÿ533ÿ200 PocoFoundation.lib  
2015-12-17 11:27 1ÿ536ÿ862 PocoFoundationd.lib  
2015-12-17 11:34 11ÿ483ÿ888 PocoFoundationmd.lib  
2015-12-17 11:33 59ÿ136ÿ846 PocoFoundationmdd.lib  
2015-12-17 11:32 16ÿ072ÿ786 PocoFoundationmt.lib  
2015-12-17 11:30 71ÿ716ÿ310 PocoFoundationmtd.lib  
2015-12-17 11:38 107ÿ098 PocoJSON.lib  
2015-12-17 11:38 107ÿ312 PocoJSONd.lib  
2015-12-17 11:39 2ÿ612ÿ350 PocoJSONmd.lib  
2015-12-17 11:38 12ÿ541ÿ290 PocoJSONmdd.lib  
2015-12-17 11:38 3ÿ154ÿ894 PocoJSONmt.lib  
2015-12-17 11:38 13ÿ826ÿ992 PocoJSONmtd.lib  
2015-12-17 11:43 1ÿ008ÿ246 PocoNet.lib  
2015-12-17 11:41 1ÿ010ÿ516 PocoNetd.lib  
2015-12-17 11:46 7ÿ901ÿ338 PocoNetmd.lib  
2015-12-17 11:45 39ÿ411ÿ762 PocoNetmdd.lib  
2015-12-17 11:44 11ÿ090ÿ100 PocoNetmt.lib  
2015-12-17 11:43 46ÿ979ÿ896 PocoNetmtd.lib  
2015-12-17 11:39 322ÿ310 PocoUtil.lib  
2015-12-17 11:39 322ÿ926 PocoUtild.lib  
2015-12-17 11:41 4ÿ041ÿ928 PocoUtilmd.lib  
2015-12-17 11:40 23ÿ338ÿ816 PocoUtilmdd.lib  
2015-12-17 11:40 4ÿ489ÿ528 PocoUtilmt.lib  
2015-12-17 11:40 24ÿ249ÿ426 PocoUtilmtd.lib  
2015-12-17 11:35 543ÿ712 PocoXML.lib  
2015-12-17 11:35 544ÿ870 PocoXMLd.lib  
2015-12-17 11:37 3ÿ485ÿ614 PocoXMLmd.lib  
2015-12-17 11:37 17ÿ879ÿ134 PocoXMLmdd.lib  
2015-12-17 11:36 3ÿ922ÿ070 PocoXMLmt.lib  
2015-12-17 11:36 18ÿ720ÿ966 PocoXMLmtd.lib

==&gt; Found “C:\\temp\\poco-1.6.1\\Net\\Net_vs140.sln” (Visual Studio 2015 solution for network examples?)

==&gt; “C:\\temp\\poco-1.6.1\\Net\\src\\FTPClientSession.cpp” seem to implement the FTP client engine (NOT asio-based)?

==&gt; “C:\\temp\\poco-1.6.1\\Net\\src\\FTPStreamFactory.cpp” seem to register a stream factory for FTP?

==&gt; "C:\\temp\\poco-1.6.1\\Net\\testsuite\\src\\FTPClientSessionTest.cpp” seem to define CPPUnit tests and also showing how to use a FTPClientSession instance to login and fetch files from an FTP Server

==&gt; FTPClientSession is NOT asynchronous (it seem to provide one metgod per Request/Response dialog with the server)?

==&gt; We could easily wrap an FTPClientSession to be used by an FTP MSM for complete fetch-file sessions?

==&gt; “C:\\temp\\poco-1.6.1\\Net\\samples\\download\\src\\download.cpp” seem to show a very compact ftp download?

HTTPStreamFactory::registerFactory();  
FTPStreamFactory::registerFactory();

…

URI uri(argv&#91;1&#93;);  
std::auto_ptr&lt;std::istream&gt; pStr(URIStreamOpener::defaultOpener().open(uri));  
StreamCopier::copyStream(\*pStr.get(), std::cout);

…

==&gt; Does this work to download from PPL-server?

==&gt; Succeeded to build “static_shared_md” win32 config of download.exe

==&gt; “FTP URL syntax is described in RFC 1738, taking the form: ftp://&#91;&lt;user&gt;&#91;:&lt;password&gt;&#93;@&#93;&lt;host&gt;&#91;:&lt;port&gt;&#93;/&lt;url-path&gt; (the bracketed parts are optional).” (<https://en.wikipedia.org/wiki/File_Transfer_Protocol>)

&gt;C:\\temp\\poco-1.6.1\\Net\\samples\\download\\bin\\static_md&gt;download "<ftp://59100016:> @164.10.25.253/59100016"

==&gt; Note that PPL server requires one space for password (does this mean empty password or one-space password)?

==&gt; Anyhow - the download.exe seem to default to output downloaded file to console output (file printed on screen and no local file created).

==&gt; Code seem quite clearly copy the ftp-setram to std::cout) :)

StreamCopier::copyStream(\*pStr.get(), std::cout);

==&gt; So, can we make this work in RAD Studio XE7 (this was Visual Studio built libraries and code)?

5) Tried to use poco in RAD Studio XE7

==&gt; Tried the code in “C:\\subversion\\babs_internal\\branches\\TestBench\\141001_RADStudioXE7_Code\\build\\PlaygroundTestBench\\MainUnit.cpp” (Project &lt;PlaygroundConsoleTestBench.cbproj&gt;)

#ifdef USE_COCO_FTP  
#include "Poco/URIStreamOpener.h"  
#include "Poco/StreamCopier.h"  
#include "Poco/Path.h"  
#include "Poco/URI.h"  
#include "Poco/Exception.h"  
#include "Poco/Net/HTTPStreamFactory.h"  
#include "Poco/Net/FTPStreamFactory.h"  
#include &lt;memory&gt;  
// #include &lt;iostream&gt;  
#endif USE_COCO_FTP

==&gt; Added “C:\\temp\\poco-1.6.1\\Foundation\\include” to &lt;include directories&gt; (Took care of all #include “Poco/&lt;file.h&gt;")

==&gt; Added “C:\\temp\\poco-1.6.1\\Net\\include” (Took care of all #include “Poco/Net/&lt;file.h&gt;”

#ifdef USE_COCO_FTP  
{  
try {  
Poco::Net::HTTPStreamFactory::registerFactory();  
Poco::Net::FTPStreamFactory::registerFactory();

Poco::URI uri("<ftp://59100016:> @164.10.25.253/59100016"); // User="59100016", Password=" ", Host="164.10.25.253", File="59100016"  
std::auto_ptr&lt;std::istream&gt; pStr(Poco::URIStreamOpener::defaultOpener().open(uri));  
Poco::StreamCopier::copyStream(\*pStr.get(), std::cout);  
}  
catch (Poco::Exception& exc)  
{  
std::cerr &lt;&lt; exc.displayText() &lt;&lt; std::endl;  
result = 1;  
}  
}  
#endif // USE_COCO_FTP

==&gt; This program compiles in BCC64 (64-bit windows) but NOT in BCC32!

==&gt; Seem BCC64 being Clang based is able to compile Poco while BCC32 being Borland C++ is not?

==&gt; But this code does not link now (and BCC64 requires libraries to be in ELF-64 format in files named \*.a)

==&gt; So, how do we compile Coco libraries into ELF-64 \*.a files?

==&gt; Use gcc in CygWin?

==&gt; Configure RAD Studio XE7 project files to build Coco libraries (seem like a lot of work)?

6) Found “Object File Converter” last updated Dec 2015 (<http://agner.org/optimize/>), See “Todo: Programming - Understand binary target files for different build platforms (VS, RAD Studio, Unix/gcc)"

“Object file converter - This utility can be used for converting object files between COFF/PE, OMF, ELF and Mach-O formats for all 32-bit and 64-bit x86 platforms. Can modify symbol names in object files. Can build, modify and convert function libraries across platforms. Can dump object files and executable files. Also includes a very good disassembler supporting the SSE4, AVX, AVX2, AVX512, FMA3, FMA4, XOP and Knights Corner instruction sets. Source code included (GPL). Manual. File name: objconv.zip, size: 1010456, last modified: 2015-Dec-09.”

==&gt; Consider to try it out to convert the PE Format libraries build by VS for Coco to get ELF format files named \*.a?

*// A library is converted in the same way as an object file:*

&gt;objconv -felf32 -nu file1.lib file1.a

==&gt; Note: BCC64 requires ELF-64 files so I suppose we need to build Coco in Visual Studio for 64-bit windows first?!

// Then convert the 64-bi lib-file to ELF64?

&gt;objconv -felf64 -nu file1.lib file1.a

***… WE ARE HERE ...***

...

...

Consider to delve deeper into this library to see if we can use it or if we can be inspired to contribute?

a) Is it implementing the Protocol-Stack idiom?  
b) Is it asio-based?  
c) Is it msm-based?  
...

{% endraw %}
