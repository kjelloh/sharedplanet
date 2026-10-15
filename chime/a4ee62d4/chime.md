# Todo: Darwinet - Consider to view Node processing as Concurrent Programming on SEPSI:s?

```#a4ee62d4``` *As of 2016-01-13 00:44*

[mail plain/text](mail.txt)

{% raw %}
Would it perhaps be a good idea to view a Darwinet Domain as being made up of concurrent nodes sharing data without blocking (data states as synchronized as a separate future operation)?

Note: we use SEPSI to mean (Shared Evolving Privately Stored Information), i.e. data in MIV.

1) Consider to watch this talk by Bartosz Miewski about C++ ”futures” from a concurrency functional programming point of view and relate to Darwinet problem domain (https://en.wikipedia.org/wiki/Monad_(category_theory) )?

2) At around 22m into the talk he explains blocking thread-to-thread ”channel” made of std::promise (client-&gt;server) and std::future (server-&gt;client)

==&gt; This is NOT the Darwinet way. Each node apply change to its local MIV (SEPSI) and distributes a delta about the change  
==&gt; Other nodes receives the Delta and now has the same state.  
==&gt; Conflicting Deltas (concurrent operation to the same state) means local states branches (or delta is commutative and may be applied without conflict).  
==&gt; Branched states may be auto-merged (e.g. deciding one state takes precedence over the other, in effect reversing the effect of the conflicting delta)

3) What about Darwinet Functors. They must be synchronized?

==&gt; A node sending a Functor (as a Closure?) to another node must know when to synchronize with the result?  
==&gt; We should thus consider the Promise, Future design pattern for distributed Functors?  
==&gt; One node decides (is triggered and allowed to) to execute a Functor (Closure)  
==&gt; It instantiates it as defined by the Model and binds it to input data and output Future.  
==&gt; The node executes the Functor and updates the Future.  
==&gt; Setting the result of the Future may result in a new Functor (a Next) to be created.  
==&gt; A Grid-computing mechanism of Darwinet may now allow another node to execute the new Functor.  
==&gt; By having all Data, Functors and Futures living in the MIV the grid-computing synchronization may be based on MIV delta synchronization?  
==&gt; Consider to base the Grid-computing on negotiated sub-domaining and branch/merge of computational results?  
==&gt; The Grid-computing mechanism should allow nodes to race for delivery and discard concurrent results of the same operation?  
==&gt; The mechanism should be able to use strict node scheduling for reliable network nodes (no or low risk of assigned node not delivering)?

4) Also consider to study Grid-comuting algorithms to see how we may implement them based on MIV-living delta-synchronized Functors and their Promise/Future pairs?

…

…

Consider to delve deeper into design patterns of concurrent programming and grid computing algorithms?  
...

{% endraw %}
