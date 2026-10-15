# Todo: Darwinet - Consider potentially encryption weaknesses in that the same deltas are re-sent through the network encrypted using each node-to-node keys?

```#240ee821``` *As of 2017-02-11 11:59*

[mail plain/text](mail.txt)

{% raw %}
Consider to what extent the security of the encryption in a Darwinet network may be weakened by the fact that Deltas are ”gossiped” (replicated many times) in the network with the different keys used between each node-to-node?

1) Elaborate on to what degree the encryption keys used may be compromised by being used to encrypt the same deltas?

…

2) Consider we may solve this problem by ”salting” the sent messages (in effect no encrypt the same data when propagating deltas through the network)?

…

…

Consider to elaborate on encryption schemes that enables Deltas to be broadcasted through the network without risking to compromise the node-to-node encryption keys used?  
...

{% endraw %}
