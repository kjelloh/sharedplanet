# Todo: Programming - Consider to define transform of C++ code into executable code as a stack-of-transformations?

```#a2b1e6e4``` *As of 2016-06-25 14:49*

[mail plain/text](mail.txt)

{% raw %}
It seems we should be able to model C++ compilation into executable code into layers of transformations and if all these transformations are correctly remembered we could deign a much better IDE for C++ development?

==&gt; Also see ”[Todo: Programming - Consider to find a way to manually edit a C++ file into a "Pandora View" of that file transformed into byte code?](../54157cbf/chime.md)”

==&gt; Also See ”[Todo: Programming - Consider to re-visit Pandora and design it as part of a Dream C++ IDE?](../92b081ea/chime.md)"

1) Consider all transform layers we can identity to compile a C++ File into target ”machine code” (real CPU or virtual CPU e.g. LLVM byte code)?

==&gt; Pre-processing transformations of Source Code File into translation unit

Source Code File Layer: &#91;Source Code File URL&#93;

|

Source Code Base Layer: &#91;Source Code Text&#93;

|

Pre-Processor Token layer: {Include Token} + {Raw text} + {Macro Token} + {Raw text} + …

==&gt; All Pre-processor tokens are identified as ranges in the Source Code Text.

==&gt; Non Pre-processor tokens (i.e. C++ source code) are anonymous ranges.

Pre-Processor Include URL: &#91;Include URL&#93; + &#91;Include URL&#93; + {Raw Text} + {Macro token}

==&gt; All Include Ranges are transformed into File URLs referencing the actual location of file to include

==&gt; Transformation of Include directive to URL are based on provided search paths for include files.

==&gt; IDE Option: Warn if multiple targets matches the Include directive given the search paths (i.e. if there are several files with the same name but different location matching the include)?

Pre-processor Include Text concatenation: {Included File Text} + …

2) Consider each transformation is either a text range transformed into another text range (e.g. pre-processor macro expansions) or tokenization of an existing text range (text divided into sub-ranges)?

==&gt; Consider a Tree view of nodes representing transformed text can show only what is transformed into what but never how transformed text relates to its source?

==&gt; For an include token text expanded into an include URL text this works fine (all we need to know)

==&gt; But for a tokenization of a text into sub-range tokens the tree can’t graphically show sub-range locations within the source text?

...

3) Consider we need to visualize the transformation stack the ”Pandora way” using layers of text with references to parent layer text?

==&gt; Consider a Tree of nodes of transformations can never show relation between transformed ranges (only that a range has been transformed into something different or into sub-ranges)?

==&gt; It seems using the ”Pandora Stacked Text Pane” view we have the ability to show both text replacement and text tokenization without repeating tokenized source?

==&gt; Consider some Text panes of a Pandora View of a compiled C++ File?

==&gt; The bottom pane can be named the C++ File URL?

==&gt; This Pane can carry a flat representation of its content?

==&gt; The next pane can be the Pre-Processor tokenization of the C++ File?

...

…

4) Consider to study the C++ Module Proposal to see how it fits into this C++ ”transform stack view” model?

==&gt; Consider if we need to view modules as C++ tokens that expose exported code and hides other code?

...

5) Consider this C++ ”Transformation Stack” enables an IDE to provide much better refactoring code entering operations?

==&gt; It seems this tool would allow editing of Pre-processor Macros and both see and know every-where the expanded macro is applied in the code?

==&gt; It seems this tool would be able to refactor out macros into separate files to make them ”private” by requiring the user to explicitly include them to use them?

…

Consider to elaborate on this idea to actually have an IDE that knows and shows each transformation step from a C++ File to the compiled Byte Code?

...

{% endraw %}
