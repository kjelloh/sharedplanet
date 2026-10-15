# Todo: Programming - Consider to model Protocol Stacks using State-Machine-Based Tagged-Range-Tree Transforms?

```#714507a2``` *As of 2016-03-17 12:32*

[mail plain/text](mail.txt)

{% raw %}
Consider to elaborate on the idea of modelling Protocol based messaging using State-Machine-Based Tagged-Range-Tree Transforms?

1) Consider to model the Protocol Rules using an FSM?

==&gt; The State Machine may then be used to define What-and-When the Protocol requires to do something?

2) Consider to model Messaging using Frames represented as Tagged-Range-Trees

==&gt; A Tagged-Range-Tree identifies elements as Ranges carrying encoded elements of the message identified with a unique tag.

3) Consider to define a model for Universal Encoding and Decoding or Message Frames?

==&gt; Encoding a message means creating a Tagged-Range-Tree, attach it to a Value Provider (tag-path based) to Encode the tree into a stream.

==&gt; Decoding a message means parsing a Frame and represent it as a Tagged-Range-Tree, attach it to a Value Receiver (tag-path-based) to Decode it into internal storage?

==&gt; Consider to implement a Value-receiver that is itself a Tagged-Range-Tree (to enable it to be forwarded upp-stack)?

==&gt; Note: In Framed Messaging Protocols the result of Decoding should NOT result in a Tagged-Range-Tree as the pay-load will be represented as an anonymous vector of bits?

==&gt; This means the Value Receiver only needs to “know” what element that is the payload and define it to be forwarded up-stack?

Model of “Send” (US = Upp-stack. DS = Down-Stack)

-----------------&gt; Value Provider (tag-path-based)

| |

| v

USFrame —&gt; **Protocol Engine** —&gt; DSFrame

Model of “Receive"

------------------ Value Receiver (tag-path-based)

| ^

v |

USFrame &lt;— **Protocol Engine** &lt;— DSFrame

==&gt; Consider to have the Value-Receiver and Value-Provider use an Element-Representation-List (tag-path-based) to “Know” the type and encoding of each element?

4) Consider to relate the Protocol Stack design to the Iterator or Generator idiom of Ranges?

==&gt; Also see “Todo: Programming - Consider to study the two Range concepts Iterator and Generator?”

==&gt; Also see “Todo: Programming - Consider to implement Message Encoding/Decoding as a C++ template grammar that looks like the Element Tables used in Swedbank Specifications?”

==&gt; Could we imagine the Protocol Engine to be a “Frame Generator” or a “Frame Iterator” (pros and cons)?

==&gt; Could we imagine the Frame event handler of the Protocol Engine (FSM) to engage a "Range Iterator” or “Range Generator” (pros and cons)?

**WE ARE HERE...**

5) Consider to study the “ArrayView” concept as an alternative to Range-trees as indicated in this TCP/IP frame example, about 12 minites in (<https://www.youtube.com/watch?v=pxREfC9mhpI>)

==&gt; An ArrayView does not own the array.

==&gt; When building a frame of known size (as a TCP/IP Frame) one may use an ArrayView of the fixed end result and pre-pend data for each layer until one has the full TCP/IP frame?

…

==&gt; Are ArrayViews kind-of the same thing as a Range (or what is the different)?

6) Consider to make Protocol Engines Stackable using a shared “Context” to intercommunication?

==&gt; Many protocol stacks defines dependence between protocol layers and that requires a shared Context?

==&gt; Consider to identify dependencies that we may (and should) solve using event delegation through the stack (dependent layer acts on the event)?

…

^

|

v C

Protocol Engine 1 &lt;———&gt;  o

^ n

| t

v e

Protocol Engine 1 &lt;———&gt; x

^ t

|

v

==&gt; Consider the Stack of Engines to be a Generator of Frames thus being able to sit at top of stack calling Protocol Engines as Consumers (idea from Range Generators, See above)?

==&gt; Then the “Context” could be stack variables (avoid Heap storing of Context)?

…

**WE ARE HERE...**

…

Consider to elaborate and this idea and try some proof-of-concept for a C++11/14 library to prove the concept?

a) Does this model hold to

{% endraw %}
