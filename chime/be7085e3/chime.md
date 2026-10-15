# Todo: Darwinet - Consider to make the node a two-threaded Zero MQ messaging peer with a separate client front-end that aggregates it?

```#be7085e3``` *As of 2017-07-31 22:20*

[mail plain/text](mail.txt)

{% raw %}
It seems a good bet to get the first Darwinet Node up and running is to make it a two threaded Zero MQ messaging peer and have an entry-point threaded client aggregate it?

1) Consider this talk “Microservice Swarms: Decentralized Discovery and Scaling - Allen Holub” with good leads into swarming micro services and Zero MQ service-to-service messaging (<https://www.youtube.com/watch?v=GVO09zcFNtY>)?

==&gt; He seems to be talking about a soon-to-come ”micro service swarming framework” (janus?) hinted to be released as open source here (<http://holub.com/allenholub/>)?

> ”*He's currently working on Janus, a soon-to-be-released open-source microservice framework based on lightweight messaging.*"

==&gt; Consider to reach out to him (<https://www.linkedin.com/in/allenholub/>) about C++ include_os micro services and Darwinet P2P shared Tha with eventual consistent view (instead of state)?

==&gt; Also see ”Todo: Darwinet - Consider to motivate survival-of-fittest-view with the argument that views always shows meaningful state where a merge algorithm will always create an invalid state?”

...

==&gt; At 17:50 he seems to start praising Zero MQ for swarming micro services (<https://youtu.be/GVO09zcFNtY?t=1069>)?

==&gt; At 27:50 he seems to state that Zero MQ exists for all major languages and platforms (<https://youtu.be/GVO09zcFNtY?t=1673>)?

==&gt; Zero MQ seems to be available also for Swift apps on iOS, Watch OS, TV OS etc (<https://github.com/azawawi/SwiftyZeroMQ>)?

==&gt; At 32:40 he shows Java code that should map very well to Cpp code (<https://youtu.be/GVO09zcFNtY?t=1959>)?

==&gt; Unless the Cpp MQ I end up using is integrated into say asio-like interface (would be great)?

...

2) Consider for a Darwinet Node we would need one Tx thread and one Rx heard to keep peers connected for Delta messaging using Zero MQ?

…

3) Consider we choose to have the entry point of the Client application aggregate the two-threaded Darwinet Node?

==&gt; Consider the entry-point is normally the Ux thread so we need thread safe posting of messages to and from the Darwinet Node?

...

4) The Zero MQ for C++ seems to live here (<https://github.com/zeromq/libzmq>)?

==&gt; Or, maybe this is a higher version Zero MQ Cpp fork (<https://github.com/zeromq/cppzmq>)?

==&gt; Actually - Consider any of the listed Cpp forks listed here for version &gt; 3.0 (<http://zeromq.org/bindings:cpp>)?

==&gt; Zero MQ Version 4 seems to include CurveZMQ - Security for ZeroMQ (

==&gt; Also see the Zero MQ org home (<http://zeromq.org>)?

...

==&gt; Zero MQ seems to be available also for Swift apps on iOS, Watch OS, TV OS etc (<https://github.com/azawawi/SwiftyZeroMQ>)?

5) Consider to use “CurveZMQ - Security for ZeroMQ” for P2P encryption security in Darwinet networks (<http://curvezmq.org>)?

==&gt; It seems to be part of Zero MQ 4.x?

> “*Implemented in ZeroMQ 4.x for point-to-point security.*"

==&gt; It seems to exist as a C library (<https://github.com/zeromq/libcurve>)?

==&gt; Which is OK for such a low level functionality?

6) Consider to check out &lt;include_os&gt; again to see if we can aggregate a darwinet node on a server as a micro service (<http://www.includeos.org>)

==&gt; The GitHub project seems to be alive and fresh (<https://github.com/hioa-cs/IncludeOS>)?

==&gt; Or, consider to use the “Acorn Web Server Appliance running on IncludeOS." (<https://github.com/hioa-cs/IncludeOS/tree/master/examples/acorn>)?

==&gt; It seems to be a small micro service that hosts a web server for static html-files and a RESTful API fro JSon data exchange?

> > “ *• Serve static content from a disk with just a few lines of code.*  
> > *• RESTful API service reading and posting JSON.*"

==&gt; This seems to be an example web page hosted on an Acorn web service in a includeos micro service (<http://acorn2.unofficial.includeos.io>)?

> > “*Written in C++ and running on the IncludeOS unikernel, Acorn is a highly efficient web application with direct access to the library operating system's facilities*”

==&gt; Consider for a micro service Darwinet Node we do NOT need an Ux thread (we can have the entry-point thread run as the Tx-thread of the Node (having it spawn the Rx thread)?

...

…

Consider to try this path to getting a Darwinet Node up and running?

{% endraw %}
