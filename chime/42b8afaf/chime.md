# Todo: Programming - Consider to design lazy (two-pass) Protocol Message Encoding and Decoding using tagged-range-ASTs?

```#42b8afaf``` *As of 2016-03-20 19:35*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea for many reasons to make Protocol Message Encoding and Decoding “lazy” by always having the first step processing a tagged-range-AST (Abstract Syntax Tree)?

1) Mapping a message to decode into tagged-range-ASTs enables parallel decoding of sub-elements?

==&gt; The idea sprung to life watching the importance of parallelise code as described in “Todo: Programming - Consider to delve into the research and ideas of Hartmut Kaiser regarding "Concurrency and Threads are evil" and Parallelism is the thing?

==&gt; mapping a Range into sub-ranges may for some encoding require sequential processing (e.g. to encode sentinel separated elements)?

==&gt; But then each sub-range are fixed in location in the message and may be processed in parallel.

2) Consider to delve into understanding to what degree a message decoding may be parallelised?

==&gt; Each time a sub-element range is identified we may parallelise processing sub-elements of that range and finding following elements?

==&gt; At least as long as sub-element locations of the identified elelement does not depend on elements following it?

==&gt; What can we say about Element locations that depend on preceding (already mapped) elements?

==&gt; E.g. the Bitmap elements of an ISO 8583 Message?

==&gt; It seems this does not impose concurrency as we expect only to read, thus sub-element processing is still fully parallel?

==&gt; What can we say about synthesising Elelement content into value receivers?

==&gt; As long as each element “writes” to its own unique value (unshared value receivers) the processing is fully parallel (unblocking write possible)?

==&gt; What can we say about ordering value receivers of composed element decoding?

==&gt; It seems the order of elements in synthesised element receivers will be correct as long as the AST is correct?

3) What can we say about synthesising values (decoding mapped elements into value-receivers) in parallel?

==&gt; It seems as long as the AST is correct, each branch of the AST may be synthesised into value-receivers in parallel?

==&gt; It seems Dynamic members of Composed Elements will still be created in the same order as the occurs in the AST?

==&gt; What can we learn from studying the Fids of an SPDH Message?

==&gt; Each Fid is a sub-element of the Fids Element.

==&gt; If we define the Fids element to be a Composed Element of type “sequence” the decoder knows it must remember the order of sub-elements in the AST.

==&gt; Synthesising the Fids element can then be made in two steps.

==&gt; Step one is to call the Fids element receiver with the member Fids in order (creating value-receivers in the order they occur in the AST of the Fids element)

== This can be seen as a “forward” declaration of synthesised values to-come?

==&gt; Step two means calling the value receiver for each Fid of the Fids AST node in any order (as ordering is already instantiated in step one)?

==&gt; This can be seen as “defining” the values “forward declared” in step one?

==&gt; As long as step one is sequenced before step two all will be fine?

4) It seems the Decoder must be designed as a “range generator” and not as a “range iterator”?

==&gt; An iterator is always sequential!

==&gt; A range generator can generate ion parallel?

5) What generators can we imagine for Decoding of a message?

==&gt; First step of Decoding should mean executing a “Map Generator” that processed received frame, creating an tagged-range-AST parallelising processing sub-elements of each identified element?

==&gt; Second step of Decoding should mean executing a “Synthesised Value Consumer” that synthesise values of AST nodes of choice?

==&gt; The “mapper” will then be able to optimise parsing based on knowledge about the element model?

==&gt; The AST may then be viewed as a passive “consumer” of identified AST nodes (tagged-ranges)

==&gt; The “Synthesised Value Consumer” will then be optimise value synthesises based on knowledge on the protocol (know what element values that are actually of interest)?

==&gt; The AST may then be viewed as a Passive “producer” of identified ASt Nodes (tagged-ranges)?

6) What generators can we imagine for Encoding a message?

==&gt; First step of Encoding means executing an “AST Generator” that calls a configured passive value-producer to know what AST to build?

==&gt; Having a generator building the AST enables it to optimise the AST to build (parallelise node creation)?

==&gt; Second step of Encoding means executing the “Synthesised Range Consumer” that collapse the AST into a single Range of synthesised values?

==&gt; Having a generator synthesising the encoded range enable it to optimise the single Range (Stream) to create?

==&gt; It seems having the AST pre-built before calling value-providers to synthesise element contents enables generator of Encoding-information values (e.g. bitfields encoding element presence)?

==&gt; No, for TLV elements the value for the L element does depend on the size of the synthesised V content (the AST structure is not enough)!

==&gt; ISO 8583 bitfield elements is fine though as there value can be determined from the node presence of the pre-built AST?

==&gt; It seems Encoding needs to cope with both AST structure dependent and not-yet-synthesised element encoding (size and value)

==&gt; It seems worth noting that the AST can know only of structure (presence and identity of elements) not size and content of actual synthesises of these elements?

==&gt; A TLV element for example must wait to encode the L element value until the V element value is synthesised (and the length of it is known)

==&gt; Consider to define that encoding ASTs where a value has forward dependence must be encoding bottom-up?

==&gt; It seems the AST enables us to identify the last element in the dream to encode (it is the leftmost bottom node in the AST)?

==&gt; To what degree can we imagine parallel encoding of an output Range is even possible?

==&gt; TLV structures we have seen must be built bottom-up (i.e. create the output range from the end and backward to the beginning)

==&gt; In this way the preceding L element value is available “after” having encoded the V element content.

==&gt; The TLV would be forward-encoded if the AST had determined the size of each range in advance?

==&gt; Could it be meaningful to determine the AST ranges sizes in advance to gain efficiency by being able to parallelise element encoding?

==&gt; The encoded size of an int can be determined by a simple mathematical expression (faster than actually encode it)?

==&gt; Th Encoded size of a string value can be determined mush faster than actually encode it into the output stream?

==&gt; some elements bay be defined to be encoded with a fixed size (so for those the AST actually knows the encoded size)?

==&gt; Seems it would be worth the effort to have the AST determine the size of its ranges?

=&gt;= Can we imagine a design that “automatically“ becomes top-down-parallel or bottom-up-sequential at compile-time or run-time?

==&gt; Compile-time Encoding specialisation would require compile-time knowledge of both structure (and at some case Range sizes)?

==&gt; Run-time Encoding specialisation requires run-time querying of AST structure and Range sizes?

==&gt; It seems there are three levels of AST completion of interest?

1) At a minimum the AST must define all member elements to encode (structure and identity)

2) A “Encode Complete” AST also knows the size of each range to encode.

3) An “constexpr Complete AST” knows at compile time also the value to encode of all elements?

==&gt; Is the third trait even interesting?

**WE ARE HERE...**

==&gt; Consider to study building an AST of an ISO 8583 to encode?

==&gt; The AST generator need to be able to query for run-time information on what message to encode?

==&gt; There seem to be two different run-time information the AST generator need at run-time to generate the correct AST to encode?

==&gt; Some elements may need to bind to correct value provider (e.g. the Message Type element)?

==&gt; Some elements are polymorphic and the AST generator need to query what specific element to encode?

7) Consider to relate processing of tagged-range-AST processing (applied both in Encoding and Decoding) to “Dependancy Trees of Futures” in parallel processing proposal by Hartmut kaiser?

==&gt; See 56:30 reference to talk by Hartmun Kaiser in “Todo: Programming - Consider to delve into the research and ideas of Hartmut Kaiser regarding "Concurrency and Threads are evil" and Parallelism is the thing?"

==&gt; A parallel algorithm is kind-of defined by writing code that builds a “Dependancy Tree of Futures”?

==&gt; Such a Dependency tree is a composite Future (A node may be a leaf-future or a future combining sub-futures).

==&gt; The tree nodes may then be constructed using HPX dataflow that combines sub-futures with a function and returning a future.

==&gt; It seems we may model Encoding element values that depend on later element encoding as Futures and parallelise the operation of encoding it?

==&gt; Also - bottom-up encoding of TLV Elements be be modelled as a Dependancy Tree of Futures (each L-value is a Future value depending on its V value)?

==&gt; What can we say about an AST where each element can be processed (Encoded or Decoded) in parallel?

==&gt; Each node than does not have to combine it sub-node futures (they do not have to wait)?

==&gt; Processing the AST just means traversing it and start processing each node asynchronously?

==&gt; We may provide all futures of the AST as a list to enable a client to delay some operation using “until all” combination (e.g. to do something when the AST is fully processed)?

==&gt; What can we say about an AST that must be processed bottom-up?

==&gt; An AST of TLV element can be seen as one if we do not implement the pre-queuing for length values (See above)

==&gt; Each L-value then becomes dependent on future&lt;V value&gt;?

==&gt; Cross-dependencies between Element values can be modelled as value x depending on a future value y?

==&gt; This we can see as a semi-bottom-up (only some elements must be bottom-up constructed)?

**WE ARE HERE...**

7) It seems we may identify some characteristics that applies to any Encoding and ay Decoding?

==&gt; Generating the AST for Encoding requires the AST generator to be able to query at run-time to determine polymorphism of elements?

{% endraw %}
