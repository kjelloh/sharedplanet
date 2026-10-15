# Todo: Programming - Consider if it is possible to create a C++ parser that parses in reverse order (from end to start)?

```#17312851``` *As of 2016-07-29 13:33*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to see if it is possible to make a C++ parser that parses backwards to allow it to only parse code that is actually used?

1) Consider that by parsing backwards the parser “knows” what is used and can skip code that is no “in play”?

==&gt; Consider the optimisation possible if backward parsing some example code?

> #include &lt;vector&gt;  
> void f(const std::vector&lt;int&gt; v) {  
> std::vector&lt;int&gt; result({1,2,3,4});  
> return result;  
> }

==&gt; parsing “return result” makes the parser know the identifier result needs definition.

==&gt; parsing result definition it knows std::vector&lt;int&gt; needs definition.

==&gt; parsing void f(…) it knows f is defined (the body is already parsed)

==&gt; Parsing #include &lt;vector&gt; it knows only std::vector&lt;int&gt; is required

==&gt; While parsing vector.h it must gather “everything” until it hits std::vector template and may collapse all knowledge to only that (forget everything else because it is not used in translation unit)?

...

2) Is there some information on the web about parsing backwards of source code?

==&gt; Wikipedia seems to define such a parser as an “inverse parser” (<https://en.wikipedia.org/wiki/Inverse_parser>)?

==&gt; This seem to be a candidate for intonation about thoughts on inverse parsing (<https://web.archive.org/web/20150131190937/http://www.erasmatazz.com/library/the-journal-of-computer/jcgd-volume-6/how-to-build-an-inverse.html>)?

==&gt; Hm, It seems an “Inverse Parser” refers to command line argument grammars (<https://news.ycombinator.com/item?id=10724570>)?

==&gt; On command line arguments are passed in a “specialisation” order (getting more and more complete)?

==&gt; This thread seem to also disagree with the term “Inverse Parser” (<https://www.reddit.com/r/programming/comments/3wneft/how_to_build_an_inverse_parser/>)?

...

3) Consider the problem of C++ forward parsing is that everything needs to be cached until the end of the translation using where we know what is actually used?

…

4) Consider to design a C++ based language where one programs top down (includes at the end)?

==&gt; Consider to actually write the code bottom-up (assuming the last instruction is at the top of the screen?

> void f(const std::vector&lt;int&gt; v) {  
> return result;  
> std::vector&lt;int&gt; result({1,2,3,4});  
> }

> #include &lt;vector&gt;

==&gt; But then existing source code would not be legal?

==&gt; Or can we imagine the parser to automatically reverse existing code (to make it reverse C++ language)?

…

…

Consider to delve into the idea of a “reverse parser” processing a grammar backwards to enhance C++ parsing speed?

...

{% endraw %}
