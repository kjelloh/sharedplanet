# Todo: Design Darwinet iterators that visits data in domains and performs big-data analysis

```#61d42a1d``` *As of 2015-09-12 22:24*

[mail plain/text](mail.txt)

{% raw %}
With darwinet is should be possible to analyze big-data although it is not centrally stored by designing iterators that visits data in nodes in domains.

1) An iterator is a function that may be transferred between nodes and vist data at the node. In this way the data does not need to be stored with the analysis. Instead the analysis vista the data.  
2) The Iterator needs to be able to carry state (integrated results from visited data)  
3) Iterators needs to ber able to navigate. Design a way to enable Iterators to find the data it needs to visit?  
4) Compare this idea with distributed data processing. Is this just plain distributed computation or is this a new way of look at data processing?  
...

{% endraw %}
