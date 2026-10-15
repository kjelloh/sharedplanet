# Todo: Tha - Consider to understand Martin-Löf Type Theory for a better base to design the Tha meta level models?

```#8fab848a``` *As of 2019-06-25 16:46*

[mail plain/text](mail.txt)

{% raw %}
It seems I should delve a little deeper into Martin-Löf Type Theory to better understand what Type Theory folks are talking about and if and how I can leverage this knowledge into the design of Tha?

==&gt; Also see "[Todo: C++ Tha - Consider we need to add Π (dependent function return type) and Σ (dependent pairs) to be able to cope with C++ types as meta shifted semantics?](../c55a8ec4/chime.md)"

-1) Consider I have so far missed that SIGMA and PI are SORTs that creates Kinds that in turn creates one single type?

**==&gt; So in fact SIGMA and PI themselves are SORTs (provide them with A and B(a:A) they create a Kind (Type constructor) that when provided with the value a creates:**

**SIGMA:  One dependent Pair {a,B(a)}**

**PI: One dependent function a:A -&gt; B(a)**

**NOTE: When the second type does NOT depend on the value of the first then Sigma creates an ordinary pair type {A,B}, and the PI creates an ordinary function type A -&gt; B?**

1) Consider wikipedia on Martin-Löf Type Theory (<https://en.wikipedia.org/wiki/Intuitionistic_type_theory> )?

==&gt; Hm... I wonder what it means that Martin-Löf Type Theory, also Intuitionistic Type Theory is also am "alternative foundation for mathematics"?

> *"Intuitionistic type theory (also known as constructive type theory, or Martin-Löf type theory) is a type theory and an alternative foundation of mathematics. " *

> *"**Intuitionistic type theory has 3 finite types, which are then composed using 5 different type constructors.**"*

==&gt; It seems in Martin-Löf Type Theory we have a 0-type (the empty type), the 1-type (the "exists" type or "unity") and the 2-type (Boolean based choice type)

![](<Screenshot 2019-06-25 at 15.12.05.png>)

==&gt; In Martin-Löf Type Theory it seems we can compose types using Ordered Pairs (With Sigma constructor), Function Types (with Pi Constructor), The "= Type", Inductive types (types that define how they expand in terms of themselves) and finally Universe Types (to define types for any family of types)?

==&gt; It seems in Martin-Löf Type Theory works with a basic relation between Type and Object and seems to reflect the relationship between Type and a value (of an Object) having that type?

> *It keeps popping up this concept of an Object that is never fully clear to me what it is.Some times it is "anything" that exists in the stuff we discuss (like mathematical objects) or like here in MArtin-Löf theory where we loosly say "a : A" as "a has type A" where "a" is either an object (?) or the existence of a value for "a" means there is an Object for the value of "a" and that object is in Type A? I am not sure if there is some difference between these two statements? Or if I still don't get the semantics fully?*

==&gt; It seems the SIGMA type constructor "creates" ordered pairs where the first term is the enumeration using a number value and the second is a type that may or may not depend on the first element number?

![](<Screenshot 2019-06-25 at 15.29.37.png>)

> *So "Sigma types contains" should be read - types created with Sigma constructor will contain ordered pairs?*  
> *So in this case the *![](<Screenshot 2019-06-25 at 15.32.13.png>)*(a KIND constructed from SIGMA SORT) would denote a function-type that once instantiated would take a natural number n and return one ordered pair of type (n, (Real, Real, Real,... n times)). And if n = 0 the type would be (N,Real)? **Now the thing I keep tripping over is the relationship between a type-constructor (a Kind which in this case is the Sigma type constructor) and the resulting Type (in this case a pair where the first element is of type N and the second element is a tuple {Real, Real, Real...} of length n), and finally an actual instance of that type that will be a pair {x : N, y : Real&#91;n&#93;} in C like syntax). So here we in fact have the three meta-layers value, type and Kind in action?!*

==&gt; It seems the PI Type constructor "creates" Types of functions as Type -&gt; Type but where the result type may optionally depend on the value of the input type?

![](<Screenshot 2019-06-25 at 15.42.01.png>)

> *So, in general the PI function denotes **the function-type taking a **value** of some type A and return a value of a **type that depends on this value**?*  
> *So in this case the ![](<Screenshot 2019-06-25 at 15.42.42.png>) denotes the function-type that takes a Natural Number value n and returns a value of type tuple {Real, Real, Real,... n times}? Again, we must pay close attention to the meta-levels here. The denoted PI function is a Kind (a type constructor). And it creates a function type that in turn once instantiated on call will take a natural number value and return a value of the tuple {Real, Real, Real,...n times}?*

...

{% endraw %}
