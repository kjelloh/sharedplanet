# Todo: Meta Value Model - Consider mechanisms to create and apply pattern matching using existing model meta-values and explicit UML-like model patterns?

```#a6a889cc``` *As of 2017-06-14 14:02*

[mail plain/text](mail.txt)

{% raw %}
It seems the value of pattern matching pops up both in value and type inference, but also in model compliance detection (e.g., as in Clojure.spec patterns) and text -&gt; value parsers and value - &gt; text compilers?

==&gt; Also see ”[Todo: Meta Value Model - Consider to implement a value-to-meta-value-contract matching ability as implemented by Clojure.spec?](../c40aa5b0/chime.md)”

1) Consider what pattern mechanisms we need for value inference?

==&gt; It seems bottom line is (See below)

**as_pattern(value) is a predicate p: source_value -&gt; inferred_value**

==&gt; Consider C++ 17 ”structured bindings” (<https://skebanga.github.io/structured-bindings/>)

auto &#91; var1, var2 &#93; = tuple;

==&gt; The value var1 is bound to tuple.get&lt;0&gt; and var2 is bound to tuple.get&lt;1&gt;?

==&gt; Thus the var1 and var2 values are inferred from the tuple value based on the left and right hand side value topology (data structure)?

==&gt; Consider we can view this as inferring composed values from meta-value declared members?

==&gt; The meta-value for tuple value is already defined.

meta tuple: array {type1, type2} // in this example a pair of types

==&gt; The meta-value of the left hand value must be inferred

meta &#91;var1, var2&#93;: struct {var1 typeA, var2 typeB} // types of var1 and var2 not yet declared (bound to type)!

==&gt; It seems we could use meta &#91;var1, var2&#93; as a ”pattern” (it has a structure and named members but members are not yet declared)?

==&gt; Consider matching meta-1: struct {var1 typeA, var2 typeB} to meta-1: array {type1, type2}?

==&gt; First the structure must match?

==&gt; The structure match if each type in left hand type can be bound to a type in right hand type (i.e. meta-1 member declaration structured binding)?

meta-1: define each nth&lt;struct {var1 typeA, var2 typeB}&gt;(n) = nth&lt;array {type1, type2}&gt;(n); n = 0,1?

0: typeA = type1

1: typeB = type2

==&gt; All meta-1 members in left hand side ”pattern” defined ok =&gt; pattern meta-1 structure match!

==&gt; NOTE: We are matching meta-1 inferred_identifier with meta-1 value!

==&gt; Requires undeclared inferred_identifier to match value by being defined to value (name and meta-value unknowns)?

==&gt; The use the inferred type to bind values?

==&gt; meta &#91;var1, var2&#93; is now inferred as struct {var1 type1, var2 type2}, what can we do with that?

==&gt; We can now use the meta-0 value as pattern to define the member values?

meta-0: define nth&lt;&#91;var1, var2&#93;:&gt;(n) = nth&lt;tuple&gt;(n); n=0,1

0: var1 = tuple.get&lt;0&gt;

1: var1 = tuple.get&lt;1&gt;

==&gt; All meta-0 members in left hand side ”pattern” defined ok =&gt; pattern meta-0 structure match!

==&gt; Q: It seems this will always be the case when the meta-1 structure match (same type-structure infers same value structure)?

…

2) Consider what mechanism we need for type inference?

==&gt; It seems type inference comes ”for free” with value inference (meta-0 matching is based on meta-1 matching)?

==&gt; Or, at least, type-inference is meta-1 matching in the same value as value-inference is meta-0 matching?

…

3) Consider defining a general meta-n matching would bring value inference and type inference as meta-0 and meta-1 value inference?

==&gt; Consider meta-n value inference to be defined as:

meta-1: define each nth&lt;inferred_value&gt;(n) = nth&lt;source_value&gt;(n); // Recursively through source_value structure?

==&gt; Each inferred_value member is defined to the same definition as the source_value member on the same ”location”?

==&gt; It seems we need to define ”same structure location” to allow matching different compositions with the ”same shape”?

==&gt; Thus, it seems we can implement this by having each value expose an as_pattern member function?

**as_pattern(value) is a predicate p: source_value -&gt; inferred_value**

NOTE: This rimes with the fact that values are immutable (we create an inferred value from a source value)?

==&gt; Thus, if inferring fails we get a NIL value back!?

==&gt; Consider to define ”same shape” of two value structures?

==&gt;  Consider the combinations match(identifier, identifier), match(identifier, value), match(value, identifier) or match(value,value)?

==&gt; match(identifier, identifier) enables inferring unordered sequences from another unordered one (name used as member key)?

==&gt; match(identifier, value) enables inferring an ordered named member sequence to an indexed ordered sequence (names disregarded)?

==&gt; match(value, identifier) enables inferring indexed member sequence from ordered named member sequence (names disregarded)?

==&gt; match (value, value) enables inferring value from value (recursing to member values of composite)?

==&gt; Consider Identifier (all members) can only be inferred from identifier (all members) or value (never meta-value as value and meta-value are indistinguishable as values)

==&gt; An inferred identifier matches a source Identifier if all bound members match AND all unbound members can be inferred from source?

==&gt; Thus, A declared identifier can be inferred from a defined identifier if meta-value and name match?

inferred_identifier {   source_identifier {

name name

meta-value &lt;- infer  meta-value

value value

} }

==&gt; nil inferred_identifier always match source identifier?

inferred_identifier {   source_identifier {

name=nil name=s

meta-value=nil &lt;- infer  meta-value=mv

value=nil value=v

} }

==&gt; inferred name=s, meta-value=mv, value=v

==&gt; named inferred_identifier match if same name as source_identifier?

==&gt; Declared inferred_identifier match if name & meta-value matches source (recurse to meta-value match)?

==&gt; defined inferred_identifier match if name, meta-value and value match (recurse on meta-value and value match)?

...

==&gt; And, An identifier can be inferred from a value (required to match named to indexed ordered sequences)?

==&gt; An identifier can be inferred from a value?

inferred_identifier {

name=s

meta-value=nil &lt;- infer

value=v1  value:v2

}

==&gt; Undefined identifiers is deferred from value by defining it to source value (name not involved)

==&gt; Defined identifier match if v1 == v2.

==&gt; Consider the C++ 17 structured binding requires identifier definition to be inferred from value?

meta-1: define each nth&lt;struct {var1 typeA, var2 typeB}&gt;(n) = nth&lt;array {type1, type2}&gt;(n); n = 0,1?

0: typeA = type1

1: typeB = type2

==&gt; All meta-1 members in left hand side ”pattern” defined ok =&gt; pattern meta-1 structure match!

==&gt; Identifier to meta-value impossible (we don’t know if value is to be considered a value or a meta-value for the identifier)?

==&gt; An atomic value matches an atomic value?

==&gt; An ordered sequence of values matches an ordered sequence of values if member count matches and each same index member matches (recursive match)

==&gt; Results in match(identifier, identifier), match(identifier, value), (value, identifier) or match(value,value)?

…

4) Consider a mechanism to define patterns that match on defined cardinality (UML model style)?

==&gt; Consider a pattern with members that implements cardinality-check (e.g., compare Clojure.spec patterns)?

==&gt; A cardinality_pattern is a predicate p: count -&gt; (value -&gt; bool) -&gt; &#91;value&#93; -&gt; {bool, tail_value}

==&gt; It takes a predicate: value -&gt; bool and aplies it count-times to ordered sequence of indexed members and returns a pair of bool and tail_value (the unconsumed part of &#91;value&#93;?

==&gt; It returns true of it was able to successfully apply the predicate the defined number of times.

…

==&gt; Consider this cardinal predicate replaces ALL Clojure.spec patterns?

**==&gt; Consider to confirm this with the Clojure.spec documentation?**

==&gt; Also see ”[Todo: Meta Value Model - Consider to implement a value-to-meta-value-contract matching ability as implemented by Clojure.spec?](../c40aa5b0/chime.md)”

5) Consider patterns that defined patterns that define conditional match (predicates)?

==&gt; Consider such members are simply a predicate function p: value -&gt; boolean?

==&gt; Thus we can declare and define such predicates with code in Meta Lisp language?

==&gt; Consider this would enable patterns that specify ISO 8583 members from decoded bitfield?

==&gt; And we can enable patterns that define ipos message members based on model constants defining ipos-T or SACI message generation?

…

6) Consider we need the pattern to be able to be used for storting the matched values?

==&gt; This would mean the pattern would provide a less_than operator that compares two matched values?

...

7) Consider we want to use the pattern matching (value inferring) mechanism to implement function dispatching?

==&gt; Consider function dispatching is in fact matchin the call signature with the candidate functions to dispatch to?

==&gt; Consider the candidate functions are those with the same name (declared called identifier matched declared function name)?

==&gt; Consider this can be implemented as a as_pattern(defined function call)?

==&gt; A Function&lt;0&gt;::as_pattern will return a pattern to create a list of matching candidates?

==&gt; Consider we need the pattern to be able to sort the list of matched candidate Function&lt;0&gt; values so we can dispatch to the best-pick?

==&gt; We may now bind the function call to the best-pick of the matched Function&lt;0&gt; candidates?

...

…

Consider to elaborate on the pattern matching mechanism we would like to have in the Meta Value Model?

...

{% endraw %}
