# Todo: Programming - Consider to make Asio easier to understand with do_in_future(Operation, Handler) semantics?

```#a00c5e58``` *As of 2016-09-07 14:32*

[mail plain/text](mail.txt)

{% raw %}
After having tried to explain the Asio interface behind-the-scene actions and expected action it seems this interface is just a bit to opaque?

1) Consider to define operations on the ioservice objects that clearly state that we only queue operation for future executions and handler callback?

==&gt; Consider ioservice.do_in_future(operation,handler)?

2) Consider to define a wrapper that implements this interface for the Asio library?

==&gt; Consider to wrap ioservice with an Executor?

> Executor myExecutor;  
> myExecutor.schedule_later(operation).then(handler);

==&gt; Consider to wrap async_xxx calls in functor factories?

> void onAccept(Error& error);  
> myExecutor.schedule_later(asio::Accept(mySocket)).then(onAccept);

==&gt; Where asio::Accept(Socket&) returns a function object that returns and error code

> Executor::Run () {  
> while (!queue.empty()) {  
> auto operation = queue.pop();  
> operation.then(operation()); // Call handler with result of operation  
> }  
> }

3) …

…

Consider what it would take to warp asio in this way to make code easier to read?

...

{% endraw %}
