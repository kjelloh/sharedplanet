# Todo: Darwinet - Consider to divide "change" into structural change and content (value) change

```#f4a53ad3``` *As of 2016-09-26 22:23*

[mail plain/text](mail.txt)

{% raw %}
It seems we would really benefit from recognizing that change is either a structural change or a content (value or size) change?

-1) Consider the difference between Value change and Structure change simply depends on whether the relation topology changes?

==&gt; It is a value change if no new path of relation between elements are created?

==&gt; It is a structural change if the paths of relations between elements changes?

==&gt; Changing Composite member presence is a structural change (element relation changes)?

==&gt; Array element adding, removing or moving does change element relations and is thus a structural change?

==&gt; Adding/Deleting or changing element references may change paths of element relations (and may thus be structural changes)?

==&gt; A value change is thus only changes internally to elements that does not affect its relation to other elements?

==&gt; Assigning to an number or text is a value change?

==&gt; Assigning to an image is a value change?

==&gt; Any change to a POD (Plain old data) is a value change?

==&gt; Assigning to a reference is almost always a structural change (new relation between elements created)?

...

1) So what should we condor to be structural change and what is value/content change?

==&gt; Adding a sub-node to a composite is a structural change

==&gt; Moving a sub-node of a composite is a structural change

==&gt; Removing a sub-node of a composite is a structural change

==&gt; Adding, moving or removing an element in an array is NOT a structural change (the topology is intact?)

==&gt; It is a structural change if the model changes (otherwise it s a value/size change)?

==&gt; The model of an array just says each element is of the same type (the size does not matter)?

==&gt; But the model must define new or removed sub-nodes of trees of different elements (and thus changing sub-nodes changes the model)?

==&gt; Changing an integer value is a value change

==&gt; Extending an array is a value change (The topology is the same but the size has changed?)

==&gt; Then it follows that any string change is a value change (not a structural change)?

==&gt; But then what about text document structures?

==&gt; Consider the structure of a text document changes if the structure is actually in the model (document parts are sub-nodes of a composite)?

…

…

==&gt; Consider we like to track move of element and values?

==&gt; Moving a range within a text is a value change (a special move-change of value within the element)?

==&gt; Consider we would like to track transforms (both structure and value transforms)?

==&gt; Consider encoding a text in UTF-16 instead of UTF-8 is a value transform (The value, but not the meaning has changed)?

==&gt; Consider sorting of elements in an array is a value transform (elements are moved but each element value are the same)?

==&gt; So, a re-organisation of elements is NOT a structural change (all values and instances remains but are relocated)?

==&gt; No - re-organisation of sub-elements in a composite is a structural change (will show up in the model)?

==&gt; Seems an Array member re-organisation is a value change while a Composite member re-organsiation is a structural change?

...

2) Seems we need to understand what we really mean with ”structure” and value?

==&gt; Why does it feel like an re-ordering elements in an array is not a structural change?

==&gt; Why does it feel like re-ordreing members of a composite is a structural change?

==&gt; Is it because in a composite each element is an individual of its own type while a member in an Array is just an anonymous member all with the same type?

==&gt; Then, what is ”Type”?

==&gt; Is it´that the ”Type” of an Array does not change if we re-order the elements while the type of a composite does change if elements are re-ordered?

**==&gt; Consider that ”Structure” matters to us because we think in space-time-relations (and structure makes us understand how to orientate in data)?**

**==&gt; And using the structure we can bring meaning to the value at a location in the structure?**

…

3) What about instance changes (when are they value changes and when are they structure changes)?

==&gt; It seems creating a new composite member IS a structural change?

==&gt; But creating a new member of an array is not a structural change?

…

4) What do we mean with Model Changes?

==&gt; Does model changes always imply structural change?

==&gt; Can we change Element Cardinality in the model without changing the structure?

==&gt; It feels like, yes, cardinal changes is just changes of array sizes (not actual structural changes)

==&gt; It seems this is because change to cardinality does not change the ”Type" of anything?

5) What about changes to elements that refers to other elements?

==&gt; Seems ”Reference” affects ”Structure” just as much as changed to member location or presence does?

==&gt; So ”Structure” is about how element values relates to each other?

==&gt; And ”Value/Size” does NOT change how values realtes to each other?

==&gt; But then array insert/move/delete of members DOES change structure (elements will get new before/after elements = change the structure)?

==&gt; So, Changes to Array members BOTH feels as value-change-only and structure-change-only (depending on how we look at it)?

…

6) Consider when the ”structure” of elements in an array (what element follows what other element) is of concern?

==&gt; An array can never branch (thats way we do not care of the order of elements and may view array membership changes as value changes)?

==&gt; No - If elements of the array are references, then the structure does change (the relationship graph topology change)?

…

7) So, can it be that we are only interested in structure changes that affects the topology (create branching paths between elements)?

==&gt; Consider a topological change to element relations IS a structural change?

==&gt; And a change that does NOT change the relation topology is a value change?

…

==&gt; Consider to study Topology Graph Theory (<https://en.wikipedia.org/wiki/Topological_graph_theory>)?

==&gt; Consider to study general Topology (<https://en.wikipedia.org/wiki/Topology>)

==&gt; Boost Graph seem to define Topology a bit different (<http://www.boost.org/doc/libs/1_46_0/libs/graph/doc/topology.html>)?

…

Consider to elaborate on what is structural change and what is value/size change?

...

{% endraw %}
