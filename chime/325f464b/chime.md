# Todo: Programming - Consider to argue that Generators reflect structure in code whilst Iterators reflect structure in state?

```#325f464b``` *As of 2016-07-14 20:27*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to stress the point that Generators reflect structure in code whilst Iterators reflect structure in state?

1) Consider a generator uses language control statements (for, while, if) to process a structure?

==&gt; Consider this also means Generators are stack-full (structure mat be reflected on iteration and function calls reflecting the structure)?  
…

2) Consider an Iterator has to store a “where are here” state to be able to pick up next element in the structure?

==&gt; Consider the Iterator is able to live both at the heap and on the stack but can’t reflect “we are here” using execution location?  
…

…

Consider to elaborate on this idea to see if it holds water and what we can learn from applying this way of thinking for data structure parsing?  
...

{% endraw %}
