# Todo: Programming - Consider to make a C++ stack overflow web-crawler that finds and modernise C++ code published there?

```#1490ba8e``` *As of 2016-08-14 18:11*

[mail plain/text](mail.txt)

{% raw %}
Could it be a fun idea to try and implement a web-crawler that searches for C++ example code on stack overflow and purposes refactorings to make found C++ code into modern C++?

1) Consider a good name for this project to attract a community to help its development and hosting?

==&gt; Consider a name that has something to do with some sure hero (fighting the bad guys)?

==&gt; Consider name that refers to some famous discovery or discoverer?

==&gt; Consider the name “eureka” (as a reference to archimedes exclamation when he understood stare displacement)?

…

2) Consider how to cut-and-paste the code into a compilable cpp-file?

==&gt; Consider how to cut-and-paste the found code into a compilable main.cpp file?

==&gt; Consider to aim at code that is dependent on some small set of standard includes (e.g. &lt;string&gt;, &lt;vector&gt;, &lt;iostream&gt;)?

==&gt; Consider to identify code that already contains a main?

…

3) Consider to try the found code using the clang-tidy tool (<http://clang.llvm.org/extra/clang-tidy/index.html>)?

==&gt; Consider to apply the clang-tidy to the cpp-file with the found cpp-snippet and output the result in some understandable way (i.e., the modernised version)?

==&gt; Consider to apply clang-tidy static checks if there are any?

...

4) Consider to apply some static analyser to the code that tests it compliance to the C++ Core Guidelines (<https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md>)

==&gt; Consider to apply Visual Studio static checks for Core Guidline compliance?

...

5) Consider to implement actors as targets of a GitHub project?

==&gt; Consider one target to be the actual “crawler” that crawls stack overflow for C++ code?

==&gt; Consider this to be the seed for this project?

**WE ARE HERE...**

==&gt; Consider one target to be the “tidy applier” that tries to bind the code into a compilable cpp-file?

==&gt; Consider one target to be a “sharer” that updates some sharable database with found code snippets and proposed modernised code?

==&gt; Consider one optional target to be one that injects modernised code into the stack overflow thread (or injects a reference to available C++11, C++14, C++17 modernised versions)?

…

6) Consider to implement some way of sharing (co-operating) on finding code snippets and produce modernised code?

==&gt; Consider to share using BitTorrent files?

==&gt; Consider implementing some file naming algorithm to enable a compartment-ized (file based)) database?

==&gt; Consider to enable the community to provide web-hosted services one may visit to study C++ code snippets and their proposed modernised versions?

…

…

Consider to delve into this idea of crawling the web for C++ code snippets and applying some C++ tooling to generate modernised C++ code?

...

{% endraw %}
