# Todo: Programming - Consider to re-visit Pandora and design it as part of a Dream C++ IDE?

```#92b081ea``` *As of 2016-07-14 17:41*

[mail plain/text](mail.txt)

{% raw %}
It seems the idea for Pandora still lives as a good idea in my head. Consider to elaborate on what Pandora can do as part of a modern C++ IDE?

1) Consider to be inspired by this talk “Emacs as a C++ IDE" (<https://channel9.msdn.com/Events/CPP/CppCon-2015/CPPConD02V009>)?

==&gt; This is a plugin to Emacs named cmake-ide.

==&gt; Aslo see “Todo: Programming - Consider to study contemporary available IDEs for C++ programming?”

2) Consider how to apply scope-layers to interact with the code?

==&gt; Each sub-scope of the C++ code is shown as a plate hovering over the encapsulating scope plate.

==&gt; Consider alternative scopes to show as “plates” turned away and stacked left to right?

==&gt; An #ifdef may be viewed as a polymorphic plate with each possible “face” stacked to show only the right edge.

==&gt; The user may turn the appropriate ifdef-face up by selecting it (the not facing plates still stacked to the right)

…

3) Consider to allow for code-folding based on selected “plate”?

==&gt; Plates of scopes (code) nearer the user (deeper scopes) are folded?

==&gt; Consider this to be a way to fold each switch entry (at least as I often writes each entry as its own {} scope)?

...

4) Consider to use the “plate-in-plate” view also for higher levels of “stack” like templates, preprocessor macros and files?

==&gt; Elaborate on wether file is the bottom or the top of the code stack?

==&gt; Should we stick to the file at the bottom and each plate closer to the user showing higher and higher levers of code?

==&gt; Or, does the code actually becomes lower (more detailed) the closer to the user the plate is?

==&gt; E.g. is a pre-processor macro close to the file or close to the user in the plate hierarchy?

==&gt; Note that a macro can be used at many locations in the code and the IDE must show how code is bound by a macro (edits changes all macro-bound code)

…

5) How can we make Pandora show only what can “be seen” and ignore code that is “far away”

==&gt; How does 3D-games cope with large worlds and can we have Pandora apply the same type of efficiency for large code projects?

...

6) What Clang and CMake integration can we use to make Pandora provide these 3D-view and editing of C++ code?

==&gt; E.g see how cmake-ide (see above) does this?

==&gt; Can we leverage rtags for Pandora to get help with understanding how the code bounds together?

7) Consider what we can use Boost.Wave to implement preprocessor-aware Pandora C++ code view (<http://www.boost.org/doc/libs/1_52_0/libs/wave/index.html>)?

==&gt; The Boost.Wave library seem to implement the standard pre-processing of C++ source code?

==&gt; Can we leverage on this library to get insight to pre-processor executed code manipulations?

8) Consider to model pre-processing as compile-time executed functionality (on par with Template Metafunctions)?

==&gt; Can we model pre-processing as compile time program execution of meta-code (e.g. macros)?

==&gt; Consider how Pandora can visualise pre-processor macros and directives in the 3D “scope-view” to the programmer?

...

…

Consider to elaborate on how a good Pandora code editor for C++ may provide good functionality to a Dread C++ IDE?

{% endraw %}
