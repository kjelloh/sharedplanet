# Todo: Programming - Consider ways to identify and adapt to Host build environment in C++ code?

```#57b1d0ec``` *As of 2016-08-02 17:16*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to find out ways available in C++ code to identify and adapt to the build environment?

1) Consider ways in C++ to identify and adapt to the build host environment?

==&gt; Consider this blog post as a good source for C++ macros (<https://sourceforge.net/p/predef/wiki/Home/>)

==&gt; This seem to be a listing of C++ language flavours in the ANSI standard?

> > C89`__STDC__`ANSI X3.159-1989C90`__STDC__`ISO/IEC 9899:1990C94`__STDC_VERSION__` = 199409LISO/IEC 9899-1:1994[C99](http://www.open-std.org/jtc1/sc22/wg14/)`__STDC_VERSION__` = 199901LISO/IEC 9899:1999[C11](http://en.wikipedia.org/wiki/C11_%28C_standard_revision%29)`__STDC_VERSION__` = 201112LISO/IEC 9899:2011[C++98](http://www.open-std.org/jtc1/sc22/wg21/)`__cplusplus` = 199711LISO/IEC 14882:1998[C++11](http://en.wikipedia.org/wiki/C%2B%2B11)`__cplusplus` = 201103LISO/IEC 14882:2011[C++14](http://en.wikipedia.org/wiki/C%2B%2B14)`__cplusplus` = 201402LISO/IEC 14882:2014[C++/CLI](http://www.ecma-international.org/publications/standards/Ecma-372.htm)`__cplusplus_cli` = 200406LECMA-372[DSP-C](http://www.dsp-c.org/)ISO/IEC JTC1/SC22 WG14/N854[EC++](http://www.caravan.net/ec2plus/)`__embedded_cplusplus`Embedded C++

==&gt; Linux POSIX platforms seem to define a set of their own platform macros?

> > POSIX.1-1988`_POSIX_VERSION` = 198808LPOSIX.1-1990`_POSIX_VERSION` = 199009LISO/IEC 9945-1:1990POSIX.2`_POSIX2_C_VERSION` = 199209LISO/IEC 9945-2:1993POSIX.1b-1993`_POSIX_VERSION` = 199309LIEEE 1003.1b-1993POSIX.1-1996`_POSIX_VERSION` = 199506LIEEE 1003.1-1996POSIX.1-2001`_POSIX_VERSION` = 200112LIEEE 1003.1-2001[POSIX.1-2008](http://pubs.opengroup.org/onlinepubs/9699919799/)`_POSIX_VERSION` = 200809LIEEE 1003.1-2008XPG3`_XOPEN_VERSION` = 3X/Open Portability Guide 3 (1989)XPG4`_XOPEN_VERSION` = 4X/Open Portability Guide 4 (1992)SUS`_XOPEN_VERSION` = 4 `&&` `_XOPEN_UNIX`X/Open Single UNIX Specification (UNIX95)[SUSv2](http://www.opengroup.org/onlinepubs/7908799/toc.htm)`_XOPEN_VERSION` = 500X/Open Single UNIX Specification, Version 2 (UNIX98)[SUSv3](http://www.opengroup.org/onlinepubs/007904975/nfindex.html)`_XOPEN_VERSION` = 600Open Group Single UNIX Specification, Version 3 (UNIX03)[SUSv4](http://pubs.opengroup.org/onlinepubs/9699919799/)`_XOPEN_VERSION` = 700Open Group Single UNIX Specification, Version 4LSB`__LSB_VERSION__` = VRLinux Standards Base

> > V = Version  
> > R = Revision

==&gt; This seems to be good lead to (but somewhat outdated) compiler identification macros (<https://sourceforge.net/p/predef/wiki/Compilers/>)?

==&gt; This seems to be the macros supposedly defined for Clang?

> > ## [Clang](http://en.wikipedia.org/wiki/Clang)

> > TypeMacroFormatIdentification`__clang__`Version`__clang_major__`VersionVersion`__clang_minor__`RevisionVersion`__clang_patchlevel__`Patch  
> > Notice that clang also defines the GNU C version macros, but you should use the clang [feature checking macros](http://clang.llvm.org/docs/LanguageExtensions.html#feature_check) to detect the availability of various features.  
> > The values of the `__clang_major__`, `__clang_minor__`, and `__clang_patchlevel__` macros are not consistent across distributions of the Clang compiler. For example, the Clang 3.1 distribution available at [http://clang.llvm.org](http://clang.llvm.org/) defines `__clang_major__` and `__clang_minor__` as `3` and `1` respectively. The version of Clang distributed with Apple XCode 4.4 is branded as "Apple Clang 4.0" and derives from the open source Clang 3.1 distribution, but defines these macros with the values `4`and `0` respectively. Apple's Clang distribution can be identified by the presence of the `__apple_build_version__` macro.

==&gt; This seems to be the macros supposedly defined for Gcc?

> > ## [GCC C/C++](http://en.wikipedia.org/wiki/GNU_Compiler_Collection)

> > TypeMacroDescriptionIdentification`__GNUC__`Version`__GNUC__`VersionVersion`__GNUC_MINOR__`RevisionVersion`__GNUC_PATCHLEVEL__`Patch (introduced in version 3.0)  
> > Notice that the meaning of the `__GNUC__` macro has changed subtly over the years, from identifying the GNU C/C++ compiler to identifying any compiler that implements the GNU compiler extensions (see the [Feature request - a macro defined for GCC](http://gcc.gnu.org/ml/gcc/2008-07/threads.html#00025)discussion for further information). For example, the Intel C++ on Linux also defines these macros from version 8.1 (see the [Intel C++ Compiler 8.1 for Linux Release Notes](ftp://download.intel.com/support/performancetools/c/linux/sb/clin81_relnotes.pdf) and [Intel Compilers for Linux: Compatibility with GNU Compilers](http://software.intel.com/en-us/articles/intel-compilers-for-linux-compatibility-with-gnu-compilers).)

==&gt; This seems to be the macros supposedly defined for Visual Studio?

> > ## [Microsoft Visual C++](http://en.wikipedia.org/wiki/Visual_studio)

> > TypeMacroFormatDescriptionIdentification`_MSC_VER`Version`_MSC_VER`VVRRVV = Version  
> > RR = RevisionVersion`_MSC_FULL_VER`VVRRPPPPVV = Version  
> > RR = Revision  
> > PPPP = Patch

> > From Visual C++ 6.0 Processor PackVersion`_MSC_FULL_VER`VVRRPPPPPVV = Version  
> > RR = Revision  
> > PPPPP = Patch

> > From Visual C++ 8.0Version`_MSC_BUILD`BB = Build number

> > From Visual C++ 9.0

==&gt; This may be good leads to (but somewhat outdated) C and C++ library standard identification macros (<https://sourceforge.net/p/predef/wiki/Libraries/>)?

==&gt; This seem to be the supposedly settings for the Dinkumware C++ standard library??

> > ## Standard C++ Libraries

> > ### [Dinkumware](http://en.wikipedia.org/wiki/Dinkumware)

> > ### TypeMacroFormatDescriptionIdentification`_CPPLIB_VER`Defined for Dinkumware 2.0 and laterVersion`_CPPLIB_VER`VVRRVV = Version  
> > RR = Revision



==&gt; This seem to be the supposedly settings for the GCC Libc++?

> > ### [GNU libstdc++](http://gcc.gnu.org/libstdc++/)

  
> > One of the standard header files must be included before any of the following macros are defined.  
> > TypeMacroFormatDescriptionVersion`__GLIBCPP__`YYYYMMDDYYYY = Year  
> > MM = Month  
> > DD = Day

> > From GCC 3.0.0 until GCC 3.4.0Version`__GLIBCXX__`YYYYMMDDYYYY = Year  
> > MM = Month  
> > DD = Day

> > From GCC 3.4.0

==&gt; This seem to be the supposedly settings for the Clang libc++ (<http://libcxx.llvm.org/docs/>)?

==&gt; NOTE: As 160802 libc++ is available only on MacOS and FreeBSD (NOT Windows and Linux Yet?

> > *“Platform Support*

> > *libc++ is known to work on the following platforms, using g++-4.2 and clang (lack of C++11 language support disables some functionality). Note that functionality provided by &lt;atomic&gt; is only functional with clang.*

> > *• Mac OS X i386*

> > *• Mac OS X x86_64*

> > *• FreeBSD 10+ i386*

> > *• FreeBSD 10+ x86_64*

> > *• FreeBSD 10+ ARM"*

==&gt; This seem to be the documentation on using libc++ (<http://libcxx.llvm.org/docs/UsingLibcxx.html>)?

==&gt; NOTE: It seems unclear how and if it is possible to detect if and what version of clang libc++ included headers are for?

**WE ARE HERE...**

==&gt; This seem to be a (somewhat outdated) try to define platform identification macros (<https://sourceforge.net/p/predef/wiki/OperatingSystems/>)?

> > ## [Windows](http://en.wikipedia.org/wiki/Category:Microsoft_Windows)

> > TypeMacroDescriptionIdentification`_WIN16`Defined for 16-bit environments [1](http://msdn.microsoft.com/en-us/library/ff540443.aspx)Identification`_WIN32`Defined for both 32-bit and 64-bit environments [1](http://msdn.microsoft.com/en-us/library/ff540443.aspx)Identification`_WIN64`Defined for 64-bit environments [1](http://msdn.microsoft.com/en-us/library/ff540443.aspx)Identification`__WIN32__`Defined by Borland C++Identification`__TOS_WIN__`Defined by xlCIdentification`__WINDOWS__`Defined by Watcom C/C++

> > ## [UNIX Environment](http://en.wikipedia.org/wiki/Unix)

> > TypeMacroIdentification`__unix__`Identification`__unix

> > `

==&gt; This is the supposedly set macros set for GNU Linux?

> > ## [GNU/Linux](http://en.wikipedia.org/wiki/GNU/Linux)

> > TypeMacroIdentification`__gnu_linux__

> > `

==&gt; This is the supposedly set macros set for Android?

> > ## [Android](http://en.wikipedia.org/wiki/Android_%28operating_system%29)

> > TypeMacroFormatDescriptionIdentification`__ANDROID__`Version`__ANDROID_API__`VV = API Version

> > Must be included from `&lt;android/api-level.h&gt;

> > `

==&gt; This is the supposedly set macros set for freeBSD (See Clang support)?

> > ## [FreeBSD](http://en.wikipedia.org/wiki/Freebsd)

> > TypeMacroFormatDescriptionIdentification`__FreeBSD__`Identification`__FreeBSD_kernel__`From FreeBSD 8.3, 9.1, and 10.0.[1](http://svnweb.freebsd.org/base/head/sys/sys/param.h?view=markup)Version`BSD`Version`__FreeBSD__`VV = VersionVersion`__FreeBSD_version`?Must be included from `&lt;osreldate.h&gt;

> > `

==&gt;

> > ## [MacOS](http://en.wikipedia.org/wiki/Mac_OS)

> > TypeMacroDescriptionIdentification`macintosh`Mac OS 9Identification`Macintosh`Mac OS 9Identification`__APPLE__` `&&` `__MACH__`Mac OS X

> > Defined by GNU C and Intel C++

…

Consider to delve deeper into these options and update if interesting information is found?

...

{% endraw %}
