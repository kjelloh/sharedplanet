# Todo: Programming - Consider to discuss how to merge the two ways of serializing data (parse based and fixed size based)?

```#7e687309``` *As of 2017-01-11 12:31*

[mail plain/text](mail.txt)

{% raw %}
It seems when tackling how to serialize data all generic approaches talk either about parsed based encoding and fixed size encoding when in fact many protocols requires a mix of both?

1) Consider to base serialization on a composite data model using components with fixed or conditional member element presence?

==&gt; Consider any data structure may be modeled as a composite (leaf or composite members in arbitrary depth)?

==&gt; Consider a composite element to either a set of member elements with unconditional or conditional presence?

==&gt; Consider serialization to incorporate structure serialization, element presence serialization and value serialization?

==&gt; Consider structure serialization to incorporate element order serialization?

2) Consider XML as composite serialization with random element ordering and fixed set of value encoding?

3) Consider ISO 8583 as a composite serialization with fixed element ordering and run-time element presence encoding?

4) Consider BER as composite serialization allowing random element ordering (in fact 1-to-1 mapping to XML possible)?

...

...

{% endraw %}
