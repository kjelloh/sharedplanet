# Todo: C++ Meta - Consider to write a blog post and Lightning talk on Herb Sutter Metaclass proposal using Tha model?

```#ec963a37``` *As of 2017-08-04 16:55*

[mail plain/text](mail.txt)

{% raw %}
Could it be fun and interesting to try and compare Herb Sutters Metaclass proposal with my own Tha meta-model?

-1) Consider to make a talk where we take C++ data abstractions one by one and populate a Tha model?

==&gt; Consider to build up this Tha model of C++ step-by-step?

==&gt; Consider meta-1 and meta-2 values are C++ fundamental types (<http://en.cppreference.com/w/cpp/language/types>)?

[bool](http://en.cppreference.com/w/cpp/keyword/bool), [char](http://en.cppreference.com/w/cpp/keyword/char), [wchar_t](http://en.cppreference.com/w/cpp/keyword/wchar_t), [char16_t](http://en.cppreference.com/w/cpp/keyword/char16_t), [char32_t](http://en.cppreference.com/w/cpp/keyword/char32_t), [int](http://en.cppreference.com/w/cpp/keyword/int), [short](http://en.cppreference.com/w/cpp/keyword/short), [long](http://en.cppreference.com/w/cpp/keyword/long), [signed](http://en.cppreference.com/w/cpp/keyword/signed), [unsigned](http://en.cppreference.com/w/cpp/keyword/unsigned), [float](http://en.cppreference.com/w/cpp/keyword/float), [double](http://en.cppreference.com/w/cpp/keyword/double)

[true](http://en.cppreference.com/w/cpp/keyword/true), [false](http://en.cppreference.com/w/cpp/keyword/false)

==&gt; And compound types (<http://en.cppreference.com/w/cpp/language/type>)?

> > A [name](http://en.cppreference.com/w/cpp/language/name) can be declared to refer to a type by means of:
- [class](http://en.cppreference.com/w/cpp/language/class) declaration;
- [enum](http://en.cppreference.com/w/cpp/language/enum) declaration;
- [typedef](http://en.cppreference.com/w/cpp/language/typedef) declaration;
- [type alias](http://en.cppreference.com/w/cpp/language/type_alias) declaration.



==&gt; Consider this can be modeled in Tha?

meta-4: template

meta-3: *array*, union, struct, class, enum

meta-2: void, char, int, float, *function*

meta-1: true, false

==&gt; Consider “array” is actually operator&#91;&#93;(meta-2-value value_type,size_t capacity)?

==&gt; Consider “void” has a private constructor (instantiation not allowed = incomplete type)?

==&gt; Consider “function” is actually implicit from syntax meta-2-value(meta-2-value… Args)?

==&gt; Consider “template” actually defines two Sets (function templates and class templates)?

==&gt; Consider how we can model “alias templates” ?

==&gt; It seems the “using” keyword is not a member of the Tha (it is an operation on values in the Tha)?

...

==&gt; Consider literal values?

meta-4:

meta-3:

int a; meta-2: “int” --&gt; Set {…-2,-1,0,1,2...}

^

| *declaration*

|

meta-1: “a"

==&gt; Consider a literal value.

meta-4:

meta-3:

int a = 2; meta-2: “int” --&gt; Set {…-2,-1,0,1,**2**...}

^ |

| | defacto

| *definition v*

meta-1: “a” -------------------&gt; 2

==&gt; Consider a literal value.

meta-4:

meta-3:

char a; meta-2: “char” --&gt; Set {…’ ‘,’0’,’1’,…,’A’,’B’,...}

^

| *declaration*

|

meta-1: “a"

==&gt; Consider a literal value.

meta-4:

meta-3:

float a; meta-2: “float” --&gt; Set {-1.4012984 ^ 10-47,…,+1.4012984 ^ 10-47} // 32 bit

^

| *declaration*

|

meta-1: “a"

==&gt; Consider basic arrays

meta-4:

meta-3: “operator&#91;&#93;"

int a&#91;3&#93;; meta-2: “??” --&gt; Set {any &#91;int,int,int&#93;...}

^

|

|

meta-1: “a”

…

1) The Herb Sutter proposal seems to be available on the web now?

==&gt; Consider his ACCU talk “Thoughts on Metaclasses - Herb Sutter - Keynote &#91;ACCU 2017&#93;” (<https://www.youtube.com/watch?v=6nsyX37nsRs>)?

==&gt; The proposal “Metaclasses Document Number: P0707 R0” seems to ber available here (<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0707r0.pdf>)?

2) Consider to relate to existing comments on the web on Herb Sutters metacalss C++ proposal?

==&gt; Consider Jonathan Baccarat’s blog post “A Summary of the Metaclasses Proposal for C++” (<http://www.fluentcpp.com/2017/08/04/metaclasses-cpp-summary/>)?

…

3) Consider to write down my own Tha metamodel and relate it to Herb Sutters proposal?

==&gt; Consider the basic idea of identifier bindings to value and meta-value pattern?

==&gt; Consider basic idea to re-use value semantics in C++ also for meta-value levels?

meta-4: template

meta-3: class, struct, enum, operator&#91;&#93; (array)

meta-2: int, char, …

meta-1: user values

---------------------------

meta-0: run-time executable representation

==&gt; It seems Herb uses ‘$’ to indicate “meta-class” (i.e. $class is a meta-class)?

==&gt; It seems he mosses the opportunity to treat template as meta-function (i.e. $function if C++ had a keyword “functions" in the same way it has keyword “class”)?

==&gt; Still - A template can be a type-constructors in the same way the keyword “class” already is)?

==&gt; Consider meta-3 level is about type composition (defines sets of composed meta-2 values)?

==&gt; Consider meta-2 level is about sets of values.

==&gt; Consider meta-1 are the user values (and functions)?

==&gt; Consider meta-1 functions maps between meta-2 sets of values?

...

4) Consider seem C++ syntax for meta-level-shifting of re-used C++ syntax?

==&gt; Consider “for" iterates over array of (repeated) values (and can be re-used to iterate over meta-values on any level)?

==&gt; Consider “switch” maps to Set (one of) values (and can be re-used on meta-values on any level)

==&gt; Consider “if” maps to boolean value (and we can define bollena to be a type available on any value)

==&gt; Consider each meta-value level to re-use a small set (all?) of C++ literals (int, bool, “text”)?

==&gt; Consider how “class” is in fact a type-constructor on meta-3 level?

==&gt; How can we define the meta-3-value named “class”?

auto class = \*constructor that creates an And-type from a list of declared or defined meta-1 names \*

==&gt; Consider declared variable members are those that gets a value from the class constructor?

==&gt; Consider declared function members are methods that gets defined separately (e.g. in in cpp file)?

==&gt; Consider defined variable members are those that has default initialisation (has defined value)?

==&gt; Consider defined function member (methods) are those that are inlined (has function body)

…

==&gt; Consider how “struct” and “class” differs only in members default accessibility (public versus private)?

==&gt; Consider how “enum” is in fact a type constructor on meta-3-level?

==&gt; How can we define the meta-3-value named “enum”?

auto enum = \*constructor that creates an Or- type from a list of declared meta-1 names (all of the same meta-2-value, i.e. type)?

==&gt; It seems an enum-type actually aggregates an array o possible members?

==&gt; It seems if we choose semantics carefully we can make an std::variant and the “enum” look “the same” (std::variant is a meta-2 enum value while built in enum is a meta-1 value)?

...

==&gt; Consider how “array” is in fact a type-constructor on meta-3-level?

==&gt; How can we define the meta-3-value named “array”?

auto enum = \*Constructor that creates a special and-type that defines all members to have the same type\*?

==&gt; Consider to aim at defining a struct and an array both as lists but struct has named members (indexed by name) and array has indexed members (indexed by integer)

==&gt; Consider meta-3 level basically only defines a small set of basic compositions?

==&gt; An aggregation of a single meta-2 value that construct an arrays of meta-1 values of this type?

==&gt; An aggregation of two meta-2 values that constructs a mapping between meta-1 values of the two types (key, value pairs)?

==&gt; An indexed member And-type of meta-2 values (tuple of meta-2 values)?

==&gt; A named member And-type of meta-2 values (classes, structs)

==&gt; Named meta-2 value members in effect means meta-1 value declarations)?

==&gt; A named member OR-type (std::variant&lt;meta-2 values...&gt;

==&gt; An indexed member Or-type (a strange union of meta-2 values set by integer index)??

Hm… we need to think a bit more to get this list small and consistent?

...

**==&gt; We want to leverage on the observation that base composition is Or-types and And-types with indexed members OR named members?**

==&gt; Thus, it seems meta-3 value “array” is to define arrays of meta-1 values (using a single meta-2 value and type constructor to define this)?

==&gt; In fact - all C++ meta-3 values are about meta-1 value compositions (using the meta-2 value only as “middle man” to provide the right constructor for meta-1 values)?

...

==&gt; Consider what extra “things” we need to name to be able to re-use C++ syntax on meta-value 2 and 3 (actually write code for “class”, “struct”, “enum” language constructs)?

…

5) Consider how many of the C++ keywords we can map into the Tha meta-model?

==&gt; Consider this page for C++ keyword definition (<http://en.cppreference.com/w/cpp/keyword>)?

> # C++ keywords

  
> [C++](http://en.cppreference.com/w/cpp)  
> [C++ language](http://en.cppreference.com/w/cpp/language)  
> **C++ keywords**  
> This is a list of reserved keywords in C++. Since they are used by the language, these keywords are not available for re-definition or overloading.  
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

…

…

Consider to delve into this idea to provide some small and initial blog-post and Meeting C++ talk (17 Aug) on Herb Suters Meta-class proposal?

...

{% endraw %}
