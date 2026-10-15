# Todo: Programming - Elaborate on the "Message Pump" Idiom and find similarities between Windows Messaging and Active Object design

```#1d8f65b8``` *As of 2015-12-02 13:52*

[mail plain/text](mail.txt)

{% raw %}
It seems we would benefit from realising how similar many thread-2-thread messaging is and that the preferred design is the “Message Pump” design and that this is actually what Windows Messaging also uses.

(1) It seems we have the following variants of thread-messaging (W being a window and A being an Active Object)?

a) W &lt;- A : (Windows::MessagePump &lt;— Active)  
b) W -&gt; A : (Windows —&gt; MessagePump::Active)

c) A1 &lt;- A2 : (Active1::MessagePump &lt;— Active2  
d) A1 -&gt; A2 : (Active1 —&gt; Active2::MessagePump)

2) Now, what we would like is to view all Active Objects as “equals” when it comes to passing messages?

==&gt; We would like W to signify an A where messages are dispatched by the Windows thread, not a spawned Active Object Thread?

W &lt;- A  
————  
A1::Q &lt;- A2 // A2 posts to A1 Queue  
W::Q &lt;- A1::Q // A1 Queue posts “process trigger” to Windows Queue  
W -&gt; A1::ProcessMessages // Windows thread calls A1 to Process its queued messages

3) In this way Active Objects differ only in who executes its Message Pump?

a) An Internally threaded A uses a non-process-triggering Queue and an internal thread that dies wait-dispatch-process processing of the queue  
b) A Windows Threaded A uses a process-triggering Queue and and expects an external thread to come and dispatch-process the queue.

4) To make this work we need a mechanism so that the thread that receives the Windows Message knows what A::ProcessMessages to call?

==&gt; It is tempting to provide the A::ProcessMesages as a functor in the Windows Message? But then, how do we make sure that A exists when processed?  
==&gt; We may provide an A Id in the Windows Message and have the windows thread look up the A to call? When then need an A Registry?  
...

5) Each Windows Window implements a message pump executed by a call to ProcessMessages ()  
6) The Active Object (Herb Sutter) also hides the threaded processing behind a queue of messages.  
7) Thus, thread-to-thread main interaction may be seen as always occurring by thread_A posting to the message queue of thread_B.  
8) Posting to windows queue is made as WM-Messages as defined by windows (id + data) and adressed to a windows handle.  
9) Posting to an Active Object is made by calling Send() of the messages instance.  
10) Do we need Actors to maintain a list of callers to know where to post the respons to an executed message (functor)?  
==&gt; Compare with Herb Sutters design for callback from Active Objects (http://www.drdobbs.com/cpp/prefer-using-futures-or-callbacks-to-com/226700179?queryText=%2522Active%2BObject%2522)?

…

So, what conclusions can we draw, design wise, from the model of inter-thread-messaging?

a) Can we design a mechanism that allow Active Objects to message each other in a way that enables them us the same interface regardless if they are messaging another Active Object or a Windows Handle Message Queue?  
b) Could we in both cases post a functor (to be executed by the receiver)?  
==&gt; Is this even possible in a secure stable way using a Window Message (How do we secure that the functor is not bound to data that has been destroyed)?  
...

{% endraw %}
