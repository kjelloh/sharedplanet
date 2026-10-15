# Todo: programming - Consider a "View" is the same thing as a callback interface?

```#28ab884c``` *As of 2016-05-14 17:09*

[mail plain/text](mail.txt)

{% raw %}
Could we imagine the idea of a View to be a replacement (being the same as) a callback interface?

1) Consider the caller to a Reactor to provide an optional View for any related update of the progress and result of the requested operation?

Client (Reactor)  &lt;— —&gt;  Server (Reactor)

—&gt; server.operation(**client.viewer**)

…

// operation is carried out

viewer.onChanged(Par…) &lt;— // Operation updates the provided view

…

viewer.onChanged(Par…) &lt;— // Operation ends

==&gt; Consider the Viewer to also be a Reactor?

==&gt; In that case any onChanged call will trigger asynchronous processing on the Client side?

2) Consider the client to create Views as shared objects but provide weak-pointers to the Server?

==&gt; In that case the server will detect View deletion by being unable to acquire a shared pointer to the view?

Client (Reactor)  &lt;— —&gt;  Server (Reactor)

shared_ptr&lt;ViewX&gt; v  —&gt; server.operationX(**v**)

...

3) Consider the Server to create shared operation objects but provide them to the Client as weak-pointers?

==&gt; In that case the Client may detect when server operation objects are deleted by being unable to acquire a shared pointer to it?

Client (Reactor)  &lt;— —&gt;  Server (Reactor)

shared_ptr&lt;ViewX&gt; **v** shared_ptr&lt;OperationX&gt; p

weak_ptr&lt;OperationX&gt; **p** &lt;— server.operationX(**v**)

weak_ptr&lt;ViewX&gt; v

...

3) Consider to define if Server Operations should be terminated if there are no viewer observing their progress?

==&gt; If the operation has side effects then it must carry on without viewers?

==&gt; If the operation is pure functional (has no side effect) then it may terminate if there are no viewers (no one interested in the progress nor result)?

4) Consider how to apply David Sankel C++ Functional Reactive Programming with Viewable (Imperative) Operations?

==&gt; So, what would it mean to view a pure function (a function with no side effects)?

==&gt; Do we have to define the Viewer onChange calls as calls to pure functions?

==&gt; This would mean we are not allowed to update the state of the screen, i.e. the User Interface in the onChanged calls?

==&gt; How may we allow Client and Server Reactors be “Functional Reactors” by using David Sankel proposed push or pull imperative interface?

==&gt; He seem to start talking about interacting with imperative code at 45:45 into the talk (<https://www.youtube.com/watch?v=tyaYLGQSr4g>)?

…

Consider to elaborate on this idea of client and server Reactors sharing client side View and server side Operation using weak-pointers and a View being equal to a callback interface?

...

{% endraw %}
