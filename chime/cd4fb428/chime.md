# Todo: darwinet - Consider to design a robust Delta-Stream-Optimisation mechanism that allows the Delta Strem to be mutated for efficiency reasons?

```#cd4fb428``` *As of 2016-03-24 16:38*

[mail plain/text](mail.txt)

{% raw %}
Consider to delve into the idea that produced Delta Streams should be mutable by future optimisation reasons?

1) Consider a File Delta produced by a low-capacity node just carries the whole new file (not actually an optimised delta)

==&gt; Consider to call this Single-Delta-Compression?  
==&gt; Then we would like some other more capable node to detect this and propose that delta to be reduced in size to carry only the actual change to the file?  
==&gt; The new (smaller) delta should then distributed in the domain as a replacement for the previously (larger) delta?

==&gt; Consider how such replacements may be implemented in a secure and stable way?  
==&gt; Does such Delta replacements need to be be handled as Deltas (and thus be trackable to)?

==&gt; Can we imagine this Delta-Replacement as a Delta applied to the Delta Trail (enabling us to repeat the Delta-mechanism for MIV states)?  
…

2) Consider Delta Trail Compressions to reduce the trail granularity (to save space)

==&gt; Consider to call this Delta-Trail-Compression (A transaction defined by a Delta Sequence is replaced with a single Delta)?

==&gt; Then we would like a Node to be able to propose that two or more nodes in sequence to be replaced by a single one?  
==&gt; We then loose Delta Trail granularity but saves storage space?

==&gt; Consider to implement such a Delta-Trail-Compression as a stable and robust mechanism?

==&gt; As for Single-Delta Compression: Does such Delta replacements need to be handled as Deltas (and thus be trackable to)?

==&gt; Can we imagine this Delta-Replacement as a Delta applied to the Delta Trail (enabling us to repeat the Delta-mechanism for MIV states)?  
…

3) Consider to allow Old Deltas to Die away into oblivion?

==&gt; Consider to call this Delta-Trail-Depth reduction?

==&gt; Then nodes may propose to cut the depth of the Delta Trail they store locally (telling others about not stored olde Deltas)?  
==&gt; Then we seem to need a mechanism for a Domain to negotiate the Delta-Trail-Depth available to the Domain (at least stored at some nodes if not all)?  
==&gt; Having a Node in the Domain capable to store large amounts of data would result in the Domain being able to keep a very deep Delta Trail?

==&gt; As for the other Delta-Trail-Mutation operations: Does such Delta deletions need to be handled as Deltas (and thus be trackable to)?

==&gt; Can we imagine this Delta-Trail-Depth reduction as a Delta applied to the Delta Trail (enabling us to repeat the Delta-mechanism for MIV states)?  
…

4) Seems we may view such operations as Delta-Trail-Mutations?

==&gt; Can we imagine any Delta-Trail-Mutation as a Delta applied to the Delta Trail (enabling us to repeat the Delta-mechanism for MIV states)?  
…

…

Consider to delve on this idea of controlled and robust Delta-Trail mutations?  
...

{% endraw %}
