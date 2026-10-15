# Todo: C++ - Consider to make a talk on what we could do if we were able to generate C++ from other languages?

```#25588ff0``` *As of 2017-01-26 12:50*

[mail plain/text](mail.txt)

{% raw %}
So, what could we learn and what could we do if we imagined it was possible to write code in other languages and compile them down to the metal by first turning it into C++?

1) How would a mapping of Erlang to C++ look like?

2) How would a mapping from F# to C++ look like?

3) How can we handle languages that targets some form of Virtual Machine (how do we re-create the virtual machine for the generated C++ code to run)?

==&gt; Can Java be turned into C++ that runs directly on the metal (or do we need to link with a C++ Virtual machine look-alike that performs the garbage collection and interfaces the hardware)?  
…

4) Consider to give this initiative a name and a goal (like one tool chain to unite them all)?

==&gt; Consider the goal is to pipe all code down to the metal through the C++ tool-chain?

Java  
C#  
F#  
Erlang  
C  
Swift ==&gt; C++ ==&gt; LLVM ==&gt; CPU/Metal  
Objective-C  
Pascal/Delphi  
Go  
Rust  
D  
...

==&gt; Consider this is a way to NOT invent a new language, but to unite all languages that already exist.  
==&gt; Consider such a unification may enable a better language to evolve (survival of the fittest language)  
…

5) Consider languages that already compiles to C++?

==&gt; Consider the Faust DSP Language to generate sound signal processing software (http://faust.grame.fr/about/)?

==&gt; Consider Faust actually transpiles to a quite large set of languages (C++ and LLVM IR just being a few)?

==&gt; Consider Rust actually translates to LLVM intermediate code and thus possibly could reverse-translate to C++ (As made by emscriptem turning C++ to LLVM code and then back to JavaScript)?  
...

…

Consider to delve into this topic and see what we can learn from such an exercise?  
...

{% endraw %}
