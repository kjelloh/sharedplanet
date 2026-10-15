# Todo: Programming - Consider to design a C++ console application source and environment setup that will cross compile on Windows, MacOS and Linux?

```#fa0d7ffa``` *As of 2016-07-11 11:40*

[mail plain/text](mail.txt)

{% raw %}
So, what may be a good architecture and build environment for a C++ console application that will cross compile on windows (Visual Studio and RAD Studio), MacOS (Xcode) and Linux (CMake clang)?

1) Consider this article that proposes #ifdefs for the three platforms (http://stackoverflow.com/questions/3627127/writing-cross-platform-c-code-windows-linux-and-mac-osx)?

==&gt; It seems the _WIN32 identifies Windows Console platform?  
==&gt; It seems __linux__ identifies Linux platform?  
==&gt; It seems __APPLE__ identifies MacOS platform?

2) Consider what the main cpp file looks like on the three platforms?

… main cpp file contents goes here …

3) Consider what the default build environment architecture of the three platforms are?

==&gt; Q: What is the Visual Studio default project architecture and settings?  
==&gt; Q: What is the CMake clang best practice on Linux?  
==&gt; Q: What is the Xcode default project architecture and settings?

4) Consider if the source architecture of front-end, core and back-end is a good approach?

==&gt; The front-end is the user interface and may or may not be cross-platform?  
==&gt; The core is all code that MUST be cross-platform (just compiler adoptions)?  
==&gt; The back-end is the interface to the operating system and should be mostly cross-platform using boost and standard C++ libraries (hidden by standard code)?  
...

…

Consider to delve into these different ”digital worlds” to understand how to design the ”best” cross platform build and source environment?  
...

{% endraw %}
