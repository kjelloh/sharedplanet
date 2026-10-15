# Todo: Programming - Consider to design C++ Template Domains Specific Languages to design FSM Protocol Engines and Element Table Message Encodings?

```#0694d434``` *As of 2017-01-26 11:14*

[mail plain/text](mail.txt)

{% raw %}
Would it be possible and a good idea to try and design DSL:s (Domain Specific Languages) using C++ Templates to implement Protocol Engines and Element Table Defines Message Encodings?

==&gt; See “Todo: Programming - Consider to study the Cpr ("C++ Request") open source library for verb-centric HTTP Protocol Client API?"

==&gt; See “Todo: Programming - Consider to design lazy (two-pass) Protocol Message Encoding and Decoding using tagged-range-ASTs?”

==&gt; See “Todo: Programming - Consider to model Protocol Stacks using State-Machine-Based Tagged-Range-Tree Transforms?”

==&gt; See “Todo: Testbench - Consider to implement Presentment-file generation as a proof-of-concept of DSL-based Protocol-message-encoding engine?”

==&gt; See “Todo: Programming - Consider to download and study interesting P2P and Protocol C++ Open Source Libraries?”

==&gt; See “Todo: Programming - Consider to design the C++11 Protocol Framework to allow for multiple Session and Links?”

==&gt; See “Todo: Programming - Consider to allow protocol Engine to apply Model Specialisation that also acts as additional Value Provider for model defined values?”

==&gt; See "Todo: Programming - Consider to discuss what traits a C++ Protocol Framework should have to enable implementation of popular protocols?”

==&gt; See “Todo: Programming - Consider to understand the e-mail protocols and authentication methods applied and programming libraries to apply them in code?”

==&gt; See “Todo: Programming - Consider to design a Boost C++ library for web protocol implementations RFC-style?”

==&gt; See “Todo: TestBench - Consider to model protocols as levels of transformations both in view and processing?”

==&gt; See “Todo: Programming - Consider to study the lightweight MQTT TCP/IP based messaging protocol?”

==&gt; See “Todo: Programming - Consider to study the POCO C++ standard Internet protocol library (ftp, pop3)”

==&gt; See “Todo: Programming - Consider to try out if a REST interface may a facade to any protocol (FTP, SPDH, ISO 8583…)"

1) Consider to be inspired by this talk on using Spirit X3 to generate and parse grammars (<https://channel9.msdn.com/Events/CPP/CppCon-2015/CPPConD02V015>)?

==&gt; Consider to study how they use the same “rule” to create both Generators and Parsers?

==&gt; Should we re-consider to perhaps use Spirit X3 after all (although it seems designed to work bets with strings)?

==&gt; Note: We then ditches using Element Table Notation!

==&gt; And how well does it fit ANS.1 notations?

==&gt; But it could work well for Internet Protocols that are mostly text-based (e.g. HTTP, FTP commands)?

...

2) How many Message Encoding DSL:s do we need to define to cover existing schemes for encoding definition?

==&gt; Consider to ogo for Swedbank Element Table notation (it covers all)?

==&gt; Do we need a special DSL to cope with RFC-niotation for protocol message encodings?

==&gt; Do we need a DSL for ASN.1 notation?

==&gt; What other commonly used message encoding notations should we consider to support as an DLS?

==&gt; Consider if the Element Table Notation is simple and powerful enough to cover all other notations?

==&gt; Note: We need to extend the Element Table Notation with model properties like Cardinality)?

3) Consider how it would be possible to extend the Element Table Notation with abilities to define Data Model concepts we need?

==&gt; We seem to need a way to define Element Cardinality?

==&gt; We seem to need a way to define an element references (an element value that defines a reference to another one)?

==&gt; E.g. in PPL files when an index value in an element implies a reference to a member in an Array of elements?

…

4) Consider to try out a DSL to define selected Message Encodings?

==&gt; Consider to pay special attention to handle both Encoding and Decoding?

==&gt; Consider to pay special attention to two-pass lazy Encode/Decode?

==&gt; First creating a tagged-range AST?

==&gt; Second synthesise AST into Encoded flat range or Decoded Value Consumers?

==&gt; An SPDH Message

==&gt; An FTP Message

==&gt; Consider both a Command Session Message and a File Transfer Message?

==&gt; An ISO 8583 Message

5) Consider to try out a DSL to define selected Protocols?

==&gt; Consider to pay special attention to the ability to “Stack” engines?

==&gt; Consider to pay special attention to the ability to define Authentication?

==&gt; Authentication seem to be an FSM defined mechanism (results in state Authenticated)?

==&gt; Consider to pay special attention to the ability to define Encryption?

==&gt; Encryption seem to be a kind of decoding (results in clear-text representation)?

==&gt; Seems lazy-evaluated decoding requires full decoding of encrypted range on access?

==&gt; An SPDH Client?

==&gt; An Iso 8583 Client?

==&gt; And FTP Client?

==&gt; Note the need to handle both command and data session?

==&gt; An HTTP Client

==&gt; An IMAP Mail Client?

…

6) Consider to design DSL:s to generate parallelised code where possible?

==&gt; Consider to use async-future idiom?

==&gt; Consider to use Coroutines-await-future idiom?

==&gt; Consider to study HPX-library extended idioms?

==&gt; Consider to stick to “plain” threads and active-objects idioms?

==&gt; Consider to choose carefully to use Range Iteration versus Range Generation to enable efficient parallelisation?

...

7) Consider to compare with the Protlr C++ serialization code and document generator project (<https://www.protlr.com>)?

==&gt; Consider this project is only able to define fixed sized and format protocol messages?

==&gt; Consider how it compares to other definition based initiatives like ASN.1?

==&gt; Can Protlr be used to define protocol messages with conditional element member presence (like XML, Jason composite protocol messages)?

...

…

Consider to delve into this case study to come up with DLS proposals for Message encodings and stackable Protocol Engines?

...

{% endraw %}
