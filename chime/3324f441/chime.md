# Todo: C++ - Consider to try to implement a "C++ Crawler" that can extract required source code from available projects?

```#3324f441``` *As of 2017-03-18 18:26*

[mail plain/text](mail.txt)

{% raw %}
Consider if we could use a “C++ Crawler” instead of #include and make-files to have our source code use code from other sources?

==&gt; Also see “Todo: Programming - Consider to check out TomTom C++ open source cpp-dependencies project to analyze C++ translation unit dependencies?"

==&gt; Also see “Todo: Programming - Consider a source-file-system for c++ that exposes a "representation-view" of representation-invariant (e.g. AST-graph) c++ translation units? “

==&gt; Also see “Todo: C++ Programming - Consider ways to totally eliminate the need fro a build-system (C++ source code based build definition)?"

==&gt; Also see “Todo: C++ Programming - Consider to discuss how to eliminate (automate) C++ Source Files (zero overhead pre-processing)?”

1) Consider the C++ Crawler should be able to extract header-code required by the code we write in our own translation unit?

==&gt; Consider the code “std::vector&lt;int&gt; v;” should make the crawler extract the required declarations from found &lt;vector&gt; file?

==&gt; Consider the extracted code to be ONLY the required one (it should be minimal but still enable built code to be ABI compliant)?

…

2) Consider the C++ Crawler should be able to extract and generate translation units from external libraries?

==&gt; Consider we want to use the C++ library VMime (<https://www.vmime.org>)?

==&gt; This code seems to be written and tested for Linux (and thus wont build in Visual Studio)?

==&gt; Consider how C++ Crawler should be able to extract and create C++ translation unit(s) for Visual Studio build (using existing VMime translation unit source code)?

==&gt; Consider each reference in own code to VMime declarations should make C++ Crawler extract required header code?

==&gt; Consider also that required C++ definitions should be extracted by C++ Crawler to balance the extracted header code?

==&gt; Consider ways for the C++ Crawler to generate cpp-files and hpp-files for the exraced code?

…

3) Consider to base the C++ Crawler on Clang lib tooling?

==&gt; Consider it could be possible to use Clang tooling to create a C++ Crawler to find referenced code in source files?

==&gt; Consider how we can make C++ Crawler “see” init #ifdefs?

==&gt; Consider to have C++ Crawler be able to find pre-processor conditionals to create possible configurations for the code to crawl?

==&gt; Consider the C++ Crawler should be able to “see” into conditional code that the applied compiler can not (e.g., see Linux code when used for Visual Studio)?

...

…

Consider to delve into this idea to use a C++ crawler to extract referenced code from external source based on references in ones own code?

...

{% endraw %}
