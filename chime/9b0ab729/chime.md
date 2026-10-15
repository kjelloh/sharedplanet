# Todo: Type Systems - Consider Strange Loop talk "Type Systems - The Good, Bad and Ugly" by Paul Snively and Amanda Laucher as having good leads into good and bad type systems and the need for a better programming language?

```#9b0ab729``` *As of 2017-10-11 15:52*

[mail plain/text](mail.txt)

{% raw %}
I found a "Type Systems - The Good, Bad and Ugly" by Paul Snively and Amanda Laucher and it seems like a good idea to use it as leads into understanding what a type system is and what a good, bad and ugly type system is?

==&gt; Also see ”[Todo: Meh and Tha and Type Theory and Systems - Consider to delve deeper into Type Theory and the Lambda Cube to understand how we may think about Meh and Tha?](../77f52160/chime.md)"

1) The talk ”Type Systems - The Good, Bad and Ugly" by Paul Snively and Amanda Laucher” seems to live here (<https://www.youtube.com/watch?v=SWTWkYbcWU0>)?

==&gt; Consider the take aways from this talk?

==&gt; At 1:55 they seem to stress the importance to ”Make illegal state unrepresentable” (<https://youtu.be/SWTWkYbcWU0?t=115>)?

==&gt; They seem to refer this quote to Yaron Minsky (See below)?

==&gt; They seem to stress the importance of the ”Lambda Cube” at least twice?

==&gt; They refer to the Lambda Cube at 2:22 (<https://youtu.be/SWTWkYbcWU0?t=142>)?

==&gt; They do it again at 35:06 (<https://youtu.be/SWTWkYbcWU0?t=2106>)

![](<Lambda Cube overview by Paul Snively and Amanda Lauche.tiff>)

==&gt; They also seem represent this as a cross indexing of type and term (at 21:07 <https://youtu.be/SWTWkYbcWU0?t=1267>)?

![](<The Lambda Cube expressed using Cross Indexing of Type and Term.tiff>)

==&gt; It seems in type theory ”terms” are the things expressed in the syntax that has a ”type” (<https://en.wikipedia.org/wiki/Type_theory>)

> > ”*In type theory, every "**term**" has a "type" and operations are restricted to terms of a certain **type***"

==&gt; In type theory it seems ”terms” are mathematical objects (<https://en.wikipedia.org/wiki/Term_(logic))?>

> > ”In analogy to natural language, where a noun phrase refers to an object and a whole sentence refers to a fact, in mathematical logic, a term denotes a mathematical object and a formula denotes a mathematical fact."

==&gt; It seems ”Terms” are what Terminology is about (<https://en.wikipedia.org/wiki/Terminology>)?

> > ”***Terms** are **words** and compound words or multi-word **expressions** that in specific **contexts** are given specific **meanings***"

==&gt; At 06:00 they list most common languages as having flawed type systems (<https://youtu.be/SWTWkYbcWU0?t=362>)?

![](<Programming Languages with flawed type systems.tiff>)

==&gt; At around 07:00 they seem to state that they ”shoot for the **curry-howard isomorphism**” (<https://youtu.be/SWTWkYbcWU0?t=410>)?

> *A type is a theorem. And a function of that type is a proof of that theorem.*

![](<The Curry–Howard correspondence.tiff>)

==&gt; Ego: It seems they say that the function arrow —&gt; between types is isomorphic to the ”implies or it-follows-that” arrow ==&gt; (?!)

**==&gt; It seems, a function is a way to state that something is true for all values of a type (it is true that all values of the argument type maps to a value of the return type)**

==&gt; In the talk they seem to list a small set of type system properties a good type system must have?

==&gt; **It must have SUM-types** (at 8:55 <https://youtu.be/SWTWkYbcWU0?t=539>)?

==&gt; SUM types enables code to express failure and success cases (and ensure all cases are covered)

==&gt; It must support **pattern matching** (at 10:13 <https://youtu.be/SWTWkYbcWU0?t=613>)?

==&gt; They state - A type system without pattern matching is in effect useless?!

==&gt; EGO: It seems pattern matching is in effect ”type dispatching” (express how to process different SUM types)?

==&gt; AHA - Pattern Matching is needed to write code for SUM types!

==&gt; It must have **Product Types** (At 10:55 <https://youtu.be/SWTWkYbcWU0?t=655>)?

==&gt; Hm… They seem to use the term ”objects” as referring to something of a product type?

==&gt; They seem to relate Currying to Product Types by defining Currying as the way to decompose processing of the composition using defined ”views”?

==&gt; It must have **Dependent Types** (At 11::55 <https://youtu.be/SWTWkYbcWU0?t=717>)?

==&gt; According to wikipedia a Dependent Type is one that is constructed from values (<https://en.wikipedia.org/wiki/Dependent_type>)?

> > ”*a dependent type is a type whose definition depends on a value.*"

==&gt; The example in the talk is a vector-append functions that returns a vector type with a length capacity that is the sum of the arguments capacities.

==&gt; It must support **Parametric Polymorphism** (At 13:50 <https://youtu.be/SWTWkYbcWU0?t=831>)?

==&gt; They seem to state that this is what is also called Generic Types (e.g. C++ templates)?

==&gt; Consider wikipedia article on Parametric Polymorphism (<https://en.wikipedia.org/wiki/Parametric_polymorphism>)?

> > ”*Using parametric polymorphism, a function or a data type can be written generically so that it can handle values identically without depending on their type*”

> > ”*parametric polymorphism may be contrasted with ad hoc polymorphism, in which a single polymorphic function can have a number of distinct and potentially heterogeneous implementations depending on the type of argument(s) to which it is applied. Thus, ad hoc polymorphism can generally only support a limited number of such distinct types, since a separate implementation has to be provided for each type.*"

==&gt; EGO: It seems C++ also applies some ”ad hoc polymorphism” in that it applies both generic type dispatching (template specialization) and function overloading (function argument dispatching)?

==&gt; It must be **Extensible** (At 15:15 <https://youtu.be/SWTWkYbcWU0?t=917>)?

==&gt; They seem to state ”no power to the designer of the language that user don’t have”?

==&gt; They seem to explicitly refer to List and Smalltalk for being languages that has stressed this point a long time?

==&gt; Then they seem to list things that are always Bad (or insufficient) usage of the Type System?

==&gt; ”**Stringly Typed Programming**” is **bad** (At 16:30 <https://youtu.be/SWTWkYbcWU0?t=992>)?

==&gt; They seem to state that programmers should at least use type aliases to express different types although the code uses some existing type?

==&gt; They seem to talk about using a string (or an int or any existing type) to really represent a more restricted type than expressed in code?

==&gt; Ego: Like, this is a string but it is actually a string representing a hexadecimal number encoded in an ASCII character set?

==&gt; They seem to state that **Duck Typing** is kind of a type structure alias?

==&gt; Duck Typing means a value of a type may be processed as the value of another type as long as the other type has the same structural shape and element by element isomorphism?

==&gt; Ego: Like a function taking a vector of ints may also be instantiated to process a linked list of ints (isomorphic structure)?

==&gt; "**Lacking connection between logic and code"** is **bad** (At 19:45 <https://youtu.be/SWTWkYbcWU0?t=1188>)?

==&gt; Again, they seem to refer to the **curry-howard isomorphism**?

==&gt; Thus, Its bad if the logic of the code can’t be expressed as rules in the type system?

==&gt; They state that it is bad to not be able to state AND, OR, NOT (**basic boolean algebra**) at the type level?

==&gt; Ego: It would seem that to model interfaces as types we would need Duck Typing with mechanism to express ”member presence requirements”?

**==&gt; The interface type may be Duck Typed to a value of another type as long as the other value members are both present and of compatible types as stated by the interface?**

==&gt; Ego: It would seem we could implement this as an infer-function with pattern matching rules tied to structured type member presence requirements (the type states conditions for its members)?

==&gt; Finally they start listing of **ugly** things in type systems?

==&gt; There are **Ugly Syntax** (At 20:38 <https://youtu.be/SWTWkYbcWU0?t=1238>)?

==&gt; They seem to use a table mapping the passing of ”type” and ”term”?

==&gt; They seem to state that this is a way to talk about **Dependent Types**?

==&gt; They seem to state it as ”&#91;Dependent Types&#93; are the things you get when you intercept terms and types”?

==&gt; Quite at 21:08 (<https://youtu.be/SWTWkYbcWU0?t=1268>)

> > ”… I want to argue for dependent types because they’re really just the final piece of the four pieces that you get when you intersect terms and types.”

> > ”What does it mean when you pass **a term to a term**? That’s called **a function**.”  
> > ”What does it mean when you pass **a type to a term**? That’s called **inheritance** or overloading. ”  
> > ”What does it mean when you pass a **type to a type**? That’s called Parametric Polymorphism or **Generics** or Templates.”  
> > ”What does it mean when you pass a **term to a type**? That’s what **Dependent Types** are."

==&gt; **Syntax Matters** (At 2:40 <https://youtu.be/SWTWkYbcWU0?t=1360>)?

==&gt; They seem to state that we’d like "single term languages for expressions, types, kinds and sorts” (At 25:00 <https://youtu.be/SWTWkYbcWU0?t=1500>)?

![](<Use single term languages for values, types, kinds and sorts.tiff>)

==&gt; WOW - They actually seem to call the *meta-level above Kinds for ”**Sort**”* ?!!

==&gt; They seem to use ”Sort” as a ”Sort of Kind” in this paper (<http://www.leafpetersen.com/leaf/publications/dtp2013/lambda-aleph-overview.pdf>)?

> > ”...*They add integers and operations on them to the type level, and an integer sort to the **kind level***..."

==&gt; Hm, **no (?)**. Its more like that Type are sorts of values and Kind are sort of types (see ”Todo: Meh and Tha and Type Theory and Systems - Consider to delve deeper into Type Theory and the Lambda Cube to understand how we may think about Meh and Tha?”)

==&gt; **False Negatives** are **ugly** (At 26:50 <https://youtu.be/SWTWkYbcWU0?t=1612>)?

==&gt; They seem to adress the problem of geting a perfectly ok program to actually compile (but don’t due to failing type checking)?

==&gt; Thus, a programming language with a complicated syntax makes it hard for the programmer to express correct type application.

==&gt; **Type Inference both good and ugly** (At 28:06 <https://youtu.be/SWTWkYbcWU0?t=1686>)?

> ”*Type Inference : Incomplete but Expressive OR Complete but weak.*"

==&gt; Ego: This is what C++ ”auto” does?

==&gt; They seem to state that one problem is that type inference results in the most permissative type - when you actually would like Occam’s Razor and get the permissive enough but no more?

2) Consider to follow up on Yaron Minsky quote ”Make illegal state unrepresentable”?

==&gt; Consider this talk ”Effective ML” by Yaron Minsky (<https://vimeo.com/14313378>)?

==&gt; At 18:09 he reaches the bullet ”Make illegal state unrepresentable”

![](<Yaron Minsky Effective ML Type System Points.tiff>)

3) Consider to understand the Lambda Cube?

==&gt; Consider this talk ”A Type System From Scratch – Robert Widmann” on Type Systems (<https://www.youtube.com/watch?v=IbjoA5xVUq0>)?

==&gt; The take-away seems to be what the planes of the cube represents (the rest of the talk lacks meaning to me)

![](<Lambda Cube Planes.tiff>)

==&gt; Going **Left** is adding **Dependent Types**

==&gt; Going **Up** is adding **Polymorphism**

==&gt; Going **Inwards** is adding **Type Operators**

==&gt; Comparing with "Type Systems - The Good, Bad and Ugly" by Paul Snively and Amanda Laucher at 35:06 (<https://youtu.be/SWTWkYbcWU0?t=2106>) we seem to get:

==&gt; Going **Left** is adding ”Types indexed by Terms” = **Dependent Types**

==&gt; Going **Up** is adding ”Terms indexed by Types" **Polymorphism**

==&gt; Going **Inwards** is adding ”Types indexed by Types" **Type Operators**

**==&gt; And the left foremost corner is untyped lambda calculus having ”terms indexed by terms” = functions (expressions)**

4) Consider to follow up on the paper ”A Multivalued Language with a Dependent Type System” by Glew, Sweeney and Petersen (<http://www.leafpetersen.com/leaf/publications/dtp2013/lambda-aleph-overview.pdf>)?

> **A Multivalued Language with a Dependent Type System**

> Neal Glew Intel Labs [aglew@acm.org](mailto:aglew@acm.org)

> Tim Sweeney Epic Games [tim.sweeney@epicgames.com](mailto:tim.sweeney@epicgames.com)

> Leaf Petersen Intel Labs leaf.petersen@intel.com

==&gt; It seems they are on to the same idea I have to use the same syntax to operate on higher levels in the type system?

> ”*First, it makes no distinction between expressions, types, kinds, and sorts—everything is a term*”

> ”*Second, the term language has a multivalued semantics—a term can evaluate to zero, one, multiple, even an infinite number of values. Since types are characterised by their members, they are equivalent to terms whose possible values are the members of the type, and we exploit this to express type information in our language*"

==&gt; It seems ”Term Level Programming” refers to ordinary ”value semantics” and ”Type Level Programming” then is the syntax and semantics to operate on types (<https://stackoverflow.com/questions/24481113/what-are-some-examples-of-type-level-programming>)?

==&gt; This corresponds to ”terms” being mathematical objects and thus the data stored in ”variables”?

==&gt; And these ”terms” have types (in effect defining all possible values of the term)?

==&gt; Thus, in ”A Multivalued Language with a Dependent Type System”, they extend terms to be any level object.

**==&gt; Which is exactly my idea for the Meh language and the Tha type system?**

…

Consider to delve deeper into the Lambda Cube and the Good, Bad and Ugly regarding Type Systems and optionally use this knowledge to understand C++ type system and design the Meh language and the Tha data model?

...

{% endraw %}
