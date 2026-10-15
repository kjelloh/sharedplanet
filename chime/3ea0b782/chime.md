# Todo: Programming - Consider sub-routines (stack-based), Coroutines (heap-based) and Goroutines (Message passing functions) are just three forms of one basic idea of function composition?

```#3ea0b782``` *As of 2017-02-04 14:07*

[mail plain/text](mail.txt)

{% raw %}
So, can we argue that independently of how we implement communication between functions we are still basically programming using function composition (with some added side-effects in between)?

1) Consider sub-routines are functions using stack-frames as the message passing mechanism?

==&gt; Consider the stack frames actually stack-up to a queue of messages (processed in FIFO-manner)?  
==&gt; Consider a stack a stack frame actually carries both the input and the output message?  
…

2) Consider Resumable routines (Coroutines) are functions using heap-frames as the message passing mechanism?

==&gt; Consider a sub-routine (stack-based) may be turned into a Coroutine by putting the stack-frame in a heap-frame instead?  
==&gt; Consider a Coroutine still mixes the input message and the output message in the same frame?  
…

3) Consider Goroutines (or any message passing process) are functions that uses dedicated input and output messages?

==&gt; Consider we may turn any sub-routine and Coroutine into a Goroutine by designing input and output messages from the data in the stack or heap frame?  
==&gt; Consider to design some examples of turning a sub-routine (e.g. a C++ function) into a Coroutine (e.g., using Visual C++ co_xxx constructs) and then turn both into a Goroutine (e.g., an Erlang like process)?  
…

4) Consider the different ways to implement Goroutine message parsing to work efficiently with existing platform messaging mechanism, local multicore considerations and intra-process (networked) message passing?

==&gt; Consider the incompatibility between std::shared_ptr and message passing (who do we model the reference to the data in flight)?

==&gt; Consider we can’t increment the std::shared_ptr reference count for the message in flight (how do we detect and handle a lost message)?  
==&gt; Consider implementing reference counts that times out?

==&gt; If the data in flight does not arrive in time we decrement the std::shared_ptr reference count?  
==&gt; But then, how should the receiver of the data know it has received a message that has ”died”?  
==&gt; Consider a in-flight scheduler that assigns a unique GUID to each data in flight.  
==&gt; The scheduler may then administrate GUID objects that holds a shared_ptr to the data in flight.  
==&gt; On time out the in-flight scheduler then kils the GUID object (the data in flight is now dead)  
==&gt; If a data that died in flight is still received - then the receiver will be told by the in-flight scheduler that the GUID does not longer refer to existing data?  
...

5) Consider the possibility to use C++ Templates to be able to transform sub-routines into Coroutines and Goroutines?

==&gt; The template will NOT be able to modify the body of an ordinary imperatively defined function.  
==&gt; But if a function is defined as composition of functions the template may be able to call them with co_await constructs (bind them with am Await Monad)?

==&gt; Consider it possible to make sub-routines and Coroutines into message passing functions by wrapping them with some message passing wrapper (Rx Message -&gt; unwrap arguments, call function, wrap result in Tx Message, Tx Message)?

==&gt; Consider any wrapper will create a ”diagonal function” (Kleisli Category) and thus resulting embellished functions may be combined (chained) using an appropriate Monad?  
…

…

Consider to elaborate ion this idea that sub-routines, Coroutines and Goroutines may all be viewed as flavors of function composition?  
...

{% endraw %}
