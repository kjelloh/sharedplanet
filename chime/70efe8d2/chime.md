# Todo: Tha - Consider to understand the relation between a programming language algebraic semantics (values and operations) and the Tha meta-value model (type system)?

```#70efe8d2``` *As of 2017-08-12 14:37*

[mail plain/text](mail.txt)

{% raw %}
Could we learn something by trying to express a language algebraic semantics (operations on values) using meta-value relative relations (in effect freeing the semantics from its concrete meaning and replace it with value/meta-value relational meaning)?

==&gt; Also see “[Todo: Tha and Algebra Semantic Shifting - Consider re-using a language existing algebraic semantics on meta-levels is in fact a way to enable reflection using value-semantics on types and kinds?](../4f87d7a4/chime.md)"

1) Consider this article on computer program semantics (<https://web.archive.org/web/20150619164601/http://www.emu.edu.tr/aelci/Courses/D-318/D-318-Files/plbook/semantic.htm>)?

==&gt; It would seem a type defines the Algebra for the Set of values it may instantiate?

> “Algebraic Semantics

> An algebraic definition of a language is a definition of an algebra. An algebra consists of a domain of values and a set of operations (functions) defined on the domain.  
> **Algebra = &lt; set of values; operations &gt;**"

==&gt; Thus, a kind (type constructor) defines an Algebra for the Set of types in may instantiate?

Type Algebra = &lt;Set of Types = kind, operations&gt;

==&gt; Even, a template (constructor of kind, type or value) defines an Algebra for the Set of “things” it may instantiate?

Kind Algebra = &lt;Set of Kinds = ??, operations&gt;

==&gt; Interesting - What is the Algebra for template instances?

…

==&gt; It seems the Algebraic Definition of natural numbers gives an insight into how to express an Algebra?

==&gt; See wikipedia on Peano Axioms (<https://en.wikipedia.org/wiki/Peano_axioms>)?

==&gt; It seems S is the Successor operator (defining ordering of natural numbers)?

> **Figure N.1: **Algebraic Definition of Peano Arithmetic

> Domains:  
> Bool = {true, false} (Boolean values)  
> N in Nat (the natural numbers)  
> N ::= 0 | S(N)

> Functions:  
> = : (Nat, Nat) -&gt; Bool  
> + : (Nat, Nat) -&gt; Nat  
> × : (Nat, Nat) -&gt; Nat

> Axioms and equations:  
> not S(N) = 0  
> if S(M) = S(N) then M = N  
> ( n + 0 ) = n  
> ( m + S(n) ) = S( m + n )  
> ( n × 0 ) = 0  
> ( m × S(n)) = (( m × n) + m)

> where m,n in Nat

==&gt; We see that the Domains are the Set of possible values of the Algebra?

==&gt; In this case we have booleans = The Set {true, false} and N the natural numbers defines as the Set of {0, }

==&gt; The “:==“ seems to be the BNF “” (<https://heerdebeer.org/ALGOL/The_History_of_ALGOL.pdf>)?

> > “*The new notation was an huge improvement over the one used earlier. Nonetheless, it was improved further by Peter Naur. He replaced or by | and :≡ by ::=.*"

==&gt; Also see wikipedia ([https://en.wikipedia.org/wiki/Backus–Naur_form](https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form))

> > “*The metasymbols ::= is to be interpreted as "is defined as”*"  
> > …  
> > “*The "**::=**" means that the symbol on the **left must be replaced with** the expression on **the right**.*"

==&gt; Also see stack overflow on “::=“ (<https://stackoverflow.com/questions/9196066/what-does-a-double-colon-followed-by-an-equals-sign-mean-in-programming-do>)?

> > “*It symbolizes 'symbol derivation rule' in Backus–Naur Form*

> > *Meaning that in:

> > *  
> > *&lt;symbol&gt; **::=** __expression__ *

> > *nonterminal &lt;symbol&gt; consists of (is defined as, **is constructed from**, derives from) __expression__

> > It's used to describe language grammars.*"

2) Consider the Algebraic Structures as defined by Wikipedia (<https://en.wikipedia.org/wiki/Algebraic_structure>)?

> “*In mathematics, and more specifically in abstract algebra, an algebraic structure is a set(called carrier set or underlying set) with one or more finitary operations defined on it that satisfies a list of axioms.&#91;1&#93;*"

==&gt; It seems every Algebraic Structure implies an Algebraic Category?

> “*...In this way, every algebraic structure gives rise to a category.*"

3) Consider this wikipedia listing of members of the Algebraic Structure Category (<https://en.wikipedia.org/wiki/Category:Algebraic_structures>)?

4) Consider the C++ algebraic semantics?

==&gt; Consider Alexander Stephanovs paper on (<http://stepanovpapers.com/DeSt98.pdf>)?

> “*we introduce the idea of a **regular type**, which matches the built-in type semantics, thereby making our user-defined types behave like bui*lt-in types as well.”  
> …  
> “  
> Fig. 1. **Fundamental Operations on Type T**

> Default constructor  T a;

> Copy constructor  Ta = b;

> Destructor  ~T(a);

> Assignment  a = b;

> Equality  a == b

> Inequality  a != b

> Ordering, e.g.  a &lt; b  
> "

==&gt; Consider we get some insights on C++ “kinds” from the std::is_compound definition (<http://en.cppreference.com/w/cpp/types/is_compound>)?

> “*...a compound type (that is, array, function, object pointer, function pointer, member object pointer, member function pointer, reference, class, union, or enumeration, including any cv-qualified variants)*"

kind “values” : ***array, function, class, union, or enumeration***

kind “references” : object pointer, function pointer, member object pointer, member function pointer, reference

==&gt; It’s a bit strange that a reference or pointer to a compound type is itself a compound type?

**C++ Tha meta-value relation**

&lt;basic types&gt;

int a; &lt;meta-name&gt; &lt;name&gt; // meta-name “int”, name “a"

int a&#91;4&#93; &lt;meta-name&gt; &lt;name&gt; &lt;cardinality&gt; // meta-name “int”, name “a”, cardinality 0…3

...

int a{4} &lt;meta-name&gt; &lt;name&gt; &lt;value&gt; // meta-name “int”, name “a”, value literal 4

…

&lt;algebraic types&gt; /<https://en.wikipedia.org/wiki/Algebraic_data_type>)

struct a {...} &lt;meta-name&gt; &lt;name&gt; &lt;value&gt; // meta-name “struct”, name “a” value &lt;struct-initialiser-list&gt;

class a {...} &lt;meta-name&gt; &lt;name&gt; &lt;value&gt; // meta-name “class”, name “a” value &lt;class-initialiser-list&gt;

enum a {...} &lt;meta-name&gt; &lt;name&gt; &lt;value&gt; // meta-name “enum”, name “a” value &lt;enum-initialiser-list&gt;

union a {...} &lt;meta-name&gt; &lt;name&gt; &lt;value&gt; // meta-name “union”, name “a” value &lt;union-initialiser-list&gt;

&lt;other kinds&gt;

int a(int x) **function** &lt;name&gt; &lt;value&gt;  // meta-name “function”, name “a”, value &lt;function-argument-list&gt;

int a(int x) {…}

==&gt; It seems we can make some observations regarding how different forms of “lists” are expressed and defined in C++?

==&gt; Note: It seems the function kind differs from the other kinds in that its type is instantiated with a (binding, binding, binding) instead of a {binding;binding;binding}?

==&gt; So **(binding, binding, binding)** &lt;=&gt; **{binding;binding;binding}** is syntactic sugar to make functions look like its mathematical counterpart?

==&gt; C++ also uses the syntax {literal, literal, literal} for initialiser-lists, also called braced-initilizer-list (<http://en.cppreference.com/w/cpp/utility/initializer_list>)?

==&gt; AND - the initialiser-list can only contain literals (it is a compile-time only instance) (<http://en.cppreference.com/w/cpp/utility/initializer_list/initializer_list>)?

==&gt; It seems functions are strange animals (they can be declared with argument-list and defined with function body and then bound at call-site)?

==&gt; How do we relate this “function type algebra” to Tha?

==&gt; Consider to express this using denotational semantics?

meaning(int a(int x);) = meaning(function “a" argument-list return-type) = meaning (a : argument-list -&gt; return-type) // a is a function that maps argument list to return type

meaning(int a(int x) {return x\*x}) = meaning (a bound-argument-list = let argument-list = bound-argument-list in body) // Note: assuming C++ expressions include statement execution

==&gt; Consider “adjustments” we can do to express C++ using some universal notion of list?

==&gt; Consider to allow any list to be expressed as braced-comma-seperated-list {value, value, value}?

==&gt; And “value” is any meta-value (including bindings as value)?

==&gt; Thus, In Tha we define a member of any of the Sets kind,type, value and Binding to be a “value” (exposing some value algebra)?

==&gt; So, we have binding lists {binding, binding, binding} meaning a namespace-initialiser-list

==&gt; And kind, type and value lists {value, value, value} meaning value-initialiser-list.

==&gt; Now, C++ initialiser-list is the Tha value-initialiser-list and may be used to define values in a namespace-initialiser-list?

meaning(namespace-initialiser-list = value-initialiser-list) = meaning (closure) // Each namespace-initialiser-list&#91;i&#93;.value = value-initialiser-list&#91;i&#93;

==&gt; We also note that namespace-initialiser-list is the meta-value of value-initialiser-list!

> > meta: namespace-initialiser-list = value : Set { value-initialiser-list… }

> > ^ |

> > | meta ----------------------

> > | | defacto

> > | v

> > defacto: value-initialiser-list = value: ...

==&gt; It would seem defacto is a map of af assignment (=) to the two lists (the new list is the one with each namespace-binding bound to the corresponding value-list member)?

…

Consider to elaborate more on this idea that we can express the grammar of a language using only meta-value relations (and thus enable the grammar to be re-used on any meta-level if we like to do so)?

...

{% endraw %}
