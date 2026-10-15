# Todo: Programming - Consider to study online games to understand how they solve the synchronisation of "world state" shared by asynchronous player clients?

```#ba6a7d31``` *As of 2016-01-03 15:19*

[mail plain/text](mail.txt)

{% raw %}
How does real-time online games like WOW solve the problem of synchronising “world state” between all interaction gaming clients?

1) This thread of discussion seem to propose “server-ack-sync” and “predict-result-sync” for an online pong-game (<http://stackoverflow.com/questions/4713582/simple-online-pong-game-network-synchronization>)?

2) This assumes online games is only interred in a censuses of “now” and not of getting the whole history of interacting mutation correct?

==&gt; Explicitly, online games always requires auto-merge of conflicting mutations to the world (there can be only one world)?

3) What can we then say about using Darwinet for online gaming?

==&gt; Seems we need Darwinet then to prohibit branching (only one world state allowed)

==&gt; Darwinet MIV must carry special data that mimics a physical reality in that each MIV predicts current MIV values based on known history?

==&gt; Darwinet may need to apply some mechanism to emulate a “central-ack” to prohibit MIVs to mutate a value until the domain agrees (acks) the mutation is actually possible given current agreed state (e.g. there is actually a missile available to launch or a weapon on the ground to pick up)?

4) Could we even find proof that some aspects to online-gaming require a central server to ensure “synchronised one world” compliance?

==&gt; Is it so that a P2P network will always be too temporarily distanced to be able to agree on current world-state?

==&gt; Or can we calculate the required latency allowed for a majority of nodes to continuously agree on current world-state to make real-time online gaming enjoyable in Darwinet?

…

Consider to elaborate more on this idea and how Post-server Darwinet networks may serve as the base on online gaming clients?

...

{% endraw %}
