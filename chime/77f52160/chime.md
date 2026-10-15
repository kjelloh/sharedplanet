# Todo: Meh and Tha and Type Theory and Systems - Consider to delve deeper into Type Theory and the Lambda Cube to understand how we may think about Meh and Tha?

```#77f52160``` *As of 2017-10-11 15:54*

[mail plain/text](mail.txt)

{% raw %}
It seems we can learn from existing Type Theory and Systems to understand more about how we may design the Meh and Tha for data modelling and Type System implementation?

==&gt; Also see ”[Todo: Type Systems - Consider Strange Loop talk "Type Systems - The Good, Bad and Ugly" by Paul Snively and Amanda Laucher as having good leads into good and bad type systems and the need for a better programming language?](../9b0ab729/chime.md)”

1) Consider this page on the Lambda Cube (<http://www.rbjones.com/rbjpub/logic/cl/tlc001.htm>)?

==&gt; It seems the "Lambda Cube” is in fact specifically ”Barendregt's Lambda Cube"

==&gt; It seems ”Sorts” are simply the grouping of the objects of the Type System into Terms (values), Types and Kinds (So Types is a Sort and Kinds are another Sort)?

> ”...*it may be helpful to think of these as the sorts of types and kinds respectively...*”

> ”*...which says that the sort of types is a kind...*"

...

2) Consider this web place about Type Theory and the Lambda Cube (<https://arstechnica.com/civis/viewtopic.php?f=20&t=750920>)?

==&gt; It seems the SET of all Types is denoted \* and the SET of all Kinds is denoted ⃞ ?

> ”*All the typesystems in the lambda-cube have two sorts: types and kinds. Expressions and values have types. Types and type operators (and type expressions) have kinds. The set of all types is "\*" (we'll use "Type"). The set of all kinds is a hollow box (sorry, can't ASCII, we'll use "Kind").*"

==&gt; Here again it seems that ”Sorts” are grouping of objects in the type system?

> ”*...One sort is types, expressions and values have types. Another sort is kinds. Types and type constructors have kinds..*"

==&gt; There seem to be something above ”Kind” represented by a triangle?

> ”...*Or, sometimes, we want to talk about the set of all Kinds (types, type constructors, higher order type constructors, ..., omega order type constructors). We might reach a paradox if we choose that the set of all Kinds is a Kind. So we might choose that there is something higher than Kind (usually written as a triangle, I don't know how it's pronounced ![smile](icon_smile.gif))*"

==&gt; So, we still have no name for the grouping of Kinds?

> ??  
> |  
> Kinds  
> |  
> Types  
> |  
> Terms (values/Expressions)

==&gt; It seems Type Systems are expressed as Sets of Sorts but the Lambda Cube is about Systems using three Sorts (s1=Types, s2=Kinds and s3 = ??)?

> ”*There is actually any number of different sorts. There is any number of axioms, expressing any arbitrary relationship between sorts.*”

> ”*Instead of the (s1, s2) rule, there is really a family of (s1, s2, s3) rules:*”

==&gt; And the s1, s2, s3 rule for the Lambda Cube can be expressed

> > G |- A: s1 G, x: A |- B: s2  
> > -------------------------------  
> > G |- (pi x: A. B): s3

G |- A: s1 reads as proposition: If Given any environment G we can conclude that A is of sort s1.

G, x: A |- B: s2 reads as proposition: If given any environment G, and x is of type A, we can conclude that B is of Sort s2.

G |- (pi x: A. B): s3 reads as conclusion (below the line): Given any environment G we can conclude that pi mapping a value to a type is of sort s3.

==&gt; But in the Lambda cube s2 = s3 (all type constructors including dependent type constructors are kinds)

> ”...*In the lambda-cube, we always have s2==s3. That is: ... A type parameterized over a type is a type, and a type parameterized over a value is a type.*"

==&gt; It seems pi is the pi-function associated with dependent types (<https://en.wikipedia.org/wiki/Dependent_type>)?

> ”*A function whose type of return value varies with its argument (i.e. there is no fixed codomain) is a dependent function and the type of this function is called dependent product type, pi-type or simply dependent type*"

3) Consider if and how we can express the C++ type system using Type Theory and the Barendregt's Lambda Cube?

==&gt; Consider the Constants int the Set of all types are the C++ built in types (<http://www.rbjones.com/rbjpub/logic/cl/tlc001.htm>)?

> Use S : The subset of the constants of the system known as the sorts.

> Then the C++ Types in S are: int, float, bool, …

> And the C++ Kinds in S are: struct, class, enum, union, …

==&gt; It seems in fact we may say that the template constructor are a sort of kinds (they construct kinds)?

==&gt; Thus, in C++ s2 (Kinds) are separated from s3 (Sort of kinds)?

…

...

…

Consider to delve deeper into Type Theory and Systems, Lambda Cubes and what have you to understand C++ type system and where the Tha meta-layers fit in to this picture?

...

{% endraw %}
