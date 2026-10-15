# Todo: Programming - Consider to understand C++ Monoid and Monad concepts?

```#814f2a8a``` *As of 2016-12-25 13:36*

[mail plain/text](mail.txt)

{% raw %}
I get the feeling it would be very productive and inspiring to try to understand the Monoid and Monad ”functional styyle” programmng concepts and how to apply them in C++ programming?

==&gt; Also see ”Todo: Programming - Consider to study and understand Functional Programming (e.g. Haskel) ”Monads”"

==&gt; Also see ”Todo: Programming - Consider to follow up on C++ talk on "Flow Interface" builders and monads?”

1) It seems mathematically a monoid is a binary operation on a set of values with at least one identity value such that operation returns the other value (<https://en.wikipedia.org/wiki/Identity_element>)

> ”Let (S, ∗) be a set S with a binary operation ∗ on it. Then an element e of S is called a left identity if e ∗ a = a for all a in S, and a right identity if a ∗ e = a for all a in S. If e is both a left identity and a right identity, then it is called a two-sided identity, or simply an identity."

2) It seems a Monoid is ”simply” an object (not a function) with a binary operation plus an identity value for that operation (<https://functionalcpp.wordpress.com/tag/monoid/>)?

==&gt; It seems an object with operation ”multiplication” and identity ”1” is a Monoid?

==&gt; It seems an object with operation ”plus” and identity ”0” is a Monoid?

==&gt; it seems an object with operation ”Append” and identity ”null” is a monoid?

==&gt; It seems boost has a clean definition of a Monoid (<http://www.boost.org/doc/libs/1_38_0/libs/graph/doc/Monoid.html>)?

> ”A monoid consists of a set of elements S, a binary operation, and an identity element”

> ”The C++ representation of a monoid consists of a function object that implements the binary operation, a set of objects that represent the elements of S, and an object that represents the identity element."

> ==&gt; It seems Boost definition is confusing? Why not use S in the C++ definition?

> ==&gt; S is the type defining the set of values s.  
> ==&gt; s1 and s2 are values in the set (of the type) S.  
> ==&gt; F is a function object defining the binary operation S F::op(const S&,const S&)  
> ==&gt; s_op_identity be a value of type S so that F::(s,s_op_identity) == s

3) It seems the beauty of Monoids is that they allow closed operations on a set of values with optional NOP operations?

==&gt; The NOP operation is not a special case.

==&gt; The closed-ness ensures composition (the monoid operation may be used in new monoid operations)

...

4) Consider this could carry good leads to what a Monad ”is” (<https://en.wikipedia.org/wiki/Monad_(functional_programming))>

==&gt; It seems one core idea of a Monad is to chain operations together to move values between closed sets (types) of values?

> ”A monad is created by defining a type constructor M and two operations, bind and return (where return is often also called unit):

• The unary return operation takes a value from a plain type and puts it into a container using the constructor, creating a monadic value: M a.

• The binary bind operation "&gt;&gt;=" takes as its arguments a monadic value M a and a function (a → M b) that can transform the value.

• The bind operator unwraps the plain value a embedded in its input monadic value M a, and feeds it to the function.

> • The function then creates a new monadic value M b that can be fed to the next bind operators composed in the pipeline.”

==&gt; A Monad in programming seems to be defined to comply to three ”rules”?

> ”The usual formulation of a monad for programming is known as a **Kleisli triple**, and has the following components:

> 1. A type constructor that defines, for every underlying type, how to obtain a corresponding monadic type. In Haskell's notation, the name of the monad represents the type constructor. If M is the name of the monad and t is a data type, then M t is the corresponding type in the monad.  
> 2. A unit function that injects a value in an underlying type to a value in the corresponding monadic type. The unit function has the polymorphic type t→M t. The result is normally the "simplest" value in the corresponding type that completely preserves the original value (simplicity being understood appropriately to the monad). In Haskell, this function is called return due to the way it is used in the do-notation described later.  
> 3. A binding operation of polymorphic type (M t)→(t→M u)→(M u), which Haskell represents by the infix operator &gt;&gt;=. Its first argument is a value in a monadic type, its second argument is a function that maps from the underlying type of the first argument to another monadic type, and its result is in that other monadic type. Typically, the binding operation can be understood as having four stages:  
> 1. The monad-related structure on the first argument is "pierced" to expose any number of values in the underlying type t.  
> 2. The given function is applied to all of those values to obtain values of type (M u).  
> 3. The monad-related structure on those values is also pierced, exposing values of type u.  
> 4. Finally, the monad-related structure is reassembled over all of the results, giving a single value of type (M u)."

==&gt; The Monad-rules seems to define the ”return” operation

> ”A unit function that injects a value in an underlying type to a value in the corresponding monadic type. The unit function has the polymorphic type t→M t. The result is normally the "simplest" value in the corresponding type that completely preserves the original value (simplicity being understood appropriately to the monad). In Haskell, this function is called return due to the way it is used in the do-notation"

5) It seems a Monad may be defined either as providing ”return/bind” interface or ”fmap/join” interface (<https://en.wikipedia.org/wiki/Monad_(functional_programming)#fmap_and_join)?>

> ”Although Haskell defines monads in terms of the return and bind functions, it is also possible to define a monad in terms of return and two other operations, join and fmap. ”

> ”The **fmap** operation, ... takes a function between two types and produces a function that does the "same thing" to values in the monad. The **join** operation, ... "flattens" two layers of monadic information into one."

6) The wikipedia description seems to rime very well with this blog post (<http://blog.reverberate.org/2015/08/monads-demystified.html>)?

==&gt; It seems a Monad is defined by a bind-function that defines when and how a provided unary function is called on an input Monadic value (M&lt;T1&gt;) to produce an output monadic value (M&lt;T2&gt;)

==&gt; Note that is seems the monadic value M is a function of a type T (So the nomadic value M is what defines the Nomad)?

![](<Monadic values chained by bind.tiff>)

> ”The monad’s user calls bind() and passes two arguments: the monadic value and a function that will return a monadic value. Note that bind() is a function that was defined by the monad’s author and is specific to that monad.”

> ”The monad gets to make a bunch of really interesting decisions at every stage about how to evaluate each function of the sequence, and where its input data comes from. And it gets to carry along whatever data it wants to inside the monadic value. The monad can use this to propagate whatever extra state is desired."

==&gt; It seems we should understand a Monad by answering the ”meaning” of the Monadic value and the semantics of the bind?

> ”  
> When we want to understand a new monad, there are two key questions we want to ask ourselves:

> • what does a monadic value represent in this monad?  
> • what semantic does bind() (“and then”) implement in this monad?"

==&gt; Consider this example of the ”Maybe Monad” gives some good clues to how to understand a Monad?

> ”Maybe is probably the simplest monad that is actually useful...

> A monadic value Maybe arepresents either a value of type a or Nothing...  
> And bind() implements the semantic: “if there is a value, evaluate the function (with that value), otherwise don’t evaluate the function at all.”

> So when you chain a bunch of functions together with the Maybe monad, it will evaluate all of them in sequence until one of them returns Nothing. If any function in the sequence returns Nothing then the subsequent functions won’t be evaluated at all and the chain will return Nothing.  
> "

==&gt; The Monad ”return” operation seems to be the way to transform provided plain value into a Monadic value?

> ”The job of return (in any monad) is to construct a monadic value out of a plain value.”

6) This seems like a good and pragmatic approach to describing C++ Monad and Functor, fmap and bind (<http://cpptruths.blogspot.se/2014/08/fun-with-lambdas-c14-style-part-3.html>)?

==&gt; It seems to give good leads to how bind/fmap correlates to map/flatmap etc.?

7) This seem to be a quite pragmatic approach to a C++ Maybe monad (<https://github.com/nesteruk/DesignPatternsWebinar/blob/master/maybe-monad/maybe-monad.cpp>)?

==&gt; Consider to try and understand this C++ implementation in my model of composition layers, template as ”composition” (function lifting) and type f: A —&gt; B lifted to F: F&lt;A&gt; —&gt; F&lt;B&gt;?

==&gt; Q: Can we view Person —&gt; Address —&gt; HouseName as function on values (and the Maybe monad as lifting these functions using nullptr detection as glue)?

Layer 2) Maybe&lt;Person&gt; F: Maybe&lt;Person&gt; —&gt; Maybe&lt;Address&gt; G: Maybe&lt;Address&gt; —&gt; Maybe&lt;HouseName&gt; HouseName

Layer 1) Person f: Person —&gt; Address Address g: Address —&gt; HouseName HouseName. h: HouseName —&gt; void, side-effect printing HouseName to User Interface

==&gt; It would seem f will either return an Address or nullptr?

==&gt; It would seem g will either return HouseName or nullptr?

==&gt; It would seem return value of h is not interesting, but the side effect of printing HouseName to user interface is.

==&gt; And the Maybe Monad will apply function h only if there is a HouseName to apply it to.

==&gt; In fact, the Maybe Monad will apply Layer 1 function ONLY if there is a Layer 1 value to apply it to (otherwise it will just create a ”valueless” (nullptr wrapped) Maybe instance of the Layer 1 type)?

==&gt; It seems the Maybe::With is the ”bind” function?

Layer 2) Maybe&lt;Person&gt;::With : Maybe&lt;Person&gt; —&gt; (f: Person —&gt; Address) —&gt; Maybe&lt;Address&gt;

==&gt; Note: The code uses C++ auto to make the return type generic (no need to state With return type as template parameter)?

...

8) This Github gist seems to provide good leads to C++ Monads like Maybe (<https://gist.github.com/brotchie/3134600>)?

==&gt; It seems here a Monad is a struct with member operations return_ and bind?

/\* Monad \*/  
template &lt;template &lt;typename...&gt; class F&gt;struct Monad { template &lt;typename A&gt; static F&lt;A&gt; **return_**(A);  
template &lt;typename A, typename B&gt; static F&lt;B&gt; **bind**(F&lt;A&gt;, function&lt;F&lt;B&gt;(A)&gt;);};

==&gt; So - return_ takes a value of type A and returns a value F&lt;A&gt;

==&gt; It seems the Monad&lt;Vector&gt; enables us to understand the idiom better?

/\* Monad vector \*/  
template &lt;&gt;struct Monad&lt;vector&gt; { template &lt;typename A&gt; static vector&lt;A&gt; **return_**(A v){ return vector&lt;A&gt;{v}; }  
template &lt;typename A, typename B&gt; static vector&lt;B&gt; **bind**(vector&lt;A&gt; m, function&lt;vector&lt;B&gt;(A)&gt; f){ vector&lt;B&gt; v; for_each(m.begin(), m.end(), &#91;f, &v&#93;(A a){ vector&lt;B&gt; result = f(a); copy(result.begin(), result.end(), back_inserter(v)); }); return v; }};

==&gt; Monad&lt;vector&gt;::return_ transforms a vector element A into a vector&lt;A&gt;

==&gt; Monad&lt;vector&gt;::bind transforms a vector&lt;A&gt; and a function vector&lt;B&gt;(A) into a vector&lt;B&gt; (i.e. it uses the provided function to transform a vector&lt;A&gt; to a vector&lt;B&gt;)?

==&gt; In this case it applies provided f on each element in provided vector&lt;A&gt; and appends the result to a vector&lt;B&gt;

==&gt; It seems then a Maybe-monad is Monad specialized for Maybe type?

/\* Monad Maybe \*/  
template &lt;&gt;struct Monad&lt;Maybe&gt; { template &lt;typename A&gt; static Maybe&lt;A&gt; **return_**(A v){ return Maybe&lt;A&gt;(v); }  
template &lt;typename A, typename B&gt; static Maybe&lt;B&gt; **bind**(Maybe&lt;A&gt; m, function&lt;Maybe&lt;B&gt;(A)&gt; f){ if (m.isNothing()){ return Maybe&lt;B&gt;(); } else { return f(m.fromJust());  } }};

==&gt; Note that return_ returns a Maybe&lt;A&gt; while bind returns a Maybe&lt;B&gt;?

==&gt; This piece of code seem to indicate how the Monad applies provided function to transform embedded Monadic value M&lt;T1&gt; (In this case Maybe&lt;A&gt;) to M&lt;T2&gt; (in this case Maybe&lt;B&gt;)

/\* Functor Maybe \*/  
template &lt;&gt;struct Functor&lt;Maybe&gt; { template &lt;typename A, typename B&gt; static function &lt;**Maybe&lt;B&gt;(Maybe&lt;A&gt;)**&gt; fmap(function &lt;B(A)&gt; f) { return &#91;f&#93;(Maybe&lt;A&gt; m) -&gt; Maybe&lt;B&gt; { if (m.isNothing()) { return Maybe&lt;B&gt;(); } else { return Maybe&lt;B&gt;(f(m.fromJust())); } }; };};

==&gt; So the Functor is specialized on the Monad type (in this case Maybe)?

==&gt; It seems a Functor provides an operation fmap that given a function B(A) returns a new function that maps F&lt;A&gt; to F&lt;B&gt;?

/\* Functor \*/  
template &lt;template &lt;typename...&gt; class F&gt;struct Functor { template &lt;typename A, typename B&gt; static function &lt;**F&lt;B&gt;(F&lt;A&gt;)**&gt; fmap(function &lt;B(A)&gt;);};

8) Consider this post to give good leads to Monads and programming (<https://bartoszmilewski.com/2011/01/09/monads-for-the-curious-programmer-part-1/>)?

![](<A Functor maps a morphism A to B to F(A) to F(B).tiff>)

==&gt; It seems a Functor ”lifts” a type to a ”richer” type (richer can mean topologically more complex like type T to list of type T, or additional states and values like for Maybe objects)?

==&gt; This following post seems good too (<https://bartoszmilewski.com/2011/03/14/monads-for-the-curious-programmer-part-2/>)?

==&gt; It seems a Functor F is what fmap may use to ”lift” a morphism a -&gt; b to a morphism F(a) -&gt; F(b) (e.g., float f(int) to Maybe&lt;float&gt; g(Maybe&lt;int&gt;))?

...

{% endraw %}
