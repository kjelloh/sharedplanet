# Todo: C++ Tha - Consider we need to add Π (dependent function return type) and Σ (dependent pairs) to be able to cope with C++ types as meta shifted semantics?

```#c55a8ec4``` *As of 2019-06-25 16:26*

[mail plain/text](mail.txt)

{% raw %}
I am slowly getting to grips with dependent types and now think we should consider to add dependent types (dependent function return type and pair)?

==&gt; Also see "[Todo: Tha - Consider to understand Martin-Löf Type Theory for a better base to design the Tha meta level models?](../8fab848a/chime.md)"

1) Consider youtube video "Naïve Type Theory by Thorsten Altenkirch (University of Nottingham, UK)" (<https://www.youtube.com/watch?v=bNG53SA4n48&t=2721s> )?

==&gt; Consider it is intuitive but seems not to be true to suspect dependent types to be dependent SUM and dependent PRODUCT (But is in fact dependent return type and dependent pair)?

==&gt; Consider it is confusing that Σ denotes dependent pair (which should suggest PRODUCT) but is in fact SUM

![](<Screenshot 2019-06-22 at 22.17.54.png>)

Thorsten Altenkirch does not seem to use the syntax of Π in the same way as suggested in wikipedia article on dependent types?

2) Consider I still have a hard time reading the syntax used in type theory?

TODO: Try to pin point all my confusions and then straighten them out?

> *What does a statement with three ':' mean? I read ':' to mean "such as" but it also some times seems to mean "of type"?*

> *And what does '.' mean? In Thorsten Altenkirch lecture it could seem to imply "pair", But it could also be lambda calculus syntax and mean "reduced/computed to"? But then, this does not correlate with lambda calculus as defined in wikipedia article (*[*https://en.wikipedia.org/wiki/Lambda_calculus](https://en.wikipedia.org/wiki/Lambda_calculus) )?*

3) Consider wikipedia on dependent types (<https://en.wikipedia.org/wiki/Dependent_type> )?

==&gt; Also see "[Todo: Tha - Consider to understand Martin-Löf Type Theory for a better base to design the Tha meta level models?](../8fab848a/chime.md)"

NOTE: Both SIGMA and PI creates a single type (SIGMA a single pair and PI a single function)?!

NOTE: Sigma seems defined to be a Kind (a type constructor) that creates one ordered pair type (the first element is a value and the second element is a type)?

NOTE: PI seems defined to be a Kind (a type constructor) that creates (all?) function types with return type that depends on the provided value (like an n-tuple)?

**NOTE: When the second type does NOT depend on the value of the first then Sigma creates an ordinary pair type {A,B}, and the PI creates an ordinary function type A -&gt; B?**

**==&gt; So in fact SIGMA and PI themselves are SORTs (provide them with A and B(a:A) they create a Kind (Type constructor) that when provided with the value a creates:**

**SIGMA:  One dependent Pair {a,B(a)}**

**PI: One dependent function a:A -&gt; B(a)**

4) Consider how I initially did not get that SIGMA and PI are Kinds (type constructors) so they define the type-signature of the cerated type, not the type instance?

==&gt; I am still confused (See below) but maybe Π denotes a tuple with a variable length and *Σ a pair with second part type dependent on the first part value?*

*NO: **PI creates a FUNCTION-TYPE** that given a value of type A returns a value of a TYPE that depends on this value (e.g., an n-tuple but can be some other relation)?!*

> *Now it is still not clear to me why this seems asymmetric to me. Soemthing in me has the intuition that we should expect dependent products and dependent sums. Where both outputs a count of "addition" and "multiplication" that is defined by a value from the first type? So somehow the Σ type function would produce B + B + B + B +... n times where n is of type A. And Π would produce B x B x B x B x... n times where n is of type A. So why is that NOT so? Are these compositions not valuable or useful. Maybe they just don't mean anything?*

> *Now it seems the *Π type function is actually *B x B x B x B x... n times**, i.e., it is a tuple of n length (i.e., a "collapsed" or "flattened" **B x B x B x B x...**)**?*

> *Could we not make sense of **B + B + B + B +...* *in the same "flattened" way?*

> *Anyhow, it seems the actual **Π is able to also produce tuples where each B is different (or am I wrong here). At least the **Σ type function can create pairs where the second element is of a type that depends on the value of the first member? But I still don't get if **Σ can create only one pair?*

==&gt; Consider to stick to the notion that the Π type function is closely related to the cartesian product of types?

> For Π to somehow produce a tuple and also resemble a cartesian product of types it seems we should imagine it first implicitly creates a SET with n empty types, where n is a member of input type A. Then it produces a set of types B(x) for ...

> F\*CK - THIS DOES NOT COMPUTE!!

==&gt; It is not super clear to me but it seems if we have a "universe" of Types (thus many types) and A is one of those types, then a dependent type is one created by a function that takes a member of A as an argument and returns some Type in the universe U?

![](<Screenshot 2019-06-22 at 22.48.09.png>)

==&gt; Now the dependent type Π seems to denote a PRODUCT type (tuple) with members of type B(x) where x is a member of type A?

*NO: **PI creates a FUNCTION-TYPE** that given a value of type A returns a value of a TYPE that depends on this value?!*

> *"The name 'pi-type' comes from the idea that these may be viewed as a Cartesian product of types."*

NOTE: The comment about PI being somehow related to the Cartesian Product seems to be nonsense. It is the SIGMA that

![](<Screenshot 2019-06-22 at 22.34.50.png>)

*The Π Type is (normally? Always?) an x-tuple of type B(x) where B is a function that returns a type and x is an integer (A is always some number type)?*

==&gt; NO! The semantics of Π is not to actually "multiply", it is the actual B provided that defines the tuple created - CONFUSING!! (See B(x) == Vec(R,n) below)

![](<Screenshot 2019-06-22 at 23.01.15.png>)

*Is wikipedia actually correct here (it would seem the semantics of Π is nothing and all the "work" is done by "B(x)" == Vec(R,n))?*

==&gt; It seems the dependent type Σ is a type constructor that creates dependent pairs where the first member of the pair is a value x from type A and the second member is a type B(x)?

> *"The dependent pair type captures the idea of an ordered pair where the type of the second term is dependent on the value of the first."*

![](<Screenshot 2019-06-22 at 22.35.08.png>)

The *Σ type function creates a pair (how many?) *

![](<Screenshot 2019-06-22 at 23.21.44.png>)

*This expression reads that the pair ( a, b) is of type Σ where a is of type A and b is of type B(a) (i.e., a dependent pair)*

...

{% endraw %}
