# Todo: Tha model - Consider that we can NOT use "Sorts" as the "Sort-of-kinds" as the term "Sort" is already used in type theory to categorise many things (sort-of-types, sort-of-kinds...)

```#f3d2a551``` *As of 2019-01-31 14:51*

[mail plain/text](mail.txt)

{% raw %}
It seems we can NOT use “Sorts” as the Tha-object names “Sort-of-kinds” (So what name can we use instead)?

==&gt; Also see “[Todo: Consider in programming that a "Dispatch" may be modeled as an "Indexing by pattern" (in addition to known indexing by term or type)?](../9c922c70/chime.md)"

==&gt; Also see “[Todo: Meh and Tha and Type Theory and Systems - Consider to delve deeper into Type Theory and the Lambda Cube to understand how we may think about Meh and Tha?](../77f52160/chime.md)"

==&gt; Also see “[Todo: Type Systems - Consider Strange Loop talk "Type Systems - The Good, Bad and Ugly" by Paul Snively and Amanda Laucher as having good leads into good and bad type systems and the need for a better programming language?](../9b0ab729/chime.md)”

==&gt; Also see “[Todo: Cratchit Book Keeping - Consider to implement a C++ book keeping application using Tha modelling, Elm Idion and Immer Immutable data Struictures asynchronously synchronising with REST Web service (FortKnox) and IPFS file system?](../7c6907a4/chime.md)"

==&gt; Also see “[Todo: Tha - Consider to name the "Meta stack model" the Tha model and define what this model implies and used?](../2927db2a/chime.md)”

==&gt; Also see “[Todo: Tha C++ - Consider to discover the C++ meta-layer objects by viewing C++ code as meta-layer expressions expressed in Haskel syntax?](../f03f3b43/chime.md)”

==&gt; Also see “[Todo: Tha - Consider Haskel "kind values" are in fact Tha meta-2 values?](../bba1c0c9/chime.md)”

1) Consider this paper “Proofs for free, Parametricity for dependent types” where they seem to define “Sort Hierarchies” as sort of types, sort of kinds etc. (<http://publications.lib.chalmers.se/records/fulltext/local_135303.pdf>)?

![](<Screenshot 2019-01-31 at 14.16.15.png>)

![](<Screenshot 2019-01-31 at 14.16.36.png>)

*Sort Hierachies defines sort-of-types, sort-of-kinds etc.*

1.

>   "Sort hierarchies Difficulties with impredicativity1 have led to the development of type systems with an infinite hierarchy of sorts. The “pure” part of such a system can be captured in the following PTS, which we name Iω.

>   Definition 2.2 (Iω)  
>   Iω is a PTS with this specification:

>   • S = {⋆i | i ∈ N}

>   • A={⋆i :⋆i+1 |i∈N}

>   • R = {(⋆i,⋆j,⋆max(i,j)) | i,j ∈ N}

>   Compared to the monomorphic λ-calculus, ⋆ has been expanded into the infinite hierarchy ⋆0,⋆1,... In Iω, the sort ⋆0 (abbreviated ⋆) is called the sort of types. Type constructors, or type-level functions have type ⋆ → ⋆. Terms like ⋆ (representing the set of types) and ⋆ → ⋆ (representing the set of type constructors) have type ⋆1 (the sort of kinds). Terms like ⋆1 and ⋆ → ⋆1 have type ⋆2, and so on."



==&gt; It seems “⋆0” or just “⋆" denotes “sort of types” (index 0) and “⋆1” denotes “sort of kinds” (index 1)

==&gt; It seems they are a bit sloppy with the terminology (“ \* has been expanded to the hierarchy ⋆0,⋆1,... In Iω” but then also “ the sort ⋆0 (abbreviated ⋆)”) - so ‘\*’ is both the hierarchy and the first tier of the hierarchy (confusing)?

==&gt; It seems clear though that they use “sort” to group anything into hierarchies (sort-of-types and sort-of-kinds etc.)?

==&gt; It seems the “sort of …” is used to categorise types, kinds, propositions and more?

> “...sort of types.”  
> “...sort of kinds…"  
> “…sort of propositions…"  
> “...sort of relational propositions about terms of sort s.”  
> “...sort of propositions corresponding to types of sort s…"  
> ![](<Screenshot 2019-01-31 at 14.41.19.png>)  
> ...

==&gt; So, in this paper we get **no name** on the sort-of-kinds?

...

2) Consider this paper for the Haskell language that also seems to talk about there being only one “sort of kinds” (<http://gallium.inria.fr/~jcretin/papers/fc-kind-poly.pdf> )?

![](<Screenshot 2019-01-31 at 14.44.54.png>)

3) Consider this paper for the Haskell language where again the square-symbol is used as the “Sort of kind” (<https://cs.brynmawr.edu/~rae/papers/2012/singletons/paper.pdf> )?

![](<Screenshot 2019-01-31 at 14.48.02.png>)

…

Consider to continue to search for a name of the Tha-objects “sort-of-kinds”. i.e., the Meta-4 level objects?

{% endraw %}
