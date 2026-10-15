# Todo: C++ - Consider what we can learn from viewing the build tool chain as a chain of functional transformations (in effect defining "compilation" as function-composition)?

```#2061479d``` *As of 2017-02-08 13:51*

[mail plain/text](mail.txt)

{% raw %}
What can we learn from trying to model the C++ build tool chain as a series of functional transformation of immutable ”files” (octet-ranges)?

==&gt; Also see ”[Todo: Programming - Consider to elaborate on the idea of modeling source code compilation and linking as a series of transformation between code-spaces?](../2d85dde3/chime.md)"

==&gt; Also see ”Todo: C++ - Consider we should aim at starting to add transpires that generates C++ code for us (extend the asm mechanism for inline assembly)?”

==&gt; Also see ”[Todo: C++ Programming - Consider to discuss how to eliminate (automate) C++ Source Files (zero overhead pre-processing)?](../5419b933/chime.md)”

==&gt; Also see ”[Todo: Programming - Consider to assemble a 3D example of a "Pandora View" of a piece of C++ code from Pre-processor macros, through templates all the way down to actual assembly?](../a3a7a483/chime.md)"

==&gt; Also see ”[Todo: programming - Consider to argue that C++ pre-processing must go (error-prone because language-agnostic)?](../a9b42774/chime.md)"

1) Consider to what degree current build tool-chains may be modeled as composition of immutable-file transformations?

...

2) Consider what we could gain from modeling having C++ source code being turned into asynchronous token streams and processed into ”Reactive streams”?

==&gt; Consider a C++ translation using in fact can we broken down into ”tokens” (e.g., classes, functions, code blocks) and processed in semi-parallel (as if separate translation units)?

==&gt; The linker should be able to bind symbols in these sub-transaltion units in just the same way as separate object files are linked?

...

3) Consider if it would be possible to ”wrap” existing tools (pre-processor, C++ front-end, LLVM back-end…) into compose-able transform-functions?

==&gt; Consider if we can wrap the Clang front-end and LLVM back-end into C++ composable functions (and say write the tool-chain using RxCpp)?

...

4) Consider this should potentially making it easier to compose new tool-chains as well as extend the C++ front-end with DSL-to-C++ transpilers?

==&gt; Also see ”Todo: C++ - Consider we should aim at starting to add transpires that generates C++ code for us (extend the asm mechanism for inline assembly)?”

…

Consider to delve deeper into this idea of modeling the C++ build tool chain as steps of transformations of immutable data using pure functions?

...

{% endraw %}
