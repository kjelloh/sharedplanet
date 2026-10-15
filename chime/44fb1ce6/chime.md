# Todo: Meta Value Model - Condor to define how to bind the Repl to the environment that gets mutated (i.e., where values and identifiers gets stored on creation)?

```#44fb1ce6``` *As of 2017-06-13 15:43*

[mail plain/text](mail.txt)

{% raw %}
It seems we need some elegant and concise way to ”know” where identifiers and values created by the Repl evaluator gets stored?

1) Consider how to mutate identifier and value presence in the actual Meta Value Model?

==&gt; Consider that in our Meta Value Model values are all there is?

==&gt; Thus values, meta-values and Identifiers are all values (and there is nothing else in there)?  
==&gt; Thus the problem is to define where defined values gets stored?

==&gt; Consider the Repl keeps track of ”current environment” (e.g., by default the Model tree root)?

&gt;(declaration count meta.number) // would store created Identifier

…

2) Consider we need this mechanism also for execution of modelled functions (functions in the model)?

==&gt; Functions in the model must execute in some environment to have access to values and be able to mutate values in the model)?

==&gt; Consider how modelled functions shall execute in environments they mutate (new state)?

==&gt; Consider to study how Lisp and Scheme does this (they have a mutable environment)?  
==&gt; Consider how Clojure and Elm does this (they do not mutate their own environment)?

==&gt; Consider how modelled functions shall return mutated version of the model they mutate?

…

==&gt; Consider mutation of the environment is not a problem for the mutating function?

==&gt; The function will operate on its own immutable values (so it will be able to access the mutated state through its local instances)?  
==&gt; And new model instances is created as side-effects?  
..

…

Consider to find a good design for this in our Repl (possibly applying a scheme from some of the existing language Repls like Lisp, Clojure or Elm)?  
...

{% endraw %}
