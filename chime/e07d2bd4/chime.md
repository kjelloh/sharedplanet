# Todo: Programming - Consider a "thread" is just message-passing using stack-frames on the same stack (another stack is another thread of stack-frame messaging)?

```#e07d2bd4``` *As of 2017-02-09 13:37*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good model to actually view a ”thread” as stack-frame-based message passing between functions on the same stack?

==&gt; Also see ”Todo: Programming - Consider a Language Semantics where we can use abstractions to model subroutines, coroutines and coroutines as well as how we engage with them?”

==&gt; Also see ”Todo: Programming - Consider sub-routines (stack-based), Coroutines (heap-based) and Goroutines (Message passing functions) are just three forms of one basic idea of function composition?"

1) Consider to a thread is stack-frame messaging passing between routines (processes) that are suspended and resumed in a ”subroutine” manner?

==&gt; Consider this talk ”CppCon 2015: Gor Nishanov “C++ Coroutines - a negative overhead abstraction”" (<https://www.youtube.com/watch?v=_fu0gx-xseY>)?

![](<Subroutine suspend-activate-yield model.tiff>)

==&gt; S = Suspend (remember state and stop executing)

==&gt; A = Activate (Callee State Execution in response to a trigger from caller)

==&gt; Y = Yield (back to caller)

==&gt; C = Terminate (but what wth the C, Cancel?)

==&gt; S+A = subroutine call

==&gt; C+Y = subroutine return

![](<Coroutine suspend-yeld-resume model.tiff>)

==&gt; S+Y (Suspend and yield to caller) is the additional ability of resumable routines (coroutines).

==&gt; Note: Now the caller S+A (Suspend and Activate) means the coroutine will resume execution in the state it suspended.

==&gt; So, caller and callee may take turns executing

----------------| -------------------------

| | | |

| v v |

| caller::Suspend  —&gt;  Callee::Activate (Resume) |

| caller::Activate (Resume) &lt;—  Callee::Suspend_and_Yeld |

| | | | |

----------------- | ————————————

Request/Response Messaging

...

2) Consider a ”thread” can be viewed as an execution mechanism applying Suspend+Activate (request) and Cancel+Yield (response) using stack-frames for messaging?

result = f(x) caller::suspend —&gt; message: x —&gt; f::activate, f::cancel_and_yeld —&gt; message: f(x) —&gt; caller::resume

...

3) Consider in what ways we can use this message model as a base to understand subroutines, coroutines and goroutines as flavors of a common meta-model of processes exchanging messages?

==&gt; Consider to apply a general model of two routines exchanging request-response messages and implementing suspend, activate, cancel, yield and resume?

----------------| -------------------------

| | | |

| v v |

| caller::Suspend  —&gt;  Callee::Activate (Resume) |

| caller::Activate (Resume) &lt;—  Callee::Suspend_and_Yeld | // Subroutines can’t do this!

| caller::Activate (Resume) &lt;—  Callee::Cancel_and_Yeld | // terminate

| | | | |

----------------- | ————————————

Request/Response Messaging

==&gt; Consider the cases where caller and callee are subrotuines, coroutines and goroutines?

==&gt; Consider we can make any combination work by applying appropriate messaging and activate,resume and yield implementations?

**==&gt; It seems a subrotuine and coroutine share its state (its frame) with the caller?**

**==&gt; It seems a goroutine shares nothing with its caller?**

**==&gt; It seems subrotuines and coroutines uses the shared state to exchange messages with the caller?**

**==&gt; It seems gorotutines uses call and response channels to exchange messages?**

==&gt; Consider S+A (Suspend+Activate) can be defined also also to activate a Coroutine and a Goroutine?

call f(x) expands to: caller::suspend —&gt; message: x —&gt; f::activate

subroutine::suspend + coroutine::activate

==&gt; Works if we just apply the appropriate caller::suspend (store state in stack-frame)?

==&gt; In this case coroutine::activate must accept a heap-frame shared with the caller (coroutine must store its state to live on after yield)?

==&gt; Thus, the message: x must live in the heap-frame (its part of coroutine state) ?

**==&gt; Note: A coroutine shares its state instance with the caller (used by caller to interact with coroutine)?**

subroutine::suspend + goroutine::activate

==&gt; Works if we just apply the appropriate caller::suspend (store in stack frame)

==&gt; In this case goroutine::activate must accept a channeled message

==&gt; Thus the goroutine gets its own copy of the message to store in its ”process” local memory?

**==&gt; Note: A goroutine shares nothing with the caller (goroutine can be executing on completely remote hardware)**

==&gt; Consider callee C+Y (Cancel and Yield) is trivial for coroutine and goroutine?

f(x) {return result} expand to: f::cancel —&gt; message: result —&gt; caller::resume

coroutine::cancel + subroutine::resume

==&gt; Works if we just apply appropriate caller::resume (needs to accept final value on the shared heap-frame)

==&gt; It seems we require the caller to detect that the coroutine has canceled and thus delete the heap-frame (after having acquired the returned value)?

goroutine::cancel + subroutine::resume

==&gt; Works if we just apply appropriate subroutine::resume (needs to accept a message copy from callee response channel)

==&gt; It seems we require the caller to detect that the goroutine has canceled and thus close the channel (after having acquired the return value)?

==&gt; Consider we may use a buffered stateful (open/closed state) channel that is garbage collected when it is empty and closed (the goroutine may thus close the channel after having sent the response)?

==&gt; Consider callee S+Y can be defined for both coroutines and goroutines?

f(x) { yield} expands to: callee::yield —&gt; message: ?? —&gt; caller::resume

coroutine::yield + subroutine::resume

==&gt; Works if we can define what message::?? carries?

==&gt; For yield = await (yield back to caller while waiting for a future event) we need message: future&lt;x&gt; (something the caller can recognize as not yet available)?

==&gt; For yield = yield y (yield a value back to caller) we need message: y (something the caller can recognize as one value with more to come)?

==&gt; goroutine::yield + subroutine::resume

==&gt; Works the same ways as for coroutine above (but the messaging must be made over the response_channel using messages that encode a value or a future value)?

==&gt; It seems here coroutines and goroutines differ only in the message scheme?

4) Consider some C++ code to try out possible semantics to be able to compose with subrotunes, coroutines and gorotutines?

==&gt; Consider this approach?

> struct Subroutine {  
> template &lt;typename X&gt;  
> auto operator()(X x) const { return 1;} // Dummy stacked fucntion  
> };  
> struct Coroutine {  
> template &lt;typename X&gt;  
> auto operator()(X x) const { return 1;} // Todo: Implement heap-based frame to return the value (coroutine style)  
> };  
> struct Goroutine {  
> template &lt;typename X&gt;  
> auto operator()(X x) const { return 1;} // Todo: Implement message copying thriough channels (goroutine-style)  
> };

> template &lt;typename Caller, typename Callee&gt;  
> auto combine(Caller caller, Callee callee) {}; // Primary template never used

> template &lt;&gt;  
> auto combine&lt;Subroutine,Subroutine&gt;(Subroutine caller, Subroutine callee) {  
> return &#91;=&#93;(auto x) {  
> return caller(callee(x));  
> };  
> };

> template &lt;&gt;  
> auto combine&lt;Subroutine,Coroutine&gt;(Subroutine caller, Coroutine callee) {  
> return &#91;=&#93;(auto x) {  
> return caller(callee(x)); // Todo: implement some example heap-based shared state  
> };  
> };

> template &lt;&gt;  
> auto combine&lt;Subroutine,Goroutine&gt;(Subroutine caller, Goroutine callee) {  
> return &#91;=&#93;(auto x) {  
> return caller(callee(x));  
> };  
> };

> int main(int argc, const char \* argv&#91;&#93;) {  
> Subroutine sub_f;  
> Coroutine co_f;  
> Goroutine go_f;  
> combine(sub_f,sub_f)(3);  
> combine(sub_f,co_f)(3);  
> combine(sub_f,go_f)(3);  
> return 0;  
> }

==&gt; Consider to apply boost::coroutines for struct Coroutine and still make combine work?

==&gt; Consider to apply boost::fiber to implement Goroutine and still make combine semantics to work?

==&gt; Consider it is ok for now to block on actual invokation of combined function (we may later provide ways to turn the whole combine-chain to a sub-,co- or go-routine)?

...

…

Consider to elaborate on this idea to model a thread as function-messaging using stack-frames?

...

{% endraw %}
