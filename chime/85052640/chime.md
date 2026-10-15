# Todo: Consider how to configure VSCode on macOS to build C++20 code?

```#85052640``` *As of 2021-11-27 23:06*

[mail plain/text](mail.txt)

{% raw %}
==&gt; Also see "[Todo: Consider to document the Brew Upgrade llvm from version 10 to version 13 on my Mac Pro 2013 (Trashcan)?](../bfd4e044/chime.md)"

1) It seems I can install LLVM 13 with Brew and get a clang++ that can compile selected C++20 code?

==&gt; After "brew upgrade llvm" it seems I have got clang++ in /usr/local/opt/llvm/bin/

==&gt; It seems I have to edit VSCode tasks.json and c_cpp_properties.json

> &lt;tasks.json&gt;

> > "command": "/usr/local/opt/llvm/bin/clang++"  
> > ...  
> > "args": &#91;  
> > ...  
> > "-std=c++20",  
> > "-stdlib=libc++",  
> > ...

> *The "command" defines what compiler is actually called.*  
> *The "args" defines the arguments provided to compiler invocation.*  
> *The llvm 13 clang++ accepts argument **-std= c++20 as well as c++2a and c++2b (experimental C++23 features)*

> &lt;c_cpp_properties.json&gt;

> > "compilerPath": "/usr/local/opt/llvm/bin/clang++"  
> > ...  
> > "cppStandard": "c++20"

> *The "compilerPath" defines the compiler used for Intellisense*  
> *The "**cppStandard**" defines what dialect of C++ to base the Intellisense operation on (does NOT affect the actual build)*  
> ...

NOTE: clang++ in llvm-13 does NOT support ranges yet :(

2) It seems I can use gcc-11 in VSCode and compile c++20 code?

NOTE: The VSCode GUI and configuration json files are still somewhat a mystery but I managed to get it working :)

> &lt;tasks.json&gt;

> {  
> "version": "2.0.0",  
> "tasks": &#91;  
> {  
> "type": "cppbuild",  
> "label": "C/C++: g++-11 build active file",  
> **"command": "/usr/local/bin/g++-11",**  
> "args": &#91;  
> "-fdiagnostics-color=always",  
> **"-std=c++20",**  
> "-g",  
> "${file}",  
> "-o",  
> "${workspaceFolder}/bin/${fileBasenameNoExtension}"  
> &#93;,  
> "options": {  
> "cwd": "${fileDirname}"  
> },  
> "problemMatcher": &#91;  
> "$gcc"  
> &#93;,  
> "group": {  
> "kind": "build",  
> "isDefault": true  
> },  
> "detail": "compiler: /usr/local/bin/g++-11"  
> }  
> &#93;  
> }

> &lt;c_cpp_properties.json&gt;

> {  
> "configurations": &#91;  
> {  
> "name": "Mac",  
> "includePath": &#91;  
> "${workspaceFolder}/\*\*"  
> &#93;,  
> "defines": &#91;&#93;,  
> "macFrameworkPath": &#91;&#93;,  
> **"compilerPath": "/usr/local/bin/gcc-11",**  
> "cStandard": "gnu17",  
> **"cppStandard": "c++20",**  
> "intelliSenseMode": "macos-gcc-x64"  
> }  
> &#93;,  
> "version": 4  
> }  
> ...

...

{% endraw %}
