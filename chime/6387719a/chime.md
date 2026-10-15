# Todo: Meta Value Model - Consider to understand C++ templates in Meta Value Model?

```#6387719a``` *As of 2017-06-14 21:26*

[mail plain/text](mail.txt)

{% raw %}
Consider it would be a good exercise to understand how C++ templates are modelled in Meta Value Model?

1) Consider a template operates on meta-2 level and is in fact a meta-2 function?

==&gt; Consider a C++ template is a meta-n function (what level is n)?

// Class template

template &lt;typename T1, typename T2&gt;

struct A { T1 x; T2 y;}

==&gt; Consider we can model this as passing arguments to function template?

template &lt;typename T1, typename T2&gt;

| |

| | struct A { T1 x; T2 y;}

| | |

template: &#91;Declaration&lt;1&gt;&#93; -&gt; Definition&lt;1&gt; -&gt; (&#91;Definition&lt;1&gt;&#93; -&gt; Value&lt;1&gt;)?

----------------  -------------  -----------------------------

| | |

argument declarations template  Actual template = meta-2 value (a function)

definition  |

Constructor for meta-1 values

e.g., A&lt;int,int&gt;, A&lt;double, string&gt;…

(The &lt;int,int&gt; is C++ Definition&lt;1&gt; list)

// Function template

template &lt;typename T1, typename T2&gt;

T1 f(T2 x) {return x\*x;}

template &lt;typename T1, typename T2&gt;

| |

| | T1 f(T2 x) {return x\*x;}

| | |

template: &#91;Declaration&lt;1&gt;&#93; -&gt; Definition&lt;1&gt; -&gt; (&#91;Definition&lt;1&gt;&#93; -&gt; Value&lt;1&gt;)?

----------------  -------------  -----------------------------

| | |

argument declarations template  Actual template = meta-2 value (a function)

definition  |

Constructor for meta-1 values

e.g., f&lt;int,int&gt;, f&lt;double, double&gt;

// Alias template

template &lt;typename T1, typename T2&gt;

using persons = std::vector&lt;std::tuple&lt;T1, T2&gt;&gt;;

template &lt;typename T1, typename T2&gt;

| |

| | using persons = std::vector&lt;std::tuple&lt;T1, T2&gt;&gt;

| | |

template: &#91;Declaration&lt;1&gt;&#93; -&gt; Definition&lt;1&gt; -&gt; (&#91;Definition&lt;1&gt;&#93; -&gt; Value&lt;1&gt;)?

----------------  -------------  -----------------------------

| | |

argument declarations template  Actual template = meta-2 value (a function)

definition  |

Constructor for meta-1 values

e.g., f&lt;int,int&gt;, f&lt;double, double&gt;

(2) Consider C++ templates can be modeled as generic type-constrctors dispatched on template arguments?

==&gt; In this way templates are just generic functions ”called” with template arguments and dispatched to matched instantiation?

==&gt; We then can apply pattern matching to pick the best candidate given the provided template arguments?

==&gt; So, how can we model C++ templates as higher-meta functions?

==&gt; consider template is the top-function?

==&gt; It instantiates type-constructors (i.e., class, function or alias templates)

==&gt; Then ”template” identifier is defined on meta-3 (!) ??

==&gt; NO! template instantiations are meta-1 generic types!

meta-2: Identifier {”template” , template&lt;3&gt; } = Set {…any template&lt;1&gt; …}

|

--------------------------------------

| (as_function args definition&lt;1&gt;) (e.g. template &lt;…args&gt; class {}, template &lt;…args&gt; T f(T) {}, template &lt;…args&gt; using name = T)

v

meta-1: Identifier {”name” , template&lt;2&gt; } = Set {…any template&lt;0&gt; …} GENERIC meta-1 values

|

--------------------------------------

| as_function args to define meta-0 value (i.e., the type constructor)

v

meta-0: Identifier {”name” , template&lt;2&gt; } = Set {…any template&lt;1&gt; …} GENERIC meta-0 values (C++ executable)

3) Consider how we implement modeling of generic types?

==&gt; Also see ”[Todo: Meta Value Model - Consider to follow up on Common Lisp Object System (CLOS) and Meta Object Protocols?](../73924a55/chime.md)”

==&gt; It seems ”generic functions” are just a special case of generic types?

==&gt; Consider ”generics” are Identifiers that are not yet fully bound (any or all of name, meta-value and value are unbound)?

==&gt; Consider how templates can be modelled as generic types using partly unbound identifiers?

==&gt; A template identifier is always named?

==&gt; A template can be declared and defined separately?

==&gt; Template declaration must bind to template argument declarations?

==&gt; The template argument becomes local names to bind to template definition?

…

4) It seems Generic Values are strongly correlated with Pattern Matching and value inferring?

==&gt; See ”[Todo: Meta Value Model - Consider mechanisms to create and apply pattern matching using existing model meta-values and explicit UML-like model patterns?](../a6a889cc/chime.md)”

==&gt; We have defined as_pattern to implement the general value inferring mechanism that we seem to be able to implement using inferred identifier and value?

==&gt; And Generic values seem to be about having a value declared in terms of an argument list that declares local names (but are still not externally bound)?

==&gt; Thus, it seems a pattern (having partly bound identifiers and values) has something to do with generic types (that has locally declared but externally unbound arguments)?

pattern: Composition of partly unbound identifiers and values.

Generic value: Composition of locally declared by externally unbound arguments (identifiers)

==&gt; Thus, it seems a pattern tries to infer unbound identifiers and values from a given value.

==&gt; And a generic type is instantiated by providing argument values.

Hm… Can we find a common abstraction here?

...

5) It seems I need to really understand how most languages implement binding of arguments on a function call?

==&gt; I suspect the argument names are bound in the environment of the call (the names given in the call)?

==&gt; Are the return value bound on call definition (it can’t be delayed to function call or function return)?

…

6) Consider we can allow generics on any meta level?

==&gt; Consider to use ”Generic” instead of ”template”?

==&gt; Generic&lt;2&gt; declares the name for all Generic&lt;1&gt; specializations!

==&gt; Generic&lt;n+2&gt; value would then be Set {… Any Generic&lt;1&gt; value with declared generic argument list …}

==&gt; Generic&lt;n+1&gt; Generic value - Each with Set {… Any Generic&lt;0&gt; value as defined by constructor }

Generic&lt;n+1&gt; defines one or more instantiations of Generic&lt;2&gt; defined value.

Each Generic&lt;n+1&gt; can be specialized for different defined template argument values (argument names cant change)

==&gt; Generic&lt;0&gt; Value, actual meta-n instantiation of defined generics (all template arguments and member values defined)

…

…

Consider to delve deeper into the nature of C++ templates, generic types and functions and how we can model these in a Meta Value Model?

...

{% endraw %}
