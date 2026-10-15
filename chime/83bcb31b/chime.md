# Todo: Meta Value Model - Consider to document Meta Value Model "basic" member values using the Elm language documentation form?

```#83bcb31b``` *As of 2017-06-16 12:44*

[mail plain/text](mail.txt)

{% raw %}
It seems Elm language uses a form for its documentation that is very good and concise?

==&gt; Also see ”Todo: Meta Value Model - Consider to define built-in value compositions using syntax Value&lt;level 2,1,0&gt; and members as_function, as_value, as_text?"

1) Consider the documentation of the Set type (<http://package.elm-lang.org/packages/elm-lang/core/latest/Set#Set>)?

==&gt; First it states in human readable form what Set is in section ”Set"?

==&gt; Then it documents the possible Generic types in section ”Sets”

==&gt; Then it documents Set member functions to construct Set values in section ”Build"?

==&gt; Then it documents Set member predicates in section ”Query”?

==&gt; Then it documents how the type compose in section ”Combine”?

==&gt; Then it documents how to map Set values to and from List in section ”Lists”?

==&gt; Consider List is a basic type that can model any ordered sequence (and thus can serve as intermediate between compositions with ordered members)?

==&gt; Then it documents the possible Set value transformations in section ”Transform”?

…

2) Consider documentation does not provide the same section names for different types?

==&gt; Consider the documentation of Array type (<http://package.elm-lang.org/packages/elm-lang/core/5.1.1/Array>)

==&gt; It seems to use other section names than those used to document Set?

…

3) Consider a Meta Value model documentation format that can be used for all member values (all meta-levels)?

==&gt; Consider to document basic value compositions using the meta-level notation Type&lt;level&gt;?

Number&lt;1&gt;

Number&lt;0&gt;

Array&lt;2&gt;

Array&lt;1&gt;

Array&lt;0&gt;

Set&lt;2&gt;

Set&lt;1&gt;

Set&lt;0&gt;

Union&lt;2&gt;

Union&lt;1&gt;

Union&lt;0&gt;

Record&lt;2&gt;

Record&lt;1&gt;

Record&lt;0&gt;

Identifier&lt;n&gt;

…

==&gt; Consider to document the basic composition member functions?

==&gt; Also see ”Todo: Meta Value Model - Consider to define built-in value compositions using syntax Value&lt;level 2,1,0&gt; and members as_function, as_value, as_text?"

Identifier&lt;n&gt;

as_name = text

as_function = as_value().as_function

as_value = defined value

Array&lt;2&gt;

as_function = defacto

as_value = self

defacto = constructs Array&lt;1&gt; value

Array&lt;1&gt;

as_function = defacto

as_value = self

defacto = constructs Array&lt;0&gt; value

Array&lt;0&gt;

as_function = error(not a function)

as_value = self

defacto = error(not a constructor)

4) Consider to document scripting engine (repl) extensions separately?

==&gt; Consider to document the scripting engine environment separate from the Meta Value Model environment?

==&gt; Consider the Meta Value Model is a member environment of the Repl environment?

==&gt; Consider Meta Value Model function values executes in a sub-environment of the Meta Value Model parent hierarchy?

model model

member model

…

member model

function environment (declares argument identifiers **AND** captured external environment value definitions)

function body environment (local identifiers)

==&gt; Consider to stress Meta Value Model is immutable (meaning functions are pure = they can’t use outer-scope environment)

==&gt; If function bodies was allowed to access outer scope it would mean different calls would bind to different external environments (yielding different function results)?

==&gt; Thus, a function environment **declares function arguments** and **defines external environment captured values**)

==&gt; In this way the function will execute in the environment state as it was when function was defined (not when in is called)

**==&gt; Function definition declares arguments and defines external environment captured value.**

**==&gt; Function call defines function argument values and bind function return value**

...

==&gt; Consider to document as_text function as defined by the scripting language evaluator?

==&gt; Thus, the Meh evaluator will define as_text using the Meh language syntax?

==&gt; And we can provide a C++ syntax evaluator with as_text that formats into C++ syntax?

…

…

…

Consider to elaborate on ways to format the documentation of the Meta Value Model and its scripting abilities?

{% endraw %}
