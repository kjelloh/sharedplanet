# Todo: Programming - Consider to play with C++ objects with an identity that includes their location in memory (e.g., a hash och its address and value)?

```#4f7bef85``` *As of 2016-10-28 14:13*

[mail plain/text](mail.txt)

{% raw %}
It just came to my mind that it would be possible to define a C++ object that, on construction, stores an ID which is a hash of its adress and value. It would seem such an object could be made so that it is not possible to create a valid copy (the copy would have another ID and thus be a totally other object, not a clone)? Consider to elaboprate on this idea and if we can see usage of such objects to track "identity" (e.g., for electronic currency or IRL object representations)?

==&gt; Also see "[Todo: Consider to compare physical and digital identity?](../6bcea7be/chime.md)"  
==&gt; Also see "[Todo: Darwinet - Consider to relate Darwinet Identity Authorization mechanism to existing web-intiatives for this?](../5f7240ed/chime.md)"  
==&gt; Also see "[Todo: Consider to write about IRL-Single-Identity versus Digital-Multiple-Identity mapping of services?](../3602bb47/chime.md) "  
==&gt; Also see "[Todo: Consider to note and write down typical "Digital Identity" inconveniences?](../d046947f/chime.md)"  
==&gt; Also see "[Todo: Compare Darwinet with other digital identity synchronisation services like IFTT](../71f42c55/chime.md)"

1) Consider how such an object should implement construction, assignment, move and equal operator?

==&gt; Consider it should create its ID on construction taking its "this" pointer and value as input to its unique ID?  
==&gt; Consider it should not allow copy construct nor assignment (be immutable and not clone-able)?  
==&gt; Consider its operator== should check for ID equal-ness?  
...

2) Consider what we can use such objects to represent?

==&gt; Consider to use them to represent IRL existing objects (persons, physicla objects...)?  
==&gt; Consider such objects to represent physical objects that can't be a two places at once (can't be at two memory locations at once)?  
...

3) Consider the inability to ensure that two different objects can't actually have the same address (e.g., due to being on two different machines with the same adress space)?

==&gt; Consider to have the ID also include some environment unique value (e.g., a MAC address or some instation assigned GUID)?  
==&gt; Consider this would ensure that objects created in the "same" address space on two different platforms (machines, virtual environment) would actually also have different IDs?  
...

4) Consider ways of "beaming" (physicly moving) such objects around (and what such moves represent)?

==&gt; Consider ways to move such objects over the network to some other machine?  
==&gt; Consider such a "move" should behave simmillar to moving physical objects in real space-time (they are now at a new location)?

==&gt; But then we would actually like them to keep their ID but have a new location)?  
==&gt; Q: How can we move an object so that it keeps its ID but it still is not allowed to be at different locations at the same time?

==&gt; Consider a way to "beam" an object from one location to another (like star-trek beaming where the original disintegrates and the clone appears at the new location)?  
...

...

Consider to delve into the idea of such "location unique" objects, how to implement them and what we can use them for?  
...

{% endraw %}
