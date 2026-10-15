# Todo: Programming - Consider to state dream traits of a good c++ make framework?

```#53c753bb``` *As of 2015-12-13 14:20*

[mail plain/text](mail.txt)

{% raw %}
When trying to understand Boost.Build (b2 and jam-files) and CMake for cross platform build (mainly boost libraries but also b2, LLVM and CMake themselves) it seems make environments are still a nightmare?

1) Each build system their own scripting language which can’t be read using knowledge of a normal programmer (special make - not procedural - syntax)  
2) Its har to trace how the make files interconnect, what options that can go into calling make tools and what affects they have.  
3) Cross target platform, source language and build tools (e.g. compilers and linkers) are not handled in a transparent way (rather gets obscure in things like toolsets that seem to mix build tools with target environments)?

Consider to elaborate on what a cross source/build-envirnment/target-environment must be able to do and how to make it do it in a transparent, automated and easy-to-use way?

a) Is it possible to have the build environment discover what to build and how to do it from source code only?

==&gt; Pre-processing stage - discover variants of header files to include and ifdef-variants  
==&gt; Compile stage - discover what compilers to use and what options to compile different targets  
==&gt; Link state - discover what modules (libraries) to link to and what targets to produce

b) Consider to identify what properties that are defined by the local build environment (that can be discovered and then be more-or-less fixed)?

==&gt; What is the build operating system and version (build platform)  
==&gt; What source is available and where (create a map of source code files)  
==&gt; What build tools are available and where  
==&gt; What libraries are available and where

c) Consider a distributed grid-build-framework cross multiple computers (virtual machines) building the same source on different build platforms for different targets?

==&gt; On a MAC running several viral machines the build-grid may conduct build of the same source on each virtual machine build-platform?  
==&gt; Consider using a Darwinet domain to synchronize such grid-builds?  
==&gt; Note that grid-builds must be asynchronous (Darwinet-way or otherwise)

==&gt; Discover what grid-nodes that are available  
==&gt; On each grid-node, perform build environment discovery (b)

d) Consider Grid-build to discover and group similar build-platforms into sub-domains for multi-node builds

==&gt; Nodes that run similar build-environments may cooperate to build the same target in parallel?  
==&gt; Like all Windows 10 nodes using Visual Studio build may split up target compilations among themselves and synchronize the outputs (e.g. obj/o-files)

e) Proposal: Assuming we will use a file synchronization mechanism (e.g. Darwinet) we may solve the single-build-platform design first.

==&gt; If we get the build-mechanisms work on one built-platform we can add grid-build later on?  
==&gt; Grid-, multiprocess- or threaded-build requires each tool in a tool-chain to be able to queue tasks rot a task pump for dispatching by cooperating nodes/procsses/threads?

… See ”Todo: Programming - Consider to design a "task-pump" for build-tool-chain members to post build tasks for dispatching by threads, processes or grid nodes?”  
…

Consider to elaborate more on this idea to see if it holds water and if so, how to proceed?

{% endraw %}
