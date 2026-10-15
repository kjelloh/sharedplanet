# Todo: Programming - Consider in what ways algorithms for data distributed in time are just he same algorithms as for data distributed in space with asynchronous message passing?

```#b4296cb4``` *As of 2017-07-26 14:17*

[mail plain/text](mail.txt)

{% raw %}
Could it be that if we separate how functions pass data between each other from how the functions are composed we can make algorithms that may operate on data distributed in space as well as on data distributed in time?

==&gt; Also see “Todo: Programming - Consider sub-routines (stack-based), Coroutines (heap-based) and Goroutines (Message passing functions) are just three forms of one basic idea of function composition?"

==&gt; Also see “Todo: Programming - Consider a "thread" is just message-passing using stack-frames on the same stack (another stack is another thread of stack-frame messaging)?”

==&gt; Also see “Todo: Darwinet - Consider to design multi-threading using Darwinet synchronized shared data as a thought experiment to find design pos and cons”

==&gt; Also see “Todo: Programming - Consider to delve into the research and ideas of Hartmut Kaiser regarding "Concurrency and Threads are evil" and Parallelism is the thing?”

1) It would seem that an algorithm on data distributed in space is time-less (the data is already there and be be processed as defined by its topology in space)

==&gt; Consider a sorting algorithm that aims at ordering data in space?

2) Consider it seems if we make messaging between functions be asynchronous we can use the same functions to operate on data distributed in space?

==&gt; Consider a sorting algorithm that aims at ordering data in time (data arriving in the wrong order are sorted to be passed on in the correct order in time)?

==&gt; Consider the Tcp/IP protocol that re-orders packages that arrive in the wrong order?

…

…

3) Consider how we can “map” algorithms on data with space topology into data with time topology?

==&gt; It seems as long as we talk about data arrays (one dimensional data) then data in space is a actor while data in time is a stream?

==&gt; Then we first have to map data distributed in time into something distributed in space to be able to sort it?

==&gt; Thus, we should be able to identify a set of algorithms that must first map data distributed in time into data distributed in space to apply them?

==&gt; Sorting of data requires data distributed in time to be first mapped to a space distribution (wait for them to arrive)

…

4) Consider what we can learn from defining isomorphisms between first…last (and index) to data distributed in space versus distributed in time?

==&gt; It seems “first” has meaning for data both in space as well as in time?

==&gt; The first data in a vector is the one at index 0?

==&gt; The first data in a stream is the one received at time t0?

==&gt; Data at index n in a vector corresponds to the data received at time tn in a stream?

==&gt; And the last data in a vector is the one at index N which corresponds to the data received at tN from a stream?

…

5) Consider in what way DAGs of data in space corresponds to parallel data processing in time?

==&gt; It seems

6) Consider what it means that we can go where we want in space while in time we an only be at the “now” location?

==&gt; It seems we are free to re-arrange things in space as we please.

==&gt; But to re-arrange things in time we need to first gather things from the past and then re-produce them in the future?

==&gt; Like sorting data that arrives in the wrong order (we need to first wait for all data to be received and then re-emitt them in the correct order)?

==&gt; But then, we seldom do this (as soon as we have the data distributed in space we just press it as fast as we can)?

...

7) Thus, It seems we can identify algorithms that has meaning only in data distributed in time (have no correlation to space distributed data)?

==&gt; Consider a “throttle” algorithm (that reduce it output to data distributed to a defined frequency)?

==&gt; Consider throttling of a GUI update to say 50 frames a second (although the model may be updated much faster)?

…

==&gt; This would correspond a an algorithm in space that filters out data with a defined index separation (e.g. only indexes: (in - in-1) &gt; 50)?

...

...

8) Consider to what degree we can say that a composition of observable streams is in fact a thread of executions?

==&gt; Consider each data is passed forward through the stream which is “the same” as threading of sub-routines (stack_based messaging)?

…

9) Consider if it would be possible to modify RxCpp to in fact apply different message passing between the transducers?

==&gt; For forward-only passing of data we should be able to pass data using sub-routine calls, go-calls or co-routine calls?

==&gt; But then - how do we signal back up-stream to “start over” in case the processing requires things like re-connect?

==&gt; In RxCpp using sub-routine function composition we can do this because each down-stream subscription is able to call up-stream observables?

==&gt; So, for go-routine and co-routine composition we need some similar mechanism to signal up-stream?

==&gt; But there is no way so signal up-stream between go-routines (each call is pure so we can’t affect it whilst it is processing)?

==&gt; The same goes for co-routines?

==&gt; On the other hand - We should be able to mimmic the RxCpp way of re-compotition by implementing the up-stream calls with special up-stream go-rotuine or co-routine equivalence?

...

10) Consider in what ways idioms for asynchronous processing, parallel programming and distributed systems becomes the same pattern when viewed as algorithms on data distributed in time?

==&gt; It seems imperative programming comes from the approach to define algorithms as if data is distributed in time?

==&gt; The computer executes imperative statements in sequence in time?

==&gt; This imperative programming is for defining algorithms on data distributed in time (first do this, then when this happens do that)?

…

==&gt; But with declarative programming we decouple the algorithm from time (we define restrictions on the “order” of data processing without stating when processing should happen)

==&gt; Consider RxCpp that uses the pipe-operator to compose observable streams that defines order constrictions of processing (but leaving actual execution time out of the picture)?

==&gt; Consider such algorithm declarations can operate on both data distributed in tim as well as on data distributed in space?

==&gt; These declarations are concerned only with “next” and “completed” (which has meaning both in space as in time)?

...

==&gt; Consider the Reactive Extensions for Cpp (RxCpp) project (<https://github.com/Reactive-Extensions/RxCpp>)

==&gt; It seems we declare algorithms using the pipe-operator ‘|’?

**==&gt; It seems RxCpp resembles RaftLib but using sub-routines for message passing (RaftLib uses go-routine/Erlang asynchronous message passing)?**

…

==&gt; Consider to study the ReactiveX project for leads into the Reactive Programming idiom (<http://reactivex.io>)?

==&gt; Consider the RaftLib project (<http://www.raftlib.io>)

==&gt; RaftLib seems to be about composing “kernels” having in and out-ports into pipe and parallell algorithms?

==&gt; The “&gt;&gt;” operator seems to pipe kernels (out to in) together?

==&gt; A map seems to hold the kernel composition together?

> > /\*\* make a map object \*\*/

> > raft::map m;

> > /\*\* add kernels to map, both hello and p are executed concurrently \*\*/

> > m += **hello** &gt;&gt; p;

> > /\*\* execute the map \*\*/

> > m.exe();

==&gt; hello and p are raft::kernel instances.

> > class hi : public raft::kernel {  
> > public:  
> > hi() : raft::kernel() {  
> > output.addPort&lt; std::string &gt;( "0" );  
> > }

> > virtual raft::kstatus **run**() {  
> > output&#91; "0" &#93;.push( std::string( "Hello World\\n" ) );  
> > return( raft::stop );  
> > }  
> > };  
> > ...  
> > /\*\* instantiate print kernel \*\*/  
> > raft::print&lt; std::string &gt; p;  
> > /\*\* instantiate hello world kernel \*\*/  
> > hi **hello**;

***==&gt; It seems RaftLib resembles RxCpp using go-routines for message passing?***

==&gt; Consider the Hpx Cpp project seems to live here (<https://github.com/STEllAR-GROUP/hpx>)

==&gt; It seems HPX C++ library use imperative semantics (<https://stellar-group.github.io/hpx/docs/html/hpx/tutorial/examples/hello_world.html>)?

==&gt; Thus RxCpp and RaftLib has more in common in that they implement declarative semantics to compose asynchronous operations?

==&gt; Each HPX application (here the hello_world) knows how to execute itself in a distributed manner?

> > &gt;./bin/hello_world [--hpx:threads](https://stellar-group.github.io/hpx/docs/html/hpx/manual/init/commandline.html) 2

Is stated to yield…

```
hello world from OS-thread 1 on locality 0
hello world from OS-thread 0 on locality 0
```

==&gt; Which seems to be this imperative code executing in two different instances of the application?

> > std::size_t hello_world_worker(std::size_t desired)

> > {

> > // Returns the OS-thread number of the worker that is running this

> > // HPX-thread.

> > std::size_t current = hpx::get_worker_thread_num();

> > if (current == desired)

> > {

> > // The HPX-thread has been run on the desired OS-thread.

> > char const\* msg = "hello world from OS-thread %1% on locality %2%";

> > hpx::cout &lt;&lt; (boost::format(msg) % desired % hpx::get_locality_id())

> > &lt;&lt; std::endl &lt;&lt; hpx::flush;

> > return desired;

> > }

> > // This HPX-thread has been run by the wrong OS-thread, make the foreman

> > // try again by rescheduling it.

> > return std::size_t(-1);

> > }

> > // Define the boilerplate code necessary for the function 'hello_world_worker'

> > // to be invoked as an HPX action (by a HPX future). This macro defines the

> > // type 'hello_world_worker_action'.

> > HPX_PLAIN_ACTION(hello_world_worker, hello_world_worker_action);

==&gt; It seems HPX is a C++ library to program for the ParalleX implementation Hpx?

> > “*HPX is a C++ Standard Library for Concurrency and Parallelism*"

==&gt; It seems Hpx is a run.time system for interprocess communication (<https://stellar-group.github.io/hpx/docs/html/hpx/tutorial/intro.html>)

> > “*High Performance ParalleX (HPX) is the first runtime system implementation of the ParalleX execution model. The HPX runtime software package is a modular, feature-complete, and performance oriented representation of the ParalleX execution model targeted at conventional parallel computing architectures such as SMP nodes and commodity clusters.*"

==&gt; Thus, It seems Hpx is all about Erlang-like interprocess programming (using messaging from a set of possible interprocess mechanisms)?

==&gt; And ParallelX is an execution model (Hpx being an implementation of this model)?

> > “*ParalleX is a new parallel execution model that offers an alternative to the conventional computation models, such as message passing. ParalleX distinguishes itself by:*

> > *• Split-phase transaction model  
> > *  
> > *• Message-driven  
> > *  
> > *• Distributed shared memory (not cache coherent)  
> > *  
> > *• Multi-threaded  
> > *  
> > *• Futures synchronization  
> > *  
> > *• Local Control Objects (LCOs)  
> > *  
> > *• Synchronization for anonymous producer-consumer scenarios  
> > *  
> > *• Percolation (pre-staging of task data)*"

==&gt; Consider this thread as good leads into inter process messaging options (<https://stackoverflow.com/questions/35367816/hpx-minimal-two-node-example-set-up>)?

…

…

Consider to delve into this idea that we may learn interesting things by finding patterns similar between processing data distributed in space with processing of data distributed in time?

...

{% endraw %}
