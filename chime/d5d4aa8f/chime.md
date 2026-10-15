# Todo: Meta Value Model - Consider to enable function definition and execution using the Value Meta Model lisp scripting language?

```#d5d4aa8f``` *As of 2017-06-09 16:35*

[mail plain/text](mail.txt)

{% raw %}
It seems, now when we are defining a scripting language to operate on the mode, that we may use this to also execute model function definitions having the definition being such a script?

1) Consider this would be a Sand-boxed execution environment (scripts may only operate on the model)?

==&gt; But we may use such scripts to define encoding and decoding of protocol elements defining structure meta-data (e.g., bitfields)?

==&gt; It would resemble SQL ability to have code in the queries?

…

2) Consider how we could implement script containing function definitions?

(declare f (function number text)) // f is a function that takes a number and returns a text  
(define f (declare i number) (…lisp code…)) // f defined to take parameter named ”i” and execute code (…lisp code…)

==&gt; And applying the function would then execute the lisp-code?

(f 3)

==&gt; evaluate(list)  
==&gt; evaluate(”f”, ”3”)  
==&gt; apply(f,3) // Identifier f as_function applied to 3 as_value

==&gt; the argument name ”i” is bound (defined) as 3 and the the lisp-code is executed (lisp code identifiers bound in the namespace of the call)?  
==&gt; NO - Consider all functions are pure (only use input argument and return result?  
…

3) Consider all functions are pure (use only argument and return result)?

==&gt; In this way we do not have to solve the problem of binding identifiers in list-script at run-time (no side-effects)?  
==&gt; Then we only need to bind the arguments when function is called?

==&gt; Single-argument and single return still allows multiple in/out by using composed values (e.g., array, record…)  
…

…

Consider to elaborate on this idea to re-use the lisp-scripting language we define for REPL test of the model to also be used to define model functions (allowing the Model to be able to execute ”itself” or by client)?  
...

{% endraw %}
