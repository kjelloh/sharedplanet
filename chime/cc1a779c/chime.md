# Todo: Programming - Consider to criticise Eric Nibblers Ranges proposal in that it does not differentiate between fixed-size- and literal-end Ranges?

```#cc1a779c``` *As of 2016-05-01 13:45*

[mail plain/text](mail.txt)

{% raw %}
Although beautiful from sequential processing point of view Eric Nibblers Ranges Proposal that treats any begin/end defined range in the same way?

1) But a range defined with an end-literal-iterator is in fact of unknown size and processing can’t be parallelised?

==&gt; An End-Literal iterator is really a kind of future-iterator (the location of the end is not yet known)?  
==&gt; A “normal” end-iterator knows its position so that (end-1) will point at the last element in the range?

==&gt; zero-ended strings are an example of a unknown-size-range (so we use and need this concept?  
…

Consider to elaborate on in what ways and to what consequence a literal-ended “range” differs from a known-size-range?

2) Elaborate on the different between a lazy-range and an unknown-size range?

==&gt; Can we imagine a lazy-fixed-size range to still allow parallel processing as opposed to lazy-literal-ended range?  
…

3) Eric Nieblers proposal seems to aim at working seamlessly with STL algoritms that operates on ranges in the form of begin/end iterators?

==&gt; Could this be the reason he proposes a Range to be any sequence of data defined by a begin/end iterator (because they will work with existing range algorithms)?  
==&gt; And by adding the literal-end-iterator this concept automatically covers the zero-terminated-strings?

==&gt; So, how should we formulate the difference between known-sized and unknown-sized (literal ended) “ranges”?

4) Consider to elaborate on model parsers as transforms from literal-ended “ranges” to fixed-size “ranges”?

==&gt; It seems a parser is about processing Code Units (character) or Code Units (binary data) in sequence until a pattern is found (a sub-range size is fixated)?  
==&gt; From this point of view some STL algoritms (e.g. find) are transforms from literal-ended range to fixed-size sub-range?  
...

5) Consider what changes we we should propose to the Ranges Proposal?

==&gt; Consider to state that a “Range” is always of known size (An end-iterator that exists always refers to the end of the range)  
==&gt; Such a “Range” may still be lazy in that although the range size is known, the data in the range may still not yet be created (or accessible)?

==&gt; Consider to define a “Stream" as an interface where one needs to iterate to access sequence members.  
==&gt; Consider to define a “Range” to be random accessible (and thus allows parallelisation?

==&gt; Consider to argue that any sequence where one needs to process data in sequence is, by definition, not parallelise-able (data must be sequentially processed) ?  
…  
.6) Consider to read the proposal and the parallelise-able research?

==&gt; Consider to follow up leads given by Eric Niebler in the Cppcast episode he participated in (http://cppcast.com/2015/12/eric-niebler/)  
…

Consider to elaborate on arguments why current Ranges proposal must be extended to enable compile-time and runtime detection and knowledge of literal-ended (not-yet-known range) from fixated-range (begin/end location known)?  
...

{% endraw %}
