# Todo: Meta Value Model - Consider to document the current "Meta Lisp" REPL as it is being developed and tried out?

```#d3622ee1``` *As of 2017-06-13 15:33*

[mail plain/text](mail.txt)

{% raw %}
Consider it would be a good idea to keep an updated documentation on the Meta Lisp language while it is being manifested as in the Meta Value Model Repl?

==&gt; Also see ”[Todo: Meta Value Model - Consider to compare our "Meta Lisp Repl" with other language Repl available online?](../c507033a/chime.md)"

1) Consider to differentiate between the evaluation rule of the Meta Value Model and the added rules of the Repl?

==&gt; Consider in this way we can bind a scripting language to the language indifferent model operations?

==&gt; Consider the Repl adds things like a ”cursor”, i.e. the current environment (reference to value in the model)

2) Consider the Meta Value Model evaluation rules?

==&gt; The model is made up of values that are Identifier, meta value or defacto value?

Value := MetaValue | DeFactoValue | Identifier

Identifier := Name & MetaValue & OptionalValue

Name = text

MetaValue := Value

OptionalValue := Value | NoValue

==&gt; All values has a fixed set of member operators that all return a value

as_value

as_function - return Value from applying ourself as function to provided argument values

text as_text // Mixed-in by script evaluator (knows how to print values)

==&gt; All values define a Set {… defacto values …}

==&gt; All values as_function act as constructor of specified defacto value from its defacto set?

...

**==&gt; Consider we would like modeled functions be be generic (apply dynamic dispatching on application)?**

==&gt; It seems from studying CLOS that we would like to have functions be generic (dispatch to appropriate definition based on argument types in the call)?

**WE ARE HERE...**

3) Consider the Meta Lisp evaluation rules?

==&gt; Consider An expression is a single identifier or a list of identifiers?

1 // single identifier ”1”

+ 1 1 // a list of identifiers ”+” ”1” ”1”

(+ 1 1) // and expression of as_function ”+” applied to as_value ”1” as_value ”1”

==&gt; Consider to use the term ”identifier” instead of lisp term ”symbol”?

4) Consider the all-things-meta-value approach to Meat Lisp evaluation?

==&gt; Consider all text is evaluated as Expression

&gt;(+ 1 1)

evaluate(expression(”(+ 1 1)”)

evaluate(list_expression(”+ 1 1”)

evaluate(as_function(”+”), as_values(”1 1”))

as_text(as_function(model&#91;”+”&#93;, as_values(as_value(”1”), as_value(”1))) //

…

==&gt; Consider an Identifier value as_function differs whether it is defined or not (bound to a value)?

as_function = (undefined? (as_function meta) (as_function value))

==&gt; That is, if undefined the identifier acts a value-constructor of itself

==&gt; otherwise it forwards to as_function of its bound value.

==&gt; Q: How do we make the undefined identifier be bound to itself (created value stored in the identifier environment)?

5) Consider to define the REPL as (loop (print (eval (read))))?

==&gt; Consider read to return input text from console (user input)?

==&gt; Consider eval to evaluate a text as script and return a value (everything is a value on some meta level)

==&gt; Consider print to produce a text of value (preferably in the syntax of the script language)?

==&gt; Consider loop repeats evaluation of expression)?

…

Consider to update this Meta List Repl documentation

{% endraw %}
