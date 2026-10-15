# Todo: C++ Programming - Consider ways to totally eliminate the need fro a build-system (C++ source code based build definition)?

```#bed0c2a2``` *As of 2016-12-20 13:42*

[mail plain/text](mail.txt)

{% raw %}
Consider to discuss to what degree we may replace static or generated build systems with automated source code analysis to know what to build?

1) Consider most build systems are redundant in that the source code to build already defines all the requirements of how to build and what to build?

==&gt; Consider a dependency graph of the C++ code will reveal what parts are libraries and what are applications?  
==&gt; Consider a dependency graph of pre-processor #includes already defines how to build each translation unit?  
==&gt; Consider existing pre-prcessor conditionals (#if, #ifdef, #else, etc.) already defines possibly combinations that will actually build?

==&gt; Consider a smart build system may try out what combinations of pre-processor conditionals that may actually compile?  
==&gt; Consider a smart build system are able to recognize pre-processor conditionals that are statically defined by the build tool chain (compiler, platforms, standard library etc.)?  
==&gt; Consider a smart build system may provide the programmer with a list os possible pre-processor configurations to choose from (like a switch board of things to turn on/off)?  
…

2) Consider such a smart build mechanism to recognize how to build a library on the current platform?

==&gt; On Windows a library will be built as a dll or lib?  
==&gt; On Unix platforms a library will be built to a shared-library file (.a or shared library file)?  
==&gt; On Mac OS a library will be built to a shared library file on Mac OS (.so ro .dylib file)  
...  
…

Consider to delve into this idea to totally eliminate the need of a separate build environment and replace it with mechanism that uses the existing source code to figure out what may be build from it?  
...

{% endraw %}
