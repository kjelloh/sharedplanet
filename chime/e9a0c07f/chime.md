# Todo: Consider where the C++ standard library and headers are located on macOS?

```#e9a0c07f``` *As of 2021-11-28 20:18*

[mail plain/text](mail.txt)

{% raw %}
1) It seems to search I need to take into account that c++ headers files may ve stored without extension (and pattern xxx.\* does not match those)?

==&gt; It seems I can find many installed C++ 11 library headers in /usr/local?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % **find** -L /usr/local -name 'initializer_list\*'  
> /usr/local/include/c++/11/initializer_list  
> /usr/local/include/boost/test/data/monomorphic/initializer_list.hpp  
> /usr/local/var/homebrew/linked/boost/include/boost/test/data/monomorphic/initializer_list.hpp  
> /usr/local/var/homebrew/linked/gcc/include/c++/11/initializer_list  
> /usr/local/opt/gcc@10/include/c++/11/initializer_list  
> /usr/local/opt/gcc@11/include/c++/11/initializer_list  
> /usr/local/opt/llvm@10/include/c++/v1/initializer_list  
> /usr/local/opt/llvm@10/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/initializer_list  
> /usr/local/opt/gfortran/include/c++/11/initializer_list  
> /usr/local/opt/boost/include/boost/test/data/monomorphic/initializer_list.hpp  
> /usr/local/opt/llvm/include/c++/v1/initializer_list  
> /usr/local/opt/llvm/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/initializer_list  
> /usr/local/opt/boost@1.73/include/boost/test/data/monomorphic/initializer_list.hpp  
> /usr/local/opt/gcc/include/c++/11/initializer_list  
> /usr/local/opt/llvm@13/include/c++/v1/initializer_list  
> /usr/local/opt/llvm@13/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/initializer_list  
> /usr/local/opt/boost@1.76/include/boost/test/data/monomorphic/initializer_list.hpp  
> /usr/local/Cellar/boost/1.73.0/include/boost/test/data/monomorphic/initializer_list.hpp  
> /usr/local/Cellar/boost/1.76.0/include/boost/test/data/monomorphic/initializer_list.hpp  
> /usr/local/Cellar/llvm/13.0.0_1/include/c++/v1/initializer_list  
> /usr/local/Cellar/llvm/13.0.0_1/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/initializer_list  
> /usr/local/Cellar/gcc/10.2.0/include/c++/10.2.0/initializer_list  
> /usr/local/Cellar/gcc/11.2.0_3/include/c++/11/initializer_list  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ %

==&gt; It seems Apple installs C++ 11 library header files in /Applications?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % find -L /Applications -name 'initializer_list\*'  
> **/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1**/initializer_list  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ %

==&gt; It seems I can find C++ 17 library headers searching the same directories as above?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % find -L /usr/local -name 'memory_resource\*'  
> /usr/local/include/c++/11/experimental/memory_resource  
> /usr/local/include/c++/11/memory_resource  
> /usr/local/include/boost/container/pmr/memory_resource.hpp  
> /usr/local/include/boost/json/memory_resource.hpp  
> /usr/local/var/homebrew/linked/boost/include/boost/container/pmr/memory_resource.hpp  
> /usr/local/var/homebrew/linked/boost/include/boost/json/memory_resource.hpp  
> /usr/local/var/homebrew/linked/gcc/include/c++/11/experimental/memory_resource  
> /usr/local/var/homebrew/linked/gcc/include/c++/11/memory_resource  
> /usr/local/opt/gcc@10/include/c++/11/experimental/memory_resource  
> /usr/local/opt/gcc@10/include/c++/11/memory_resource  
> /usr/local/opt/gcc@11/include/c++/11/experimental/memory_resource  
> /usr/local/opt/gcc@11/include/c++/11/memory_resource  
> /usr/local/opt/llvm@10/include/c++/v1/experimental/memory_resource  
> /usr/local/opt/llvm@10/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/experimental/memory_resource  
> /usr/local/opt/gfortran/include/c++/11/experimental/memory_resource  
> /usr/local/opt/gfortran/include/c++/11/memory_resource  
> /usr/local/opt/boost/include/boost/container/pmr/memory_resource.hpp  
> /usr/local/opt/boost/include/boost/json/memory_resource.hpp  
> /usr/local/opt/llvm/include/c++/v1/experimental/memory_resource  
> /usr/local/opt/llvm/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/experimental/memory_resource  
> /usr/local/opt/boost@1.73/include/boost/container/pmr/memory_resource.hpp  
> /usr/local/opt/boost@1.73/include/boost/json/memory_resource.hpp  
> /usr/local/opt/gcc/include/c++/11/experimental/memory_resource  
> /usr/local/opt/gcc/include/c++/11/memory_resource  
> /usr/local/opt/llvm@13/include/c++/v1/experimental/memory_resource  
> /usr/local/opt/llvm@13/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/experimental/memory_resource  
> /usr/local/opt/boost@1.76/include/boost/container/pmr/memory_resource.hpp  
> /usr/local/opt/boost@1.76/include/boost/json/memory_resource.hpp  
> /usr/local/Cellar/boost/1.73.0/include/boost/container/pmr/memory_resource.hpp  
> /usr/local/Cellar/boost/1.76.0/include/boost/container/pmr/memory_resource.hpp  
> /usr/local/Cellar/boost/1.76.0/include/boost/json/memory_resource.hpp  
> /usr/local/Cellar/llvm/13.0.0_1/include/c++/v1/experimental/memory_resource  
> /usr/local/Cellar/llvm/13.0.0_1/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/experimental/memory_resource  
> /usr/local/Cellar/gcc/10.2.0/include/c++/10.2.0/experimental/memory_resource  
> /usr/local/Cellar/gcc/10.2.0/include/c++/10.2.0/memory_resource  
> /usr/local/Cellar/gcc/11.2.0_3/include/c++/11/experimental/memory_resource  
> /usr/local/Cellar/gcc/11.2.0_3/include/c++/11/memory_resource

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % find -L /Applications -name 'memory_resource\*'  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1/experimental/memory_resource  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ %

==&gt; It seems I can find C++ 2+ library headers searching the same directories as above?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % find -L /usr/local -name 'coroutine'  
> /usr/local/include/c++/11/coroutine  
> /usr/local/include/boost/coroutine  
> /usr/local/var/homebrew/linked/boost/include/boost/coroutine  
> /usr/local/var/homebrew/linked/gcc/include/c++/11/coroutine  
> /usr/local/opt/gcc@10/include/c++/11/coroutine  
> /usr/local/opt/gcc@11/include/c++/11/coroutine  
> /usr/local/opt/llvm@10/include/c++/v1/experimental/coroutine  
> /usr/local/opt/llvm@10/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/experimental/coroutine  
> /usr/local/opt/gfortran/include/c++/11/coroutine  
> /usr/local/opt/boost/include/boost/coroutine  
> /usr/local/opt/llvm/include/c++/v1/experimental/coroutine  
> /usr/local/opt/llvm/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/experimental/coroutine  
> /usr/local/opt/boost@1.73/include/boost/coroutine  
> /usr/local/opt/**gcc/include/c++/11**/coroutine  
> /usr/local/opt/tcl-tk/lib/tcllib1.20/coroutine  
> /usr/local/opt/llvm@13/include/c++/v1/experimental/coroutine  
> /usr/local/opt/llvm@13/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/experimental/coroutine  
> /usr/local/opt/boost@1.76/include/boost/coroutine  
> /usr/local/Cellar/boost/1.73.0/include/boost/coroutine  
> /usr/local/Cellar/boost/1.76.0/include/boost/coroutine  
> /usr/local/Cellar/**llvm/13.0.0_1**/include/c++/v1/**experimental**/coroutine  
> /usr/local/Cellar/**llvm/13.0.0_1**/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/**experimental**/coroutine  
> /usr/local/Cellar/gcc/10.2.0/include/**c++/10.2.0**/coroutine  
> /usr/local/Cellar/gcc/11.2.0_3/include/**c++/11**/coroutine  
> /usr/local/Cellar/tcl-tk/8.6.12/lib/tcllib1.20/coroutine

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % find -L /Applications -name 'coroutine'  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1/**experimental**/coroutine  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ %

==&gt; It seems C++20 &lt;ranges&gt; is part of gcc-11?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % find -L /usr/local -name 'ranges'  
> /usr/local/include/**c++/11**/ranges  
> /usr/local/var/homebrew/linked/**gcc/include/c++/11**/ranges  
> /usr/local/opt/gcc@10/include/c++/11/ranges  
> /usr/local/opt/gcc@11/include/c++/11/ranges  
> /usr/local/opt/llvm@10/include/c++/v1/ranges  
> /usr/local/opt/llvm@10/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/ranges  
> /usr/local/opt/gfortran/include/c++/11/ranges  
> /usr/local/opt/llvm/include/c++/v1/ranges  
> /usr/local/opt/llvm/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/ranges  
> /usr/local/opt/gcc/include/c++/11/ranges  
> /usr/local/opt/llvm@13/include/c++/v1/ranges  
> /usr/local/opt/llvm@13/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/ranges  
> /usr/local/Cellar/llvm/13.0.0_1/include/c++/v1/ranges  
> /usr/local/Cellar/llvm/13.0.0_1/Toolchains/LLVM13.0.0.xctoolchain/usr/include/c++/v1/ranges  
> /usr/local/Cellar/gcc/10.2.0/include/c++/10.2.0/ranges  
> /usr/local/Cellar/gcc/11.2.0_3/include/c++/11/ranges  
> /usr/local/texlive/2019/texmf-dist/doc/fonts/gnu-freefont/tools/test/ranges

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % find -L /Applications -name 'ranges'  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ %

==&gt; It seems /usr/local contains some static ".a" and dynamic ".dylib" version of clang stdc++ library?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % find -L **/usr/local** -name 'libc++\*.**a'**  
> /usr/local/opt/llvm@10/lib/libc++.a  
> /usr/local/opt/llvm@10/lib/libc++experimental.a  
> /usr/local/opt/llvm@10/lib/libc++abi.a  
> /usr/local/opt/llvm@10/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.a  
> /usr/local/opt/llvm@10/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++experimental.a  
> /usr/local/opt/llvm@10/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.a  
> /usr/local/opt/llvm/lib/libc++.a  
> /usr/local/opt/llvm/lib/libc++experimental.a  
> /usr/local/opt/llvm/lib/libc++abi.a  
> /usr/local/opt/llvm/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.a  
> /usr/local/opt/llvm/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++experimental.a  
> /usr/local/opt/llvm/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.a  
> /usr/local/opt/llvm@13/lib/libc++.a  
> /usr/local/opt/llvm@13/lib/libc++experimental.a  
> /usr/local/opt/llvm@13/lib/libc++abi.a  
> /usr/local/opt/llvm@13/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.a  
> /usr/local/opt/llvm@13/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++experimental.a  
> /usr/local/opt/llvm@13/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.a  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libc++.a  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libc++experimental.a  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libc++abi.a  
> /usr/local/Cellar/llvm/13.0.0_1/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.a  
> /usr/local/Cellar/llvm/13.0.0_1/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++experimental.a  
> /usr/local/Cellar/llvm/13.0.0_1/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.a

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % find -L **/usr/local** -name 'libc++\*.**dylib**'  
> /usr/local/opt/llvm@10/lib/libc++abi.1.0.dylib  
> /usr/local/opt/llvm@10/lib/libc++.1.0.dylib  
> /usr/local/opt/llvm@10/lib/libc++.dylib  
> /usr/local/opt/llvm@10/lib/libc++.1.dylib  
> /usr/local/opt/llvm@10/lib/libc++abi.dylib  
> /usr/local/opt/llvm@10/lib/libc++abi.1.dylib  
> /usr/local/opt/llvm@10/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.1.0.dylib  
> /usr/local/opt/llvm@10/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.1.0.dylib  
> /usr/local/opt/llvm@10/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.dylib  
> /usr/local/opt/llvm@10/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.1.dylib  
> /usr/local/opt/llvm@10/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.dylib  
> /usr/local/opt/llvm@10/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.1.dylib  
> /usr/local/opt/llvm/lib/libc++abi.1.0.dylib  
> /usr/local/opt/llvm/lib/libc++.1.0.dylib  
> /usr/local/opt/llvm/lib/libc++.dylib  
> /usr/local/opt/llvm/lib/libc++.1.dylib  
> /usr/local/opt/llvm/lib/libc++abi.dylib  
> /usr/local/opt/llvm/lib/libc++abi.1.dylib  
> /usr/local/opt/llvm/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.1.0.dylib  
> /usr/local/opt/llvm/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.1.0.dylib  
> /usr/local/opt/llvm/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.dylib  
> /usr/local/opt/llvm/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.1.dylib  
> /usr/local/opt/llvm/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.dylib  
> /usr/local/opt/llvm/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.1.dylib  
> /usr/local/opt/llvm@13/lib/libc++abi.1.0.dylib  
> /usr/local/opt/llvm@13/lib/libc++.1.0.dylib  
> /usr/local/opt/llvm@13/lib/libc++.dylib  
> /usr/local/opt/llvm@13/lib/libc++.1.dylib  
> /usr/local/opt/llvm@13/lib/libc++abi.dylib  
> /usr/local/opt/llvm@13/lib/libc++abi.1.dylib  
> /usr/local/opt/llvm@13/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.1.0.dylib  
> /usr/local/opt/llvm@13/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.1.0.dylib  
> /usr/local/opt/llvm@13/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.dylib  
> /usr/local/opt/llvm@13/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.1.dylib  
> /usr/local/opt/llvm@13/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.dylib  
> /usr/local/opt/llvm@13/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.1.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libc++abi.1.0.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libc++.1.0.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libc++.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libc++.1.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libc++abi.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/lib/libc++abi.1.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.1.0.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.1.0.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++.1.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.dylib  
> /usr/local/Cellar/llvm/13.0.0_1/Toolchains/LLVM13.0.0.xctoolchain/usr/lib/libc++abi.1.dylib  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ %

==&gt; It seems macOS /Applications folder contains NO static .a files, then .dylib files and .tbd files (supposedly a compact text based wrapper of dylib files)?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % find -L /Applications -name 'libc++\*.**a**'  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % find -L /Applications -name '**libc++\***'  
> /Applications/Xcode.app/Contents/Developer/Platforms/AppleTVOS.platform/Developer/SDKs/AppleTVOS14.3.sdk/usr/lib/libc++.1.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/AppleTVOS.platform/Developer/SDKs/AppleTVOS14.3.sdk/usr/lib/libc++.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/AppleTVOS.platform/Developer/SDKs/AppleTVOS14.3.sdk/usr/lib/libc++abi.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/AppleTVOS.platform/Developer/SDKs/AppleTVOS.sdk/usr/lib/libc++.1.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/AppleTVOS.platform/Developer/SDKs/AppleTVOS.sdk/usr/lib/libc++.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/AppleTVOS.platform/Developer/SDKs/AppleTVOS.sdk/usr/lib/libc++abi.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/**AppleTVOS.platform**/Library/Developer/CoreSimulator/Profiles/Runtimes/tvOS.simruntime/Contents/Resources/RuntimeRoot/usr/lib/libc++.**dylib**  
> /Applications/Xcode.app/Contents/Developer/Platforms/AppleTVOS.platform/Library/Developer/CoreSimulator/Profiles/Runtimes/tvOS.simruntime/Contents/Resources/RuntimeRoot/usr/lib/libc++.1.dylib  
> /Applications/Xcode.app/Contents/Developer/Platforms/AppleTVOS.platform/Library/Developer/CoreSimulator/Profiles/Runtimes/tvOS.simruntime/Contents/Resources/RuntimeRoot/usr/lib/libc++abi.dylib  
> /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/usr/lib/libc++.1.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/usr/lib/libc++.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/usr/lib/libc++abi.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS14.4.sdk/usr/lib/libc++.1.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS14.4.sdk/usr/lib/libc++.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS14.4.sdk/usr/lib/libc++abi.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/**iPhoneOS.platform**/Library/Developer/CoreSimulator/Profiles/Runtimes/iOS.simruntime/Contents/Resources/RuntimeRoot/usr/lib/libc++.**dylib**  
> /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Library/Developer/CoreSimulator/Profiles/Runtimes/iOS.simruntime/Contents/Resources/RuntimeRoot/usr/lib/libc++.1.dylib  
> /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Library/Developer/CoreSimulator/Profiles/Runtimes/iOS.simruntime/Contents/Resources/RuntimeRoot/usr/lib/libc++abi.dylib  
> /Applications/Xcode.app/Contents/Developer/Platforms/WatchOS.platform/Developer/SDKs/WatchOS.sdk/usr/lib/libc++.1.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/WatchOS.platform/Developer/SDKs/WatchOS.sdk/usr/lib/libc++.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/WatchOS.platform/Developer/SDKs/WatchOS.sdk/usr/lib/libc++abi.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/WatchOS.platform/Developer/SDKs/WatchOS7.2.sdk/usr/lib/libc++.1.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/WatchOS.platform/Developer/SDKs/WatchOS7.2.sdk/usr/lib/libc++.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/WatchOS.platform/Developer/SDKs/WatchOS7.2.sdk/usr/lib/libc++abi.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/**WatchOS.platform**/Library/Developer/CoreSimulator/Profiles/Runtimes/watchOS.simruntime/Contents/Resources/RuntimeRoot/usr/lib/libc++.**dylib**  
> /Applications/Xcode.app/Contents/Developer/Platforms/WatchOS.platform/Library/Developer/CoreSimulator/Profiles/Runtimes/watchOS.simruntime/Contents/Resources/RuntimeRoot/usr/lib/libc++.1.dylib  
> /Applications/Xcode.app/Contents/Developer/Platforms/WatchOS.platform/Library/Developer/CoreSimulator/Profiles/Runtimes/watchOS.simruntime/Contents/Resources/RuntimeRoot/usr/lib/libc++abi.dylib  
> /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX11.1.sdk/usr/lib/libc++.1.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX11.1.sdk/usr/lib/libc++.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX11.1.sdk/usr/lib/libc++abi.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/lib/libc++.1.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/lib/libc++.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/lib/libc++abi.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/DriverKit20.2.sdk/System/DriverKit/usr/lib/libc++.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/DriverKit20.2.sdk/System/DriverKit/usr/lib/libc++abi.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/WatchSimulator.platform/Developer/SDKs/WatchSimulator.sdk/usr/lib/libc++.1.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/WatchSimulator.platform/Developer/SDKs/WatchSimulator.sdk/usr/lib/libc++.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/WatchSimulator.platform/Developer/SDKs/WatchSimulator.sdk/usr/lib/libc++abi.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/WatchSimulator.platform/Developer/SDKs/WatchSimulator7.2.sdk/usr/lib/libc++.1.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/WatchSimulator.platform/Developer/SDKs/WatchSimulator7.2.sdk/usr/lib/libc++.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/WatchSimulator.platform/Developer/SDKs/WatchSimulator7.2.sdk/usr/lib/libc++abi.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/AppleTVSimulator.platform/Developer/SDKs/AppleTVSimulator.sdk/usr/lib/libc++.1.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/AppleTVSimulator.platform/Developer/SDKs/AppleTVSimulator.sdk/usr/lib/libc++.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/AppleTVSimulator.platform/Developer/SDKs/AppleTVSimulator.sdk/usr/lib/libc++abi.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/AppleTVSimulator.platform/Developer/SDKs/AppleTVSimulator14.3.sdk/usr/lib/libc++.1.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/AppleTVSimulator.platform/Developer/SDKs/AppleTVSimulator14.3.sdk/usr/lib/libc++.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/AppleTVSimulator.platform/Developer/SDKs/AppleTVSimulator14.3.sdk/usr/lib/libc++abi.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk/usr/lib/libc++.1.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk/usr/lib/libc++.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk/usr/lib/libc++abi.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator14.4.sdk/usr/lib/libc++.1.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator14.4.sdk/usr/lib/libc++.tbd  
> /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator14.4.sdk/usr/lib/libc++abi.tbd  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ %

2) It seems llvm comes with a Builtins.h file that "Defines enum values for all the target-independent builtin functions" (<https://clang.llvm.org/doxygen/Builtins_8h_source.html> )?

==&gt; On my system it seems the Builtins.h and .def are installed for GCC and Brew installed clang (but none found for XCode in /Applications)?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % find -L /usr/local -name 'Builtins.\*'  
> /usr/local/opt/llvm@10/include/clang/Basic/Builtins.h  
> /usr/local/opt/llvm@10/include/clang/Basic/Builtins.def  
> /usr/local/opt/llvm@10/Toolchains/LLVM13.0.0.xctoolchain/usr/include/clang/Basic/Builtins.h  
> /usr/local/opt/llvm@10/Toolchains/LLVM13.0.0.xctoolchain/usr/include/clang/Basic/Builtins.def  
> /usr/local/opt/llvm/include/clang/Basic/Builtins.h  
> /usr/local/opt/llvm/include/clang/Basic/Builtins.def  
> /usr/local/opt/llvm/Toolchains/LLVM13.0.0.xctoolchain/usr/include/clang/Basic/Builtins.h  
> /usr/local/opt/llvm/Toolchains/LLVM13.0.0.xctoolchain/usr/include/clang/Basic/Builtins.def  
> /usr/local/opt/llvm@13/include/clang/Basic/Builtins.h  
> /usr/local/opt/llvm@13/include/clang/Basic/Builtins.def  
> /usr/local/opt/llvm@13/Toolchains/LLVM13.0.0.xctoolchain/usr/include/clang/Basic/Builtins.h  
> /usr/local/opt/llvm@13/Toolchains/LLVM13.0.0.xctoolchain/usr/include/clang/Basic/Builtins.def  
> /usr/local/Cellar/llvm/13.0.0_1/include/clang/Basic/Builtins.h  
> /usr/local/Cellar/llvm/13.0.0_1/include/clang/Basic/Builtins.def  
> /usr/local/Cellar/llvm/13.0.0_1/Toolchains/LLVM13.0.0.xctoolchain/usr/include/clang/Basic/Builtins.h  
> /usr/local/Cellar/llvm/13.0.0_1/Toolchains/LLVM13.0.0.xctoolchain/usr/include/clang/Basic/Builtins.def  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % find -L /Applications -name 'Builtins\*'  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ %

==&gt; Although it seems Apple open source web site lists a Builtins.h file (<https://opensource.apple.com/source/clang/clang-700.0.72/src/tools/clang/include/clang/Basic/Builtins.h.auto.html> )?

NOTE: Maybe this file is for building clang and NOT for interfacing with clang build system?

...

{% endraw %}
