# Todo: Meta Value Model - Consider ways to embed and integrate existing Lisp system into our Meh Repl?

```#5b7e3d0f``` *As of 2017-08-07 23:56*

[mail plain/text](mail.txt)

{% raw %}
IS it possible for us to re-use some existing Lisp system and integrate it with our Meh Repls, in effect not having to implement the Lisp interpreter?

==&gt; Also see ”[Todo: Lisp - Consider to really understand the basic Lisp syntax and evaluation rules of Lisp expressions as base of our Meh (Meta Lisp) Repl?](../e84606f2/chime.md)"

1) Consider to embed ECL (Embedded Common Lisp) (<https://github.com/ageneau/ecl-mirror>)?

==&gt; It seems it may be used as two-way interaction between lisp evaluator and C/C++ code (<https://chriskohlhepp.wordpress.com/advanced-c-lisp/embedding-lisp-in-cplusplus-a-recipe/>)?  
==&gt; Although the emphasis seems to be to be able to call Lisp evaluator from C/C++ code (<https://common-lisp.net/project/ecl/>)?

2) Consider to be inspired and refactor from ”Lisp interpreter in 90 lines of C++” (<https://gist.github.com/ofan/721464>)?

==&gt; Is this a good role-model for Lisp parse and eval C++ code?  
…

3) Consider to study MAL List that is implemented in &gt; 68 languages (<https://github.com/kanaka/mal>)?

==&gt; Consider this talk “Joel Martin: Make Your Own Lisp Interpreter in 10 Incremental Steps Part 1 - λC 2016” on ten steps for making a Lisp (<https://www.youtube.com/watch?v=jVhupfthTEk>)?

==&gt; Consider this talk “Joel Martin: Make Your Own Lisp Interpreter in 10 Incremental Steps Part 2 - λC 2016” on ten steps for making a Lisp (<https://www.youtube.com/watch?v=X5OQBMGpaTU>)?

==&gt; Consider the C++ implementation of MAL (<https://github.com/kanaka/mal/tree/master/cpp>)?

**Hm… This seems really educating to build up a Lisp Repl in 10 steps!**

**...**

…

Consider to delve deeper into this idea to re-use by embedding some existing Lisp evaluator system?  
...

{% endraw %}
