# Todo: C++ - Figure our a way to integrate an asio::tcp object, an boost::msm and the Active Object idiom?

```#e5c2822d``` *As of 2015-11-28 15:54*

[mail plain/text](mail.txt)

{% raw %}
Seem we would like to have the workings of an asio TCP object (client or server) to be defined by an MSM (Meta State Machine) and also have threaded actors implement the Active idiom?

1) We would like to have a link protocol engine to be a threaded msm state machine (an actor with state)

2) We would like the Event handlers of the asio object post to be processed by the msm state machine.

3) So what is needed to have the protocol layered engines ”asynchronously" signal up and down the chain?

higher layer ==&gt; Event ==&gt; Link Layer Engine ==&gt; MSM state machine ==&gt; asio TCP Object

higher layer &lt;== Event &lt;== Link Layer Engine &lt;== MSM state machine &lt;== asio TCP Object

4) Seem we need to have both the MSM Engine and the asio TCP object threaded?

==&gt; Link MSM needs its own thread to dispatch messages from both upstream engines and downstream asio TCP object?

==&gt; And the TCP Object needs its own threading to be ablo to block in actual send/receive?

5) Now, this would mean we’d like the Link Engine MSM AND the asio TCP Link object (call it connection?) to be Active objects?

==&gt; Downstream is pretty straight forward (1 = main VCL thread, 2 and 3 each Active object threads)

higher layer =(1)=&gt; Active&#91;Link Layer Engine =(2)=&gt; MSM state machine&#93; =(2)=&gt; Active&#91;asio TCP Object =(3)=&gt; io_service&#93;

==&gt; Perfectly ok for Active::2 thread to call asio TCP object directly.

==&gt; Upstream is trickier (each upstream thread needs to be awaken to dispatch downstream posted event)

higher layer &lt;=(1)= Active&#91;Link Layer Engine &lt;=(2)= MSM state machine&#93; &lt;=(?)= Active&#91;asio TCP Object &lt;-(3)- ios_service&#93;

==&gt; How does Active::2 fetch and process Event from Active::3?

==&gt; And how does main thread 1 fetch and process event from Active::2?

6) Active::2 may be awaken on Event posted to its Event queue from Active::3 (Active::3 posts to Active::2 queue)?

Active&#91;Link Layer Engine &lt;=(2)= MSM state machine&#93;::Queue23 &lt;=(3)= Active&#91;asio TCP Object &lt;-(3)- ios_service&#93;

7) Main VCL thread may be awaken by a Windows Message triggering a poll of Active::2 upstream queue?

Queue12::Active&#91;Link Layer Engine &lt;=(2)= MSM state machine&#93;::Queue23 &lt;=(3)= Active&#91;asio TCP Object &lt;-(3)- ios_service&#93;

WM_MSG &lt;=(2)= Queue12::Active&#91;Link Layer Engine &lt;=(2)= MSM state machine&#93;

Main::1 — poll —&gt; Queue12::Active::2

higher layer &lt;=(1)= Queue::Active::2

…

Elaborate on this design to see what is most convenient and easy to tread code to implement this threading?

{% endraw %}
