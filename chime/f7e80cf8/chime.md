# Todo: Programming - Consider with Immutable Values are basically fine being anonymous (no name required for later reference)?

```#f7e80cf8``` *As of 2017-02-20 13:09*

[mail plain/text](mail.txt)

{% raw %}
Consider that in code using functional composition and immutable values we rarely need to name the values we construct?

1) Consider the reason variables needs names is because we must be able to refer to them to be able to mutate them?

…

2) Consider immutable values should normally be named only as input arguments to functions?

==&gt; Consider this means in function composition the output of one function goes directly to the input of the next (no intermediate required)?

==&gt; Consider naming of arguments is more about the type than about the value?

==&gt; Consider declarative code can use value names that refer to type (state the source type of the function input)?

fopen(const Path path); // The argument path is sufficient and is more about the type than about what file we actually are opening?

==&gt; Consider to compare with imperative code where values must refer to value meaning (must state what the value is) ?

Path log_file_path(”myLogFile.log”); // We need to state we mean a log file

Handle log_file = fopen(log_file_path);

…

…

Consider to elaborate on this idea that in functional programming with immutable values we declare **how** stuff is done while in imperative code using mutable values we declare **what** we do?

...

{% endraw %}
