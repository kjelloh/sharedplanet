# Todo: Programming - Consider to study and try out a native Clang C++ compiler on windows?

```#52b0d95e``` *As of 2015-12-18 17:28*

[mail plain/text](mail.txt)

{% raw %}
What Clang compilers are there on windows and may I download, build and use one u Windows 8?

*Note: Also see “Todo: Programming - Consider to understand and try out the LLVM tool chain on windows?”.*

1) This seem to be the official instruction on how to get and build Clang for windows (<http://clang.llvm.org/get_started.html>)

==&gt; “Using Visual Studio” defines steps to get and build using a Visual Studio Solution (sln) file.

==&gt; Checked out llvm to C:\\subversion\\llvm\\trunk folder

C:\\subversion\\llvm&gt;svn co <http://llvm.org/svn/llvm-project/llvm/trunk> trunk

…

Checked out revision 255995.

C:\\subversion\\llvm&gt;

== &gt;Then checked out Clang to subfolder C:\\subversion\\llvm\\trunk\\tools\\clang

C:\\subversion\\llvm&gt;cd trunk\\tools

C:\\subversion\\llvm\\trunk\\tools\\&gt;svn co <http://llvm.org/svn/llvm-project/cfe/trunk> clang

…

Checked out revision 255995.

C:\\subversion\\llvm\\trunk\\tools\\&gt;

==&gt; Hm… I did not believe it was possible to check out another subversion tree into an existing one (C:\\subversion\\llvm\\trunk\\tools\\ is version controlled bound to <http://llvm.org/svn/llvm-project/llvm/trunk/tools> is it not)?

==&gt; Well it worked.

![](llvm_with_clang_svn_folder_size.tiff)

==&gt; Now created a build-folder parallel with the source trunk-folder

C:\\subversion\\llvm\\trunk\\tools&gt;cd ..

C:\\subversion\\llvm\\trunk&gt;cd ..

C:\\subversion\\llvm&gt;mkdir build

==&gt; Now used make to generate visual studio solution file for llvm/clang project

C:\\subversion\\llvm\\&gt;cd build

C:\\subversion\\llvm\\build&gt;cmake -G "Visual Studio 14" ..\\trunk

…

-- Configuring done  
-- Generating done  
-- Build files have been written to: C:/subversion/llvm/build

C:\\subversion\\llvm\\build&gt;

==&gt; The build folder now seems populated with files and visual studio solution and projects.

![](llvm_cmake_build_vs_folder.tiff)

==&gt; Note: Can’t help to reflect upon how nitty-picky complicated all these build-form-files environments are (not including all the script dialects, target platforms and build tools)!

==&gt; Started the LLVM.sln solution file with Visual Studio 2015.

![](clang_vs_solution_contents.tiff)

==&gt; In total there are 315 projects in this solution!

==&gt; When with building the default settings (Debug, Win-32, BUILD_ALL project)

...

========== Build: 306 succeeded, 0 failed, 0 up-to-date, 8 skipped ==========

==&gt; Debug Win-32 targets seem to have succeeded.

==&gt; The build tools seem to be in “C:\\subversion\\llvm\\build\\Debug\\bin”?

C:\\subversion\\llvm\\build\\Debug\\bin&gt;dir \*.exe

Volume in drive C has no label.

Volume Serial Number is 6CB3-DA31

Directory of C:\\subversion\\llvm\\build\\Debug\\bin

2015-12-18 15:41 37 278 720 arcmt-test.exe

2015-12-18 15:47 26 930 688 BrainF.exe

2015-12-18 15:36 24 587 264 bugpoint.exe

2015-12-18 15:38 39 936 c-arcmt-test.exe

2015-12-18 15:38 157 696 c-index-test.exe

2015-12-18 15:39 107 873 280 clang++.exe

2015-12-18 15:40 86 919 680 clang-check.exe

2015-12-18 15:39 107 873 280 clang-cl.exe

2015-12-18 15:40 4 394 496 clang-format.exe

2015-12-18 14:09 2 591 232 clang-tblgen.exe

2015-12-18 15:39 107 873 280 clang.exe

2015-12-18 15:41 37 888 count.exe

2015-12-18 15:41 30 358 016 diagtool.exe

2015-12-18 15:47 26 835 968 Fibonacci.exe

2015-12-18 15:37 1 055 232 FileCheck.exe

2015-12-18 15:47 26 833 920 HowToUseJIT.exe

2015-12-18 15:46 129 536 Kaleidoscope-Ch2.exe

2015-12-18 15:45 5 689 344 Kaleidoscope-Ch3.exe

2015-12-18 15:47 30 799 360 Kaleidoscope-Ch4.exe

2015-12-18 15:47 30 810 624 Kaleidoscope-Ch5.exe

2015-12-18 15:46 30 818 304 Kaleidoscope-Ch6.exe

2015-12-18 15:46 30 839 808 Kaleidoscope-Ch7.exe

2015-12-18 15:46 29 196 288 Kaleidoscope-Ch8.exe

2015-12-18 15:46 29 859 328 Kaleidoscope-Orc-fully_lazy.exe

2015-12-18 15:45 29 722 112 Kaleidoscope-Orc-initial.exe

2015-12-18 15:46 29 757 440 Kaleidoscope-Orc-lazy_codegen.exe

2015-12-18 15:45 29 787 136 Kaleidoscope-Orc-lazy_irgen.exe

2015-12-18 15:41 862 720 KillTheDoctor.exe

2015-12-18 15:42 52 769 792 llc.exe

2015-12-18 15:42 824 320 lli-child-target.exe

2015-12-18 15:42 31 427 072 lli.exe

2015-12-18 15:30 26 317 312 llvm-ar.exe

2015-12-18 15:42 6 764 544 llvm-as.exe

2015-12-18 15:42 983 552 llvm-bcanalyzer.exe

2015-12-18 15:42 48 310 272 llvm-c-test.exe

2015-12-18 15:42 939 520 llvm-config.exe

2015-12-18 15:43 7 700 480 llvm-cov.exe

2015-12-18 15:43 7 411 200 llvm-cxxdump.exe

2015-12-18 15:43 6 615 040 llvm-diff.exe

2015-12-18 15:43 5 640 192 llvm-dis.exe

2015-12-18 15:43 47 954 944 llvm-dsymutil.exe

2015-12-18 15:43 7 584 768 llvm-dwarfdump.exe

2015-12-18 15:44 47 456 256 llvm-dwp.exe

2015-12-18 15:44 9 336 320 llvm-extract.exe

2015-12-18 15:44 26 317 312 llvm-lib.exe

2015-12-18 15:44 8 940 544 llvm-link.exe

2015-12-18 15:44 57 393 664 llvm-lto.exe

2015-12-18 15:44 29 130 240 llvm-mc.exe

2015-12-18 15:44 874 496 llvm-mcmarkup.exe

2015-12-18 15:44 26 186 752 llvm-nm.exe

2015-12-18 15:45 20 299 776 llvm-objdump.exe

2015-12-18 15:45 1 254 400 llvm-pdbdump.exe

2015-12-18 15:42 86 528 llvm-PerfectShuffle.exe

2015-12-18 15:45 5 360 128 llvm-profdata.exe

2015-12-18 15:45 26 317 312 llvm-ranlib.exe

2015-12-18 15:45 7 657 984 llvm-readobj.exe

2015-12-18 15:45 20 198 912 llvm-rtdyld.exe

2015-12-18 15:37 7 074 304 llvm-size.exe

2015-12-18 15:37 10 093 056 llvm-split.exe

2015-12-18 15:37 5 682 688 llvm-stress.exe

2015-12-18 15:37 7 916 032 llvm-symbolizer.exe

2015-12-18 14:09 6 427 136 llvm-tblgen.exe

2015-12-18 15:47 5 244 416 ModuleMaker.exe

2015-12-18 15:37 808 960 not.exe

2015-12-18 15:37 7 566 848 obj2yaml.exe

2015-12-18 15:38 55 322 112 opt.exe

2015-12-18 15:38 20 121 088 sancov.exe

2015-12-18 15:38 7 323 136 verify-uselistorder.exe

2015-12-18 15:38 1 045 504 yaml-bench.exe

2015-12-18 15:38 1 589 760 yaml2obj.exe

70 File(s) 1 544 181 248 bytes

0 Dir(s) 2 486 222 848 bytes free

C:\\subversion\\llvm\\build\\Debug\\bin&gt;dir \*.exe &gt; dir.txt

C:\\subversion\\llvm\\build\\Debug\\bin&gt;

2) At this time I discovered the clang compiler was already installed on the system - twice!

==&gt; One may use the DOS command where to discover where a command/application is found

C:\\subversion\\llvm\\build&gt;where clang  
C:\\Program Files (x86)\\Embarcadero\\Studio\\15.0\\bin\\clang.exe  
C:\\Program Files\\LLVM\\bin\\clang.exe

C:\\subversion\\llvm\\build&gt;

==&gt; Thus we at this time have three clang compilers available in the system (the third one being the just built one)

==&gt; So RAD Studio ships with clang! (What version is this)?

==&gt; I seem to have installed an LLVM with clang at C:\\Program Files\\LLVM\\bin (See “Todo: Programming - Consider to understand and try out the LLVM tool chain on windows?”)

==&gt; Hm… this clang build was for nothing then. A 64-bit clang 3.7.0 is available for install (both 32/64 bit) (<http://llvm.org/releases/download.html>)

==&gt; See “<http://llvm.org/releases/3.7.0/LLVM-3.7.0-win32.exe>”

==&gt; See “<http://llvm.org/releases/3.7.0/LLVM-3.7.0-win64.exe>”

3) clang is able to list all supported options with --help argument (double dashes, not single long dash)

==&gt; This seems to be the options of C:\\Program Files (x86)\\Embarcadero\\Studio\\15.0\\bin\\clang.exe (found first in PATH listed directories)?

C:\\subversion\\llvm\\build&gt;clang --help  
OVERVIEW: clang "gcc-compatible" driver

USAGE: clang &#91;options&#93; &lt;inputs&gt;

OPTIONS:  
-### Print the commands to run for this compilation  
--analyze Run the static analyzer  
--help Display available options  
--ilink-no-cfg Do not use cfg file for borland linker  
--migrate Run the migrator  
--relocatable-pch Build a relocatable precompiled header  
--serialize-diagnostics &lt;value&gt;  
Serialize compiler diagnostics to a file  
-E Only run the preprocessor  
-ObjC++ Treat source input files as Objective-C++ inputs  
-ObjC Treat source input files as Objective-C inputs  
-Qunused-arguments Don't emit warning for unused driver arguments  
-S Only run preprocess and compilation steps  
-Wa,&lt;arg&gt; Pass the comma separated arguments in &lt;arg&gt; to the assembler  
-Wl,&lt;arg&gt; Pass the comma separated arguments in &lt;arg&gt; to the linker  
-Wp,&lt;arg&gt; Pass the comma separated arguments in &lt;arg&gt; to the preprocessor  
-Xanalyzer &lt;arg&gt; Pass &lt;arg&gt; to the static analyzer  
-Xassembler &lt;arg&gt; Pass &lt;arg&gt; to the assembler  
-Xclang &lt;arg&gt; Pass &lt;arg&gt; to the clang compiler  
-Xdriver &lt;arg&gt; Do not convert &lt;arg&gt; from older bcc32 to Clang.  
-Xlinker &lt;arg&gt; Pass &lt;arg&gt; to the linker  
-Xpreprocessor &lt;arg&gt; Pass &lt;arg&gt; to the preprocessor  
-arcmt-migrate-emit-errors  
Emit ARC errors even if the migrator can fix them  
-arcmt-migrate-report-output &lt;value&gt;  
Output path for the plist report  
-c Only run preprocess, compile, and assemble steps  
-emit-ast Emit Clang AST files for source inputs  
-emit-llvm Use the LLVM representation for assembler and object files  
-external-linker &lt;arg&gt; Select &lt;arg&gt; as external linker  
-fcatch-undefined-behavior  
Generate runtime checks for undefined behavior.  
-flimit-debug-info Limit debug information produced to reduce size of debug binary  
-fno-limit-debug-info Do not limit debug information produced to reduce size of debug binary  
-ftrap-function=&lt;value&gt; Issue call to specified function rather than a trap instruction  
-gcc-toolchain &lt;value&gt; Use the gcc toolchain at the given directory  
-mcdecl Make CDecl calling convention the default  
-mfastcall Make FastCall calling convention the default  
-mno-cdecl Do not make CDecl calling convention the default  
-mno-fastcall Do not make FastCall calling convention the default  
-mno-stdcall Do not make StdCall calling convention the default  
-mstdcall Make StdCall calling convention the default  
-n &lt;directory&gt; Specify the output directory for intermediate files  
-objcmt-migrate-literals  
Enable migration to modern ObjC literals  
-objcmt-migrate-subscripting  
Enable migration to modern ObjC subscripting  
-o &lt;file&gt; Write output to &lt;file&gt;  
-pipe Use pipes between commands, when possible  
-print-file-name=&lt;file&gt; Print the full library path of &lt;file&gt;  
-print-libgcc-file-name Print the library path for "libgcc.a"  
-print-prog-name=&lt;name&gt; Print the full program path of &lt;name&gt;  
-print-search-dirs Print the paths used for finding libraries and programs  
-q Suppress compiler identification banner  
-rewrite-legacy-objc Rewrite Legacy Objective-C source to C++  
-rewrite-objc Rewrite Objective-C source to C++  
-save-temps Save intermediate compilation results  
-target &lt;value&gt; Generate code for the given target  
-time Time individual commands  
-t&lt;value&gt; Specify Borland target executable  
-verify Verify output using a verifier.  
-v Show commands to run and use verbose output  
-working-directory &lt;value&gt;  
Resolve file paths relative to the specified directory

-x &lt;language&gt; Treat subsequent input files as having type &lt;language&gt;

C:\\subversion\\llvm\\build&gt;

==&gt; Trying the options of installed LLVM clang returns a much longer list of options!

C:\\subversion\\llvm\\build&gt;"C:\\Program Files\\LLVM\\bin\\clang.exe" --help &gt; llvm_clang_options.txt

==&gt; Produces txt-file with the following content.

OVERVIEW: clang LLVM compiler

USAGE: clang.exe &#91;options&#93; &lt;inputs&gt;

OPTIONS:

-### Print (but do not run) the commands to run for this compilation

--analyze Run the static analyzer

-arcmt-migrate-emit-errors

Emit ARC errors even if the migrator can fix them

-arcmt-migrate-report-output &lt;value&gt;

Output path for the plist report

--cuda-device-only Do device-side CUDA compilation only

--cuda-host-only Do host-side CUDA compilation only

-cxx-isystem &lt;directory&gt;

Add directory to the C++ SYSTEM include search path

-c Only run preprocess, compile, and assemble steps

-dD Print macro definitions in -E mode in addition to normal output

-dependency-dot &lt;value&gt; Filename to write DOT-formatted header dependencies to

-dependency-file &lt;value&gt;

Filename (or -) to write dependency output to

-dM Print macro definitions in -E mode instead of normal output

-emit-ast Emit Clang AST files for source inputs

-emit-llvm Use the LLVM representation for assembler and object files

-E Only run the preprocessor

-faltivec Enable AltiVec vector initializer syntax

-fansi-escape-codes Use ANSI escape codes for diagnostics

-fapple-kext Use Apple's kernel extensions ABI

-fapple-pragma-pack Enable Apple gcc-compatible #pragma pack handling

-fapplication-extension Restrict code to those available for App Extensions

-fblocks Enable the 'blocks' language feature

-fborland-extensions Accept non-standard constructs supported by the Borland compiler

-fbuild-session-file=&lt;file&gt;

Use the last modification time of &lt;file&gt; as the build session timestamp

-fbuild-session-timestamp=&lt;time since Epoch in seconds&gt;

Time when the current build session started

-fcolor-diagnostics Use colors in diagnostics

-fcomment-block-commands=&lt;arg&gt;

Treat each comma separated argument in &lt;arg&gt; as a documentation comment block command

-fcoverage-mapping Generate coverage mapping to enable code coverage analysis

-fcxx-exceptions Enable C++ exceptions

-fdata-sections Place each data in its own section (ELF Only)

-fdebug-types-section Place debug types in their own section (ELF Only)

-fdelayed-template-parsing

Parse templated function definitions at the end of the translation unit

-fdiagnostics-parseable-fixits

Print fix-its in machine parseable form

-fdiagnostics-print-source-range-info

Print source range spans in numeric form

-fdiagnostics-show-note-include-stack

Display include stacks for diagnostic notes

-fdiagnostics-show-option

Print option name with mappable diagnostics

-fdiagnostics-show-template-tree

Print a template comparison tree for differing templates

-fdollars-in-identifiers

Allow '$' in identifiers

-femit-all-decls Emit all declarations, even if unused

-fexceptions Enable support for exception handling

-ffast-math Enable the \*frontend\*'s 'fast-math' mode. This has no effect on optimizations, but provides a preprocessor macro __FAST_MATH__ the same as GCC's -ffast-math flag

-ffixed-r9 Reserve the r9 register (ARM only)

-ffixed-x18 Reserve the x18 register (AArch64 only)

-ffp-contract=&lt;value&gt; Form fused FP ops (e.g. FMAs): fast (everywhere) | on (according to FP_CONTRACT pragma, default) | off (never fuse)

-ffreestanding Assert that the compilation takes place in a freestanding environment

-ffunction-sections Place each function in its own section (ELF Only)

-fgnu-keywords Allow GNU-extension keywords regardless of language standard

-fgnu-runtime Generate output compatible with the standard GNU Objective-C runtime

-fgnu89-inline Use the gnu89 inline semantics

-fimplicit-module-maps Implicitly search the file system for module map files.

-finstrument-functions Generate calls to instrument function entry and exit

-fintegrated-as Enable the integrated assembler

-fmath-errno Require math functions to indicate errors by setting errno

-fmax-type-align=&lt;value&gt;

Specify the maximum alignment to enforce on pointers lacking an explicit alignment

-fmodule-file=&lt;file&gt; Load this precompiled module file

-fmodule-map-file=&lt;file&gt;

Load this module map file

-fmodule-name= &lt;name&gt; Specify the name of the module to build

-fmodules-cache-path=&lt;directory&gt;

Specify the module cache path

-fmodules-decluse Require declaration of modules used within a module

-fmodules-ignore-macro=&lt;value&gt;

Ignore the definition of the given macro when building and loading modules

-fmodules-prune-after=&lt;seconds&gt;

Specify the interval (in seconds) after which a module file will be considered unused

-fmodules-prune-interval=&lt;seconds&gt;

Specify the interval (in seconds) between attempts to prune the module cache

-fmodules-search-all Search even non-imported modules to resolve references

-fmodules-strict-decluse

Like -fmodules-decluse but requires all headers to be in modules

-fmodules-user-build-path &lt;directory&gt;

Specify the module user build path

-fmodules-validate-once-per-build-session

Don't verify input files for the modules if the module has been successfully validated or loaded during this build session

-fmodules-validate-system-headers

Validate the system headers that a module depends on when loading the module

-fmodules Enable the 'modules' language feature

-fms-compatibility-version=&lt;value&gt;

Dot-separated value representing the Microsoft compiler version number to report in _MSC_VER (0 = don't define it (default))

-fms-compatibility Enable full Microsoft Visual C++ compatibility

-fms-extensions Accept some non-standard constructs supported by the Microsoft compiler

-fmsc-version=&lt;value&gt; Microsoft compiler version number to report in _MSC_VER (0 = don't define it (default))

-fno-access-control Disable C++ access control

-fno-assume-sane-operator-new

Don't assume that C++'s global operator new can't alias any pointer

-fno-autolink Disable generation of linker directives for automatic library linking

-fno-builtin-&lt;value&gt; Disable implicit builtin knowledge of a specific function

-fno-builtin Disable implicit builtin knowledge of functions

-fno-common Compile common globals like normal definitions

-fno-constant-cfstrings Disable creation of CodeFoundation-type constant strings

-fno-diagnostics-fixit-info

Do not include fixit information in diagnostics

-fno-dollars-in-identifiers

Disallow '$' in identifiers

-fno-elide-constructors Disable C++ copy constructor elision

-fno-elide-type Do not elide types when printing diagnostics

-fno-gnu-inline-asm Disable GNU style inline asm

-fno-integrated-as Disable the integrated assembler

-fno-lax-vector-conversions

Disallow implicit conversions between vectors with a different number of elements or different element types

-fno-math-builtin Disable implicit builtin knowledge of math functions

-fno-merge-all-constants

Disallow merging of constants

-fno-objc-infer-related-result-type

do not infer Objective-C related result type based on method family

-fno-operator-names Do not treat C++ operator name keywords as synonyms for operators

-fno-reroll-loops Turn off loop reroller

-fno-rtti Disable generation of rtti information

-fno-sanitize-blacklist Don't use blacklist file for sanitizers

-fno-sanitize-coverage=&lt;value&gt;

Disable specified features of coverage instrumentation for Sanitizers

-fno-sanitize-memory-track-origins

Disable origins tracking in MemorySanitizer

-fno-sanitize-recover=&lt;value&gt;

Disable recovery for specified sanitizers

-fno-sanitize-trap=&lt;value&gt;

Disable trapping for specified sanitizers

-fno-short-wchar Force wchar_t to be an unsigned int

-fno-show-column Do not include column number on diagnostics

-fno-show-source-location

Do not include source location information with diagnostics

-fno-signed-char Char is unsigned

-fno-signed-zeros Allow optimizations that ignore the sign of floating point zeros

-fno-spell-checking Disable spell-checking

-fno-stack-protector Disable the use of stack protectors

-fno-standalone-debug Limit debug information produced to reduce size of debug binary

-fno-threadsafe-statics Do not emit code to make initialization of local statics thread safe

-fno-trigraphs Do not process trigraph sequences

-fno-unroll-loops Turn off loop unroller

-fno-use-cxa-atexit Don't use __cxa_atexit for calling destructors

-fno-use-init-array Don't use .init_array instead of .ctors

-fobjc-arc-exceptions Use EH-safe code when synthesizing retains and releases in -fobjc-arc

-fobjc-arc Synthesize retain and release calls for Objective-C pointers

-fobjc-exceptions Enable Objective-C exceptions

-fobjc-gc-only Use GC exclusively for Objective-C related memory management

-fobjc-gc Enable Objective-C garbage collection

-fobjc-runtime=&lt;value&gt; Specify the target Objective-C runtime kind and version

-fpack-struct=&lt;value&gt; Specify the default maximum struct packing alignment

-fpascal-strings Recognize and construct Pascal-style string literals

-fpcc-struct-return Override the default ABI to return all structs on the stack

-fprofile-generate=&lt;directory&gt;

Generate instrumented code to collect execution counts into &lt;directory&gt;/default.profraw (overridden by LLVM_PROFILE_FILE env var)

-fprofile-instr-generate=&lt;file&gt;

Generate instrumented code to collect execution counts into &lt;file&gt; (overridden by LLVM_PROFILE_FILE env var)

-fprofile-instr-generate

Generate instrumented code to collect execution counts into default.profraw file (overriden by '=' form of option or LLVM_PROFILE_FILE env var)

-fprofile-instr-use=&lt;value&gt;

Use instrumentation data for profile-guided optimization

-fprofile-sample-use=&lt;value&gt;

Enable sample-based profile guided optimizations

-fprofile-use=&lt;pathname&gt;

Use instrumentation data for profile-guided optimization. If pathname is a directory, it reads from &lt;pathname&gt;/default.profdata. Otherwise, it reads from file &lt;pathname&gt;.

-freciprocal-math Allow division operations to be reassociated

-freg-struct-return Override the default ABI to return small structs in registers

-freroll-loops Turn on loop reroller

-fsanitize-address-field-padding=&lt;value&gt;

Level of field padding for AddressSanitizer

-fsanitize-blacklist=&lt;value&gt;

Path to blacklist file for sanitizers

-fsanitize-coverage=&lt;value&gt;

Specify the type of coverage instrumentation for Sanitizers

-fsanitize-memory-track-origins=&lt;value&gt;

Enable origins tracking in MemorySanitizer

-fsanitize-memory-track-origins

Enable origins tracking in MemorySanitizer

-fsanitize-memory-use-after-dtor

Enable use-after-destroy detection in MemorySanitizer

-fsanitize-recover=&lt;value&gt;

Enable recovery for specified sanitizers

-fsanitize-trap=&lt;value&gt; Enable trapping for specified sanitizers

-fsanitize=&lt;check&gt; Turn on runtime checks for various forms of undefined or suspicious behavior. See user manual for available checks

-fshort-enums Allocate to an enum type only as many bytes as it needs for the declared range of possible values

-fshort-wchar Force wchar_t to be a short unsigned int

-fshow-overloads=&lt;value&gt;

Which overload candidates to show when overload resolution fails: best|all; defaults to all

-fsized-deallocation Enable C++14 sized global deallocation functions

-fslp-vectorize-aggressive

Enable the BB vectorization passes

-fslp-vectorize Enable the superword-level parallelism vectorization passes

-fstack-protector-all Force the usage of stack protectors for all functions

-fstack-protector-strong

Use a strong heuristic to apply stack protectors to functions

-fstack-protector Enable stack protectors for functions potentially vulnerable to stack smashing

-fstandalone-debug Emit full debug info for all types used by the program

-fstrict-enums Enable optimizations based on the strict definition of an enum's value range

-ftrap-function=&lt;value&gt; Issue call to specified function rather than a trap instruction

-ftrapv-handler=&lt;function name&gt;

Specify the function to be called on overflow

-ftrapv Trap on integer overflow

-ftrigraphs Process trigraph sequences

-funique-section-names Use unique names for text and data sections (ELF Only)

-funroll-loops Turn on loop unroller

-fuse-init-array Use .init_array instead of .ctors

-fveclib=&lt;value&gt; Use the given vector functions library

-fvectorize Enable the loop vectorization passes

-fvisibility-inlines-hidden

Give inline C++ member functions default visibility by default

-fvisibility-ms-compat Give global types 'default' visibility and global functions and variables 'hidden' visibility by default

-fvisibility=&lt;value&gt; Set the default symbol visibility for all global declarations

-fwrapv Treat signed integer overflow as two's complement

-fwritable-strings Store string literals as writable data

-fzvector Enable System z vector language extension

-F &lt;value&gt; Add directory to framework include search path

--gcc-toolchain=&lt;value&gt; Use the gcc toolchain at the given directory

-gdwarf-2 Generate source-level debug information with dwarf version 2

-gdwarf-3 Generate source-level debug information with dwarf version 3

-gdwarf-4 Generate source-level debug information with dwarf version 4

-gline-tables-only Emit debug line number tables only

-g Generate source-level debug information

-help Display available options

-H Show header includes and nesting depth

-idirafter &lt;value&gt; Add directory to AFTER include search path

-iframework &lt;value&gt; Add directory to SYSTEM framework search path

-imacros &lt;file&gt; Include macros from file before parsing

-include-pch &lt;file&gt; Include precompiled header file

-include &lt;file&gt; Include file before parsing

-index-header-map Make the next included directory (-I or -F) an indexer header map

-iprefix &lt;dir&gt; Set the -iwithprefix/-iwithprefixbefore prefix

-iquote &lt;directory&gt; Add directory to QUOTE include search path

-isysroot &lt;dir&gt; Set the system root directory (usually /)

-isystem &lt;directory&gt; Add directory to SYSTEM include search path

-ivfsoverlay &lt;value&gt; Overlay the virtual filesystem described by file over the real file system

-iwithprefixbefore &lt;dir&gt;

Set directory to include search path with prefix

-iwithprefix &lt;dir&gt; Set directory to SYSTEM include search path with prefix

-iwithsysroot &lt;directory&gt;

Add directory to SYSTEM include search path, absolute paths are relative to -isysroot

-I &lt;value&gt; Add directory to include search path

-mabicalls Enable SVR4-style position-independent code (Mips only)

-mcrc Allow use of CRC instructions (ARM only)

-MD Write a depfile containing user and system headers

-mfix-cortex-a53-835769 Workaround Cortex-A53 erratum 835769 (AArch64 only)

-mfp32 Use 32-bit floating point registers (MIPS only)

-mfp64 Use 64-bit floating point registers (MIPS only)

-MF &lt;file&gt; Write depfile output from -MMD, -MD, -MM, or -M to &lt;file&gt;

-mgeneral-regs-only Generate code which only uses the general purpose registers (AArch64 only)

-mglobal-merge Enable merging of globals

-MG Add missing headers to depfile

--migrate Run the migrator

-mios-version-min=&lt;value&gt;

Set iOS deployment target

-mllvm &lt;value&gt; Additional arguments to forward to LLVM's option processing

-mlong-calls Generate an indirect jump to enable jumps further than 64M

-mmacosx-version-min=&lt;value&gt;

Set Mac OS X deployment target

-MMD Write a depfile containing user headers

-mms-bitfields Set the default structure layout to be compatible with the Microsoft compiler standard

-mmsa Enable MSA ASE (MIPS only)

-MM Like -MMD, but also implies -E and writes to stdout by default

-mno-abicalls Disable SVR4-style position-independent code (Mips only)

-mno-fix-cortex-a53-835769

Don't workaround Cortex-A53 erratum 835769 (AArch64 only)

-mno-global-merge Disable merging of globals

-mno-implicit-float Don't generate implicit floating point instructions

-mno-long-calls Restore the default behaviour of not generating long calls

-mno-msa Disable MSA ASE (MIPS only)

-mno-restrict-it Allow generation of deprecated IT blocks for ARMv8. It is off by default for ARMv8 Thumb mode

-mno-unaligned-access Force all memory accesses to be aligned (AArch32/AArch64 only)

-mnocrc Disallow use of CRC instructions (ARM only)

-module-dependency-dir &lt;value&gt;

Directory to dump module dependencies to

-momit-leaf-frame-pointer

Omit frame pointer setup for leaf functions

-MP Create phony target for each dependency (other than main file)

-mqdsp6-compat Enable hexagon-qdsp6 backward compatibility

-MQ &lt;value&gt; Specify name of main file output to quote in depfile

-mrelax-all (integrated-as) Relax all machine instructions

-mrestrict-it Disallow generation of deprecated IT blocks for ARMv8. It is on by default for ARMv8 Thumb mode.

-mrtd Make StdCall calling convention the default

-msoft-float Use software floating point

-mstack-alignment=&lt;value&gt;

Set the stack alignment

-mstack-probe-size=&lt;value&gt;

Set the stack probe size

-mstackrealign Force realign the stack at entry to every function

-mthread-model &lt;value&gt; The thread model to use, e.g. posix, single (posix by default)

-MT &lt;value&gt; Specify name of main file output in depfile

-munaligned-access Allow memory accesses to be unaligned (AArch32/AArch64 only)

-MV Use NMake/Jom format for the depfile

-M Like -MD, but also implies -E and writes to stdout by default

--no-system-header-prefix=&lt;prefix&gt;

Treat all #include paths starting with &lt;prefix&gt; as not including a system header.

-nobuiltininc Disable builtin #include directories

-nostdinc++ Disable standard #include directories for the C++ standard library

-ObjC++ Treat source input files as Objective-C++ inputs

-objcmt-atomic-property Make migration to 'atomic' properties

-objcmt-migrate-all Enable migration to modern ObjC

-objcmt-migrate-annotation

Enable migration to property and method annotations

-objcmt-migrate-designated-init

Enable migration to infer NS_DESIGNATED_INITIALIZER for initializer methods

-objcmt-migrate-instancetype

Enable migration to infer instancetype for method result type

-objcmt-migrate-literals

Enable migration to modern ObjC literals

-objcmt-migrate-ns-macros

Enable migration to NS_ENUM/NS_OPTIONS macros

-objcmt-migrate-property-dot-syntax

Enable migration of setter/getter messages to property-dot syntax

-objcmt-migrate-property

Enable migration to modern ObjC property

-objcmt-migrate-protocol-conformance

Enable migration to add protocol conformance on classes

-objcmt-migrate-readonly-property

Enable migration to modern ObjC readonly property

-objcmt-migrate-readwrite-property

Enable migration to modern ObjC readwrite property

-objcmt-migrate-subscripting

Enable migration to modern ObjC subscripting

-objcmt-ns-nonatomic-iosonly

Enable migration to use NS_NONATOMIC_IOSONLY macro for setting property's 'atomic' attribute

-objcmt-returns-innerpointer-property

Enable migration to annotate property with NS_RETURNS_INNER_POINTER

-objcmt-whitelist-dir-path=&lt;value&gt;

Only modify files with a filename contained in the provided directory path

-ObjC Treat source input files as Objective-C inputs

-o &lt;file&gt; Write output to &lt;file&gt;

-pg Enable mcount instrumentation

-pipe Use pipes between commands, when possible

-print-file-name=&lt;file&gt; Print the full library path of &lt;file&gt;

-print-ivar-layout Enable Objective-C Ivar layout bitmap print trace

-print-libgcc-file-name Print the library path for "libgcc.a"

-print-prog-name=&lt;name&gt; Print the full program path of &lt;name&gt;

-print-search-dirs Print the paths used for finding libraries and programs

-pthread Support POSIX threads in generated code

-P Disable linemarker output in -E mode

-Qunused-arguments Don't emit warning for unused driver arguments

-relocatable-pch Whether to build a relocatable precompiled header

-rewrite-legacy-objc Rewrite Legacy Objective-C source to C++

-rewrite-objc Rewrite Objective-C source to C++

-Rpass-analysis=&lt;value&gt; Report transformation analysis from optimization passes whose name matches the given POSIX regular expression

-Rpass-missed=&lt;value&gt; Report missed transformations by optimization passes whose name matches the given POSIX regular expression

-Rpass=&lt;value&gt; Report transformations performed by optimization passes whose name matches the given POSIX regular expression

-R&lt;remark&gt; Enable the specified remark

-save-temps=&lt;value&gt; Save intermediate compilation results.

-save-temps Save intermediate compilation results

-serialize-diagnostics &lt;value&gt;

Serialize compiler diagnostics to a file

-std=&lt;value&gt; Language standard to compile for

-stdlib=&lt;value&gt; C++ standard library to use

--system-header-prefix=&lt;prefix&gt;

Treat all #include paths starting with &lt;prefix&gt; as including a system header.

-S Only run preprocess and compilation steps

--target=&lt;value&gt; Generate code for the given target

-time Time individual commands

-traditional-cpp Enable some traditional CPP emulation

-trigraphs Process trigraph sequences

-undef undef all system defines

--verify-debug-info Verify the binary representation of debug output

-verify-pch Load and verify that a pre-compiled header file is not stale

-v Show commands to run and use verbose output

-Wa,&lt;arg&gt; Pass the comma separated arguments in &lt;arg&gt; to the assembler

-Wl,&lt;arg&gt; Pass the comma separated arguments in &lt;arg&gt; to the linker

-working-directory &lt;value&gt;

Resolve file paths relative to the specified directory

-Wp,&lt;arg&gt; Pass the comma separated arguments in &lt;arg&gt; to the preprocessor

-W&lt;warning&gt; Enable the specified warning

-w Suppress all warnings

-Xanalyzer &lt;arg&gt; Pass &lt;arg&gt; to the static analyzer

-Xassembler &lt;arg&gt; Pass &lt;arg&gt; to the assembler

-Xclang &lt;arg&gt; Pass &lt;arg&gt; to the clang compiler

-Xlinker &lt;arg&gt; Pass &lt;arg&gt; to the linker

-Xpreprocessor &lt;arg&gt; Pass &lt;arg&gt; to the preprocessor

-x &lt;language&gt; Treat subsequent input files as having type &lt;language&gt;

-z &lt;arg&gt; Pass -z &lt;arg&gt; to the linker

==&gt; And querying our built clang compiler

C:\\subversion\\llvm\\build\\Debug\\bin&gt;"C:\\subversion\\llvm\\build\\Debug\\bin\\clang.exe" --help &gt; llvm_clang_options.txt

==&gt; Results in a text file with the following content

OVERVIEW: clang LLVM compiler

USAGE: clang.exe &#91;options&#93; &lt;inputs&gt;

OPTIONS:

-### Print (but do not run) the commands to run for this compilation

--analyze Run the static analyzer

-arcmt-migrate-emit-errors

Emit ARC errors even if the migrator can fix them

-arcmt-migrate-report-output &lt;value&gt;

Output path for the plist report

--cuda-device-only Do device-side CUDA compilation only

--cuda-host-only Do host-side CUDA compilation only

--cuda-path=&lt;value&gt; CUDA installation path

-cxx-isystem &lt;directory&gt;

Add directory to the C++ SYSTEM include search path

-c Only run preprocess, compile, and assemble steps

-dD Print macro definitions in -E mode in addition to normal output

-dependency-dot &lt;value&gt; Filename to write DOT-formatted header dependencies to

-dependency-file &lt;value&gt;

Filename (or -) to write dependency output to

-dM Print macro definitions in -E mode instead of normal output

-emit-ast Emit Clang AST files for source inputs

-emit-llvm Use the LLVM representation for assembler and object files

-E Only run the preprocessor

-faltivec Enable AltiVec vector initializer syntax

-fansi-escape-codes Use ANSI escape codes for diagnostics

-fapple-kext Use Apple's kernel extensions ABI

-fapple-pragma-pack Enable Apple gcc-compatible #pragma pack handling

-fapplication-extension Restrict code to those available for App Extensions

-fblocks Enable the 'blocks' language feature

-fborland-extensions Accept non-standard constructs supported by the Borland compiler

-fbuild-session-file=&lt;file&gt;

Use the last modification time of &lt;file&gt; as the build session timestamp

-fbuild-session-timestamp=&lt;time since Epoch in seconds&gt;

Time when the current build session started

-fcolor-diagnostics Use colors in diagnostics

-fcomment-block-commands=&lt;arg&gt;

Treat each comma separated argument in &lt;arg&gt; as a documentation comment block command

-fcoverage-mapping Generate coverage mapping to enable code coverage analysis

-fcxx-exceptions Enable C++ exceptions

-fdata-sections Place each data in its own section (ELF Only)

-fdebug-prefix-map=&lt;value&gt;

remap file source paths in debug info

-fdebug-types-section Place debug types in their own section (ELF Only)

-fdeclspec Allow __declspec as a keyword

-fdelayed-template-parsing

Parse templated function definitions at the end of the translation unit

-fdiagnostics-parseable-fixits

Print fix-its in machine parseable form

-fdiagnostics-print-source-range-info

Print source range spans in numeric form

-fdiagnostics-show-note-include-stack

Display include stacks for diagnostic notes

-fdiagnostics-show-option

Print option name with mappable diagnostics

-fdiagnostics-show-template-tree

Print a template comparison tree for differing templates

-fdollars-in-identifiers

Allow '$' in identifiers

-femit-all-decls Emit all declarations, even if unused

-femulated-tls Use emutls functions to access thread_local variables

-fexceptions Enable support for exception handling

-ffast-math Enable the \*frontend\*'s 'fast-math' mode. This has no effect on optimizations, but provides a preprocessor macro __FAST_MATH__ the same as GCC's -ffast-math flag

-ffixed-r9 Reserve the r9 register (ARM only)

-ffixed-x18 Reserve the x18 register (AArch64 only)

-ffp-contract=&lt;value&gt; Form fused FP ops (e.g. FMAs): fast (everywhere) | on (according to FP_CONTRACT pragma, default) | off (never fuse)

-ffreestanding Assert that the compilation takes place in a freestanding environment

-ffunction-sections Place each function in its own section (ELF Only)

-fgnu-keywords Allow GNU-extension keywords regardless of language standard

-fgnu-runtime Generate output compatible with the standard GNU Objective-C runtime

-fgnu89-inline Use the gnu89 inline semantics

-fimplicit-module-maps Implicitly search the file system for module map files.

-finstrument-functions Generate calls to instrument function entry and exit

-fintegrated-as Enable the integrated assembler

-flto=&lt;value&gt; Set LTO mode to either 'full' or 'thin'

-flto Enable LTO in 'full' mode

-fmath-errno Require math functions to indicate errors by setting errno

-fmax-type-align=&lt;value&gt;

Specify the maximum alignment to enforce on pointers lacking an explicit alignment

-fmodule-file=&lt;file&gt; Load this precompiled module file

-fmodule-map-file=&lt;file&gt;

Load this module map file

-fmodule-name= &lt;name&gt; Specify the name of the module to build

-fmodules-cache-path=&lt;directory&gt;

Specify the module cache path

-fmodules-decluse Require declaration of modules used within a module

-fmodules-ignore-macro=&lt;value&gt;

Ignore the definition of the given macro when building and loading modules

-fmodules-prune-after=&lt;seconds&gt;

Specify the interval (in seconds) after which a module file will be considered unused

-fmodules-prune-interval=&lt;seconds&gt;

Specify the interval (in seconds) between attempts to prune the module cache

-fmodules-search-all Search even non-imported modules to resolve references

-fmodules-strict-decluse

Like -fmodules-decluse but requires all headers to be in modules

-fmodules-user-build-path &lt;directory&gt;

Specify the module user build path

-fmodules-validate-once-per-build-session

Don't verify input files for the modules if the module has been successfully validated or loaded during this build session

-fmodules-validate-system-headers

Validate the system headers that a module depends on when loading the module

-fmodules Enable the 'modules' language feature

-fms-compatibility-version=&lt;value&gt;

Dot-separated value representing the Microsoft compiler version number to report in _MSC_VER (0 = don't define it (default))

-fms-compatibility Enable full Microsoft Visual C++ compatibility

-fms-extensions Accept some non-standard constructs supported by the Microsoft compiler

-fmsc-version=&lt;value&gt; Microsoft compiler version number to report in _MSC_VER (0 = don't define it (default))

-fno-access-control Disable C++ access control

-fno-assume-sane-operator-new

Don't assume that C++'s global operator new can't alias any pointer

-fno-autolink Disable generation of linker directives for automatic library linking

-fno-builtin-&lt;value&gt; Disable implicit builtin knowledge of a specific function

-fno-builtin Disable implicit builtin knowledge of functions

-fno-common Compile common globals like normal definitions

-fno-constant-cfstrings Disable creation of CodeFoundation-type constant strings

-fno-coverage-mapping Disable code coverage analysis

-fno-declspec Disallow __declspec as a keyword

-fno-diagnostics-fixit-info

Do not include fixit information in diagnostics

-fno-dollars-in-identifiers

Disallow '$' in identifiers

-fno-elide-constructors Disable C++ copy constructor elision

-fno-elide-type Do not elide types when printing diagnostics

-fno-gnu-inline-asm Disable GNU style inline asm

-fno-integrated-as Disable the integrated assembler

-fno-lax-vector-conversions

Disallow implicit conversions between vectors with a different number of elements or different element types

-fno-lto Disable LTO mode (default)

-fno-math-builtin Disable implicit builtin knowledge of math functions

-fno-merge-all-constants

Disallow merging of constants

-fno-objc-infer-related-result-type

do not infer Objective-C related result type based on method family

-fno-operator-names Do not treat C++ operator name keywords as synonyms for operators

-fno-profile-instr-generate

Disable generation of profile instrumentation.

-fno-profile-instr-use Disable using instrumentation data for profile-guided optimization

-fno-reroll-loops Turn off loop reroller

-fno-rtti Disable generation of rtti information

-fno-sanitize-blacklist Don't use blacklist file for sanitizers

-fno-sanitize-cfi-cross-dso

Disable control flow integrity (CFI) checks for cross-DSO calls.

-fno-sanitize-coverage=&lt;value&gt;

Disable specified features of coverage instrumentation for Sanitizers

-fno-sanitize-memory-track-origins

Disable origins tracking in MemorySanitizer

-fno-sanitize-recover=&lt;value&gt;

Disable recovery for specified sanitizers

-fno-sanitize-trap=&lt;value&gt;

Disable trapping for specified sanitizers

-fno-short-wchar Force wchar_t to be an unsigned int

-fno-show-column Do not include column number on diagnostics

-fno-show-source-location

Do not include source location information with diagnostics

-fno-signed-char Char is unsigned

-fno-signed-zeros Allow optimizations that ignore the sign of floating point zeros

-fno-spell-checking Disable spell-checking

-fno-stack-protector Disable the use of stack protectors

-fno-standalone-debug Limit debug information produced to reduce size of debug binary

-fno-threadsafe-statics Do not emit code to make initialization of local statics thread safe

-fno-trigraphs Do not process trigraph sequences

-fno-unroll-loops Turn off loop unroller

-fno-use-cxa-atexit Don't use __cxa_atexit for calling destructors

-fno-use-init-array Don't use .init_array instead of .ctors

-fobjc-arc-exceptions Use EH-safe code when synthesizing retains and releases in -fobjc-arc

-fobjc-arc Synthesize retain and release calls for Objective-C pointers

-fobjc-exceptions Enable Objective-C exceptions

-fobjc-gc-only Use GC exclusively for Objective-C related memory management

-fobjc-gc Enable Objective-C garbage collection

-fobjc-runtime=&lt;value&gt; Specify the target Objective-C runtime kind and version

-fobjc-weak Enable ARC-style weak references in Objective-C

-fpack-struct=&lt;value&gt; Specify the default maximum struct packing alignment

-fpascal-strings Recognize and construct Pascal-style string literals

-fpcc-struct-return Override the default ABI to return all structs on the stack

-fplugin=&lt;dsopath&gt; Load the named plugin (dynamic shared object)

-fprofile-generate=&lt;directory&gt;

Generate instrumented code to collect execution counts into &lt;directory&gt;/default.profraw (overridden by LLVM_PROFILE_FILE env var)

-fprofile-instr-generate=&lt;file&gt;

Generate instrumented code to collect execution counts into &lt;file&gt; (overridden by LLVM_PROFILE_FILE env var)

-fprofile-instr-generate

Generate instrumented code to collect execution counts into default.profraw file (overriden by '=' form of option or LLVM_PROFILE_FILE env var)

-fprofile-instr-use=&lt;value&gt;

Use instrumentation data for profile-guided optimization

-fprofile-sample-use=&lt;value&gt;

Enable sample-based profile guided optimizations

-fprofile-use=&lt;pathname&gt;

Use instrumentation data for profile-guided optimization. If pathname is a directory, it reads from &lt;pathname&gt;/default.profdata. Otherwise, it reads from file &lt;pathname&gt;.

-freciprocal-math Allow division operations to be reassociated

-freg-struct-return Override the default ABI to return small structs in registers

-freroll-loops Turn on loop reroller

-fsanitize-address-field-padding=&lt;value&gt;

Level of field padding for AddressSanitizer

-fsanitize-blacklist=&lt;value&gt;

Path to blacklist file for sanitizers

-fsanitize-cfi-cross-dso

Enable control flow integrity (CFI) checks for cross-DSO calls.

-fsanitize-coverage=&lt;value&gt;

Specify the type of coverage instrumentation for Sanitizers

-fsanitize-memory-track-origins=&lt;value&gt;

Enable origins tracking in MemorySanitizer

-fsanitize-memory-track-origins

Enable origins tracking in MemorySanitizer

-fsanitize-memory-use-after-dtor

Enable use-after-destroy detection in MemorySanitizer

-fsanitize-recover=&lt;value&gt;

Enable recovery for specified sanitizers

-fsanitize-trap=&lt;value&gt; Enable trapping for specified sanitizers

-fsanitize=&lt;check&gt; Turn on runtime checks for various forms of undefined or suspicious behavior. See user manual for available checks

-fshort-enums Allocate to an enum type only as many bytes as it needs for the declared range of possible values

-fshort-wchar Force wchar_t to be a short unsigned int

-fshow-overloads=&lt;value&gt;

Which overload candidates to show when overload resolution fails: best|all; defaults to all

-fsized-deallocation Enable C++14 sized global deallocation functions

-fslp-vectorize-aggressive

Enable the BB vectorization passes

-fslp-vectorize Enable the superword-level parallelism vectorization passes

-fstack-protector-all Force the usage of stack protectors for all functions

-fstack-protector-strong

Use a strong heuristic to apply stack protectors to functions

-fstack-protector Enable stack protectors for functions potentially vulnerable to stack smashing

-fstandalone-debug Emit full debug info for all types used by the program

-fstrict-enums Enable optimizations based on the strict definition of an enum's value range

-fstrict-vtable-pointers

Enable optimizations based on the strict rules for overwriting polymorphic C++ objects

-fthinlto-index=&lt;value&gt; Perform ThinLTO importing using provided function summary index

-ftrap-function=&lt;value&gt; Issue call to specified function rather than a trap instruction

-ftrapv-handler=&lt;function name&gt;

Specify the function to be called on overflow

-ftrapv Trap on integer overflow

-ftrigraphs Process trigraph sequences

-funique-section-names Use unique names for text and data sections (ELF Only)

-funroll-loops Turn on loop unroller

-fuse-init-array Use .init_array instead of .ctors

-fveclib=&lt;value&gt; Use the given vector functions library

-fvectorize Enable the loop vectorization passes

-fvisibility-inlines-hidden

Give inline C++ member functions default visibility by default

-fvisibility-ms-compat Give global types 'default' visibility and global functions and variables 'hidden' visibility by default

-fvisibility=&lt;value&gt; Set the default symbol visibility for all global declarations

-fwrapv Treat signed integer overflow as two's complement

-fwritable-strings Store string literals as writable data

-fzvector Enable System z vector language extension

-F &lt;value&gt; Add directory to framework include search path

--gcc-toolchain=&lt;value&gt; Use the gcc toolchain at the given directory

-gcodeview Generate CodeView debug information

-gdwarf-2 Generate source-level debug information with dwarf version 2

-gdwarf-3 Generate source-level debug information with dwarf version 3

-gdwarf-4 Generate source-level debug information with dwarf version 4

-gline-tables-only Emit debug line number tables only

-gmodules Generate debug info with external references to clang modules or precompiled headers

-g Generate source-level debug information

-help Display available options

-H Show header includes and nesting depth

-idirafter &lt;value&gt; Add directory to AFTER include search path

-iframework &lt;value&gt; Add directory to SYSTEM framework search path

-imacros &lt;file&gt; Include macros from file before parsing

-include-pch &lt;file&gt; Include precompiled header file

-include &lt;file&gt; Include file before parsing

-index-header-map Make the next included directory (-I or -F) an indexer header map

-iprefix &lt;dir&gt; Set the -iwithprefix/-iwithprefixbefore prefix

-iquote &lt;directory&gt; Add directory to QUOTE include search path

-isysroot &lt;dir&gt; Set the system root directory (usually /)

-isystem &lt;directory&gt; Add directory to SYSTEM include search path

-ivfsoverlay &lt;value&gt; Overlay the virtual filesystem described by file over the real file system

-iwithprefixbefore &lt;dir&gt;

Set directory to include search path with prefix

-iwithprefix &lt;dir&gt; Set directory to SYSTEM include search path with prefix

-iwithsysroot &lt;directory&gt;

Add directory to SYSTEM include search path, absolute paths are relative to -isysroot

-I &lt;value&gt; Add directory to include search path

-mabicalls Enable SVR4-style position-independent code (Mips only)

-mcrc Allow use of CRC instructions (ARM only)

-MD Write a depfile containing user and system headers

-meabi &lt;value&gt; Set EABI type, e.g. 4, 5 or gnu (default depends on triple)

-mfix-cortex-a53-835769 Workaround Cortex-A53 erratum 835769 (AArch64 only)

-mfp32 Use 32-bit floating point registers (MIPS only)

-mfp64 Use 64-bit floating point registers (MIPS only)

-MF &lt;file&gt; Write depfile output from -MMD, -MD, -MM, or -M to &lt;file&gt;

-mgeneral-regs-only Generate code which only uses the general purpose registers (AArch64 only)

-mglobal-merge Enable merging of globals

-MG Add missing headers to depfile

-mhvx-double Enable Hexagon Double Vector eXtensions

-mhvx Enable Hexagon Vector eXtensions

--migrate Run the migrator

-mios-version-min=&lt;value&gt;

Set iOS deployment target

-mllvm &lt;value&gt; Additional arguments to forward to LLVM's option processing

-mlong-calls Generate an indirect jump to enable jumps further than 64M

-mmacosx-version-min=&lt;value&gt;

Set Mac OS X deployment target

-MMD Write a depfile containing user headers

-mms-bitfields Set the default structure layout to be compatible with the Microsoft compiler standard

-mmsa Enable MSA ASE (MIPS only)

-MM Like -MMD, but also implies -E and writes to stdout by default

-mno-abicalls Disable SVR4-style position-independent code (Mips only)

-mno-fix-cortex-a53-835769

Don't workaround Cortex-A53 erratum 835769 (AArch64 only)

-mno-global-merge Disable merging of globals

-mno-hvx-double Disable Hexagon Double Vector eXtensions

-mno-hvx Disable Hexagon Vector eXtensions

-mno-implicit-float Don't generate implicit floating point instructions

-mno-long-calls Restore the default behaviour of not generating long calls

-mno-ms-bitfields Do not set the default structure layout to be compatible with the Microsoft compiler standard

-mno-msa Disable MSA ASE (MIPS only)

-mno-restrict-it Allow generation of deprecated IT blocks for ARMv8. It is off by default for ARMv8 Thumb mode

-mno-unaligned-access Force all memory accesses to be aligned (AArch32/AArch64 only)

-mnocrc Disallow use of CRC instructions (ARM only)

-module-dependency-dir &lt;value&gt;

Directory to dump module dependencies to

-momit-leaf-frame-pointer

Omit frame pointer setup for leaf functions

-MP Create phony target for each dependency (other than main file)

-mqdsp6-compat Enable hexagon-qdsp6 backward compatibility

-MQ &lt;value&gt; Specify name of main file output to quote in depfile

-mrelax-all (integrated-as) Relax all machine instructions

-mrestrict-it Disallow generation of deprecated IT blocks for ARMv8. It is on by default for ARMv8 Thumb mode.

-mrtd Make StdCall calling convention the default

-msoft-float Use software floating point

-mstack-alignment=&lt;value&gt;

Set the stack alignment

-mstack-probe-size=&lt;value&gt;

Set the stack probe size

-mstackrealign Force realign the stack at entry to every function

-mthread-model &lt;value&gt; The thread model to use, e.g. posix, single (posix by default)

-MT &lt;value&gt; Specify name of main file output in depfile

-munaligned-access Allow memory accesses to be unaligned (AArch32/AArch64 only)

-MV Use NMake/Jom format for the depfile

-M Like -MD, but also implies -E and writes to stdout by default

--no-system-header-prefix=&lt;prefix&gt;

Treat all #include paths starting with &lt;prefix&gt; as not including a system header.

-nobuiltininc Disable builtin #include directories

-nostdinc++ Disable standard #include directories for the C++ standard library

-ObjC++ Treat source input files as Objective-C++ inputs

-objcmt-atomic-property Make migration to 'atomic' properties

-objcmt-migrate-all Enable migration to modern ObjC

-objcmt-migrate-annotation

Enable migration to property and method annotations

-objcmt-migrate-designated-init

Enable migration to infer NS_DESIGNATED_INITIALIZER for initializer methods

-objcmt-migrate-instancetype

Enable migration to infer instancetype for method result type

-objcmt-migrate-literals

Enable migration to modern ObjC literals

-objcmt-migrate-ns-macros

Enable migration to NS_ENUM/NS_OPTIONS macros

-objcmt-migrate-property-dot-syntax

Enable migration of setter/getter messages to property-dot syntax

-objcmt-migrate-property

Enable migration to modern ObjC property

-objcmt-migrate-protocol-conformance

Enable migration to add protocol conformance on classes

-objcmt-migrate-readonly-property

Enable migration to modern ObjC readonly property

-objcmt-migrate-readwrite-property

Enable migration to modern ObjC readwrite property

-objcmt-migrate-subscripting

Enable migration to modern ObjC subscripting

-objcmt-ns-nonatomic-iosonly

Enable migration to use NS_NONATOMIC_IOSONLY macro for setting property's 'atomic' attribute

-objcmt-returns-innerpointer-property

Enable migration to annotate property with NS_RETURNS_INNER_POINTER

-objcmt-whitelist-dir-path=&lt;value&gt;

Only modify files with a filename contained in the provided directory path

-ObjC Treat source input files as Objective-C inputs

-o &lt;file&gt; Write output to &lt;file&gt;

-pg Enable mcount instrumentation

-pipe Use pipes between commands, when possible

-print-file-name=&lt;file&gt; Print the full library path of &lt;file&gt;

-print-ivar-layout Enable Objective-C Ivar layout bitmap print trace

-print-libgcc-file-name Print the library path for "libgcc.a"

-print-prog-name=&lt;name&gt; Print the full program path of &lt;name&gt;

-print-search-dirs Print the paths used for finding libraries and programs

-pthread Support POSIX threads in generated code

-P Disable linemarker output in -E mode

-Qunused-arguments Don't emit warning for unused driver arguments

-relocatable-pch Whether to build a relocatable precompiled header

-rewrite-legacy-objc Rewrite Legacy Objective-C source to C++

-rewrite-objc Rewrite Objective-C source to C++

-Rpass-analysis=&lt;value&gt; Report transformation analysis from optimization passes whose name matches the given POSIX regular expression

-Rpass-missed=&lt;value&gt; Report missed transformations by optimization passes whose name matches the given POSIX regular expression

-Rpass=&lt;value&gt; Report transformations performed by optimization passes whose name matches the given POSIX regular expression

-R&lt;remark&gt; Enable the specified remark

-save-temps=&lt;value&gt; Save intermediate compilation results.

-save-temps Save intermediate compilation results

-serialize-diagnostics &lt;value&gt;

Serialize compiler diagnostics to a file

-std=&lt;value&gt; Language standard to compile for

-stdlib=&lt;value&gt; C++ standard library to use

--system-header-prefix=&lt;prefix&gt;

Treat all #include paths starting with &lt;prefix&gt; as including a system header.

-S Only run preprocess and compilation steps

--target=&lt;value&gt; Generate code for the given target

-time Time individual commands

-traditional-cpp Enable some traditional CPP emulation

-trigraphs Process trigraph sequences

-undef undef all system defines

--verify-debug-info Verify the binary representation of debug output

-verify-pch Load and verify that a pre-compiled header file is not stale

-v Show commands to run and use verbose output

-Wa,&lt;arg&gt; Pass the comma separated arguments in &lt;arg&gt; to the assembler

-Wl,&lt;arg&gt; Pass the comma separated arguments in &lt;arg&gt; to the linker

-working-directory &lt;value&gt;

Resolve file paths relative to the specified directory

-Wp,&lt;arg&gt; Pass the comma separated arguments in &lt;arg&gt; to the preprocessor

-W&lt;warning&gt; Enable the specified warning

-w Suppress all warnings

-Xanalyzer &lt;arg&gt; Pass &lt;arg&gt; to the static analyzer

-Xassembler &lt;arg&gt; Pass &lt;arg&gt; to the assembler

-Xclang &lt;arg&gt; Pass &lt;arg&gt; to the clang compiler

-Xlinker &lt;arg&gt; Pass &lt;arg&gt; to the linker

-Xpreprocessor &lt;arg&gt; Pass &lt;arg&gt; to the preprocessor

-x &lt;language&gt; Treat subsequent input files as having type &lt;language&gt;

-z &lt;arg&gt; Pass -z &lt;arg&gt; to the linker

**… WE ARE HERE ...**

{% endraw %}
