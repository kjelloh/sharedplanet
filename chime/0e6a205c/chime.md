# Todo: Darwinet - Consider how common Group Chat protocols (e.g., iMessage, Messenger?) breaks two-part double-ratchet security into group message (sender key) single-ratchet security?

```#0e6a205c``` *As of 2019-01-29 16:49*

[mail plain/text](mail.txt)

{% raw %}
Consider if and how we should design Darwinet network synchronisation security based on the known problems with group messaging (they are more or less single-ratchet sender-key algorithms) as opposed to two-part-messaging (in effect mostly double-ratchet send-and-receiver key algorithms)?

1) Consider this youtube video “What's Up With Group Messaging? - Computerphile” (https://www.youtube.com/watch?v=Q0_lcKrUdWg)?

…

2) Consider in Darwinet we should use double-ratchet node-2-node delta messaging (despite the overhead)?

==&gt; Consider in Darwinet we treat state conflict as branches (and may thus apply double-ratchet for each unbranched state-history path)?

==&gt; Consider if Darwinet needs to consider the Group-Messaging overhead problem (to much overhead with double-ratcheting each node-2-node messaging)?

==&gt; Consider Darwin et branching-state differs from a Group-Chat in that the latter always merge while Darwinet always branch on state conflict?

…

3) Consider Darwinet should apply a double-ratchet Node-2-Node mechanism to prevent a stolen key to allow eaves-dropper to also read old delta messages?

==&gt; Consider we want an eaves-dropper to NOT be able to read either later NOR older messages of Delta in a Domain they are NOT a member of?

==&gt; Consider how we can provide sufficient security in adding members to a shared Domain (in effect giving the member access to current domain state and all the state change history)?

...

…

Consider to delve deeper into this known aspect how group chats uses sender-key-ratchets with a group-common-key response (no ratchet) affects how we should design Darwinet node-2-node messaging security?

{% endraw %}
