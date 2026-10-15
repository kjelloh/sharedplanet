# Todo: ibi library key path - Consider to enable easy construction of Tries (Index and hash) with corresponding key-path support for member reference?

```#2035cd75``` *As of 2017-01-28 19:53*

[mail plain/text](mail.txt)

{% raw %}
Listening to a talk (<https://www.youtube.com/watch?v=I7IdS-PbEgI&feature=youtu.be>) by Lee Byron, the autor of immutable.js, I realize that Tries are in fact a Composite with nodes having a key-path of sub-ranges of an index (Index Trie) or of a hash value (A Hash Trie).

==&gt; Also see "Todo: Darwinet - Consider Javascript React with immutable.js or Mori actually kind-of already implemented Darwinet immutable MIV and delta history mechanisms?"

1) Consider to enable the ibi library to conveniently create paths into both index and hash Tries?

==&gt; Consider an eight bit index into a four level deep Index Trie the node-path to a value with key 10001101 is the path {10,00,11,01}

==&gt; Consider the string key ”R” into a Hash Trie where hash(”R”) = 01010010 the key path to this value is index key path {01,01,00,10} but traversed in reverse order {10,00,01,01}

==&gt; Note: Selecting a value in a Hash Trie with the Hash Trie Key Path requires we allow the value to be found at a node with a shorter key path (see definition of Hash Trie in the talk)

==&gt; Also Note that The Hash Trie, being a Hash table, means each node stores all values with the same hash (so final step is to ensure we return the value with the correct key)

…

Consider to delve into this idea of adding support for Index and Hash Tries by creation and processing of key-paths into these types of structures?

...

{% endraw %}
