# Todo: Programming - Consider to try the same component front-end for Tinyxml2 and pugixml?

```#7cc078a5``` *As of 2016-10-10 23:53*

[mail plain/text](mail.txt)

{% raw %}
Consider to use the existing component front-end in macbook Air ”/Users/kjell-olov/Documents/XCode/MyXMLComponent” (already using tinyxml2)?

1) The pugixml seems to live here (http://pugixml.org/docs/quickstart.html)?

==&gt; What would it require to ditch tinyxml2 and use pugixml back-end instead?  
…

…

2) Consider even more open source xml libraries for possible back-end?

…

3) Consider both tinyxml2 and pugixml misses the point of separating structure from content?

==&gt; Q: Why do they expose document, element and attribute as different types (they all share the property of being a node with a name and optional value)?  
==&gt; Q: Why does both tinyxml2 and pugixml insist of having the document owning all nodes (when each parent can simply own its childs)?  
...

…

Consider to try out the same component front-end on different xml backend engines?

{% endraw %}
