# Todo: C++ KeyPath&lt;&gt; - Consider to enable a KeyPath to be made up of a series of different KeyPaths to handle mixing of Key Node types

```#9a8ce179``` *As of 2015-11-26 13:45*

[mail plain/text](mail.txt)

{% raw %}
The TestBench application applies Key Paths carrying nodes of different types. This leads to problems when matching and parsing to/from string representation.

1) Consider to require each KeyPath to us sonly one strictly typed Node.  
2) Instead enable a Key Path to be made up of several Key Paths, each allowed to be based on different Node types.  
3) This would allow for a Key Path to define a path into a Composite of sub-grouped composites each having using different types of keys to match instances?

==&gt; We may have the first part of the key path identify a signal Id for an action to send a message followed by a tail path identifying a data structure of a message to send.

4) Each KeyPath may then define its own operators (e.g. the toString and fromString) that works with the node types of that key path?

5) How do we define a Key Path Array so that it may be applied in a similar way as a single Key Path would?

==&gt; Do we even care? If we define a Key Path Array we may presume we also need to know what part to apply to what structure (context)?

6) Consider to add KeyPathArray&lt;T&gt; as std::vector&lt;KeyPath&lt;T&gt; &gt; and see how that works out in TestBench application?

==&gt; Does this solve the problem of toString and fromString fro different Key Path Node types?  
…

Consider to elaborate on this idea to see if this is a good approach to the ”Key Path” design pattern?

a) Does this allow defining a Key Path that first defines directory location of an xml-file then followed by a key path into the xml-structure?  
b) Can we imagine other cool features we may use this Key-path-array mechanism for?  
...

{% endraw %}
