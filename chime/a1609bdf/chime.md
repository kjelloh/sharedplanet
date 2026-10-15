# Todo: Programming - Consider to implement a C++ project discoverer application

```#a1609bdf``` *As of 2015-12-16 21:23*

[mail plain/text](mail.txt)

{% raw %}
Would it be possible to implement an application that searches a folder structure and figures out what libraries and applications that may be built from the code?

1) The discoverer should be used when one has a bunch of source code without proper build scripts (IDE configuration files) to build for the build environment one uses.

2) Consider to have the discoverer first list all source files (explicitly all cpp and h files)

3) The discoverer could then search the header files for declared functions/methods.

4) The next step could be to cross reference the code to “guess” where functions/methods are declared, where they are defined and where they are called.

==&gt; Guessing could be enough (e.g. do not bother with namespace resolutions)

5) The discoverer could now list pre-processor macros for conditional compiles (#if, #ifdef)

==&gt; The list should list complete predicates and used macros.

==&gt; Consider to sort the used predicates in the number of times they occur?

5) The discoverer now needs to find dependent libraries and includes (build environment includes)

6) The discoverer could now list candidates for compile units and what include folders to use to enable them to compile.

7) The discoverer could now try to compile the candidates to see what works. The result is then a list of compilable candidates.

8) Next question is how to link targets from the compiled units.

==&gt; The discoverer could search cpp-files for main(), WinMain(), DllMain (<http://stackoverflow.com/questions/416739/difference-between-winmain-main-and-dllmain-in-c>)

"

-  main() means your program is a console application.

-  WinMain() means the program is a GUI application -- that is, it displays windows and dialog boxes instead of showing console.

-  DllMain() means the program is a DLL. A DLL cannot be run directly but is used by the above two kinds of applications.

“

==&gt; How does this translate to other platforms (unix/linux, Mac OsX, iOS, Android)?

9) Note that whatever the discoverer finds out from the source is build platform and target independent (what to build and how to build it must be defined by the applied build platform, e.g. compiler and link directives).

==&gt; The discovered predicate macros may indicate for what build platforms the source is written (compiler defined macros)

…

Consider to elaborate on this idea and if a simple proof-of-concept may be built using e.g. boost filesystem and regular expressions?

...

{% endraw %}
