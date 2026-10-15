# Todo: Darwinet - Consider to design multi-threading using Darwinet synchronized shared data as a thought experiment to find design pos and cons

```#9d5372d2``` *As of 2016-02-09 14:55*

[mail plain/text](mail.txt)

{% raw %}
Could it be a fun and beneficial throughout experiment to propose a multi threading design where shared data is synchronized as asynchronous Darwinet MIVs?

1) Each thread operates on a MIV of its own.

2) MIV mutations are synchronized using Darwinet Deltas.

3) Consider to have MIV elements in the same state refer to the same memory location (same instance)?

4) Consider an auto-merge mechanism for conflicting changes?

==&gt; What impact can we imagine for computation that was initiated with the ”wrong” state?  
==&gt; Or, put another way, how do we redo computation when MIV element state gets updated?  
==&gt; How much re-compugtation may we imagine as a result of trying to keep up with state changes made by other threads?

5) How efficient may we make the synchronization mechanism?

==&gt; ”Raw” MIV synchronization seems to carry a lot of overhead in state-id, target-id and the actual delta?  
==&gt; How much compression can we imagine from applying deltas to implicit target and state (e.g. using relative target paths)?  
==&gt; How much compression can we imagine if the sender realies on the receiver guessing how to apply the delta combined with a fault detection mechanism?  
==&gt; We may imagine the sender to provide a Hash of the left-out data so that the receiver may check against the Hash of its guess (equal means correct guess)?  
…

6) Could we argue that correct data sharing would minimize synchronization conflicts?

==&gt; Output from one thread as input to the next should be handled as a Future (Dependent thread waits for state update before using data as input)  
==&gt; This means no re-computation occurs due pre-mature processing of data.  
==&gt; Data mutated by multiple threads should not be used until all operations (all threads) has done their job?  
==&gt; This means Delta synchronization may be postponed until each operation ends.  
==&gt; Consider to define synchronization to be ”transactions” (individual deltas during thread execution are NOT synchronized as they have no value until the operation, and thus the transaction, ends)?

…

Consider to elaborate more on this thought experiment and perhaps even consider to make a proof of concept just to test MIV synchronization mechanisms?  
...

{% endraw %}
