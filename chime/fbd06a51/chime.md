# Todo Tha C++ - Consider ways to defines "class" meta-3 value using C++ syntax?

```#fbd06a51``` *As of 2017-08-06 00:22*

[mail plain/text](mail.txt)

{% raw %}
Could it be possible to propose a definition of C++ class in Tha C++ by re-using C++ syntax on meta-3 values?

==&gt; Also see “[Todo: C++ Meta - Consider to write a blog post and Lightning talk on Herb Sutter Metaclass proposal using Tha model?](../ec963a37/chime.md)"

1) Consider to define a C++ class declaration using the Tha model?

==&gt; It seems a “struct” is in fact just a list (array) of bound (declared or defined) identifiers?

> struct A {  
> A(int x, int y) : m_x(x), m_y(y) {}  
> int m_x;  
> int m_y;  
> };  
> A a = {1,2};

==&gt; So A is a meta-2 value (a type) with two declared data members and one member constructor function?

==&gt; But then “struct” is a meta-3 value (type constructor) that constructs a meta-2 value (type) from provided meta-1 declarations AND definitions?

==&gt; Q: Is it not a bit strange that a meta-3 value operates on meta-1 value arguments?

==&gt; And how do we allow both data declarations (m_x and m_y) and constructor definition to be passed to “struct”?

declaration: int m_x;

declaration: int m_y;

declaration: A(int x, int y);

==&gt; It seems the constructor is in fact a function declared in the namespace “A”?

2) Consider we can actually write a Tha data model in C++ and use that one to show meta-level code on meta-values?

==&gt; See “/Users/kjell-olovhogdahl/BitTorrent Sync/XCode/MyThaCppPlayground/MyThaCppPlayground”

…

…

Consider to keep on experimenting until we get something simple to show of (Meeting C++ talk and/Or blog-post or paper)?

...

{% endraw %}
