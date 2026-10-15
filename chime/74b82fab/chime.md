# Todo: C++ - Consider ways to implement Composites as recursive variants?

```#74b82fab``` *As of 2017-07-04 09:15*

[mail plain/text](mail.txt)

{% raw %}
The Self-recursive Composite pattern keeps popping up and it would be nice to represent it using variants that recurse to ”itself” (self referential variant structure)?

1) Consider Vittoria Romero C++Now 2017 talk ”C++Now 2017: Vittorio Romeo “Implementing \`variant\` visitation using lambdas”” at 39:00 (<https://youtu.be/3KyW5Ve3LtI?list=PL_AKIMJc4roXJldxjJGtH8PJb4dY6nN1D&t=2339>)?

==&gt; Also see Vittorias web-page blog post (<http://vittorioromeo.info/index/blog/variants_lambdas_part_3.html>)?

==&gt; He seems to take advantage of something calls the ”Y combinator” (<https://en.wikipedia.org/wiki/Fixed-point_combinator#Fixed_point_combinators_in_lambda_calculus>)?

==&gt; This seems to be a stackoverflow thread stating an Y-combinator in C++ (<https://stackoverflow.com/questions/152084/fixed-point-combinators-in-c/154267#154267>)?

==&gt; Implemented as Synced ”/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyYCombinatorPlayGround"

> //  
> // main.cpp  
> // MyYCombinatorPlayGround  
> //  
> // Created by Kjell-Olov Högdahl on 2017-07-01.  
> // Copyright © 2017 Kjell-Olov Högdahl. All rights reserved.  
> //

> // From <https://stackoverflow.com/questions/152084/fixed-point-combinators-in-c/154267#154267>

> #include &lt;iostream&gt;  
> #include &lt;boost/bind.hpp&gt;  
> #include &lt;boost/function.hpp&gt;

> // Y-combinator compatible factorial  
> int fact(boost::function&lt;int(int)&gt; int_to_int,int v) {  
> if(v == 0) {  
> // Terminate  
> return 1;  
> }  
> else {  
> // Recurse  
> return v \* int_to_int(v -1);  
> }  
> }

> // Y-combinator for the int type  
> boost::function&lt;int(int)&gt;  
> y(boost::function&lt;int(boost::function&lt;int(int)&gt;,int)&gt; f_and_int_to_int) {  
> return boost::bind(f_and_int_to_int,boost::bind(y,f_and_int_to_int),_1);  
> }

> int main(int argc,char\*\* argv) {

> {  
> // std::cout &lt;&lt; y(fact)(5) &lt;&lt; std::endl;  
> }

> {  
> boost::function&lt;int(int)&gt; factorial = y(fact);  
> std::cout &lt;&lt; factorial(5) &lt;&lt; std::endl;  
> }

> return 0;  
> }

==&gt; It seems the boost::bind is used in y to recursively return an y´: int -&gt; int, by binding first (int-&gt;int) to the provided function (<http://www.boost.org/doc/libs/1_61_0/libs/bind/doc/html/bind.html>)?

==&gt; It seems y is a function: (int -&gt; int) -&gt; int -&gt; (int -&gt; int) (i.e., it takes a function: int -&gt; int and an int, and returns a function int-&gt;int with the function argument bound)?

==&gt; Thus: **y**:  (int -&gt; int) -&gt; (int -&gt; int)

==&gt; And **fact**:  (int -&gt; int) -&gt; int -&gt; int

==&gt; So, y and fact are NOT of the same type

==&gt; But fact take y as first argument and y take fact as first argument?

-&gt; y(fact) = fact(y,x)

^ |

| |

-----\\ /-----

X

|----/ \\---------

| |

v |

fact(y,x) = x \* y(x - 1) | 1

|

v

==&gt; Stepping through code gives this recursion:

> boost::function&lt;int(int)&gt; factorial = y(fact);

> // Recurse v = 5..0

> > boost::function&lt;int(int)&gt; y(boost::function&lt;int(boost::function&lt;int(int)&gt;,int)&gt; f) {

> > return boost::bind(f,boost::bind(&y,f),_1);

> > }

> > int fact(boost::function&lt;int(int)&gt; f,int v = **5**) {

> > return 5 \* f(4);

> > }

> > boost::function&lt;int(int)&gt; y(boost::function&lt;int(boost::function&lt;int(int)&gt;,int)&gt; f) {

> > return boost::bind(f,boost::bind(&y,f),_1);

> > }

> > int fact(boost::function&lt;int(int)&gt; f,int v = **4**) {

> > return 4 \* f(3);

> > }

> > boost::function&lt;int(int)&gt; y(boost::function&lt;int(boost::function&lt;int(int)&gt;,int)&gt; f) {

> > return boost::bind(f,boost::bind(&y,f),_1);

> > }

> > int fact(boost::function&lt;int(int)&gt; f,int v = **3**) {

> > return 3 \* f(2);

> > }

> > boost::function&lt;int(int)&gt; y(boost::function&lt;int(boost::function&lt;int(int)&gt;,int)&gt; f) {

> > return boost::bind(f,boost::bind(&y,f),_1);

> > }

> > int fact(boost::function&lt;int(int)&gt; f,int v = **2**) {

> > return 2 \* f(1);

> > }

> > boost::function&lt;int(int)&gt; y(boost::function&lt;int(boost::function&lt;int(int)&gt;,int)&gt; f) {

> > return boost::bind(f,boost::bind(&y,f),_1);

> > }

> > int fact(boost::function&lt;int(int)&gt; f,int v = **1**) {

> > return 1 \* f(0);

> > }

> > boost::function&lt;int(int)&gt; y(boost::function&lt;int(boost::function&lt;int(int)&gt;,int)&gt; f) {

> > return boost::bind(f,boost::bind(&y,f),_1);

> > }

> > int fact(boost::function&lt;int(int)&gt; f,int v = **0**) {

> > return 1

> > }

==&gt; ...

2) Consider to try out using std::optional as indirection for the variant self-reference?

...

…

Consider to elaborate more on how to implement recursive variants?

...

{% endraw %}
