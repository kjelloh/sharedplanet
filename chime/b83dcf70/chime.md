# Todo: Programming - Consider Files, Streams and Ranges are the same data object that just differs in its distribution in time?

```#b83dcf70``` *As of 2018-04-26 11:52*

[mail plain/text](mail.txt)

{% raw %}
Could it be valuable to view a File, A Stream and a Range as the same data structure but just different in how it is distributed in time?

==&gt; Also see “Todo: C++ - Consider to understand Reactive Programming from the semantics and design of RxCpp (Reactive Extensions for Cpp)?”

==&gt; Also see “Todo: C++ - Consider ways to turn Callback based asynchronous mechanism into a Reactive Observable model?"

1) Consider a File is in fact just bits ordered “in file”?

==&gt; Consider a File may be accessed both as a stream and as a range (with direct access to position in the range)?

…

2) Consider a Stream is just a more general way to represent data in a file distributed in time?

==&gt; Consider a stream can only be consumed in one end (no random access is possible)?

==&gt; Consider random access is not possible because unread data is still not possible (it will be available later)?

==&gt; Thus a stream represents data distributed in time (from the consumers point of view)?

…

3) Consider a Range is in fact a randomly accessible stream?

==&gt; Consider for a range we have the data stored in file “in space” (it has been read into randomly accessible memory)?

==&gt; Thus, A stream becomes a range once it has been read into memory (distribution in space is transformed into data distributed in address space)?

…

4) Consider to forward some critique to the C++ Ranges Proposal for not correctly model the “distribution in time” versus “distribution in address space”?

==&gt; Consider the C++ Ranges Proposal to introduce sentinel iterators is not good based on that it tries to treat Streams (range end known later) as Ranges (Ranges in time)?

==&gt; Consider how the C++ Ranges Proposal may be upgraded to better model Stream -&gt; Vector (Distribution in time transformed into distribution in adress space)?

==&gt; Consider to compare with how the “Reactive Programming Model” realises its algorithms to be about operation on data (events) distributed in time?

==&gt; Consider how C++ Reactive forwards the notion that C++ Ranges is about data distributed in space (<https://github.com/Reactive-Extensions/RxCpp>)?

> > “*The Reactive Extensions for C++ (RxCpp) is a library of algorithms for values-distributed-in-time. The Range-v3 library does the same for values-distributed-*in-space."

==&gt; But then with Ranges v3 sentinel iterators it actually tries to treat data distributed in time as-if it is distributed in space (i.e., **trying to make streams iterable**)?

==&gt; Consider how The Reactive Initiative seems to relate “Iterable” to “Distributed in space” and its counterpart “Observable” as “Distributed in time” (<http://reactivex.io/intro.html>)?

![](<Screen Shot 2018-04-26 at 11.40.23.png>)

...

{% endraw %}
