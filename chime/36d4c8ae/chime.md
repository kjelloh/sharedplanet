# Todo: Programming - Consider the code point and encode aware C++ Text class library to help bridging text encoding to and from the platform API?

```#36d4c8ae``` *As of 2016-07-20 21:06*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to study how different platform APIs (e.g., Windows, Linux and MacOS) applies string encoding options and have the code point and encode aware (CPEA) C++ text library provide services to help with cross platform API call text encoding issues?

1) Consider this blog post on testing platform string encoding (<https://alfps.wordpress.com/2011/11/22/unicode-part-1-windows-console-io-approaches/>)?

==&gt; The post seem to draw the conclusion that all-utf8 is not the way to go?

2) Consider to use Boost config header includes and apply the Boost macros in user code as a way of identifying the build environment?

==&gt; The Boost Config documentation seems to indicate that this is a feasible way to use the Boost config mechanism (<http://www.boost.org/doc/libs/1_61_0/libs/config/doc/html/index.html>)?

==&gt; This seem to be the documentation of Boost macros for identified build environment (<http://www.boost.org/doc/libs/1_61_0/libs/config/doc/html/boost_config/boost_macro_reference.html>)?

==&gt; But Boost does not seem to provide any identification of platform Unicode support?

==&gt; The only macro seem to be BOOST_NO_CXX11_UNICODE_LITERALS that identifies if there is C++11 support for unicode string literals?

...

2) Consider what options a Microsoft Visual Studio console application have for API string encoding?

==&gt; It seems a Windows Console App may support ANSI or Unicode string in API calls?

==&gt; It seems Windows C++ API uses the UNICODE macro to assume what API function to call (<https://en.wikibooks.org/wiki/Windows_Programming/Unicode>)?

“The Win32 API classifies all of its functions that require text input into two categories. Some of the functions have an "A" suffix (for ASCII), and some have a "W" suffix (for Wide characters, or Unicode). These functions are differentiated using the macro "UNICODE”:"

==&gt; This seems to be an example of how an API function is defined as its \*A or \*W variant based on UNICODE macro

> > ```
> > #ifdef UNICODE
> > #define MessageBox MessageBoxW
> > #else
> > #define MessageBox MessageBoxA
> > #endif
> > ```



==&gt; It seems one should ensure that both the UNICDE and _UNICODE macro is defined together

> > ```
> > #ifdef UNICODE
> >   #ifndef _UNICODE
> >     #define _UNICODE
> >   #endif
> > #endif

> > ```

> > ```
> > #ifdef _UNICODE
> >   #ifndef UNICODE
> >     #define UNICODE
> >   #endif
> > #endif
> > ```



==&gt;

3) Consider the CPEA C++ text library to provide some “neutral” base string that adopts the assumed platform API string encoding?

==&gt; Consider on Windows the API string to detect the UNICODE and TCHAR definitions

4) Consider to compare with how Boost libraries are designed to adopt to cross-platform and feature build environments (<http://www.boost.org/doc/libs/1_61_0/libs/config/doc/html/index.html>)?

“Using boost "as is" without trying to reconfigure is the recommended method for using boost.”

“Boost informational or helper macros are designed for use by Boost users as well as for our own internal use.”

==&gt; This seem to be the boost/config.hpp that both Boost libraries and user code may use to apply boost way of identifying and adopting to build environment (<http://www.boost.org/doc/libs/1_61_0/boost/config.hpp>)?

==&gt; Boost seem to apply three different headers to identify compiler, standard library and platform and mirror them as boost macros?

==&gt; It also seem to apply a (default empty) “user” include before including any of the other config headers (<http://www.boost.org/doc/libs/1_61_0/boost/config/user.hpp>)?

> > “Boost's configuration is structured so that the user-configuration is included first (defaulting to &lt;boost/config/user.hpp&gt; if BOOST_USER_CONFIG is not defined). This sets up any user-defined policies, and gives the user-configuration a chance to influence what happens next.

> > Next the compiler, standard library, and platform configuration files are included. These are included via macros (BOOST_COMPILER_CONFIG etc, see user settable macros), and if the corresponding macro is undefined then a separate header that detects which compiler/standard library/platform is in use is included in order to set these. The config can be told to ignore these headers altogether if the corresponding BOOST_NO_XXX macro is set (for example BOOST_NO_COMPILER_CONFIG to disable including any compiler configuration file - see user settable macros).

  
> > Finally the boost configuration header, includes &lt;boost/config/suffix.hpp&gt;; this header contains any boiler plate configuration code - for example where one boost macro being set implies that another must be set also."

==&gt; Boost seem to provide a “compiler identification” header file (<http://www.boost.org/doc/libs/1_61_0/boost/config/select_compiler_config.hpp>)

==&gt; It seems to be further divided into compiler-specific include files?

==&gt; This seem to be the one for Microsoft Visual Studio compilers (<http://www.boost.org/doc/libs/1_61_0/boost/config/compiler/visualc.hpp>)?

==&gt; NOTE: There seem to be none for CodeGear but NONE for Embarcadero (suggesting official Boost does not target Embarcadero)?

==&gt; Boost seem to provide a “Standard library” identification header file (<http://www.boost.org/doc/libs/1_47_0/boost/config/select_stdlib_config.hpp>)?

==&gt; It seems to be divided into library specific include files?

5) Consider ways to detect in C++ code compilation the target platform API and its string encoding?

==&gt; Consider this blog post as a good source for C++ macros (<https://sourceforge.net/p/predef/wiki/Home/>)

==&gt; This seem to be a listing of C++ language flavours in the ANSI standard?

> > C89`__STDC__`ANSI X3.159-1989C90`__STDC__`ISO/IEC 9899:1990C94`__STDC_VERSION__` = 199409LISO/IEC 9899-1:1994[C99](http://www.open-std.org/jtc1/sc22/wg14/)`__STDC_VERSION__` = 199901LISO/IEC 9899:1999[C11](http://en.wikipedia.org/wiki/C11_%28C_standard_revision%29)`__STDC_VERSION__` = 201112LISO/IEC 9899:2011[C++98](http://www.open-std.org/jtc1/sc22/wg21/)`__cplusplus` = 199711LISO/IEC 14882:1998[C++11](http://en.wikipedia.org/wiki/C%2B%2B11)`__cplusplus` = 201103LISO/IEC 14882:2011[C++14](http://en.wikipedia.org/wiki/C%2B%2B14)`__cplusplus` = 201402LISO/IEC 14882:2014[C++/CLI](http://www.ecma-international.org/publications/standards/Ecma-372.htm)`__cplusplus_cli` = 200406LECMA-372[DSP-C](http://www.dsp-c.org/)ISO/IEC JTC1/SC22 WG14/N854[EC++](http://www.caravan.net/ec2plus/)`__embedded_cplusplus`Embedded C++

==&gt; Linux POSIX platforms seem to define a set of their own platform macros?

> > POSIX.1-1988`_POSIX_VERSION` = 198808LPOSIX.1-1990`_POSIX_VERSION` = 199009LISO/IEC 9945-1:1990POSIX.2`_POSIX2_C_VERSION` = 199209LISO/IEC 9945-2:1993POSIX.1b-1993`_POSIX_VERSION` = 199309LIEEE 1003.1b-1993POSIX.1-1996`_POSIX_VERSION` = 199506LIEEE 1003.1-1996POSIX.1-2001`_POSIX_VERSION` = 200112LIEEE 1003.1-2001[POSIX.1-2008](http://pubs.opengroup.org/onlinepubs/9699919799/)`_POSIX_VERSION` = 200809LIEEE 1003.1-2008XPG3`_XOPEN_VERSION` = 3X/Open Portability Guide 3 (1989)XPG4`_XOPEN_VERSION` = 4X/Open Portability Guide 4 (1992)SUS`_XOPEN_VERSION` = 4 `&&` `_XOPEN_UNIX`X/Open Single UNIX Specification (UNIX95)[SUSv2](http://www.opengroup.org/onlinepubs/7908799/toc.htm)`_XOPEN_VERSION` = 500X/Open Single UNIX Specification, Version 2 (UNIX98)[SUSv3](http://www.opengroup.org/onlinepubs/007904975/nfindex.html)`_XOPEN_VERSION` = 600Open Group Single UNIX Specification, Version 3 (UNIX03)[SUSv4](http://pubs.opengroup.org/onlinepubs/9699919799/)`_XOPEN_VERSION` = 700Open Group Single UNIX Specification, Version 4LSB`__LSB_VERSION__` = VRLinux Standards Base

> > V = Version  
> > R = Revision

==&gt; This seems to be good lead to (but somewhat outdated) compiler identification macros (<https://sourceforge.net/p/predef/wiki/Compilers/>)?

==&gt; This may be good leads to (but somewhat outdated) C and C++ library standard identification macros (<https://sourceforge.net/p/predef/wiki/Libraries/>)?

==&gt; This seem to be a (somewhat outdated) try to define platform identification macros (<https://sourceforge.net/p/predef/wiki/OperatingSystems/>)?

> > ## [Windows](http://en.wikipedia.org/wiki/Category:Microsoft_Windows)

> > TypeMacroDescriptionIdentification`_WIN16`Defined for 16-bit environments [1](http://msdn.microsoft.com/en-us/library/ff540443.aspx)Identification`_WIN32`Defined for both 32-bit and 64-bit environments [1](http://msdn.microsoft.com/en-us/library/ff540443.aspx)Identification`_WIN64`Defined for 64-bit environments [1](http://msdn.microsoft.com/en-us/library/ff540443.aspx)Identification`__WIN32__`Defined by Borland C++Identification`__TOS_WIN__`Defined by xlCIdentification`__WINDOWS__`Defined by Watcom C/C++

> > ## [UNIX Environment](http://en.wikipedia.org/wiki/Unix)

> > TypeMacroIdentification`__unix__`Identification`__unix

> > `

==&gt;

…

Consider to elaborate on this idea to view the required services of CPEA Text C++ library to make platform API calls correct?

...

{% endraw %}
