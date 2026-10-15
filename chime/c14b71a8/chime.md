# Todo: Programming - Consider to setup several C++ Development Environments on same and different virtual machines?

```#c14b71a8``` *As of 2016-03-03 16:40*

[mail plain/text](mail.txt)

{% raw %}
Consider it to be a good and fun idea to have virtual machines (e.g. Windows 10 and Linux) provide several C++ development environment to try out different concepts, compilers and build environments?

1) Install RAD Studio on the Windows 10 machine.

2) Install Microsoft Visual Studio on Windows 10 machine.

3) Install C++ CLang LLVM environment on windows 10 machine.

4) Install GCC on Windows 10 Machine.

5) Install CLang on Ubuntu machine?

6) Install GCC on Ubuntu Machine?

7) Consider to keep XE2 and XE7 on Windows 7 machine?

8) Consider to list some ”Tool-chains” like Editors, make-tools and complete IDE:s to try out and use?

==&gt; RAD Studio and Visual Studio are complete tool-chains of their own.

==&gt; GCC/CLang may be used with different Editors, build-envitronments and debuggers?

==&gt; See ”[Todo: Programming - Consider to study contemporary available IDEs for C++ programming?](../9c1df47d/chime.md)”

…

9) Consider to elaborate on how we may keep a common code-base for all these different build-platforms, build-environments and possibly target platforms?

a) Consider unsource repository::source&#91;revision state&#93; —&gt; workspace&#91;target-platform&#93;::executable&#91;processor&#93;

==&gt; I.e., unsource is a function that transforms source (of a defined revision in a repository) into executables (stored in a workspace targeting a specified hardware cpu)

b) Consider to list all options through the build chain (e.g. front-end language, make-environment, compiler, linker, target platform, cpu, memory model)?

c) Can we imagine ”unsource” as a ”client” compile-stack (creating intermediate binary code) and a ”server” link-stack (creating executable binary for the server platform)?

Source Linux Executable

| ^

v |

CLang C++ Link

LLVM LLVM

Windows 10 Linux

| ^

|--------------------------------------- |

==&gt; Source is compiled on ”Client” machine (Windows 10) into intermediate binary code

==&gt; It is then linked to executable on ”Server” Linux platform

d) In a Darwinet network Nodes may share the source files, intermediate binary code and different target-platform executable files

==&gt; A Windows 10 Darwinet Node performs Compilation into shared Intermediate binary code

==&gt; A Linux link node detects changed intermediate binary code and links it into Linux executable binaries.

==&gt; All Nodes may share Source files, intermediate binary files and all different target-platform binary files (different nodes links to different binary targets)?

**…WE ARE HERE...**

10) Consider to elaborate on the ”Unsource” tool in a grid-computing build environment?

==&gt; Consider &gt;unsource &lt;source-list&gt; &lt;build-platform&gt; &lt;build-environment&gt; &lt;target-platform&gt;?

==&gt; The unsource tool would then find a node running the build-platform and that supports the build-environment?

==&gt; It would then call that node to build source-list för the target.platform?

Side ideas:

a) Consider to test out Docker (Container-based application execution)?

==&gt; See ”[Todo: Software - Consider to follow up on pointers to platform build, automate and manage made by Parallels 11?](../e5e82d39/chime.md)”

==&gt; No, Docker is a server (or cloud based) service (it,s not possible to build Docker Containers locally)

{% endraw %}
