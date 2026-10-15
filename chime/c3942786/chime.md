# Todo: C++ - Consider to design good ways to get C++17 (GCC, LLVM/Clang,...) tool chain and library on major platforms (MAC OS, Linux, Windows 10) of mine?

```#c3942786``` *As of 2017-03-08 16:58*

[mail plain/text](mail.txt)

{% raw %}
So, what ways can we get to work to obtain working C++17 tool chains on the major platforms MAC OS, Linux MATE and Windows 10?

==&gt; Also see ”[Todo: Programming - Consider the C++ cross platform tool-chain and front-end/back-end options options?](../5d4c0bbb/chime.md)”

==&gt; Also see ”[Todo: Programming - Consider to generate CMake C++ Console project cross platform MacOS, Linix MAKET and Microsoft Visual Studio?](../06fb30da/chime.md)”

==&gt; Also see ”[Todo: Programming - Consider the best way to install and keep updated the llvm tool-chain on Linux?](../1fccd5dd/chime.md)"

1) Consider gcc-7 on MAC OS?

==&gt; It seems one can install latest gcc experimental with brew (<http://stackoverflow.com/questions/39091173/how-to-enable-c17-on-mac>)?

==&gt; It seems I have already done this on my 17” laptop?

> kjell-olov-hogdahls-macbook-pro:bin kjell-olovhogdahl$ **pwd**  
> **/usr/local/bin**  
> kjell-olov-hogdahls-macbook-pro:bin kjell-olovhogdahl$ **ls -la gcc\*  
> **lrwxr-xr-x 1 kjell-olovhogdahl admin 37 11 Jan 23:22 **gcc-7 -&gt; ../Cellar/gcc/HEAD-244334_1/bin/gcc-7**  
> lrwxr-xr-x 1 kjell-olovhogdahl admin 40 11 Jan 23:22 gcc-ar-7 -&gt; ../Cellar/gcc/HEAD-244334_1/bin/gcc-ar-7  
> lrwxr-xr-x 1 kjell-olovhogdahl admin 40 11 Jan 23:22 gcc-nm-7 -&gt; ../Cellar/gcc/HEAD-244334_1/bin/gcc-nm-7  
> lrwxr-xr-x 1 kjell-olovhogdahl admin 44 11 Jan 23:22 gcc-ranlib-7 -&gt; ../Cellar/gcc/HEAD-244334_1/bin/gcc-ranlib-7  
> kjell-olov-hogdahls-macbook-pro:bin kjell-olovhogdahl$

==&gt; It seems to work if I provide the c++ library to link with (<http://stackoverflow.com/questions/172587/what-is-the-difference-between-g-and-gcc>)?

> **$ gcc-7 -lstdc++ main.cpp**

==&gt; NOTE: The GCC 7 does not seem to install a ”++” variant?

2) Consider latest Clang/LLVM on MAC OS?

==&gt; Consider this page on how to get and build latest LLVM from Git Mirror (<http://llvm.org/docs/GettingStarted.html#git-mirror>)?

> kjell-olov-hogdahls-macbook-pro:GitHub kjell-olovhogdahl$ **./llvm_me.sh**  
> Cloning into 'llvm'...  
> remote: Counting objects: 1321056, done.  
> remote: Compressing objects: 100% (339499/339499), done.  
> remote: Total 1321056 (delta 1093862), reused 1202660 (delta 976633)  
> Receiving objects: 100% (1321056/1321056), 235.95 MiB | 251.00 KiB/s, done.  
> Resolving deltas: 100% (1093862/1093862), done.  
> Checking out files: 100% (24664/24664), done.  
> Cloning into 'clang'...  
> remote: Counting objects: 626278, done.  
> remote: Compressing objects: 100% (126902/126902), done.  
> remote: Total 626278 (delta 529913), reused 588290 (delta 493072)  
> Receiving objects: 100% (626278/626278), 99.60 MiB | 244.00 KiB/s, done.  
> Resolving deltas: 100% (529913/529913), done.  
> Checking out files: 100% (13683/13683), done.  
> Cloning into 'libcxx'...  
> remote: Counting objects: 64225, done.  
> remote: Compressing objects: 100% (18638/18638), done.  
> remote: Total 64225 (delta 50597), reused 57570 (delta 44405)  
> Receiving objects: 100% (64225/64225), 12.08 MiB | 228.00 KiB/s, done.  
> Resolving deltas: 100% (50597/50597), done.  
> kjell-olov-hogdahls-macbook-pro:GitHub kjell-olovhogdahl$

==&gt; This seems to be the result of generating XCode build environment?

> kjell-olov-hogdahls-macbook-pro:GitHub kjell-olovhogdahl$ ./llvm_me.sh  
> fatal: not in a git directory  
> -- The C compiler identification is AppleClang 8.0.0.8000042  
> -- The CXX compiler identification is AppleClang 8.0.0.8000042  
> -- The ASM compiler identification is AppleClang  
> -- Found assembler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  
> -- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  
> -- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc -- works  
> -- Detecting C compiler ABI info  
> -- Detecting C compiler ABI info - done  
> -- Detecting C compile features  
> -- Detecting C compile features - done  
> -- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  
> -- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ -- works  
> -- Detecting CXX compiler ABI info  
> -- Detecting CXX compiler ABI info - done  
> -- Detecting CXX compile features  
> -- Detecting CXX compile features - done  
> -- No build type selected, default to Debug  
> -- Found libtool - /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/libtool  
> -- Looking for dirent.h  
> -- Looking for dirent.h - found  
> -- Looking for dlfcn.h  
> -- Looking for dlfcn.h - found  
> -- Looking for errno.h  
> -- Looking for errno.h - found  
> -- Looking for execinfo.h  
> -- Looking for execinfo.h - found  
> -- Looking for fcntl.h  
> -- Looking for fcntl.h - found  
> -- Looking for inttypes.h  
> -- Looking for inttypes.h - found  
> -- Looking for link.h  
> -- Looking for link.h - not found  
> -- Looking for malloc.h  
> -- Looking for malloc.h - not found  
> -- Looking for malloc/malloc.h  
> -- Looking for malloc/malloc.h - found  
> -- Looking for ndir.h  
> -- Looking for ndir.h - not found  
> -- Looking for pthread.h  
> -- Looking for pthread.h - found  
> -- Looking for signal.h  
> -- Looking for signal.h - found  
> -- Looking for stdint.h  
> -- Looking for stdint.h - found  
> -- Looking for sys/dir.h  
> -- Looking for sys/dir.h - found  
> -- Looking for sys/ioctl.h  
> -- Looking for sys/ioctl.h - found  
> -- Looking for sys/mman.h  
> -- Looking for sys/mman.h - found  
> -- Looking for sys/ndir.h  
> -- Looking for sys/ndir.h - not found  
> -- Looking for sys/param.h  
> -- Looking for sys/param.h - found  
> -- Looking for sys/resource.h  
> -- Looking for sys/resource.h - found  
> -- Looking for sys/stat.h  
> -- Looking for sys/stat.h - found  
> -- Looking for sys/time.h  
> -- Looking for sys/time.h - found  
> -- Looking for sys/types.h  
> -- Looking for sys/types.h - found  
> -- Looking for sys/uio.h  
> -- Looking for sys/uio.h - found  
> -- Looking for termios.h  
> -- Looking for termios.h - found  
> -- Looking for unistd.h  
> -- Looking for unistd.h - found  
> -- Looking for valgrind/valgrind.h  
> -- Looking for valgrind/valgrind.h - not found  
> -- Looking for zlib.h  
> -- Looking for zlib.h - found  
> -- Looking for fenv.h  
> -- Looking for fenv.h - found  
> -- Looking for FE_ALL_EXCEPT  
> -- Looking for FE_ALL_EXCEPT - found  
> -- Looking for FE_INEXACT  
> -- Looking for FE_INEXACT - found  
> -- Looking for mach/mach.h  
> -- Looking for mach/mach.h - found  
> -- Looking for histedit.h  
> -- Looking for histedit.h - found  
> -- Looking for CrashReporterClient.h  
> -- Looking for CrashReporterClient.h - not found  
> -- Performing Test HAVE_CRASHREPORTER_INFO  
> -- Performing Test HAVE_CRASHREPORTER_INFO - Success  
> -- Looking for pthread_create in pthread  
> -- Looking for pthread_create in pthread - found  
> -- Looking for pthread_getspecific in pthread  
> -- Looking for pthread_getspecific in pthread - found  
> -- Looking for pthread_rwlock_init in pthread  
> -- Looking for pthread_rwlock_init in pthread - found  
> -- Looking for pthread_mutex_lock in pthread  
> -- Looking for pthread_mutex_lock in pthread - found  
> -- Looking for dlopen in dl  
> -- Looking for dlopen in dl - found  
> -- Looking for clock_gettime in rt  
> -- Looking for clock_gettime in rt - not found  
> -- Looking for pthread.h  
> -- Looking for pthread.h - found  
> -- Looking for pthread_create  
> -- Looking for pthread_create - found  
> -- Found Threads: TRUE  
> -- Looking for compress2 in z  
> -- Looking for compress2 in z - found  
> -- Looking for el_init in edit  
> -- Looking for el_init in edit - found  
> -- Looking for setupterm in tinfo  
> -- Looking for setupterm in tinfo - not found  
> -- Looking for setupterm in terminfo  
> -- Looking for setupterm in terminfo - not found  
> -- Looking for setupterm in curses  
> -- Looking for setupterm in curses - found  
> -- Looking for xar_open in xar  
> -- Looking for xar_open in xar - found  
> -- Looking for arc4random  
> -- Looking for arc4random - found  
> -- Looking for backtrace  
> -- Looking for backtrace - found  
> -- Looking for _Unwind_Backtrace  
> -- Looking for _Unwind_Backtrace - found  
> -- Looking for getpagesize  
> -- Looking for getpagesize - found  
> -- Looking for sysconf  
> -- Looking for sysconf - found  
> -- Looking for getrusage  
> -- Looking for getrusage - found  
> -- Looking for setrlimit  
> -- Looking for setrlimit - found  
> -- Looking for isatty  
> -- Looking for isatty - found  
> -- Looking for futimens  
> -- Looking for futimens - not found  
> -- Looking for futimes  
> -- Looking for futimes - found  
> -- Looking for posix_fallocate  
> -- Looking for posix_fallocate - not found  
> -- Looking for writev  
> -- Looking for writev - found  
> -- Looking for lseek64  
> -- Looking for lseek64 - not found  
> -- Looking for mallctl  
> -- Looking for mallctl - not found  
> -- Looking for mallinfo  
> -- Looking for mallinfo - not found  
> -- Looking for malloc_zone_statistics  
> -- Looking for malloc_zone_statistics - found  
> -- Looking for mkdtemp  
> -- Looking for mkdtemp - found  
> -- Looking for mkstemp  
> -- Looking for mkstemp - found  
> -- Looking for mktemp  
> -- Looking for mktemp - found  
> -- Looking for getcwd  
> -- Looking for getcwd - found  
> -- Looking for gettimeofday  
> -- Looking for gettimeofday - found  
> -- Looking for getrlimit  
> -- Looking for getrlimit - found  
> -- Looking for posix_spawn  
> -- Looking for posix_spawn - found  
> -- Looking for pread  
> -- Looking for pread - found  
> -- Looking for realpath  
> -- Looking for realpath - found  
> -- Looking for sbrk  
> -- Looking for sbrk - found  
> -- Looking for strtoll  
> -- Looking for strtoll - found  
> -- Looking for strerror  
> -- Looking for strerror - found  
> -- Looking for strerror_r  
> -- Looking for strerror_r - found  
> -- Looking for strerror_s  
> -- Looking for strerror_s - not found  
> -- Looking for setenv  
> -- Looking for setenv - found  
> -- Looking for dlopen  
> -- Looking for dlopen - found  
> -- Looking for dladdr  
> -- Looking for dladdr - found  
> -- Looking for __GLIBC__  
> -- Looking for __GLIBC__ - not found  
> -- Looking for pthread_getname_np in pthread  
> -- Looking for pthread_getname_np in pthread - found  
> -- Looking for pthread_setname_np in pthread  
> -- Looking for pthread_setname_np in pthread - found  
> -- Performing Test HAVE_INT64_T  
> -- Performing Test HAVE_INT64_T - Success  
> -- Performing Test HAVE_UINT64_T  
> -- Performing Test HAVE_UINT64_T - Success  
> -- Performing Test HAVE_U_INT64_T  
> -- Performing Test HAVE_U_INT64_T - Success  
> -- Performing Test HAVE_CXX_ATOMICS_WITHOUT_LIB  
> -- Performing Test HAVE_CXX_ATOMICS_WITHOUT_LIB - Success  
> -- Performing Test HAVE_CXX_ATOMICS64_WITHOUT_LIB  
> -- Performing Test HAVE_CXX_ATOMICS64_WITHOUT_LIB - Success  
> -- Performing Test LLVM_HAS_ATOMICS  
> -- Performing Test LLVM_HAS_ATOMICS - Success  
> -- Performing Test SUPPORTS_VARIADIC_MACROS_FLAG  
> -- Performing Test SUPPORTS_VARIADIC_MACROS_FLAG - Success  
> -- Performing Test SUPPORTS_GNU_ZERO_VARIADIC_MACRO_ARGUMENTS_FLAG  
> -- Performing Test SUPPORTS_GNU_ZERO_VARIADIC_MACRO_ARGUMENTS_FLAG - Success  
> -- Native target architecture is X86  
> -- Threads enabled.  
> -- Doxygen disabled.  
> -- Sphinx disabled.  
> -- Go bindings disabled.  
> -- Found ld64 - /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ld  
> -- Could NOT find OCaml (missing: OCAMLFIND OCAML_VERSION OCAML_STDLIB_PATH)  
> -- Could NOT find OCaml (missing: OCAMLFIND OCAML_VERSION OCAML_STDLIB_PATH)  
> -- OCaml bindings disabled.  
> -- LLVM host triple: x86_64-apple-darwin15.6.0  
> -- LLVM default target triple: x86_64-apple-darwin15.6.0  
> -- Performing Test C_SUPPORTS_FPIC  
> -- Performing Test C_SUPPORTS_FPIC - Success  
> -- Performing Test CXX_SUPPORTS_FPIC  
> -- Performing Test CXX_SUPPORTS_FPIC - Success  
> -- Building with -fPIC  
> -- Performing Test SUPPORTS_FVISIBILITY_INLINES_HIDDEN_FLAG  
> -- Performing Test SUPPORTS_FVISIBILITY_INLINES_HIDDEN_FLAG - Success  
> -- Performing Test CXX_SUPPORTS_MISSING_FIELD_INITIALIZERS_FLAG  
> -- Performing Test CXX_SUPPORTS_MISSING_FIELD_INITIALIZERS_FLAG - Success  
> -- Performing Test C_SUPPORTS_COVERED_SWITCH_DEFAULT_FLAG  
> -- Performing Test C_SUPPORTS_COVERED_SWITCH_DEFAULT_FLAG - Success  
> -- Performing Test CXX_SUPPORTS_COVERED_SWITCH_DEFAULT_FLAG  
> -- Performing Test CXX_SUPPORTS_COVERED_SWITCH_DEFAULT_FLAG - Success  
> -- Performing Test CXX_WONT_WARN_ON_FINAL_NONVIRTUALDTOR  
> -- Performing Test CXX_WONT_WARN_ON_FINAL_NONVIRTUALDTOR - Success  
> -- Performing Test C_SUPPORTS_DELETE_NON_VIRTUAL_DTOR_FLAG  
> -- Performing Test C_SUPPORTS_DELETE_NON_VIRTUAL_DTOR_FLAG - Success  
> -- Performing Test CXX_SUPPORTS_DELETE_NON_VIRTUAL_DTOR_FLAG  
> -- Performing Test CXX_SUPPORTS_DELETE_NON_VIRTUAL_DTOR_FLAG - Success  
> -- Performing Test C_WCOMMENT_ALLOWS_LINE_WRAP  
> -- Performing Test C_WCOMMENT_ALLOWS_LINE_WRAP - Success  
> -- Performing Test C_SUPPORTS_STRING_CONVERSION_FLAG  
> -- Performing Test C_SUPPORTS_STRING_CONVERSION_FLAG - Success  
> -- Performing Test CXX_SUPPORTS_STRING_CONVERSION_FLAG  
> -- Performing Test CXX_SUPPORTS_STRING_CONVERSION_FLAG - Success  
> -- Performing Test C_SUPPORTS_WERROR_DATE_TIME  
> -- Performing Test C_SUPPORTS_WERROR_DATE_TIME - Success  
> -- Performing Test CXX_SUPPORTS_WERROR_DATE_TIME  
> -- Performing Test CXX_SUPPORTS_WERROR_DATE_TIME - Success  
> -- Performing Test CXX_SUPPORTS_CXX11  
> -- Performing Test CXX_SUPPORTS_CXX11 - Success  
> -- Found PythonInterp: /usr/bin/python2.7 (found version "2.7.10")  
> -- Constructing LLVMBuild project information  
> -- Targeting AArch64  
> -- Targeting AMDGPU  
> -- Targeting ARM  
> -- Targeting BPF  
> -- Targeting Hexagon  
> -- Targeting Lanai  
> -- Targeting Mips  
> -- Targeting MSP430  
> -- Targeting NVPTX  
> -- Targeting PowerPC  
> -- Targeting RISCV  
> -- Targeting Sparc  
> -- Targeting SystemZ  
> -- Targeting X86  
> -- Targeting XCore  
> -- Looking for fopen in c  
> -- Looking for fopen in c - found  
> -- Looking for __gcc_personality_v0 in gcc_s  
> -- Looking for __gcc_personality_v0 in gcc_s - not found  
> -- Performing Test LIBCXX_SUPPORTS_NODEFAULTLIBS_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_NODEFAULTLIBS_FLAG - Success  
> -- Performing Test LIBCXX_HAVE_CXX_ATOMICS_WITHOUT_LIB  
> -- Performing Test LIBCXX_HAVE_CXX_ATOMICS_WITHOUT_LIB - Success  
> -- Looking for __atomic_fetch_add_8 in atomic  
> -- Looking for __atomic_fetch_add_8 in atomic - not found  
> -- Performing Test LIBCXX_HAS_WX_FLAG  
> -- Performing Test LIBCXX_HAS_WX_FLAG - Failed  
> -- Performing Test LIBCXX_HAS_NO_WX_FLAG  
> -- Performing Test LIBCXX_HAS_NO_WX_FLAG - Failed  
> -- Performing Test LIBCXX_HAS_EHSC_FLAG  
> -- Performing Test LIBCXX_HAS_EHSC_FLAG - Failed  
> -- Performing Test LIBCXX_HAS_NO_EHS_FLAG  
> -- Performing Test LIBCXX_HAS_NO_EHS_FLAG - Failed  
> -- Performing Test LIBCXX_HAS_NO_EHA_FLAG  
> -- Performing Test LIBCXX_HAS_NO_EHA_FLAG - Failed  
> -- Performing Test LIBCXX_HAS_NO_GR_FLAG  
> -- Performing Test LIBCXX_HAS_NO_GR_FLAG - Failed  
> -- Looking for pthread_create in pthread  
> -- Looking for pthread_create in pthread - found  
> -- Looking for ccos in m  
> -- Looking for ccos in m - found  
> -- Looking for clock_gettime in rt  
> -- Looking for clock_gettime in rt - not found  
> -- Performing Test LIBCXX_SUPPORTS_STD_EQ_CXX11_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_STD_EQ_CXX11_FLAG - Success  
> -- Performing Test LIBCXX_SUPPORTS_NOSTDINCXX_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_NOSTDINCXX_FLAG - Success  
> -- Performing Test LIBCXX_SUPPORTS_FVISIBILITY_INLINES_HIDDEN_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_FVISIBILITY_INLINES_HIDDEN_FLAG - Success  
> -- Performing Test LIBCXX_SUPPORTS_WALL_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_WALL_FLAG - Success  
> -- Performing Test LIBCXX_SUPPORTS_WEXTRA_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_WEXTRA_FLAG - Success  
> -- Performing Test LIBCXX_SUPPORTS_W_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_W_FLAG - Success  
> -- Performing Test LIBCXX_SUPPORTS_WWRITE_STRINGS_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_WWRITE_STRINGS_FLAG - Success  
> -- Performing Test LIBCXX_SUPPORTS_WNO_UNUSED_PARAMETER_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_WNO_UNUSED_PARAMETER_FLAG - Success  
> -- Performing Test LIBCXX_SUPPORTS_WNO_LONG_LONG_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_WNO_LONG_LONG_FLAG - Success  
> -- Performing Test LIBCXX_SUPPORTS_WERROR_EQ_RETURN_TYPE_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_WERROR_EQ_RETURN_TYPE_FLAG - Success  
> -- Performing Test LIBCXX_SUPPORTS_WNO_USER_DEFINED_LITERALS_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_WNO_USER_DEFINED_LITERALS_FLAG - Success  
> -- Performing Test LIBCXX_SUPPORTS_WNO_COVERED_SWITCH_DEFAULT_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_WNO_COVERED_SWITCH_DEFAULT_FLAG - Success  
> -- Performing Test LIBCXX_SUPPORTS_WNO_ERROR_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_WNO_ERROR_FLAG - Success  
> -- Performing Test LIBCXX_SUPPORTS_EHSC_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_EHSC_FLAG - Failed  
> -- Performing Test LIBCXX_SUPPORTS_FPIC_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_FPIC_FLAG - Success  
> -- Found SDK version 10.12  
> -- Performing Test LIBCXX_SUPPORTS_STD_EQ_CXX14_FLAG  
> -- Performing Test LIBCXX_SUPPORTS_STD_EQ_CXX14_FLAG - Success  
> -- Adding Benchmark: algorithms.bench.cpp  
> -- Adding Benchmark: filesystem.bench.cpp  
> -- Adding Benchmark: string.bench.cpp  
> -- Adding Benchmark: unordered_set_operations.bench.cpp  
> -- Adding Benchmark: util_smartptr.bench.cpp  
> -- Adding Benchmark: vector_operations.bench.cpp  
> -- libc++ configuration differs from the abilist configuration. check-cxx-abilist target is not supported  
> -- Looking for sys/resource.h  
> -- Looking for sys/resource.h - found  
> -- Clang version: 5.0.0  
> -- Performing Test CXX_SUPPORTS_NO_NESTED_ANON_TYPES_FLAG  
> -- Performing Test CXX_SUPPORTS_NO_NESTED_ANON_TYPES_FLAG - Success  
> -- Configuring done  
> -- Generating done  
> -- Build files have been written to: /Users/kjell-olovhogdahl/Documents/GitHub/build_llvm  
> kjell-olov-hogdahls-macbook-pro:GitHub kjell-olovhogdahl$

==&gt; install after build seems to succeed (although the installation is made anonymous = NO VERSION NUMBER)?

==&gt; Q: Did this install corrupt any previous clang/llvm installation?

> ...  
> -- Up-to-date: /usr/local/bin/clang-5.0  
> -- Up-to-date: /usr/local/bin/clang  
> Creating clang++  
> Creating clang-cl  
> Creating clang-cpp  
> ...

## Attachments

- [llvm head MAC OS build and install.rtf](<llvm head MAC OS build and install.rtf>)

{% endraw %}
