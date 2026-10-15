# Todo: Programming - Consider to replace static C++ make scripts with dynamic make script factories?

```#4be926fb``` *As of 2016-07-07 11:14*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to implement a C++ make script factory that the make environment calls to get the make script to execute?

1) Consider a make script factory being able to analyze existing source code and generate the appropriate make script to build possible targets?

==&gt; Consider a command line environment may stream the make script to the make utility using a command line make script factory application?

&gt;make_factory &gt; make

...

2) Consider a makes script factory being able to provide different pieces of a make script (e.g. the list of source files)?

==&gt; Consider a make script factory could be queried for possible targets to build (it being able to generate possible targets by analyzing the source code)?  
==&gt; Consider a mek script factory could provide a list of source files to compile for a defined target (the client provides the target in the query for files)?  
==&gt; Consider a make script factory could be queried to provide possible #ifxxx switches (available source code profiling options)?  
==&gt; Co insider it should be able to produce a list of pre-processor switches and the ”decision points” for each switch (e.g., #ifdef MY_OPTION defined/undefined)?

3) Consider a make script factory could also be combined with a source file (translation unit) producer?

==&gt; Consider a source file producer could generate source files from a source file database (no need to store the actual source files)?  
==&gt; A source file producer could free the programmer from having to define actual source files (only write types, classes and methods)?  
…

4) Consider a make script factory as an extension of the IDE-idiom (project file based programming)?

==&gt; An IDE is a kind of make script factory in that it tries to hide the actual make script into a project with settings that defines how and what to build?  
==&gt; Consider with a make script factory the IDE can be freed from handling source files and just focus on writing code components (classes, types, methods)?  
==&gt; Consider pre-processor code snippets as just another level (digital world) of "source code objects” (e.g., macros, #ifdef structures)?  
...

…

Consider to delve into this idea of having a make script factory help with building C++ programs?  
...

{% endraw %}
