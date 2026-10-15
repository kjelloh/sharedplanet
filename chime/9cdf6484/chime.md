# Todo: programming - Consider to implement a C++ open source library to compile-time identify the build tool chain and target platform?

```#9cdf6484``` *As of 2016-08-10 16:04*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to implement a C++ library that provides a mechanism with which C++ source code may compile-time detect and apply knowledge about the build tool-chain and target platform?

==&gt; Also see “[Todo: Programming - Consider to implement a set of Data Model Investigator services as a C++ library?](../da551771/chime.md)”

1) Consider a good name for this compile-time build tool chain and target identification library?

==&gt; Consider a name that refers to the name of that greek traveller (<https://en.wikipedia.org/wiki/Greek_mythology>)?

==&gt; Consider “Odysseus” (As a reference to the traveller of geek mythology)?

...

2) Consider to aim at having this library be drop-in compatible with existing cross platform projects?

==&gt; Consider to evaluate what this library must do to provide for Jason Turner open source cross platform projects (<https://www.youtube.com/watch?v=cb3WIL96N-o&list=PLs3KjaCtOwSaUCQOzoGEhKwYxQL3qs8ub&index=2>)

==&gt; Consider to especially study how to support cross platform mechanism to Jason Turner Chaiscript project (<https://github.com/ChaiScript/ChaiScript>)?

==&gt; This seem to be the compile-time macro generator for chaiscript (<https://github.com/ChaiScript/ChaiScript/blob/develop/include/chaiscript/chaiscript_defines.hpp>)?

==&gt; it seems to first do pre-processor build environment identification into special CHAISCRIPT_xxx macros

pre-processer(macros…) ==&gt; CHAISCRIPT_xxx ...

> > #ifdef _MSC_VER ==&gt; To identify Visual studio and declspec support  
> > #if defined( _LIBCPP_VERSION ) ==&gt; To identify C++ standard library  
> > #if defined(_WIN32) || defined(__CYGWIN__) ==&gt; To identify on windows platform  
> > #if defined(_WIN32)  
> > #if defined(__llvm__) ==&gt; clang on windows  
> > #elif defined(__GNUC__) ==&gt; clang on MinGW  
> > ==&gt; Else Visual Studio (on windows of course)  
> > #else ==&gt;To identify Clang or GCC  
> > #if defined(CHAISCRIPT_MSVC) || (defined(__GNUC__) && __GNUC__ &gt; 4) || (__GNUC__ == 4 && __GNUC_MINOR__ &gt;= 8) || (defined(__llvm__) && !defined(CHAISCRIPT_LIBCPP)) ==&gt; To identify ha Thread Local  
> > #if defined(__llvm__) ==&gt; To identify Clang Chaiscript

==&gt; Then it seems to populate the chaiscript namespace based on CHAISCRIPT_xxx macros?

using chaiscript::xxx = pre-processor(CHAISCRIPT_yyy…)

==&gt; It seem to populate the namespace with compile time literals?

> > static const char \*compiler_version = CHAISCRIPT_COMPILER_VERSION;  
> > static const char \*compiler_name = CHAISCRIPT_COMPILER_NAME;  
> > static const bool debug_build = CHAISCRIPT_DEBUG;

==&gt; It seems to populate chaiscript namespace with pre-processor tuned functions?

> > template&lt;typename B, typename D, typename ...Arg&gt;

> > inline std::shared_ptr&lt;B&gt; make_shared(Arg && ... arg)

> > {

> > #ifdef CHAISCRIPT_USE_STD_MAKE_SHARED

> > return std::make_shared&lt;D&gt;(std::forward&lt;Arg&gt;(arg)...);

> > #else

> > return std::shared_ptr&lt;B&gt;(static_cast&lt;B\*&gt;(new D(std::forward&lt;Arg&gt;(arg)...)));

> > #endif

> > }

==&gt; Consider to map how ChaiScript uses pre-processor tuned code (only from CHAISCRIPT_xxx or mixed with standard/proprietary macros)?

**WE ARE HERE...**

3) Consider the mechanisms in C++ we want to leverage with what Odysseus produce as result of its identification processing?

==&gt; Consider to target the C++ “stack” of mechanisms to find what runtime code to generate?

==&gt; Consider to use leads presented by Stephan T. Lavavej in this prevention of his (<https://channel9.msdn.com/Series/C9-Lectures-Stephan-T-Lavavej-Core-C-/Stephan-T-Lavavej-Core-C-1-of-n>)?

==&gt; It seems a C++ compiler uses a pre-set of phases to find a referenced function?

First Name Lookup (<http://en.cppreference.com/w/cpp/language/lookup>)

  
> > > *“Name lookup is the procedure by which a name, when encountered in a program, is associated with the declarationthat introduced it."*

Name lookup seems to honour name visibility (<http://www.cplusplus.com/doc/tutorial/namespaces/>)?

Unqualified name lookup seems to define what is “seen” without explicitly stating so in the reference (<http://en.cppreference.com/w/cpp/language/unqualified_lookup>)?

Then Template Argument Deduction (<http://en.cppreference.com/w/cpp/language/template_argument_deduction>)

  
> > > *“In order to instantiate a function template, every template argument must be known, but not every template argument has to be specified. When possible, the compiler will deduce the missing template arguments from the function arguments. This occurs when a function call is attempted, when an address of a function template is taken, and in some other contexts:"*

Then Overload Resolution (<http://en.cppreference.com/w/cpp/language/overload_resolution>)

  
> > > *“ &#91;if previous&#93;... steps produce more than one candidate function, then overload resolution is performed to select the function that will actually be called."*

Then Access Control

==&gt; Access Control seem to be about honouring the access specifiers public, protected and private (<http://en.cppreference.com/w/cpp/language/access>)?

==&gt; Q: It does not seem to have anything to do with visibility (see above)?

Then Virtual Function Binding (<http://www.cplusplus.com/doc/tutorial/polymorphism/>)

==&gt; It seems we should see the pre-processing step as pre-pending the compiler steps (<http://www.cplusplus.com/doc/tutorial/preprocessor/>)?

> Pre-processor steps  
> ...  
> Compiler steps  
> First Name Lookup (<http://en.cppreference.com/w/cpp/language/lookup>)  
> Then Template Argument Deduction (<http://en.cppreference.com/w/cpp/language/template_argument_deduction>)  
> Then Overload Resolution (<http://en.cppreference.com/w/cpp/language/overload_resolution>)  
> Then Access Control  
> Then Virtual Function Binding (<http://www.cplusplus.com/doc/tutorial/polymorphism/>)  
> Linker steps  
> …

4) Consider what “compile-time” decisions that can be made only by the pre-processor?

==&gt; Consider that using a namespace alias is compile time unconditional and must be decided by the pre-processor?

> **namespace my_namespace = some::name::space; **// my_namespace::member now equals some::name::space::member

==&gt; Consider that bringing in a namespace is compile-time unconditional and presence must be decided by pre-processor (#if, #ifdef…)?

> namespace my_name_space {  
> **using namespace some::name::space;** // brings in all members (e.g. member1) of some::name::space into this namespace  
> }

==&gt; Consider the alternative is replacing namespace members with struct members (requiring cherry-picking what to bring in to struct)?

> > struct my_scope_struct {

> > **using member1 = some::name::space::member1;** // my_scope_struct::member1 is now the name type as some::name::space::member1

> > ...

> > }

==&gt; Consider include of files must be performed and decided by pre-processor (compiler deals only with pre-processed code)?

…

5) Consider a Macro-generating header that provides a defined set of macros that defines the build tool-chain and target platform?

==&gt; Consider these macros may be used in #ifdefs and pre-processor code generation for compile-time code that reflects the build tool chain and target platform?

==&gt; Consider we like pre-processor functionality as small as possible (and prefer compile time type specialisation instead)?

...

6) Consider a Type tag declaring header that provides a defined set of types that defines the build tool-chain and target platform?

==&gt; Consider these types may be used in type traits and template specialisation for compile-time types that reflects the build tool chain and target platform?

==&gt; Consider compile-time functions that defines (or streams) readable identification of the identified compiler?

> std::cout &lt;&lt; odysseus::host_compiler::caption &lt;&lt; std::endl; // (1)  
> …  
> odysseus::host_compiler::print_id(std::out); // (2)  
> ...

…

==&gt; Consider to have odysseus provide a replacement for printf based MSC_VER print (<https://msdn.microsoft.com/en-us/library/b0084kay.aspx>)?

![](<printf of MSC_VER.tiff>)

> *“_MSC_FULL_VER Evaluates to an integer literal that encodes the major, minor, and build number components of the compiler's version number. The major number is the first component of the period-delimited version number, the minor number is the second component, and the build number is the third component. For example, if the version number of the Visual C++ compiler is 15.00.20706.01, the _MSC_FULL_VER macro evaluates to 150020706. Type cl /? at the command line to view the compiler's version number.”*

> *“_MSC_VER Evaluates to an integer literal that encodes the major and minor number components of the compiler's version number. The major number is the first component of the period-delimited version number and the minor number is the second component.”*

> *“_MSC_BUILD Evaluates to an integer literal that contains the revision number component of the compiler's version number. The revision number is the fourth component of the period-delimited version number. For example, if the version number of the Visual C++ compiler is 15.00.20706.01, the _MSC_BUILD macro evaluates to 1."*

> printf(“%02d.%02d.%05d.%02d\\n”  
> , odysseus::compiler::id.major  
> , odysseus::compiler::id.minor  
> , odysseus::compiler::id.build  
> , odysseus::compiler::id.revision);

…

==&gt; NOTE: Consider how to tackle the C++11 incapability of compile-time string processing?

==&gt; Q: What will the compile-time string processing abilities be of C++17?

==&gt; Consider how we should identify the GCC compiler (<https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html>)?

==&gt; Consider this stack overflow thread for gcc version detection (<http://stackoverflow.com/questions/1936719/what-are-the-gcc-predefined-macros-for-the-compilers-version-number>)

> __GNUC__  
> __GNUC_MINOR__  
> __GNUC_PATCHLEVEL__

> ```
> /* Test for GCC > 3.2.0 */
>           #if __GNUC__ > 3 || \
>               (__GNUC__ == 3 && (__GNUC_MINOR__ > 2 || \
>                                  (__GNUC_MINOR__ == 2 && \
>                                   __GNUC_PATCHLEVEL__ > 0))
> ```



==&gt; Consider the clang compiler version macros (<http://clang.llvm.org/docs/UsersManual.html>)?

==&gt; It seems clang for windows may emulate _MSC_VER macros to enable compilation of Visual Studio tuned code?

> *“For compatibility with existing code that compiles with MSVC, clang defines the _MSC_VER and _MSC_FULL_VER macros. These default to the values of 1800 and 180000000 respectively, making clang look like an early release of Visual C++ 2013."*

==&gt; It seems the best way for pre-defined clang macros is to simply ask the compiler on the platform (<http://stackoverflow.com/questions/2658461/what-predefined-macro-can-i-use-to-detect-clang>)?

> > clang -dM -E -x c /dev/null

==&gt; It seems Xcode clang may be version “7.3.0 (clang-703.0.31)”

==&gt; See listings in appendix below

==&gt; The same command seem to be available for GCC (clang emulates gcc options)?

==&gt; Consider to have odysseus provide at least a const std::string mapping to _VERSION_ and then a compiler specific struct with compiler version elements?

==&gt; Hm… It seems we have to provide orthogonal host environment (macOS, Linus, Windows), Actual Compiler (Xcode Cpp, gcc, clang, msvc) and “emulates” (clang may emulate mdvc and gcc)?

> > ==&gt; This seems to be the gcc pre-defined macros on Linux 16.04 MATE?

> > struct gcc_id {

> > const int major; // #define __GNUC__ 5

> > const int minor; // #define __GNUC_MINOR__ 3

> > const int patch_level; // #define __GNUC_PATCHLEVEL__ 1

> > const std::string sVersion; // #define __VERSION__ "5.3.1 20160413”

> > };

> > ==&gt; This seems to be the clang pre-defined macros on Linux 16.04 MATE?

> > struct clang_id {

> > const int major; // #define __clang_major__ 3

> > const int minor; // #define __clang_minor__ 8

> > const int patch_level; // #define __clang_patchlevel__ 0

> > // #define __clang_version__ "3.8.0 (tags/RELEASE_380/final)”

> > const std::string sVersion;  // #define __VERSION__ "4.2.1 Compatible Clang 3.8.0 (tags/RELEASE_380/final)"

> > };

> > ==&gt; This seem to be the gcc pre-defined macros on Windows 10 MinGW?

> > struct gcc_id {

> > const int major; // #define __GNUC__ 5

> > const int minor; // #define __GNUC_MINOR__ 4

> > const int patch_level; // #define __GNUC_PATCHLEVEL__ 0

> > const std::string sVersion; // #define __VERSION__ "5.4.0”

> > };

> > ==&gt; This seems to be the clang pre-defined macros on Windows 10 MinGW?

> > struct clang_id {

> > // #define __GNUC_MINOR__ 2

> > // #define __GNUC_PATCHLEVEL__ 1

> > // #define __GNUC__ 4

> > // #define __WIN64 1

> > // #define __WIN64__ 1

> > // #define __clang__ 1

> > const int major; // #define __clang_major__ 3

> > const int minor; // #define __clang_minor__ 8

> > const int patch_level; // #define __clang_patchlevel__ 0

> > // #define __clang_version__ "3.8.0 (tags/RELEASE_380/final)”

> > const std::string sVersion;  // #define __VERSION__ "4.2.1 Compatible Clang 3.8.0 (tags/RELEASE_380/final)"

> > };

> > ==&gt; This seem to be the clang pre-defined macros on MacOS?

> > struct xcode_clang_id {

> > // #define __GNUC_MINOR__ 2

> > // #define __GNUC_PATCHLEVEL__ 1

> > // #define __GNUC__ 4

> > // #define __apple_build_version__ 7030031

> > // #define __clang__ 1

> > const major; // #define __clang_major__ 7

> > const minor; // #define __clang_minor__ 3

> > const patch_level; // #define __clang_patchlevel__ 0

> > // #define __clang_version__ "7.3.0 (clang-703.0.31)"

> > const std::string sVersion;  // #define __VERSION__ "4.2.1 Compatible Apple LLVM 7.3.0 (clang-703.0.31)"

> > };

**WE ARE HERE…**

7) Consider to define the strict set of identified tool-chains and target environments?

==&gt; Consider we should design a set of values that defines different aspects of the environment?

==&gt; Consider macro values for #ifdef-code?

==&gt; Consider template type tags?

...

==&gt; Consider we should design a set of actors that returns results related to the environment?

==&gt; Consider macro functions?

==&gt; Consider template meta-functions?

...

==&gt; Consider to what degree we need to identify the compiler?

==&gt; Consider to what degree we need to identify the language compliance support (C++98/03, C++11, C++14, C++1y experimental …)

==&gt; Consider to what degree we need to identify the standard library?

==&gt; Consider to what degree we would like to identify standard library experimental (TR) support?

…

8) Consider what mechanisms are available for different tool-chains and standard libraries to support compile time identification of build and target environment?

==&gt; Consider the SG10 proposal that compiler should provide feature-testing macros (<https://isocpp.org/std/standing-documents/sd-6-sg10-feature-test-recommendations>)

==&gt; Note: It seems SD-6 is ”Standing Document 6” and WG10 is the group (study group?) that is responsible for this document?

==&gt; It seems the proposed way to apply feature-macros is to first #ifdef __

==&gt; This seem to be listing the **SD-6** support for **GCC** (<https://gcc.gnu.org/projects/cxx-status.html>)?

==&gt; On this page Clang seems to list support for SD-6 (<http://clang.llvm.org/cxx_status.html#ts>)?

==&gt; Xcode slems to reports it sLLVM version thus implicitly defining its Clang version (<https://gist.github.com/yamaya/2924292>)?

> > Kjell-Olovs-MacBook-Air:~ kjell-olov$ clang++ --version

> > Apple LLVM version 7.3.0 (clang-703.0.31)

> > Target: x86_64-apple-darwin15.6.0

> > Thread model: posix

> > InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin

> > Kjell-Olovs-MacBook-Air:~ kjell-olov$

==&gt; BUT: Apple LLVM is not readily bound to official LLVM releases (<http://stackoverflow.com/questions/32985758/what-is-the-llvm-version-bundled-with-xcode-7>)?

==&gt; Seems the recommendation is to apply the SD-6 macros to compile-time query for feature supports?

==&gt; Microsoft Visual Studio C++ seems to be lagging behind and they list no support for SD-9 (N4200) features (<https://blogs.msdn.microsoft.com/vcblog/2015/04/29/c111417-features-in-vs-2015-rc/>)?

==&gt; Q: What macros (pragmas) can we imagine to use to detect Visual Studio build environment, its abilities and the target environment?

...

==&gt; Consider to use the SG10 (SD-6 document) proposal of __has_include macros?

1. #ifdef __has_include
2. # if __has_include(&lt;optional&gt;)
3. # include &lt;optional&gt;
4. # define have_optional 1
5. # elif __has_include(&lt;experimental/optional&gt;)
6. # include &lt;experimental/optional&gt;
7. # define have_optional 1
8. # define experimental_optional
9. # else
10. # define have_optional 0
11. # endif
12. #endif



9) Consider to have Poirot library use this compile-time investigation library?

…

10) Consider to have the Tris library use this compile-time identification library to tune its front-end and back-end?

...

11) Consider to experiment if it is possible to hide members defined by an #include in a user namespace?

==&gt; Consider to try out if it is possible to do something like:

> namespace my_secret_namespace {  
> #include &lt;some_header&gt;  
> }

==&gt; Note: First try including boost.filesystem did not compile (the included header seemed to be confused by not being in the global namespace to start with)?

...

…

Consider to delve into this idea of making a compile-time build tool-cgaon and target environment library as an open source C++ one?

…

&lt;appendix&gt;

==&gt; This seems to be the gcc pre-defined macros on Linux 16.04 MATE?

> kjell-olovhogdahl@ubuntu:~$ gcc -dM -E -x c /dev/null | sort  
> #define __amd64 1  
> #define __amd64__ 1  
> #define __ATOMIC_ACQ_REL 4  
> #define __ATOMIC_ACQUIRE 2  
> #define __ATOMIC_CONSUME 1  
> #define __ATOMIC_HLE_ACQUIRE 65536  
> #define __ATOMIC_HLE_RELEASE 131072  
> #define __ATOMIC_RELAXED 0  
> #define __ATOMIC_RELEASE 3  
> #define __ATOMIC_SEQ_CST 5  
> #define __BIGGEST_ALIGNMENT__ 16  
> #define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__  
> #define __CHAR16_TYPE__ short unsigned int  
> #define __CHAR32_TYPE__ unsigned int  
> #define __CHAR_BIT__ 8  
> #define __code_model_small__ 1  
> #define __DBL_DECIMAL_DIG__ 17  
> #define __DBL_DENORM_MIN__ ((double)4.94065645841246544177e-324L)  
> #define __DBL_DIG__ 15  
> #define __DBL_EPSILON__ ((double)2.22044604925031308085e-16L)  
> #define __DBL_HAS_DENORM__ 1  
> #define __DBL_HAS_INFINITY__ 1  
> #define __DBL_HAS_QUIET_NAN__ 1  
> #define __DBL_MANT_DIG__ 53  
> #define __DBL_MAX_10_EXP__ 308  
> #define __DBL_MAX__ ((double)1.79769313486231570815e+308L)  
> #define __DBL_MAX_EXP__ 1024  
> #define __DBL_MIN_10_EXP__ (-307)  
> #define __DBL_MIN__ ((double)2.22507385850720138309e-308L)  
> #define __DBL_MIN_EXP__ (-1021)  
> #define __DEC128_EPSILON__ 1E-33DL  
> #define __DEC128_MANT_DIG__ 34  
> #define __DEC128_MAX__ 9.999999999999999999999999999999999E6144DL  
> #define __DEC128_MAX_EXP__ 6145  
> #define __DEC128_MIN__ 1E-6143DL  
> #define __DEC128_MIN_EXP__ (-6142)  
> #define __DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000000000001E-6143DL  
> #define __DEC32_EPSILON__ 1E-6DF  
> #define __DEC32_MANT_DIG__ 7  
> #define __DEC32_MAX__ 9.999999E96DF  
> #define __DEC32_MAX_EXP__ 97  
> #define __DEC32_MIN__ 1E-95DF  
> #define __DEC32_MIN_EXP__ (-94)  
> #define __DEC32_SUBNORMAL_MIN__ 0.000001E-95DF  
> #define __DEC64_EPSILON__ 1E-15DD  
> #define __DEC64_MANT_DIG__ 16  
> #define __DEC64_MAX__ 9.999999999999999E384DD  
> #define __DEC64_MAX_EXP__ 385  
> #define __DEC64_MIN__ 1E-383DD  
> #define __DEC64_MIN_EXP__ (-382)  
> #define __DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD  
> #define __DEC_EVAL_METHOD__ 2  
> #define __DECIMAL_BID_FORMAT__ 1  
> #define __DECIMAL_DIG__ 21  
> #define __ELF__ 1  
> #define __FINITE_MATH_ONLY__ 0  
> #define __FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__  
> #define __FLT_DECIMAL_DIG__ 9  
> #define __FLT_DENORM_MIN__ 1.40129846432481707092e-45F  
> #define __FLT_DIG__ 6  
> #define __FLT_EPSILON__ 1.19209289550781250000e-7F  
> #define __FLT_EVAL_METHOD__ 0  
> #define __FLT_HAS_DENORM__ 1  
> #define __FLT_HAS_INFINITY__ 1  
> #define __FLT_HAS_QUIET_NAN__ 1  
> #define __FLT_MANT_DIG__ 24  
> #define __FLT_MAX_10_EXP__ 38  
> #define __FLT_MAX__ 3.40282346638528859812e+38F  
> #define __FLT_MAX_EXP__ 128  
> #define __FLT_MIN_10_EXP__ (-37)  
> #define __FLT_MIN__ 1.17549435082228750797e-38F  
> #define __FLT_MIN_EXP__ (-125)  
> #define __FLT_RADIX__ 2  
> #define __FXSR__ 1  
> #define __GCC_ATOMIC_BOOL_LOCK_FREE 2  
> #define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2  
> #define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2  
> #define __GCC_ATOMIC_CHAR_LOCK_FREE 2  
> #define __GCC_ATOMIC_INT_LOCK_FREE 2  
> #define __GCC_ATOMIC_LLONG_LOCK_FREE 2  
> #define __GCC_ATOMIC_LONG_LOCK_FREE 2  
> #define __GCC_ATOMIC_POINTER_LOCK_FREE 2  
> #define __GCC_ATOMIC_SHORT_LOCK_FREE 2  
> #define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1  
> #define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2  
> #define __GCC_HAVE_DWARF2_CFI_ASM 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1  
> #define __GCC_IEC_559 2  
> #define __GCC_IEC_559_COMPLEX 2  
> #define __GNUC__ 5  
> #define __GNUC_MINOR__ 3  
> #define __GNUC_PATCHLEVEL__ 1  
> #define __GNUC_STDC_INLINE__ 1  
> #define __gnu_linux__ 1  
> #define __GXX_ABI_VERSION 1009  
> #define __has_include_next(STR) __has_include_next__(STR)  
> #define __has_include(STR) __has_include__(STR)  
> #define __INT16_C(c) c  
> #define __INT16_MAX__ 0x7fff  
> #define __INT16_TYPE__ short int  
> #define __INT32_C(c) c  
> #define __INT32_MAX__ 0x7fffffff  
> #define __INT32_TYPE__ int  
> #define __INT64_C(c) c ## L  
> #define __INT64_MAX__ 0x7fffffffffffffffL  
> #define __INT64_TYPE__ long int  
> #define __INT8_C(c) c  
> #define __INT8_MAX__ 0x7f  
> #define __INT8_TYPE__ signed char  
> #define __INT_FAST16_MAX__ 0x7fffffffffffffffL  
> #define __INT_FAST16_TYPE__ long int  
> #define __INT_FAST32_MAX__ 0x7fffffffffffffffL  
> #define __INT_FAST32_TYPE__ long int  
> #define __INT_FAST64_MAX__ 0x7fffffffffffffffL  
> #define __INT_FAST64_TYPE__ long int  
> #define __INT_FAST8_MAX__ 0x7f  
> #define __INT_FAST8_TYPE__ signed char  
> #define __INT_LEAST16_MAX__ 0x7fff  
> #define __INT_LEAST16_TYPE__ short int  
> #define __INT_LEAST32_MAX__ 0x7fffffff  
> #define __INT_LEAST32_TYPE__ int  
> #define __INT_LEAST64_MAX__ 0x7fffffffffffffffL  
> #define __INT_LEAST64_TYPE__ long int  
> #define __INT_LEAST8_MAX__ 0x7f  
> #define __INT_LEAST8_TYPE__ signed char  
> #define __INT_MAX__ 0x7fffffff  
> #define __INTMAX_C(c) c ## L  
> #define __INTMAX_MAX__ 0x7fffffffffffffffL  
> #define __INTMAX_TYPE__ long int  
> #define __INTPTR_MAX__ 0x7fffffffffffffffL  
> #define __INTPTR_TYPE__ long int  
> #define __k8 1  
> #define __k8__ 1  
> #define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L  
> #define __LDBL_DIG__ 18  
> #define __LDBL_EPSILON__ 1.08420217248550443401e-19L  
> #define __LDBL_HAS_DENORM__ 1  
> #define __LDBL_HAS_INFINITY__ 1  
> #define __LDBL_HAS_QUIET_NAN__ 1  
> #define __LDBL_MANT_DIG__ 64  
> #define __LDBL_MAX_10_EXP__ 4932  
> #define __LDBL_MAX__ 1.18973149535723176502e+4932L  
> #define __LDBL_MAX_EXP__ 16384  
> #define __LDBL_MIN_10_EXP__ (-4931)  
> #define __LDBL_MIN__ 3.36210314311209350626e-4932L  
> #define __LDBL_MIN_EXP__ (-16381)  
> #define __linux 1  
> #define __linux__ 1  
> #define linux 1  
> #define __LONG_LONG_MAX__ 0x7fffffffffffffffLL  
> #define __LONG_MAX__ 0x7fffffffffffffffL  
> #define __LP64__ 1  
> #define _LP64 1  
> #define __MMX__ 1  
> #define __NO_INLINE__ 1  
> #define __ORDER_BIG_ENDIAN__ 4321  
> #define __ORDER_LITTLE_ENDIAN__ 1234  
> #define __ORDER_PDP_ENDIAN__ 3412  
> #define __PRAGMA_REDEFINE_EXTNAME 1  
> #define __PTRDIFF_MAX__ 0x7fffffffffffffffL  
> #define __PTRDIFF_TYPE__ long int  
> #define __REGISTER_PREFIX__  
> #define __SCHAR_MAX__ 0x7f  
> #define __SHRT_MAX__ 0x7fff  
> #define __SIG_ATOMIC_MAX__ 0x7fffffff  
> #define __SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)  
> #define __SIG_ATOMIC_TYPE__ int  
> #define __SIZE_MAX__ 0xffffffffffffffffUL  
> #define __SIZEOF_DOUBLE__ 8  
> #define __SIZEOF_FLOAT128__ 16  
> #define __SIZEOF_FLOAT__ 4  
> #define __SIZEOF_FLOAT80__ 16  
> #define __SIZEOF_INT128__ 16  
> #define __SIZEOF_INT__ 4  
> #define __SIZEOF_LONG__ 8  
> #define __SIZEOF_LONG_DOUBLE__ 16  
> #define __SIZEOF_LONG_LONG__ 8  
> #define __SIZEOF_POINTER__ 8  
> #define __SIZEOF_PTRDIFF_T__ 8  
> #define __SIZEOF_SHORT__ 2  
> #define __SIZEOF_SIZE_T__ 8  
> #define __SIZEOF_WCHAR_T__ 4  
> #define __SIZEOF_WINT_T__ 4  
> #define __SIZE_TYPE__ long unsigned int  
> #define __SSE__ 1  
> #define __SSE2__ 1  
> #define __SSE2_MATH__ 1  
> #define __SSE_MATH__ 1  
> #define __SSP_STRONG__ 3  
> #define __STDC__ 1  
> #define __STDC_HOSTED__ 1  
> #define __STDC_IEC_559__ 1  
> #define __STDC_IEC_559_COMPLEX__ 1  
> #define __STDC_ISO_10646__ 201505L  
> #define __STDC_NO_THREADS__ 1  
> #define _STDC_PREDEF_H 1  
> #define __STDC_UTF_16__ 1  
> #define __STDC_UTF_32__ 1  
> #define __STDC_VERSION__ 201112L  
> #define __UINT16_C(c) c  
> #define __UINT16_MAX__ 0xffff  
> #define __UINT16_TYPE__ short unsigned int  
> #define __UINT32_C(c) c ## U  
> #define __UINT32_MAX__ 0xffffffffU  
> #define __UINT32_TYPE__ unsigned int  
> #define __UINT64_C(c) c ## UL  
> #define __UINT64_MAX__ 0xffffffffffffffffUL  
> #define __UINT64_TYPE__ long unsigned int  
> #define __UINT8_C(c) c  
> #define __UINT8_MAX__ 0xff  
> #define __UINT8_TYPE__ unsigned char  
> #define __UINT_FAST16_MAX__ 0xffffffffffffffffUL  
> #define __UINT_FAST16_TYPE__ long unsigned int  
> #define __UINT_FAST32_MAX__ 0xffffffffffffffffUL  
> #define __UINT_FAST32_TYPE__ long unsigned int  
> #define __UINT_FAST64_MAX__ 0xffffffffffffffffUL  
> #define __UINT_FAST64_TYPE__ long unsigned int  
> #define __UINT_FAST8_MAX__ 0xff  
> #define __UINT_FAST8_TYPE__ unsigned char  
> #define __UINT_LEAST16_MAX__ 0xffff  
> #define __UINT_LEAST16_TYPE__ short unsigned int  
> #define __UINT_LEAST32_MAX__ 0xffffffffU  
> #define __UINT_LEAST32_TYPE__ unsigned int  
> #define __UINT_LEAST64_MAX__ 0xffffffffffffffffUL  
> #define __UINT_LEAST64_TYPE__ long unsigned int  
> #define __UINT_LEAST8_MAX__ 0xff  
> #define __UINT_LEAST8_TYPE__ unsigned char  
> #define __UINTMAX_C(c) c ## UL  
> #define __UINTMAX_MAX__ 0xffffffffffffffffUL  
> #define __UINTMAX_TYPE__ long unsigned int  
> #define __UINTPTR_MAX__ 0xffffffffffffffffUL  
> #define __UINTPTR_TYPE__ long unsigned int  
> #define __unix 1  
> #define __unix__ 1  
> #define unix 1  
> #define __USER_LABEL_PREFIX__  
> #define __VERSION__ "5.3.1 20160413"  
> #define __WCHAR_MAX__ 0x7fffffff  
> #define __WCHAR_MIN__ (-__WCHAR_MAX__ - 1)  
> #define __WCHAR_TYPE__ int  
> #define __WINT_MAX__ 0xffffffffU  
> #define __WINT_MIN__ 0U  
> #define __WINT_TYPE__ unsigned int  
> #define __x86_64 1  
> #define __x86_64__ 1  
> kjell-olovhogdahl@ubuntu:~$

==&gt; This seems to be the clang pre-defined macros on Linux 16.04 MATE?

> kjell-olovhogdahl@ubuntu:~$ clang -dM -E -x c /dev/null  
> #define _LP64 1  
> #define __ATOMIC_ACQUIRE 2  
> #define __ATOMIC_ACQ_REL 4  
> #define __ATOMIC_CONSUME 1  
> #define __ATOMIC_RELAXED 0  
> #define __ATOMIC_RELEASE 3  
> #define __ATOMIC_SEQ_CST 5  
> #define __BIGGEST_ALIGNMENT__ 16  
> #define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__  
> #define __CHAR16_TYPE__ unsigned short  
> #define __CHAR32_TYPE__ unsigned int  
> #define __CHAR_BIT__ 8  
> #define __CONSTANT_CFSTRINGS__ 1  
> #define __DBL_DECIMAL_DIG__ 17  
> #define __DBL_DENORM_MIN__ 4.9406564584124654e-324  
> #define __DBL_DIG__ 15  
> #define __DBL_EPSILON__ 2.2204460492503131e-16  
> #define __DBL_HAS_DENORM__ 1  
> #define __DBL_HAS_INFINITY__ 1  
> #define __DBL_HAS_QUIET_NAN__ 1  
> #define __DBL_MANT_DIG__ 53  
> #define __DBL_MAX_10_EXP__ 308  
> #define __DBL_MAX_EXP__ 1024  
> #define __DBL_MAX__ 1.7976931348623157e+308  
> #define __DBL_MIN_10_EXP__ (-307)  
> #define __DBL_MIN_EXP__ (-1021)  
> #define __DBL_MIN__ 2.2250738585072014e-308  
> #define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__  
> #define __ELF__ 1  
> #define __FINITE_MATH_ONLY__ 0  
> #define __FLT_DECIMAL_DIG__ 9  
> #define __FLT_DENORM_MIN__ 1.40129846e-45F  
> #define __FLT_DIG__ 6  
> #define __FLT_EPSILON__ 1.19209290e-7F  
> #define __FLT_EVAL_METHOD__ 0  
> #define __FLT_HAS_DENORM__ 1  
> #define __FLT_HAS_INFINITY__ 1  
> #define __FLT_HAS_QUIET_NAN__ 1  
> #define __FLT_MANT_DIG__ 24  
> #define __FLT_MAX_10_EXP__ 38  
> #define __FLT_MAX_EXP__ 128  
> #define __FLT_MAX__ 3.40282347e+38F  
> #define __FLT_MIN_10_EXP__ (-37)  
> #define __FLT_MIN_EXP__ (-125)  
> #define __FLT_MIN__ 1.17549435e-38F  
> #define __FLT_RADIX__ 2  
> #define __FXSR__ 1  
> #define __GCC_ATOMIC_BOOL_LOCK_FREE 2  
> #define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2  
> #define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2  
> #define __GCC_ATOMIC_CHAR_LOCK_FREE 2  
> #define __GCC_ATOMIC_INT_LOCK_FREE 2  
> #define __GCC_ATOMIC_LLONG_LOCK_FREE 2  
> #define __GCC_ATOMIC_LONG_LOCK_FREE 2  
> #define __GCC_ATOMIC_POINTER_LOCK_FREE 2  
> #define __GCC_ATOMIC_SHORT_LOCK_FREE 2  
> #define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1  
> #define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1  
> #define __GNUC_MINOR__ 2  
> #define __GNUC_PATCHLEVEL__ 1  
> #define __GNUC_STDC_INLINE__ 1  
> #define __GNUC__ 4  
> #define __GXX_ABI_VERSION 1002  
> #define __GXX_RTTI 1  
> #define __INT16_C_SUFFIX__  
> #define __INT16_FMTd__ "hd"  
> #define __INT16_FMTi__ "hi"  
> #define __INT16_MAX__ 32767  
> #define __INT16_TYPE__ short  
> #define __INT32_C_SUFFIX__  
> #define __INT32_FMTd__ "d"  
> #define __INT32_FMTi__ "i"  
> #define __INT32_MAX__ 2147483647  
> #define __INT32_TYPE__ int  
> #define __INT64_C_SUFFIX__ L  
> #define __INT64_FMTd__ "ld"  
> #define __INT64_FMTi__ "li"  
> #define __INT64_MAX__ 9223372036854775807L  
> #define __INT64_TYPE__ long int  
> #define __INT8_C_SUFFIX__  
> #define __INT8_FMTd__ "hhd"  
> #define __INT8_FMTi__ "hhi"  
> #define __INT8_MAX__ 127  
> #define __INT8_TYPE__ signed char  
> #define __INTMAX_C_SUFFIX__ L  
> #define __INTMAX_FMTd__ "ld"  
> #define __INTMAX_FMTi__ "li"  
> #define __INTMAX_MAX__ 9223372036854775807L  
> #define __INTMAX_TYPE__ long int  
> #define __INTMAX_WIDTH__ 64  
> #define __INTPTR_FMTd__ "ld"  
> #define __INTPTR_FMTi__ "li"  
> #define __INTPTR_MAX__ 9223372036854775807L  
> #define __INTPTR_TYPE__ long int  
> #define __INTPTR_WIDTH__ 64  
> #define __INT_FAST16_FMTd__ "hd"  
> #define __INT_FAST16_FMTi__ "hi"  
> #define __INT_FAST16_MAX__ 32767  
> #define __INT_FAST16_TYPE__ short  
> #define __INT_FAST32_FMTd__ "d"  
> #define __INT_FAST32_FMTi__ "i"  
> #define __INT_FAST32_MAX__ 2147483647  
> #define __INT_FAST32_TYPE__ int  
> #define __INT_FAST64_FMTd__ "ld"  
> #define __INT_FAST64_FMTi__ "li"  
> #define __INT_FAST64_MAX__ 9223372036854775807L  
> #define __INT_FAST64_TYPE__ long int  
> #define __INT_FAST8_FMTd__ "hhd"  
> #define __INT_FAST8_FMTi__ "hhi"  
> #define __INT_FAST8_MAX__ 127  
> #define __INT_FAST8_TYPE__ signed char  
> #define __INT_LEAST16_FMTd__ "hd"  
> #define __INT_LEAST16_FMTi__ "hi"  
> #define __INT_LEAST16_MAX__ 32767  
> #define __INT_LEAST16_TYPE__ short  
> #define __INT_LEAST32_FMTd__ "d"  
> #define __INT_LEAST32_FMTi__ "i"  
> #define __INT_LEAST32_MAX__ 2147483647  
> #define __INT_LEAST32_TYPE__ int  
> #define __INT_LEAST64_FMTd__ "ld"  
> #define __INT_LEAST64_FMTi__ "li"  
> #define __INT_LEAST64_MAX__ 9223372036854775807L  
> #define __INT_LEAST64_TYPE__ long int  
> #define __INT_LEAST8_FMTd__ "hhd"  
> #define __INT_LEAST8_FMTi__ "hhi"  
> #define __INT_LEAST8_MAX__ 127  
> #define __INT_LEAST8_TYPE__ signed char  
> #define __INT_MAX__ 2147483647  
> #define __LDBL_DECIMAL_DIG__ 21  
> #define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L  
> #define __LDBL_DIG__ 18  
> #define __LDBL_EPSILON__ 1.08420217248550443401e-19L  
> #define __LDBL_HAS_DENORM__ 1  
> #define __LDBL_HAS_INFINITY__ 1  
> #define __LDBL_HAS_QUIET_NAN__ 1  
> #define __LDBL_MANT_DIG__ 64  
> #define __LDBL_MAX_10_EXP__ 4932  
> #define __LDBL_MAX_EXP__ 16384  
> #define __LDBL_MAX__ 1.18973149535723176502e+4932L  
> #define __LDBL_MIN_10_EXP__ (-4931)  
> #define __LDBL_MIN_EXP__ (-16381)  
> #define __LDBL_MIN__ 3.36210314311209350626e-4932L  
> #define __LITTLE_ENDIAN__ 1  
> #define __LONG_LONG_MAX__ 9223372036854775807LL  
> #define __LONG_MAX__ 9223372036854775807L  
> #define __LP64__ 1  
> #define __MMX__ 1  
> #define __NO_INLINE__ 1  
> #define __NO_MATH_INLINES 1  
> #define __ORDER_BIG_ENDIAN__ 4321  
> #define __ORDER_LITTLE_ENDIAN__ 1234  
> #define __ORDER_PDP_ENDIAN__ 3412  
> #define __POINTER_WIDTH__ 64  
> #define __PRAGMA_REDEFINE_EXTNAME 1  
> #define __PTRDIFF_FMTd__ "ld"  
> #define __PTRDIFF_FMTi__ "li"  
> #define __PTRDIFF_MAX__ 9223372036854775807L  
> #define __PTRDIFF_TYPE__ long int  
> #define __PTRDIFF_WIDTH__ 64  
> #define __REGISTER_PREFIX__  
> #define __SCHAR_MAX__ 127  
> #define __SHRT_MAX__ 32767  
> #define __SIG_ATOMIC_MAX__ 2147483647  
> #define __SIG_ATOMIC_WIDTH__ 32  
> #define __SIZEOF_DOUBLE__ 8  
> #define __SIZEOF_FLOAT__ 4  
> #define __SIZEOF_INT128__ 16  
> #define __SIZEOF_INT__ 4  
> #define __SIZEOF_LONG_DOUBLE__ 16  
> #define __SIZEOF_LONG_LONG__ 8  
> #define __SIZEOF_LONG__ 8  
> #define __SIZEOF_POINTER__ 8  
> #define __SIZEOF_PTRDIFF_T__ 8  
> #define __SIZEOF_SHORT__ 2  
> #define __SIZEOF_SIZE_T__ 8  
> #define __SIZEOF_WCHAR_T__ 4  
> #define __SIZEOF_WINT_T__ 4  
> #define __SIZE_FMTX__ "lX"  
> #define __SIZE_FMTo__ "lo"  
> #define __SIZE_FMTu__ "lu"  
> #define __SIZE_FMTx__ "lx"  
> #define __SIZE_MAX__ 18446744073709551615UL  
> #define __SIZE_TYPE__ long unsigned int  
> #define __SIZE_WIDTH__ 64  
> #define __SSE2_MATH__ 1  
> #define __SSE2__ 1  
> #define __SSE_MATH__ 1  
> #define __SSE__ 1  
> #define __STDC_HOSTED__ 1  
> #define __STDC_UTF_16__ 1  
> #define __STDC_UTF_32__ 1  
> #define __STDC_VERSION__ 201112L  
> #define __STDC__ 1  
> #define __UINT16_C_SUFFIX__  
> #define __UINT16_FMTX__ "hX"  
> #define __UINT16_FMTo__ "ho"  
> #define __UINT16_FMTu__ "hu"  
> #define __UINT16_FMTx__ "hx"  
> #define __UINT16_MAX__ 65535  
> #define __UINT16_TYPE__ unsigned short  
> #define __UINT32_C_SUFFIX__ U  
> #define __UINT32_FMTX__ "X"  
> #define __UINT32_FMTo__ "o"  
> #define __UINT32_FMTu__ "u"  
> #define __UINT32_FMTx__ "x"  
> #define __UINT32_MAX__ 4294967295U  
> #define __UINT32_TYPE__ unsigned int  
> #define __UINT64_C_SUFFIX__ UL  
> #define __UINT64_FMTX__ "lX"  
> #define __UINT64_FMTo__ "lo"  
> #define __UINT64_FMTu__ "lu"  
> #define __UINT64_FMTx__ "lx"  
> #define __UINT64_MAX__ 18446744073709551615UL  
> #define __UINT64_TYPE__ long unsigned int  
> #define __UINT8_C_SUFFIX__  
> #define __UINT8_FMTX__ "hhX"  
> #define __UINT8_FMTo__ "hho"  
> #define __UINT8_FMTu__ "hhu"  
> #define __UINT8_FMTx__ "hhx"  
> #define __UINT8_MAX__ 255  
> #define __UINT8_TYPE__ unsigned char  
> #define __UINTMAX_C_SUFFIX__ UL  
> #define __UINTMAX_FMTX__ "lX"  
> #define __UINTMAX_FMTo__ "lo"  
> #define __UINTMAX_FMTu__ "lu"  
> #define __UINTMAX_FMTx__ "lx"  
> #define __UINTMAX_MAX__ 18446744073709551615UL  
> #define __UINTMAX_TYPE__ long unsigned int  
> #define __UINTMAX_WIDTH__ 64  
> #define __UINTPTR_FMTX__ "lX"  
> #define __UINTPTR_FMTo__ "lo"  
> #define __UINTPTR_FMTu__ "lu"  
> #define __UINTPTR_FMTx__ "lx"  
> #define __UINTPTR_MAX__ 18446744073709551615UL  
> #define __UINTPTR_TYPE__ long unsigned int  
> #define __UINTPTR_WIDTH__ 64  
> #define __UINT_FAST16_FMTX__ "hX"  
> #define __UINT_FAST16_FMTo__ "ho"  
> #define __UINT_FAST16_FMTu__ "hu"  
> #define __UINT_FAST16_FMTx__ "hx"  
> #define __UINT_FAST16_MAX__ 65535  
> #define __UINT_FAST16_TYPE__ unsigned short  
> #define __UINT_FAST32_FMTX__ "X"  
> #define __UINT_FAST32_FMTo__ "o"  
> #define __UINT_FAST32_FMTu__ "u"  
> #define __UINT_FAST32_FMTx__ "x"  
> #define __UINT_FAST32_MAX__ 4294967295U  
> #define __UINT_FAST32_TYPE__ unsigned int  
> #define __UINT_FAST64_FMTX__ "lX"  
> #define __UINT_FAST64_FMTo__ "lo"  
> #define __UINT_FAST64_FMTu__ "lu"  
> #define __UINT_FAST64_FMTx__ "lx"  
> #define __UINT_FAST64_MAX__ 18446744073709551615UL  
> #define __UINT_FAST64_TYPE__ long unsigned int  
> #define __UINT_FAST8_FMTX__ "hhX"  
> #define __UINT_FAST8_FMTo__ "hho"  
> #define __UINT_FAST8_FMTu__ "hhu"  
> #define __UINT_FAST8_FMTx__ "hhx"  
> #define __UINT_FAST8_MAX__ 255  
> #define __UINT_FAST8_TYPE__ unsigned char  
> #define __UINT_LEAST16_FMTX__ "hX"  
> #define __UINT_LEAST16_FMTo__ "ho"  
> #define __UINT_LEAST16_FMTu__ "hu"  
> #define __UINT_LEAST16_FMTx__ "hx"  
> #define __UINT_LEAST16_MAX__ 65535  
> #define __UINT_LEAST16_TYPE__ unsigned short  
> #define __UINT_LEAST32_FMTX__ "X"  
> #define __UINT_LEAST32_FMTo__ "o"  
> #define __UINT_LEAST32_FMTu__ "u"  
> #define __UINT_LEAST32_FMTx__ "x"  
> #define __UINT_LEAST32_MAX__ 4294967295U  
> #define __UINT_LEAST32_TYPE__ unsigned int  
> #define __UINT_LEAST64_FMTX__ "lX"  
> #define __UINT_LEAST64_FMTo__ "lo"  
> #define __UINT_LEAST64_FMTu__ "lu"  
> #define __UINT_LEAST64_FMTx__ "lx"  
> #define __UINT_LEAST64_MAX__ 18446744073709551615UL  
> #define __UINT_LEAST64_TYPE__ long unsigned int  
> #define __UINT_LEAST8_FMTX__ "hhX"  
> #define __UINT_LEAST8_FMTo__ "hho"  
> #define __UINT_LEAST8_FMTu__ "hhu"  
> #define __UINT_LEAST8_FMTx__ "hhx"  
> #define __UINT_LEAST8_MAX__ 255  
> #define __UINT_LEAST8_TYPE__ unsigned char  
> #define __USER_LABEL_PREFIX__  
> #define __VERSION__ "4.2.1 Compatible Clang 3.8.0 (tags/RELEASE_380/final)"  
> #define __WCHAR_MAX__ 2147483647  
> #define __WCHAR_TYPE__ int  
> #define __WCHAR_WIDTH__ 32  
> #define __WINT_TYPE__ unsigned int  
> #define __WINT_UNSIGNED__ 1  
> #define __WINT_WIDTH__ 32  
> #define __amd64 1  
> #define __amd64__ 1  
> #define __clang__ 1  
> #define __clang_major__ 3  
> #define __clang_minor__ 8  
> #define __clang_patchlevel__ 0  
> #define __clang_version__ "3.8.0 (tags/RELEASE_380/final)"  
> #define __gnu_linux__ 1  
> #define __k8 1  
> #define __k8__ 1  
> #define __linux 1  
> #define __linux__ 1  
> #define __llvm__ 1  
> #define __tune_k8__ 1  
> #define __unix 1  
> #define __unix__ 1  
> #define __x86_64 1  
> #define __x86_64__ 1  
> #define linux 1  
> #define unix 1  
> kjell-olovhogdahl@ubuntu:~$

==&gt; This seem to be the gcc pre-defined macros on Windows 10 MinGW?

> kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 ~  
> $ gcc -dM -E -x c /dev/null | sort  
> #define __amd64 1  
> #define __amd64__ 1  
> #define __ATOMIC_ACQ_REL 4  
> #define __ATOMIC_ACQUIRE 2  
> #define __ATOMIC_CONSUME 1  
> #define __ATOMIC_HLE_ACQUIRE 65536  
> #define __ATOMIC_HLE_RELEASE 131072  
> #define __ATOMIC_RELAXED 0  
> #define __ATOMIC_RELEASE 3  
> #define __ATOMIC_SEQ_CST 5  
> #define __BIGGEST_ALIGNMENT__ 16  
> #define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__  
> #define __cdecl __attribute__((__cdecl__))  
> #define __CHAR_BIT__ 8  
> #define __CHAR16_TYPE__ short unsigned int  
> #define __CHAR32_TYPE__ unsigned int  
> #define __code_model_medium__ 1  
> #define __DBL_DECIMAL_DIG__ 17  
> #define __DBL_DENORM_MIN__ ((double)4.94065645841246544177e-324L)  
> #define __DBL_DIG__ 15  
> #define __DBL_EPSILON__ ((double)2.22044604925031308085e-16L)  
> #define __DBL_HAS_DENORM__ 1  
> #define __DBL_HAS_INFINITY__ 1  
> #define __DBL_HAS_QUIET_NAN__ 1  
> #define __DBL_MANT_DIG__ 53  
> #define __DBL_MAX__ ((double)1.79769313486231570815e+308L)  
> #define __DBL_MAX_10_EXP__ 308  
> #define __DBL_MAX_EXP__ 1024  
> #define __DBL_MIN__ ((double)2.22507385850720138309e-308L)  
> #define __DBL_MIN_10_EXP__ (-307)  
> #define __DBL_MIN_EXP__ (-1021)  
> #define __DEC_EVAL_METHOD__ 2  
> #define __DEC128_EPSILON__ 1E-33DL  
> #define __DEC128_MANT_DIG__ 34  
> #define __DEC128_MAX__ 9.999999999999999999999999999999999E6144DL  
> #define __DEC128_MAX_EXP__ 6145  
> #define __DEC128_MIN__ 1E-6143DL  
> #define __DEC128_MIN_EXP__ (-6142)  
> #define __DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000000000001E-6143DL  
> #define __DEC32_EPSILON__ 1E-6DF  
> #define __DEC32_MANT_DIG__ 7  
> #define __DEC32_MAX__ 9.999999E96DF  
> #define __DEC32_MAX_EXP__ 97  
> #define __DEC32_MIN__ 1E-95DF  
> #define __DEC32_MIN_EXP__ (-94)  
> #define __DEC32_SUBNORMAL_MIN__ 0.000001E-95DF  
> #define __DEC64_EPSILON__ 1E-15DD  
> #define __DEC64_MANT_DIG__ 16  
> #define __DEC64_MAX__ 9.999999999999999E384DD  
> #define __DEC64_MAX_EXP__ 385  
> #define __DEC64_MIN__ 1E-383DD  
> #define __DEC64_MIN_EXP__ (-382)  
> #define __DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD  
> #define __DECIMAL_BID_FORMAT__ 1  
> #define __DECIMAL_DIG__ 21  
> #define __declspec(x) __attribute__((x))  
> #define __fastcall __attribute__((__fastcall__))  
> #define __FINITE_MATH_ONLY__ 0  
> #define __FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__  
> #define __FLT_DECIMAL_DIG__ 9  
> #define __FLT_DENORM_MIN__ 1.40129846432481707092e-45F  
> #define __FLT_DIG__ 6  
> #define __FLT_EPSILON__ 1.19209289550781250000e-7F  
> #define __FLT_EVAL_METHOD__ 0  
> #define __FLT_HAS_DENORM__ 1  
> #define __FLT_HAS_INFINITY__ 1  
> #define __FLT_HAS_QUIET_NAN__ 1  
> #define __FLT_MANT_DIG__ 24  
> #define __FLT_MAX__ 3.40282346638528859812e+38F  
> #define __FLT_MAX_10_EXP__ 38  
> #define __FLT_MAX_EXP__ 128  
> #define __FLT_MIN__ 1.17549435082228750797e-38F  
> #define __FLT_MIN_10_EXP__ (-37)  
> #define __FLT_MIN_EXP__ (-125)  
> #define __FLT_RADIX__ 2  
> #define __FXSR__ 1  
> #define __GCC_ATOMIC_BOOL_LOCK_FREE 2  
> #define __GCC_ATOMIC_CHAR_LOCK_FREE 2  
> #define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2  
> #define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2  
> #define __GCC_ATOMIC_INT_LOCK_FREE 2  
> #define __GCC_ATOMIC_LLONG_LOCK_FREE 2  
> #define __GCC_ATOMIC_LONG_LOCK_FREE 2  
> #define __GCC_ATOMIC_POINTER_LOCK_FREE 2  
> #define __GCC_ATOMIC_SHORT_LOCK_FREE 2  
> #define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1  
> #define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1  
> #define __GCC_IEC_559 2  
> #define __GCC_IEC_559_COMPLEX 2  
> #define __GNUC__ 5  
> #define __GNUC_MINOR__ 4  
> #define __GNUC_PATCHLEVEL__ 0  
> #define __GNUC_STDC_INLINE__ 1  
> #define __GXX_ABI_VERSION 1009  
> #define __GXX_MERGED_TYPEINFO_NAMES 0  
> #define __GXX_TYPEINFO_EQUALITY_INLINE 0  
> #define __has_include(STR) __has_include__(STR)  
> #define __has_include_next(STR) __has_include_next__(STR)  
> #define __INT_FAST16_MAX__ 0x7fff  
> #define __INT_FAST16_TYPE__ short int  
> #define __INT_FAST32_MAX__ 0x7fffffff  
> #define __INT_FAST32_TYPE__ int  
> #define __INT_FAST64_MAX__ 0x7fffffffffffffffLL  
> #define __INT_FAST64_TYPE__ long long int  
> #define __INT_FAST8_MAX__ 0x7f  
> #define __INT_FAST8_TYPE__ signed char  
> #define __INT_LEAST16_MAX__ 0x7fff  
> #define __INT_LEAST16_TYPE__ short int  
> #define __INT_LEAST32_MAX__ 0x7fffffff  
> #define __INT_LEAST32_TYPE__ int  
> #define __INT_LEAST64_MAX__ 0x7fffffffffffffffLL  
> #define __INT_LEAST64_TYPE__ long long int  
> #define __INT_LEAST8_MAX__ 0x7f  
> #define __INT_LEAST8_TYPE__ signed char  
> #define __INT_MAX__ 0x7fffffff  
> #define __INT16_C(c) c  
> #define __INT16_MAX__ 0x7fff  
> #define __INT16_TYPE__ short int  
> #define __INT32_C(c) c  
> #define __INT32_MAX__ 0x7fffffff  
> #define __INT32_TYPE__ int  
> #define __INT64_C(c) c ## LL  
> #define __INT64_MAX__ 0x7fffffffffffffffLL  
> #define __INT64_TYPE__ long long int  
> #define __INT8_C(c) c  
> #define __INT8_MAX__ 0x7f  
> #define __INT8_TYPE__ signed char  
> #define __INTMAX_C(c) c ## LL  
> #define __INTMAX_MAX__ 0x7fffffffffffffffLL  
> #define __INTMAX_TYPE__ long long int  
> #define __INTPTR_MAX__ 0x7fffffffffffffffLL  
> #define __INTPTR_TYPE__ long long int  
> #define __k8 1  
> #define __k8__ 1  
> #define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L  
> #define __LDBL_DIG__ 18  
> #define __LDBL_EPSILON__ 1.08420217248550443401e-19L  
> #define __LDBL_HAS_DENORM__ 1  
> #define __LDBL_HAS_INFINITY__ 1  
> #define __LDBL_HAS_QUIET_NAN__ 1  
> #define __LDBL_MANT_DIG__ 64  
> #define __LDBL_MAX__ 1.18973149535723176502e+4932L  
> #define __LDBL_MAX_10_EXP__ 4932  
> #define __LDBL_MAX_EXP__ 16384  
> #define __LDBL_MIN__ 3.36210314311209350626e-4932L  
> #define __LDBL_MIN_10_EXP__ (-4931)  
> #define __LDBL_MIN_EXP__ (-16381)  
> #define __LONG_LONG_MAX__ 0x7fffffffffffffffLL  
> #define __LONG_MAX__ 0x7fffffffL  
> #define __MINGW32__ 1  
> #define __MINGW64__ 1  
> #define __MMX__ 1  
> #define __MSVCRT__ 1  
> #define __NO_INLINE__ 1  
> #define __ORDER_BIG_ENDIAN__ 4321  
> #define __ORDER_LITTLE_ENDIAN__ 1234  
> #define __ORDER_PDP_ENDIAN__ 3412  
> #define __pic__ 1  
> #define __PIC__ 1  
> #define __PRAGMA_REDEFINE_EXTNAME 1  
> #define __PTRDIFF_MAX__ 0x7fffffffffffffffLL  
> #define __PTRDIFF_TYPE__ long long int  
> #define __REGISTER_PREFIX__  
> #define __SCHAR_MAX__ 0x7f  
> #define __SEH__ 1  
> #define __SHRT_MAX__ 0x7fff  
> #define __SIG_ATOMIC_MAX__ 0x7fffffff  
> #define __SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)  
> #define __SIG_ATOMIC_TYPE__ int  
> #define __SIZE_MAX__ 0xffffffffffffffffULL  
> #define __SIZE_TYPE__ long long unsigned int  
> #define __SIZEOF_DOUBLE__ 8  
> #define __SIZEOF_FLOAT__ 4  
> #define __SIZEOF_FLOAT128__ 16  
> #define __SIZEOF_FLOAT80__ 16  
> #define __SIZEOF_INT__ 4  
> #define __SIZEOF_INT128__ 16  
> #define __SIZEOF_LONG__ 4  
> #define __SIZEOF_LONG_DOUBLE__ 16  
> #define __SIZEOF_LONG_LONG__ 8  
> #define __SIZEOF_POINTER__ 8  
> #define __SIZEOF_PTRDIFF_T__ 8  
> #define __SIZEOF_SHORT__ 2  
> #define __SIZEOF_SIZE_T__ 8  
> #define __SIZEOF_WCHAR_T__ 2  
> #define __SIZEOF_WINT_T__ 2  
> #define __SSE__ 1  
> #define __SSE_MATH__ 1  
> #define __SSE2__ 1  
> #define __SSE2_MATH__ 1  
> #define __STDC__ 1  
> #define __STDC_HOSTED__ 1  
> #define __STDC_UTF_16__ 1  
> #define __STDC_UTF_32__ 1  
> #define __STDC_VERSION__ 201112L  
> #define __stdcall __attribute__((__stdcall__))  
> #define __thiscall __attribute__((__thiscall__))  
> #define __UINT_FAST16_MAX__ 0xffff  
> #define __UINT_FAST16_TYPE__ short unsigned int  
> #define __UINT_FAST32_MAX__ 0xffffffffU  
> #define __UINT_FAST32_TYPE__ unsigned int  
> #define __UINT_FAST64_MAX__ 0xffffffffffffffffULL  
> #define __UINT_FAST64_TYPE__ long long unsigned int  
> #define __UINT_FAST8_MAX__ 0xff  
> #define __UINT_FAST8_TYPE__ unsigned char  
> #define __UINT_LEAST16_MAX__ 0xffff  
> #define __UINT_LEAST16_TYPE__ short unsigned int  
> #define __UINT_LEAST32_MAX__ 0xffffffffU  
> #define __UINT_LEAST32_TYPE__ unsigned int  
> #define __UINT_LEAST64_MAX__ 0xffffffffffffffffULL  
> #define __UINT_LEAST64_TYPE__ long long unsigned int  
> #define __UINT_LEAST8_MAX__ 0xff  
> #define __UINT_LEAST8_TYPE__ unsigned char  
> #define __UINT16_C(c) c  
> #define __UINT16_MAX__ 0xffff  
> #define __UINT16_TYPE__ short unsigned int  
> #define __UINT32_C(c) c ## U  
> #define __UINT32_MAX__ 0xffffffffU  
> #define __UINT32_TYPE__ unsigned int  
> #define __UINT64_C(c) c ## ULL  
> #define __UINT64_MAX__ 0xffffffffffffffffULL  
> #define __UINT64_TYPE__ long long unsigned int  
> #define __UINT8_C(c) c  
> #define __UINT8_MAX__ 0xff  
> #define __UINT8_TYPE__ unsigned char  
> #define __UINTMAX_C(c) c ## ULL  
> #define __UINTMAX_MAX__ 0xffffffffffffffffULL  
> #define __UINTMAX_TYPE__ long long unsigned int  
> #define __UINTPTR_MAX__ 0xffffffffffffffffULL  
> #define __UINTPTR_TYPE__ long long unsigned int  
> #define __USER_LABEL_PREFIX__  
> #define __VERSION__ "5.4.0"  
> #define __WCHAR_MAX__ 0xffff  
> #define __WCHAR_MIN__ 0  
> #define __WCHAR_TYPE__ short unsigned int  
> #define __WIN32 1  
> #define __WIN32__ 1  
> #define __WIN64 1  
> #define __WIN64__ 1  
> #define __WINNT 1  
> #define __WINNT__ 1  
> #define __WINT_MAX__ 0xffff  
> #define __WINT_MIN__ 0  
> #define __WINT_TYPE__ short unsigned int  
> #define __x86_64 1  
> #define __x86_64__ 1  
> #define _cdecl __attribute__((__cdecl__))  
> #define _fastcall __attribute__((__fastcall__))  
> #define _INTEGRAL_MAX_BITS 64  
> #define _REENTRANT 1  
> #define _stdcall __attribute__((__stdcall__))  
> #define _thiscall __attribute__((__thiscall__))  
> #define _WIN32 1  
> #define _WIN64 1  
> #define WIN32 1  
> #define WIN64 1  
> #define WINNT 1

> kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 ~  
> $

==&gt; This seems to be the clang pre-defined macros on Windows 10 MinGW?

> kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 ~  
> $ clang -dM -E -x c /dev/null  
> #define WIN64 1  
> #define _WIN32 1  
> #define _WIN64 1  
> #define __ATOMIC_ACQUIRE 2  
> #define __ATOMIC_ACQ_REL 4  
> #define __ATOMIC_CONSUME 1  
> #define __ATOMIC_RELAXED 0  
> #define __ATOMIC_RELEASE 3  
> #define __ATOMIC_SEQ_CST 5  
> #define __BIGGEST_ALIGNMENT__ 16  
> #define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__  
> #define __CHAR16_TYPE__ unsigned short  
> #define __CHAR32_TYPE__ unsigned int  
> #define __CHAR_BIT__ 8  
> #define __CONSTANT_CFSTRINGS__ 1  
> #define __DBL_DECIMAL_DIG__ 17  
> #define __DBL_DENORM_MIN__ 4.9406564584124654e-324  
> #define __DBL_DIG__ 15  
> #define __DBL_EPSILON__ 2.2204460492503131e-16  
> #define __DBL_HAS_DENORM__ 1  
> #define __DBL_HAS_INFINITY__ 1  
> #define __DBL_HAS_QUIET_NAN__ 1  
> #define __DBL_MANT_DIG__ 53  
> #define __DBL_MAX_10_EXP__ 308  
> #define __DBL_MAX_EXP__ 1024  
> #define __DBL_MAX__ 1.7976931348623157e+308  
> #define __DBL_MIN_10_EXP__ (-307)  
> #define __DBL_MIN_EXP__ (-1021)  
> #define __DBL_MIN__ 2.2250738585072014e-308  
> #define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__  
> #define __FINITE_MATH_ONLY__ 0  
> #define __FLT_DECIMAL_DIG__ 9  
> #define __FLT_DENORM_MIN__ 1.40129846e-45F  
> #define __FLT_DIG__ 6  
> #define __FLT_EPSILON__ 1.19209290e-7F  
> #define __FLT_EVAL_METHOD__ 0  
> #define __FLT_HAS_DENORM__ 1  
> #define __FLT_HAS_INFINITY__ 1  
> #define __FLT_HAS_QUIET_NAN__ 1  
> #define __FLT_MANT_DIG__ 24  
> #define __FLT_MAX_10_EXP__ 38  
> #define __FLT_MAX_EXP__ 128  
> #define __FLT_MAX__ 3.40282347e+38F  
> #define __FLT_MIN_10_EXP__ (-37)  
> #define __FLT_MIN_EXP__ (-125)  
> #define __FLT_MIN__ 1.17549435e-38F  
> #define __FLT_RADIX__ 2  
> #define __FXSR__ 1  
> #define __GCC_ATOMIC_BOOL_LOCK_FREE 2  
> #define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2  
> #define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2  
> #define __GCC_ATOMIC_CHAR_LOCK_FREE 2  
> #define __GCC_ATOMIC_INT_LOCK_FREE 2  
> #define __GCC_ATOMIC_LLONG_LOCK_FREE 2  
> #define __GCC_ATOMIC_LONG_LOCK_FREE 2  
> #define __GCC_ATOMIC_POINTER_LOCK_FREE 2  
> #define __GCC_ATOMIC_SHORT_LOCK_FREE 2  
> #define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1  
> #define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1  
> #define __GNUC_MINOR__ 2  
> #define __GNUC_PATCHLEVEL__ 1  
> #define __GNUC_STDC_INLINE__ 1  
> #define __GNUC__ 4  
> #define __GXX_ABI_VERSION 1002  
> #define __GXX_RTTI 1  
> #define __INT16_C_SUFFIX__  
> #define __INT16_FMTd__ "hd"  
> #define __INT16_FMTi__ "hi"  
> #define __INT16_MAX__ 32767  
> #define __INT16_TYPE__ short  
> #define __INT32_C_SUFFIX__  
> #define __INT32_FMTd__ "d"  
> #define __INT32_FMTi__ "i"  
> #define __INT32_MAX__ 2147483647  
> #define __INT32_TYPE__ int  
> #define __INT64_C_SUFFIX__ LL  
> #define __INT64_FMTd__ "lld"  
> #define __INT64_FMTi__ "lli"  
> #define __INT64_MAX__ 9223372036854775807LL  
> #define __INT64_TYPE__ long long int  
> #define __INT8_C_SUFFIX__  
> #define __INT8_FMTd__ "hhd"  
> #define __INT8_FMTi__ "hhi"  
> #define __INT8_MAX__ 127  
> #define __INT8_TYPE__ signed char  
> #define __INTMAX_C_SUFFIX__ LL  
> #define __INTMAX_FMTd__ "lld"  
> #define __INTMAX_FMTi__ "lli"  
> #define __INTMAX_MAX__ 9223372036854775807LL  
> #define __INTMAX_TYPE__ long long int  
> #define __INTMAX_WIDTH__ 64  
> #define __INTPTR_FMTd__ "lld"  
> #define __INTPTR_FMTi__ "lli"  
> #define __INTPTR_MAX__ 9223372036854775807LL  
> #define __INTPTR_TYPE__ long long int  
> #define __INTPTR_WIDTH__ 64  
> #define __INT_FAST16_FMTd__ "hd"  
> #define __INT_FAST16_FMTi__ "hi"  
> #define __INT_FAST16_MAX__ 32767  
> #define __INT_FAST16_TYPE__ short  
> #define __INT_FAST32_FMTd__ "d"  
> #define __INT_FAST32_FMTi__ "i"  
> #define __INT_FAST32_MAX__ 2147483647  
> #define __INT_FAST32_TYPE__ int  
> #define __INT_FAST64_FMTd__ "lld"  
> #define __INT_FAST64_FMTi__ "lli"  
> #define __INT_FAST64_MAX__ 9223372036854775807LL  
> #define __INT_FAST64_TYPE__ long long int  
> #define __INT_FAST8_FMTd__ "hhd"  
> #define __INT_FAST8_FMTi__ "hhi"  
> #define __INT_FAST8_MAX__ 127  
> #define __INT_FAST8_TYPE__ signed char  
> #define __INT_LEAST16_FMTd__ "hd"  
> #define __INT_LEAST16_FMTi__ "hi"  
> #define __INT_LEAST16_MAX__ 32767  
> #define __INT_LEAST16_TYPE__ short  
> #define __INT_LEAST32_FMTd__ "d"  
> #define __INT_LEAST32_FMTi__ "i"  
> #define __INT_LEAST32_MAX__ 2147483647  
> #define __INT_LEAST32_TYPE__ int  
> #define __INT_LEAST64_FMTd__ "lld"  
> #define __INT_LEAST64_FMTi__ "lli"  
> #define __INT_LEAST64_MAX__ 9223372036854775807LL  
> #define __INT_LEAST64_TYPE__ long long int  
> #define __INT_LEAST8_FMTd__ "hhd"  
> #define __INT_LEAST8_FMTi__ "hhi"  
> #define __INT_LEAST8_MAX__ 127  
> #define __INT_LEAST8_TYPE__ signed char  
> #define __INT_MAX__ 2147483647  
> #define __LDBL_DECIMAL_DIG__ 21  
> #define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L  
> #define __LDBL_DIG__ 18  
> #define __LDBL_EPSILON__ 1.08420217248550443401e-19L  
> #define __LDBL_HAS_DENORM__ 1  
> #define __LDBL_HAS_INFINITY__ 1  
> #define __LDBL_HAS_QUIET_NAN__ 1  
> #define __LDBL_MANT_DIG__ 64  
> #define __LDBL_MAX_10_EXP__ 4932  
> #define __LDBL_MAX_EXP__ 16384  
> #define __LDBL_MAX__ 1.18973149535723176502e+4932L  
> #define __LDBL_MIN_10_EXP__ (-4931)  
> #define __LDBL_MIN_EXP__ (-16381)  
> #define __LDBL_MIN__ 3.36210314311209350626e-4932L  
> #define __LITTLE_ENDIAN__ 1  
> #define __LONG_LONG_MAX__ 9223372036854775807LL  
> #define __LONG_MAX__ 2147483647L  
> #define __MINGW32__ 1  
> #define __MINGW64__ 1  
> #define __MMX__ 1  
> #define __MSVCRT__ 1  
> #define __NO_INLINE__ 1  
> #define __NO_MATH_INLINES 1  
> #define __ORDER_BIG_ENDIAN__ 4321  
> #define __ORDER_LITTLE_ENDIAN__ 1234  
> #define __ORDER_PDP_ENDIAN__ 3412  
> #define __PIC__ 2  
> #define __POINTER_WIDTH__ 64  
> #define __PRAGMA_REDEFINE_EXTNAME 1  
> #define __PTRDIFF_FMTd__ "lld"  
> #define __PTRDIFF_FMTi__ "lli"  
> #define __PTRDIFF_MAX__ 9223372036854775807LL  
> #define __PTRDIFF_TYPE__ long long int  
> #define __PTRDIFF_WIDTH__ 64  
> #define __REGISTER_PREFIX__  
> #define __SCHAR_MAX__ 127  
> #define __SEH__ 1  
> #define __SHRT_MAX__ 32767  
> #define __SIG_ATOMIC_MAX__ 2147483647  
> #define __SIG_ATOMIC_WIDTH__ 32  
> #define __SIZEOF_DOUBLE__ 8  
> #define __SIZEOF_FLOAT__ 4  
> #define __SIZEOF_INT128__ 16  
> #define __SIZEOF_INT__ 4  
> #define __SIZEOF_LONG_DOUBLE__ 16  
> #define __SIZEOF_LONG_LONG__ 8  
> #define __SIZEOF_LONG__ 4  
> #define __SIZEOF_POINTER__ 8  
> #define __SIZEOF_PTRDIFF_T__ 8  
> #define __SIZEOF_SHORT__ 2  
> #define __SIZEOF_SIZE_T__ 8  
> #define __SIZEOF_WCHAR_T__ 2  
> #define __SIZEOF_WINT_T__ 4  
> #define __SIZE_FMTX__ "llX"  
> #define __SIZE_FMTo__ "llo"  
> #define __SIZE_FMTu__ "llu"  
> #define __SIZE_FMTx__ "llx"  
> #define __SIZE_MAX__ 18446744073709551615ULL  
> #define __SIZE_TYPE__ long long unsigned int  
> #define __SIZE_WIDTH__ 64  
> #define __SSE2_MATH__ 1  
> #define __SSE2__ 1  
> #define __SSE_MATH__ 1  
> #define __SSE__ 1  
> #define __STDC_HOSTED__ 1  
> #define __STDC_UTF_16__ 1  
> #define __STDC_UTF_32__ 1  
> #define __STDC_VERSION__ 201112L  
> #define __STDC__ 1  
> #define __UINT16_C_SUFFIX__  
> #define __UINT16_FMTX__ "hX"  
> #define __UINT16_FMTo__ "ho"  
> #define __UINT16_FMTu__ "hu"  
> #define __UINT16_FMTx__ "hx"  
> #define __UINT16_MAX__ 65535  
> #define __UINT16_TYPE__ unsigned short  
> #define __UINT32_C_SUFFIX__ U  
> #define __UINT32_FMTX__ "X"  
> #define __UINT32_FMTo__ "o"  
> #define __UINT32_FMTu__ "u"  
> #define __UINT32_FMTx__ "x"  
> #define __UINT32_MAX__ 4294967295U  
> #define __UINT32_TYPE__ unsigned int  
> #define __UINT64_C_SUFFIX__ ULL  
> #define __UINT64_FMTX__ "llX"  
> #define __UINT64_FMTo__ "llo"  
> #define __UINT64_FMTu__ "llu"  
> #define __UINT64_FMTx__ "llx"  
> #define __UINT64_MAX__ 18446744073709551615ULL  
> #define __UINT64_TYPE__ long long unsigned int  
> #define __UINT8_C_SUFFIX__  
> #define __UINT8_FMTX__ "hhX"  
> #define __UINT8_FMTo__ "hho"  
> #define __UINT8_FMTu__ "hhu"  
> #define __UINT8_FMTx__ "hhx"  
> #define __UINT8_MAX__ 255  
> #define __UINT8_TYPE__ unsigned char  
> #define __UINTMAX_C_SUFFIX__ ULL  
> #define __UINTMAX_FMTX__ "llX"  
> #define __UINTMAX_FMTo__ "llo"  
> #define __UINTMAX_FMTu__ "llu"  
> #define __UINTMAX_FMTx__ "llx"  
> #define __UINTMAX_MAX__ 18446744073709551615ULL  
> #define __UINTMAX_TYPE__ long long unsigned int  
> #define __UINTMAX_WIDTH__ 64  
> #define __UINTPTR_FMTX__ "llX"  
> #define __UINTPTR_FMTo__ "llo"  
> #define __UINTPTR_FMTu__ "llu"  
> #define __UINTPTR_FMTx__ "llx"  
> #define __UINTPTR_MAX__ 18446744073709551615ULL  
> #define __UINTPTR_TYPE__ long long unsigned int  
> #define __UINTPTR_WIDTH__ 64  
> #define __UINT_FAST16_FMTX__ "hX"  
> #define __UINT_FAST16_FMTo__ "ho"  
> #define __UINT_FAST16_FMTu__ "hu"  
> #define __UINT_FAST16_FMTx__ "hx"  
> #define __UINT_FAST16_MAX__ 65535  
> #define __UINT_FAST16_TYPE__ unsigned short  
> #define __UINT_FAST32_FMTX__ "X"  
> #define __UINT_FAST32_FMTo__ "o"  
> #define __UINT_FAST32_FMTu__ "u"  
> #define __UINT_FAST32_FMTx__ "x"  
> #define __UINT_FAST32_MAX__ 4294967295U  
> #define __UINT_FAST32_TYPE__ unsigned int  
> #define __UINT_FAST64_FMTX__ "llX"  
> #define __UINT_FAST64_FMTo__ "llo"  
> #define __UINT_FAST64_FMTu__ "llu"  
> #define __UINT_FAST64_FMTx__ "llx"  
> #define __UINT_FAST64_MAX__ 18446744073709551615ULL  
> #define __UINT_FAST64_TYPE__ long long unsigned int  
> #define __UINT_FAST8_FMTX__ "hhX"  
> #define __UINT_FAST8_FMTo__ "hho"  
> #define __UINT_FAST8_FMTu__ "hhu"  
> #define __UINT_FAST8_FMTx__ "hhx"  
> #define __UINT_FAST8_MAX__ 255  
> #define __UINT_FAST8_TYPE__ unsigned char  
> #define __UINT_LEAST16_FMTX__ "hX"  
> #define __UINT_LEAST16_FMTo__ "ho"  
> #define __UINT_LEAST16_FMTu__ "hu"  
> #define __UINT_LEAST16_FMTx__ "hx"  
> #define __UINT_LEAST16_MAX__ 65535  
> #define __UINT_LEAST16_TYPE__ unsigned short  
> #define __UINT_LEAST32_FMTX__ "X"  
> #define __UINT_LEAST32_FMTo__ "o"  
> #define __UINT_LEAST32_FMTu__ "u"  
> #define __UINT_LEAST32_FMTx__ "x"  
> #define __UINT_LEAST32_MAX__ 4294967295U  
> #define __UINT_LEAST32_TYPE__ unsigned int  
> #define __UINT_LEAST64_FMTX__ "llX"  
> #define __UINT_LEAST64_FMTo__ "llo"  
> #define __UINT_LEAST64_FMTu__ "llu"  
> #define __UINT_LEAST64_FMTx__ "llx"  
> #define __UINT_LEAST64_MAX__ 18446744073709551615ULL  
> #define __UINT_LEAST64_TYPE__ long long unsigned int  
> #define __UINT_LEAST8_FMTX__ "hhX"  
> #define __UINT_LEAST8_FMTo__ "hho"  
> #define __UINT_LEAST8_FMTu__ "hhu"  
> #define __UINT_LEAST8_FMTx__ "hhx"  
> #define __UINT_LEAST8_MAX__ 255  
> #define __UINT_LEAST8_TYPE__ unsigned char  
> #define __USER_LABEL_PREFIX__  
> #define __VERSION__ "4.2.1 Compatible Clang 3.8.0 (tags/RELEASE_380/final)"  
> #define __WCHAR_MAX__ 65535  
> #define __WCHAR_TYPE__ unsigned short  
> #define __WCHAR_UNSIGNED__ 1  
> #define __WCHAR_WIDTH__ 16  
> #define __WIN64 1  
> #define __WIN64__ 1  
> #define __WINT_TYPE__ int  
> #define __WINT_WIDTH__ 32  
> #define __amd64 1  
> #define __amd64__ 1  
> #define __cdecl __attribute__((__cdecl__))  
> #define __clang__ 1  
> #define __clang_major__ 3  
> #define __clang_minor__ 8  
> #define __clang_patchlevel__ 0  
> #define __clang_version__ "3.8.0 (tags/RELEASE_380/final)"  
> #define __declspec(a) __attribute__((a))  
> #define __fastcall __attribute__((__fastcall__))  
> #define __k8 1  
> #define __k8__ 1  
> #define __llvm__ 1  
> #define __pascal __attribute__((__pascal__))  
> #define __pic__ 2  
> #define __stdcall __attribute__((__stdcall__))  
> #define __thiscall __attribute__((__thiscall__))  
> #define __tune_k8__ 1  
> #define __x86_64 1  
> #define __x86_64__ 1  
> #define _cdecl __attribute__((__cdecl__))  
> #define _fastcall __attribute__((__fastcall__))  
> #define _pascal __attribute__((__pascal__))  
> #define _stdcall __attribute__((__stdcall__))  
> #define _thiscall __attribute__((__thiscall__))

> kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 ~  
> $

==&gt; This seem to be the clang pre-defined macros on MacOS?

> Kjell-Olovs-MacBook-Pro:MyCppStringPlayground kjell-olovhogdahl$ clang -dM -E -x c /dev/null  
> #define OBJC_NEW_PROPERTIES 1  
> #define _LP64 1  
> #define __APPLE_CC__ 6000  
> #define __APPLE__ 1  
> #define __ATOMIC_ACQUIRE 2  
> #define __ATOMIC_ACQ_REL 4  
> #define __ATOMIC_CONSUME 1  
> #define __ATOMIC_RELAXED 0  
> #define __ATOMIC_RELEASE 3  
> #define __ATOMIC_SEQ_CST 5  
> #define __BIGGEST_ALIGNMENT__ 16  
> #define __BLOCKS__ 1  
> #define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__  
> #define __CHAR16_TYPE__ unsigned short  
> #define __CHAR32_TYPE__ unsigned int  
> #define __CHAR_BIT__ 8  
> #define __CONSTANT_CFSTRINGS__ 1  
> #define __DBL_DECIMAL_DIG__ 17  
> #define __DBL_DENORM_MIN__ 4.9406564584124654e-324  
> #define __DBL_DIG__ 15  
> #define __DBL_EPSILON__ 2.2204460492503131e-16  
> #define __DBL_HAS_DENORM__ 1  
> #define __DBL_HAS_INFINITY__ 1  
> #define __DBL_HAS_QUIET_NAN__ 1  
> #define __DBL_MANT_DIG__ 53  
> #define __DBL_MAX_10_EXP__ 308  
> #define __DBL_MAX_EXP__ 1024  
> #define __DBL_MAX__ 1.7976931348623157e+308  
> #define __DBL_MIN_10_EXP__ (-307)  
> #define __DBL_MIN_EXP__ (-1021)  
> #define __DBL_MIN__ 2.2250738585072014e-308  
> #define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__  
> #define __DYNAMIC__ 1  
> #define __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ 101100  
> #define __FINITE_MATH_ONLY__ 0  
> #define __FLT_DECIMAL_DIG__ 9  
> #define __FLT_DENORM_MIN__ 1.40129846e-45F  
> #define __FLT_DIG__ 6  
> #define __FLT_EPSILON__ 1.19209290e-7F  
> #define __FLT_EVAL_METHOD__ 0  
> #define __FLT_HAS_DENORM__ 1  
> #define __FLT_HAS_INFINITY__ 1  
> #define __FLT_HAS_QUIET_NAN__ 1  
> #define __FLT_MANT_DIG__ 24  
> #define __FLT_MAX_10_EXP__ 38  
> #define __FLT_MAX_EXP__ 128  
> #define __FLT_MAX__ 3.40282347e+38F  
> #define __FLT_MIN_10_EXP__ (-37)  
> #define __FLT_MIN_EXP__ (-125)  
> #define __FLT_MIN__ 1.17549435e-38F  
> #define __FLT_RADIX__ 2  
> #define __FXSR__ 1  
> #define __GCC_ATOMIC_BOOL_LOCK_FREE 2  
> #define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2  
> #define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2  
> #define __GCC_ATOMIC_CHAR_LOCK_FREE 2  
> #define __GCC_ATOMIC_INT_LOCK_FREE 2  
> #define __GCC_ATOMIC_LLONG_LOCK_FREE 2  
> #define __GCC_ATOMIC_LONG_LOCK_FREE 2  
> #define __GCC_ATOMIC_POINTER_LOCK_FREE 2  
> #define __GCC_ATOMIC_SHORT_LOCK_FREE 2  
> #define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1  
> #define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_16 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1  
> #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1  
> #define __GNUC_MINOR__ 2  
> #define __GNUC_PATCHLEVEL__ 1  
> #define __GNUC_STDC_INLINE__ 1  
> #define __GNUC__ 4  
> #define __GXX_ABI_VERSION 1002  
> #define __GXX_RTTI 1  
> #define __INT16_C_SUFFIX__  
> #define __INT16_FMTd__ "hd"  
> #define __INT16_FMTi__ "hi"  
> #define __INT16_MAX__ 32767  
> #define __INT16_TYPE__ short  
> #define __INT32_C_SUFFIX__  
> #define __INT32_FMTd__ "d"  
> #define __INT32_FMTi__ "i"  
> #define __INT32_MAX__ 2147483647  
> #define __INT32_TYPE__ int  
> #define __INT64_C_SUFFIX__ LL  
> #define __INT64_FMTd__ "lld"  
> #define __INT64_FMTi__ "lli"  
> #define __INT64_MAX__ 9223372036854775807LL  
> #define __INT64_TYPE__ long long int  
> #define __INT8_C_SUFFIX__  
> #define __INT8_FMTd__ "hhd"  
> #define __INT8_FMTi__ "hhi"  
> #define __INT8_MAX__ 127  
> #define __INT8_TYPE__ signed char  
> #define __INTMAX_C_SUFFIX__ L  
> #define __INTMAX_FMTd__ "ld"  
> #define __INTMAX_FMTi__ "li"  
> #define __INTMAX_MAX__ 9223372036854775807L  
> #define __INTMAX_TYPE__ long int  
> #define __INTMAX_WIDTH__ 64  
> #define __INTPTR_FMTd__ "ld"  
> #define __INTPTR_FMTi__ "li"  
> #define __INTPTR_MAX__ 9223372036854775807L  
> #define __INTPTR_TYPE__ long int  
> #define __INTPTR_WIDTH__ 64  
> #define __INT_FAST16_FMTd__ "hd"  
> #define __INT_FAST16_FMTi__ "hi"  
> #define __INT_FAST16_MAX__ 32767  
> #define __INT_FAST16_TYPE__ short  
> #define __INT_FAST32_FMTd__ "d"  
> #define __INT_FAST32_FMTi__ "i"  
> #define __INT_FAST32_MAX__ 2147483647  
> #define __INT_FAST32_TYPE__ int  
> #define __INT_FAST64_FMTd__ "ld"  
> #define __INT_FAST64_FMTi__ "li"  
> #define __INT_FAST64_MAX__ 9223372036854775807L  
> #define __INT_FAST64_TYPE__ long int  
> #define __INT_FAST8_FMTd__ "hhd"  
> #define __INT_FAST8_FMTi__ "hhi"  
> #define __INT_FAST8_MAX__ 127  
> #define __INT_FAST8_TYPE__ signed char  
> #define __INT_LEAST16_FMTd__ "hd"  
> #define __INT_LEAST16_FMTi__ "hi"  
> #define __INT_LEAST16_MAX__ 32767  
> #define __INT_LEAST16_TYPE__ short  
> #define __INT_LEAST32_FMTd__ "d"  
> #define __INT_LEAST32_FMTi__ "i"  
> #define __INT_LEAST32_MAX__ 2147483647  
> #define __INT_LEAST32_TYPE__ int  
> #define __INT_LEAST64_FMTd__ "ld"  
> #define __INT_LEAST64_FMTi__ "li"  
> #define __INT_LEAST64_MAX__ 9223372036854775807L  
> #define __INT_LEAST64_TYPE__ long int  
> #define __INT_LEAST8_FMTd__ "hhd"  
> #define __INT_LEAST8_FMTi__ "hhi"  
> #define __INT_LEAST8_MAX__ 127  
> #define __INT_LEAST8_TYPE__ signed char  
> #define __INT_MAX__ 2147483647  
> #define __LDBL_DECIMAL_DIG__ 21  
> #define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L  
> #define __LDBL_DIG__ 18  
> #define __LDBL_EPSILON__ 1.08420217248550443401e-19L  
> #define __LDBL_HAS_DENORM__ 1  
> #define __LDBL_HAS_INFINITY__ 1  
> #define __LDBL_HAS_QUIET_NAN__ 1  
> #define __LDBL_MANT_DIG__ 64  
> #define __LDBL_MAX_10_EXP__ 4932  
> #define __LDBL_MAX_EXP__ 16384  
> #define __LDBL_MAX__ 1.18973149535723176502e+4932L  
> #define __LDBL_MIN_10_EXP__ (-4931)  
> #define __LDBL_MIN_EXP__ (-16381)  
> #define __LDBL_MIN__ 3.36210314311209350626e-4932L  
> #define __LITTLE_ENDIAN__ 1  
> #define __LONG_LONG_MAX__ 9223372036854775807LL  
> #define __LONG_MAX__ 9223372036854775807L  
> #define __LP64__ 1  
> #define __MACH__ 1  
> #define __MMX__ 1  
> #define __NO_INLINE__ 1  
> #define __NO_MATH_INLINES 1  
> #define __ORDER_BIG_ENDIAN__ 4321  
> #define __ORDER_LITTLE_ENDIAN__ 1234  
> #define __ORDER_PDP_ENDIAN__ 3412  
> #define __PIC__ 2  
> #define __POINTER_WIDTH__ 64  
> #define __PRAGMA_REDEFINE_EXTNAME 1  
> #define __PTRDIFF_FMTd__ "ld"  
> #define __PTRDIFF_FMTi__ "li"  
> #define __PTRDIFF_MAX__ 9223372036854775807L  
> #define __PTRDIFF_TYPE__ long int  
> #define __PTRDIFF_WIDTH__ 64  
> #define __REGISTER_PREFIX__  
> #define __SCHAR_MAX__ 127  
> #define __SHRT_MAX__ 32767  
> #define __SIG_ATOMIC_MAX__ 2147483647  
> #define __SIG_ATOMIC_WIDTH__ 32  
> #define __SIZEOF_DOUBLE__ 8  
> #define __SIZEOF_FLOAT__ 4  
> #define __SIZEOF_INT128__ 16  
> #define __SIZEOF_INT__ 4  
> #define __SIZEOF_LONG_DOUBLE__ 16  
> #define __SIZEOF_LONG_LONG__ 8  
> #define __SIZEOF_LONG__ 8  
> #define __SIZEOF_POINTER__ 8  
> #define __SIZEOF_PTRDIFF_T__ 8  
> #define __SIZEOF_SHORT__ 2  
> #define __SIZEOF_SIZE_T__ 8  
> #define __SIZEOF_WCHAR_T__ 4  
> #define __SIZEOF_WINT_T__ 4  
> #define __SIZE_FMTX__ "lX"  
> #define __SIZE_FMTo__ "lo"  
> #define __SIZE_FMTu__ "lu"  
> #define __SIZE_FMTx__ "lx"  
> #define __SIZE_MAX__ 18446744073709551615UL  
> #define __SIZE_TYPE__ long unsigned int  
> #define __SIZE_WIDTH__ 64  
> #define __SSE2_MATH__ 1  
> #define __SSE2__ 1  
> #define __SSE3__ 1  
> #define __SSE_MATH__ 1  
> #define __SSE__ 1  
> #define __SSP__ 1  
> #define __SSSE3__ 1  
> #define __STDC_HOSTED__ 1  
> #define __STDC_UTF_16__ 1  
> #define __STDC_UTF_32__ 1  
> #define __STDC_VERSION__ 201112L  
> #define __STDC__ 1  
> #define __UINT16_C_SUFFIX__  
> #define __UINT16_FMTX__ "hX"  
> #define __UINT16_FMTo__ "ho"  
> #define __UINT16_FMTu__ "hu"  
> #define __UINT16_FMTx__ "hx"  
> #define __UINT16_MAX__ 65535  
> #define __UINT16_TYPE__ unsigned short  
> #define __UINT32_C_SUFFIX__ U  
> #define __UINT32_FMTX__ "X"  
> #define __UINT32_FMTo__ "o"  
> #define __UINT32_FMTu__ "u"  
> #define __UINT32_FMTx__ "x"  
> #define __UINT32_MAX__ 4294967295U  
> #define __UINT32_TYPE__ unsigned int  
> #define __UINT64_C_SUFFIX__ ULL  
> #define __UINT64_FMTX__ "llX"  
> #define __UINT64_FMTo__ "llo"  
> #define __UINT64_FMTu__ "llu"  
> #define __UINT64_FMTx__ "llx"  
> #define __UINT64_MAX__ 18446744073709551615ULL  
> #define __UINT64_TYPE__ long long unsigned int  
> #define __UINT8_C_SUFFIX__  
> #define __UINT8_FMTX__ "hhX"  
> #define __UINT8_FMTo__ "hho"  
> #define __UINT8_FMTu__ "hhu"  
> #define __UINT8_FMTx__ "hhx"  
> #define __UINT8_MAX__ 255  
> #define __UINT8_TYPE__ unsigned char  
> #define __UINTMAX_C_SUFFIX__ UL  
> #define __UINTMAX_FMTX__ "lX"  
> #define __UINTMAX_FMTo__ "lo"  
> #define __UINTMAX_FMTu__ "lu"  
> #define __UINTMAX_FMTx__ "lx"  
> #define __UINTMAX_MAX__ 18446744073709551615UL  
> #define __UINTMAX_TYPE__ long unsigned int  
> #define __UINTMAX_WIDTH__ 64  
> #define __UINTPTR_FMTX__ "lX"  
> #define __UINTPTR_FMTo__ "lo"  
> #define __UINTPTR_FMTu__ "lu"  
> #define __UINTPTR_FMTx__ "lx"  
> #define __UINTPTR_MAX__ 18446744073709551615UL  
> #define __UINTPTR_TYPE__ long unsigned int  
> #define __UINTPTR_WIDTH__ 64  
> #define __UINT_FAST16_FMTX__ "hX"  
> #define __UINT_FAST16_FMTo__ "ho"  
> #define __UINT_FAST16_FMTu__ "hu"  
> #define __UINT_FAST16_FMTx__ "hx"  
> #define __UINT_FAST16_MAX__ 65535  
> #define __UINT_FAST16_TYPE__ unsigned short  
> #define __UINT_FAST32_FMTX__ "X"  
> #define __UINT_FAST32_FMTo__ "o"  
> #define __UINT_FAST32_FMTu__ "u"  
> #define __UINT_FAST32_FMTx__ "x"  
> #define __UINT_FAST32_MAX__ 4294967295U  
> #define __UINT_FAST32_TYPE__ unsigned int  
> #define __UINT_FAST64_FMTX__ "lX"  
> #define __UINT_FAST64_FMTo__ "lo"  
> #define __UINT_FAST64_FMTu__ "lu"  
> #define __UINT_FAST64_FMTx__ "lx"  
> #define __UINT_FAST64_MAX__ 18446744073709551615UL  
> #define __UINT_FAST64_TYPE__ long unsigned int  
> #define __UINT_FAST8_FMTX__ "hhX"  
> #define __UINT_FAST8_FMTo__ "hho"  
> #define __UINT_FAST8_FMTu__ "hhu"  
> #define __UINT_FAST8_FMTx__ "hhx"  
> #define __UINT_FAST8_MAX__ 255  
> #define __UINT_FAST8_TYPE__ unsigned char  
> #define __UINT_LEAST16_FMTX__ "hX"  
> #define __UINT_LEAST16_FMTo__ "ho"  
> #define __UINT_LEAST16_FMTu__ "hu"  
> #define __UINT_LEAST16_FMTx__ "hx"  
> #define __UINT_LEAST16_MAX__ 65535  
> #define __UINT_LEAST16_TYPE__ unsigned short  
> #define __UINT_LEAST32_FMTX__ "X"  
> #define __UINT_LEAST32_FMTo__ "o"  
> #define __UINT_LEAST32_FMTu__ "u"  
> #define __UINT_LEAST32_FMTx__ "x"  
> #define __UINT_LEAST32_MAX__ 4294967295U  
> #define __UINT_LEAST32_TYPE__ unsigned int  
> #define __UINT_LEAST64_FMTX__ "lX"  
> #define __UINT_LEAST64_FMTo__ "lo"  
> #define __UINT_LEAST64_FMTu__ "lu"  
> #define __UINT_LEAST64_FMTx__ "lx"  
> #define __UINT_LEAST64_MAX__ 18446744073709551615UL  
> #define __UINT_LEAST64_TYPE__ long unsigned int  
> #define __UINT_LEAST8_FMTX__ "hhX"  
> #define __UINT_LEAST8_FMTo__ "hho"  
> #define __UINT_LEAST8_FMTu__ "hhu"  
> #define __UINT_LEAST8_FMTx__ "hhx"  
> #define __UINT_LEAST8_MAX__ 255  
> #define __UINT_LEAST8_TYPE__ unsigned char  
> #define __USER_LABEL_PREFIX__ _  
> #define __VERSION__ "4.2.1 Compatible Apple LLVM 7.3.0 (clang-703.0.31)"  
> #define __WCHAR_MAX__ 2147483647  
> #define __WCHAR_TYPE__ int  
> #define __WCHAR_WIDTH__ 32  
> #define __WINT_TYPE__ int  
> #define __WINT_WIDTH__ 32  
> #define __amd64 1  
> #define __amd64__ 1  
> #define __apple_build_version__ 7030031  
> #define __block __attribute__((__blocks__(byref)))  
> #define __clang__ 1  
> #define __clang_major__ 7  
> #define __clang_minor__ 3  
> #define __clang_patchlevel__ 0  
> #define __clang_version__ "7.3.0 (clang-703.0.31)"  
> #define __core2 1  
> #define __core2__ 1  
> #define __llvm__ 1  
> #define __nonnull _Nonnull  
> #define __null_unspecified _Null_unspecified  
> #define __nullable _Nullable  
> #define __pic__ 2  
> #define __strong  
> #define __tune_core2__ 1  
> #define __unsafe_unretained  
> #define __weak __attribute__((objc_gc(weak)))  
> #define __x86_64 1  
> #define __x86_64__ 1  
> Kjell-Olovs-MacBook-Pro:MyCppStringPlayground kjell-olovhogdahl$

{% endraw %}
