# Todo: Programming - Consider to design a good way to connect business logic code to callback to Windows handle message pump

```#80cbd53f``` *As of 2015-12-07 13:03*

[mail plain/text](mail.txt)

{% raw %}
As in the TestBench application the business logic should be separated from the GUI. But how do we design a good way for the GUI to register call-backs with the business logic?

1) The problem is code in the business logic that needs to be executed by the GUI thread.

2) We may have threaded code send windows messages to GUI thread when there is “stuff to process”.

3) By how do we make GUI code (windows message pump) and business logic agree on how and where to set up and exercise these callbacks?

==&gt; How and when does the business logic get to know what windows message to send and to what windows handle to sned it?

==&gt; And how does the Windows thread know what code to process on reception of the windows message?

4) Why not make a queue of functors that the windows thread dispatch and executes?

==&gt; Each post to this process-by-windows-thread queue of functors sends a dedicated windows message

==&gt; The window dispatches the message, pops one functor from the queue and executes it.

==&gt; Whatever code bound to the queued functor will then be executed by the windows thread.

==&gt; For threaded business code this may look like

(1)  B::Queue &lt;== Data &lt;== Active

(2)  W::Queue &lt;== B::ProcessData &lt;==  B

(3) W &lt;== Process_Q &lt;==  W::Queue

(4) W::Execute(W::Queue::First) // Will execute queued B::ProcessData

1: The Active object callbacks to Business object with data to process

2: B queues its own ProcessData as functor to Queue of functors to be processed by windows thread.

3: Windows queue of functors posts a windows message to trigger windows thread to execute the queued functor

4: Receiving windows dispatches the message, pops the first functor and executes it (in effect executes B::ProcessData)

5) Now, how do we guard this mechanism so that queued functor is not bound to erased code when executed by windows thread?

==&gt; B existence is guarded by shared_ptr so it is not deleted until released by executed functor?

==&gt; But this could mean life of business objects are prolonged when not wanted any more (e.g. switching to new TestBench object)?

==&gt; When B is deleted it tells W::Queue to remove all queued processing of B (does not solve if W has already enqueued one functor bound to deleted B)?

…

6) Lets view this as a problem where business logic is executed by a core thread (e.g. the main VCL thread) but has some Active Objects that performs threaded tasks.

==&gt; Each Active Object now needs to callback stuff to process to the core business thread for execution.

==&gt; The core business thread may provide a queue of functors for this.

==&gt; Each Active Object thus callbacks to enqueue a functor to be executed by the main core thread.

==&gt; So, how do we synchronise replacement of one Active Object with another so that core business thread does not dequeue and executes a functor bound to replaced Active Object?

7) Can we design the functor to be able to detect if the bound object is “still there”?

a) We can have the functor reference the Active Object through a weak_ptr?

==&gt; When the functor is executed it will fail to get a shared_ptr to the deleted Active Object?

==&gt; The Active Object must then be able to hold a shared_ptr to its own instance (<http://stackoverflow.com/questions/142391/getting-a-boostshared-ptr-for-this>)

class Y: public boost::enable_shared_from_this&lt;Y&gt; {

…

shared_ptr&lt;Y&gt; p_shared_this = shared_from_this();

…

}

==&gt; The functor should thus make use of a weak_ptr copy to the Active Object to be called by it?

// 151207, Pseudo-code, not yet tried in compiler

*weak_ptr pWeak_Shared_Active(shared_from_this());*

*function&lt;void ()&gt; execute_by_main_functor( &#91;=&#93; {*

*if (shared_ptr&lt;Active&gt; pActive(pWeak_Shared_This.lock()) {*

*pActive-&gt;/\* The process method\*/;*

*}*

*});*

…

8) The only this we then need to do to have the main VCL thread be the executor of the functor is to post a windows message to trigger main VCL thread dequeue and execute the functor?

Elaborate on this idea and consider to build a proof-of-concept and then try it out in the TestBench application?

{% endraw %}
