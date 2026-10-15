# Todo: Programming - Consider to understand and apply C++ Coroutines and follow if and when it gets implemented into compilers and the standard?

```#05530f6d``` *As of 2016-09-08 16:17*

[mail plain/text](mail.txt)

{% raw %}
Consider it would be a good idea to follow, try out and understand the C++ coroutine proposal and technical specification implementation to help write future safe and easy to read asynchronous C++ programs?

1) Consider this talk as a good starting point to understand the Microsoft initiative (<https://www.youtube.com/watch?v=YYtzQ355_Co>)

==&gt; Consider this is somewhat based on this 2015 talk that also talks about the motivation and idiom (<https://www.youtube.com/watch?v=_fu0gx-xseY>)?

…

2) Consider to write a test-application in visual studio that uses coroutines to implement a TCP/IP proxy xml sniffer application?

==&gt; Consider to implement it to sniff epas xml messages to and from a T?

==&gt; This seem to be one example of C++ using Microsoft coroutine implementation (<https://blogs.msdn.microsoft.com/vcblog/2016/04/04/using-c-coroutines-to-simplify-async-uwp-code/>)?

> #include &lt;experimental\\resumable&gt;  
> #include &lt;pplawait.h&gt;  
> ...

==&gt; And it seems we need to provide the “/await” command line parameter to have the compiler allow usage of the coroutine language features?

> > *“Of course, the code has to be compiled using the /await option in the command line:"*

…

3) Consider to understand the C++ standard papers that defines the progress of the coroutine proposal?

==&gt; Consider this post as having good leads to the current discussions on coroutine (<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0054r0.html>)?

==&gt; Consider this is the current proposal N3708 (<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3708.pdf>)?

==&gt; Or is it this one N4402 (<https://isocpp.org/files/papers/N4402.pdf>)?

==&gt; Consider P0057R5 is the revision 5 of the current TS (<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0057r5.pdf>)?

==&gt; Or, is the TS on the way but not yet published?

==&gt; Consider this page contains july status on C++ standardisation papers (<https://isocpp.org/blog/2016/07/P30>)?

==&gt; This post seem to indicate the Coroutine will be published as a TS (<https://meetingcpp.com/index.php/br/items/cpp17-and-other-future-highlights-of-cpp.html>)?

==&gt; And Coroutines did not get it into C++17?

4) Consider to follow and try out Clang support for coroutines?

==&gt; It seems it is Microsoft Gor Nishanov that works on the Clang implementation of coroutines (<http://lists.llvm.org/pipermail/cfe-dev/2016-April/048325.html>)?

“Discussion on the ISO C++ list&#91;1&#93; suggests that Gor Nishanov of Microsoft is working on a clang implementation"

==&gt;

5) Consider to compare (and try out) the Boost coroutine implementation?

==&gt; This seems to be a good survey of using the Boost coroutine library (<https://media.readthedocs.org/pdf/stackless-coroutine/latest/stackless-coroutine.pdf>)?

…

Consider to elaborate on the coroutine proposal in C++ to know what and how to use to write good, readable and future safe, cross platform asynchronous programs?

...

{% endraw %}
