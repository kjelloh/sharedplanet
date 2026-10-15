# Todo: Darwinet - Consider what conflicting MIV mutations we can actually imagine (and what mutations that we can treat as commutative)?

```#da60226b``` *As of 2017-02-22 17:00*

[mail plain/text](mail.txt)

{% raw %}
So, what can we say about what types of mutations that may conflict and what ones we can treat as commutative (automatically merge)?

1) Consider what Text mutations that we should treat as conflicting ones?

==&gt; Consider changes to the same work always conflicts (never merge these as done in WOOT)?  
==&gt; Consider changes to the same paragraph MAY conflict (it may or may not be ok to merge asynchronous edits to the same paragraph)?  
==&gt; Consider changes to separate Paragraphs ALWAYS commute (We may always automatically merge asynchronous edits to separate paragraphs)?  
…

2) Consider different Text must apply different Edit Conflict Rules (e.g. Text for reading versus Text as Computer Source Code)?

==&gt; Consider a ”Paragraph” in written text is different from a ”Paragraph” in Computer Source Code?  
==&gt; Consider to have Darwinet ”know” about some set of Semantics that defines the rules for what is considered commutative or conflicting asynchronous edits to the text?

==&gt; Consider Darwinet to know about ”Western Language Text” Semantics (Words, Sentences, Paragraphs, Chapters, Sections)?  
==&gt; Consider Darwinet to know about Computer Language Semantics (e.g. a set of the most common languages like JavaScript, Java, Swift, C++, C, …)?  
…

3) Consider what set of Structural Changes must be treated as Conflicting?

==&gt; Consider ARRAYS may sometimes be allowed to apply the WOOT insert/Delete strategy (also when insert/delete are made to the same location)?

==&gt; Or, Always consider Insert/Delete in relation to a ”tombstone” (locally deleted) as Conflicting (and must result in a branch)?  
==&gt; Consider the WOOT example Edit_1: ”HELL” —&gt; ”HELLO” and Edit_2: ”HELL” -&gt; ”HEY” MUST conflict (Not result in WOOT Merge ”HEYO”)?  
…

==&gt; Consider TREE structure change may conflict?

==&gt; Consider moving a node to a ”tumbstone” (locally deleted) node must be regarded as a conflict (e.g. Node A moved to be sub-node of B while B is moved to be sub-node of A)?  
…

==&gt; Actually - Consider the general case is that mutations that relates to tombstones are ALWAYS to be treated as a conflict?  
==&gt; Further - A mutation in any structure where the path to mutated location contain tombstone nodes must always be considered a conflict?

==&gt; Hm… Not sure this holds?  
==&gt; It takes care of adding tree nodes to path that does no longer exist (tombstone nodes in the path means the path has been cut)?  
==&gt; It also seems to take care of adding a record member before or after a removed member (if we consider the path to be the location of the removed member)?  
==&gt; But what about Text where we allow tombstones in previous and following paragraphs (but not in the same word or sentence)?  
...

...

4) Consider conflicting Edits that ends up in the SAME STATE must be silently accepted and NOT result in branching?

==&gt; Is this a special corner case or will it be taken care of by the general optimistic-mutate-merge-later mechanism?  
…

…

Consider to delve deeper into this analysis of what mutations that Darwinet MIV must treat as conflicting (not silently merge into consistent but wrong merged state)?  
...

{% endraw %}
