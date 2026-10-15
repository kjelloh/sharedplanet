# Todo: Consider to write and distribute a white-paper on character-set-encodings in Payment System Messaging?

```#8c9ad97b``` *As of 2016-03-28 15:48*

[mail plain/text](mail.txt)

{% raw %}
Could it be fun and rewarding to try and write and distribute a paper on character-set-encodings in Payment System Messaging?

1) Consider to describe the lack of control of applied encodings in current messaging protocols?

==&gt; The problems of member strings in ISO 8583?

==&gt; The problem of string encoding of whole SPDH-messages (ASCII, EBCDIC)

==&gt; The problem a text members in SPDH messages?

2) Consider to discuss encoding transparence of some gateway-paths?

==&gt; Consider to describe when EBCDIC —&gt; ASCII —&gt; EBCDIC “works” although the intermediate ASCII encoding is actually not correct (e.g. by following ‘Ä’)?

Client Send: ASCII IEC 646 (swedish 7-bit ASCII) —&gt; EBCDIC 278 (Sw/Fin)

Gateway: EBCDIC 037 (US) —&gt; ASCII (US 7-bit ASCII) —&gt; EBCDIC 037 (US) (<http://www.easymarketplace.de/codepages.php>)

Server Receive: EBCDIC 278 (Sw/Fin) —&gt; ASCII IEC 646 (swedish 7-bit ASCII)

==&gt; The Client will map ‘Ä’ to 0x5B as defined by ISO/IEC 646 (<https://sv.wikipedia.org/wiki/ASCII>) and then to 0x7B (<http://www.easymarketplace.de/cp/cp00278_Finland_Sweden.pdf>)

==&gt; The Gateway will decode 0x7B to ‘#’ (<http://www.easymarketplace.de/cp/cp00037_US.pdf>) to 0x23 (ASCII ‘#’)

==&gt; The Gatway then reverses this back to EBCDIC ‘#’ 0x7B ok.

==&gt; And the receiver decodes it using EBCDIC 278 and ASII IEC 646 to an ‘Ä’ ok.

==&gt; So, as long as the intermediate uses a unique 1-to-1 mapping it does not matter that the mapping is incorrect?

==&gt; It seems the intermediate (being a processor or acquirer) will run into problem if the text is parsed (or presented for human reading)?

==&gt; E.g. if the intermediate processing does not allow the character ‘#’ in the encoded text it will be a problem?

3) Consider to propose enhancements to system components to adress the problem of character-.set-encodings?

==&gt; What intermediates problems can we identify that indicates incoherent character-set encodings?

==&gt; Where may Swedish characters end up in the character set applied by an intermediate (enables identification of ok and erroneous encodings)?

==&gt; Imagine the path PPL —&gt; Terminal —&gt; Intermediate 1…n —&gt; Card Issuer?

==&gt; Where may Swedish characters end-up depending on applied encodings at each node in the path?

==&gt; What encoding may be regarded as the “safest” to avoid as many errors as possible?

==&gt; Consider to require correct end-to-end encoding (intermediate encodings irrelevant)

==&gt; Consider to require intermediate encodings to not get characters that are not allowed in encoded texts?

==&gt; What texts are actually parsed by intermediates?

==&gt; What texts are simply displayed (causing strange displaying but no parsing errors)?

…

...

4) Consider to propose possible BOM (Byte order Mark) to add possible encode-aware message extension?

==&gt; See “Todo: Programming - Consider to note that Character-set encoding is a special but strong part of Protocol Message Encodings?"

…

Consider to write such white paper “just for fun” and distribute not to colleagues at Swedbank, PSPs and Terminal Vendors?

...

{% endraw %}
