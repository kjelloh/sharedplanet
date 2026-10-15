# Todo: Darwinet - Consider Javascript React with immutable.js or Mori actually kind-of already implemented Darwinet immutable MIV and delta history mechanisms?

```#d6548533``` *As of 2017-01-28 20:04*

[mail plain/text](mail.txt)

{% raw %}
Reading and article on Javascript React and libraries immutable.js and Mori it seems to me they atcualy kind-of already apply the mechanism designed to be applied for Darwinet immutable MIV and Delta history?

1) Consider this talk on React and immutable.js (<https://www.youtube.com/watch?v=I7IdS-PbEgI&feature=youtu.be>)?

==&gt; The talk seem to be made by Lee Byron, the autor of immutable.js?

==&gt; This seems to be the ”Simple Made Easy” by Rich Hickie (inventor of Clojure) referenced by Lee Byron (<https://www.infoq.com/presentations/Simple-Made-Easy>)?

**WE ARE HERE...**

==&gt; He seems to define ”Persistent” as meaning that when we modify the structure into a new one, the old one persists?

==&gt; It seems this means we may implement immutable structures by having the new structure share the persistent un-changed structure?

==&gt; Implementing structures as DAGs (Directed Acyclic Graphs) means any new structure will have a new root node anytime we changed the structure (we have to create new copy of teh changed node and that change propagates all teh way to the root).

![](<Shared Structure.tiff>)

==&gt; Right lemon node the ”new/changed” one.

==&gt; Parent green nodes are new to accommodate referencing the new changed node (leaving the blue original structure persistent)

==&gt; Yellow nodes are shared structure and values.

==&gt; immutable.js seem to implemented DAGs as Tries (name from reTRIEve) and use them to implement persistent immutable Arrays and Records (although JavaScript calls records for ”Objects” = confusing)?

==&gt; Index Tries are DAG:s with nodes that are keys of a stored value key being the path of key-nodes to the value.

==&gt; In fact, given eight bit keys and four level deep Index Trie the node-path to a value with index 10001101 is the path {10,00,11,01}

**==&gt; Thus, an Index Trie may be used to represent a list (array)**

![](<Index Trie Example.tiff>)

==&gt; Hash Tries are DAGs with nodes that are any type of key (e.g., a string label) but the path to the key is represented by its hash!

![](<Hash Trie Key Path.tiff>)

==&gt; In this case the path to the value with key ”R” is the hash(”R”) = 01010010 turned into index key path {01,01,00,10} but traversed in reverse order {10,00,01,01}

==&gt; Also, the Trie is optimized so that in this case the last key 01 si not required to idenify the ”R” node (the path {10,00,01} is unique)

**==&gt; Thus a Hash Tries is good for key-value maps (and thus in effect to represent Records and Sets)?**

2) Consider this article ”*The power of Immutability and React, **Building a Sequencer with React and Immutable.js*" (<https://medium.com/@sharifsbeat/the-power-of-immutability-and-react-daf46f2a5f4d#.9carw6j9m>)?

==&gt; It seems we keep track of the change history by using immutable lists?

![](<React Javascript App Class.tiff>)

==&gt; It seems our State is an immutable record carrying this state grid value (items) and a list of historic items and future items (See undo/redo below)?

==&gt; Now undo is just popping the grid value (items) from our history and pushing it to our future (in effect making our grid the ”previous” one)?

![](<React Undo Example.tiff>)

==&gt; Here we see that future is a list of immutable items values (grids) (we push grid value ”items” to the future list)

==&gt; We also see that history is also a list of immutable item values (grids) (we change items (grid) value to the last one in the history)

==&gt; And redo is just popping next future grid value and push it to our history and then set our grid value to our current last history?

![](<React Redo Example.tiff>)

**==&gt; Q: So, how does React render the grid?**

==&gt; It seems React provide some syntactic sugar to enable writing an update method that only creates new parts of the immutable data structure that actually changes (leaving unchanged parts just referring to previous state)?

==&gt; Consider this page about React update (<https://facebook.github.io/react/docs/update.html>)?

...

3) This seem to be a good page that described React and Immutable State (<https://facebook.github.io/react/tutorial/tutorial.html>)?

==&gt; It seems change-detection of Immutable data is done by checking if the object we reference has changed (new state == new object)

> ”*Determining how an immutable object has changed is considerably easier. If the object being referenced is different from before, then the object has changed. That's it.*"

…

Consider to follow up on these leads into Javascript React and rendering of immutable data?

...

{% endraw %}
