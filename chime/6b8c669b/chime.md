# Todo: Programming - Consider any encoding to define structure semantics and value semantics?

```#6b8c669b``` *As of 2016-06-09 15:20*

[mail plain/text](mail.txt)

{% raw %}
Could it be that any encoding of data actually defines a structure semantics and a value semantics?

1) To encode structured data a defined structure semantics is required?

==&gt; The structure semantics enables the structure of the encoded data to be perserved?

==&gt; An encoding may define element structure without explicitly defining element value encoding?

==&gt; Element value encoding may be implicit (the decoder must know value encoding from element identification)?

2) Consider encodings like JSON, XML, HTML, ASN.1, SPDH, BERTLV and key-path-lists to all define a semantics to express structure?

...

3) Consider that any composite value structure semantics uses tagged or position defined element identification?

==&gt; Using tagged-path-lists require each element to have a structurally unique tag name?

==&gt; SPDH mixes position based element ID (header elements) and tagged elements (Fids)?

==&gt; XML is a purely tagged-based composite value semantics (cant have position based elements)?

==&gt; ISO 8583 is a purely position based composite value structure semantics?

==&gt; BERTLV is a purely tagged-based composite value definition semantics?

…

4) Consider that only some encodings includes explicit value encoding semantics?

==&gt; Consider SPDH to define implicit (element id based) value encoding?

==&gt; Consider BERTLV as applied by EMV, PPL and iPOS define implicit (element id based) value encoding?

==&gt; Consider MIME to define value encoding semantics (special elements and values are used to express encoding of values)?

…

5) Consider that actually any data value may be represented using an encoding that defines structure and value?

==&gt; The structure defines the topology of data elements?

==&gt; XML, JSON, HTML are all example of structure defining semantics?

==&gt; The value defines “what” a value represents and “how” it is represented?

==&gt; XML element values seem to always be text?

==&gt; An additional XSD seems to define value semantics for XML element values (<http://www.w3schools.com/xml/schema_dtypes_numeric.asp>)?

XSD: &lt;xs:element name="prize" type="xs:decimal"/&gt;

XML: &lt;prize&gt;999.50&lt;/prize&gt;

==&gt; HTML 5 seem to define semantics for input types (<http://www.w3schools.com/html/html_form_input_types.asp>)?

&lt;form&gt;  
Quantity (between 1 and 5):  
&lt;input type="number" name="quantity" min="1" max="5"&gt;  
&lt;/form&gt;

==&gt; SPDH, iPOS, PPL and HISO all applies implicit value encodings (encoding defined by identified element)?

6) Consider that any implicit value encoding scheme may be defined with a run-time tag-path-element based value encoding schema?

==&gt; Consider that using a tag-path-based element id one can “easily” define the value encodings of an encoded structured value of any structure semantics.

==&gt; Defining a tagging-scheme of an SPDH message one may provide a tag-path-list that defines each element value encoding.

==&gt; The tag-path-list itself may be encoded in the same way regardless of the encoding of the data to decode?

…

7) Consider that originally BERTLV was intended to define both structure and value encoding semantics?

==&gt; Note that BERTLV is part of ASN.1 and defined in X.690 (“Information technology – ASN.1 encoding rules: Specification of Basic Encoding Rules (BER), Canonical Encoding Rules (CER) and Distinguished Encoding Rules (DER)”)

“This Recommendation | International Standard defines a set of Basic Encoding Rules (BER) that may be applied to values of types defined using the ASN.1 notation."

==&gt; In BER the structure encoding semantics is used to express primitive or constructed elements.

==&gt; In BER the value encoding is defined by the Identifier octets encoding the ASN.1 tag (class and number) of the type of the data value.

“The identifier octets shall encode the ASN.1 tag (class and number) of the type of the data value.”

==&gt; It seems EMV, iPOS and PPL all break this ASN.1 convention and use the identifier for element identification instead of type and value identification?

…

Consider to elaborate on this idea of modelling encodings as structure encoding and value encoding semantics?

...

{% endraw %}
