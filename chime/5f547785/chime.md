# Todo: C++ - Consider a Template as an "Optional Type" and a Type as an "Optional Value"?

```#5f547785``` *As of 2017-02-20 14:37*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to view a C++ template as an optional type and a type as an optional value?

1) Consider how this may be a way to layer templates on top of types on top of values?

Template: List

Type: List&lt;int&gt;

Value: List&lt;int&gt; l;

2) Consider the Compiler is able to perform Compile Time computation on all these three levels (creating a separation between compile-time and runt-time actions)?

Compile Time Run Time

Template: List

Type: List&lt;int&gt;

Value: List&lt;int&gt; my_list; List_Type my_list;

…

Consider to elaborate on this idea of ”layered” compile-time mechanisms template = optional type, type = optional value?  
...

{% endraw %}
