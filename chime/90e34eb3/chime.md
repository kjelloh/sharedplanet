# Todo: Programming - Consider benefits of a Protocol Library based on immutable data and Functional Reactive Programming?

```#90e34eb3``` *As of 2017-02-06 23:26*

[mail plain/text](mail.txt)

{% raw %}
So, what would it mean if we imagine a Protocol Library designed using immutable data (Persistent Data Structures) and Functional Reactive Programming?

1) Consider the Protocol State Machine would have to be a Functional Persistent Data Structure (New State = New Instance)?

2) Consider we can imagine the Protocol as the Input and Output stream as two separate streams of events?

==&gt; Consider the input stream is processed using Functional Reactive Programming?  
==&gt; Consider each event in the stream may result in a new protocol state (a new instance of the protocol state)?

new_state = react_on(event, current_state);

==&gt; Consider each message on the out stream to the other side is a function on the state change?

tx_event = tell_peer(previous_state, new_state)?

==&gt; Consider the received data is always immutable?

…

…

Consider to elaborate on this idea of implementing Protocols as Functional Reactive Programming?

...

{% endraw %}
