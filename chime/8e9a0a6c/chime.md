# Todo: Programming - Consider to write a C++ Standard Proposal for String character-set-and-encode aware semantics?

```#8e9a0a6c``` *As of 2016-04-03 14:30*

[mail plain/text](mail.txt)

{% raw %}
Could we imagine to present to the C++ standard committee a proposal on how to correctly process and transfer Text in C++ applications?

1) Consider to state the problem of correctly express Text “meaning” and “Representation”?

==&gt; See “Todo: Programming - Consider to design a String "type" that bridges text "meaning" and text encoding?”

2) Consider to relate Text processing to contemporary discussion on C++ extensions like ranges, concepts and GPL?

==&gt; Consider the importance of being able to preserve Text “meaning” in API:s using Concepts?

==&gt; The programmer should be notified at compile time or run-time if passing a Text that is not represented as required?

==&gt; Consider to relate Strings to Nieblers Ranges and the problem of begin/end versus being/end-sentinel ranges?

==&gt; String ranges comes in both flavours (known length std::string and null-terminated sentinel-end ranges)

==&gt; Consider these to be totally different types of ranges (especially when studied from a concurrency perspective)?

==&gt; A sentinel-terminated string can be parallel-processed only as long as the code preserves at least one sequential operation of looking for the sentinel?

==&gt; A known-length string may be broken up using fix-location splitting schemes?

3) Consider to relate an enhanced Text processing idiom to the GPL library and string views?

==&gt; String views seem to only make Code-Unit-Sequences safe (not to help with adding Code-Point-Sequence-Aware processing)?

4) Consider to relate an enhanced Text Processing Idiom in the language to existing string literal semantics?

==&gt; How can we make character-set aware string literals (e.g. u”” and u8””) to fit with proposed Text processing semantics?

==&gt; How can we make “raw” string literals (unknown or source-code-defined Code Point Sequences) to fit with Text Processing Semantics?

…

5) Consider to relate en enhanced Text Processing Idiom with the Value Semantics proposed (discussed) by John Lakos

==&gt; See “Todo: Programming - Consider to find an enhanced C++ String representation and manipulation with a proper value semantics and view abstraction?”

==&gt; Explicitly see "Consider what we can say about string value semantics by referring to John Lakos proposal of value semantics (<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2479.pdf>)?"

==&gt; Also see his cppcon 2015 talks (although quite unclear and noisy) (<https://channel9.msdn.com/Events/CPP/CppCon-2015/CPPConD04V015>) (<https://www.youtube.com/watch?v=0EvSxHxFknM&ebc=ANyPxKoWBmqLt7y88vSnTAn-SiLVrBs2LUj78-SS9EVcbjcWBfwUUtMz10adAy8X4DuR7D0YctHK>)

==&gt; What is the value of a string according to John Lakos?

...

6) Consider to relate proposed Text Processing idiom to C++ discussion on parallelism and concurrency?

…

…

Consider to delve into

{% endraw %}
