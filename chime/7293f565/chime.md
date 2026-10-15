# Todo: Programming - Consider tag-path-based encoding and decoding to allow for both implicit and explicit value encodings

```#7293f565``` *As of 2016-06-09 17:06*

[mail plain/text](mail.txt)

{% raw %}
It seems, if we view data encoding as consisting of structure encoding and value encoding, that the tag-path-based design should allow for both explicit (encoded) and implicit (element identification based) value processing?

1) Consider the basic mode to be processing of data structures using tag-path-based element processing without value encoding information?

==&gt; Consider at basic level the only information provided for element processing is the element tag path and wether it is a primitive or a composite element?

**{tag path, composite}**

**{tag path, primitive}**

2) Consider element value encoding to be an optional additional level of processing?

==&gt; Consider for a primitive node, additional type::representation may be provided in processing?

**{tag path, primitive, type::representation}**

==&gt; Consider type to define “what” e.g., boolean, integer or text?

==&gt; Consider representation to define “how” e.g., boolean::octet, integer::octets, text::utf-8 (i.e. type plus encoding)?

...

==&gt; Consider it is only “primitive” (unstructured) values who’s encoding is defined (composite elements are processed on structure information only)?

==&gt; Consider a value to be defined as “what” it represents (its type) and “how” it is represented (its encoding)?

==&gt; Consider “what” to be some standard set of types as Boolean, Integer, Float or Text?

==&gt; Consider “How” to be defined by a “codec”, “Encoding” or “Representation”?

==&gt; Consider C++ memory representation of primitive data types to be one sort af value encodings (including endianness)?

==&gt; Consider ISO-OSI 7-layer “Representation” layer to be about encoding (representing) values?

==&gt; Consider to define some canonical way to represent values as Text or in some binary form?

...

==&gt; Consider that XML, HTML, BERTLV does NOT define how to encode values (They define how to encode structures and requires implicit knowledge of value encodings)?

3) Consider that by separating structure encoding from value encoding the model melts down to something really simple?

==&gt; Consider the number of structures imaginable is actually quite small to cover all composite structures?

a) Unstructured (Primitive)

b) Structured (Composite)

|

|

— Fixed or variable set of members, Fixed or variable sized Members, Ordered or unordered members

==&gt; Consider the ways to encode structure is also quite small?

a) Pre-fix encoding (each element is prefixed to encode structure)

b) Element separation (each element is separated with a separator encoding)

c) Element framing (each element is encoding using most a prefix and post-fix, e.g. XML elements)

c) Structure mirroring values (dedicated element value, e.g. a bitfield, defines the encoded structure, e.g. ISO 8583 bitfields)

d) Position based structure (Record or Array of elements each defined by its size and position)

Consider the number of value types and representation is quite small

a) Consider the types Boolean, Integer, Real and Text could cover all data types we need to encode?

b) Consider the ways to encode these can be efficiently defined (including endianness) using a very small set?

==&gt; All data can be encoded into octets of bit streams?

==&gt; One endianness will suffice (and each platform must understand the endianness used)

==&gt; A boolean can be encoded as an octet with value 0 (false) and not false as true.

==&gt; An integer can be encoded as a stream of octets applying the same endianness as each bit stream.

==&gt; A Real number can be encoded using a defined sufficient way?

==&gt; Or do we need to enable optimisation as has been developed in gaming or 32 versus 64 bit platforms?

==&gt; A Text can be encoded in Unicode using UTF-8, UTF-16 or UTF-32?

...

4) Consider the idea of {tag path, primitive/composite} with option {type::representation} can be generalised to {tag path, structure-model, value-model}?

==&gt; Consider the basic processing is based on structure (structure before value)?

input stream ==&gt; decode ==&gt; a map of {tag path, primitive/composite} to content (modeled as ranges in processed data vector)?

==&gt; Consider this enables a separate table of {tag path, value-model} to be applied to turn each {tag path, primitive, range} into {tag path, value}?

==&gt; It seems it should be easy to use a parsed {tag path, range} to find table entry {tag path, value-model} to turn content defined by {range} into {value}?

input stream ==&gt; decode ==&gt;  &#91;element element element element element …&#93;

|  |  |  |  |

|  |  |  |  |

|  |  |  |  |

|  |  ----- |  |

|  ---------- | |  |

--------------- | | |  |

| | | |  |

{tag path, range} — | | |  |

{tag path, range} ---- | |  |

{tag path, range}-------- |  |

{tag path, range}------------  |

{tag path, range}--------------------

{tag path, range}-----…

{tag path, range}   {tag path, value-model} {tag path, value}

{tag path, range} {tag path, value-model} {tag path, value}

{tag path, range} {tag path, value-model} {tag path, value}

{tag path, **range**} + {tag path, **value-model**} ==&gt; *(value-model(range) = value) ==&gt;  *{tag path, **value**}

{tag path, range} {tag path, value-model} {tag path, value}

{tag path, range} {tag path, value-model} {tag path, value}

{tag path, range} {tag path, value-model} {tag path, value}

{tag path, range} {tag path, value-model} {tag path, value}

4) Consider to compare the idea of separating structure encoding (tag path table) and value encoding (type::representation) to existing protocol encodings?

&lt;Data Structure (Topology)&gt;

tag-path-table &lt;==&gt;  XML

HTML

JSON

SPDH

ASN.1 BER Primitive/Constructed

…

&lt;Data Value (Content)&gt;

Type::Representation &lt;==&gt; MIME Content

ASN.1 BER Tag+Content

C++ memory representation

…

5) Consider how well ASN.1 has succeeded to define a general data structure and value encoding notation and implementation?

==&gt; Consider why ASN.1 seems so complicated?

==&gt; Consider if ASN.1 has missed out on the point of separating structure encoding from value type::representation encoding?

==&gt; Consider if ASN.1 can be made simpler if modelled as suggested above by separating structure from value encoding?

...

…

Consider to delve deeper into this idea of how to unify any data encoding finding a common structure and value encoding semantics?

...

{% endraw %}
