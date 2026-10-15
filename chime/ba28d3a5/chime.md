# Todo: Programming - Consider to find an enhanced C++ String representation and manipulation with a proper value semantics and view abstraction?

```#ba28d3a5``` *As of 2016-03-29 16:51*

[mail plain/text](mail.txt)

{% raw %}
Could it be that we have approached the problem of string encoding and string manipulation from the wrong end? What it we need to separate encoding and representation (transfer) from value semantics and views (using)?

==&gt; See “[Todo: Programming - Consider to implement Encoding Aware String types based on C++ Template runtime zero-overhead Metafunctionality?](../3c9f09f2/chime.md)”  
==&gt; See “[Todo: Consider to refactor encoding-aware string types as "dimension aware" meta-data?](../97702e7d/chime.md)”  
==&gt; See “Todo: Testbench - Consider to use the icu-project C++ library for UTF string conversions?”

1) Consider current strings lacks a layer of indirection to process their “meaning” (they only expose a raw representation interface)?

==&gt; a char s&#91;40&#93;; is just an array of bytes of type char (said nothing of what characters that are encoded)  
==&gt; std::string s; Also said nothing about what chars are encoded.  
==&gt; wchar_t s&#91;4&#93;; is just an array of two-bytes characters but sis nothing about what chars that are encoded.  
==&gt; char\* s = “Hello”; is a bit unclear regarding on how the string literal is encoded (the same encoding as the source code file)?  
==&gt; char\* s = “Välkommen”; What encoding is used here (assumably UTF-8)?

==&gt; RAD Studio String s16 = “Välkommen”; will create an encode-aware UTF-16 string.  
==&gt; RAD Studio AnsiString s8 = “Örkelljunga”; will create an encode-aware UTF-8 string.  
==&gt; s16 = s8; Will transform the UTF-8 encoded string in s8 to an UTF-16 string and assign it to s16.

==&gt; Consider to compare with C++ string literal syntax (<http://en.cppreference.com/w/cpp/language/string_literal>)  
==&gt; It seem to mix representation and encoding?

“Välkommen” means a char&#91;10&#93; array (encoding of source code file?)  
L“Välkommen” means char_t&#91;10&#93; array (encoding of source code file?)  
u8”Välkommen” means char&#91;??&#93; array of UTF-8 encoded string (compiler required to transform from source code encoding?)  
u16”Välkommen” means what_t&#91;??&#93; array of UTF-16 encoded string (compiler required to transform from source code encoding?)  
&lt;prefix&gt;R”Välkommen” (prefix any of the allowed string literal prefixes above) means the string representation without escape characters and the ending delimiter.

2) Consider what “The value of a string” actually means?

==&gt; We would like UTF-16 string “Välkommen” to be of equal value as the UTF-8 string “Välkommen” (would we not)?  
==&gt; On the other hand - we do want the code to express representation incompatibilities?

UTF8String s8= “Välkommen”;  
UTF16String s16 = s8; // Should not compile?  
UTF16String s16 = u8”Välkommen”; // Should not compile?  
…

3) Consider what we can say about string value semantics by referring to John Lakos proposal of value semantics (<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2479.pdf>)?

==&gt; Also see his cppcon 2015 talks (although quite unclear and noisy) (<https://channel9.msdn.com/Events/CPP/CppCon-2015/CPPConD04V015>) (<https://www.youtube.com/watch?v=0EvSxHxFknM&ebc=ANyPxKoWBmqLt7y88vSnTAn-SiLVrBs2LUj78-SS9EVcbjcWBfwUUtMz10adAy8X4DuR7D0YctHK>)

==&gt; What is the value of a string according to John Lakos?

==&gt; It seems he require the types to be the same (thus and UTF8String can never be of same value as an UTF16String)?  
==&gt; Still - he seems to claim that the value type should not depend on how the value is represented?  
==&gt; He seem to state that two values are the same of the same salient operations return the same result on the two?

==&gt; Seems to suggest we need to define a new “Text” type capable of holding any character string to have “sameness” being applied to strings of different encodings?

==&gt; Can a Range-view (as defined by Eric Niebler) be considered to be (and provide) values?

==&gt; We could then define an UCS (Universal Coded Character Set) String View Adaptor to make any string interoperable?  
==&gt; But re-encoings would then be implicit and invisible in code?  
…

4) What can we learn from array_view concept in the proposed C++ GSL Library (<https://www.youtube.com/watch?v=C4Z3c4Sv52U>)

==&gt; Seems an Array view is all about representation (not value) type. See 21:15 (<https://www.youtube.com/watch?v=C4Z3c4Sv52U>)  
array_view&lt;int&gt; ==&gt; array_view&lt;short&gt; does NOT compile.

==&gt; So the template parameter to array_view states the representation, not the value type?

==&gt; Q: Is this definition of “view” consistent with Eric Niebler Range View concept?

5) What can we learn from current Range and View proposals to enhance String manipulation with an encode aware “view adaptor layer”?

==&gt; Consider to compare with Eric Niebler Ranges proposal (<https://channel9.msdn.com/Events/CPP/CppCon-2015/Ranges-for-the-Standard-Library>)?

==&gt; Ranges are views (they do not own the data) so it is a way to add the encode-aware adaption for string manipulation?

==&gt; What can we learn from studying Eric Nieblers c_str&lt;C\*&gt; ranges (<https://github.com/ericniebler/range-v3/blob/bd64149fcb66b1f4aac72afb7684a63053c85e92/include/range/v3/view/c_str.hpp>)

==&gt; const char\* const sz = “Välkommen”;

==&gt; auto s_view = c_str(sz); // will be a range view of type const char\*. begin(s) == &sz&#91;0&#93;. end(s) == &sz&#91;??&#93; (‘Ä’ is probably encode-encoded as UTF-8?)

==&gt; Thus, seems the c_str range view is a view into the string representation, not the string “meaning” (e.g. c_str(“Välkommen”) is NOT a range of the characters ‘V’,’ä’,…, but the range of char values encoding this string)!

…

**WE ARE HERE...  
**  
6) Consider to extend this discussion to include “sameness” or “changes” to Text Documents (the value of a text document)?

==&gt; How can we talk about Text Value Change (changes to the text actually stated) separated from Text Formatting (bold, font, colour)?  
==&gt; Where do we draw the line between white spaces being text changes versus text formatting (e.g. when used as indentation of paragraph separation)?  
==&gt; We would like a Text Change to be about changing actual phrasing and ordering, not about separation and indentation?  
==&gt; Q: Are bullet lists part of the text or part of the format?  
…

==&gt; Can we imagine having two text documents contain the same text but in different format (e.g. comparing a text document with a word document)?  
==&gt; Consider the example of finding requirement IDs in a word document (we need Text value equivalence)?

…

Consider to elaborate on Encode Aware String Representation in C++ using a defined String Value Semantics and String View Adaptors?  
...

{% endraw %}
