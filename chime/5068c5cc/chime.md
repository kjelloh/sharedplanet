# Todo: C++ - Consider to understand Reactive Programming from the semantics and design of RxCpp (Reactive Extensions for Cpp)?

```#5068c5cc``` *As of 2017-02-09 13:49*

[mail plain/text](mail.txt)

{% raw %}
It seems like a good idea to delve into RxCpp design and semantics to get more understanding of what actually makes Reactive Programming tick?

1) Consider this talk ”Kirk Shoop, Adding async algorithms to std” (<https://www.youtube.com/watch?v=Re6DS5Ff0uE>)?

==&gt; At 50:00 it seems he defines the contract of ”receivers” to behave as ”three-track-functions” (they accept {value, completion, error/excpetion} in Scot Wlaschin termonology)?

==&gt; See ”[Todo: Programming - Consider to understand Monoids and Monads using the "Railway Oriented Programming" model?](../e359b4d0/chime.md)”

==&gt; BUT: RxCpp does not model this as Monad that lifts function to take this triple, instead they chain objects of type receiver that provide the function triple {on_value, on_termination, on_error}?

![](<RxCpp Three-track Receiver.tiff>)

==&gt; At 44:30 he seems to introduce ”subscription” as an object made to control stream lifetimes (enabling streams to end on in-stream end, process done or error)?

==&gt; In this example he states that he makes subscription member of receiver (although actual RxCpp does it a little differently)?

==&gt; Anyhow, it seems this enables the receiver to interact with its subscription to control the life-time of itself (and thus implicitly of the whole stream transform chain)?

![](<RxCpp stream lifetime control though subscription instances.tiff>)

==&gt; It seems the insert/erease subscription is for nesting of subscriptions?

==&gt; It is not totally clear what insert(stopper) does (a way to propagate stop in the reverse order of calling the member stop?)?

==&gt; He actually states that it is also to break circular references that may occur in asynchronous chains?

==&gt; It seems the make_state is for creating heap-located state to have state live during asynchronous scope?

==&gt; At 50:30 he shows what seems like a good illustration of both construction order, bind order, call order on error and destruction?

![](<RxCpp construct, bind, error, destruct example.tiff>)

==&gt; It seem to show clearly how the lazy-chain is constructed ”down-stream” while the binding is made ”up-stream”?

==&gt; Note how the special predicate always_throw (used for this example to introduce an exception in the chain) terminates processing (none of the 0…9 inst are processed)?

==&gt; Note how the error (exception) still propagates through the chain and gets handled by printto!

...

2) Consider this interactive examples showing transformation of events-in-time-streams (<http://rxmarbles.com>)?

![](<Reactive Stream Merge.tiff>)

==&gt; In this case two streams of events in time is merged (a merged value is generated to the merged stream each time any of the input streams gets a new value)?

==&gt; See example RxCpp code below for merge.

...

3) It seems the ”pipe” operator is used to chain asynchronous event stream transforming actions and kick of processing by the last function being a ”subscriber” to the chained functions?

==&gt; It seems ”function” chained by the pipe-operator creates a new ”stream” - in effect making processing ”lazy” (nothing happens until the created function is actually called)

==&gt; It seems it is the last function in the chain (the subscriber) that implements the actually calling (staring to process the stream)?

4) It seems we need to kick-of the stream chaining by create-and-publish an observable (that may then be chained into new published observables)?

==&gt; Consider this example (

> int main() {  
> auto keys = rx::observable&lt;&gt;::create&lt;int&gt;(  
> &#91;&#93;(rx::subscriber&lt;int&gt; dest){  
> for (;;) {  
> int key = std::cin.get();  
> dest.on_next(key);  
> }  
> }).publish();  
> auto a = keys.filter(&#91;&#93;(int key){return std::tolower(key) == 'a';});  
> auto g = keys.filter(&#91;&#93;(int key){return std::tolower(key) == 'g';});  
> a.merge(g)  
> .subscribe(&#91;&#93;(int key){  
> std::cout &lt;&lt; key &lt;&lt; std::endl;  
> });  
> // run the loop in create  
> keys.connect();  
> return 0;  
> }

==&gt; It seems keys.connect() initiates observation of the published observable keys ( rx::observable&lt;&gt;::create&lt;int&gt; … .publish())?

==&gt; It seems merge is a standard algorithm and thus a member of each observable stream (in this case stream a)?

a.merge(g) // creates a merged observable stream of a and g?

4) It seems Reactive Extensions for C++ is functional to the extent each value transform operates on immutable values?

…

5) Consider to understand Reactive Extensions for C++ from the view of Functional concepts like Monad. Monoids, bind and map?

==&gt; The library does not seem to use these terms at all?

==&gt; It would seem the pipe-operator on stream transforms form a monoid (the result is a new stream transform)?

==&gt; It seems RxCpp does not use the idiom to lift functions to operate on lifted values (instead it composes with function tuples {on_next, on_terminate, on_error})?

observable transform transform subscriper

on_next on_next on_next

on_terminate on_terminate on_terminate

on_error on_error on_error

…

…

Consider to delve into the design and usability of RxCpp in particular and Reactive Extensions in general?

...

{% endraw %}
