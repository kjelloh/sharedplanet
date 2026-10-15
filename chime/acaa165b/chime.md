# Todo: Darwinet - Consider to motivate survival-of-fittest-view with the argument that views always shows meaningful state where a merge algorithm will always create an invalid state?

```#acaa165b``` *As of 2017-03-07 12:18*

[mail plain/text](mail.txt)

{% raw %}
Consider to motivate the Darwinet survival-of-the-fittest-view with the argument that branched views due to conflict preserves valid states (the two conflicting states) while merge-for-consistency in the case of conflicts will always result in an invalid state?

1) Consider how Google Wave Operational Transformation mechanism would always produce an invalid consistent state in case of conflicting edits?

Consider the text ”Go”

Client A deletes ’o’ and adds ”et” to produce ”Get"

Client B adds ”at” to produce ”Goat"

==&gt; Depending on how A and B edits gets merged (synchronized in time) Wave could solve these conflicts to a single consistent state in different ways.

==&gt; Delete ’o’, add ’”at”, add ’et’ = ”Gatet” (invalid state no edits intended)

==&gt; Add ’’at”, Delete ’o’ FAILS (invalid state no edits intended)

...

2) Consider how the WOOT algorithm would always produce an invalid state in case of conflicting edits?

Consider the text ”Go”

Client A deletes ’o’ and adds ”et” to produce ”Get"

Client B adds ”at” to produce ”Goat"

==&gt; WOOT usage of tombstones are able to synchronize also deletions

==&gt; At A: ”Goet” (invisible ’o’ = deleted) + Add ”at” after ’o’ results in ”Goatet” or ”Goetat"(both invalid states no edits intended)

==&gt; At B: ”Goat” + Delete ’o’ + Add ”et” after ’o’ results in ”Goetat” or ”Goatet” (both invalid states no edits intended)

3) Consider Dartwinet branch-on-conflict preserves both intended but conflicting state for later selection?

Consider the text ”Go”

Client A deletes ’o’ and adds ”et” to produce ”Get"

Client B adds ”at” to produce ”Goat”

==&gt; Darwinet will reproduce the correct conflicting states on both nodes A and B.

==&gt; At A: -------- 1:”Go” --- d Delete ’o’ --- d Add ”et” --- 3: ”Get”

==&gt; At B: -------- 1:”Go” --- d Add ”at” --- 2: ”Goat”

---------------------------------------------------------------------------------------

==&gt; At A: -------- 1:”Go” — 1.1.1:d Delete ’o’ —1.1.2: d Add ”et” — 1.1.3: ”Get” view&#91;1.1.3&#93;

|

— 1.2.1:d Add ”at” — 1.2.2: ”Goat” view&#91;1.2.2&#93;

==&gt; At B: -------- 1:”Go” — 1.2.1:d Add ”at” — 1.2.2: ”Goat” view&#91;1.2.2&#93;

|

--- 1.1.1:d Delete ’o’ — 1.1.2:d Add ”et” —1.1.3: ”Get” view&#91;1.1.3&#93;

==&gt; Note: Each node creates branches 1 for Node A and brach 2 for Node B (requires algorithmic consensus on branch names for Node IDs cross network)

==&gt; Note: Darwinet now needs a mechanism to promote A and B to decide on a common view (view 1.1.3 or 1.2.2) - I.e., a survival-of-fittest-view mechanism that has the ability to converge to consistent view?

…

…

Consider to expand on this argumentation for the survival-of-the-fittest-view idiom and puit it into the Darwinet paper?

...

{% endraw %}
