# Todo: Programming - Consider to understand and document (optionally cross-platform) cmake based windows DLL generation?

```#e5222c60``` *As of 2016-08-26 10:09*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to try and understand windows DLL generation and also find ways to make such a project work cross platform and cross compilers?

1) Consider to understand how to generate DLL:s using Visual Studio?

==&gt; Consider this blog post on msvs DLL projects, name mangling and calling conventions (http://www.ni.com/white-paper/3056/en/)?  
...

2) Consider to understand how to generate DLL:s using Embarcadero (Borland idiom) RAD Studio?

3) Consider to understand how CMake handles library projects?

4) Consider to create a cmake based cross platform and build toll chain library project?

==&gt; Consider how to make the project generate a DLL on Windows using msvs, RAD Studio, MinGW gcc and clang?

==&gt; Consider how to make the project generate a Linux Archive (.a) file on Linux?

==&gt; Consider how to make the project generate a MacOS archive (.a) file on Apple?

5) Consider to understand the EXPORT naming mechanism (name mangling and call conventions)?

==&gt; Consider to understand how to use msvs to export functions with preferred names and calling conventions?  
==&gt; Consider to understand how to use RAD Studio to export functions and preferred names calling conventions?  
==&gt; Consider to understand how to use MinGW Gcc to export functions and preferred names calling conventions?  
==&gt; Consider to understand how to use MinGW Clang to export functions and preferred names calling conventions?

==&gt; Consider to understand how to use Linux Gcc to export functions and preferred names calling conventions?  
==&gt; Consider to understand how to use Linux Clang to export functions and preferred names calling conventions?

==&gt; Consider to understand how to use MacOS XCode to export functions and preferred names calling conventions?

…

Consider to make this an open source project to share the findings with those that are interested?  
...

{% endraw %}
