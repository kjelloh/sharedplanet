# Todo: Darwinet - Synchronised self-organising of grid-computing networks

```#238bb1f8``` *As of 2015-12-10 14:23*

[mail plain/text](mail.txt)

{% raw %}
For Darwinet to be used for grid-computing it needs a synchronised mechanism to dedicate nodes to do designated sub-tasks (decide who does what)

1) As opposed to data distribution that tries to meet redundancy and access requirements, grid computing needs to reduce radiancy whilst still optimise computing speed.

==&gt; P2P Data synchronisation is to ensure that nodes that need data may acquire it as efficient and securely as possible  
==&gt; P2P grid computing is to distribute parallell computing to nodes so that the answer may be acquired in shortest time.  
==&gt; Grid computing may implement some level of radiancy to allow node drop-out without breaking the algorithm (other nodes perform the work of the dropped out nodes)

2) So, how can we imagine a task to be distributed for grid computing in a Darwinet P2P network?

a) Somewhere the task must originate. An actor (user or application) needs some computing to be performed.  
b) The taks must be broken down into sub-tasks that may be computed independent of other tasks.  
c) The initiating Node now needs to query for nodes to perform the sub-functors (keeping some for local computation).  
d) The functor-computation-distribution should implement some redundancy (assign two or more nodes to compute, or apply time-out-monitoring to re-quesry for new node if assigned node does not return a value within time)?  
e) Assigning functors to node for computation must involve hand-shaking so that Node that takes on the tasks is approved and acknowledged by the assigning node?  
f) Seems we may use node-restricted delta distribution to forward functors to computing node but not for handshaking of actual task-assignment?  
==&gt; Storing functors as MIV object allows it to be synchronised to other nodes.  
==&gt; Having distribution-restrictor on the Functor allows it to be synchronised to computing candidates only.  
==&gt; A MIV stored boolean could be used for signalling if we have it in a MIV of a sub-domain with only functor computing candidate nodes?

==&gt; Consider to have functor objects live in sub-domains of computation?

3) Imagine tasks to be distributed as functors with parameters bound to data in the MIV?

==&gt; The original taks is a root functor that defines what to do.  
==&gt; The functor is a closure that defines what data to use as input and what data to modify as a result.  
==&gt; Consider to have the Functor being a MIV with a state just as any other data (to enable self-synchronisation between functors that generates deltas to data used as input by other functors).  
==&gt; A “future” may then be defined as a functor applicable after another functor?  
==&gt; Thus we can imagine each Functor to return a Future in the form of a new functor (and this is the way to break down computing in sequential steps defined by MIV state sequences)?  
==&gt; MIV-stored functors must synchronise differently form other MIVs in that they need to be distributed only to nodes that are to execute them?

4) Consider each functor to live in a designated sub-domain using MIV synchronisation as hand-shake of task assignment and completion?

a) A functor is created by an actor (user or application) at the initiating node.  
b) Node creates a sub-domain for functor computation.  
c) Node invites a set of nodes to join the computation domain.  
d) Node accepts one or more nodes to compute the functor (more if redundancy is wanted to cover for node drop-out or computation-time-race)  
e) Initiating node stores the functor in the computation domain  
==&gt; How does the initiating node exclude itself from reacting to the stored functor and compute it locally?  
f) The computation-domain members triggers on the Functor modification (creation) in the domain and starts executing it.  
g) Computation ends by storing the Future (the resulting functor)  
h) The initiating node detects the storage of the Future and decides how to continue)  
==&gt; Should the initiating node kill of the computation domain here?

…

Elaborate on this idea of functors as MIV objects creating Futures as functors to transform existing MIV synchronisation for grid-computing in Darwinet networks?

{% endraw %}
