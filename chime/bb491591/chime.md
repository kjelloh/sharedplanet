# Todo: C++ - Consider how move-semantics relates to immutable data structures (move means mutation)?

```#bb491591``` *As of 2017-01-30 12:30*

[mail plain/text](mail.txt)

{% raw %}
So, what can we say about the usability or impact on move-semantics when applying functional programming and immutable (persistent) data structures?

1) Consider move-construct from non-const rvalues are ok?

==&gt; Consider non-const r-values are constructed temporaries (unnamed and thus not shared)?

2) Consider what ”moves” that are NOT allowed in the immutable and functional world of things?

==&gt; We can’t allow move-from a named object?

==&gt; The moved-from object will be mutated (and if it is also shared we can’t allow this)?

==&gt; We can’t allow perfect forwarding of non r-value references?

==&gt; This would potentially allow a move-from the referenced object by someone in the call chain?

…

…

Consider to elaborate more on this clash between move-semantic and immutable data objects?  
...

{% endraw %}
