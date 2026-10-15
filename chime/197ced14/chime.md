# Todo: C++ - Consider to design good ways to get C++17 tool chain and library on major platforms of mine?

```#197ced14``` *As of 2017-03-06 19:45*

[mail plain/text](mail.txt)

{% raw %}
So, what ways can we get to work to obtain working C++17 tool chains on the major platforms MAC OS, Linux MATE and Windows 10?

==&gt; Also see ”Todo: Programming - Consider the C++ cross platform tool-chain and front-end/back-end options options?”

==&gt; Also see ”Todo: Programming - Consider to generate CMake C++ Console project cross platform MacOS, Linix MAKET and Microsoft Visual Studio?”

==&gt; Also see ”Todo: Programming - Consider the best way to install and keep updated the llvm tool-chain on Linux?"

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

2) Consider MAC OS + CLion + gcc-7 + libstdc++?

See Synced project ”/Users/kjell-olovhogdahl/Resilio Sync/CLion/MyC++17PlayGround"

==&gt; (1) It seems in CLion, either we may override CMake environment variables to configure the CLion Project to use specific compiler (<https://intellij-support.jetbrains.com/hc/en-us/articles/207251865-How-can-I-change-compilers-in-CLion->)?

![](<CLion CMake Options C++17 (gcc-7).tiff>)

==&gt; (2) OR - It seems we can force CMake to set gcc-7 compiler and correct switches to link with gcc libstdc++?

> **set(CMAKE_CXX_COMPILER=gcc-7)**  
> **set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++17 -lstdc++")**

==&gt; NOTE: Because we are using gcc-7 we must provide the option -lstdc++ (we can’t pass -stdlib=libstdc++ as that is a switch to the g++ compiler, and gcc-7 does not seem to install a ”++” flavor)?

...

3) Consider MAC OS + XCode + Clang + libc++?

==&gt; See XCode Project ”/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyC++17PlayGround/MyC++17PlayGround"

==&gt; It seems a bit unclear what version of Clang that comes with XCode (They have their own version numbering)?

==&gt; It seems Version Version 8.2.1 (8C1002) accepts the -std=c++1z flag and some C++17 language features (But no C++17 library features)?

![](<XCode 8.0 -std=c++1z compiler option.tiff>)

…

Consider to continue to update this Todo: with ways of getting C++17 on to my different platforms?

...

{% endraw %}
