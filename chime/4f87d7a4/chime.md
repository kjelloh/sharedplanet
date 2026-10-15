# Todo: Tha and Algebra Semantic Shifting - Consider re-using a language existing algebraic semantics on meta-levels is in fact a way to enable reflection using value-semantics on types and kinds?

```#4f87d7a4``` *As of 2017-08-12 14:37*

[mail plain/text](mail.txt)

{% raw %}
Could we express the idea to be able to evaluate programming language algebra semantics on meta-values is in fact a way to “shift down” the types system to get to use value-semantics on types and kinds?

==&gt; Also see “Todo: Tha - Consider to understand the relation between a programming language algebraic semantics (values and operations) and the Tha meta-value model (type system)?"

1) Consider to decide what terms to use to describe this idea of algebra-semantics-shifting?

...

2) Consider what happens in a meta-scope with C++ algebra semantics?

// an Int alias on meta and ordinary scope

using my_int = int;

meta {

// Here algebra semantics has shifted meaning so that types gets value semantics and kinds gets type semantics.

auto my_int = int;

}

3) Consider “meta” and “defacto” syntactically shifts the language algebraic semantics up and down in the meta-value hierarchy?

==&gt; Consider the “normal” C++ algebraic semantics (value, type, kind, template)

> {  
> meta-4 ( ) : template  
> int a; meta-3 (kind) : array  
> using my_int = int;  ,function  
> struct a {  ,class  
> int x;  ,union  
> int y;  ,enumeration  
> }  ,namespace  
> template &lt;typename T&gt; meta-2 (type) : bool  
> class a {  ,char  
> T x;  ,int  
> }  ,nullptr_t  
> ...  
> } algebraic-base -----&gt; meta-1 (value): null  
> ,true  
> ,false,...

==&gt; In a “meta” scope the syntax is unchanged but the semantics is shifted

> **meta** {  
> meta-4 ( ) : template  
> // int a; meta-3 (kind) : array  
> auto my_int = int;    ,function  
> auto a = struct {  ,class  
> a(a&) = default;  ,union  
> int x;int y;   ,enumeration  
> }  ,namespace  
> --&gt; meta-2 (type) : bool  
> auto a(auto T) {  |  ,char  
> return class {T t;}; |  ,int  
> }  | ,nullptr_t  
> | ...  
> } algebraic-base -----------| meta-1 (value): null  
> ,true  
> ,false,...

…

4) Consider how Algebraic Semantic up-Shifting exposes types to value semantics?

==&gt; It seems the bets way to understand the power of Algebraic Semantic up-shifting is that it brings types and kinds down to be used in value semantics?

struct a {

int x;

int y;

}

meta {

// Semantics shifted so that types have value semantics and kinds has type semantics etc.

for (auto m: a) { // a is iteratable because it is a namespace with bindings

// m is a binding (value_name, type_name) in namespace of “a"

auto name = m.name; // “x” and “y”

auto type_name = m.meta_name; // “int”

// Note that a itself is unchanged!

// It is only the semantics in this scope that has shifted!

// The original semantics when declaring “a” still means the same thing.

}

}

...

…

Consider to find more insight and better ways to express this idea of re-using existing language algebraic semantics (meaning of algebraic expressions) when shifting the type system hierarchy up and down?

...

{% endraw %}
