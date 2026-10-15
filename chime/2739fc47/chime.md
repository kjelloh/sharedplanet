# Todo: Darwinet - Consider to design Deltas as "Actions" and have update: Action -&gt; State -&gt; State and view: State -&gt; State -&gt; GUI (Elm/React style)?

```#2739fc47``` *As of 2017-02-27 17:20*

[mail plain/text](mail.txt)

{% raw %}
Inspired by the talk ”The Pure Functional Web by Bodil Stokke” (<https://www.youtube.com/watch?v=fLsTPHDWoF0>) it seems to me Darwinet could adopt the Elm/React model/update/view immutable approach for turning Deltas into new MIV states and then use State-diffs to report to clients?

==&gt; Also see ”Todo: Darwinet - Consider to apply the Elm language Model, Update, View architecture for Darwinet MIV, Update View?"

1) Consider the Darwinet MIV to behave like update: Action -&gt; State -&gt; State (where Action is the Delta and State is the MIV state)?

==&gt; It seems in Elm (and React?) each Action plus current State is executed by update and the result is a new State?

==&gt; This seems to correspond to Darwinet where each Delta plus current MIV state results in a new MIV state?

…

2) Consider a Darwinet Client to play the role of the ”Elm/React view” (in fact we actually call the Darwinet component holding the MIV state for the ”view”)?

==&gt; It seems the Elm (and React?) each new State is processed by the view that produces a new GUI (in Elm/React is is simply a new HTML DOM)?

==&gt; Consider we make Darwinet have each new MIV state result in a new ”view” to the Client (whatever we should call the ”stuff” we end up sending to the Client)?

==&gt; In fact - Consider to enable the client to receive only the MIV State change by view function: State -&gt; State -&gt; Client Data (as in Old State plus New State results in some Delta State sent to the Client)?

…

3) Seems for Darwinet we still have to settle for what terms to use and how to design what the Client actually receives from the Darwinet View?

==&gt; Consider the Delta is not quite the same as the MIV State Difference (Old State - New State)?

==&gt; Consider they may differ because Darwinet P2P Deltas are about the data types of the MIV while the data sent to the client may be different?

==&gt; Consider for example that the MIV may be implemented using different forms of Persistent and Replicated data structures (including in some cases Conflict-Free Replicated Data Types)?

==&gt; Consider what Data Types the Client should receive from the Darwinet View?

…

4) Consider to design the Client View interface to be a Reactive Programming Interface (Subscribes to a stream of MIV State Changes)?

==&gt; Consider what it would mean if we force the Client to subscribe to a Functional Reactive stream of ”Events”?

...

…

Consider to delve deeper into this idea of mimicking the Elm/React Model, Update, View design for P2P Deltas, the MIV state and the Client View messaging?

...

{% endraw %}
