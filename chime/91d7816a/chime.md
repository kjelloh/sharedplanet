# Todo: Programming - Consider a source-file-system for c++ that exposes a "representation-view" of representation-invariant (e.g. AST-graph) c++ translation units?

```#91d7816a``` *As of 2015-12-21 11:38*

[mail plain/text](mail.txt)

{% raw %}
When watching a youtube video about using clang for c++ refactoring () I started to think of a way to bring c++ programmers using all the variety of platforms, IDE:s, editors, build-environemts and what-have-you, together by isolating the user environment into a “view” and have a common “back-end” of common-represermation of the code?

1) Could we imagine a file system that exposes source code the the users build-environment as cpp/h files the way the lie to see it but where the back-end is actually some build-environment invariant representation?

==&gt; The file system lets the user edit and compile source code managed by the “view” enabling the user to name functions, place braces and format the source as they see fit.  
==&gt; But behind the scenes the code is actually represented using “neutral names” and bother only with the correctness of the source-code-stream, not the users preferences of new lines, indentation and such look-end-feel issues?

2) Consider to define a transformation of existing source code into a representation-independent format?

==&gt; One layer may be file-represenatiton of code (where and in what file the source is located)?  
==&gt; The file-independent representation of code only bothers with in what order the code items appear, not in what file and where in that file the code actually appears to the programmer?

==&gt; Another layer is the pre-processor view (what macros are defined and where they are used).  
==&gt; The pre-processor-view may be seen as a static-variant of “templates” but not language-defined, only text-transformation defined.  
==&gt; The view-independent representation of code should NOT know anything about pre-processor-macro-based representations?

==&gt; Another layer is template-instanciated-code (the view independent representation must know about the template-level but may represent these macros in neutral-name form)?  
==&gt; The template-neutral form should be such that it is able to identify the same template defined twice (the templates instantiate the same code given the same parameter input)?

==&gt; The view-independent representation should bother only with the code-structure, not the actual naming of functions, variables, types etc.  
==&gt; It should be able to identify code that is actually the “same” (it differs only in programmers choice of names and edit)?  
==&gt; Two pieces of code is the “same” if it generates the same compiler output (same machine instructions)  
==&gt; Two pieces of code is “equivalent” if it produces the exact same result (differ only in the order the operations are executed).

3) Consider to combine this ide with the Database-stored-meta-code idiom (macro/template-like code bound to code-located data and functions)?

==&gt; This is the spinn-off-idea from the Pandora project where we thought of code-snippets bound to other code rather than template-generated code bound to provided template parameters.  
==&gt; The difference would be that meta-code lives in a pre-process environment and the compiler only sees the bound code.  
==&gt; meta-code would be able to bind to template code and thus allowing yet a higher level of abstraction when writing code?  
==&gt; Meta-code would be able to provide ready-to-use design-patterns (they may define much more bound-pints that macros or templates are able to do).  
==&gt; Meta-code should be combined with a graphical user interface to allow the programmer to use it CAD-wise rather than next-door wise?  
…

Consider to elaborate more on this method of separating view-aspects ofd source code form actual end-result-aspcets of the targets?  
...

{% endraw %}
