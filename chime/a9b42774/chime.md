# Todo: programming - Consider to argue that C++ pre-processing must go (error-prone because language-agnostic)?

```#a9b42774``` *As of 2016-03-03 17:58*

[mail plain/text](mail.txt)

{% raw %}
C++ Pre-processor language-agnostic source-code manipulation just can’t be a good idea, can it?

1) The result of pre-processing is not meant to be read by the programmer, thus pre-processing is dangerous and error-prone?

2) Pre-processing was a way to do Meta-programming before C++ Template Meta-programming was introduced and should be replaced with extended meta-programming features?

3) Both pre-processing and meta-programming ”hides" what code is actually compiled which is in itself a ”bad” thing?

==&gt; Pre-processing being language-agnostic enables writing ”code” that seem to do one thing but does something completely different?  
==&gt; Template-meta-programming at least is type-safe and language-aware but still allows correct Meta-functions generate mal-formed C++ code (compiler error)

4) What can we imagine to replace Pre-processing and existing Template Meta-programming with to make code more readable and less error-prone?

==&gt; We want to be able to do al the ”stuff” we do with Pre-processing and Template Meta-programming?  
==&gt; But we want the code that the compiler actually compiles to be explicit and not implicit?  
==&gt; Or, at least enable the compiler to generate compiler-errors that actually enables the programer to understand where the error is?

5) What mechanism can we imagine to enable the programmer to write boiler-plate code without using the Pre-processor?

6) What mechanism can we imagine to make unit-compilation compile shared dependent code (i.e. header-files) efficiently?

==&gt; Consider to study C++ ”module” proposal that seem to relieve the Pre-processor of doing the #include?  
==&gt; What other thoughts can we find on the web regarding this issue?

7) What can we say about defining a graphical language on to of the C++ text-represneation of code?

==&gt; Can we imagine a Meta-language that maps graphical representation 1-to-1 to C++ Code?  
==&gt; How well does Pandora fit as such a Graphical Meta-language?

==&gt; Consider to eliminate to-broad inefficient #include and better (but should-be-redundant) using with Pandora source-file-scope ”bindings”?

==&gt; The Pandora 3D-view shows what meta-type/type/meta-function/function that some code is ”bound” to (may generate C++ #include and/or using code lines on C++ level)?

8) How much of Pre-processor stuff and C++ Template stuff can we replace with Pandora Graphical Meta-code-snippets?

==&gt; Remember the idea of having Pandora show Code-snippets where the programmer ”bound” the code-snippet to actual code where it was ”used”?  
==&gt; This idea seem to be able to handle both Pre-processor ”Meta-programing” as well as Template Meta-programming?  
==&gt; Further, it can be made ”crystal clear” what ”Meta-code-snippets” that are used and how they relate to instantiated C++ source code?  
…

9) Can we imagine to define a Meta-program layer that totally replaces all C++ source coding?

==&gt; Consider to define a Meta-programming language that generates C++ code under-the-hood (as C++ once generated plain C-code)?  
==&gt; Consider to make all programming into Meta-programmng in some ”new” Meta-programming language?  
==&gt; Can we make this Meta-programming-language easy-to-understand for C++ programmers?  
==&gt; Can we make this Meta-programming-language allow mixing with existing C++ source code?

==&gt; I.e. in the same way C++ Templates allow plain C++ Code to co-exist with template-code?

==&gt; What would the benefits be of this Meta-programming-language?

==&gt; Is the D-language in some sens such a Meta-programming language?

10) Note that Wikipedia article on Meta Programming defines it a borader than just compile-time generation of code (https://en.wikipedia.org/wiki/Metaprogramming)?

…

Consider to elaborate on this idea of replacing traditional Pre-processor mechanism and Template Meta-programming with something better that enables the programmer to more easily write clear and correct code using re-usable Meta-code?  
...

{% endraw %}
