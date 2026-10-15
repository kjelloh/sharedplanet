# Todo: Programming - Consider to design an example to spot the Monad pattern in a "chaining function" example?

```#25e8728d``` *As of 2017-02-20 12:54*

[mail plain/text](mail.txt)

{% raw %}
Consider to design an example where the goal is to take an imperatively designed function and turn it into a composed-function design instead and then try to spot the Monad?

-3) Consider this article as a good example of a C++ ”Maybe String” Monad (<http://zenol.fr/blog/an-alternative-error-handling-strategy-cpp/en.html>)?

==&gt; Note: This article if referred to from the ”Stop calling "Function Objects" "Functors"” (<http://jackieokay.com/2017/01/26/functors.html>)

...

-2) Consider the ”best practices” and ”lessons learned” for Functional C++?

==&gt; C++ does NOT allow binary operator function composition on built in types (e.g. functions pointers and lambdas)!

> // Error - C++ does not allow this overload for built in types (in this case function pointers)  
> // template &lt;typename F, typename G&gt;  
> // auto operator&gt;&gt;(F f, G g) {  
> // return &#91;f,g&#93;(auto x) { return g(f(x));}; // return function h, such that h(x) == g(f(x)), i.e. the composed function g\*f  
> // }

==&gt; (1) If we pipe the result value to next function it WILL work (but that is value piping, not function composition)

==&gt; For binary-operator composition of function call chains we may define value-to-next-function-piping or wrapped-function-composition-end-then-call piping.

in_value &gt;&gt; f1 &gt;&gt; f2 &gt;&gt; f3 &gt;&gt; fn // value piping to executefn(f3(f2(f1(in_value)))), i.e. direct evaluation.

(f1 &gt;&gt; f2 &gt;&gt; f3 &gt;&gt; fn)(in_value) // composition piping (fn\*f3\*f2\*f1)(in_value), i.e., lazy evaluation

-1) Consider that if the lifted functions does not apply any ”glue code”, then there is no ”Algebra” involved and the lifting Functor is NOT a Monad?

==&gt; It seems to rime well with a Monad having a bind to ”lift” diagonal functions (and it is the bind that defines the ”Algebra” about how to lift the diagonal function)?

==&gt; In example ”namespace unified” we are able to lift each f1,f2,… without ”gluing” code as the lifted parameter value can always be used ”as is” (It does not represent an optional or future value and there are no side effects to apply)?

==&gt; Q: So it seems the presence of a diagonal function indicates we require a Monad to lift it (we need a bind that defines how to chain the parameter to the diagonal function call)?

...

1) Consider some esoteric (highly abstracted) example in C++ that compiles and that we refactor step-by-step into a ”Composed-Function” design?

//

// main.cpp

// MyFunctionCompositions

//

// Created by Kjell-Olov Högdahl on 2017-01-16.

// Copyright © 2017 Kjell-Olov Högdahl. All rights reserved.

//

#include &lt;iostream&gt;

#include &lt;functional&gt;

struct Type_0 {};

struct Type_1 {};

struct Type_2 {};

struct Type_3 {};

struct Type_n {};

using Result = Type_n;

Type_1 f1(Type_0 p) {

std::cout &lt;&lt; "\\n\\t" &lt;&lt; "f1";

return Type_1{};

}

Type_2 f2(Type_1 p) {

std::cout &lt;&lt; "\\n\\t" &lt;&lt; "f2";

return Type_2{};

}

Type_3 f3(Type_2 p) {

std::cout &lt;&lt; "\\n\\t" &lt;&lt; "f3";

return Type_3{};

}

Type_n fn(Type_3 p) {

std::cout &lt;&lt; "\\n\\t" &lt;&lt; "f4";

return Type_n{};

}

namespace imperative {

Result f(Type_0 in_value) {

// (1) We want to chain function calls

Type_1 result_1 = f1(in_value);

// |

// --------------

// v

Type_2 result_2 = f2(result_1);

// |

// --------------

// v

Type_3 result_3 = f3(result_2);

// ...

// |

// --------------

// v

Type_n result_n = fn(result_3);

return result_n;

}

/\*

-&gt; f1 -&gt; -&gt; f2 -&gt; -&gt; f3 -&gt; -&gt; fn -&gt;

| | | | | | | |

"Plain" type Type_0 Type_1 Type_2 Type_3 Type_n -&gt; return -&gt; Result

\*/

}

namespace composed {

template &lt;typename F, typename G&gt;

auto composed_f(F f, G g) {

return &#91;f,g&#93;(auto x) { return g(f(x));}; // return function h, such that h(x) == g(f(x)), i.e. the composed function g\*f

}

Result f(Type_0 in_value) {

// (2) Then we may compose the functions and then just call the composed one

return composed_f(composed_f(composed_f(f1,f2),f3),fn)(in_value);

// ------- composed_f -------

// | |

// -- composed_f -- |

// | | |

// composed_f | |

// | | | |

// f1 f2 f3 fn

// | | | |

// Type_0 -&gt; Type_1 -&gt; Type_2 -&gt; Type_3 -&gt; ... -&gt; Type_n

}

}

namespace operator_composed {

template &lt;typename F, typename G&gt;

auto compose_f(F f, G g) {

return &#91;f,g&#93;(auto x) { return g(f(x));}; // return function h, such that h(x) == g(f(x)), i.e. the composed function g\*f

}

// (X) C++ does not allow this overload for built in types (in this case function pointers)

// template &lt;typename F, typename G&gt;

// auto operator&gt;&gt;(F f, G g) {

// return &#91;f,g&#93;(auto x) { return g(f(x));}; // return function h, such that h(x) == g(f(x)), i.e. the composed function g\*f

// }

// (X) Ugly syntax passing operating on function refernces (to avoid using built in function pointers)

// template &lt;typename F&gt;

// struct f_ref {

// const F& f;

// f_ref(const F& f_ref) : f(f_ref) {}

// };

//

// template &lt;typename F&gt;

// auto _ref(F f) { return f_ref&lt;F&gt;{f};}

//

// template &lt;typename FRef, typename GRef&gt;

// auto operator&gt;&gt;(FRef _f,GRef _g) {

// return _ref(&#91;=&#93;(auto x) { return _g.f(_f.f(x));});

// };

template &lt;typename R, typename T&gt;

std::function&lt;R(T)&gt; _func(R (\*f)(T t)) {return f;}; // Conveniant function factory

template &lt;typename F, typename G&gt;

auto operator&gt;&gt;(F&& f, G&& g) {

return &#91;=&#93;(auto x) { return g(f(x));};

}

Result f(Type_0 in_value) {

// (3) We must "lift" functions to some new type so we can implement function composition using some "compose operator"

// return (f1 &gt;&gt; f2) &gt;&gt; f3 &gt;&gt; fn)(in_value); // Error, can't overload binary operators for built in types (in this case function pointers)

// return (_ref(f1) &gt;&gt; _ref(f2) &gt;&gt; _ref(f3) &gt;&gt; _ref(fn)).f(in_value); // UGLY!

return (f1 &gt;&gt; _func(f2) &gt;&gt; _func(f3) &gt;&gt; _func(fn))(in_value); // STRANGE - Works because operator&gt;&gt;( function_pointer ,std::function) is allowed and works

// ---------- &gt;&gt; ---------

// | |

// -- &gt;&gt; -- |

// | | |

// &gt;&gt; | |

// | | | |

// f1 f2 f3 fn

// | | | |

// Type_0 -&gt; Type_1 -&gt; Type_2 -&gt; Type_3 -&gt; ... -&gt; Type_n

}

}

// (4) WE ARE HERE, Find a nice function type to allow C++ operator to compose functions of this function type

// ?? Use std::function ??

namespace unified {

template &lt;typename T&gt;

struct UnifiedType {

UnifiedType(T t) : value(t) {}

UnifiedType() = default;

T value;

};

UnifiedType&lt;Type_1&gt; unified_f1(UnifiedType&lt;Type_0&gt; p) {return UnifiedType&lt;Type_1&gt;{f1(p.value)};}

UnifiedType&lt;Type_2&gt; unified_f2(UnifiedType&lt;Type_1&gt; p) {return UnifiedType&lt;Type_2&gt;{f2(p.value)};}

UnifiedType&lt;Type_3&gt; unified_f3(UnifiedType&lt;Type_2&gt; p) {return UnifiedType&lt;Type_3&gt;{f3(p.value)};}

UnifiedType&lt;Type_n&gt; unified_fn(UnifiedType&lt;Type_3&gt; p) {return UnifiedType&lt;Type_n&gt;{fn(p.value)};}

Result f(Type_0 in_value) {

UnifiedType&lt;Type_1&gt; result_1 = unified_f1(UnifiedType&lt;Type_0&gt;(in_value));

// |

// ---------------------

// v

UnifiedType&lt;Type_2&gt; result_2 = unified_f2(result_1);

// |

// ---------------------

// v

UnifiedType&lt;Type_3&gt; result_3 = unified_f3(result_2);

// ...

// |

// ---------------------

// v

UnifiedType&lt;Type_n&gt; result_n = unified_fn(result_3);

return result_n.value;

}

/\*

UnifiedType UnifiedType&lt;Type_0&gt; UnifiedType&lt;Type_1&gt; UnifiedType&lt;Type_2&gt; UnifiedType&lt;Type_3&gt; UnifiedType&lt;Type_n&gt;

^ | | | | | | | | |

| --- unified_f1 ---&gt; --- unified_f2 ---&gt; --- unified_f3 ---&gt; --- unified_fn ---&gt; |

| |

create .value

| |

| --- f1 ---&gt; --- f2 ---&gt; --- f3 ---&gt; --- fn ---&gt; |

| | | | | | | | | |

"Plain" type Type_0 Type_1 Type_2 Type_3 Type_n -&gt; return -&gt; Result

\*/

}

// (2) Better.

// ==&gt; We "lift" in_value to the UnifiedType world

// ==&gt; We chain "lifted" unified_f1, unified_f2, ... together.

// ==&gt; Finally we return the "plain" value of the last result.

// (3) Can we now get rid of (hide) intermediate results?

// ==&gt; What if we define a chaining operator&gt;&gt;?

namespace operator_unified {

// using namespace unified;

template &lt;typename Param, typename UnifiedFunc&gt;

auto operator&gt;&gt;(Param&& p, UnifiedFunc unified_func) {

return unified_func(std::move(p));

}

Result f(Type_0 in_value) {

return (

unified::UnifiedType&lt;Type_0&gt;(in_value)

&gt;&gt; unified::unified_f1

&gt;&gt; unified::unified_f2

&gt;&gt; unified::unified_f3

&gt;&gt; unified::unified_fn).value;

}

}

int main(int argc, const char \* argv&#91;&#93;) {

std::cout &lt;&lt; '\\n' &lt;&lt; "&lt;imperative&gt;";

imperative::f(Type_0{});

std::cout &lt;&lt; '\\n' &lt;&lt; "&lt;composed&gt;";

composed::f(Type_0{});

std::cout &lt;&lt; '\\n' &lt;&lt; "&lt;operator_composed&gt;";

operator_composed::f(Type_0{});

std::cout &lt;&lt; '\\n';

return 0;

}

…WE ARE HERE

… Continue the refactoring and do it in a way so that we may identify return and map?

==&gt; NOTE: Is this really going to be a Monad as we do not require a bind (we have no diagonal functions)?

==&gt; Q: Should we do the refactoring so that we have diagonal functions on the way (define diagonal_f and then have bind create a unified_f)?

...

2) Consider some more real examples?

==&gt; Consider this one currently in ”/Users/kjell-olovhogdahl/Resilio Sync/XCode/MySpotTheMonadPlayground/MySpotTheMonadPlayground/ParseIntsFromFile.cpp”?

> std::vector&lt;int&gt; read_ints(const char\* szPath) {  
> // |  
> // -----------  
> // |  
> // v  
> FILE\* pFile = std::fopen(szPath,"r");  
> // |  
> // -----------------------  
> // |  
> // v  
> std::string text = read_text(pFile); std::fclose(pFile);  
> // |  
> // --------------------------------------  
> // |  
> // v  
> std::vector&lt;std::string&gt; texts = split_on_comma(text);  
> // |  
> // v  
> auto ints = map_to_ints(texts);  
> // |  
> // V  
> return ints; // --&gt;  
> }

==&gt; Consider to first make a compose-function-variant for the happy path (ignoring error path)

==&gt; Consider to then ”lift” the happy-path to an asynchronous version (each function returns a value lifted to a future)?

==&gt; Consider to then go back and lift the plain one again to a two-trtack version using optional (poor mans error path)?

==&gt; Consider to then lift it using two-track happy+error path (each function returns variant&lt;result,error&gt;

==&gt; Consider at some point lift the lifted happy-error path to the async version (lift return value to future&lt;variant&lt;result,error&gt;&gt;)?

...

3) Consider the example from ”CppCon 2015: Gor Nishanov “C++ Coroutines - a negative overhead abstraction"” (<https://www.youtube.com/watch?v=_fu0gx-xseY>)?

![](<Synchronous (blocking) tcp reader example.tiff>)

==&gt; He transforms this using Coroutines (co_await, co_return).

==&gt; Can we build on that to identify a Future Monad when bind provides the Coroutine glue stuff?

==&gt; Consider to lift this code the same way as

...

4) Consider an example of traversal of pointer structures and refactor it to Maybe-Monad composition?

==&gt; Consider to design an example (e.g. take one from TestBench) where a pointer structure is traversed?

auto pResult = pConatiner-&gt;member()-&gt;member()-&gt;member(); // each member may be NULL

==&gt; Consider breaking it down in separate steps?

auto pMember1 = pConatiner-&gt;member();

auto pMember2 = pMember1-&gt;member();

auto pMember3 = pMember2-&gt;member();

==&gt; Then add the null-check at each step.

auto pMember1 = pConatiner-&gt;member();

if (pMember1) {

auto pMember2 = pMember1-&gt;member();

if (pMember2) {

auto pMember3 = pMember2-&gt;member();

if (pMember3) {

pResult = pMember3;

}

}

}

==&gt; We seem to repeat a general pattern that is associated with each composition step?

==&gt; Consider to move the Null-check into a compose function)?

… I.e., we are close to the Maybe Monad Bind?

...

4) Consider steps to break each problem down to make it into composable functions?

1) Motivate why we want to make this into a design where we chain fucntions?  
2) Realize each function takes a ”thing” from the step before and produces a new ”thing” (functions a —&gt; b)  
3) How do we make them all take the ”same” thing and return the ”same” thing (but process the value of course)  
…

…

Consider to elaborate on this example to expose the Monad pattern?  
...

{% endraw %}
