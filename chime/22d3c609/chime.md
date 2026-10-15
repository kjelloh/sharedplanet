# Todo: Darwinet - Consider to implement text as trees where each node defines a branch between not mutated range and mutated range of text to enable easy Text Delta Conflicts?

```#22d3c609``` *As of 2017-01-21 14:22*

[mail plain/text](mail.txt)

{% raw %}
Consider in Darwinet we need a way to detect if individual Text Deltas in a sequence commute (the same end state is reached independently of application order), and that a way of doing this is to have each delta create a text range tree node with one branch being the mutated range and the other branch the un-mutaed range?

1) Consider this enables instant detection of conflicting deltas?

Consider the Text = ”Hello - My name is Harry and I am a Programmer”

Consider two Darwinet views V1 and V2 each with its own MIV instance MIV1 and MIV2.

1) Consider MIV1 mutates the Text by changing the name to ”Alice” (Delta D1)

Text = node

|

--------------------------------------------------

| | |

L D1 R

”Hello - My name is ” ”Harry” " and I am a Programmer”

”Alice"

2) Consider MIV2 mutates the Text by changing the occupation to ”Designer” (Delta D2)

Text = node

|

----------------------------------------------------------------------

| | |

L D2 R

”Hello - My name is Harry and I am a ” ”Programmer” ”"

”Designer”

==&gt; When MIV2 receives D1 it will be able to detect that the mutation is to be made to an un-mutated branch of the text tree which is ok (does not conflict with the mutations made)

Text = node

|

----------------------------------------------------------------------

| | |

L D2 R

”Hello - My name is Harry and I am a ” ”Programmer” ”"

| ”Designer”

-------------------------------------------

| | |

L D1 R

”Hello - My name is ” ”Harry” " and I am a ”

”Alice"

==&gt; When MIV1 receives D2 it will be able to detect that it mutates an un-mutaed part of the text tree (does not conflict with the mutations made)

1) Consider MIV1 mutates the Text by changing the name to ”Alice” (Delta D1)

Text = node

|

--------------------------------------------------

| | |

L D1 R

”Hello - My name is ” ”Harry” " and I am a Programmer”

”Alice” |

------------------------------------------------

| | |

L D2 R

" and I am a ” ”Programmer” ”"

”Designer"

2) Consider how we can represent these text trees in a way so that a Delta may locate its target in the text in the tree state of the receiver?

==&gt; A delta that targets a range in the tree of the local instance state must be applicable in the state of the tree of the target instance state (see example above)

==&gt; We must be able to locate the target range in trees where the range before and range after has been mutated compared to the tree where the delta was created.

==&gt; In the example above, D1 must be able to operate on tree where D2 has already been applied (and vice versa)

...

3) Consider how ”deep” the mutation tree of the text must be and when we can collapse the tree for branches we no longer need?

==&gt; Note that this approach will always work.

==&gt; Note that this approach may be expensive depending on how we design storage of the branching text (may we implement it as immutable text object that only stores the mutation)?

...

4) Consider the alternative is to always branch for Text Deltas and then apply auto-merge if the branching Text states does not conflict?

==&gt; Compare if this this approach is more or less expensive than having the Text itself model the mutation in a Text Tree?

...

…

Consider to delve deeper into this problem of efficient handling of identifying Text mutations that commute?

...

{% endraw %}
