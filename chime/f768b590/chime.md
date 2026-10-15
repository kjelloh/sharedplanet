# Todo: Darwinet - Consider to study and understand how LCS (longest common subsequence) and Suffix Trees (Tries) maps to possible base for MIV Deltas?

```#f768b590``` *As of 2016-08-20 17:11*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to compare Suffix Trees with LCS (Longest Commons Sequence) or its counterpart Shortest Common Subsequence (SES)?

1) It seems a Suffix Tree should have something to do with (or even define) the LCS (or the SES)?

==&gt; Consider to delve into the data structures and algorithms to generate them, to see what they have in common?

==&gt; Consider if and how to apply them for Darwinet Delta needs?

==&gt; Consider to use them to generate String deltas?

...

==&gt; Consider if we could create Suffix Trees of keys fro objects (in effect applying Suffix Tree services also for sequences of complex objects)?

==&gt; Consider if this could be used to compress Delta Streams (find patterns in Delta sequences)?

==&gt; Consider if this could be used as an efficient way of mapping branches of Delta Trails (the node of a Trie effectively defines a branch point)?

...

2) Consider this blog post on the Ukkonen Algorithm to generate Suffix Trees (or Tries) (<https://en.wikipedia.org/wiki/Ukkonen%27s_algorithm>)?

==&gt; It seems a Suffix tree is an implementation of a “Trie” (<https://en.wikipedia.org/wiki/Trie>)?

> *“In computer science, a trie, also called digital tree and sometimes radix tree or prefix tree (as they can be searched by prefixes), is a kind of search tree—an ordered tree data structure that is used to store a dynamic set or associative array where the keys are usually strings. Unlike a binary search tree, no node in the tree stores the key associated with that node; instead, its position in the tree defines the key with which it is associated"*

3) Consider this blogpost on Suffix Tree generation using the Ukkonen Algorithm (<http://www.murrayc.com/permalink/2016/08/19/suffix-tree-ukkonen-c/>)

==&gt; Consider this video talk explaining the Ukkonen algorithm referenced by the blogpost (<https://www.youtube.com/watch?v=aPRqocoBsFQ>)?

4) This wikipedia entry on SES seems like a good start (<https://en.wikipedia.org/wiki/Shortest_common_supersequence_problem>)?

5) Consider to compare with implementation and leads in existing Darwinet source forge repository (

==&gt; See checked out to my Windows 10 machine “C:\\subversion\\darwinet”

{% endraw %}
