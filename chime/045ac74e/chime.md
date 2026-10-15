# Todo: Programming - Consider to design a C++ "File System" that assembles source code as if in the same project (same folder structure)

```#045ac74e``` *As of 2016-07-29 13:43*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to design a C++ File System that presents a file view (folder structure and content) that is adapted for a project but takes files and parts of files from other locations?

1) Consider a good name for the tool that creates (presents) this C++ File System to the build environment?

==&gt; Consider the name “Narnia” (as a reference to the parallel world behind the wardrobe in “The Chronicles of Narnia” by C. S. Lewis)  
…

2) Consider the C++ File System as based on the Digital World idiom?

==&gt; Consider the files to be entities of this world?  
==&gt; Consider the files to be transforms of files from the larger Platform World?  
==&gt; Consider how the binding between C++ File System files and Platform files are transforms that goes two ways?

==&gt; Can we imagine how edits of files in the C++ Files System is mirrored back to edits in the Platform files?  
==&gt; Consider if the transforms are one-to-one, one-to-many or many-to-may?  
…

3) Consider file transform to the C++ File System to enable extraction of only “what is used” (e.g. extraction of C?? Standard Library)?

==&gt; Consider that if the Project uses std::vector&lt;int&gt; only the std::vector&lt;int&gt; source is extracted and present in the C++ File System, version if &lt;vector&gt;?  
…

4) Consider the organisation into files and folders may be drastically different in the C++ File System compared to the underlaying Platform file system?

==&gt; Consider the C++ File System being allowed to represent all of the used standard library code into one file?  
==&gt; Consider it should be convenient to have the source code use the same #include statements as when built on platform files system?

==&gt; Consider it would b to confusing if the standard library includes in the source had to change to build in the C++ File System environment?  
…

5) Consider the C++ File System by default exposed each class and function as separate header/cpp files?

==&gt; Consider this would enable re-use of ones own code in an easy manner without having to restructure the platform file system architecture?  
...

6) Consider using a C++ “revers” parser and base file content to cover only the actual used ATS?

==&gt; See “[Todo: Programming - Consider if it is possible to create a C++ parser that parses in reverse order (from end to start)?](../17312851/chime.md)"  
==&gt; Consider that reverse parsing is the quickest way to get an AST of what is actually used in code?  
==&gt; But also consider that the same AST can be created using normal parsing and then stripping away what is not used?

==&gt; Consider the content of C++ files in the C++ File Systems can actually be created by reverse-engerening the AST of each translation unit?

==&gt; Consider the AST only contains what is used (or can be made to do)?  
==&gt; Consider Clang AST may allow the actual source behind the AST may be retrieved and put into the files of the C++ Files System /the rest thrown away)?  
…

==&gt; Consider changing the translation unit would require the original (platform) files to be parsed again to add or remove as defined by the edited code?

...

...

Consider to delve into this idea of having a C++ File System with transformed files only containing what is used and organised in a project efficient way (not as in the actual platform file system)?  
...

{% endraw %}
