# Todo: Sweden C++ - Consider a "C++ Compilation Walk" through Stockholm assigning a C++ compilation phase to each part of the walk?

```#9f70a081``` *As of 2017-04-12 13:51*

[mail plain/text](mail.txt)

{% raw %}
Could it be a fun idea to manifest and discuss each phase of C++ source code compilation to parts of a walk through stockholm (with a pause for fika in the middle)?

==&gt; Also see ”Todo: Programming - Consider to talk/blog on all "layers" C++ source code goes through before becoming in-memory…”

1) Consider to start in Kungsträdgården, walk through Djurgården and end by Ferry to Slussen?

==&gt; Consider to start with a short piece of C++ code handed out to all attendees?

==&gt; Consider what phases to go through during the walk?

==&gt; Consider each attendee may choose which compiler they like to ”be” (This affects the steps but also the format of the binary output)?

==&gt; Consider each attendee may chose on what platform they like to be ”walking” (this restricts what platform to choose and possibly the phases and the format of the output)?

…

2) Consider the common (mandatory) phases of C++ compilation (<http://en.cppreference.com/w/cpp/language/translation_phases>)?

— For each source file to compile… --

— ”Pre-Compile phases” --

Phase 1 - Transform source file characters to defined ones

Phase 2 - Process continuation back-slash and fix end-of-line of last line

Phase 3 - Process comments

Phase 4 - Execute pre-processing (relating phase 1..4 for each included file) (See <http://en.cppreference.com/w/cpp/preprocessor>)

Phase 5 - Process string and character literals

Phase 6 - Concatenate Adjacent string literals

— Compilation phases ---

Phase 7 - Compile the Translation Unit produced by phase 1..6 on the initial source file to compile

Phase 8 - Perform ”Compile Time Executions” (transform explicit template instantiations into instantiation units)

— Linker Phase --

Phase 9 - Link compiled translation units, generated instations units with library components into ”execution units"

3) Consider to what degree we like to expand on the Compilation phases into compiler steps?

==&gt; Consider to arrange a separate walk to focus on compiler steps only?

==&gt; Consider what Compiler steps we may dive into?  
==&gt; Consider First Name Lookup (<http://en.cppreference.com/w/cpp/language/lookup>)?  
==&gt; Consider Then Template Argument Deduction (http://en.cppreference.com/w/cpp/language/template_argument_deduction)?  
==&gt; Consider Overload Resolution (http://en.cppreference.com/w/cpp/language/overload_resolution)?  
==&gt; Consider Access Control?  
==&gt; Consider Virtual Function Binding (http://www.cplusplus.com/doc/tutorial/polymorphism/)?

…

Consider to elaborate on this idea to arrange a walk through Stockholm and map C++ compilation phases (steps) to actual parts of the walk for discussion and emulation based on some simple C++ source code brought along on paper?

...

{% endraw %}
