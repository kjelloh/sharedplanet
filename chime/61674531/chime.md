# Todo: Programming - Consider to analyze the Protocol Encode/Decode Engine by thinking about the components we want to be able to re-use/change?

```#61674531``` *As of 2016-07-03 15:35*

[mail plain/text](mail.txt)

{% raw %}
So, what can we learn about the desired architecture from analyzing the architecture Encode/Decode Engine from the view of ”what we would like to re-use or change”?

1) Consider architectures that allows the same model (message) to be encoded/decoded using different encodings (e.g. BERTLV versus XML)?

==&gt; Consider what is actually the difference between two ways to encode the same message?

==&gt; Consider that we need to be able to encode both structure and value?

==&gt; Consider decoding differens from encoding in that is is the encoded data that may, or may not, define the structure?

==&gt; Consider decoding where we need the decoder to use the model to know the structure it decodes?

=&gt;= Or, do we actually assume the model to define the encoded data?

2) Consider to study encoding explicitly and look at an iPOS Message encoded in BERTLV or XML?

==&gt; Consider our options to know how to represent an iPOS message in XML (decide on tags to use)?

==&gt; Consider an XML encoder to simply require the model to provide labels of encoded elements to use as XML tags?

==&gt; Consider the example of encoding an iPOS message element in a structure?

label-path:  cdoiPOS_SA.cdoDI_INFO.cdoDIMessage.pdoTextId = "101"

tag-path: fff10a.ffe101.ffe102.dfc102 = "101"

…

…

Konster to delve into this way of analyzing the encode/decide transformation to see what we can learn about a good design?

...

{% endraw %}
