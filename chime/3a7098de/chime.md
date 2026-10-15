# Todo: Darwinet run-time - It seems wee need to understand how the run-time handles the state branching?

```#3a7098de``` *As of 2017-06-19 14:11*

[mail plain/text](mail.txt)

{% raw %}
It seems as the Tha of a Darwinet View may be mutated both by synchronizing with the domain Tha state and bu mutating messages from the Client, the run-time need to be able to detect and process conflicting Tha state changes?

1) Consider how Tha mutations may conflict?

==&gt; Consider what it means that only update() may mutate Tha state?

==&gt; It means whatever comes back from update may or may not be a new Tha state?

==&gt; That new state may be a synchronization with peer node Tha state?

subscriptions -&gt; Sub Delta —&gt; run-time &lt;--&gt; update

|

v View(view_tha)

view_Tha --&gt; view --&gt; Client

==&gt; Or it may be a local new state mutated bly Client (on Client Msg)

run-time

^

|

view_Tha (the Tha state the client assumes)

Msg &lt;------------- Client

Msg (operates on view_that)

==&gt; It seems the run-time may end up with different Tha states when update()?

==&gt; Sub Delta carries Darwinet information on what Tha state the Delta must be applied on (Delta.target_index)?

==&gt; And the run-time needs to keep track of what Tha state the Client Msg must be applied to?

==&gt; So, the run-time needs to be able to detect if these two mutations conflict?

2) Consider ways for the run-time to manage conflicting Tha states?

==&gt; Consider an Set of Tha-state heads (one for each ”latest state” of a series of non-conflicting mutations)?

==&gt; It seems such a head would correspond with one sequence of Deltas with no conflicts?

using ThaHeads = map&lt;ThaKey, Tha&gt; // Tha heads are just a map from a Tha key to a Tha

==&gt; Consider the run-time may now find the head to send to update to mutate it?

tha_heads&#91;tha.key()&#93; = update(tha) // update is synchronous!

==&gt; And for Msg from the Client we must look-up the Client Head tha (to know what head the client operates on)?

tha_heads&#91;client_tha.key()&#93; = update(client_tha);

==&gt; BUT - this does NOT work (each mutation will give a NEW head key (the state has changed)!

==&gt; So, how do we keep track of branches (each allowing non-conflcting head mutation)?

==&gt; Consider the branch key is the key of the that state that branched (the one where mutations conflicted)?

==&gt; ”Who” knows this key?

==&gt; Consider we may get to a mechanism by understanding how we detect conflicts in the first place?

==&gt; Consider a conflict is when we tray to apply a mutation to a Tha state that already has descendants?

head tha0

|

v

tha0 -&gt; branch:tha0 -&gt; tha1 -&gt; tha2

|

v

update (OK tha2 is the head)

^

|

Msg

==&gt; Consider it is the run-time that detects if we are updating a head or not?

head tha0 &lt; - - head tha0

| | |

v . v

tha0 -&gt; branch:tha0 -&gt; tha1 -&gt; tha2 &lt; - - | | -&gt; tha3 = tha´

| . . ^

v | | |

update -&gt; run-time (OK tha2 is the head)

^ tha´

|

Msg

==&gt; What happens in case of conflict (we call update on a non-head tha-state)?

head tha0

|

v

tha0 -&gt; branch:tha0 -&gt; tha1 -&gt; tha2

|

v

update -&gt; run-time (CONFLICT tha1 != head)

^ tha'

|

Msg

==&gt; How may the run-time create a new branch on conflict?

head tha0

|

v head tha1

tha0 -&gt; branch:tha0 -&gt; tha1 -&gt; tha2 |

| v

| ---&gt; branch:tha1 -&gt; tha1’ = tha´

| ^ ^

| | |

| ----------- |

v | |

update -&gt; run-time (branch tha1 with tha')

^ tha'

|

Msg

==&gt; Consider we need a list of branches (each with a head)?

==&gt; It seems branches can be implemented as pairs {branched_tha, head_tha}?

head tha0

|

v head tha1

tha0 -&gt; branch:tha0 -&gt; tha1 -&gt; tha2 |

| v

| ---&gt; branch:tha1 -&gt; tha1’ = tha´

| ^ ^

| | |

| ----------- |

v | |

update -&gt; run-time (branch tha1 with tha')

^ tha'

|

Msg

branches {tha0,tha2}, {tha1,tha1’}?

==&gt; Consider how we allow and manage multiple branches?

head tha0

|

v head tha1´, tha1´´and tha1´´´

tha0 -&gt; branch:tha0 -&gt; tha1 -&gt; tha2 |

| v

| ---&gt; branch:tha1 -&gt; tha1´

|

| ---&gt; branch:tha1 -&gt; tha1’´

|

| ---&gt; branch:tha1 -&gt; tha1’´´

|

...

==&gt; Thus, for tha1 there is a list of branches (each with a different head)?

==&gt; Consider a branch may thus be identified by its root state (the state that branched) and the head (head tha1´, tha1´´and tha1´´´in the example)?

==&gt; But - then the branch ID will CHANGE as the head change (do we care)?

==&gt; YES- we do care because if we would add the SAME HEAD to two branches with the same root they will be identical branches?

==&gt; Or, that is a good thing?

head tha0

|

v head tha1´, tha1´´and tha1´´´

tha0 -&gt; branch:tha0 -&gt; tha1 -&gt; tha2 |

| v

| ---&gt; branch:tha1 -&gt; tha1´ -&gt; tha2´

|

| ---&gt; branch:tha1 -&gt; tha1’´ -&gt; tha2´´

|

| ---&gt; branch:tha1 -&gt; tha1’´´ -&gt; tha2´ (Now the same branch as the first one?)

|

...

==&gt; Consider we need to distinguish between ”**same instance**” and ”**same state**”?

==&gt; Two tha instances may represent the same state but be different instances?

…

…

Consider to delve deeper into this Issue of how the run-time must handle conflicting model mutations (branches)?

...

{% endraw %}
