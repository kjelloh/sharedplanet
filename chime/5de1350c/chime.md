# Todo: Darwinet - Consider the work of Christopher Meiklejohn on Declarative, Convergent Edge Computation is in fact a variant of the Darwinet Network?

```#5de1350c``` *As of 2017-02-21 16:09*

[mail plain/text](mail.txt)

{% raw %}
Watching a talk at Lambda World 2016 by Christopher Meiklejohn it seemed to me he was actually talking about a system with many of the same components as I have imagined to use to build the Darwinet network?

==&gt; Also see ”[Todo: Darwinet - It seems Darwinet Deltas are in fact the same thing as "Conflict-free replicated data type" or CFRD?](../36f0b5ab/chime.md)"

1) Consider to delve into the talk ”Declarative, Convergent Edge Computation by Christopher Meiklejohn” (<https://www.youtube.com/watch?v=9xRWBJ5LZBs>)?

==&gt; In first minute - He seems to state they implement the system on top of Erlang?

==&gt; Thus we should be able to mimic their system in C++ using some go-routine like distributed library?

==&gt; His PhD seems to be made in cooperation of an EU project (and several other universities and organisations)?

==&gt; This seems to be the EU Project ”SyncFree” (<https://syncfree.lip6.fr>)?

> > ”*SyncFree is a European research project running October 2013 to December 2016. It is funded by the European Union, grant agreement n°609551.*"

...

2) This seems to be his home page with blogs and references to research (<https://christophermeiklejohn.com>)?

==&gt; In his CV he seems to state his main interest to be Conflict-Free Replicated Data Types (CRDTs) (<https://christophermeiklejohn.com/ChristopherMeiklejohn_CV_2015.pdf>)?

==&gt; This page seems to summarize references to information about CRDTs (<https://christophermeiklejohn.com/crdt/2014/07/22/readings-in-crdts.html>)?

...

3) Consider to delve deeper into the EU Project ”SyncFree (EU/FP7)” (<https://syncfree.lip6.fr>)?

==&gt; Consider this page with references to talks in scope with EU Project SyncFree EU/FP7 (<https://syncfree.lip6.fr/index.php/dissemination>)?

==&gt; Consider this talk ”Marc Shapiro - Encapsulating replication, high concurrency and consistency with CRDTs - Curry On” (<https://www.youtube.com/watch?v=rVRegyQvHqs&feature=youtu.be>)?

==&gt; Consider this talk ”CRDTs in Practice - Marc Shapiro & Nuno Preguiça” (<https://www.youtube.com/watch?v=xxjHC3yLDqw&feature=youtu.be>)?

==&gt; Consider this talk ”Demo of the CISE tool” by Marc Shapiro (<https://www.youtube.com/watch?v=HJjWqNDh-GA&feature=youtu.be>)?

==&gt; Consider this talk ”Implementation of CRDTs with δ-mutators: Carlos Baquero Moreno, HASLAB” (<https://www.youtube.com/watch?v=jwCx1A181vY&feature=youtu.be>)?

==&gt; Consider this talk ”Lasp: Declarative, Distributed Edge Computation: Christopher Meiklejohn, Machine Zone, Inc.” (<https://www.youtube.com/watch?v=co8Eyb2BrIQ&feature=youtu.be>)?

==&gt; It seems to be a variant of the talk at Lambda World 2016 talk ”Declarative, Convergent Edge Computation by Christopher Meiklejohn” (<https://www.youtube.com/watch?v=9xRWBJ5LZBs>)?

==&gt; Consider this talk ”When Weak Consistency is not Enough from Causality to Transactions: JOÃO LEITÃO, NOVA-LINCS” (<https://www.youtube.com/watch?v=Ox6UY-D_Zvs&feature=youtu.be>)?

==&gt; Consider this talk ”Erlang Factory SF Bay 2015 - Christopher Meiklejohn - Distributed Eventually Consistent Computations” (<https://www.youtube.com/watch?v=uwpakTIg9r8&feature=youtu.be&list=PLWbHc_FXPo2h0sJW6X2RZDtT1ndw6KKpQ>)?

==&gt; Consider this Github project ”SyncFree” (<https://github.com/SyncFree>)?

==&gt; There seem to be a C++ implementation of delta enabled CRDT:s (<https://github.com/SyncFree/delta-enabled-crdts>)? - See below.

4) Consider to browse the web for talks on CRDT?

==&gt; Consider ”Conflict-Free Replicated Data Types (CRDTs)” (<https://www.youtube.com/watch?v=ZLjl_55um4I>)?

==&gt; Consider ”Strong Eventual Consistency and Conflict-free Replicated Data Types” by Marc Shapiro (<https://www.youtube.com/watch?v=ebWVLVhiaiY>)?

==&gt; Consider ”Towards Browser and Server Utopia with Scala.JS: an example using CRDTs” by Richard Dallaway (<https://www.youtube.com/watch?v=Ohu2cajjTdw>)?

==&gt; This talk seems to be about sharing mutating Text?!

> > ”*ublicerades den 4 jan. 2016*  
> > *This session demonstrates the practical application of Scala.JS using the example of a collaborative text editing algorithm, written once in Scala, but used from the JVM and JavaScript. Scala.JS is a compelling way to build JavaScript applications using Scala.*"

==&gt; He demonstrates Collaborative Text Editing using WOOT that seems to live here (<https://github.com/kroky/woot>)?

==&gt; This talk seems to be mostly about Scala.js and front-end/back-end tool chains to build WOOT?

==&gt; At 9:30 he states that the collaborative editing network is built on top of the JavaScipt based Editor Ace?

![](<WOOT as Ace Client Editor and HTTP server based framework.tiff>)

==&gt; It seems WOOT is a Client Server Architecture (All messages goes through the server)?

==&gt; At 12:45 he states the solution is to share the Text as a Commutative Replicated Data Type.

==&gt; Note: He dod NOT say *Conflict Free* nor *Convergence* Replicated Data Type (The other two flavors of CRDT:s)?

==&gt; It seems WOOT has found a way to make Text Edit Operations Commute (hence the WOOT Text is represented as a Commutative Replicated Data Type)?

==&gt; At 14:50 he defines a WOOT Character used to represent the shared text.

![](<WOOT Character very much like a Darwinet Delta.tiff>)

==&gt; Also see WOOT paper.

==&gt; This is almost identical to the proposed Darwinet Delta :)

==&gt; Now WOOT seems to have managed to make the insert/delete commute by always keeping deleted characters as hidden (and thus enabling receivers to still reference deleted characters)?

![](<WOOT Algorithm based on hide-instead-of-delete.tiff>)

==&gt; In this example Site may delete b (make it invisible) and still handle a remote operation inserting ’y’ between ’b’ and ’c’.

==&gt; This seems to be all this talk is about WOOT.

==&gt; Consider ”The Distributed Web, and the Browser I Wrote to Surf It (Beaker Browser Demo)” by (<https://www.youtube.com/watch?v=pi-kreA52oI>)?

==&gt; It seems to be about Distributed Web and a Browser for this called ”Beaker”?

==&gt; Consider ”PWLTO#7 – Paul Osman on CRDTs - Commutative Replicated Data Types” by Paul Osman (<https://www.youtube.com/watch?v=8NJ2bA7B_-Y>)?

==&gt; He seem to state three variants of CRDT:s (C... Replicated Data Types)?

Commutative…

Conflict Free…

Convergence…

==&gt; It seems they are slightly different but he does not go into details in this talk?

==&gt; He seems to refer to an original paper on CRDT:s called ”” (<https://hal.archives-ouvertes.fr/file/index/docid/397981/filename/RR-6956.pdf>)?

> > ”*CRDTs: Consistency without concurrency control*  
> > *Mihai Leia, Nuno Pregui ̧ca, Marc Shapiro

> > To cite this version:  
> > *  
> > *Mihai Leia, Nuno Pregui ̧ca, Marc Shapiro. CRDTs: Consistency without concurrency control. &#91;Research Report&#93; RR-6956, INRIA. 2009, pp.16. &lt;inria-00397981&gt;*"

**WE ARE HERE...**

5) Consider to study the JavaScript based Web run Editor Ace (<https://ace.c9.io/#nav=about>)?

==&gt; It seems to be implemented as a javascript module ace.js (and thus be embeded in a web page) (<https://ace.c9.io/#nav=embedding>)?

==&gt; It seems WOOT wraps the back-end of Ace to share the edited file in a WebSocket network?

6) Consider to delve into the WOOT Collaborative Text Editing project?

==&gt; It seems to live on github here (<https://github.com/kroky/woot>)?

==&gt; It seems to be a Node/JavaScript project (to enable execution in Web Browsers)?

==&gt; No, it is actually Scala.js (but still Javascript though)?

==&gt; Scala.js seems to live here (<https://www.scala-js.org>)?

==&gt; It seems to be Scala to JavaScript compiler to build Web Browser front ends?

==&gt; Could be interesting to check out for making User Interfaces based on Immutable State?

...

==&gt; It seems to be based on this paper ”*Real time group editors without Operational transformation*” (<https://hal.inria.fr/file/index/docid/71240/filename/RR-5580.pdf>)?

> ”*Real time group editors without Operational transformation*  
> *G ́erald Oster, Pascal Urso, Pascal Molli, Abdessamad Imine*”

> ”*To cite this version:*

> *G ́erald Oster, Pascal Urso, Pascal Molli, Abdessamad Imine. Real time group editors with- out Operational transformation. &#91;Research Report&#93; RR-5580, INRIA. 2005, pp.24. &lt;inria- 00071240&gt;*"

==&gt; WOOT seems to be an acronym for ”Without Operational Transformation” and be a framework for very large P2P networks?

![](<WOOT Paper Abstract.tiff>)

==&gt; It seems WOOT proposes a Commutative Replicated Data Type to represent text edit operations that actually commute to the same end state?

![](<WOOT never-delete and insert-between algorithm ensure commuting operations.tiff>)

==&gt; It seems a WOOT character is very much like Darwinet Deltas?

![](<WOOT Characters very much like Darwinet Deltas.tiff>)

==&gt; Where id is a pair *Site Number* and a *Local Logical Clock*

==&gt; This corresponds exactly to Darwinet Delta Index is a pair of *MIV Id* and a *Local Sequence Number *:)

==&gt; Consider what it means that WOOT treats each character as a Delta (Each character has a unique ID)?

==&gt; They state in the paper that the memory consumption is still reasonable and actually less that that of an ”ordinary” Operational Transform (OT) Approach?

==&gt; It seems if we trust WOOT to be an efficient algorithm to make intrinsically non-commutative text operarations to commute - then we should try this for all Darwinet Container structure mutations?

==&gt; Consider all Darwinet Containers to behave like never-delete (only make deleted members invisible)?

==&gt; Consider to implement Darwinet Text as Arrays of Characters (in effect making Darwinet Text into WOOT-like Text)?

==&gt; Consider the never-delete idiom rimes very well with the Darwinet MIV being a Confluent Persistent data Type?

==&gt; The Persistent Dat Type already preserves past states (so **WOOT is actually an implementation of Persistence**)?

==&gt; Consider by using the WOOT idiom the Darwinet MIVs will never merge (they can always converge to the same state the same way WOOT text does)?

==&gt; Consider if this is what we want (we do like to branch for conflicting deltas do we not)?

==&gt; Consider the always-converge WOOT algorithm enable us to make branching a manual operation (The user may travel-back-and-branch to not accept conflicting operations from others)?

...

7) Consider to study ”*A comprehensive study of Convergent and Commutative Replicated Data Types*” by Marc Shapiro and others (<https://hal.inria.fr/inria-00555588/document>)?

==&gt; Consider to use the full title if required to search on the web?

> ”*A comprehensive study of Convergent and Commutative Replicated Data Types*

> *Marc Shapiro, Nuno Pregui ̧ca, Carlos Baquero, Marek Zawirsk*”

==&gt; The actual pdf-document seems to be available here (<https://hal.inria.fr/inria-00555588/file/techreport.pdf>)?

==&gt; And referred to from Open Archive here (<https://hal.inria.fr/inria-00555588>)?



8) Consider to follow up on ”Convergent Replicated Data Types” by Simon Guindon (<http://simongui.github.io/distributed-systems/crdt.html>)?

==&gt; He seems to state that one method for state synchronization is ”dotted version vectors” which is exactly what we have devised for Darwinet Deltas?

==&gt; Consider to follow up on this paper ”Dotted Version Vectors: Logical Clocks for Optimistic Replication” (<https://arxiv.org/pdf/1011.5808v1.pdf>)?

==&gt; YES - This paper seems very much like the Delta synchronization proposed for the Darwinet network!

**WE ARE HERE...**

==&gt; Consider list of references by Simon Guindon (<http://simongui.github.io>)?

9) Consider this C++ implementation of delta enabled CRDT:s (<https://github.com/SyncFree/delta-enabled-crdts>)?

> ”Reference implementations of state-based CRDTs that offer deltas for all mutations.”

==&gt; Consider to study and understand the set of Conflict-Free Replicated Data Types (CRDT:s)?

> "Current datatypes are:

> • GSet: A grow only set  
> • 2PSet: A two phase set that supports removing an element for ever  
> • Pair: A pair of CRDTs, first and second.  
> • GCounter: A grow only counter  
> • PNCounter: A counter supporting increment and decrement  
> • LexCounter: A counter supporting increment and decrement (Cassandra inspired)  
> • DotKernel: (Auxiliary datatype for building causal based datatypes)  
> • CCounter: A (causal) counter for map embedding (Optimization over Riak EMCounter)  
> • AWORSet: A add-wins optimized observed-remove set that allows adds and removes  
> • RWORSet: A remove-wins optimized observed-remove set that allows adds and removes  
> • MVRegister: An optimized multi-value register (new unpublished datatype)  
> • EWFlag: Flag with enable/disable. Enable wins (Riak Flag inspired)  
> • DWFlag: Flag with enable/disable. Disable wins (Riak Flag inspired)  
> • ORMap: Map of keys to CRDTs. (spec in common with the Riak Map)  
> • RWLWWSet: Last-writer-wins set with remove wins bias (SoundCloud inspired)  
> • LWWReg: Last-writer-wins register"

==&gt; It does not seem to provide any ”Text” types (because text mutations do not commute)?

==&gt; It seems to support ”last win” types (that sugests this is a way to have shared state converge)?

==&gt; Consider to understand how the network reaches consensus on who is ”the last”?

==&gt; Consider Simon Guindon provides a good overview of these types (<http://simongui.github.io/distributed-systems/crdt.html>)?

==&gt; Consider to follow up on SoundCloud seeming to apply CRDT mechanisms as indicated by the type ”RWLWWSet: Last-writer-wins set with remove wins bias (SoundCloud inspired)”?

10) Consider to study the ”Riak” Protocol for distributed database storage (<https://github.com/basho/riak>)?

> ”Riak is a decentralized datastore from Basho Technologies. <http://docs.basho.com>"

…

Consider to continue to use the work of Christopher Meiklejohn to follow up on references into the world of CRDT:s to see what we can learn and what we can use for Darwinet implementation?

...

{% endraw %}
