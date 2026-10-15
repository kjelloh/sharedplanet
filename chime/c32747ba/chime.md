# Todo: Programming - Consider to write a C++ standard proposal about build-rules of source-code directory trees?

```#c32747ba``` *As of 2016-05-04 15:24*

[mail plain/text](mail.txt)

{% raw %}
Could we imagine that one way to try and adress the problems of complicated c++ build systems is to actually extend the language with standard build rules that enables build of well-formed source code trees?

Also See “Todo: Programming - Consider to understand how to write and send C++ standard proposals to the committee?"

Also See “Todo: Programming - Consider a Dream C++ IDE (build environment) to detect Strongly Connected Components (SCC:s) in source as build-able libraries?”

1) Consider the idea that the source code is all that is needed for correct source code compilation?

==&gt; Consider compilation rules that detects “Strongly Connected Components” to identify possible library targets (possible code with a simple exposed API)?

==&gt; Consider rules that detects dependancies to compile only what-is-needed to create detected (or defined) target?

==&gt; Consider rules to apply switches provided to compiler that defines the target?

==&gt; Consider rules that honors compiler options that defines source files (and apply only those)?

2) Consider rules that detects if multiple targets are possible and reports them at compile time?

==&gt; Consider that if no target is defined then the rules should generate a message listing possible targets?

3) Consider rules to detect and list applied pre-processor-selected code?

==&gt; Consider rules that defines detection of #if, #ifdef dependent code?

==&gt; Consider rules that based on defined pre-processor macros deduce further macros that may be used to select code to compile?

==&gt; Consider rules that finds a best-match of pre-processor macros to apply (best guess of what code to compile)?

…

4) Consider the goal is to enable the compiler to generate a standard output of possible builds of defined or accessible source code?

==&gt; Could we imagine it to be possible to define rules so that invoking the compiler in a directory automatically would result in the correct build (no separate build system required)?

5) Consider what additional build-rules that the C++ compiler will be unable to detect (and that still requires separate build system)?

==&gt; Consider that C++ code generators must be invoked before the compiler?

==&gt; Consider compilation of source code in other languages must be invoked by separate build system?

==&gt; Consider options to build test/debug or release targets can never be determined by the C++ compiler (equal strong options)?

...

6) Consider to elaborate on how the Modules proposal may be integrated and leveraged to enhance compiler.build-rules generator?

==&gt; Could we imagine the current Modules proposal to help in enabling the Compiler to detect build options and targets?

...

…

Consider to elaborate on this approach of compiler source-code-based build rules generation?

{% endraw %}
