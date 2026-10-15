# Todo: Meta Value Model - Consider ways to implement function meta-value hierarchy (meta-2...meta-0 declaration, definition operations)?

```#130c6d9a``` *As of 2017-06-13 15:28*

[mail plain/text](mail.txt)

{% raw %}
It seems we need to get the Meta Value Model of functions to fit the meta-value hierarchy which adds the trickery of functions having an extra dimension in that they bind to it arguments on meta-0 call (not on meta-0 definition)?

1) It seems we need to figure out what gets declared and what gets bound on each of the meta-levels of function meta-values?

==&gt; It seems Function&lt;2&gt; value is a constructor of Function&lt;1&gt; values that defines a mapping Value&lt;1&gt; -&gt; Value&lt;1&gt;?

Function&lt;2&gt; = Set of {… any Function&lt;1&gt; = Value&lt;1&gt; -&gt; Value&lt;1&gt; …}

as_function = constructs Function&lt;1&gt; from Value&lt;1&gt; argument

==&gt; It seems Function&lt;1&gt; value is a constructor of Function&lt;0&gt; values that defines a mapping Value&lt;0&gt; -&gt; Value&lt;0&gt;?

Function&lt;1&gt; = Set of {… any Function&lt;0&gt; = Value&lt;0&gt; -&gt; Value&lt;0&gt; …}

as_function = constructs Function&lt;0&gt; from Value&lt;0&gt; argument

==&gt; It seems Function&lt;0&gt; values are actual callable functions mapping Value&lt;0&gt; -&gt; Value&lt;0&gt;?

Function&lt;0&gt; = single function value

as_function = function body

Identifier&lt;Function&lt;0&gt;&gt; = binds a name to Function&lt;1&gt; value (declaration) and Function&lt;0&gt; value (definition)

as_function =  ?? For other values we have designed this to mean (define name as_function(Value&lt;1&gt;))), i.e., bind name to value

?? But for functions we must have it mean call-the-function?

...

==&gt; So - How do we define a function versus how do we call it?

==&gt; Consider declaration and definition like any-other-value?

meta-0&gt; (declare f (function number text)) // declares identifier ”f” to be meta-2 identifier ”function” applied to meta-1 identifiers ”number” and ”text” = mapping number -&gt; text

meta-0&gt; (f x (x\*x)) // defines identifier ”f” meaning declaring argument names and body definition (having argument name accessible in its namespace)

==&gt; This would mean applying function as-function would yield the same syntax as function definition?

meta-0&gt; (f y) // ?? Function definition but missing the body value?

==&gt; But, Consider Identifier as_function differs depending on wether identifier has been defined or not?

(undefined_identifier argument) // would mean define undefined_identifier as argument?

(defined_identifier argument) // Would mean apply identifier value as_function to argument?

Thus, after definition of function we may apply it using its name as identifier?

meta-0&gt; (f y) // Apply f to value y (because f is defined and thus ”applicable”)?

==&gt; Q: Does this make a good syntax for the language (or will it be confusing for the programmer and cause programming errors ”undefined is not a function”)?

==&gt; Note: ”Undefined is not a function” is the #1 issue in Javascript (We do not want that problem)?

...

2) Consider to allow function currying (be applied to multiple parameters)?

==&gt; What would it take for us to allow functions to accept a list of parameters?

(declare f (function number number number)) // would mean f: number -&gt; number -&gt; number

(f x y (x+y)) // define f by declaring argument names and function body

==&gt; Then Function&lt;2&gt; constructor must instantiate a Function&lt;1&gt; with as many parameters as provided to the constructor?

(function number number number) // would create a Function&lt;1&gt; that knows how to defined Function&lt;0&gt; instances that accepts two numbers as arguments?

==&gt; Consider we would like currying to take place (allowing to express definitions leaving arguments unbound)?

(declare f (function number number number)) // would mean f: number -&gt; number -&gt; number

==&gt; Q: How can we define a Function&lt;0&gt; where first parameter gets defined byt second does not (i.e. define (f x) )?

(f x) could be read as f with first argument declared as ”x” (but f takes two parameters so the second one is still undeclared)?

i.e., (f x) : (function number -&gt; number) ?

((f x) y) could then read (f x) argument declared as ”y” (but no function body yet)?

(f (x+y)) could now read as f defined to function body x+y (argument x and y already declared?

…

==&gt; Consider to look again at CLOS generic functions (See ”Todo: Meta Value Model - Consider to follow up on Common Lisp Object System (CLOS) and Meta Object Protocols?”)

==&gt; It seems in CLOS the meta-1 definition declares function name AND argument names (but not argument types)?

==&gt; This would rime with a generic function is dispatched on argument number and types (so we must leave the types out)

==&gt; Thus, we may now defined several meta-0 functions with different argument types and bodies (to have function name be dispacthed on argument airity and types)?

**==&gt; Q: How do we allow Meta-lisp functions to be defined for parameter airity and type dispatching?**

**WE ARE HERE...**

2) Consider to implement the Elm language idiom (<https://guide.elm-lang.org/types/reading_types.html>)?

==&gt; Elm seems to allow separated function declaration using ”Type Annotations”

> ”...but it also lets you write a type annotation on the line above a definition if you want."

Elm&gt; **Update : Msg -&gt; Model -&gt; Model** // Reads: Identifier ”update” is of meta-value Msg -&gt; Model -&gt; Model

==&gt; Which would mean our Meta Value Lisp declaration could be:

meta-0&gt; **(declare Update (function Msg Model Model))**

==&gt; The function definition seems to declare arguments and define the function body?

Elm&gt; **Update msg model = … function body …**

==&gt; Which would mean our Meta List definition would be:

meta-0&gt; **(define Update msg model (… function body…))**

==&gt; Note: It seems we can’t apply the function identifier as value constructor as this would would be confused with function application (how would evaluator know when to execute constructor and when to execute actual function)?

==&gt; Or, Can we define that an undefined Identifier will act as value constructor bit a defined Identifier will apply the as_function on the value?

**Identifier&lt;0&gt;**

**as_function = if (undefined identifier)**

**then (define identifier as_function(as_meta identifier))**

**else as_function(as_value identifier)**

==&gt; And our declaration, definition and call in Meta List will be:

meta-0&gt; **(declare Update (function Msg Model Model)) **// Identifier&lt;0&gt; ”Update” declared (bound to) Function&lt;1&gt; value created by Function&lt;2&gt; applied to Identifier&lt;1&gt; Msg, Model, Model

==&gt; Note: The created Function&lt;1&gt; value is not bound to a name on meta-1 level (there is no Identifier&lt;1&gt; for this value)?

meta-0&gt;**(Update msg model (…function body …))** // Identifier ”Update” is undefined so as_function on ”Update” will bind it to constructed Function&lt;0&gt; value

==&gt; In effect name ”Update” is bound to meta-value Function&lt;0&gt; and **function namespace Identifier&lt;0&gt;** ”msg” and ”model” are **declared**.

meta-0&gt;**(Update a_msg current_model)** // Identifier ”Update” is now defined, so apply its value as_function to Identifier&lt;0&gt; ”a_msg” and ”current_model” (i.e., **call the function**)

==&gt; In effect environment Identifier&lt;0&gt; ”a_msg” and ”current_model” are bound to function namespace Identifier&lt;0&gt; ”msg” and ”model” (declared when function identifier was defined)

…

==&gt; The trick seems to be to be to use a Function&lt;1&gt; value without a bound Identifier&lt;1&gt; (a meta-1 lambda?)

...

3) Elm seems to allow definition of anonymous (lambda) functions?

==&gt; It seems an anonymous function is just a function with the name ”\\” (resembling greek lambda ”λ")?

Elm&gt; \\n -&gt; n / 2

&lt;function&gt; : Float -&gt; Float

==&gt; Thus would resemble Meta Lisp syntax:

meta-0&gt; ((function number number) n (/ n 2))

(function number number) n (/ n 2))

…Or what should the display format be?

==&gt; In Meta List we could then define and apply an anonymous function:

meta-0&gt; (((function number number) n (/ n 2)) 4)

2

==&gt; ”function” is a named Function&lt;1&gt; value (defined Identifier)

==&gt; (function number number) applies identifier&lt;1&gt; ”function” to identifier&lt;1&gt; ”number” and ”number” (in effect creating a Function&lt;0&gt; value)

==&gt; Note: there is no ”define” statement

==&gt; But we do not need one as we apply the Function&lt;0&gt; value as_function directly

==&gt; (Function&lt;0&gt; n (/ n 2)) would now

==&gt; Consider Meta Lisp lambda function implementation?

meta-0&gt; **(declare Update (function Msg Model Model)) **// Identifier&lt;0&gt; ”Update” declared (bound to) Function&lt;1&gt; value created by Function&lt;2&gt; applied to Identifier&lt;1&gt; Msg, Model, Model

meta-0&gt;**(Update msg model (…function body …))** // Identifier ”Update” is undefined so as_function on ”Update” will bind it to constructed Function&lt;0&gt; value

meta-0&gt;**(Update a_msg current_model)** // Identifier ”Update” is now defined, so

3) Elm seems to apply some form of type inference in cases where to declaration (type annotation) is provided?

> ”So far we have just let Elm figure out the types, but it also lets you write a type annotation on the line above a definition if you want"

...

…

Consider to elaborate on ways to implement Function&lt;n&gt; meta-levels declare and define and meta-0 additions Function&lt;0&gt; call to get a consistent design with all other meta-value operations?

...

{% endraw %}
