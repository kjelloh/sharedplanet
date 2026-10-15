# Todo: C++ - Consider to explain this Monad example using my value, type, template abstraction layer model?

```#36b286b9``` *As of 2017-01-10 18:23*

[mail plain/text](mail.txt)

{% raw %}
Consider this blog post (<http://cpptruths.blogspot.se/2017/01/folding-monadic-functions.html>) may be better explained and understood if described using the value, type, template layers of abstraction I have identified in previous Monad, Monoid and C++ functional programming discussions?

1) Consider this code from the blog post (<http://cpptruths.blogspot.se/2017/01/folding-monadic-functions.html>) is an example of meta functions taking both template and types as input parameters?

`template``&lt;``template` `&lt;``typename``&gt; ``class` `M&gt;`

`struct` `monad `

`{ `

` ``template` `&lt;``class` `T, ``class` `Func&gt;`

` ``static` `auto` `bind(M&lt;T&gt;& m, Func&& func) -&gt; result_type_t&lt;Func&gt;;`

`};`

==&gt; monad is a meta function that takes a Template M and returns a type (a struct) (monad&lt;M&gt; is some struct type)

==&gt; monad&lt;M&gt;::bind is a meta function that takes two types T and F and returns a function (monad&lt;M&gt;::bind&lt;T,F&gt; is a function)

==&gt; result_type is a meta function that takes a type F and return a type (result_type&lt;F&gt; is the return type of function monad&lt;M&gt;::bind&lt;T,F&gt;)

==&gt;

2) Consider to elaborate on the problem with C++ obscurity what meta functions actually returns?

==&gt; M&lt;T&gt; does not reveal in its semantics what the result will be

template &lt;typename T&gt;

using M = std::vector&lt;T&gt;;

==&gt; Then M&lt;T&gt; will ”return” std::vector&lt;T&gt;

template &lt;typename T&gt;

struct _M {

const int value = 3;

};

template &lt;typename T&gt;

const auto M = _M&lt;T&gt;::value;

==&gt; Then M&lt;T&gt; will be the integer value 3.

// <http://en.cppreference.com/w/cpp/language/variable_template>  
template &lt;typename T&gt;  
int M = 4;

==&gt; M&lt;T&gt; will be integer 4;

template &lt;typename T&gt;

struct _M {

template &lt;typename U&gt;

struct meta {};

};

template &lt;typename T&gt;

using M = _M:: template meta;

==&gt; DOES NOT COMPILE! C++ does not allow using to define an alias for a template (<http://en.cppreference.com/w/cpp/language/type_alias>)!

==&gt; It does not seem to be a way to make M&lt;T&gt; to semantically be a template?

…

Consider to elaborate more on this model of C++ meta functions being able to operate on each, end between each, levels of integral values, types and templates?

{% endraw %}
