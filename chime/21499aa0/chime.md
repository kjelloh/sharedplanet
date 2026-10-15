# Todo: emergenceawareprogramming.blogspot.se - Expressive PI Estimation Algorithm in C++

```#21499aa0``` *As of 2017-03-11 17:34*

[mail plain/text](mail.txt)

{% raw %}
1) Consider the ”abstractions” we may use to ”tell the story of pi estimation”?

==&gt; Consider telling it using plain (raw) c++ language artifacts (statements and minimum function calls)?

==&gt; See ”brute_force”

==&gt; Consider using the C++ algorithms library?

==&gt; See using std::generate_n, std::for_each and suitable callable?

==&gt; Consider some ”fluent interface” (<https://en.wikipedia.org/wiki/Fluent_interface#C.2B.2B>)?

==&gt; Consider what functions to chain and how to name them to express the algorithm?

==&gt; Consider lazy function composition?

==&gt; Consider using a ”function pipe” operator?

==&gt; Consider what functions to chain and how to name them to express the algorithm?

==&gt; Consider function composition maps to the fluent interface (but fluent interface stores result as state)?

...

==&gt; Consider ”expressiveness” maps to ”composability”?

==&gt; Q: Will expressive code lead to code-pieces that is suitable for flexible compositions?

...

2) Consider ways to use C++ std algorithms in an expressive way?

==&gt; Consider we also want to use them ”lazily” (There are so much intermediate data we do not like to store during computation)?

==&gt; Consider to use std::generate_n to generate the ”test suite” of {radius, point_count} parameter pairs?

==&gt; Consider to use std::transform?

==&gt; Consider we realize we would like a way to enumerate the {n,m} pairs?

==&gt; Consider what we loose in efficiency by generating {n,m} pairs from an enumeration?

...

3) Consider to use a co-routine to generate {n,m} pairs?

==&gt; Consider to write co-routine code in Visual Studio 2017?

**WE ARE HERE...**

==&gt; Consider to argue that the NM co-routine is in fact a state-ful NM Generator (only more efficient as it actually remembers the execution state in the nested n,m loops)?

==&gt; State as execution point does not require calculating {n,m} from severance number (mathematical overhead)?

==&gt; Consider even if we store n,m we still have to re-cerate the increment-algorithm (which in co-routine is encoded as for-loop-code = very efficient)?

...

4) Consider the actual text for blog post to write?

> Expressive PI Estimation Algorithm in C++

> Recently Jonathan Boccara’s announced ”The Pi Day Challenge For The Most Expressive Code In C++” (<http://www.fluentcpp.com/2017/03/02/the-pi-day-challenge-for-expressive-code-in-c/>). A fun little problem with the twist that the solution will be rewarded for being ”expressive”.

> One brute force (or naive) solution to this problem could be to nest two loops to parameterize the problem on a sequence of radiuses and random point count and then just get the work done?

> namespace brute_force {  
> const auto pi_reference = 3.14159265359;  
> const int N = 9; // try radius 10^0 ... 10^N  
> const int M = 7; // Try Random Point Count 10^0...10^M  
> std::random_device random_device;  
> std::mt19937 random_generator(random_device());  
> void do_pi_estimations() {  
> for (int n = 0;n&lt;=N;++n) {  
> for (int m = 0;m&lt;=M;++m) {  
> // Generate radius and point count for our estimation  
> double radius = std::pow(10,n);  
> double point_count = std::pow(10,m);  
> std::uniform_real_distribution&lt;&gt; distribution(-radius, radius); // place origo at center of square/circle  
> double points_in_circle_count{};  
> // Count number of random points within square with side 2xradious that fall within the circle  
> for (double i=0;i&lt;point_count;++i) {  
> double x = distribution(random_generator); // random x in square -radius...radious  
> double y = distribution(random_generator); // random y in square -radius...radious  
> if ((x\*x + y\*y) &lt;= radius\*radius) {  
> // random point {x,y} is in circle according to pythagoras :)  
> points_in_circle_count += 1;  
> }  
> };  
> double pi_estimate = 4\*points_in_circle_count/point_count; // Based on Circle Area / Square Area = Pi/4  
> std::cout  
> &lt;&lt; '\\n'  
> &lt;&lt; "PI Estimate"  
> &lt;&lt; "(radius:" &lt;&lt; radius &lt;&lt; ",point count:" &lt;&lt; point_count &lt;&lt; ") = "  
> &lt;&lt; pi_estimate  
> &lt;&lt; " diff from " &lt;&lt; pi_reference &lt;&lt; " = " &lt;&lt; (pi_reference - pi_estimate);  
> }  
> }  
> }  
> }

> Question is, this code ”expressive”? I find this question interesting. Not the least because as C++ programmers it is so much we like to ”express”. And it is so seldom we take the time to discuss if we express the right thing(s)?

> So, what is it we should express here? Is it how things should be done by the computer? Or is it the motivation to why we do what we do, i.e., the intention with each part of the code?

> I would go for the latter. Motivation being that the compiler will understand anything we throw at it as long as it is valid C++. But humans reading the code will in most cases not. In fact I think we programmers are in fact story tellers. I’ll side with David Heinemeier Hansson in his talk ”RailsConf 2014 - Keynote: Writing Software” (<https://www.youtube.com/watch?v=9LfmrkyP81M>) here.

> Lets try to explain the algorithm in plain english shall we? The algorithm is based on the two realizations. The first is that if we draw a square tightly round a circle we will have ”Area of Circle”/”Area of Square” equal Pi/4 (do the math). The Second is that we can estimate the areas by spraying it with evenly distributed dots and count how may that falls within each shape. Now, that may not be a very efficient way but it should work.

> 1) Create a sequence of ”Square hugged Circles” paired with a ”Point count"  
> 2) For each such pair spray the square with ”Point Count” number of random points.  
> 3) For each such spray - count the number of points that fall within the circle.  
> 4) Now estimate the area fraction ”circle area” / ”square area” with ”point count in circle” / ”total point count”.  
> 5) The Pi estimate is now 4 times the area fraction estimate.

> Now, lets try to express this in C++ code.

{% endraw %}
