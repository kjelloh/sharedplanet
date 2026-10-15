# Todo: Programming - Consider to study and understand the HPX C++ Opens Source library for Large System Concurrent Programming?

```#8c5cdedd``` *As of 2017-02-10 16:13*

[mail plain/text](mail.txt)

{% raw %}
It seems Concurrency is the future when Core Density and Processing speed has started to hut the roof? And C++ async, future and await initiatives tries to address these issues which also on a more general level addresses the core Issues of Concurrency (being it from a hardware or software view)?

Consider to study the HPX C++ Open Source library that allows large scale multi-threading and/or distributed concurrency programming of applications?

-1) Consider to try out on what IDE:s we may use HPX?

==&gt; Q: Can we use it with RAD Studio?

**WE ARE HERE...**

1) The HPX Project seems to live here at Github (<https://github.com/gentryx/hpx>)?

==&gt; It seems hpx requires client code to define hpx_main (<http://stellar.cct.lsu.edu/files/hpx_0.9.5/html/hpx/manual/applications.html>)?

...

2) This seem to be a good talk by Hartman Kaiser about HPX (<https://www.youtube.com/watch?v=INS1xKWKBQE&feature=youtu.be>)?

==&gt; At 8:30 he talk about Amdahs Law that seem to define benefits of concurrency (<https://en.wikipedia.org/wiki/Amdahl%27s_law>)?

==&gt; At 56 minutes he shows the async/await generated code scales linearly on any available cores of the platform (e.g. 1…22 cores on a 24 core system)

==&gt; At 57 minutes he shows a ”hack” using a special function ”data flow” that is able to archive the same behavior and efficiency as the async/await compiler generated code?

==&gt; Q: So, is this solution available in the HPX library?

YES (<http://stellar-group.org/2015/06/hpx-and-cpp-dataflow/>)

==&gt; Q: Is it available in some boost library?

3) What can we learn from C++ Concurrency idioms and HPX library to guide the design of Darwinet Distributed Computing mechanisms?

==&gt; Seems we should aim at having Distributed Darwinet Node Functions communicate though futures stored in MIV of a computations sub-domain?

==&gt; sub-domain computation may then return results to higher domains until the final result reaches the main domain?

==&gt; Each sub-Domain may then be seen as a ”virtual computer” with ”threads” being Nodes executing concurrent tasks?

==&gt; Co-Routine Suspend and Resume should be ”easy” by defining them as MIV state changes?

==&gt; A future is ”Ready” when its state changes to Ready (and we may model this as a value in the MIV)?

==&gt; Thus a Node may Suspend execution of a routine until a future ”ready” state associated with the result of the activated routine (local or remote Node)?

==&gt; Consider to draw a diagram for this showing One Darwinet Node activating a Co-routine on another node and wait for a future ready-state of the return value?

==&gt; Node A calls a Wait-able Co-Routine on a remote Node

==&gt; Can we do the call through the MIV?

==&gt; Then, what mechanism can we use to adress what Node that decides to perform the requested operation?

==&gt; Can we imagine accomplishing this by creating a sub-domain with only the calling and called Nodes as members)?

==&gt; Then the Caller can recognize it is being called by seeing that the request written to the MIV is made by another Node?

==&gt; This would mean we must use another mechanism to compute Co-routines locally?

==&gt; How can we process Co-routines locally on multiple cores?

==&gt; Note: We would like to have a mechanism where a Darwinet Co-Routine may be a local one on local cores or on a remoter Darwinet Node?

==&gt; And we use the same mechanism that may be re-sued for both these implementations (run-time decided)?

==&gt; Can we imagine a Delta-mechanism that is really-really efficient for local-node zero-depth-history Concurrent Execution of Co-routines in darwinet?

==&gt; i.e., can we imagine Darwinet to be the preferred choose to implement User-centric Distributed Computation?

==&gt; If so, we have a potential platform in darwinet to implement Web-search, social networking and private clouds for personal digital data?

...

...

4) Consider to move the bullets below to appropriate Todo:s on Resumable Functions (Coroutines) and the co_xxx proposal in C++?

…\* grayed for moving\*

5) This blog is about C++ Resumable Functions using the async and await idiom but based on HPX (<http://meetingcpp.com/index.php/br/items/resumable-functions-async-and-await.html>)?

==&gt; This seems to be the talk on which the blog is based (<https://www.youtube.com/watch?v=INS1xKWKBQE&feature=youtu.be&t=48m30s>)?

6) So, how can we explain (understand) what the C++ standard proposal async-and-await idiom is doing behind the scenes (i.e. how do we ”read” the code)?

a) A function/method is declared using the key-word ”async”.

==&gt; This is now a special method that is resumable

==&gt; It returns a future that will not be ready until the call related to that future has completed (hit its return statement)

b) Inside such a function one may define ”await” statements.

==&gt; Each await-statement wraps the result of the statement into a future.

==&gt; The function ”returns” each time it initiates the processing of an await statement (behind the scenes it generates code to wait for the future returned from the statement)

c) The client calling the async function will get the future returned from the function when it hits its first await (or its final return if no internal await is executed)

==&gt; So, from the callers point it will get a future that will be ready when the function executed all its internal ”await” statements and reaches a return statement.

d) The compiler is now able to generate code that allows the async-function to execute concurrent calls without instantiating a spectate thread and call stack (large overhead)

==&gt; Instead it may optimize the concurrency on the same stack.frame using call-related heap-data and true core-dispatched processing)

7) This seem to be a good talk by Gor Nishanov about a kind of ”philosophy” to understand what we add to make regular function calls into Concurrent Function Calls (<https://www.youtube.com/watch?v=_fu0gx-xseY>)?

==&gt; Consider to follow up on what Gor Nishanov is writing about?

==&gt; We kind-of move the ”return” statement to inside the future the caller gets?

==&gt; The callers future will get ”ready” when the called function actually ends processing and ”returns” the value (sets the future)?

==&gt; Single threaded client::call f means ”Suspend client” and ”Activate f” written caller::S —&gt; callee::A (about 4:45 into talk)

==&gt; Single threaded f::return means ”Yield f back to Caller” and ”Continue Client” written caller::C &lt;— callee::Y

==&gt; To create a Concurrent ”Resumable” Function we add a third operation, namely ”Suspend Callee” and ”Continue Caller” written as caller::C &lt;— callee::Y (at 5:30 into talk)?

==&gt; At 10:00 he shows how to write Concurrent functions using promise&lt;T&gt; and Future&lt;T&gt; in C++11

==&gt; Caller gets a Future and is able to do blocking wait and the callee is able to initiate a threaded operation and return the future.

==&gt; But this this not solve chaining of asynchronous calls without using wait-for-future (blocking) and then call-next-asynchronous-operation.

==&gt; At 11:00 he introduces the proposed future&lt;T&gt;::then(…)

==&gt; This allows chaining of asynchronous calls so that a ready future knows to call the next operation defined in then(next-asynchronous-function).

==&gt; At 15:45 he shows code trying to apply .then but shows this still is not a ”good” feature (impossible to read and maintain code)

==&gt; Use s state-machine with Concurrent callbacks instead!

==&gt; At 19:00 he states - we would like to have concurrent version of the simple synchronous code (just a few lines defining each blocking step)

==&gt; The point he makes is that what we what is to introduce ”suspend and yield” into the function (to define Concurrent steps)!

==&gt; At 21:45 he shows that code generated by ”resumable” function (await idiom) is both faster and smaller :)

==&gt; At 26:30 he introduces the Concept ”Await-able” (Future&lt;T&gt; implements this concept)

==&gt; The statement following ”await” key-word must implement the Await-able concept?

==&gt; From about 33:00 it starts to be uninteresting (he delves into details on how to implement the compiler mechanism for ”await” and apply it for efficient overlapped io)?

==&gt; At 42:00 he lists the design principles and goals of the Compiler Generated Co-Routines.

==&gt; Scale-able (to billions of concurrent Co-Routines)

==&gt; Very Efficient Suspend/Resume operations (negative overhead relative threaded concurrency solutions)

…

==&gt; At 45:15 he lists current and scheduled support

==&gt; Proposal for C++17

==&gt; Experimental in Visual Studio 2015 RTM (Release to Manufacturing) (<https://www.visualstudio.com/en-us/news/vs2015-vs.aspx>)

==&gt; The C++17 proposal seem to be published as N4499 /<http://open-std.org/JTC1/SC22/WG21/docs/papers/2015/n4499.pdf>)?

==&gt; Pre/Post-Kona seem to refer to the ISO C++ Meeting at Kona, Hawai (<http://www.cplusplus-soup.com/2012/03/post-kona-mailing-and-more-libraries.html>)?

8) What compilers has implemented the async/await C++ idioms already?

a) Visual Studio 2015 RC1 seem to provide an implementation already (<https://www.youtube.com/watch?v=_fu0gx-xseY>)?

…

So, what can we learn from studying HPX and how can we relate and apply this knowledge to Asynchronous C++ programming in general and to explicit application like the Darwinet Distributed Computation?

{% endraw %}
