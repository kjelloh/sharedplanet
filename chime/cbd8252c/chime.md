# Todo: C++ Meh and Tha - Consider to understand C++ types as Product, Sum and Exponential types with names or indexed members?

```#cbd8252c``` *As of 2019-02-02 21:49*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to understand C++ types (any language types) in terms of Product, Sum and Exponential types with named or indexed members?

==&gt; Also see “Todo: Darwinet Meh - Consider to study the Julia lisp-based language as inspiration and incorporation when designing the Meh language for the Darwinet Tha model?"

1) Consider C++ Product Types?

![](<Screen Shot 2018-04-24 at 10.17.37.png>)

==&gt; Consider a Product-type is a Set of types that carries all instance of each multiplied type?

==&gt; Consider struct, class, namespace are C++ product types with member accessed by name?

==&gt; Consider C-array, tuple are C++ product types with members accessed by index?

...

2) Consider C++ SUM Types?

![](<Screen Shot 2018-04-24 at 10.17.50.png>)

==&gt; Consider a Sum-type is a Set of types that carries any instance of each summed type?

==&gt; Consider union, enum are C++ sum types with members accessed by name?

==&gt; Consider enum as a Sum-type where all members are of the same type (e.g., int)?

==&gt; Consider enum as a Sum-type of Unit-types of a single C++ type (e.g., int)

==&gt; Consider Unit-type is in fact a 0-tuple, i.e., a product of zero types (<https://en.wikipedia.org/wiki/Unit_type>)?

> > “ *a unit type is a type that allows only **one value** (and thus can hold no information). The carrier (underlying set) associated with a unit type can be any singleton set. There is an isomorphism between any two such sets, so it is customary to talk about the unit type and **ignore the details of its value**. One may also regard the unit type as the type of 0-tuples, i.e. the product of no types.*"

==&gt; Consider for a Unit-type the type itself identifies the value it may have (and thus the type name and the value are interchangeable)

==&gt; Thus, the C++ enum is in fact a Sum-type of named unit-types (all unit-types are singletons of one same C++ integral type, e.g., int)?

==&gt; Consider for a C++ union only the compiler “knows” the type of the currently instantiated value of a enum type instance?

==&gt; Thus, the run-time code does not contain any information from the type abstraction (C++ zero overhead abstraction)?

...

3) Consider C++ function types?

![](<Screen Shot 2018-04-24 at 10.18.03.png>)

==&gt; Consider C++ function types a curryed exponential types “result type to the power of argument type” (i.e., for each combination of result type value set and argument value set there is a function in the function set that does that mapping)?

==&gt; Consider named C++ function type syntax “B F(A a) {…body environment ...}”?

==&gt; Consider anonymous C++ function type lambda "&#91;captured environment&#93;(A a) {…body environment}”?

==&gt; NOTE: We can declare named function types (because they have a name)

==&gt; NOTE: We can NOT declare an anonymous function type (because it has no name so there is nothing to bind the type to)

...

4) Consider to extend C++ type system to incorporate any missing exotic combination of Sum, Product, Exponential types with named or indexed member reference abilities?

==&gt; Consider we can expand enum to allow unit types of any C++ type?

==&gt; Consider an enum of same struct singletons?

==&gt; Consider the enumerated singletons must then be constructible from compiler generated index?

==&gt; See “/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyTestAnything/MyTestAnything"

![](<Screen Shot 2018-04-24 at 11.13.15.png>)

…

…

Consider to continue to elaborate on this view of C++ types as Product, Sum and Exponential types with named or indexed members?

...

{% endraw %}
