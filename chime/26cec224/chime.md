# Todo: C++ - Consider to delve into good talks on Functional C++ e.g.,  by Phil Nash and Kevlin Henney?

```#26cec224``` *As of 2017-01-21 20:11*

[mail plain/text](mail.txt)

{% raw %}
So, the guy that seems to have put me on track to understand functional concepts in programming languages is Scott Wlaschin, it is also interesting to find good leads to how to actually leverage these concepts in C++?

1) Consider this page by with links to recommended C++ Functional programming talks (http://www.levelofindirection.com/storage/FCPPRefs.html)?

...

2) Consider talks by Phil Nash?

==&gt; ”Functional C++ for Fun and Profit by Phil Nash” (https://www.youtube.com/watch?v=YgcUuYCCV14)?

==&gt; At 11:00 he proposes C++ alreade have map, filter and reduce ”functional” functions

std::transform == map  
std::copy_if == filter  
std::accumulate == reduce

==&gt; But how can std::transform be the ”map” (In functional programming map returns a lifted function, not the actual execution of the lifted function)?

==&gt; std::transform creates a new output range by applying a function to each element in an input range

Vector&lt;T&gt; —&gt; Vector&lt;U&gt;  
F  
^  
|  
map  
|  
f  
T —&gt; U

==&gt; So yes, execution of std::transform(Vector&lt;T&gt;, Vector&lt;U&gt;,f) is kind of execution of F: Vector&lt;T&gt; —&gt; Vector&lt;U&gt;, i.e. F(Vector&lt;T&gt;)  
…

==&gt; Immutable data structures do not need a default constructor (we need to create it with its value)  
...

3) Consider talks by Kevlin Henney

==&gt; ”Functional C++ - Kevlin Henney" on NDC Norway 2016 (https://vimeo.com/131640207)?  
…

…

Consider to follow up on leads by these presenters into ideas on how to best do Functional C++ :)  
...

{% endraw %}
