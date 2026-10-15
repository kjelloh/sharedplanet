# Todo: Consider to try out and document the EOS GitHub open source library in Xcode OS X?

```#c26c278d``` *As of 2018-04-20 16:29*

[mail plain/text](mail.txt)

{% raw %}
So, what can I learn from cloning and delving into the EOS (C++?) open source libraries?

==&gt; Also see “Todo: Consider to document how to install and maintain C++ Boost libraries in Xcode and OS X?”

1) The EOS GitHub library seems to live here (<https://github.com/EOSIO/eos>)?

==&gt; I cloned to my Macbook Pro 2014 (See “/Users/kjell-olovhogdahl/Documents/GitHub/eos”)?

1) It seems it comes with CMake and possibly the ability to generate tool chain for Xcode?

==&gt; I succeeded to engage CMake to generate into new ”build” sub-folder (but had to upgrade boost to &gt; 1.66)?

> Last login: Thu Apr 19 13:54:18 on ttys003  
> Kjell-Olovs-MacBook-Pro-2014:~ kjell-olovhogdahl$ cd Documents/  
> Kjell-Olovs-MacBook-Pro-2014:Documents kjell-olovhogdahl$ cd GitHub/  
> Kjell-Olovs-MacBook-Pro-2014:GitHub kjell-olovhogdahl$ cd eos/  
> Kjell-Olovs-MacBook-Pro-2014:eos kjell-olovhogdahl$ mkdir build  
> Kjell-Olovs-MacBook-Pro-2014:eos kjell-olovhogdahl$ cd build  
> Kjell-Olovs-MacBook-Pro-2014:build kjell-olovhogdahl$ cmake ..  
> -- The C compiler identification is AppleClang 9.1.0.9020039  
> -- The CXX compiler identification is AppleClang 9.1.0.9020039  
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
> -- Using custom FindBoost.cmake  
> CMake Error at libraries/fc/CMakeModules/FindBoost.cmake:1129 (message):  
> Unable to find the requested Boost libraries.

> Boost version: 1.60.0

> Boost include path: /usr/local/include

> **Detected version of Boost is too old. Requested version was 1.66** (or  
> newer).  
> Call Stack (most recent call first):  
> CMakeLists.txt:88 (FIND_PACKAGE)

> -- Configuring Eos on OS X  
> -- Looking for pthread.h  
> -- Looking for pthread.h - found  
> -- Looking for pthread_create  
> -- Looking for pthread_create - found  
> -- Found Threads: TRUE  
> -- binaryen building with -std=c++11  
> -- binaryen building for platform x86-64  
> -- binaryen building with -Wall  
> -- binaryen building with -Werror  
> -- binaryen building with -Wextra  
> -- binaryen building with -Wno-unused-parameter  
> -- binaryen building with -fno-omit-frame-pointer  
> -- binaryen building with -fPIC  
> -- binaryen building with -O2  
> -- binaryen building with -UNDEBUG  
> -- Could NOT find WASM (missing: WASM_CLANG WASM_LLC WASM_LLVM_LINK)  
> CMake Error at CMakeModules/wasm.cmake:8 (message):  
> No WASM compiler cound be found (make sure WASM_ROOT is set)  
> Call Stack (most recent call first):  
> CMakeLists.txt:183 (include)

> -- Configuring incomplete, errors occurred!  
> See also "/Users/kjell-olovhogdahl/Documents/GitHub/eos/build/CMakeFiles/CMakeOutput.log".  
> Kjell-Olovs-MacBook-Pro-2014:build kjell-olovhogdahl$

==&gt; I then seemed to be able to use “brew upgrade” to get lastest boost (1.67)?

==&gt; Also see “Todo: Consider to document how to install and maintain C++ Boost libraries in Xcode and OS X?"

> Kjell-Olovs-MacBook-Pro-2014:build kjell-olovhogdahl$ brew upgrade boost  
> Updating Homebrew...  
> ==&gt; **Auto-updated Homebrew!**  
> Updated 2 taps (homebrew/core, caskroom/cask).  
> ==&gt; **Updated Formulae**  
> amazon-ecs-cli erlang kubeless presto  
> annie feh libgsf qmmp  
> atlassian-cli fn mysql sdcc  
> blueutil ghc mysql@5.5 silk  
> caddy gpgme mysql@5.6 spotbugs  
> cake haproxy node-build txr  
> calicoctl heroku nudoku typescript  
> dockviz kotlin osrm-backend wireguard-tools  
> ==&gt; **Renamed Formulae**  
> geth -&gt; ethereum

> ==&gt; **Upgrading 1 outdated package, with result:**  
> boost 1.60.0_1 -&gt; 1.67.0_1  
> ==&gt; **Upgrading ****boost**  
> ==&gt; **Downloading <https://homebrew.bintray.com/bottles/boost-1.67.0_1.high_sierra>.**  
> ==&gt; **Downloading from <https://akamai.bintray.com/26/265ab8beaa6fa26a7c305ef2e6aec>**  
> ######################################################################## 100.0%  
> ==&gt; **Pouring boost-1.67.0_1.high_sierra.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/boost/1.67.0_1: 13,506 files, 450.9MB  
> Kjell-Olovs-MacBook-Pro-2014:build kjell-olovhogdahl$

==&gt; It seems on second cmake try it requires something called

> Kjell-Olovs-MacBook-Pro-2014:build kjell-olovhogdahl$ cmake ..  
> -- Using custom FindBoost.cmake  
> -- Boost version: 1.67.0  
> -- Found the following Boost libraries:  
> -- thread  
> -- date_time  
> -- filesystem  
> -- system  
> -- program_options  
> -- signals  
> -- serialization  
> -- chrono  
> -- unit_test_framework  
> -- context  
> -- locale  
> -- iostreams  
> -- Configuring Eos on OS X  
> -- binaryen building with -std=c++11  
> -- binaryen building for platform x86-64  
> -- binaryen building with -Wall  
> -- binaryen building with -Werror  
> -- binaryen building with -Wextra  
> -- binaryen building with -Wno-unused-parameter  
> -- binaryen building with -fno-omit-frame-pointer  
> -- binaryen building with -fPIC  
> -- binaryen building with -O2  
> -- binaryen building with -UNDEBUG  
> -- **Could NOT find WASM** (missing: WASM_CLANG WASM_LLC WASM_LLVM_LINK)  
> CMake Error at CMakeModules/wasm.cmake:8 (message):  
> No WASM compiler cound be found (make sure WASM_ROOT is set)  
> Call Stack (most recent call first):  
> CMakeLists.txt:183 (include)

> -- Configuring incomplete, errors occurred!  
> See also "/Users/kjell-olovhogdahl/Documents/GitHub/eos/build/CMakeFiles/CMakeOutput.log".  
> Kjell-Olovs-MacBook-Pro-2014:build kjell-olovhogdahl$

**TODO: Find out what WASM is and fix this problem to get an XCOde environment up and running?**

…

Consider to continue to delve into the EOS source code to see what I can learn from it?

...

{% endraw %}
