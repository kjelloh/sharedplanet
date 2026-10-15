# Todo: Consider a programming language defined to always operate on immutable data may provide a "rewind" operation to re-start computation at a previous state?

```#a84ad78c``` *As of 2019-01-31 13:39*

[mail plain/text](mail.txt)

{% raw %}
Could it be of value to imagine a programming language that always operates on immutable data to be able to execute programs that can “rewind” and re-start computation at a previous state again?

1) Consider the syntax and properties of a “rewind” operation; To what state should it go back and how do we signal that a specified rewind has happened so we don’t get an eternal loop?

==&gt; Consider a way to define an entry point in the code that receives a signal and a state (to be able dispatch the signal to determine how to execute on the provided state)?

==&gt; Consider we do NOT need a special operation or “rewind” keyword if we allow the language to reference its own data model in any previous state (and thus may recurse a function and provide any input signal and state to execute on)?

…

2) Consider with a “rewind” operation we can iterate several possible execution paths and in the end investigate if any of the different end-states are preferable (and thus optionally have a new mechanism to implement “search" algorithms)?

==&gt; Consider if a “rewind” operation paired with an iteration of different execution paths on the same data model start state - may in any way have advantages to ordinary mutable data function iteration?

==&gt; Consider for execution on externally received signals (data) it may prove easier to process such signals in the same state if we could utilise a “rewind” keyword?

==&gt; Consider with a “rewind” operation we can replace code guards with a “rewind” when we detect that we have executed down the wrong path (or on the wrong external signal)?

...

3) Consider how a “rewind” operation is exactly what a CPU must implement to perform speculative execution?

TODO: Research how CPU speculative execution works (and how we may use this knowledge as inspiration for a “rewind” keyword)?

…

4) Consider how a “rewind” operation is to a large degree what a fail Transaction operation must perform to undo its own effects if the transaction fails to complete?

TODO: Research transaction operations (e.g., the ones in transact tonal databases)?  
…

5) Consider how a C++ destructor to some parts is a “rewind” of its own existence and may be used to “undo” operations (RAII style)?

…

6) Consider how the Clojure programming language operates on immutable data (and if it provides ways to reference data in previous states)?

TODO: Study how Clojure operates on immutable data and if it provides some mechanisms to implement a “rewind” like operation (to restart execution in a previous state)?  
…

7) Consider how a “rewind” operation may be seen as a way to take advantage of the fact that immutable data preserves its Entropy (thus allowing time travel backwards)?

==&gt; Consider in the “real world” we are unable to go back in time because that would require a decrease in entropy (and only events that increase entropy are allowed to actually happen)?

==&gt; Consider that maybe this is not actually so insightful as even in “reality” we allow local entry decrease as long as the total entropy in the universe increase?

…

{% endraw %}
