# Todo: Programming - Consider to study and understand Functional Programming (e.g. Haskel) "Monads"

```#3267f141``` *As of 2017-02-03 00:28*

[mail plain/text](mail.txt)

{% raw %}
Following up on C++ work on Alexandrescu proposal for Expected&lt;T&gt; I read one proposal (<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4109.pdf>) to put Expected&lt;T,E&gt; into C++17 and stumbled cross references to Functional Programming ”Nomads” (as rational for Expected&lt;T,E&gt; interface).

1) Consider to start reading about Haskel Monads here (<https://wiki.haskell.org/Monad>)?

”The essence of monad is thus separation of composition timeline from the composed computation's execution timeline, as well as the ability of computation to implicitly carry extra data, as pertaining to the computation itself, in addition to its one (hence the name) output, that it will produce when run (or queried, or called upon)”

2) Monad seem to be defined in mathematics Category Theory also (<https://en.wikipedia.org/wiki/Monad_(category_theory)> )

==&gt; Are they related to Functional Programming Monads?

3) This seem to be a good wikipedia page about Functional Programming ”Nomads” (<https://en.wikipedia.org/wiki/Monad_(functional_programming)> )?

”In functional programming, a monad is a structure that represents computations defined as sequences of steps: a type with a monad structure defines what it means to chain operations, or nest functions of that type together. This allows the programmer to build pipelines that process data in steps, in which each action is decorated with additional processing rules provided by the monad.”

4) This post by Bartosz Milewski seem to link several C++ concepts to Haskel and Monads (<http://bartoszmilewski.com/2011/07/11/monads-in-c/>)?

”You have to understand that compile-time C++ is a strict functional language operating (mostly) on types. If that is not immediately obvious, it’s because the C++ template syntax is so appalling.”

==&gt; He talks about C++ template ”language” being 1-to-1 mappable to Haskel

” translating complex template code to Haskell may help you understand it better and enable you to maintain and extend it"

==&gt; He talks about Boost Proto being about ”Monads”?

”Boost Proto is a library for implementing domain-specific languages (DSLs). It’s an impressive piece of C++ metaprogramming but it’s hard to comprehend and it doesn’t yield to straightforward translation to Haskell. The problem is that it combines compile-time constructs with run time code in a non-trivial way. I struggled long with Proto until one day I had an epiphany– I was looking at a monad. ”

5) This post by Bartosz Milewski is another angle to C++ and Monads (<http://bartoszmilewski.com/2014/02/26/c17-i-see-a-monad-in-your-future/>)

”If you thought you were safe from functional programming in your cozy C++ niche, think again! First the lambdas and function objects and now the monad camouflaged as std::future. But do not despair, it’s all just patterns. You won’t find them in the Gang of Four book, but once you see them, they will become obvious.”

==&gt; He argues that C++11 implementation of std::future is faulty but that proposed improvement is correct based on Monad-argumentaion?

”Apparently some design patterns that form the foundation of functional programming are not obvious to everybody. So now I find myself on the other side of the discussion and will try to explain why the improved design of std::future is right.”

”Together, the methods next (or then) and unwrap, and the function make_ready_future are easily recognizable by a functional programmer as forming the monad pattern (in Haskell, they would be called, respectively, fmap, join, and return). It’s a very general pattern for composing functions that return encapsulated values."

6) This may be a good talk ”C++17: I See a Monad in Your Future” by Bartosz Milwski on C++17, Monads and Functional Programming (<https://www.youtube.com/watch?v=BFnhhPehpKw>)?

==&gt; He states object oriented programs due to hidden and shared data more or less in evidently leads to data races in concurrent programs?  
==&gt; Higher order functions are functions that takes functions as input (e.g. std::transform()).

==&gt; future::then calls a function that returns another future (the future is needed to pass either return value OR exception)

==&gt; Proposed update provides helper function future::next that calls any function (frames it into function returning a future) (See talk at 34m)

==&gt; future::next is said to ”lift” functions (in this case from return of value to return of future&lt;value&gt;)

==&gt; Generally a ”lifted function” returns some encapsulated value that the in lifted function returns.

==&gt; std::transform ”lifts” functions that operates on values to functions that operates on containers (another kind of ”encapsulated” values)

==&gt; A ”Type Constructor” maps a type to a new type, i.e. takes a type and constructs a new type (in c++ Templates are type constructors)

==&gt; E.g. ”Here is an int” and template sais ”here is a future&lt;int&gt;” (or what have you for the used Type Constructor)

==&gt; In Functional Programming a ”Functor” is a pattern combining a Type Constructor (maps a type to a new type) and ”lifting” of functions (e.g. std::next, std::transform)

==&gt; Note that C++ ”functors” are something else (a function object)

**WE ARE HERE...  
**  
7) Consider to view Expected&lt;T&gt;, std::optional&lt;T&gt;, std::future&lt;T&gt; and so on as different ”maybe T” mechanisms?

==&gt; Expected&lt;T,E&gt; is a Maybe T or E, and it is it at construction. This means we know what it as by examine it right now.  
==&gt; std::optional&lt;T&gt; is a Maybe T or nothing  
==&gt; std::future&lt;T&gt; is a Maybe T, but it is it ”not yet”. This means it has an extra ”state” of ”not yet” during which is nothing.  
…

8) Consider Monads relates to Kleisli Arrows (Diagonally lifted Functions) and CoMonads to reversed Kleisli Arrows (Diagonally Returned Functions)?

==&gt; Consider Milewskis blog series on ”Category Theory for Programmers” (<https://bartoszmilewski.com/2014/10/28/category-theory-for-programmers-the-preface/>)

==&gt; Consider Milewski blog series on ”Category Theory for the Programmer” (<https://bartoszmilewski.com/category/category-theory/>)?

==&gt; Yohooo - He uses the Mathematical Monad morphism names μ and η (See ”Comonad Categorically” in <https://bartoszmilewski.com/2017/01/02/comonads/>)?

> "*Recall, however, that in our approach to a monad, we used a more general definition of a monoid as an object in a monoidal category. The construction was based on two morphisms:*

> ```
> μ :: m ⊗ m -> m
> η :: i -> m
> ```

> *The reversal of these morphisms produces a **comonoid** in a monoidal category:*

> ```
> δ :: m -> m ⊗ m
> ε :: m -> i
> ```

  
> "

==&gt; Consider this blog post ”Monads, Kleisli Arrows, Comonads and other Rambling Thoughts” as a good one explaining Monads (<http://blog.sigfpe.com/2006/06/monads-kleisli-arrows-comonads-and.html>)?

==&gt; It seems ”Diagonal Functions” (Milewski ”Embellishing Functions”) are ”Kleisli Arrows” in Haskel (and category theory)?

==&gt; It seems they also define a coMonad as a functor that creates a function that is diagonal in teh opposite direction (un-embelished return type)?

> ”*Let's still use m to represent a **comonad**. We need to compose f::m a→b and g::m b→c. m is a functor (by definition of comonad) so **we can lift f to a function of type m (m a)→m b. This composes directly with g**. And to finish it off we use the function m a→m (m a) provided by the definition of a comonad.*"

==&gt; This seems symmetric with normal monad m: m (a) —&gt; m (m b)

==&gt; Compare int —&gt; future&lt;int&gt; lifts to future&lt;int&gt; —&gt; future&lt;future&lt;int&gt;&gt; (which is future&lt;int&gt;)

==&gt; Compare f: int -&gt; maybe&lt;int&gt; lifts to maybe&lt;f&gt;: maybe&lt;int&gt; —&gt; maybe&lt;maybe&lt;int&gt;&gt; (which is maybe&lt;int&gt;)

==&gt; Compare f: int —&gt; vector&lt;int&gt; lifts to vector&lt;f&gt;: vector&lt;int&gt; —&gt; vector&lt;vector&lt;int&gt;&gt; (which is vector&lt;int&gt;)?

...

…

Consider to delve deeper into C++ Monads, Bartosz Miliewski approach to C++ functional programming and concurrent c++?

...

{% endraw %}
