# Todo: Programming - Consider a Message payload reduction scheme based on receiver-cashing of sender constant data?

```#4bcb3b68``` *As of 2016-04-03 01:03*

[mail plain/text](mail.txt)

{% raw %}
Can we imagine a Protocol Messaging scheme where the sender only sends data that the receiver can’t figure out for itself?

1) Consider a protocol where a lot of the data from the Sender is for session synchronisation and identification of the sender to the receiver?

==&gt; Consider the sender assembles the synchronisation data and just sends a hash of that data to the receiver?  
==&gt; The receiver then assembles the same data is it exotics it (e.g. incremented sequence numbers) and compares the revived hash to the has of expected data.  
==&gt; The receiver would then detect errors just as efficient but without the data having to be sent cross the wire?

==&gt; Consider the same approach to be applied to semi-constant data about the sender (e.g. Sender ID, sender adress info)?  
==&gt; If the sender just sends it once when authenticated (e.g. by a Host), the Host may then cache this information and use for hash-comparrission with has of same data from the sender?

2) Consider to apply this scheme to Payment Network Messaging?

==&gt; What can we gain from applying this to SPDH Messaging?  
==&gt; What can we learn from applying this to ISO 8583 messaging?  
==&gt; What can we learn from applying this to ISO-STD Presentment files?

==&gt; Consider to try this out to local storage of TestBench Present,ent File storage (internal format)?  
…

Consider to delve into this idea of compressing known Protocol Messaging by replacing data that can be known by the receiver with secure hash values to keep error detection?  
...

{% endraw %}
