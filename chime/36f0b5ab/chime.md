# Todo: Darwinet - It seems Darwinet Deltas are in fact the same thing as "Conflict-free replicated data type" or CFRD?

```#36f0b5ab``` *As of 2017-01-20 12:35*

[mail plain/text](mail.txt)

{% raw %}
Browing the web on interesting talks I stumbled on the concept of a "Conflict-free replicated data type" or CFRD and it seems this is strongly correlated with Darwinet MIV/SEPSI concepts?

1) Consider a Darwinet MIV/SEPSI is a kind of CFRD that is allowed to both evolve (change state) and ”mutate” (branch) to apply ”survival of the fittest” selection?

==&gt; Consider how this ”mutation” (branch) and ”survival of the fittest” (evolution) correlates to Conflict-free replicated data types (See below)?

...

2) Consider this wikipedia definition of ”Conflict-free replicated data type” (<https://en.wikipedia.org/wiki/Conflict-free_replicated_data_type>)

> ”*In distributed computing, a conflict-free replicated data type (abbreviated CRDT) is a type of specially-designed data structure used to achieve strong eventual consistency (SEC) and monotonicity (absence of rollbacks)&#91;1&#93; . As their name indicates, a CRDT instance is distributed into several replicas; each replica can be mutated promptly and concurrently; the potential divergence between replicas is however guaranteed to be eventually reconciled through downstream synchronisation (off the critical path);&#91;1&#93; consequently CRDTs are known to be highly available.*"

==&gt; It seems this means a Darwinet MIV (Model Instance Value) or SEPSI (Shared Evolving Privately Stored Information) are in fact instances of a CFRD (Conflict-free Replicated Datatype)

==&gt; ”*a CRDT instance is distributed into several replicas*” = Each MIV/SEPSI is replicated in the local Darwinet View.

==&gt; ”*each replica can be mutated promptly and concurrently*” = Each View updates its MIV/SEPSI locally (local concurrency of deltas)

...

> ”*Informally, eventual consistency means that replicas eventually reach the same value if clients stop submitting updates. Eventually consistent systems accept local updates without remote synchronization, improving performance and scalability by sacrificing strong consistency. Without remote synchronization, replicas concurrently hold different values which are expected to converge over time. Convergence is complicated by conflicts which arise when merging values between replicas. A conflict is a combination of concurrent updates which may be individually correct, but taken together violate some system invariant. Conventional conflict-resolution schemes involve state roll-back, full consensus, or even user interaction.*"

==&gt; This seems to cover all aspects of Darwinet MIV synchronisation by Delta Exchange?

==&gt; ”Eventual Consistency” = Each MIV will stabilize to the same state some time after all nodes has stopped producing Deltas.

==&gt; ”...accept local updates without remote synchronization” = Each MIV operates on local state (and only synchronize with remote state changes when they are received asynchronously with local state changes)

==&gt; ”*Convergence is complicated by conflicts which arise when merging values between replicas*” = Merging MIV Delta conflicts requires a merging scheeme.

==&gt; ”*Conventional conflict-resolution schemes involve state roll-back, full consensus, or even user interaction*” = We have discussed MIV merging concepts to involve ”undo” (rollback) of conflicts to reach consensus and user merge.

  
> ”*If the system is monotonically increasing in state, clients never observe state rolling back. The set of system states is partially ordered, and the merge operation being commutative, associative and idempotent, the set of all system states is a semilattice, and the merge operation is the semilattice join.*”

==&gt; This corresponds to my problem with Deltas NOT being commutative (causing branching on Delta conflicts)

==&gt; But it seems they state this is ok as long as the merge operation being commutative.

==&gt; And of course merge is commutative (we get the same merge result independent on the order of conflict resolution)

==&gt; At least, we can define a merge that behaves in this way.

> ”*Operation-based CRDTs are called commutative replicated data types, or CmRDTs. CmRDT replicas propagate state by broadcasting the state update operation itself, which must be commutative. For example, a CmRDT of a single integer might broadcast the operations (+10) or (−20). Replicas receive the updates and a*pply them locally. The operations are commutative, so can be received and applied in any order; however, they are not idempotent, and additional network protocol guarantees are required to ensure unique delivery."

==&gt; This seem to indicate Darwinet Deltas as in fact CmRTDs?

==&gt; But NO - We have Darwinet Deltas that does NOT commute (e.g., string mutations)?

> ” *gossip protocols work well for propagating CvRDT state to other replicas while reducing network use and handling topology changes.*"

==&gt; This seem to correspond to our idea of having Darwinet communicate using a friend-to-friends P2P protocol (i.e., Deltas spread in a gossiping manner)

> ”*A sequence (a.k.a. list, ordered set) CRDT can be used to build a Collaborative real-time editor, as an alternative to Operational transformation (OT).*

> *Some known Sequence CRDTs are Treedoc,&#91;10&#93; RGA,&#91;15&#93; Woot,&#91;9&#93; Logoot,&#91;16&#93; LSEQ.&#91;17&#93; CRATE&#91;18&#93; is a decentralized real-time editor built on top of LSEQ and runnable on a network of browsers thanks to WebRTC.*"

==&gt; It seems Dartwinet Delta sequences actually produce sequences of CRDT (MIV/SEPSI state instances)?

==&gt; Q: How does this allow for collaborative real-time editors (text editing deltas does NOT commute)?

==&gt; Consider to follow up on the references in this wikipedia article?

==&gt; Treedoc,&#91;10&#93; Seems to be published in this paper (<https://hal.inria.fr/inria-00445975/document>)?

==&gt; Referred to by subsequent paper (<http://hal.upmc.fr/file/index/docid/555588/filename/techreport.pdf>) from here (<https://christophermeiklejohn.com/distributed/systems/2013/07/12/readings-in-distributed-systems.html>)?

==&gt; RGA,&#91;15&#93; seem to be available as pdf here (<https://drive.google.com/file/d/0B-AJQZ6Mvw1jS05fa0ZUQV9fM2c/view>)?

==&gt; Woot,&#91;9&#93; seems to be available as pdf here (<https://hal.inria.fr/inria-00108523/document>)?

**==&gt; Logoot,&#91;16&#93; ??**

**==&gt; LSEQ.&#91;17&#93; ??**

**==&gt; CRATE&#91;18&#93; ??**

3) Consider to study Wikipedia on Collaborative Real Time Editors and its correlation with ordered CRDT instances and thus to Darwinet MIVs/SEPSIs (<https://en.wikipedia.org/wiki/Collaborative_real-time_editor>)?

**…??**

4) Consider to study the works of Marc Shapiro and colleagues on CRDTs for Collaborative Editors?

==&gt; Consider the paper ”A comprehensive study of Convergent and Commutative Replicated Data Types” (<http://hal.upmc.fr/file/index/docid/555588/filename/techreport.pdf>)?

==&gt; Consider the paper ”A commutative replicated data type for cooperative editing” defining Treedoc (<https://hal.inria.fr/inria-00445975/document>)?

==&gt; Consider the paper ”CRDTs: Consistency without concurrency control” (<https://hal.archives-ouvertes.fr/file/index/docid/397981/filename/RR-6956.pdf>)?

...

4) Consider this page with references to readings on Distributed Data Systems (<https://christophermeiklejohn.com/distributed/systems/2013/07/12/readings-in-distributed-systems.html>)?

==&gt; This site leads for example to the works on CRDTs my Marc Shapiro and colleagues :)

...

5) Consider to read these attached papers (See above URLs)

## Attachments

- [Data Consistency for P2P Collaborative Editing.pdf](<Data Consistency for P2P Collaborative Editing.pdf>)
- [A comprehensive study of Convergent and Commutative Replicated Data Types.pdf](<A comprehensive study of Convergent and Commutative Replicated Data Types.pdf>)
- [A commutative replicated data type for cooperative editing.pdf](<A commutative replicated data type for cooperative editing.pdf>)
- [CRDTs - Consistency without concurrency control.pdf](<CRDTs - Consistency without concurrency control.pdf>)

{% endraw %}
