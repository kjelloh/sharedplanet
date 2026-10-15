# Todo: Programming - Consider to delve into the research and ideas of Hartmut Kaiser regarding "Concurrency and Threads are evil" and Parallelism is the thing?

```#6f3cafd2``` *As of 2016-03-20 19:58*

[mail plain/text](mail.txt)

{% raw %}
1) Consider to study his talk at Meeting C++ 2104 “Plain Threads are the GOTO of todays computing” (<https://www.youtube.com/watch?v=4OCUEgSNIAY&index=4&list=PLRyNF2Y6sca0Luy-3XreR2l2aQ7Hf5ODl>)?

==&gt; At 39:40 he states he like std::async and future&lt;&gt;.

==&gt; It is good because it ties nothing to the nation of “thread”

==&gt; The function provided to async will be run as-if on a separate thread (and we do not care)

==&gt; the returned future will be there or it will not. It is up to us to behave (the value access is synchronised efficiently without us having to implement it)

==&gt; At 39:50 he states “Concurrency TS (N4107)” (it seems to be published here <http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4107.html>)

==&gt; It should be called “Asynchronous TS” as it deals mostly with std::future.

==&gt; std::future in C++11 is mainly “useless” (you can’t do composition and get blocks without you being able to be pre.emptive)

==&gt; TS 4107 proposes solutions

==&gt; future&lt;T&gt;::then() (enables sequential composition)

==&gt; std::when_all(variadic list-of-futures) and std::when_any(variadic list-of-futures) to enable parallel composition.

==&gt; At 42:40 he states act they added in HPX to make this even better.

==&gt; He describes dataflow() that works like async but takes variadic number of futures and delays calling the function until all futures are ready.

==&gt; This “changes everything” he states.

==&gt; At 44:15 he refers to “Parallelism TS (N4105)” (it seems to be published here <http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4105.pdf>)

==&gt; He states it to be about Fork-and-join parallelism.

==&gt; He seem to mean that join is poisson to parallelism in that it defines barriers to make tasks before and after joins become parallel?

==&gt; At 48:50 he refers to adopting HPX extensions to cope with Eric Niebler proposal for Ranges.

==&gt; See “Todo: Programming - Consider to follow up and understand Eric Nibblers C++ Ranges concepts for the standard?”

==&gt; At 56:30 he describes the idea of “dependency trees of Futures”

==&gt; Such a Dependency tree is a composite Future (A node may be a leaf-future or a future combining sub-futures).

==&gt; The tree nodes may then be constructed using HPX dataflow that combines sub-futures with a function and returning a future.

==&gt; Consider to relate this to parallelise processing of tagged-range_ASTs as investigated in “Todo: Programming - Consider to design lazy (two-pass) Protocol Message Encoding and Decoding using tagged-range-ASTs?”?

==&gt; At 59:10 he starts describing an example of parallel Matrix Transposition on multiple Node computation (the matrix does not fit on one node/computer)

==&gt; Consider to delve into this example to understand Distributed (grid) Computing?

==&gt; Consider to relate this example to Darwinet Grid Computing?

…

**WE ARE HERE...**

2) What else has he produced in this area?

3) Consider to relate the importance of parallelism to lazy evaluation of Protocol Message Encoding and Decoding?

==&gt; Seems processing a each sub-range of a decoded range may be made in parallell?

==&gt; Once we have found sub-ranges of a range of an element in a message, then each such sub-range are “fixed” and its contents may be processed independently of other elements?

==&gt; Thus, having decoding made lazily we enables decoding to be parallelised?

==&gt; Move this idea into “Todo: Programming - Consider to model Protocol Stacks using State-Machine-Based Tagged-Range-Tree Transforms?”

==&gt; See “Todo: Programming - Consider to design lazy (two-pass) Protocol Message Encoding and Decoding using tagged-range-ASTs?”

4) Consider to relate these ideas also to Darwinet Grid-computing?

==&gt; What design should we go for to enable Darwinet Grid-computing to leverage of true parallelism?

…

Consider to study the ideas and publication of Hartmut Kaiser to see what we can learn and apply to other ideas?

...

{% endraw %}
