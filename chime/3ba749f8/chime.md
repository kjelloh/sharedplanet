# Todo: Programming - Consider we can actually prove that we can unequally define a protocol buffer from a Composite type of a small set of member elements?

```#3ba749f8``` *As of 2017-01-29 14:10*

[mail plain/text](mail.txt)

{% raw %}
It seems we should be able to prove that any protocol buffer (encoding of values and structure) can be modelled as a composite type made up of a small set of member element types?

1) Consider we should be able to prove that in C++ we should be able to compile-time generate a buffer Encoder and Decoder from just one Buffer type that models the streamed buffer?

==&gt; Consider the steps to transfer a Composite Type Value as a stream of octets?

buffer —&gt; Encoder&lt;Buffer&gt; —&gt; octet-stream —&gt; Decoder&lt;Buffer&gt; —&gt; buffer

==&gt; Where Buffer is some Composite Type

==&gt; Consider Encoder&lt;Buffer&gt; should be able to generate an Encoder for each element in the Data Structure?

I.e., Encoder&lt;Buffer&gt; = {Encoder&lt;e1&gt;, Encoder&lt;e2&gt;, …} // Where e1, e2 are member element types in Buffer

==&gt; Consider Encoder&lt;Buffer&gt; may then be recursively be defined as lists of lists of Encoders of each type in the structure?

...

2) Consider any protocol buffer may be modelled as a DAG defining a Composite of element types?

==&gt; All buffers are finite in size and thus not cyclic?  
==&gt; All buffers are streams of Code Units (e.g. octets) that encode structure and values?

3) Consider We can represent any Composite Data Structure using a small set of types?

==&gt; We have unstructured elements (e.g. ”values” like int, float, boolean)?  
==&gt; We have the structure Composite (identifies a recursion in the structure, i.e. a new layer of element combinations)  
==&gt; We have the List Composite (ordered member elements of the same type)  
==&gt; We have the Record Composite (ordered member elements of different types)  
…

4) Consider we may map all structure elements to a small set of structure encoding scheme classes?

==&gt; Consider Fixed structure encoding (We parse using presumptions on the fixed mapping between element type and encoded element data)  
==&gt; Consider some Array Encoding scheme (actual scheme is defined by the protocol, e.g., BERTLV, XML defines schemes to encode Arrays)  
…

5) Consider we may map any unstructured element type to a small set of value encoding schemes?

==&gt; Consider an integer may be mapped to a protocol defined encoding of an int (e.g. as digit string in XML or defined BER encoding of an integer value)?  
==&gt; Consider the same goes for all primitive (unstructured) type and their value encodings?  
…

6) Consider we can define any protocol buffer data model using a small set of structure and value types?

==&gt; Consider a structure composite may be either one with fixed or conditional members?

==&gt; In a fixed composite all model members are always encoded into the protocol buffer?  
==&gt; In a Conditional composite the presence of an encoded member in the protocol buffer is defined by meta-data.  
==&gt; The meta-data for presence of elements in Conditional Composites may either be encoded as structural data (XML, BER enables detection of elements) or implied presence values (ISO 8583 defines special bitfields to define element presence)  
==&gt; The Presence condition may be Mandatory, Conditional or Optional.

==&gt; Conditional Presence means an element must be present in the encoded buffer based on some meta-data.  
==&gt; The meta-data for a Condition must be available from the data already encoded (e.g., ISO 8583 bitfield values)

==&gt; NOTE: For encoding and decoding we are only concerned with Presence Conditions available to the parser to be able to instantiate a value of the Buffer type based on the octet stream.  
==&gt; This means that Element presence defined by the protocol for correct messaging semantics are NOT of interest at this level (the buffer type may be correctly encoded and still carry inconsistent data)  
…

…

Consider to elaborate on this idea that an Encoder and Decoder of a protocol buffer should be able to be uniquely defined from a Composite Type modeling the buffer?  
...

{% endraw %}
