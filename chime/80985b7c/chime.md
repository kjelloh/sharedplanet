# Todo: Darwinet - Consider top follow up on "JuliaCon 2016 \| A functional approach to High Performance Computing \| Erik Schnetter" and his proposal FunHPC library both in C++ and Julia?

```#80985b7c``` *As of 2017-02-23 19:29*

[mail plain/text](mail.txt)

{% raw %}
I stumbled on a talk

1) The talk ”JuliaCon 2016 | A functional approach to High Performance Computing | Erik Schnetter” that inspired me seems tro live here (https://www.youtube.com/watch?v=h4VpT0YcnH8)?

==&gt; He seems to make the point that in distributed systems Garbage Collection is actually much faster than Reference Counting?

==&gt; But then he must mean a special kind of Garbage Collection that is not reference counted What does he mean)?  
==&gt; OR, He actually means Replication versus Reference Counting (as in its actually faster to create and use copied data than to lock on atomic reference count updates)?  
==&gt; If so, then he is advocating the same thing I am thinking of that due to reference count synchronization overhead between shared counts in L1. L3, L3 and Main memory we may actually gain from operating on copied but unshared data)?

==&gt; It would seem we gain if the total overhead of having to lock and update shared memory reference counts distributed on L1, L2, L3 and memory storage is higher than simply clone once and then operate on the data totally asynchronously)?  
...

==&gt; Consider to understand if C++ RAII somehow still is applicable as an efficient alternative to Reference Counting?

==&gt; He seems to argue for an approach where object lifetimes are always viewed as two phases mutable unshared (one thread private) construction followed by thread shared immutable interaction?

==&gt; This seems to correspond to the Builder Pattern (Curried Constructor using mutable Builder) and Clojure Transient Objects?

==&gt; He states he has developed a Prototype ”FunHPC” (Functional High Performance Computing) library both in C++ and Julia?

==&gt; He seems to state that the ”name of the game” is to Hide the Latency as in structuring the computations so that locks due to data transport latency (i.e., Cache or serial messaging) can be filled with unlocked processing (operations where data is already available)?

==&gt; This seems to correspond to my idea of being able to compose subroutines, coroutines and goroutines seamlessly and then have the ”bind” take care of parallelization so that the messaging asynchronous latency is ”hidden” behind asynchronous processing?  
…

==&gt; He seems to advocate that for efficient parallel computing we should NOT try to reuse or save memory, we should not try to tune execution order (which kind of advocates that the Darwinet Approach is the right one)?

==&gt; The Don’t-tune-execution-order seems to come from teh fact that the optimum is totally-parallel (which rimes with Darwinet optimistic do-now-merge-if-required approach)?  
==&gt; The Don’t-save-memory seems to come from the fact that distributed processing scales memory per parallel node (which rimes with Darwinet Approach having data replicated on each Node of execution)?  
...

2) Consider to delve into his Github Project ”FunHPC: Functional HPC Programming” for C++ (https://github.com/eschnett/FunHPC.cxx)?

…

…

Consider to follow up on the works of Erik Schnetter and his library FunHPC in C++ an Julia to see how it relates to the design of Darwinet?

{% endraw %}
