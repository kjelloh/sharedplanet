# Todo: Consider to use clang compiler switch --trace-includes to track down how to get macOS stand alone clang use stand alone libc++ headers (NOT use XCode c++ standard library headers)

```#90c8755c``` *As of 2022-11-06 23:58*

[mail plain/text](mail.txt)

{% raw %}
I want to be able to run my own clang c++ too chain on mac OS (i.e., NOT use XCode installed c++ tool chain)

0) Consider to document an abstract of what I learned and may need to remember for future problem solving?

==&gt; It seems the following VSCode tasks.json sections is enough to build with clang 15 on macOS for Brew and macPorts installed clang 15?

> *It seems for Clang 15 ranges is still "experimental" so I need **-fexperimental-library **to activate it and add the lib library for it to find the experimental library to link to (-L**/usr/local/Cellar/llvm/15.0.3/lib/c++/** for the Brew installed clang 15 and -L**/opt/local/libexec/llvm-15/lib/** for the macPorts installed clang 15)*

> {  
> "type": "cppbuild",  
> "label": "macOS C/C++: Brew installed clang-15 build cratchit",  
> "command": "/usr/local/Cellar/llvm/15.0.3/bin/clang++",  
> "args": &#91;  
> "-fdiagnostics-color=always",  
> "-fexperimental-library",  
> "-L/usr/local/Cellar/llvm/15.0.3/lib/c++/",  
> "-std=c++20",  
> "-g",  
> "${file}",  
> "-o",  
> "${workspaceFolder}/cratchit.out"  
> &#93;,  
> "options": {  
> "cwd": "${fileDirname}"  
> },  
> "problemMatcher": &#91;  
> "$gcc"  
> &#93;,  
> "group": "build",  
> "detail": "compiler: /usr/local/Cellar/llvm/15.0.3/bin/clang++"  
> },

> {  
> "type": "cppbuild",  
> "label": "macOS C/C++: macPorts installed clang-15 build cratchit",  
> "command": "/opt/local/libexec/llvm-15/bin/clang++",  
> "args": &#91;  
> "--sysroot=/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk",  
> "-fexperimental-library",  
> "-L/opt/local/libexec/llvm-15/lib/",  
> "-fdiagnostics-color=always",  
> "-std=c++20",  
> "-g",  
> "${file}",  
> "-o",  
> "${workspaceFolder}/cratchit.out"  
> &#93;,  
> "options": {  
> "cwd": "${fileDirname}"  
> },  
> "problemMatcher": &#91;  
> "$gcc"  
> &#93;,  
> "group": "build",  
> "detail": "compiler: /opt/local/libexec/llvm-15/bin/clang++"  
> },

==&gt; It seems clang 15 is broken due to bad concept implementation (<https://stackoverflow.com/questions/73929080/error-with-clang-15-and-c20-stdviewsfilter> )?

> *"Libc++'s implementation of views is guarded behind the -fexperimental-library flag with which the particular example in your question also compiles. I am not sure, but I think the implementation is still incomplete, which is why it isn't enabled by default. It could be that my information on that is outdated though, in which case the guard might be there only to wait for stabilization.*  
> *Update: Both of these issues have been resolved on current LLVM trunk. The linked bug reports regarding libstdc++'s views implementation have been fixed. The libc++ views implementation (at least for the code in the question) is no longer guarded with -fexperimental-library. So I would expect that the LLVM 16 release will work with the shown code fine."*

> *With the switch -fexperimental-library my ranges code does compile but instead fails to link, as the experimental library is not available or not found (See below)*

> *BUT, some trial and error made me find the missing library and when I added that folder as a link folder the following command succeeds!*

> */opt/local/libexec/llvm-15/bin/clang++ --sysroot=/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -std=c++20 -fexperimental-library -L**/opt/local/libexec/llvm-15/lib/** src/main.cpp  
> *

==&gt; Press &lt;Shift&gt; + &lt;Cmd&gt; + '.' to be able to open hidden folders in macOS Finder dialog

> *Use this to e.g., open **/opt/local/libexec/llvm-15/bin/../include/c++/v1/ranges file where the folder /opt is hidden.*

{% endraw %}
