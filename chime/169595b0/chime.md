# Todo: Programming Ibi - Consider Key Path library Ibi to implement path hashing behind the scene?

```#169595b0``` *As of 2016-07-30 19:02*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to have the Key path library Ibi to make behind-the-scene processing (matching) of paths hash-based?

1) Consider a design to translate between hash-values and Paths?

==&gt; Consider compile-time has-value-based Path processing (whatever that means)?  
…

2) Consider if there is a way to have a Path only carry its hash-value (low weight) but still behave as a fill path (provide member node access)?

==&gt; Can we imagine a Path instance that keeps a share_ptr to its domain (environment) where its has-to-path list is stored?  
==&gt; Consider such an instance to use the has-table to implement accessors to member nodes?  
…

3) Consider Path streaming services that streams hash-values and expects the receiver to already have a hash-value list to reconstruct actual path content?

==&gt; How can we imagine the receiver to keep synchronised with the sender?  
==&gt; Consider a streaming protocol that streams both path and hash-value for new Paths but not for old (already hash-transferred ones)?  
…

…

Consider to delve into this idea to implement some hash-based mechanism to lower the weight of Paths of the Ibi Key Path library?  
...

{% endraw %}
