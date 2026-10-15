# Todo: Programming - Consider to document how to configure Xcode to use boost?

```#d228368b``` *As of 2018-04-24 12:02*

[mail plain/text](mail.txt)

{% raw %}
So, making Xcode use boost libraries does not come by itself as it seems.

-1) Multiple Search Paths MUST be entered using white space separation AND enclosed in “”!!

==&gt; 180424 - They seem to have enhanced the IDE (not I get a drop-down to add multiple paths)?

![](<Screen Shot 2018-04-24 at 11.59.21.png>)

==&gt; This draw me crazy!

==&gt; The only way I could get Xcode to accepts multiple search paths was to enclose them with “” and separate them with spaces!

==&gt; Note; Xcode gives NO ERROR if one enters paths wrongly!

==&gt; E.g., it is easy to try separation using ‘;’. The only error is that only the last path is actually then used (causing #include errors for files in preceding paths)!!

**THIS SUCKS!!**

1) Boost libraries see to be installed at “/usr/local/include” and “/user/local/lib”?

==&gt; It seems one has to set the “Search Paths” of the target to the path to the boost include folder?

![](<Xcode Boost library settings.tiff>)

==&gt; Select Project root node.

==&gt; Select &lt;Build Settings&gt;

==&gt; Expand &lt;Search Paths&gt; (Note that entries seems to be ordered in alphabetic order?)

==&gt; “Header Search Paths” = **/usr/local/include**

==&gt; “Library Search Paths” = **/usr/local/lib**

==&gt; NOTE: I installed boost with **Brew package manager** (install location thus /usr/local/include and /usr/local/lib)

==&gt; NOTE: Searching the web seem to indicate that if boost is installed with sudo apt gets the same result (<https://www.youtube.com/watch?v=G3MbSpLWAbk>)?

2) I was now able to compile and run this code

//

// main.cpp

// MyZipIteratorPlayground

//

// Created by Kjell-Olov Högdahl on 15/07/16.

// Copyright © 2016 Kjell-Olov Högdahl. All rights reserved.

//

#include &lt;iostream&gt;

#include &lt;vector&gt;

#include &lt;functional&gt;

#include &lt;boost/iterator/zip_iterator.hpp&gt;

struct zip_func :

public std::unary_function&lt;const boost::tuple&lt;const double&, const int&&gt;&, void&gt;

{

void operator()(const boost::tuple&lt;const double&, const int&&gt;& t) const

{

std::cout &lt;&lt; t.get&lt;0&gt;() &lt;&lt; " , " &lt;&lt; t.get&lt;1&gt;() &lt;&lt; "\\n";

}

};

int main(int argc, const char \* argv&#91;&#93;) {

// From

std::vector&lt;double&gt; vect_of_doubles = {1,2,3,4,5};

std::vector&lt;int&gt; vect_of_ints = {10,20,30,40,50};

std::vector&lt;double&gt;::const_iterator beg1 = vect_of_doubles.begin();

std::vector&lt;double&gt;::const_iterator end1 = vect_of_doubles.end();

std::vector&lt;int&gt;::const_iterator beg2 = vect_of_ints.begin();

std::vector&lt;int&gt;::const_iterator end2 = vect_of_ints.end();

std::for_each(

boost::make_zip_iterator(

boost::make_tuple(beg1, beg2)

),

boost::make_zip_iterator(

boost::make_tuple(end1, end2)

),

zip_func()

);

return 0;

}

{% endraw %}
