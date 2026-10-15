# Todo: Consider to try and understand why c++ compilation on macOS results in "...wchar.h: No such file or directory"

```#24349627``` *As of 2022-11-05 15:31*

[mail plain/text](mail.txt)

{% raw %}
0) Consider the "bottom line" for what the problem is and how to fix it?

==&gt; It seems the "correct" way to tell both gcc and clang about the tool chain paths are to set the environment variable SDKROOT before running XCode?

NOTE: Setting the SDKROOT with the export command does NOT STICK to the global environment (We need to do it in current terminal session before starting XCode in that session)

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit % **export SDKROOT=\`xcrun --show-sdk-path\`**  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit % **env**  
> TERM_PROGRAM=Apple_Terminal  
> SHELL=/bin/zsh  
> TERM=xterm-256color  
> TMPDIR=/var/folders/h1/w8wsr9316md0l3jtptr9wnx80000gn/T/  
> TERM_PROGRAM_VERSION=445  
> TERM_SESSION_ID=3E506958-C2D6-4103-AE36-FF9AB7F68653  
> USER=kjell-olovhogdal  
> SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.tPSakAja9x/Listeners  
> PATH=/opt/local/bin:/opt/local/sbin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/TeX/texbin:/Library/Apple/usr/bin:/Users/kjell-olovhogdal/Documents/Github/nudge:/usr/local/Cellar/llvm/13.0.1_1/bin  
> __CFBundleIdentifier=com.apple.Terminal  
> PWD=/Users/kjell-olovhogdal/Documents/Github/cratchit  
> XPC_FLAGS=0x0  
> XPC_SERVICE_NAME=0  
> SHLVL=1  
> HOME=/Users/kjell-olovhogdal  
> LOGNAME=kjell-olovhogdal  
> OLDPWD=/Users/kjell-olovhogdal/Documents/Github/cratchit  
> **SDKROOT=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk**  
> LC_CTYPE=UTF-8  
> _=/usr/bin/env  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit % **code .**

==&gt; With xcrun on macOS it seems we can retrieve the path to the current SDK

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit % **xcrun --show-sdk-path**  
> /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit %

==&gt; And now it seems we can tell gcc how to find the OS framework specific includes and libraries (<https://gcc.gnu.org/onlinedocs/gcc/Directory-Options.html#Directory-Options> )?

> "*--sysroot=dir*  
> *Use dir as the logical root directory for headers and libraries. For example, if the compiler normally searches for headers in /usr/include and libraries in /usr/lib, it instead searches dir/usr/include and dir/usr/lib.*"

==&gt; With XCode installed this poath to the SDK worked for me.

> --sysroot=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk

==&gt; With macOS Command Line Tools installed this alternative path also worked

> --sysroot=/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk

==&gt; Also see this thread "gcc10 missing header &lt;wchar.h&gt;" (<https://trac.macports.org/ticket/60449> )?

> *"**this is likely due to the removal of /usr/include*

> *Like clang, gcc now respects your SDKROOT setting, so this is the recommendation now. i.e.

> export SDKROOT=\`xcrun --show-sdk-path\`**"*

1) Consider the clang++ -v src/main.cpp

==&gt; The macOS XCode clang compiler DOES find ALL include files (NO "no such file or directory" error)

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit % clang++ -v src/main.cpp  
> Apple clang version 13.1.6 (clang-1316.0.21.2)  
> Target: x86_64-apple-darwin21.3.0  
> Thread model: posix  
> InstalledDir: /Library/Developer/CommandLineTools/usr/bin  
> "/Library/Developer/CommandLineTools/usr/bin/clang" -cc1 -triple x86_64-apple-macosx12.0.0 -Wundef-prefix=TARGET_OS_ -Wdeprecated-objc-isa-usage -Werror=deprecated-objc-isa-usage -Werror=implicit-function-declaration -emit-obj -mrelax-all --mrelax-relocations -disable-free -disable-llvm-verifier -discard-value-names -main-file-name main.cpp -mrelocation-model pic -pic-level 2 -mframe-pointer=all -fno-strict-return -fno-rounding-math -munwind-tables -target-sdk-version=12.3 -fvisibility-inlines-hidden-static-local-var -target-cpu penryn -tune-cpu generic -debugger-tuning=lldb -target-linker-version 762 -v -resource-dir /Library/Developer/CommandLineTools/usr/lib/clang/13.1.6 -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -stdlib=libc++ -internal-isystem /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1 -internal-isystem /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/local/include -internal-isystem /Library/Developer/CommandLineTools/usr/lib/clang/13.1.6/include -internal-externc-isystem /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include -internal-externc-isystem /Library/Developer/CommandLineTools/usr/include -Wno-reorder-init-list -Wno-implicit-int-float-conversion -Wno-c99-designator -Wno-final-dtor-non-final-class -Wno-extra-semi-stmt -Wno-misleading-indentation -Wno-quoted-include-in-framework-header -Wno-implicit-fallthrough -Wno-enum-enum-conversion -Wno-enum-float-conversion -Wno-elaborated-enum-base -Wno-reserved-identifier -Wno-gnu-folding-constant -Wno-objc-load-method -fdeprecated-macro -fdebug-compilation-dir=/Users/kjell-olovhogdal/Documents/Github/cratchit -ferror-limit 19 -stack-protector 1 -fstack-check -mdarwin-stkchk-strong-link -fblocks -fencode-extended-block-signature -fregister-global-dtors-with-atexit -fgnuc-version=4.2.1 -fno-cxx-modules -fcxx-exceptions -fexceptions -fmax-type-align=16 -fcommon -fcolor-diagnostics -clang-vendor-feature=+messageToSelfInClassMethodIdReturnType -clang-vendor-feature=+disableInferNewAvailabilityFromInit -clang-vendor-feature=+disableNonDependentMemberExprInCurrentInstantiation -fno-odr-hash-protocols -clang-vendor-feature=+enableAggressiveVLAFolding -clang-vendor-feature=+revert09abecef7bbf -clang-vendor-feature=+thisNoAlignAttr -clang-vendor-feature=+thisNoNullAttr -mllvm -disable-aligned-alloc-awareness=1 -D__GCC_HAVE_DWARF2_CFI_ASM=1 -o /var/folders/h1/w8wsr9316md0l3jtptr9wnx80000gn/T/main-8fef2b.o -x c++ src/main.cpp  
> clang -cc1 version 13.1.6 (clang-1316.0.21.2) default target x86_64-apple-darwin21.3.0  
> ignoring nonexistent directory "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/local/include"  
> ignoring nonexistent directory "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/Library/Frameworks"  
> #include "..." search starts here:  
> #include &lt;...&gt; search starts here:  
> **/usr/local/include**  
> **/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1**  
> **/Library/Developer/CommandLineTools/usr/lib/clang/13.1.6/include**  
> **/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include**  
> **/Library/Developer/CommandLineTools/usr/include**  
> **/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks (framework directory)**  
> End of search list.

2) Consider the /usr/local/bin/g++-11 -v src/main.cpp

==&gt; The Brew installed g++-11 does NOT find required include files (incomplete list of search paths?)

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit % /usr/local/bin/g++-11 -v src/main.cpp  
> Using built-in specs.  
> COLLECT_GCC=/usr/local/bin/g++-11  
> COLLECT_LTO_WRAPPER=/usr/local/Cellar/gcc/11.2.0_3/libexec/gcc/x86_64-apple-darwin19/11/lto-wrapper  
> Target: x86_64-apple-darwin19  
> Configured with: ../configure --prefix=/usr/local/Cellar/gcc/11.2.0_3 --libdir=/usr/local/Cellar/gcc/11.2.0_3/lib/gcc/11 --disable-nls --enable-checking=release --with-gcc-major-version-only --enable-languages=c,c++,objc,obj-c++,fortran,d --program-suffix=-11 --with-gmp=/usr/local/opt/gmp --with-mpfr=/usr/local/opt/mpfr --with-mpc=/usr/local/opt/libmpc --with-isl=/usr/local/opt/isl --with-zstd=/usr/local/opt/zstd --with-pkgversion='Homebrew GCC 11.2.0_3' --with-bugurl=<https://github.com/Homebrew/homebrew-core/issues> --enable-libphobos --build=x86_64-apple-darwin19 --with-system-zlib --disable-multilib --with-native-system-header-dir=/usr/include --with-sysroot=/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk  
> Thread model: posix  
> Supported LTO compression algorithms: zlib zstd  
> gcc version 11.2.0 (Homebrew GCC 11.2.0_3)  
> COLLECT_GCC_OPTIONS='-v' '-mmacosx-version-min=12.2.0' '-asm_macosx_version_min=12.2' '-shared-libgcc' '-mtune=core2' '-dumpdir' 'a-'  
> /usr/local/Cellar/gcc/11.2.0_3/libexec/gcc/x86_64-apple-darwin19/11/cc1plus -quiet -v -D__DYNAMIC__ src/main.cpp -fPIC -quiet -dumpdir a- -dumpbase main.cpp -dumpbase-ext .cpp -mmacosx-version-min=12.2.0 -mtune=core2 -version -o /var/folders/h1/w8wsr9316md0l3jtptr9wnx80000gn/T//ccYBoSS3.s  
> GNU C++17 (Homebrew GCC 11.2.0_3) version 11.2.0 (x86_64-apple-darwin19)  
> compiled by GNU C version 11.2.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

> GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072  
> ignoring nonexistent directory "/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/local/include"  
> ignoring nonexistent directory "/usr/local/Cellar/gcc/11.2.0_3/lib/gcc/11/gcc/x86_64-apple-darwin19/11/../../../../../../x86_64-apple-darwin19/include"  
> ignoring nonexistent directory "/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include"  
> ignoring nonexistent directory "/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/System/Library/Frameworks"  
> ignoring nonexistent directory "/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/Library/Frameworks"  
> #include "..." search starts here:  
> #include &lt;...&gt; search starts here:  
> **/usr/local/Cellar/gcc/11.2.0_3/lib/gcc/11/gcc/x86_64-apple-darwin19/11/../../../../../../include/c++/11**  
> **/usr/local/Cellar/gcc/11.2.0_3/lib/gcc/11/gcc/x86_64-apple-darwin19/11/../../../../../../include/c++/11/x86_64-apple-darwin19**  
> **/usr/local/Cellar/gcc/11.2.0_3/lib/gcc/11/gcc/x86_64-apple-darwin19/11/../../../../../../include/c++/11/backward**  
> **/usr/local/Cellar/gcc/11.2.0_3/lib/gcc/11/gcc/x86_64-apple-darwin19/11/include**  
> **/usr/local/Cellar/gcc/11.2.0_3/lib/gcc/11/gcc/x86_64-apple-darwin19/11/include-fixed**  
> End of search list.

3) Consider the /usr/local/Cellar/llvm/13.0.1_1/bin/clang++ -v src/main.cpp

==&gt; The brew installed clang-13 DOES find ALL include files (NO "no such file or directory" error)

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit % /usr/local/Cellar/llvm/13.0.1_1/bin/clang++ -v src/main.cpp  
> Homebrew clang version 13.0.1  
> Target: x86_64-apple-darwin21.3.0  
> Thread model: posix  
> InstalledDir: /usr/local/Cellar/llvm/13.0.1_1/bin  
> "/usr/local/Cellar/llvm/13.0.1_1/bin/clang-13" -cc1 -triple x86_64-apple-macosx12.0.0 -Wundef-prefix=TARGET_OS_ -Werror=undef-prefix -Wdeprecated-objc-isa-usage -Werror=deprecated-objc-isa-usage -emit-obj -mrelax-all --mrelax-relocations -disable-free -disable-llvm-verifier -discard-value-names -main-file-name main.cpp -mrelocation-model pic -pic-level 2 -mframe-pointer=all -fno-rounding-math -munwind-tables -fcompatibility-qualified-id-block-type-checking -fvisibility-inlines-hidden-static-local-var -target-cpu penryn -tune-cpu generic -debugger-tuning=lldb -target-linker-version 711 -v -fcoverage-compilation-dir=/Users/kjell-olovhogdal/Documents/Github/cratchit -resource-dir /usr/local/Cellar/llvm/13.0.1_1/lib/clang/13.0.1 -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX12.sdk -stdlib=libc++ -internal-isystem /usr/local/Cellar/llvm/13.0.1_1/bin/../include/c++/v1 -internal-isystem /Library/Developer/CommandLineTools/SDKs/MacOSX12.sdk/usr/local/include -internal-isystem /usr/local/Cellar/llvm/13.0.1_1/lib/clang/13.0.1/include -internal-externc-isystem /Library/Developer/CommandLineTools/SDKs/MacOSX12.sdk/usr/include -fdeprecated-macro -fdebug-compilation-dir=/Users/kjell-olovhogdal/Documents/Github/cratchit -ferror-limit 19 -stack-protector 1 -fblocks -fencode-extended-block-signature -fregister-global-dtors-with-atexit -fgnuc-version=4.2.1 -fcxx-exceptions -fexceptions -fmax-type-align=16 -fcolor-diagnostics -D__GCC_HAVE_DWARF2_CFI_ASM=1 -o /var/folders/h1/w8wsr9316md0l3jtptr9wnx80000gn/T/main-b776f3.o -x c++ src/main.cpp  
> clang -cc1 version 13.0.1 based upon LLVM 13.0.1 default target x86_64-apple-darwin21.3.0  
> ignoring nonexistent directory "/Library/Developer/CommandLineTools/SDKs/MacOSX12.sdk/usr/local/include"  
> ignoring nonexistent directory "/Library/Developer/CommandLineTools/SDKs/MacOSX12.sdk/Library/Frameworks"  
> #include "..." search starts here:  
> #include &lt;...&gt; search starts here:  
> **/usr/local/Cellar/llvm/13.0.1_1/bin/../include/c++/v1**  
> **/usr/local/Cellar/llvm/13.0.1_1/lib/clang/13.0.1/include**  
> **/Library/Developer/CommandLineTools/SDKs/MacOSX12.sdk/usr/include**  
> **/Library/Developer/CommandLineTools/SDKs/MacOSX12.sdk/System/Library/Frameworks (framework directory)**  
> End of search list.

...

{% endraw %}
