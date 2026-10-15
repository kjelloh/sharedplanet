# Todo: Programming - Consider to discuss what traits a C++ Protocol Framework should have to enable implementation of popular protocols?

```#64352105``` *As of 2016-01-30 14:07*

[mail plain/text](mail.txt)

{% raw %}
Can we gain anything from discussing what traits we would like a C++ Protocol Framework should have to enable some “easy” way of implementing popular protocols?

1) A Protocol seem to be a combination of “message” and “Behaviour”?

2) A protocol seem to define a sender and a receiver side?

3) Many protocol seem to define a “Client” role (initiating messaging session) and a “Server” role acting on client initiatives?

4) Protocol Messages seem to combine “Encoding" and “Implication”?

5) Many protocols are “Stack-able” or represent stacks of sub-protocols (e.g. TCP/IP)?

6) A protocol is a “Messenger” that exchange “Cargo” with the “Other Side”?

==&gt; This reflects the fact that a protocol defines how to talk end exchange data with another actor?

7) A Protocol may be implemented as a black-box “Messenger" that transfers “Cargo” to and from the “other side”?

==&gt; This implies that if one stacks Messengers one get a new Messenger?

8) Protocol Message Representation often require “Cargo” to be obtained and deposited as sub-elements?

==&gt; This reflects the fact that protocols assigns “Implication” to defined elements of Messages (e.g. Header and Cargo Elements of SPDH)

==&gt; BERTLV is an “neutral” encoding format often used by a Protocol to identify tagged elements as having defined implications (and thus content)

9) All Protocols define “Streams” of bits often grouped into octets or other range lengths?

10) It always makes sense to talk about “Downstream” and “Upstream” messaging?

==&gt; Downstream Messaging always meaning from server (responder) to client (requester)?

==&gt; Downstream Messaging within a local Stack always means towards the bitstream sender actor?

==&gt; Confusing: This would mean Stackwise Downstream is in the direction of Message Upstream for Client sender?!

==&gt; Client Stack Downstream corresponds to Server Stack Upstream and both to Message Upstream!

==&gt; Consider to find better terms to refer to Node-to-Node Messaging direction and Layer-to-Layer Stack direction?

11) Consider to design a Protocol Messenger to obtain and deposit Cargo elements using element-key-paths?

==&gt; The element-key-path uniquely defines message Elements and is strongly typed by the Protocol.

==&gt; A Protocol-Daya-Model defines Element Encoding and Cardinality.

…

12) Consider to design the Framework using “Functional” (stateless) programming as far as possible?

==&gt; Stateless means a Framework made up of combinations of functions with no side effects?

==&gt; Each Protocol may then provide a set of Functions that takes a “Cargo Provider” with data to send as input and returns a Future with a Cargo Provider with received data?

protocol::future_response&lt;spdh::message&gt; future_spdh_response = spdh::transieve(spdh_message_provider);

==&gt; In this scenario the protocol “knows” the data model for messages and accepts “Cargo Holders” that exposes elements using element_key_paths?

…?

13) We would like Stack Layers to interact either synchronously or asynchronously?

==&gt; Two Protocols interacting in a stack should we unaware of wether they interact synchronously or asynchronously?

==&gt; Is that even possible?

==&gt; Can we hide this using “C++ Template Magic”?

...

14) We would like to be able to define a “Protocol” using C++ Template Expressions to implement statically (compile time) optimised engines?

==&gt; Using Boost we may use Meta State Machine (<http://theboostcpplibraries.com/boost.msm>) for “Behaviour” and Spirit.Qi or X3 for message parsing?

...

…

Consider to delve deeper into this idea to design a C++ library in which to implement popular protocols using a shared framework of operations and design idioms?

...

{% endraw %}
