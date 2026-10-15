# Todo: Meta Value Model - Consider to define built-in value compositions using syntax Value&lt;level 2,1,0&gt; and members as_function, as_value, as_text?

```#5830e388``` *As of 2017-06-11 17:32*

[mail plain/text](mail.txt)

{% raw %}
It seems like a good idea to use a C++ template syntax Value&lt;n&gt; for level dependent Value types and have standard member functions as_function, as_value and as_text to define implementation?

1) It seems most Values can be defined by specifying them on three relative meta layers 2, 1 and 0?

==&gt; Consider Value&lt;2&gt; would refer to an **Atomic** value that constructs Value&lt;1&gt; instances from Value&lt;1&gt; argument?

==&gt; Consider Value&lt;1&gt; would refer to an **intermediate** Composite (or Atomic) that constructs Value&lt;0&gt; from Value&lt;0&gt; argument?

==&gt; Consider Value&lt;0&gt; would refer to a Composite (or Atomic) on **terminating** meta-layer?

2) Consider each Value **Implementation** has member operations as_function, as_value and as_text?

==&gt; Consider Value&lt;2&gt; would refer to an **Atomic** value that constructs Value&lt;1&gt; instances from Value&lt;1&gt; argument?

as_function = Constructs Value&lt;1&gt; from argument Value&lt;1&gt;

as_value = self

as_text = script representation of value

==&gt; Consider Value&lt;1&gt; would refer to an **intermediate** Composite (or Atomic) that constructs Value&lt;0&gt; from Value&lt;0&gt; argument?

as_function = Constructs Value&lt;1&gt; from argument Value&lt;0&gt;

as_value = self

as_text = script representation of value

==&gt; Consider Value&lt;0&gt; would refer to a Composite (or Atomic) on **terminating** meta-layer?

as_function = ErrorValue or forward to function definition (if function value)

as_value = self

as_text = script representation of value

3) Consider how this relates to Lisp syntax (name names) evaluates to (as_function(name) as_value(names)) and name evaluates to as_value(name)?

==&gt; Consider identifier-list evaluation?

evaluate(list) = evaluate(as_function(head list) as_value (tail list))?

==&gt; Consider identifier evaluation

evaluate(identifier) = as_value(identifier)

==&gt; Consider as_text is used to produce text representation to communicate with humans?

==&gt; Consider REPL print?

evaluate(expression) ==&gt; as_text(evaluate(expression))?

==&gt; Consider creating message for ErrorValue?

==&gt; Error message can compose into a stack-dump using as_text on argument and return ErrorValue(error message)?

evaluate(expression) ==&gt; as_text(evaluate(expression)) would then print a stack-dump if returned value is ErrorValue?

...

3) It seems we thus have a really small set of built-in value abstractions?

==&gt; We have ErrorValue (Composes an error message)

ErrorValue

as_function = self // Pass the error back

as_value = self

as_text = error message

==&gt; We have UndefinedValue (A special value which represents ”no value”)

UndefinedValue&lt;2&gt;

as_function = constructor of UndefinedValue&lt;1&gt;

as_value = self

UndefinedValue&lt;1&gt;

as_function = constructor of UndefinedValue&lt;0&gt;

as_value = self

UndefinedValue&lt;0&gt;

as_function = ErrorValue(”Undefined Value")

as_value = self

==&gt; We have Atomic values (No members)

Atomic&lt;2&gt;

as_function = constructor of Atomic&lt;1&gt;

==&gt; We have Bool value (Defines the Set {”true", ”false”}

Bool&lt;1&gt; = number with Set {1,0} // Restricted number

”bool” = Bool&lt;1&gt;

as_function = constructor of Bool&lt;0&gt;

Bool&lt;0&gt;

”true” = number{1}

”false” = number{0}

==&gt; We have Optional value (A Variant Value or UndefinedValue, to enable ISO-8583-like composition of Composite versus Constructed values)

&lt;2&gt; TBD

&lt;1&gt; TBD

&lt;0&gt; TBD

==&gt; We have Conditional value (A Predicated value, to enable ISO-8583-like composition of Composite versus Constructed values)

&lt;2&gt; TBD

&lt;1&gt; TBD

Conditional&lt;0&gt;

as_function = bool predicate(arguments)?

==&gt; We have Pair of values (Compose two values)

&lt;2&gt; TBD

&lt;1&gt; TBD

&lt;0&gt; TBD

==&gt; We have Array of values (Compose array of values)

&lt;2&gt; TBD

&lt;1&gt; TBD

&lt;0&gt; TBD

==&gt; We have Variant value (compose an OR ”one-of” value)

&lt;2&gt; TBD

&lt;1&gt; TBD

&lt;0&gt; TBD

==&gt; We have a Function value (Compose argument value and return value)

Function&lt;2&gt;

as_function = Construct Function&lt;1&gt;

Function&lt;1&gt;

as_function = Construct Function&lt;0&gt;

Function&lt;0&gt; (Compose argument name and script)

as_function = bind-argument and evaluate(script)

as_value = self

as_text = the script

==&gt; We have Identifier value (Compose a name, a meta-value and an optional value)

Identifier&lt;2&gt; (Atomic)

as_function = Construct Identifier&lt;1&gt;

Identifier&lt;1&gt; (Compose name and Value&lt;2&gt;)

as_function = Construct Identifier&lt;0&gt; from Value&lt;0&gt;

”identifier”

Identifier&lt;0&gt;

as_function = forward to as_function(value)

(identifier count number) // Would then declare name ”count” as Value&lt;1&gt; ”number”

(**define** count 5) // Would then define count to value 5 (Normal Lisp style)?

==&gt; We have Custom values (additional values manifested by Meta Value Model implementation)

Custom&lt;2&gt;

as_function = Constructor of Custom&lt;1&gt;

as_value = self

as_text = custom

Custom&lt;1&gt;

as_function = Constructor of Custom&lt;0&gt;

as_value = self

as_text = custom

Custom&lt;0&gt;

as_function = custom // E.g., a function or ErrorValue(”Undefined Value")

as_value = self

as_text = custom

…

…

Consider to elaborate on this syntax to specify built-in Value meta-level operations and syntax relation?

...

{% endraw %}
