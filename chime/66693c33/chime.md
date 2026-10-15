# Todo: Programming (Darwinet) - Consider if Fenwick (Binary Indexed Trees) may be used to make Path access to composite structures efficient to modify and traverse?

```#66693c33``` *As of 2017-05-16 13:21*

[mail plain/text](mail.txt)

{% raw %}
Could the Fenwick Tree be used to implement Path indexed Composite data structures?

1) Consider this good tutorial on Fenwick (Binary Indexed) Trees (https://www.youtube.com/watch?v=v_wj_mOAlig)?

2) Also consider this ACUU 2017 talk ”” with a C++ implementation of Fenwick Trees (https://www.youtube.com/watch?v=-tkl8UYVFT4&index=1&list=PL9hrFapz4dsNYgaDy3CL76Cz2J_jSZrHA)?

3) Consider traversing a Path is isomorphic to summarize indexes (and thus path traversal may be replaced with Binary Index Tree traversal)?

==&gt; The Fenwick Tree is efficient in accessing and modifying index sums (only range sums are stored and needs to be updated)  
==&gt; Consider how this maps to ”adding” nodes in a Path index (can a sub-path be viewed as an ”addition” of each node in the path)?

==&gt; Consider if the ”index sum” maps to an element reference adressed by the sub-path ”sum” (the reference to the element referred to by the sub-path)?

==&gt; It seems we will get a new Fenwick tree for each possible path into the data structure (each path has different ”sums”, i.e. traverse the elements in the structure differently)?  
…

…

Consider to study the Fenwick Tree in more details to understand for what it is used and if it may be applied to make Path access to data structures more efficient?  
...

{% endraw %}
