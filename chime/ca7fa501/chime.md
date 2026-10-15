# Todo: Tha - Consider to really understand how persistent data structures behave (how to instantiate, assign, pass around)?

```#ca7fa501``` *As of 2017-07-04 09:14*

[mail plain/text](mail.txt)

{% raw %}
I realize I have not really got a grip on what API the existing C++ persistent Data structures provide (e.g., do they provide value semantics)?

1) Consider to understand the immer C++ persistent data structures through the Ewig editor example (<https://github.com/arximboldi/ewig>)

==&gt; Also see ”Todo: Tha, Elm and Immer - Consider the C++ Immer immutable data structures based text editor "ewig" is in fact implementing the Elm model, view, update?”

2) So, how do we initiate the first instance of a C++ Persistent Data Structure?

==&gt; It seems Immutable-Cpp provides a static empty() factory method (<https://github.com/rsms/immutable-cpp>)?

> auto a = Array&lt;int&gt;::empty();

==&gt;

3) Consider to understand if and how a C++ Persistent Data Structure instance supports value semantics?

==&gt; Can we assign an existing persistent data structure ”variable” with a new ”instance” (i.e., does the object act as a smart reference)?

==&gt; It seems Immutable-Cpp provides value semantcs once variable is instantiated (<https://github.com/rsms/immutable-cpp>)?

> auto a = Array&lt;int&gt;::empty();  
> a = a-&gt;push(1);  
> a = a-&gt;push(2);  
> a = a-&gt;push(3);

==&gt;

4) Consider to understand how we can compose with persistent data structures (e.g., have Tha values be and aggregate persistent data structures)?

==&gt; It seems immutable-cpp actually provides a ref&lt;Array&gt; instance to provide value semantics?

> ref&lt;Array&gt; Array::empty();

==&gt; Thus we may aggregate ref&lt;Array&gt; members (not try to aggregate the Array&lt;T&gt; itself?

…

Consider to study and try out C++ persistent data structures more to understand what goes behind the scenes and how to best use them in combination with non persistent data?

...

{% endraw %}
