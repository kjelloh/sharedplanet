# Todo: Seems a Data Aggregation Structure Model could be represented as a graph of "aggregates" edges?

```#092ce637``` *As of 2015-10-10 14:50*

[mail plain/text](mail.txt)

{% raw %}
Could it be that a Data Aggregation Structure model could be represented as a model graph with ”aggregates” edges?

1) Each Element of the data structure is either a primitive data element or a composite data element.  
2) A composite data element may be modelled as a node that lists the data element it aggregates (ordered array of models)  
3) Thus, the whole data structure may be modelled as nodes that realtes to sub-nodes where the relation is always ”aggregates”.  
…

Elaborate on this approach and find a way to prove that it works and then document it for future usage.

a) Consider to test the approach on TestBench ”interface” concept? May implemented interface-concept be refactored into a graph of model nodes and ”aggregates” relations (each such relation defining also Cardinality)?  
b) With this approach higher level of data relations like ”reference” (e.g. an element encoding an index of an element array at another location in the structure) becomes the concern of application layer (or the encode/decode layer)?  
c) Or, can we imagine to repeat the modeling approach in ”layers” where encoding becomes transforming to lower layers and decoding becomes transforming to higher layers?  
...

{% endraw %}
