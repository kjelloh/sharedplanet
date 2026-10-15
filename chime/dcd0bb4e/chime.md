# Todo: C++ - Study Interface-factory idiom versus pimpl idiom for code separation purposes

```#dcd0bb4e``` *As of 2015-11-27 15:48*

[mail plain/text](mail.txt)

{% raw %}
For C++ it seems we have two main mechanisms to use for code separation

A) The pimpl idiom (pointer to implementation)  
B) The interface + factory idiom

1) If the visible class represents an Entity and is only construct/destruct-able (no copy, move or assignment) then the interface + factory would be preferred?

==&gt; Class instances are never used in STL for value copy/assign/move, thus having factory as only external creation method is fine.  
==&gt; class instances may still be used in STL by manipulating pointer references (storing, iterating, sorting)

2) Only if the visible class represents a Value would the pimpl-idiom be the way to separate code?

==&gt; Class instances are copied, moved or assigned (e.g. the act as values)

3) Care should thus be taken to implement classes in code according to “what they represent” (Value or Entity)?

4) What about specialisation? The pimpl idiom allows inheriting class to specialise private methods (still hiding private data in the pimpl)

==&gt; Specialisation requires access to full interface (public, protected, private) and thus can’t be separated from inheriting class.  
==&gt; Data may still be pimpl-ed if proper accessors are provided in the visual interface.  
…

Ok, so theres quite complicated and a lot to take into account when trying to spare code for faster compilation and re-use?  
...

{% endraw %}
