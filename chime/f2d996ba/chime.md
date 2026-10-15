# Todo: Tha C++ - Consider a way to enable Tha kinds to mutate constructors and destructors on instantiated class types (although the constructor does not know the name of later binding)?

```#f2d996ba``` *As of 2017-08-10 00:58*

[mail plain/text](mail.txt)

{% raw %}
It seems C++ constructors are designed to instantiate values and thus do not know the name the value may bind to. But class types requires the constructor and destructor members to have the name of the type the type instance binds to!

1) It seems this is a quirk of the C++ language (constructors and destructors should have neutral names)?

…

2) Consider how we can enable Tha C++ to define meta-3 kind constructors that can affect instantiated member constructor and destructor?

==&gt; Consider we need a work-around that mutate the type value when it binds to a name?  
…

…

Consider to elaborate on this problem that constructors instantiate “values” without knowing the name the value may bind to?  
...

{% endraw %}
