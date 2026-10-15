# Todo: Meta Value Model - Consider we need a Set composition meta-value (to be able to compose e.g., type classes)?

```#0cac16f1``` *As of 2017-06-16 12:47*

[mail plain/text](mail.txt)

{% raw %}
Reading about Haskell type classes and the ability to define constraints to any-type identifiers, it seems we can accomplish this in Meta Value Model aslo if we just add the Set composition of values?

1) Consider a Set is a composition of defined values (any meta level)?

==&gt; Thus, a Set is an unordered composition of defined identifiers?

Meh´.meta-1&gt; (identifier numbers (set int float)) // Would be meta-1 value ”numbers” with the meta-1 value members ”int” and ”float”?

Meh´.meta-0&gt; (identifier my_set (set count index age)) // would be meta-0 value ”my_set” with meta-0 value members ”count”, ”index” and ”age”?

==&gt; But, how can we define a Set of literals (e.g. 1,3,5)?

Meh´.meta-0&gt; (identifier my_set (set 1 3 5)) // ”1”, ”3” and ”5” are NOT identifiers?

==&gt; Can it be that any Set can only contain members defined by the same meta-value?

==&gt; Consider C++ std:.set definition (<http://www.cplusplus.com/reference/set/set/>)?

> ”*In a set, the value of an element also identifies it (the value is itself the key, of type T), and each value must be unique. The value of the elements in a set cannot be modified once in the container (the elements are always const), but they can be inserted or removed from the container.*"

==&gt; So, it seems a Set is a composition of defined identifiers but the identifier is the value itself?

==&gt; Thus, identifiers for members of a Set must be able to compare against name or value?

Meh´.meta-1&gt; (identifier numbers (set int float)) // Would be meta-1 value ”numbers” with the meta-1 value members ”int” and ”float”?

Meh´.meta-0&gt; (identifier my_set (set count index age)) // would be meta-0 value ”my_set” with meta-0 value members ”count”, ”index” and ”age”?

Meh´.meta-0&gt; (identifier my_set (set 1 3 5)) // Would be meta-0 value ”my_set” with meta-0 members ”1”, ”3” and ”5”?

==&gt; Consider we can now enable Set of any arbitrary complex value using hash value as identifier name?

==&gt; Consider Sets allow members declared of different meta-value (e.g. meta-0 Sets can contain members of different types)?

==&gt; Consider the only thing a Set cares about is that the members have different names (keys)?

Meh´.meta-0&gt; (identifier my_set_of_different_types (set ”Hello” ”World” 3)) // would be a set with two string-literal members and one number member?

==&gt; It seems we can implement this by designing a way to infer set member name (key) from the member value (**Set Key inference**)?

==&gt; An atomic meta-0 literal set member key is inferred to its readable representation (e.g. 3 is set key ”3”, true is set key ”true”)?

==&gt; A composite value set member key is its hash value text representation (e.g. meta-0 literal ”Hello” has set key hash(”Hello”))?

==&gt; An identifier value set member key is the name defined by the identifier (e.g. object ”my_number” has set key ”my_number”)?

==&gt; This should work as defined value names are required to be unique in its namespace?

==&gt; Consider allowing a Set to contain members of ”different types” does not comply with other languages (or the mathematical definition of Set)?

==&gt; Elm constrains Set to have members of same types only (e.g. (Set Int), (Set String))?

==&gt; C++ allows

==&gt; Consider we should provide Union of Set as the abstraction to compose Sets of values of different types?

Meh´.meta-0&gt; (identifier my_set_union (**union** (**set** 1 3) (**set** ”Hello” ”World”))

Meh´.meta-0&gt; (my_set_union.**has_member** 1)

(bool true)

Meh´.meta-0&gt; (my_set_union.**has_member** ”World”)

(bool true)

Meh´.meta-0&gt;

...

2) Consider the operations a Set&lt;n&gt; should expose?

==&gt; Consider Set&lt;n+2&gt; just define the Set {…any Set&lt;n+1&gt; value…} (i.e. it is the any-level Set type constructor)?

==&gt; Consider Set&lt;n+1&gt; provides ability to infer key name from meta-n value (i.e. it is able to construct meta-n set value that is a set of any meta-n value)?

Set&lt;n+1&gt;::as_key(meta-0 value) // infers the set member name (key) from provided meta-0 value

Set&lt;n+1&gt;::defacto(list of meta-0 values) // constructs meta-0 set value from constructor arguments (list meta-0 values)

==&gt; Consider Set&lt;0&gt; is then the defacto set value (in effect a set of any meta-n value)?

==&gt; Consider it must provide ”check for membership” predicate?

Meh´.meta-0&gt; (my_set.is_member 3) // applies my_set operation ”is_member”

3) Consider how Set types are defined in other languages?

==&gt; Elm Set types seem to define values of a fixed type (Set defined in terms of a meta-value just as arrays) (<http://package.elm-lang.org/packages/elm-lang/core/latest/Set>)?

> "type [Set](http://package.elm-lang.org/packages/elm-lang/core/latest/Set#Set) t

> Represents a set of unique values. So `(Set Int)` is a set of integers and `(Set String)` is a set of strings."

  
==&gt;

3) Consider how we can now use Set to implement Haskell type constraints?

==&gt; Consider Haskell operator &gt; type definition?

1. ghci&gt; :t (&gt;)
2. (&gt;) :: (Ord a) =&gt; a -&gt; a -&gt; Bool



==&gt; This would read: type of (:t) operator ’&gt;’.

==&gt; is of type (::) a -&gt; a -&gt; Bool (any type to same any-type to Bool)

==&gt; But, any-type ’a’ must be a member of Set Ord (a Set of all types whose values can be ordered)

==&gt; Now, how can we model this in our Meta Value Model?

TBD...

…

Consider to elaborate on possible ways to define modeling using Set composition?

...

{% endraw %}
