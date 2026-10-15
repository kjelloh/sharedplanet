# Todo: Programming - Consider to follow up and understand Eric Nibblers C++ Ranges concepts for the standard?

```#47010d6a``` *As of 2016-07-08 11:30*

[mail plain/text](mail.txt)

{% raw %}
Studying different aspects of C++, DSL for Element Table encoding/decoding, tagged-range-ASTs and Darwinet Grid Computing (to name a few) the name Eric Niebler and his work on C++ Ranges for the standard has come up.

1) This seem to be a good talk on Cppcon 2015 (<https://www.youtube.com/watch?v=mFUXNMfaciE>)?

==&gt; At 3:40 he defines a Range

==&gt; A range is basically something with a beginning and an end that returns iterators or sentinel iterators.

==&gt; An iterate-able container is a Range.

==&gt; At 6:30 he defines Range Views

==&gt; Begin/End represented as Iterators/Sentinel

==&gt; Lazy sequence algorithm

==&gt; Lightweight non-owning

==&gt; Compose-able

==&gt; Non-mutating

==&gt; At 14:20 he defines his proposed Built-in Range Views

==&gt; Seems he puts Views (Not ranges) at the core of the library idiom?

==&gt; Seems he uses “Range” as a concept and Implement Range Views as lazy adaptors to manipulate output (still keeping underlaying data unmated)?

==&gt; He actually calls them Range Adaptors.

**WE ARE HERE...**

2) He seem to be in charge of an experimental implementation of C++ Ranges on Github published here (<https://github.com/ericniebler/range-v3>)?

3) He seem to have a home page here (<http://ericniebler.com>)?

==&gt; Although the last entry is from march 2015 (is this page dormant)?

4) Consider to compare his and others work on sequences when it comes to terms and idioms used?

==&gt; I’d like a **sequence** to be an actual existing container of iterate-able data of known length.

==&gt; I’d like a **Stream** to be a sequence where data can be consumed only at the beginning, length is unknown (streamed) and data not yet available will be in the future.

==&gt; I’d like a **vector** or a list to be just different implementation of iterate-able containers.

==&gt; I’d like a **view** to be an adaptor to a sequence or a stream (i.e. define an interface and possible a restriction to data)

==&gt; <https://github.com/ericniebler/range-v3/blob/master/doc/index.md>

“A view is a lightweight wrapper that presents a view of an underlying sequence of elements in some custom way without mutating or copying it. Views are cheap to create and copy, and have non-owning reference semantics."

==&gt; I’d like a range to be a view into an iterate-able sequence of data with a known size.

==&gt; How can we relate sentinel-defined ranges (Range end defined by a special sentinel data in the sequence)?

...

5) Consider to apply this Range concept to the implement tagged-range-ASTs?

==&gt; See “Todo: Programming - Consider to study Eric Nibblers Ranges to see if we can use it to operate on Range-trees?"

…

Consider to delve into his and related work on the concept of Ranges to see what we may learn and optimally apply to the design defined by related Todo:s?

...

{% endraw %}
