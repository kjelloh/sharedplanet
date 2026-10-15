# Todo: Trudelutt - Consider to make first version one where one can share an mp3 and play it synchronously with other members of Darwinet domain?

```#167a476f``` *As of 2016-08-05 11:46*

[mail plain/text](mail.txt)

{% raw %}
Consider the first function we need of Trudelutt is to share one mp3 file and be able to play it synchronously with other members of the same Darwinet domain?

1) Consider to implement some very basic mechanism to be able to share one mp3-file over mail P2P messaging?

2) Consider to implement a mechanism so that one can start plating an mp3 synchronously with other members of the same Darwinet Domain?

==&gt; In this way member of a choir can meet and sing to an mp3 using earphones?

==&gt; The &lt;start&gt; mechanism must work over mail P2P communication!

==&gt; Consider each present member presses Synchronous-Play.

==&gt; Each app then sends a request to the other nodes for synchronous play of the selected file.

==&gt; Do we need to synchronize clocks (or does the internal clocks of Nodes run synchronously already)?

==&gt; Also See ”Todo: Programming - Consider to understand the NTP (network Time Protocol) and how to use it with available C++ open source code?"

==&gt; Consider we need a synchronisation accuracy down to at least 50 ms ()?

> > *“It boils down to, roughly, optimal values of around:*

> > *• vocals &lt; 3ms;*

> > *• drums &lt; 6ms;*

> > *• guitars &lt; 12ms;*

> > *• piano &lt; 10ms;*

> > *• keyboards (pads, etc) &lt; 20ms*

> > *Note how, according to the author,*

  
> > *"The speed of sound in air is roughly a thousand feet per second, each millisecond of delay is equivalent to listening to the sound from a point one foot further away. So if you can play an electric guitar 12 feet from your amp, you can easily cope with a 12ms latency."" *

==&gt; Consider we need a way to determine the difference between the system clocks on each node?

==&gt; Consider the time to send the mail is to erratic to measure (it does not mean anything)?

==&gt; So, how do we adjust for any differences in each node system clock?

==&gt; Consider to define an algorithm where the nodes decide on a time to start the playback on each node?

==&gt; When the time occurs each node starts the playback.

==&gt; Playback continues until end of file or one presses stop?

3) Consider to adjust the Play-mechanism so that each member may start and stop regardless of the others?

==&gt; Consider that one node that stops and starts again must re-synchronise to know when and where to start the local file to be in sync?

==&gt; Consider to make this synchronisation mechanism to be part of the same one used when all starts at the same time?

…

…

Consider to implement this mp3-share and synchronous playback as functions of the first release of Trudelutt?

…

{% endraw %}
