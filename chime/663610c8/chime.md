# Todo: Programming - Consider an object may memoize calls to it (mutate internal state) as long as the mutation is not visible from the outside?

```#663610c8``` *As of 2017-02-07 18:41*

[mail plain/text](mail.txt)

{% raw %}
It seems we may implement immutable objects with function members that memoize return results as long as the mutation is not visible from the outside (each member function still returns the same result whether it actually does the processing or returns a previously calculated result)?

1) Consider this confirming example by Milewski (<https://bartoszmilewski.com/2014/04/21/getting-lazy-with-c/>)

==&gt; Although he goes a bit further and implements memoization as mutating the internal function actually called (Exactly what I implemented as experiment for JIT getters :) )

> ”*Initially, the thunk is set to thunkForce, which calls the method setMemo. This method evaluates the function, stores the result in _memo, switches the thunk to thunkGet, and returns the memoized value. On subsequent calls get goes through the getMemo thunk which simply returns the memoized value.*"

2) It seems we may make a mutable object wrap an observed immutable one to explicitly express where we cross from immutable-land into the mutable one?

==&gt; Consider a class Observer&lt;Persistent&gt;?

Persistent my_persistent; // Some Persistent Data Structure

Observer&lt;Persistent&gt; observed_persistent_data(my_persistent); // An observer of my_persistent object

auto current = observed_persistent_data.get(); // Returns an immutable copy of the latest state?

template&lt;typename T&gt;

class Observer {

Latest&lt;T&gt; get() {

*// 1) Apply some mechanism to retrieve the most recent instance of T (T being a Persistent Data Structure Object)?*

*// 2) Return an instance of type Latest&lt;T&gt; that does somehow gets rid of older parts not referenced anymore (deleted part of the structure)?*

}

};

==&gt; Consider we aim for an object that mutates (we can keep only one instance to query over and over)

==&gt; But we like the get() function to return the last instance of the chain of immutable object instance we observe?

…

…

Consider to elaborate on this aspect of immutability and how to express where we cross over to mutable land in the code?

...

{% endraw %}
