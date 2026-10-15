# Todo: Tha functions - Consider to represent both functional and imperative functions Tha needs an algebra for statements and expressions?

```#2344b76a``` *As of 2017-08-13 18:29*

[mail plain/text](mail.txt)

{% raw %}
Can we say that to be able to represent and execute “functions” (both imperative and functional) we need Tha to define an algebra for statements and expressions?

1) Consider to define for Tha the semantics for Statements versus Expressions?

==&gt; Consider to apply the “common” notion as defined in this wikipedia page (<https://en.wikipedia.org/wiki/Statement_(computer_science)> )?

> “*In most languages, statements contrast with expressions in that statements do not return results and are executed solely for their side effects, while expressions always return a result and often do not have side effects at all*"

2) Consider a function has a body that is a list of statements (to be able to apply imperative semantic grammars for functions)?

==&gt; Consider C++ statements (<http://en.cppreference.com/w/cpp/language/statements>)?

> C++ includes the following types of statements:  
> 1) **expression** statements;  
> 2) **compound** statements;  
> 3) **selection** statements;  
> 4) **iteration** statements;  
> 5) **jump** statements;  
> 6) **declaration** statements;  
> 7) try blocks;  
> 8) atomic and synchronized blocks (TM TS).

3) Consider how statements seem to compose very much in the same way as data structures do?

==&gt; Iteration is the same statement instantiated for indexed environments (as array of same type instantiated for indexed values)?

==&gt; The iteration can be seen as the sequence of statements of the “same type” but executed in a sequence of environments (each with different member values)

==&gt; So, the statement “type” is the “environment type” and the “statement value” is the statement bound to current environment value?

Iteration : vector&lt;Statement&gt; -&gt; Type

Iteration statement = for (auto s : statements) result = execute(s); // result may be void_t

==&gt; With lazy evaluation we can model the array using a single mutable environment that the statement mutates?

Hm… How do I model this in C++ implementation of Tha (must be runtime mutable statements)?

I need to implement run-time dispatch on statement execution?

...

==&gt; Compound statement is a sequence of different statements (as a tuple of different types)?

==&gt; The compound statement can be seen as a sequence of statements of different types each executed in its own environment (the value of the statement)?

Compound: tuple&lt;Statement1, Statement2, …&gt; -&gt; Type

Compound statement = for_each_in_tuple(&#91;result&#93;(auto s) {result = execute(s)}); return result; // result may be void_t

Hm… How do I model this in C++ implementation of Tha (must be runtime mutable statements)?

I need to implement run-time dispatch on statement execution?

...

==&gt; Selection statement is a a statement composition where only the selected statement is executed (as in a sum-type)?

Compound: variant&lt;Statement1, Statement2, …&gt; -&gt; Type

Compound statement = visit(execute(result), statement); return result; // result may be void_t

Hm… How do I model this in C++ implementation of Tha (must be runtime mutable statements)?

I need to implement run-time dispatch on statement execution?

...

4) Consider Tha should be able to execute statements in a provided environment?

==&gt; It seems we can implement this as Lisp evaluate (only we also allow imperative statement to operate on the environment)?

==&gt; It seems Lisp actually defines statements (like the let statement, if statement, macro statement, etc)?

5) Consider statements are required to mutate the environment?

==&gt; It seems expressions only evaluates to values while to bind values to name we need statement that does this?

==&gt; Consider Clojure “operations” are in fact statements (<https://clojuredocs.org/quickref>)?

==&gt; It seems FlowControl are Clojure statements and Operation is a “function” FlowControl -&gt; Boolean | Normal | Exceptional | Delay | …

...

==&gt; Compare lisp/haskell let (

==&gt; Also see Haskel “Actions” that compose lazily with as IOMonads (<https://en.wikibooks.org/wiki/Haskell/Simple_input_and_output#Controlling_actions>)

> ```
> doGuessing num = do
>    putStrLn "Enter your guess:"
>    guess <- getLine
>    if (read guess) < num
>      then do putStrLn "Too low!"
>              doGuessing num
>      else if (read guess) > num
>             then do putStrLn "Too high!"
>                     doGuessing num
>             else putStrLn "You Win!"
> ```

  
==&gt; It seems getLine : IO String which must be executed to return a value.

==&gt; And the “&lt;-“ syntax is such an execution in a do-seqeunce?

==&gt; Do seems to be a statement that sequence actions?

==&gt; And all actions are IO types (lazy execution)?

==&gt; Thus, the first do sequence {putStrLn, guess, if}

==&gt; The second do sequence {putStrLn, doGuessing} and so on.

==&gt; The if is a special expression (it evaluates any of its two member then or else expressions)?

…

==&gt; It seems Clojure “do” is very much like Haskel do /<https://www.braveclojure.com/do-things/>)?

“*The do operator lets you wrap up multiple forms in parentheses and run each of them*"

==&gt; But in Clojure ALL forms return a value?

> ```
> (if true
>   (do (println "Success!")
>       "By Zeus's hammer!")
>   (do (println "Failure!")
>       "By Aquaman's trident!"))
> ; => Success!
> ; => "By Zeus's hammer!"
> ```



==&gt; The “do” makes println execute but the if-form still returns the last value of the do?

…

…

Consider to delve on this idea to enable Tha to compose functions with statements that may or may not be expressions?

...

{% endraw %}
