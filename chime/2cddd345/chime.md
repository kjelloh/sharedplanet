# Todo: Programming - Consider to design a Text streaming framework based on Iterator adaptors and Universal 32 bit Code Points?

```#2cddd345``` *As of 2016-01-24 18:24*

[mail plain/text](mail.txt)

{% raw %}
Would it be a good idea to design another Text streaming framework based on Iterator Adaptors and true 32-bit Universal Character Code Points?

1) Base the design on the insight that input is always a stream but that the stream may be of 7-bit, 8-bit, 16-bit or 32-bit “primitives”?

2) Also consider that input stream may be encoded in text encodings like UTF-8, UTF-16 or Base32, Base64.

3) Text Streams may also be encoded using a variety of characters sets like ASCII. ISO-Latin-1, Windows Wide Char etc.

…

Consider the following design idioms?

a) A Stream is represented by an Iterator.  
b) Actual data is stored in an iteratable container.  
c) Input and Output iterators base defines an interface that references a type Ref_T that may be 7-bit, 8-bit, 16-bit or 32-bit of size.  
d) Data containers are “representation aware” of encodings defined by size (7,8,16,32 bit) and type (binary, ASCII, UTF-8, UTF-16, EBCDIC, Base32, Base64)  
e) Adaptor Iterators performs transformations between encodings (both size and type)  
f) All character encoding transforms goes through UCS Code Point Iterators

==&gt; UTF8 to UTF16 becomes utf8_vector —&gt; utf8_ucs_Iterator —&gt; ucs_tff16_Iterator —&gt; utf16_vector.

g) All streams (Iterators) implements “lazy” dereference (value produced on access, not on iteration).  
h) All iterators “memoize” referenced value (second access uses cached value)  
i) All character set transforms goes through ucf Code Points.

==&gt; EBCDIC to ASCII becomes ebcdic_vector —&gt; ebcdic_ucs_Iterator —&gt; ucs_ascii_Iterator —&gt; ascii_vector

j) All STL string operations are implemented on “encoding aware” source and input parameter ranges.

==&gt; range = string::find(source_range,key_range) // returns the range in source where the key defined by key_range is found.  
==&gt; returned range is a sub-range of source_range.  
==&gt; all ranges must have Ref_T being ucs Code Points (using adaptor Iterators if transform is required).

k) Consider to design the framework to have client compartmentalise the design into “representation domains” (e.g. keep UTF8 code separated from UTF16 code)?

==&gt; Consider to never perform implicit representation (encoding) transforms (An UTF8 stream must be transformed in code using an utf8_usc_Iterator)?

l) Consider to design the framework to enable compiler optimisation to take care of redundant encoding transforms?

==&gt; string::find(UTF8-range,UTF8-Key) should “collapse” to UTF8-optimized code?  
==&gt; Both source and key in UTF8 means we may do a simple octet-by-octet find (escaped characters will have the same octet expansion)?  
…

…

Consider to elaborate on this approach to a more general text stream framework?  
...

{% endraw %}
