# Todo: Programming - Consider to play with the term "Codec" for a name on the C++ object that uses a Protocol Data Model to encode and decode to and from serialized form of protocol messages?

```#d7f10143``` *As of 2016-06-26 13:40*

[mail plain/text](mail.txt)

{% raw %}
Consider that the term ”Codec” is a good one to name an object that uses a common common data model to both encode and decode data messages?

1) Consider that the common usage of Codec is to encode/decode streamed multimedia content (<https://en.wikipedia.org/wiki/Codec>)

”A codec is a device or computer program for encoding or decoding a digital data stream or signal.&#91;1&#93;&#91;2&#93;&#91;3&#93; Codec is a portmanteau of coder-decoder or, less commonly, compressor-decompressor."

==&gt; Also see Ubuntu ”What is a codec” (<https://web.archive.org/web/20120219101738/https://help.ubuntu.com/8.04/musicvideophotos/C/codecs.html>)

”A multimedia codec is a small piece of software which allows you to watch videos or listen to music of a specific format.”

2) Consider the term ”Protocol Codec” for an object that may encode and decode Protocol Messages?

==&gt; Consider that searching the Web for Protocol Codec does not turn up any hits for this term?

==&gt; Consider for example the wikipedia page on Communications Protocols (<https://en.wikipedia.org/wiki/Communications_protocol>)

…

3) Consider that if we go for a design where the Encoded Data Object and the Decoded Data Object are generators we will not need a designated encoder/decoder generator/iterator?

==&gt; See ”Todo: Programming - Consider different Generator or Iterator design of general Protocol Message encode decode library?”

...

…

Consider to elaborate on this idea to combine an encoder and decoder into a ”Codec”, ”Protocol Codec”?

{% endraw %}
