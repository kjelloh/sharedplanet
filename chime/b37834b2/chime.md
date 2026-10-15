# Todo: Darwinet - Consider to apply Reactive Functional Programming to synchronize between Darwinet Nodes as well as interfacing local clients (through views)?

```#b37834b2``` *As of 2017-01-31 19:28*

[mail plain/text](mail.txt)

{% raw %}
It seems we should aim at applying all the good stuff we gain from applying the Functional Reactive Pattern for the Darwinet System Design?

1) Consider the talk ”Functional reactive programming in C++ - Ivan Cukic - Meeting C++ 2016” to be a good overview into C++ Functional Reactive Programming (<https://www.youtube.com/watch?v=a2MmURgc6cU>)?

==&gt; At 42:15 Ivan Cukic lists some references to Reactive C++ libraries - Consider to follow up on these references?

==&gt; The ”SObjectizer” library seems to live at sourceforge ([https://sourceforge.net/p/sobjectizer/wiki/About%20SObjectizer/](<https://sourceforge.net/p/sobjectizer/wiki/About SObjectizer/>))?

==&gt; It seems to provide tools to write Erlang Process/Go-routine like applications?

> > ”*Since v.5.5.13 SObjectizer also supports CSP-like concurrency via message chains. Message chains were added to SObjectizer for simplification of interaction between agents and user threads. But they can be used also to write multithreaded C++ application in very similar way as Go applications with goroutines and channels.*"

==&gt; The ”C++ Actor Framework” seems to live here (<https://github.com/actor-framework/actor-framework>)?

==&gt; It also seems to have a community web-page here (<http://actor-framework.org>)?

==&gt; He also refers to ZeroMQ that seems to live here (<http://zeromq.org>)?

==&gt; But ZeroMQ is a messaging protocol, not a Reactive Consumer library?

==&gt; ZeroMQ seems to be C++ core and then have a large set of bindings to other languages (<http://zeromq.org/community>)?

==&gt; This seems to be the Github home for ”Reactive Extensions, An API for asynchronous programming with observable streams” (<https://github.com/Reactive-Extensions>)

==&gt; And this seem to be RxCpp, the C++ library for Reactive Extensions (<https://github.com/Reactive-Extensions/RxCpp>)?

2) Consider ways a Darwinet Network may or should apply the Functional Reactive Pattern?

==&gt; Consider each MIV View is a consumer of Delta Operations (Reacts to Deltas)

==&gt; Consider each Client consumes mutated MIVs (as defined by the view) and may then react to partially new state?

…

…

Consider to try out some C++ Reactive Programming libraries to implement some design of Darwinet Nodes, views and MIVs?

...

{% endraw %}
