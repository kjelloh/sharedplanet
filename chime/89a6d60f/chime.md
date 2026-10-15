# Todo: Meta Value Model - Consider to define the environment used to evaluate Meh expression in (especially for execution of modelled functions)?

```#89a6d60f``` *As of 2017-06-16 12:44*

[mail plain/text](mail.txt)

{% raw %}
It seems we really need to be careful on how to implement the mechanism to provide the execution environment of Meh expressions, especially for functions modeled as Meh expressions?

1) Consider all functions are pure (which means function body environment must capture any external environment values when defined)?

==&gt; Also see ”[Todo: Meta Value Model - Consider to document Meta Value Model "basic" member values using the Elm language documentation form?](../83bcb31b/chime.md)”

==&gt; Consider a function modeled at some depth into the Meta Value Model instance?

model root

member model

…

member model // Function **Parent environment**

// **Defined function**

function environment (**declares arguments** (identifiers) **AND** **captured** external environment **value definitions**)

function body environment (local identifiers)

==&gt; If function bodies was allowed to access outer scope it would mean different calls would bind to different external environments (yielding different function results)?

==&gt; Thus, a function environment **declares function arguments** and **defines external environment captured values**)

==&gt; In this way the function will execute in the environment state as it was when function was defined (not when in is called)

**==&gt; Function definition declares arguments and defines external environment captured value.**

**==&gt; Function call defines function argument values and bind function return value**

2) Consider the Repl defines a parent environment for the Meta Value Model instance (aggregates the model)?

==&gt; Consider the Repl has a global environment that aggregates (and thus extends) the Meta Value Model instance?

Repl global environment

… // any global environment members

model root

member model

==&gt; This would mean the Meta Value Model instance has to be defined in the Repl global environment?

Meh´&gt; (identifier miv my_model) // global environment ”miv” declared as meta-value named ”my_model” (e.g. imported?)

Meh¨&gt; cd miv // Change environment to ”miv” value

Meh´.miv&gt;(identifier my_value number) // ”my_value” now a member of ”miv” (Meta Value Model miv mutated = new instance)?

…

…

Consider to pin down exactly how environments gets defined and bound to expression evaluations (based on all environments being immutable and all functions pure)?

...

{% endraw %}
