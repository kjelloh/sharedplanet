# Todo: Consider to refactor encoding-aware string types as "dimension aware" meta-data?

```#97702e7d``` *As of 2016-03-02 21:59*

[mail plain/text](mail.txt)

{% raw %}
Reading "C++ Template Metaprogramming" I get the idea to implement encoding-aware strings as data of different "dimensions" as the exams shown in chapter 3, page 37?

1) Consider to define what “dimensions” we need for encoding-aware string types?

==&gt; Consider &lt;char_type,encoding,bool is_escaped&gt;?

==&gt; The char_type defines the type of String&#91;n&#93;, \*iter.  
==&gt; Encoding is a type that defines a character-set and its encoding (e.g. ASCII, UTF-8, EBCDIC)  
==&gt; is_escaped is a boolean flag that defines if the encoding uses escape sequences (e.g. if String&#91;n&#93; needs to be proxied)

==&gt; Consider &lt;base_string, encoding_type, bool is_escaped&gt;

==&gt; base_string will then provide traits like char_type

==&gt; Consider that bool is_escaped is not a parameter but can be determined by a metafunction is_escaped&lt;Encoding&gt;::value ?

==&gt; Consider Encoding to be a meta-data dimension list &lt;is_ASCII, is_ISOLatin1, is_UTF8, is_UTF16, is_UTC,…&gt;?

==&gt; Perhaps that enables us to write meta-functions to detect and handle safe compile-time encoding transforms (e.g. is_ASCII means the string is assignable to any of the other encodings)?  
==&gt; On the other hand these encoding “dimensions” are mostly true-orthogonal and may never mix (?) so a metafiction is_assign_compatible&lt;Source_Encoding, Target_Encoding&gt;::value works just as well?  
...

2) Compile-time string types must specialise to base string code for strings of compatible types (e.g. No encoding changes required)?

==&gt; Should be handled compile time and generate zero-overhead runtime (compatible base-strings)

3) Run-time adaption should be based on proxy-iterates that takes care of encoding transformations?

==&gt; Is it even possible to non-intrusively re-define the strings Iterators into proxied-ones due to the design of Strings (using traits)?

==&gt; How could we imagine to provide new traits to have strings that uses escaped Encodings (e.g. UTF-8, UTF-16)?

==&gt; Are these the only two that uses escape sequences in encoding?

==&gt; If so, we may threat them in a special way (allowing all other encode-aware strings) use their ordinary Iterators (there is a one-to-one mapping of position and code value instance)?

...

==&gt; Consider to note that this would make the strings break the Standard Container idiom in the same way std::vector&lt;bool&gt; specialisation does according to Herb Sutter (<http://www.gotw.ca/gotw/050.htm>)?

==&gt; Having the Iterator return a proxy makes Iterator “looks like” it iterates over objects of the vector Type when it in fact does not.

==&gt; Iteration is made less efficient than you “expect” due to the extra Proxy encode/decode operations.

==&gt; Code that uses POD (plain-old-data) access to the vector member values may in fact end-up with PD access to the proxy (which may not work)

==&gt; E.g. this code does not work

std::vector&lt;bool&gt; v({true,false,false});

bool\* p = &\*v.begin(); // Compiler error “cannot convert 'std::vector&lt;bool&gt;::reference\* {aka std::_Bit_reference\*}' to 'bool\*' in initialization"

a) v.begin() will return std::vector&lt;bool&gt;::iterator at position 0 (the first element)

b) \*v.begin() will return a Proxy to the first bit in the underlaying bit-vector.

c) &\*v.begin() will try to return the address of the proxy (where we expected to get the adress of the value in the array).

d) And we can’t implement an “address of” operator& in the proxy as there is no boolean to return the address to!

==&gt; A string returning a proxy that encodes/decodes escaped character codes will suffer the same problems as std::vector&lt;bool&gt; for the same reason.

==&gt; e.g. char\* p = &s&#91;0&#93; will not work if “character 0” is actually escaped in the underlaying string storage!

==&gt; An example of this would the the UTF-8 String “Örjan” where the first ‘Ö’ will be encodes as an escaped sequence of bytes.

==&gt; Consider to study “Scott Meyers has a long Item 30 in More Effective C++ about proxy classes. “ (<http://stackoverflow.com/questions/17794569/why-is-vectorbool-not-a-stl-container>)

“You can come a long way to almost mimic the builtin types: for any given type T, a pair of proxies (e.g. reference_proxy&lt;T&gt; and iterator_proxy&lt;T&gt;) can be made mutually consistent in the sense that reference_proxy&lt;T&gt;::operator&() and iterator_proxy&lt;T&gt;::operator\*() are each other's inverse."

==&gt; So, what can we say about using proxy-iterators to handle escaped-strings as if they where iteratable strings of chars (or wchar_t)?

a) They will introduce “hidden” inefficiency in the form of proxy encode/decode operations.

b) They will fail to compile in code expecting to be able to take the adress of the member characters of the string.

Compiler error similar to “cannot convert 'std::vector&lt;bool&gt;::reference\* {aka std::_Bit_reference\*}' to 'bool\*' in initialization"

...

4) Transformation between incompatible encodings must show in code (implicit transformations not be possible)!

==&gt; Consider to implement these as dynamic_cast&lt;S2&gt;(S1& s1) (<http://www.cplusplus.com/doc/tutorial/typecasting/>)?

==&gt; Or better, define template &lt;typename S1, typename S2&gt; —&gt; S1 to_string(const S2& s2); ?

...

5) Implicit operations in incompatible string encodings shall never be possible.

6) Consider to compare with this seemingly excellent article about character-set issues in Windows and how Visual Studio 2016 will enhance support for this (<https://blogs.msdn.microsoft.com/vcblog/2016/02/22/new-options-for-managing-character-sets-in-the-microsoft-cc-compiler/>)?

==&gt; This article seem define different encodings and the BOM-encoding of text files?

...

...

Consider to study the "dimension" example and elaborate on an encoding-aware string type based on this idiom?

...

Skickat från min iPhone

{% endraw %}
