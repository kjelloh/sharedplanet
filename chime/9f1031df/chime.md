# Todo: Tha - Consider the Tha meta-value model is in fact a Set category in that each meta-value (Object) is a Set and constructors are morphisms between sets?

```#9f1031df``` *As of 2017-08-11 14:05*

[mail plain/text](mail.txt)

{% raw %}
Could it be valuable, and true, to model the Tha meta-value stack as a Set category in that all members of Tha are Sets?

-1) Consider the bottom line of this proposal?

==&gt; It seems meta-value to value morphisms maps a Set to a Singleton (e.g., a set of int values -&gt; int value)?

==&gt; In Tha it seems we want the meta-value to be the morphism to a vale?

int: Int -&gt; Int // The first is the selector and the result is the value instance?

...

1) Consider wikipedia definition of the Set category (<https://en.wikipedia.org/wiki/Category_of_sets>)?

…

2) Consider that all values in Tha are in fact Sets and thus Tha forms a Set category?

==&gt; Consider each meta-value is a Set of values (on the layer below)?

==&gt; Thus each kind defines a set of types (types of that kind)?

==&gt; Each types is a set of values (values of that type)

==&gt; And each value is a set of value representations (possible representations of that value)?

==&gt; Thus values of each level is a Set and Tha forms a Set Category with these sets as objects?

Tha is a Category with member objects Meta Kinds, Kinds, Types, Values, Defacto Values

==&gt; Consider we still has no good name for the Meta value that defines sets of Kinds?

3) Consider that in fact Tha is a Set of Sets (Kind, Type and Value are themselves Sets)?

==&gt; It seems each meta-level is itself a Set of its member values?

==&gt; Consider C++ Types is the Set {int, char, user types…}?

==&gt; And C++ kKinds is the Set {struct, class, union, enum,namespace, user kinds…}?

…

==&gt; Thus Tha is a category with morphisms between objects that reflects the meta-value &lt;—&gt; value relations?

Kinds: Set of {K1, K2, K3…}

Types: Set of {T1, T2, T3,…}

Values: Set of {V1, V2, V3}

==&gt; And the Tha meta-value &lt;—&gt; value relations are morphisms we can call meta and defacto?

meta: Value -&gt; Meta-Value

defacto: Meta-Value -&gt; Value

==&gt; This would seem to mean that meta and defacto are Functors that preserves the Algebra between a Value and a Meta-Value Category?

==&gt; Thus each Value on each Meta-level forms a Category and functors “meta” and “defacto” maps between Category Pairs {Value, Meta-Value}?

==&gt; Lets try it!

==&gt; Consider the Functor definition (<https://en.wikipedia.org/wiki/Functor>)?

> > Let *C* and *D* be [categories](<https://en.wikipedia.org/wiki/Category_(mathematics)>). A **functor** *F* from *C* to *D* is a mapping that[&#91;3&#93;](https://en.wikipedia.org/wiki/Functor#cite_note-3)

  - associates to each object X in *C* an object F(X) in *D*,
  - associates to each morphism f: X -&gt; Y in *C* a morphism F(X): F(f): F(X) -&gt; F(Y) in *D* such that the following two conditions hold:
    - F(Id&lt;X&gt;) = Id&lt;F(X)&gt; for every object X in *C*,
    - F(g . f) = F(g) . F(f) for all morphisms  and f: X -&gt; Y, g: Y -&gt; Z in *C*.

  
> > That is, functors must preserve [**identity morphisms**](https://en.wikipedia.org/wiki/Morphism#Definition) and [**composition**](https://en.wikipedia.org/wiki/Function_composition) of morphisms.

==&gt; Try this on meta and defacto as functor between the int type and int values?

> > Let IntValue and IntType be categories. A functor meta from IntValue to IntType is a mapping that
- associates to each value v in IntValue, a meta-value meta(v) in IntType,

  
> > … **NO, this does not work** (meta is not a mapping between each int value to an int-type)!

==&gt; Instead, try this on meta and defector as functor between Values and Types?

> > Let Values and Types be categories. A functor meta from Values to Types is a mapping that:
- associates to each Set of values V in Values, a Set of types meta( V) in Types

  
> > …**No, this does not work** either (The morphism Values -&gt; Types does NOT preserve the structure, it maps a Set, say set of int values, to a Singleton, say the int type)?

==&gt; Hm… It seems we need to understand the rations between Tha meta-levels better?

4) Consider to try and understand the relations between Tha meta-levels using C++ type system expressed in Tha?

==&gt; Consider this is the C++ type system expressed in Tha?

> meta-kinds: &lt;C++ built in meta-kinds&gt;

> template = Set {class-template-kinds, function-template-kinds, template-alias-kinds...}

> kinds:  &lt;C++ built in kinds&gt;

> struct = Set {struct-types...}

> class = Set {class-types...}

> union = Set {union-types...}

> enum = Set {enum types...}

> function-kind = Set {function-types...}

> ...

> &lt;user kinds k = 1...K&gt;

> class-template-kind-k = Set {class-types...}

> function-template-kind-k = Set {function-types...}

> template-alias-kind-k = Set {actual-template-closures…} // closure may turn a template-kind, a type or a literal value

> ...

> types: &lt;C++ built in types&gt;

> int = Set {...,-2, -1, 0 , 1 …}

> char = Set {‘\\0’, ...,’ ‘, ‘1’, …} // Code Points of source file character set that fits in char&lt;Code Unit&gt;

> ...

> &lt;user types t = 1...L&gt;

> struct-type-t = Set {struct-type-t-values...}

> class-type-t = Set {class-type-t-values…}

> function-type-t = Set {function-type-m-values}

> ...

> values: &lt;C++ built in literal values&gt;

> null, true, false,…

> &lt;user values v = 1...M&gt;

> struct-value-v

> class-value-v

> function-value-v

> ...

==&gt; Now, we have actually proposed that in Tha each meta-value is a function that maps a Set of values to a single value on the layer below?

int: int -&gt; int // **Does not work!** int can’t be both a function and a type!

==&gt; It seems we need a way to separate the constructor from the type it instantiates?

…

5) Consider to identify the objects of Tha for C++ (to try and identify categories and morphisms)?

==&gt; It seems Tha is composed of meta-layer objects?

Kind = {union, struct, class, enum, function, namespace,…}

Type = {bool, char, int, float, kind constructed types…}

Value = {true, false, null, C++ literals..., type constructed values…}

==&gt; Thus, Tha Is a Set category (with the Sets Kind, Type and Value)?

==&gt; But what are the members of these sets?

==&gt; Could it be that the Kind set contains composition of members of Type?

union: Type -&gt; Type -&gt; ...

union t1 t2 t3 … = t1 + t2 + t3… // + for types means OR-type

struct: (Name,Type) -&gt; (Name, Type) -&gt; ...

struct (name1, t1) (name2, t2) … = (name1, t1) \* (name2, t2) \* // \* for types mean AND-types

==&gt; But, for Tha we would like to separate bindings (named or unnamed meta-value to value binding) from values?

==&gt; So, where does binding and Set of bindings fit in into the mathematical picture for Tha?

==&gt; Consider a binding is the triplet (optional value-name, optional meta-value-name, optional value)?

==&gt; A declaration and a definition are the obvious name bindings?

(name, meta-value-name, null) is a declaration binding (value meta-value binding)?

(name, meta-value-name, value) is a definition binding (named value)?

==&gt; But we can have more esoteric bindings?

> > name meta-name value  
> > 0 0 0 // null (z)?  
> > 0 0 1 // unnamed, untyped value  
> > 0 1 0 // unnamed typed null  
> > 0 1 1 // unnamed typed value (e.g., temporary)

> > 1 0 0 // named untyped null  
> > 1 0 1 // named untyped value  
> > 1 1 0 // named typed null (declared name)  
> > 1 1 1 // named typed value (defined name)

==&gt; Could it be that the Set of bindings is an object in Tha of its own?

Tha is the Set of {**Kind**, **Type**, **Value**, **Binding**}?

…

==&gt; We can now play with the idea that meta and defacto are morphisms that maps Binding to itself?

> > ------------  
> > | |  
> > v | meta  
> > Binding | defacto  
> > | |  
> > ------------

==&gt; Now, this means meta will return a single binding (the one with meta-name we search for)

**meta**: Binding -&gt; Binding

meta b = The binding with binding.meta-name = b.name

==&gt; And defacto will return a list of bindings (all that are meta-bound to the same name)?

defacto: Binding -&gt; &#91;Binding&#93; // Binding value to list of Binding values

defacto b = all bindings with bining.name = b.meta-name

==&gt; BUT - this clashes with the Tha proposal that meta should lift syntax-evaluation (parse and evaluate an AST on a higher meta-value level)?

==&gt; How can we even express “evaluation-lifting” using mathematics (computer science)?

…

6) Consider “AST evaluation lifting” can be defined as a functor that lifts values and functions of a language to a meta-level?

**==&gt; Bottom line - No. That definition does not work (See below)**

==&gt; Consider we need to express the semantics of the language as Object Morphism of the Type System?

int a = 4; // int is a function that binds the name “a” to the member 4 in the Set Int = {…,-2,-1,0,1,2,3,**4**,5…}?

Lifting this to a meta-level should mean that “int” becomes a “value” (but the construct semantics remains the same)?

meta {

// the value “a” is below us (semantically out of reach as we have no semantics to operate on value instances)

auto a = int; // Copy construct the int value (a will be an int alias)

// Equivalent to using a = int; or typedef int a;

}

==&gt; It seems we would like meta { program } to mean “execute program in a type system lowered so that types -&gt; values, kinds -&gt; types”?

==&gt; And this is NOT category lifting at all?

7) Consider “evaluation lifting” can be defined as shifting how the language syntax is bound to the type system?

==&gt; Consider when we build the AST we actually applies rules on how the grammar is bound to the type system of the language?

==&gt; Consider the grammar defines what values, types and linds are expressed and how the parser should interpret them in the type system?

==&gt; Consider for C++ {int a = 4} is pre-defined to mean “bind name “a” to the type “int” and define it to have literal 4”?

==&gt; Now, we can play with the idea that we can shift the interpretation of value, type and kind bindings so that values binds to types and types to kinds?

==&gt; Consider for C++ meta {auto a = int} would now be interpreted as “bind a name “a” to the value of name “int” and infer its type”?

==&gt; In practice this should work as long as the interpreter has rules to treat types as values and kinds as types?

==&gt; It must lift the value semantics to be executable on types and kinds?

...

...

…

Consider to delve deeper into this idea that Tha as a Set of meta-values, each defining a Set of values on the layer below, is somehow related to a Set Category (or a Set of Categories)?

...

{% endraw %}
