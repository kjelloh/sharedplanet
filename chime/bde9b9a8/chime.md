# Todo: Tha - Consider to define mtea-2 value "inferred" that constructs generic meta-1 value (they apply pattern matching to define meta-0 values)?

```#bde9b9a8``` *As of 2017-06-21 11:35*

[mail plain/text](mail.txt)

{% raw %}
It seems it could be possible to provide inference through a meta-2 value we name ”inferred” that instantiate meta-1 generic value that from provided meta-0 value infers its own value?

==&gt; Also see ”[Todo: Meta Value Model - Consider in Meh we define meta-1 name "a" as a generic (any) type to be inferred from (Haskel and Elm style)?](../9e687519/chime.md)”

==&gt; Also see ”[Todo: Meta Value Model - Consider mechanisms to create and apply pattern matching using existing model meta-values and explicit UML-like model patterns?](../a6a889cc/chime.md)”

==&gt; Also see ”[Todo: Meta Value Model - Consider to implement a value-to-meta-value-contract matching ability as implemented by Clojure.spec?](../c40aa5b0/chime.md)”

1) Consider to elaborate on the nature of this meta-2 value to make this work?

==&gt; Consider it consists of a constructor that accepts meta-1 identifiers that are only partly bound (may be without name, meta-value and/or value)?

==&gt; Consider the constructor accepts meta-1 value compositions (declared meta-2 composition values, e.g., record, array…)

==&gt; Consider the pattern matching algorithm of the meta-1 value visits the provided meta-0 value/identifier in the same sequence and structure as ”itself” to try and copy the missing bindings it has (using structure and existing bindings as keys)?

==&gt; Consider to follow on thoughts in ”Todo: Meta Value Model - Consider mechanisms to create and apply pattern matching using existing model meta-values and explicit UML-like model patterns?"

2) Consider some thought experiments to try out some pattern matching we know of in other languages (or that we imagine could be cool to have)?

==&gt; Consider matching a record with unnamed members with another record?

3) Consider function dispatching, generic functions and values and value and type inference all share a core algorithm?

==&gt; They are all based on matching an ordered structure of identifiers to a value (using existing structure and values as keys to copy in the missing bindings from the source)?

==&gt; Consider if a full match is mandatory or if we should allow matching against a series of sources to ”fill in the blanks”?

...

4) Consider what querying we would like to be able to do on a Inferred&lt;2,1,0&gt; value?

==&gt; Consider we need to be able to detect if the Inferred&lt;0&gt; is fully defined (meta-0 value inference)?

==&gt; Consider we would like to be able to infer also meta-1 values (or even meta-2 values)?

==&gt; Consider what arguments the Inferred&lt;2&gt; value takes to instantiate an Inferred&lt;1&gt;?

==&gt; That is, how do we define what ”gaps” the generic Inferred&lt;1&gt; may have (infer names, values, meta-values)?

…

…

Consider to elaborate on this idea to define a Inferred&lt;2,1,0&gt; layered value that can provide all the required inference service we would like to have for generic types, generic functions and function dispatching?

...

{% endraw %}
