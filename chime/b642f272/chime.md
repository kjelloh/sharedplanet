# Todo: Tha - Consider possible ways to implement the Tha persistent data structure using existing C++ immutable data structures?

```#b642f272``` *As of 2017-06-27 12:32*

[mail plain/text](mail.txt)

{% raw %}
Consider ways we may implement the Tha persistent data structure in a stable, efficient and good-enough way for a proof-of-concept?

==&gt; Also see ”Todo: Tha - Consider the persistent data structure may be represented as a DAG with Deltas as edges and Tha instances as nodes?”

==&gt; Also see ”Todo: Darwinet - Consider to study "Confluently Persistent Tries for Efficient Version Control" as a base for design decisions for Darwinet File Systems?”

==&gt; Also see ”Todo: Darwinet - Consider to delve into available C++ information and solutions to implement the MIV as a Confluent Persistent (Immutable) Data Structure?"

==&gt; Also see ”Todo: Meta Value Model - Consider all values (and the whole mode) is immutable (all mutations create new instance)?"

==&gt; Also see ”Todo: Programming - Consider to check out the C++ Immutable Data Structures Library "Immer" and possibly if to use it with Darwinet implementation?”

==&gt; Also see ”Todo: Programming - Consider with Immutable Values are basically fine being anonymous (no name required for later reference)?”

==&gt; Also see ”Todo: Programming - Consider benefits of a Protocol Library based on immutable data and Functional Reactive Programming?”

==&gt; Alse see ”Todo: Darwinet - Consider to delve into available C++ information and solutions to implement the MIV as a Confluent Persistent (Immutable) Data Structure?”

==&gt; Also see ”Todo: C++ - Consider how move-semantics relates to immutable data structures (move means mutation)?”

==&gt; Also see ”Todo: Programming C++ - Consider to create a "React Like" C++ GUI framework that views and operates on an Immutable Persistent Data Structure?”

==&gt; Also see ”Todo: C++ - Consider to make an "Immutable C++" language that generates C++ code where everything is const (immutable) by default?”

==&gt; Also see ”Todo: Darwinet - Consider Javascript React with immutable.js or Mori actually kind-of already implemented Darwinet immutable MIV and delta history mechanisms?”

==&gt; Also see ”Todo: Darwinet - Consider what Deltas we may have to evolve Immutable MIVs (e.g. new I:s can only be done with value provided)”

==&gt; Also see ”Todo: Darwinet - Consider the MIV is actually immutable (each delta creates a new MIV) making Darwinet suitable for a function composition design?”

1) Consider to really understand the terms used to discuss and define persistent (immutable )data structures?

==&gt; Consider ”Persistent Data Structure” definition in wikipedia (<https://en.wikipedia.org/wiki/Persistent_data_structure>)?

> ”*A data structure is **partially persistent** if all versions can be accessed but only the newest ver*sion can be modified.”

> ”*The data structure is **fully persistent** if every version can be both accessed and modified.*”

> ”*If there is also a meld or merge operation that can create a new version from two previous versions, the data structure is called **confluently persistent**.*”

> ”*Structures that are not persistent are called **ephemeral**.*"

==&gt; Consider ”Confluent” means ”Convergence of shape...” (<https://en.wiktionary.org/wiki/confluent>)?

==&gt; Consider to compare with ”Confluence” as meaning ”point where two rivers meet”?

2) Consider we should implement a ”persistent value wrapper” to be able to adopt different actual persistent data structure implementations?

==&gt; Consider what API a Persistent Data Structure wrapper should have?

==&gt; Consider to start of with a Persistent List?

==&gt; Consider a List of S-expressions (<https://en.wikipedia.org/wiki/S-expression>)?

> an s-expression is classically defined[&#91;1&#93;](https://en.wikipedia.org/wiki/S-expression#cite_note-McCarthy1960-1) as
1. an atom, or
2. an expression of the form `(*x* . *y*)` where *x* and *y* are s-expressions.



> Most modern sexpr notations in addition use an abbreviated notation to represent [lists](https://en.wikipedia.org/wiki/Linked_list) in s-expressions, so that  
> `(*x* *y* *z*)`  
> stands for  
> `(*x* . (*y* . (*z* . NIL)))`

==&gt; Such a List should have only cons, head and tail services?

head: (sexpr . sexpr) -&gt; sexpr

tail: (sexpr . sexpr) -&gt; sexpr

cons: sexpr -&gt; sexpr -&gt; (sexpr . sexpr)

3) Consider open source projects implementing Presistent Data Structures?

==&gt; From ”Todo: Darwinet - Consider to delve into available C++ information and solutions to implement the MIV as a Confluent Persistent (Immutable) Data Structure?”

==&gt; Consider ”Immutable++” (<https://github.com/rsms/immutable-cpp>)?

==&gt; Consider ”Cat: C++14 functional library” (<https://github.com/awgn/cat>)?

==&gt; Consider ”Fit is a header-only C++11/C++14 library” (<https://github.com/pfultz2/Fit>)?

==&gt; Consider ”FTL - The Functional Template Library” (<https://github.com/beark/ftl>)

…

4) Consider the github project ”rsms/immutable-cpp” (<https://github.com/rsms/immutable-cpp>)?

==&gt; It seems good that it is only one translation unit (and two header files)?

==&gt; It seem to compile OK in Xcode?

==&gt; It seems to have a clear and easy-enough API?

> struct Array&lt;T&gt; {  
> static ref&lt;Array&gt; empty();  
> static ref&lt;Array&gt; create(std::initializer_list&lt;typename Y&gt;&&);  
> static ref&lt;Array&gt; create(typename Iterable&&);  
> static ref&lt;Array&gt; create(const typename Iterable&);  
> static ref&lt;Array&gt; create(Iterator&& begin, const Iterator& end);  
> static ref&lt;Array&gt; create(Iterator& begin, const Iterator& end);  
> static ref&lt;Array&gt; create(typename It& begin, const typename It& end);  
> static ref&lt;Array&gt; create(typename It&& begin, const typename It& end);

> uint32 size() const;

> ref&lt;Array&gt; push(Value&lt;T&gt;\*) const;  
> ref&lt;Array&gt; push(typename Any&&) const;  
> ref&lt;Array&gt; push(Iterator&& begin, const Iterator& end) const;  
> ref&lt;Array&gt; push(Iterator& begin, const Iterator& end) const;  
> ref&lt;Array&gt; push(typename It&& begin, const typename It& end) const;  
> ref&lt;Array&gt; push(typename It& begin, const typename It& end) const;

> ref&lt;Array&gt; set(uint32 i, typename Any&&) const;  
> ref&lt;Array&gt; set(uint32 i, Value&lt;T&gt;\*) const;  
> const T& get(uint32 i) const;  
> Iterator find(uint32 i) const;  
> const ref&lt;Value&lt;T&gt;&gt; findValue(uint32 i) const;  
> const ref&lt;Value&lt;T&gt;&gt; getValue(uint32 i) const;  
> const T& first() const;  
> const T& last() const;  
> const ref&lt;Value&lt;T&gt;&gt; firstValue() const;  
> const ref&lt;Value&lt;T&gt;&gt; lastValue() const;

> ref&lt;Array&gt; pop() const;  
> ref&lt;Array&gt; rest() const;  
> ref&lt;Array&gt; concat(ref&lt;Array&gt;) const;  
> ref&lt;Array&gt; slice(uint32 start, uint32 end=END) const;  
> ref&lt;Array&gt; splice(uint32 start, uint32 end, typename It&& it, const typename It& endit) const;  
> ref&lt;Array&gt; splice(uint32 start, uint32 end, Iterator&& it) const;  
> ref&lt;Array&gt; splice(uint32 start, uint32 end, Iterator& it) const;  
> ref&lt;Array&gt; splice(uint32 start, uint32 end, ref&lt;Array&gt;) const;  
> ref&lt;Array&gt; without(uint32 start, uint32 end=END) const;

> ref&lt;TransientArrayT&gt; asTransient() const;  
> ref&lt;Array&gt; modify(typename Func&& fn) const;

> int compare(const ref&lt;Array&gt;& other) const;

> Iterator begin(uint32 start=0, uint32 end=END) const;  
> const Iterator& end() const;  
> }

==&gt; Consider if we can settle with modeling the whole Tha only using a persistent Array?

==&gt; It seems we should be able to model any Tha member value using an Array based on the fact that Lisp models all data using a {head, tail} list?

==&gt; And, we should be able to use the persistent Array as a {head, tail} list?

> > auto a = immutable::Array&lt;int&gt;::empty();  
> > auto head = \*a-&gt;begin();  
> > auto tail = a-&gt;rest();

==&gt; Q: Does this work?

==&gt; Consider how we can compose Tha values using Persistent Array&lt;T&gt;?

==&gt; Consider how we implement the Tha Identifier (name, meta-value, value binding) value?

==&gt; Consider all Tha values are variants?

==&gt; Thus, Tha is **immutable::Array&lt;tha::Value&gt;**?

...

==&gt; Consider ways to generate Darwinet Deltas from comparing two generations (versions) of the Persistent Array?

==&gt; We should be able to walk the two Arrays and compare the nodes (unchanged nodes share the same node instance)?

==&gt; Consider ways to generate Darwinet Deltas from comparing a Transient Array with a Persistent Array?

...

3) Consider the C++ immutable library ”Immer" (<https://sinusoid.es/immer/>)?

==&gt; From ”Todo: Programming - Consider to check out the C++ Immutable Data Structures Library "Immer" and possibly if to use it with Darwinet implementation?”

==&gt; The immer project seems to live on Github here (<https://github.com/arximboldi/immer>)?

==&gt; Consider to use the C++ immer library although it requires GNU licensing (<https://sinusoid.es/immer/introduction.html#license>)?

> ”*This is a header-only library. As such, under the terms of the LGPLv3 license, you can use it to build any kind of software. However, if you distribute software containing a modified version of Immer, you need to make your version of Immer available to your u*sers under the LGPLv3 license."

==&gt; Q: So, if we do not modify Immer we can distribute the rest of Meh, Tha (Darwinet) using a more modrete license?

==&gt; Q: But then project will be dependent on Immer and manage synchronization with immer themselves (We cant distribute Immer in our own distribution)?

...

==&gt; Consider this Cpp Now 2017 talk (<https://www.youtube.com/watch?v=ZsryQp0UAC8>)?

==&gt; Consider this paper ”ersistence for the masses: RRB-Vectors in a systems language” implemented in the Immer library (<https://public.sinusoid.es/misc/immer/immer-icfp17-preprint-00.pdf>)?

> ”*Relaxed Radix Balanced Trees (RRB-Trees) is one of the latest members in a family of persistent tree based data-structures that combine wide branching factors with simple and relatively at structures.*”

> ”*In this work we propose… *  
> *(1) an Embedding RRB-Tree (ERRB-Tree) data structure that efficiently stores arbitrary unboxed types, *  
> *(2) a technique for implementing tree operations independent of optimizations for a more compact representation of the tree, *  
> *(3) a policy-based design to support multiple memory management and reclamation mechanisms (including automatic garbage collection and reference counting), *  
> *(4) a model of transience &#91;,&#93; based on move-semantics and reference counting, and *  
> *(5) a definition of transience for confluent meld operations. Combining these techniques a performance comparable to that of mutable arrays can be achieved in many situations, while u*sing the data structure in a functional way.”

![](<Radix Balanced Tree - Fig 1 Example .jpeg>)

==&gt; Also see "Todo: Darwinet - Consider to study "Confluently Persistent Tries for Efficient Version Control" as a base for design decisions for Darwinet File Systems?”

==&gt; It seems more focused on memory efficiency and larger palette of data structures?

> namespace immer {

> /\*!  
> \* Immutable sequential container supporting both random access and  
> \* structural sharing.  
> \*/  
> template &lt;typename T,  
> typename MemoryPolicy = default_memory_policy,  
> detail::rbts::bits_t B = default_bits,  
> detail::rbts::bits_t BL = detail::rbts::derive_bits_leaf&lt;T, MemoryPolicy, B&gt;&gt;  
> class vector { /\* ... \*/}

> /\*!  
> \* Immutable sequential container supporting both random access,  
> \* structural sharing and efficient concatenation and slicing.  
> \*/  
> template &lt;typename T,  
> typename MemoryPolicy = default_memory_policy,  
> detail::rbts::bits_t B = default_bits,  
> detail::rbts::bits_t BL = detail::rbts::derive_bits_leaf&lt;T, MemoryPolicy, B&gt;&gt;  
> class flex_vector { /\* ... \*/}

> /\*!  
> \* Immutable container that stores a sequence of elements in  
> \* contiguous memory.  
> \*/  
> template &lt;typename T, typename MemoryPolicy = default_memory_policy&gt;  
> class array { /\* ... \*/}

> /\*!  
> \* Immutable box for a single value of type \`T\`.  
> \*/  
> template &lt;typename T,  
> typename MemoryPolicy = default_memory_policy&gt;  
> class box { /\* ... \*/}  
> }

==&gt; It seems we would be tempted to implement the Tha as a flex_vector?

...

==&gt; Immer seems to provide a small set of algorithm helpers to apply operations on persistent data structures (<https://github.com/arximboldi/immer/blob/master/immer/algorithm.hpp>)?

…

==&gt; Consider ways to generate Darwinet Deltas from comparing two generations of immer persistent data structures?

...

==&gt; Consider ways to generate Darwinet Deltas from comparing immr Transient data structure with a persistent data structure?

…

…

Consider to elaborate and try out different C++ data structures to be used as the budiling blocks for persistent Tha values and structures?

...

{% endraw %}
