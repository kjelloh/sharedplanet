# Todo: Programming - Consider to partition C++ source code by divide-and-compile until the smallest compile-able parts are found?

```#9a54e656``` *As of 2016-03-29 00:40*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to not parse C++ code to decompose it but rather divide-and-compile until the smallest compile-able parts are found?

1) Consider we would like to partition C++ code to store the parts to build the code rather than store the actual source files?

==&gt; In this way we would be able to re-arrange these parts for efficiency in building the code?  
==&gt; It could be seen as an alternative to using C++ modules (proposed for C++17)  
==&gt; Instead source is represented as trees of compile-able parts put together at compile time (just in time)?

2) Consider a divide-and-compile algorithm that uses binary search putting in a ‘;’ to identify statements?

==&gt; A header file may be divided in half and a ‘;’ is written there.  
==&gt; If the first half compiles without the second one, then the first one is a source-code “statement”.  
==&gt; If not, try to put the ‘;’ at the half of the second half.  
==&gt; Repeat until a first compilable first “statement” is found.

==&gt; Now repeat the procedure on the first and second half.

==&gt; Note that the second half always depends on all that precedes it (for now)

==&gt; When no smaller parts are found we have identified all statements of the code?

WE ARE HERE…

3) Consider to divide statements into smaller C++ code items by use the divide-and-compile using other separator chars?

==&gt; We would like to identify identifiers (use space to separate statement parts that still compiles)  
==&gt; We would like to identify class initialisers (use ‘:’ - the code only compiles when ‘:’ is paced in existing ‘:’)?  
...

…

Consider to elaborate (and try out) this approach to decompose C++ code into statements, expressions, identifiers and what we can have?  
...

{% endraw %}
