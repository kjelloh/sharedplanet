# Todo: Tha - Consider the persistent data structure may be represented as a DAG with Deltas as edges and Tha instances as nodes?

```#925b6bde``` *As of 2017-06-20 12:17*

[mail plain/text](mail.txt)

{% raw %}
Consider if we can gain any benefits from noting that Tha states as persistent data structure instances and Deltas as mutations creation state changes may be modeled as a DAG with Deltas as edges and Tha instances as Nodes?

1) Consider the benefits of a Darwinet run-time storing Deltas and Tha states in a DAG data structure?

==&gt; Consider to use sha-values as Tha state a,d Delta identifiers enables us to find Tha states and also inspect Tha state relations?

Δ Δ Δ Δ

ث &lt;-- ث &lt;-- ث &lt;-- ث &lt;-- ث

|

----&gt; ث

Δ

==&gt; The DAG could serve as a data structure to handle branching in case of conflicting Deltas?

==&gt; If we find the Tha in the DAG we are able to detect if it is an end-node or an intermediate node?

==&gt; An end node is a ”head” and is OK to mutate (extend the path)

==&gt; An intermediate node menas we branch (two or more Deltas applies to this Tha)

2) Consider how a DAG allows us to handle both branch and merge of branches?

Δ Δ Δ Δ

ث &lt;-- ث &lt;-- ث &lt;-- ث &lt;-- ث

| ^

----&gt; ث ----|

Δ Δ

==&gt; A tha with only one incoming and one outgoing edge models a progress (the delta identifies the progress)?

==&gt; A tha with two or more outgoing edges models branching (each outgoing delta identifies a branch)?

==&gt; A tha with two or more incoming edges models a merge (each incoming delta identifies a merge)?

3) Consider any advantages of modeling DAGs of Deltas and Tha instances using Boost grapgh library (<http://www.boost.org/doc/libs/1_63_0/libs/graph/doc/quick_tour.html>)?

==&gt; It would seem we can operate on DAGs using well known graph algoritms (e.g. find node or edge)?

![](<Graph algoritms operates on Graph data structures.tiff>)

==&gt; It seems we must create bi-directional graphs to be able to detect in-edges to nodes?

> ”*The in_edges() function of the BidirectionalGraph interface provides access to all the in-edges of a vertex through in-edge iterators. The in_edges() function is only available for the adjacency_list if bidirectionalS is supplied for the Directed template parameter. There is an extra cost in space when bidirectionalS is specified instead of directedS.*"

==&gt; The C++ code seems quite straight forward to get hold of all in-edges to a node?

> template &lt;class Graph&gt; struct exercise_vertex {  
> //...  
> void operator()(const Vertex& v) const  
> {  
> //...  
> std::cout &lt;&lt; "in-edges: ";  
> typedef typename graph_traits&lt;Graph&gt; GraphTraits;  
> typename GraphTraits::in_edge_iterator in_i, in_end;  
> for (boost::tie(in_i, in_end) = in_edges(v,g);  
> in_i != in_end; ++in_i) {  
> e = \*in_i;  
> Vertex src = source(e, g), targ = target(e, g);  
> std::cout &lt;&lt; "(" &lt;&lt; index&#91;src&#93; &lt;&lt; "," &lt;&lt; index&#91;targ&#93; &lt;&lt; ") ";  
> }  
> std::cout &lt;&lt; std::endl;  
> //...  
> }  
> //...  
> };

==&gt; For vertex 0 the output is: in-edges: (2,0) (3,0) (4,0)

==&gt; Consider for the Delta and Tha DAG the in-edges are merging deltas?

4) Consider using C++ Boost DAG representation of Deltas + Tha states enables us to print current Persistent data structure using boost algorithms?

…

…

Consider to delve into this idea to model Darwinet Tha and Deltas as a DAG?

...

{% endraw %}
