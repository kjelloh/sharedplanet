# Todo: C++ - Study and implement the PIMPL Design Pattern

```#49251797``` *As of 2015-11-27 10:02*

[mail plain/text](mail.txt)

{% raw %}
Using the PIMPL (Pointer to Implementation) in C++ one may put only interfaces in header files and isolate all implementation into cpp-files.

1) This seem to be a good description of the basic design (https://tonka2013.wordpress.com/2013/08/31/why-every-c-developer-should-know-about-the-pimpl-idiom-pattern/)

==&gt; Note: This solution means every instance of class will carry a dynamically instantiated _impl (requiring internal new() and delete())  
And dynamic memory has a performance penalty as opposed to state (stack) allocated counterparts.

2) What about Construct/Deconstruct, Copy and Assign of _impl?

…

3) Here is Herb Stutters “fast” PIMPL (http://www.gotw.ca/gotw/028.htm)

==&gt; It removes the dynamic allocation of _impl by having _impl implement its own memory management using list of free memory blocks.  
==&gt; This alos have a cost in that one has to maintain ones own memory allocation/deallocation!

…

Consider to study this more and try it out say on some TestBench header files?

a) What about copy construct and assignment operators?

{% endraw %}
