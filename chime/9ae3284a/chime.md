# Todo: Programming - Consider a good application of Function Currying is to turn constructors into builders (each building a member using a mutable Transient Type)?

```#9ae3284a``` *As of 2017-02-20 13:48*

[mail plain/text](mail.txt)

{% raw %}
It seems a good application of Function Cyrrying is to turn Constructors for records into builders of these structures using function composition?

1) Consider a Constructor in C++ taking member values to use in construction?

struct A {  
private:  
int m_x;  
bool m_b;  
string m_s;  
public:  
A(int x, bool b, string s);  
};

==&gt; Consider the Constructor is in fact a function taking three parameters (one for each member in the struct to construct)?  
==&gt; Consider with Currying we can break down into composition of three functions, each building one member value into A?

A a = builder&lt;A&gt;()  
.x(3)  
.b(false)  
.s(”Wow”);

==&gt; Consider this also enables us to enforce a correct full build of A?

==&gt; It seems we require the client to build A by composing builder functions in the correct order (not leaving one out)?

==&gt; Consider what this would look like in C++?

struct A {  
private:  
int m_x;  
bool m_b;  
string m_s;  
auto s_builder(A& a) {return &#91;&a&#93;(string& s){a.m_s = s; return a;}}  
auto b_builder(A& a) {return &#91;&a&#93;(bool b) {this-&gt;m_b = b; return s_builder(this);}}  
public:  
auto builder() {return &#91;this&#93;(int x) {this-&gt;m_x = x; return b_builder(this);}};  
};

==&gt; Hm… We can do better?  
…

2) Consider the ”Builder Pattern” seems strongly correlated with Clojure ”Transient Types”?

==&gt; It seems the Transient Type is mutable but only to allow it to be ”built” using function composition?  
==&gt; This seems to correspond to the ”builder” functions we get from Currying the Constructor and compose into a builder function (where each intermediate builder operates on a Transient A)?

Builder of A: int —&gt; bool —&gt; string —&gt; A

==&gt; Consider what A and Transient A can look like in C++?

…

…

Consider to elaborate on this idea of applying Currying to transform a C++ constructor into a builder pattern of composition of a builder function for each member of A using a Transient A?  
...

{% endraw %}
