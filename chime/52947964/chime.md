# Todo: Consider an immutable file system where applications registers there file references (to enable the file system to enforce file dependencies)?

```#52947964``` *As of 2019-03-12 21:12*

[mail plain/text](mail.txt)

{% raw %}
It seems a key feature of an immutable file system would be to ensure application projects file dependencies are not easily broken?

1) Consider to build-in a file-reference-aggregate for application to store to tell the file system about referenced files?

==&gt; Consider in this way the File System gets to know about files that reference other files as defined by proprietary applications?

==&gt; Consider in this way we do NOT have to implement a general "file alias" mechanism in the File System?

==&gt; Or...Maybe we actually need the file system to know about file references (to be able to model existing file systems alias and short-cut mechanisms)?

...

2) Consider ways to implement file aliases?

==&gt; Consider to Tha-model the file system with name, enumeration and hash keys and key-paths?

==&gt; Consider we can then allow for Tha-objects that themselves store such a key or key-path (implements indirection)?

==&gt; But then, how can Tha as an immutable data structure take into account indirected references (to track what has been mutated)?

==&gt; How can we prevent or at least detect circular references caused by indirections?

...

3) Consider to what degree we can implement this immutable file system in Darwinet (A Tha-model that IS a file system)?

==&gt; Consider if we "simply" implemented the Immutable file system as a Darwinet Tha (for now disregarding the inefficiency due to the overhead)?

...

{% endraw %}
