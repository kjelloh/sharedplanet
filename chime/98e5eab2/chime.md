# Todo: Consider an Arduino based receipt OCR scanner and paper ripper connected to Darwinet domain Tha and eMdividual accounting?

```#98e5eab2``` *As of 2019-01-21 18:36*

[mail plain/text](mail.txt)

{% raw %}
Consider it could be fun to design and optionally build a small Arduino based receipt scanner that OCR captures receipt data and stores it in a shared Darwinet Domain Tha model for access by an eMdividual based accounting app?

1) Consider a receipt scanner built from the dimension of a receipt printer?

==&gt; Consider a mechanism to detect a receipt and then automatically feed the receipt through a line scanner?

==&gt; Consider to use the line scanner of a commercial scanner (diode sensor array)?

…

2) Consider to control and operate the scanner with an Arduino MCU?

==&gt; Consider available Arduino libraries for diode array scanning?

==&gt; Consider available Arduino diode array sensors?

3) Consider available options for OCR processing a scanned receipt?

==&gt; Consider if there are and Arduino libraries to OCR process a scanned receipt into lines of text?

==&gt; Consider to always save the scanned receipt as a bitmap as a base format for storage?

==&gt; Consider to convert the scanned receipt into some compressed image format (jpeg, tiff, ogg…)

…

4) Consider we can use an Intel Neural Compute Stick for OCR processing (and optionally receipt recognition to recognise Point of sale, automatic accounting etc.)?

==&gt; Consider if there are arduino libraries to interact with an Intel neural network compute stick?

==&gt; Consider we may need to use a Raspberry Pi (for Linux libraries to interface Intel neural network compute stick)?

...

5) Consider to have the scanner to feed the receipt into a receipt tearer?

==&gt; Consider to have a receipt buffer in case we need to re-scan a receipt before it is physically destroyed?

...

{% endraw %}
