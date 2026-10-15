# Todo: Tha function model - Consider to once and for all define how Tha should model function kind, type, value and call?

```#4ca21428``` *As of 2017-08-12 19:58*

[mail plain/text](mail.txt)

{% raw %}
It seems we really need to pin down how Tha should model function kind, type, value and call?

==&gt; Also see “Todo: Tha in C++ - Consider we can implement Tha meta-value stack in C++ by "laying it down" (each meta-value layer becomes a C++ value, types, kind, template stack)?"

==&gt; Also see “Todo: Tha functions - Consider to define the Tha model of functions in terms of closures?”

==&gt; Also see “Todo: C++ - Consider to describe function overloading as meta-functions that returns functions based on call signature?”

==&gt; Also see “Todo: Meta Value Model - Consider to remember how it was Captain Picard that put me on track to Elm Repl and generic function modelling?"

==&gt; Also see “Todo: Tha function types - Consider we can actually extend normal value-functions to also allow type-functions and kind-functions?"

1) Consider Tha function algebra as three operate operations?

==&gt; It seems the function **kind**: name -&gt; argument-list -&gt; binding // A function type declaration

==&gt; It seems the function **type**: binding -&gt; value-initialiser-list -&gt; function-body // A function value definition

==&gt; It seems the function **apply**: binding -&gt; value-initialiser-list -&gt; value // A function call

==&gt; Consider that Tha models these based on some lambda (anonymous function) modelling?

==&gt; Consider Tha allows generic functions (argument “types” are bound at call - in effect also instantiating a new function body with bound argument “types”)?

==&gt; Consider to compare with C++ generic lambdas (<http://en.cppreference.com/w/cpp/language/lambda>)?

> `**&#91;**` captures `**&#93;**` `**(**` params `**)**` `**-&gt;**` ret `**{**` body `**}**`

==&gt; Consider &#91; captures&#93;, ( params) and {body} are all lists (the latter a list of statements?

2) Consider that Tha models functions relative any base meta-level?

==&gt; Then It seems the base + 2 function meta-value is constructor: name -&gt; argument-list -&gt; binding // A function type declaration

==&gt; Then It seems the base + 1 function meta-value is constructor -&gt; value-initialiser-list -&gt; function-body // A function value definition

==&gt; Then It seems the base function meta-value call constructor is: binding -&gt; value-initialiser-list -&gt; value // A function call

==&gt; Thus, a call instantiates the call-environment in which to execute the function body (i.e. the stack-frame for stack-based evaluation)

3) Consider the Tha model function call dispatching mechanism?

==&gt; Consider Tha allows parameter “type” matching?

==&gt; Consider if Tha should support return “type” dispatch matching (functions can be equal in arguments but differ in return type)?

==&gt; Consider to compare with C++ ADL (<http://en.cppreference.com/w/cpp/language/adl>)?

> “*Argument-dependent lookup, also known as ADL, or Koenig lookup, is the set of rules for looking up the unqualified function names in function-call expressions, including implicit function calls to overloaded operators. These function names are looked up in the namespaces of their arguments in addition to the scopes and namespaces considered by the usual unqualified name lookup.*"

==&gt; Consider this wikipedia page on *Koenig lookup* (<https://en.wikipedia.org/wiki/Argument-dependent_name_lookup>)?

> “*During argument-dependent lookup, other namespaces not considered during normal lookup may be searched where the set of namespaces to be searched depends on the types of the function arguments. Specifically, the set of declarations discovered during the ADL process, and considered for resolution of the function name, is the union of the declarations found by normal lookup with the declarations found by looking in the set of namespaces associated with the types of the function arguments.*"

...

4) Consider if C++ class template is in fact in Tha a meta-2 based function

==&gt; Also see “Todo: Tha and Algebra Semantic Shifting - Consider re-using a language existing algebraic semantics on meta-levels is in fact a way to enable reflection using value-semantics on types and kinds?”

==&gt; Consider the “normal” C++ algebraic semantics (value, type, kind, template)

> {  
> meta-4 ( ) : template  
> **template** **&lt;typename T&gt; **meta-3 (kind) : array  
> **class a** {     ,function  
> **T x;**    ,class  
> **}**     ,union  
> ,enumeration  
> ,namespace  
> meta-2 (type) : bool  
> ,char  
> ,int  
> ,nullptr_t  
> ...  
> } algebraic-base -------------&gt; meta-1 (value): null  
> ,true  
> ,false  
> ,...

==&gt; In a “meta” scope the syntax is unchanged but the semantics is shifted

> **meta** {  
> meta-4 ( ) : template  
> **auto a(auto T)** { meta-3 (kind) : array  
> **return class {T t;};**     ,function  
> **}**  ,class  
> ,union  
> ,enumeration  
> ,namespace  
> } algebraic-base -------------&gt; meta-2 (type) : bool  
> ,char  
> ,int  
> ,nullptr_t  
> ...  
> meta-1 (value): null  
> ,true  
> ,false  
> ,...

==&gt; Note: C++ does not seem to allow generic functions (but it does allow generic lambdas)?

> template &lt;typename T&gt;  
> class a {  
> T t;  
> }

> // Is equivalent with

> meta {  
> auto a = &#91;&#93;(auto T) {  
> return struct a {  
> defacto {T t;}  
> }  
> }  
> }

==&gt; Note: We get a **quirk** in the meta-scope in that we must use a **defacto**-scope to provide the body of the struct…?

…

…

Consider to to delve deeper into this idea to have a primitive in Tha to compose functions that works on any algebraic base level?

...

{% endraw %}
