# Todo: Meta Value Model - Consider all values (and the whole mode) is immutable (all mutations create new instance)?

```#b098e8f6``` *As of 2017-06-10 13:21*

[mail plain/text](mail.txt)

{% raw %}
Consider we want the Meta Value Model to be immutable so that each mutation returns a new instance?

1) Consider Immutable model and values is required by Darwinet MIV (A Darwinet MIV mutation creates a new state)?

==&gt; As Darwinet synchronize the MIV state between nodes each state must be immutable (state is unique)

…

2) Consider having Meta Value Model being immutable makes it easier to implement a scripting language?

==&gt; The scripting language does not have to deal with mutations?

==&gt; Each functions is pure (no side effects) returns a new Value?

…

3) Consider how the Immutability affects the Lisp scripting language to operate on the model?

==&gt; ”Ordinary" Lisp has a mutable environment (definitions are added to current environment)?

==&gt; ”Ordinary” Lisp does not have the concept of ”Declaration” (values are defined directly with value)?

==&gt; Thus - our "Meta Value Lisp” must require the environment to be mutated (so that each environment mutation returns a new environment)?

(append **environment** (declare count number)) // Will return a new environment with the declaration appended?

==&gt; But then - Who owns the environment?

==&gt; And - Who observes the environment state change?

==&gt; Consider environment is just an array value like any other?

==&gt; And it is the Meta Value Model client that owns the model (i.e., the root environment)?

==&gt; This, it is the client that mutates the model?

(append miv (declare count number)) // returns a new miv with declaration appended?

==&gt; But then - How are names resolved (in what namespace are they looked up)?

**WE ARE HERE...**

…

Consider to elaborate on this idea to make Meta Value Model immutable?

...

{% endraw %}
