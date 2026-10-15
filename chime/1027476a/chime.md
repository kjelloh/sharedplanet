# Todo: Optimus Prime - Consider to make oprime a domain that treats also document generators as "transforms" between "representation domains"?

```#1027476a``` *As of 2015-12-28 17:04*

[mail plain/text](mail.txt)

{% raw %}
Studying different moment generation tools and domain (e.g. Doc-to-help, Doxygen, DocBook format) it seems we should be able to treat document generation as a “transformation” in the same sense as protocol encoding and source code compilation are transformations between representation domains?

1) Consider to elaborate on the idea that a document generator transforms documentation source (e.g. some markup language in SGML, XML or source code comments) into targets (transforming the representation whilst keeping the “type”)?  
2) Imagine having oprime define a type-domain for “documentation” or “human readable information” to handle document generation as “transformations” between such representations?  
3) If so, oprime should also be able to use meta-information for document source to guide what transformation to perform (e.g. Doc-to-help defines projects that defines how different targets are built)?  
4) Consider to make a C++ oprime library that helps programmers to define and build different representation transformation engines?  
==&gt; Protocol encode/decode is one domain with sub-domains for known protocol data structures (e.g. TCP/IP, SPDH, ISO 8583)?  
==&gt; Source code pre-process/compile/link transforms  
==&gt; Documentation representation tarsnforms  
…

5) The general concept seem to be we have a source representation in the form a file of bytes that, using a builder (i.e. a transformer) creates a target representation?  
…

Consider to elaborate on this idea and see if it holds for documentation transformation and also if we can imagine a C++ oprime library to help implementing such “transformers”?  
...

{% endraw %}
