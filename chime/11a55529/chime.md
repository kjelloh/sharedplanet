# Todo: Programming - Consider to note that Character-set encoding is a special but strong part of Protocol Message Encodings?

```#11a55529``` *As of 2016-09-20 16:43*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to elaborate on the idea that Character-set-encoding (string encoding) is normally a strong part in Protocol Message Encodings?

1) Most WEB-Protocols are in fact text-based (and normally encoded using US-ASCII)?

2) Card Payment Processing Protocols all struggle with encoding text correctly?

==&gt; The Cardholder, card-acceptor, messaging processor all transfer names and addresses as strings that needs correct encoding?  
==&gt; Current Protocol Messages (e.g. ISO 8583, SPDH)

3) Consider to study how IFSF (International Forecourt Standard Forum) handles String encoding in their communication standard (https://www.ifsf.org)?

==&gt; Consider to ask Autotank for IFSF specifications (acres requirer membership and I can’t become one)?

4) Consider how we can define interoperable character-set-encodings for protocols that lack the ability to encode the encoding used?

==&gt; How can we enhance interoperability of ISO 8583 messaging agents when the Message can’t encode what encodings was used?  
==&gt; How can we enhance SPDH agents interoperability when SPDH messages can’t encode what character sets are used neither for the message itself, nor for member strings?  
==&gt; To what degree does EMV define the encoding of text in the chip interface (do they always require ASCII)?

==&gt; Can we imagine some non-intrusive BOM (Byte Order Mark) that is invisible to the receiver that does not implement this character-set-enocidng option?

==&gt; Note that a BOM must be “raw” in that it is decoded and removed before decoding of the string is made?  
==&gt; It seems we may imagine a prefix- or a postfix-BOM?  
==&gt; Can we even imagine an embedded BOM that is invisible if not decoded and removed?  
==&gt; Such a BOM must have values that are allowed in the encoded character set (ok as code points if not removed)?  
==&gt; Such a BOM must decode to invisible characters (e.g. some white-spaces)?

==&gt; Can we imagine a kind of prefix BOM (Byte Order Mark) to non-intrusively encodes what character encodings that are used?

==&gt; We would like a BOM that is invisible to receiving systems that do not implement this option?

==&gt; For SPDH we may implement it so a Receiver will respond NAK if it does not support the BOM (plug-and-play adaption)?

==&gt; Can we imagine a post-fix BOM that are invisible for receivers that does not implement this option?

==&gt; An SPDH message may be encoded with an extra optional Fid that carry the BOM?

==&gt; Can we imagine an embedded BOM that are invisible to receivers that does not implement this option?

==&gt; Also see “Todo: Consider to write and distribute a white-paper on character-set-encodings in Payment System Messaging? "

==&gt; Consider to use “invisible” encoding using “Space” (Ascii 20), “Tab” (Ascii 09) and “Back Space” (Ascii 08), (http://www.ibb.net/~anne/keyboard.html)?

==&gt; Consider “Space” encodes a ‘1’ and “Back Space” a ‘0’. We may then use three or four bits to encode some form of “BOM”?  
==&gt; We would then need an additional one to four characters to “undo” the visible impact of the BOM series of Space and Tab?  
...

==&gt; Can we imagine using a BOM made up of a self-canceling series of tabs?  
==&gt; No, there are no “Back Tab” but there is a “Back Space” (See above)  
==&gt; we can now encode the BOM using a series of n tabs and n back-tabs?  
==&gt; Starting with a back-tab is ok as this will not erase any preceding text.  
==&gt; We can now encode a binary number using tab as 0 and back-tab as 1?

==&gt; Can we imagine using a BOM made up of a self-cancelling series of space and back-space?  
==&gt; Yes, we can use Space and Tab (See above)  
==&gt; The fist octet of the BOM must be a space (starting with a back-space will erase the last character of the actual string)  
==&gt; The following octets may be any combination of n-1 space and n back-space (end result is n space and n back-space)

==&gt; We may now encode a binary number using space as a 0 and back-space as a 1?  
…

Consider to elaborate on this idea of the importance to support character-set-encodings as a component of Protocol Message Encodings?  
...

{% endraw %}
