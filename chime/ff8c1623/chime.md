# Todo: Programming - Consider a Gateway (e.g., iPos &lt;-&gt; Epas) designed to trigger on upstream and downstream ism state transitions only?

```#ff8c1623``` *As of 2016-09-27 01:40*

[mail plain/text](mail.txt)

{% raw %}
Can we imagine a Gateway between two state machines to work just on listening to state transitions in the two state machines?

1) Consider an upstream iPos fsm (finite state machine) and one downstream Epas fsm.

==&gt; The upstream iPos fsm acts on upstream received iPos messages and changes state accordingly.

==&gt; The Downstream Epas fsm acts on downstream received Soaps messages and changes state accordingly.

==&gt; Now, can a gateway perform iPos &lt;-&gt; Epas event transforms based only on the state changes of these two state machines?

upstream —&gt; msg —&gt; iPos FSM —&gt; Transition —&gt; Gateway &lt;— Transition &lt;— Epas FSM &lt;— msg &lt;— downstream

==&gt; Now, it is evident that in this model the Gateway has no means to trigger events in the two state machines.

upstream &lt;— msg &lt;— iPos FSM &lt;— Event &lt;— Gateway —&gt; Event —&gt; Epas FSM —&gt; msg —&gt; downstream

==&gt; Now, is this sufficient for all processing we need to do to transfer messages both up- and down-stream?

upstream —&gt; msg —&gt; iPos FSM —&gt; Transition —&gt; Gateway &lt;— Transition &lt;— Epas FSM &lt;— msg &lt;— downstream

^

|

v

upstream &lt;— msg &lt;— iPos FSM &lt;— Event &lt;— Gateway —&gt; Event —&gt; Epas FSM —&gt; msg —&gt; downstream

==&gt; Now we may have an upstream msg received by iPos FSM trigger a state transition that the Gateway turns into an Event to the Epas FSM that will send its message.

==&gt; And vice versa a downstream message received by Epas FSM may trigger a state transition that the Gateway turns into an Event to the iPOS FSM that will send its message.

==&gt; The key design will then to ensure each received message triggers sufficient state transitions so have the Gateway trigger the message transform.

2) Consider to argue why the Gateway should be transition receiver and Event emitter (and not the other way around or both)?

==&gt; Having the Gateway reacting on state transitions enables it to react on history rather than the present?

==&gt; A state transition is an Event that encapsulates history (depends on temporal ordering of events)

==&gt; Having the gateway react only to State Transitions forces each FSM to generate redundant state changes for Events that is not dependent on history?

==&gt; It may be redundant to trigger a state transition for messages that always triggers one-to-one?

==&gt; Or, is it still better to reflect such transformation as state changes to be able to process the response (upstream as well as downstream)?

...

==&gt; It would seem having the Gateway trigger only on state transitions make the Gateway itself state free (it relies on upstream and downstream state machines to take care of history)?

==&gt; And upstream and Downstream protocol are already state machines (so there is no need to make the Gateway into yet a third state machine)?

==&gt; The two bridged protocol state machine transitions are always enough to trigger the Gateway to do its job?

**==&gt; There are no additional states for the Gateway to keep track of?**

…

…

Consider to elaborate on this design to see if it is a sound enough design for a Gateway implementation?

...

{% endraw %}
