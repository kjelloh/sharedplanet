# Todo: C++ Meh - Consider to list the C++ keywords that are the actual Type System Operators on different Meta-layers?

```#1c67d70d``` *As of 2018-03-21 18:09*

[mail plain/text](mail.txt)

{% raw %}
What can we learn by listing all C++ keywords and pick out those we want to define as Type System Operators that actually acts as constructors of the Type System “Objects”?

==&gt; Also see “/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyClosureModelPlayground"

-3) Consider a C++ enum and union are both “tagged unions” of meta-values (<https://en.wikipedia.org/wiki/Tagged_union>)?

==&gt; Generally, An enum is a tagged union of “unit types”, i.e., single value types?

==&gt; In C++ an enum is a tagged union of values, all of the same underlaying integral type (<http://en.cppreference.com/w/cpp/language/enum>)?

*==&gt; Hm…, How do we understand an integral type in terms of Sets of Union Types (single value types)?*

==&gt; In C++ an “enum” is a tagged union of values?

==&gt; In C++ a “union” is a tagged union of types?

==&gt; Thus, “enum” and “union” repeat the same pattern but on different meta-levels?

“enum” ==&gt; {underlaying type, values = Set {tagged values of underlaying type}}

^ |

| --defacto(name)--

meta |

| v

“my_enum_variable” ==&gt; {current value}

“union” ==&gt; {underlaying types, values = Set {tagged values of underlaying types}}

^ |

| --defacto(name)--

meta |

| v

“my_union_type” ==&gt; {current type}

^ |

|  defacto(name)

meta |

| v

“my_union_type_variable” ==&gt; {current value}

**==&gt; It seems, The current type of a union is known ONLY by the type system?!!**

==&gt; Thus, It is up to the programmer to assign to correct member of the union variable so that it’s type constraints is at all time respected?

-2) Consider some initial base-set of C++ type System operators to model the basic set of C++ variables?

==&gt; Consider there is an implicit “fundamental” kind-operator that instantiates all the C++ fundamental (non compound) pre-defined types of C++ (<http://en.cppreference.com/w/cpp/types/is_compound>)?

> “*Compound types are the types that are constructed from fundamental types. Any C++ type is either fundamental or compound.*"

Meta-3 Meta-2 Meta-1

“*fundamental*”  &lt;== **meta** ==  “bool” == **value** ==&gt; {true, false} == defacto ==&gt; {variable name list}

Meta-4 Meta-3 Meta-2

“*compound*”  &lt;== **meta** ==  “class” == **value** ==&gt; { … } == defacto ==&gt; {type name list}

“*compound*”  &lt;== **meta** ==  “struct” == **value** ==&gt; { … } == defacto ==&gt; {type name list}

“*compound*”  &lt;== **meta** ==  “union” == **value** ==&gt; { … } == defacto ==&gt; {type name list}

“*compound*”  &lt;== **meta** ==  “enum” == **value** ==&gt; { … } == defacto ==&gt; {type name list}

-1) Consider to understand C++ declaration vs definitions in the context of the Meta Layered model of the C++ Type System (<http://en.cppreference.com/w/cpp/language/declarations>)?

==&gt; Consider a C++ “Declaration” is a binding of a name to its meta-value?

> “Declarations introduce (or re-introduce) names into the C++ program. Each kind of entity is declared differently."

==&gt; Consider a C++ “Definition” is binding of a name to its value

> “Definitions are declarations that are sufficient to use the entity identified by the name."

==&gt; Consider the list of possible C++ declarations?

> A declaration is one of the following:
- [Function definition](http://en.cppreference.com/w/cpp/language/function#Function_definition)
- [Template declaration](http://en.cppreference.com/w/cpp/language/templates)
- [Explicit template instantiation](http://en.cppreference.com/w/cpp/language/class_template#Explicit_instantiation)
- [Explicit template specialization](http://en.cppreference.com/w/cpp/language/template_specialization)
- [Namespace definition](http://en.cppreference.com/w/cpp/language/namespace)
- [Linkage specification](http://en.cppreference.com/w/cpp/language/language_linkage)
- Attribute declaration ([attr](http://en.cppreference.com/w/cpp/language/attributes) `**;**`) (since C++11)
- Empty declaration (`**;**`) (since C++11)
- A function declaration without a decl-specifier-seq:


- Block declaration (a declaration that can appear inside a [block](http://en.cppreference.com/w/cpp/language/statements#Compound_statement)), which, in turn, can be one of the following:

- [asm definition](http://en.cppreference.com/w/cpp/language/asm)
- [type alias declaration](http://en.cppreference.com/w/cpp/language/type_alias) (since C++11)
- [namespace alias definition](http://en.cppreference.com/w/cpp/language/namespace_alias)
- [using declaration](http://en.cppreference.com/w/cpp/language/using_declaration)
- [using directive](http://en.cppreference.com/w/cpp/language/namespace#Using-directives)
- [static_assert](http://en.cppreference.com/w/cpp/language/static_assert) declaration (since C++11)
- [opaque enum declaration](http://en.cppreference.com/w/cpp/language/enum) (since C++11)
- simple declaration



1) Consider to list all C++ keywords from this web page (

> ``[alignas](http://en.cppreference.com/w/cpp/keyword/alignas) (since C++11)  
> ``[alignof](http://en.cppreference.com/w/cpp/keyword/alignof) (since C++11)  
> ``[and](http://en.cppreference.com/w/cpp/keyword/and)  
> ``[and_eq](http://en.cppreference.com/w/cpp/keyword/and_eq)  
> ``[asm](http://en.cppreference.com/w/cpp/keyword/asm)  
> [atomic_cancel](http://en.cppreference.com/w/cpp/language/transactional_memory) (TM TS)  
> [atomic_commit](http://en.cppreference.com/w/cpp/language/transactional_memory) (TM TS)  
> [atomic_noexcept](http://en.cppreference.com/w/cpp/language/transactional_memory) (TM TS)  
> ``[auto](http://en.cppreference.com/w/cpp/keyword/auto)(1)  
> ``[bitand](http://en.cppreference.com/w/cpp/keyword/bitand)  
> ``[bitor](http://en.cppreference.com/w/cpp/keyword/bitor)  
> ``[bool](http://en.cppreference.com/w/cpp/keyword/bool)  
> ``[break](http://en.cppreference.com/w/cpp/keyword/break)  
> ``[case](http://en.cppreference.com/w/cpp/keyword/case)  
> ``[catch](http://en.cppreference.com/w/cpp/keyword/catch)  
> ``[char](http://en.cppreference.com/w/cpp/keyword/char)  
> ``[char16_t](http://en.cppreference.com/w/cpp/keyword/char16_t) (since C++11)  
> ``[char32_t](http://en.cppreference.com/w/cpp/keyword/char32_t) (since C++11)  
> ``[class](http://en.cppreference.com/w/cpp/keyword/class)(1)  
> ``[compl](http://en.cppreference.com/w/cpp/keyword/compl)  
> ``[concept](http://en.cppreference.com/w/cpp/keyword/concept) (since C++20)  
> ``[const](http://en.cppreference.com/w/cpp/keyword/const)  
> ``[constexpr](http://en.cppreference.com/w/cpp/keyword/constexpr) (since C++11)  
> ``[const_cast](http://en.cppreference.com/w/cpp/keyword/const_cast)  
> ``[continue](http://en.cppreference.com/w/cpp/keyword/continue)  
> ``[co_await](http://en.cppreference.com/mwiki/index.php?title=cpp/keyword/co_await&action=edit&redlink=1) (coroutines TS)  
> ``[co_return](http://en.cppreference.com/mwiki/index.php?title=cpp/keyword/co_return&action=edit&redlink=1) (coroutines TS)  
> ``[co_yield](http://en.cppreference.com/mwiki/index.php?title=cpp/keyword/co_yield&action=edit&redlink=1) (coroutines TS)  
> ``[decltype](http://en.cppreference.com/w/cpp/keyword/decltype) (since C++11)  
> ``[default](http://en.cppreference.com/w/cpp/keyword/default)(1)  
> ``[delete](http://en.cppreference.com/w/cpp/keyword/delete)(1)  
> ``[do](http://en.cppreference.com/w/cpp/keyword/do)  
> ``[double](http://en.cppreference.com/w/cpp/keyword/double)  
> ``[dynamic_cast](http://en.cppreference.com/w/cpp/keyword/dynamic_cast)  
> ``[else](http://en.cppreference.com/w/cpp/keyword/else)  
> ``[enum](http://en.cppreference.com/w/cpp/keyword/enum)  
> ``[explicit](http://en.cppreference.com/w/cpp/keyword/explicit)  
> ``[export](http://en.cppreference.com/w/cpp/keyword/export)(1)  
> ``[extern](http://en.cppreference.com/w/cpp/keyword/extern)(1)  
> ``[false](http://en.cppreference.com/w/cpp/keyword/false)  
> ``[float](http://en.cppreference.com/w/cpp/keyword/float)  
> ``[for](http://en.cppreference.com/w/cpp/keyword/for)  
> ``[friend](http://en.cppreference.com/w/cpp/keyword/friend)  
> ``[goto](http://en.cppreference.com/w/cpp/keyword/goto)  
> ``[if](http://en.cppreference.com/w/cpp/keyword/if)  
> ``[import](http://en.cppreference.com/mwiki/index.php?title=cpp/keyword/import&action=edit&redlink=1) (modules TS)  
> ``[inline](http://en.cppreference.com/w/cpp/keyword/inline)(1)  
> ``[int](http://en.cppreference.com/w/cpp/keyword/int)  
> ``[long](http://en.cppreference.com/w/cpp/keyword/long)  
> ``[module](http://en.cppreference.com/mwiki/index.php?title=cpp/keyword/module&action=edit&redlink=1) (modules TS)  
> ``[mutable](http://en.cppreference.com/w/cpp/keyword/mutable)(1)  
> ``[namespace](http://en.cppreference.com/w/cpp/keyword/namespace)  
> ``[new](http://en.cppreference.com/w/cpp/keyword/new)  
> ``[noexcept](http://en.cppreference.com/w/cpp/keyword/noexcept) (since C++11)  
> ``[not](http://en.cppreference.com/w/cpp/keyword/not)  
> ``[not_eq](http://en.cppreference.com/w/cpp/keyword/not_eq)  
> ``[nullptr](http://en.cppreference.com/w/cpp/keyword/nullptr) (since C++11)  
> ``[operator](http://en.cppreference.com/w/cpp/keyword/operator)  
> ``[or](http://en.cppreference.com/w/cpp/keyword/or)  
> ``[or_eq](http://en.cppreference.com/w/cpp/keyword/or_eq)  
> ``[private](http://en.cppreference.com/w/cpp/keyword/private)  
> ``[protected](http://en.cppreference.com/w/cpp/keyword/protected)  
> ``[public](http://en.cppreference.com/w/cpp/keyword/public)  
> ``[register](http://en.cppreference.com/w/cpp/keyword/register)(2)  
> ``[reinterpret_cast](http://en.cppreference.com/w/cpp/keyword/reinterpret_cast)  
> ``[requires](http://en.cppreference.com/w/cpp/keyword/requires) (since C++20)  
> ``[return](http://en.cppreference.com/w/cpp/keyword/return)  
> ``[short](http://en.cppreference.com/w/cpp/keyword/short)  
> ``[signed](http://en.cppreference.com/w/cpp/keyword/signed)  
> ``[sizeof](http://en.cppreference.com/w/cpp/keyword/sizeof)(1)  
> ``[static](http://en.cppreference.com/w/cpp/keyword/static)  
> ``[static_assert](http://en.cppreference.com/w/cpp/keyword/static_assert) (since C++11)  
> ``[static_cast](http://en.cppreference.com/w/cpp/keyword/static_cast)  
> ``[struct](http://en.cppreference.com/w/cpp/keyword/struct)(1)  
> ``[switch](http://en.cppreference.com/w/cpp/keyword/switch)  
> [synchronized](http://en.cppreference.com/w/cpp/language/transactional_memory) (TM TS)  
> ``[template](http://en.cppreference.com/w/cpp/keyword/template)  
> ``[this](http://en.cppreference.com/w/cpp/keyword/this)  
> ``[thread_local](http://en.cppreference.com/w/cpp/keyword/thread_local) (since C++11)  
> ``[throw](http://en.cppreference.com/w/cpp/keyword/throw)  
> ``[true](http://en.cppreference.com/w/cpp/keyword/true)  
> ``[try](http://en.cppreference.com/w/cpp/keyword/try)  
> ``[typedef](http://en.cppreference.com/w/cpp/keyword/typedef)  
> ``[typeid](http://en.cppreference.com/w/cpp/keyword/typeid)  
> ``[typename](http://en.cppreference.com/w/cpp/keyword/typename)  
> ``[union](http://en.cppreference.com/w/cpp/keyword/union)  
> ``[unsigned](http://en.cppreference.com/w/cpp/keyword/unsigned)  
> ``[using](http://en.cppreference.com/w/cpp/keyword/using)(1)  
> ``[virtual](http://en.cppreference.com/w/cpp/keyword/virtual)  
> ``[void](http://en.cppreference.com/w/cpp/keyword/void)  
> ``[volatile](http://en.cppreference.com/w/cpp/keyword/volatile)  
> ``[wchar_t](http://en.cppreference.com/w/cpp/keyword/wchar_t)  
> ``[while](http://en.cppreference.com/w/cpp/keyword/while)  
> ``[xor](http://en.cppreference.com/w/cpp/keyword/xor)  
> `[xor_eq](http://en.cppreference.com/w/cpp/keyword/xor_eq)`

2) Consider to separate out those acting as operators on the Type System?

> alignas (since C++11)  
> alignof (since C++11)  
> and  
> and_eq  
> asm  
> atomic_cancel (TM TS)  
> atomic_commit (TM TS)  
> atomic_noexcept (TM TS)  
> \*infer\* auto  
> bitand  
> bitor  
> \*type\* bool  
> break  
> case  
> catch  
> \*type\* char  
> \*type\* char16_t (since C++11)  
> \*type\* char32_t (since C++11)  
> \*kind\* class  
> compl  
> concept (since C++20)  
> const  
> constexpr (since C++11)  
> const_cast  
> continue  
> co_await (coroutines TS)  
> co_return (coroutines TS)  
> co_yield (coroutines TS)  
> decltype (since C++11)  
> default(1)  
> delete(1)  
> do  
> \*type\* double  
> dynamic_cast  
> else  
> \*kind\* enum  
> explicit  
> export(1)  
> extern(1)  
> \*value\* false  
> \*type\* float  
> for  
> friend  
> goto  
> if  
> import (modules TS)  
> inline(1)  
> \*type\* int  
> \*type\* long  
> module (modules TS)  
> mutable(1)  
> namespace  
> new  
> noexcept (since C++11)  
> not  
> not_eq  
> nullptr (since C++11)  
> operator  
> or  
> or_eq  
> private  
> protected  
> public  
> register(2)  
> reinterpret_cast  
> requires (since C++20)  
> return  
> \*type\* short  
> signed  
> sizeof(1)  
> static  
> static_assert (since C++11)  
> static_cast  
> \*kind\* struct  
> switch  
> synchronized (TM TS)  
> \*sort\* template  
> this  
> thread_local (since C++11)  
> throw  
> \*value\* true  
> try  
> typedef  
> typeid  
> typename  
> \*kind\* union  
> unsigned  
> using(1)  
> virtual  
> void  
> volatile  
> \*type\* wchar_t  
> while  
> xor  
> xor_eq

3) Consider to place the C++ Type System Operators into the Type System meta layers?

==&gt; Also see “/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyTestAnything"

> \*infer\* auto

> \*sort\* template

> \*kind\* class  
> \*kind\* struct  
> \*kind\* enum  
> \*kind\* union

> \*type\* bool  
> \*type\* char  
> \*type\* char16_t  
> \*type\* char32_t  
> \*type\* wchar_t  
> \*type\* double  
> \*type\* float  
> \*type\* int  
> \*type\* long  
> \*type\* short

> \*value\* true  
> \*value\* false

> namespace cpp_type_system_playground {

> // \*infer\* auto  
> //  
> // \*sort\* template

> // C++20 Proposed template contraints <http://en.cppreference.com/w/cpp/language/constraints>  
> #if (__cplusplus &gt; 201703L) // &gt; C++17  
> // Declaration of the concept "EqualityComparable", which is satisfied by  
> // any type T such that for values a and b of type T,  
> // the expression a==b compiles and its result is convertible to bool  
> template&lt;typename T&gt;  
> concept EqualityComparable = requires(T a, T b) {  
> { a == b } -&gt; bool;  
> };  
> template&lt;EqualityComparable T&gt;  
> void f(T&&); // constrained C++20 function template  
> #endif

> // \*kind\* class  
> class Base {  
> public:  
> Base() = default;  
> private:  
> int x;  
> };

> class Derived : Base {  
> public:  
> Derived() = default;  
> private:  
> int y;  
> };

> // \*kind\* struct

> // \*kind\* enum  
> enum e_Enum {  
> eEnumUndefined  
> ,eEnumUnknown  
> };  
> // \*kind\* union  
> // <http://en.cppreference.com/w/cpp/language/union>  
> union S {  
> std::int32_t n; // occupies 4 bytes  
> std::uint16_t s&#91;2&#93;; // occupies 4 bytes  
> std::uint8_t c; // occupies 1 byte  
> };

> // \*type\* bool  
> // \*type\* char  
> // \*type\* char16_t  
> // \*type\* char32_t  
> // \*type\* wchar_t  
> // \*type\* double  
> // \*type\* float  
> // \*type\* int  
> // \*type\* long  
> // \*type\* short  
> //  
> // \*value\* true  
> // \*value\* false

> }

4) Consider Type System Operators that are NOT named but implicit from semantics?

==&gt; Consider C++ Array?

==&gt; Consider C++ Function?

==&gt; Consider C++ Lambda?

5) Consider C++ “auto” is to some degree associated with a “infer” operator?

==&gt; Consider this definition of C++ “auto” (<http://en.cppreference.com/w/cpp/language/auto>)?

![](<Screen Shot 2018-03-21 at 11.52.37.png>)

==&gt; It seems “auto” in (1) engages the “template argument deduction” mechanism as soon as the initialiser type is determined?

> > “ *Once the type of the initializer has been determined, the compiler determines the type that will replace the keyword auto using the rules for template argument deduction from a function call (see template argument deduction#Other contexts for details).*"

==&gt; Consider what information of the C++ Type System the “auto” operator may infer?

==&gt; Consider if there are cases when “auto” is NOT an infer-operator?

4) Consider to find a way to model functions?

==&gt; How do we model the function “Kind” (The operator that instantiates the function declaration)?

==&gt; How do we model the function “Type” (The operator that instantiates the function definition)?

==&gt; How do we model the function Call (The operator that instantiates the function call where the arguments are bound to values in the environment of the call)?

…

==&gt; Consider the semantics of C++ functions declarations?

> int foo(int); // “foo” is a value bound to a function-type with defined return type and argument list types  
> …

> {  
> int y;  
> int x = foo(y); // Compiles but will not link (no function body to bind the argument “y” in to  
> }

==&gt; Consider the semantics of C++ function definitions?

> int y; // “y” visible to foo-body  
> int foo(int x) { return x+y;} // “foo” bound to Closure where free variable “y” is bound to external namespace “y"  
> …  
> {  
> int y;  
> int x = foo(y); // Compiles and links ok (local “y” binds to foo-argument “x”  
> /\*\*  
> \* Note that “foo” will refer to the “y” visible when defined (NOT the “y” in this call scope)  
> \* Note that our foo-argument “x” is bound to our local “y” in the call  
> \*/  
> }

==&gt; Consider we can always replace a function definition with a lambda definition?

==&gt; But a C++ Lambda can capture also automatic variables (not only “static” or “namespace” variables as cpp functions is restricted to)

==&gt; The cpp lambda is actually a struct with a special set of members to store captured variables and invoke function

![](<Screen Shot 2018-03-20 at 19.52.34.png>)

==&gt; Note: The “operator int (\*)(int) const” is a cast-operator to corresponding cpp function pointer!

5) Consider to really understand closures, C++ functions and C++ lambdas?

==&gt; Consider the wikipedia article on Closures (<https://en.wikipedia.org/wiki/Closure_(computer_programming)> )?

==&gt; It seems a Closure is “just” the function body with an environment where all external access is bound (leaving only arguments to be bound at the call)?

> “ Operationally, a closure is a record storing a function&#91;a&#93; together with an environment.&#91;1&#93; The environment is a mapping associating each free variable of the function (variables that are used locally, but defined in an enclosing scope) with the value or reference to which the name was bound when the closure was created.&#91;b&#93;A closure—unlike a plain function—allows the function to access those captured variables through the closure's copies of their values or references, even when the function is invoked outside their scope."

==&gt; In that sense it seems a C++ Lambda is a Closure where the “Capture” is the Environment where externally symbols are bound locally (<http://en.cppreference.com/w/cpp/language/lambda>)?

> “*Constructs a closure: an unnamed function object capable of capturing variables in scope.*"

6)

{% endraw %}
