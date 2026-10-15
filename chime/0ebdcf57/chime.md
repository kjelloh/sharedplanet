# Todo: C++ - Consider to describe function overloading as meta-functions that returns functions based on call signature?

```#0ebdcf57``` *As of 2017-01-11 12:00*

[mail plain/text](mail.txt)

{% raw %}
Could there be a pattern found in identifying C++ function overloading as if there is a hidden meta-function there that returns the overloaded function based on the call signature?

1) Consider this example code of std namespace specialization of advance() for different iterator types (<http://www.boost.org/community/generic_programming.html#tag_dispatching>)?

> ```
> namespace std {
>   struct input_iterator_tag { };
>   struct bidirectional_iterator_tag { };
>   struct random_access_iterator_tag { };

>   namespace detail {
>     template <class InputIterator, class Distance>
>     void advance_dispatch(InputIterator& i, Distance n, input_iterator_tag) {
>       while (n--) ++i;
>     }

>     template <class BidirectionalIterator, class Distance>
>     void advance_dispatch(BidirectionalIterator& i, Distance n,
>        bidirectional_iterator_tag) {
>       if (n >= 0)
>         while (n--) ++i;
>       else
>         while (n++) --i;
>     }

>     template <class RandomAccessIterator, class Distance>
>     void advance_dispatch(RandomAccessIterator& i, Distance n,
>        random_access_iterator_tag) {
>       i += n;
>     }
>   }

>   template <class InputIterator, class Distance>
>   void advance(InputIterator& i, Distance n) {
>     typename iterator_traits<InputIterator>::iterator_category category;
>     detail::advance_dispatch(i, n, category);
>   }
> }
> ```

  
==&gt; The actual function called is determined by the match to the last parameter (the tag)

==&gt; iterator_traits&lt;InputIterator&gt; is in fact a meta-function that returns the traits type for provided Iterator type.

==&gt; Then detail::advance_dispatch can be seen as a meta-function (it has overloads) that returns different functions based on the type of the last parameter?

2) Consider to what degree the hidden meta-functionality provided by function overloading may actually be implemented using explcit meta functionality (on the form F&lt;T&gt;)?

==&gt; Further see ”/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyThreeLevelMetaFunctionExample/MyThreeLevelMetaFunctionExample/FunctionOverloadAsMetaFunctions.hpp” on my 17” laptop

> namespace meta {

> struct tag_type_1 {};  
> struct tag_type_2 {};

> struct T1 {};  
> struct T2 {};

> namespace overload {

> template &lt;typename T&gt;  
> struct T_traits {};

> template &lt;&gt;  
> struct T_traits&lt;T1&gt; {  
> using type = tag_type_1;  
> };

> template &lt;&gt;  
> struct T_traits&lt;T2&gt; {  
> using type = tag_type_2;  
> };

> template &lt;typename T&gt;  
> using tag_type = typename T_traits&lt;T&gt;::type;

> namespace detail {  
> void f(tag_type_1) {}  
> void f(tag_type_2) {}  
> }

> template &lt;typename T&gt;  
> void f(T t) {  
> detail::f(tag_type&lt;T&gt;()); // hidden meta-function returning detail::f(tag_type_1) or detail::f(tag_type_2)  
> }

> void test() {  
> f(T1()); // Will call detail::f(tag_type_1)  
> f(T2()); // Will call detail::f(tag_type_2)  
> }

> }

> namespace specialization {

> template &lt;typename T&gt;  
> struct F {};

> template &lt;&gt;  
> struct F&lt;T1&gt; {  
> void operator()() {}; // "Overload" for type T1  
> };

> template &lt;&gt;  
> struct F&lt;T2&gt; {  
> void operator()() {}; // "Overload" for type T2  
> };

> template &lt;typename T&gt;  
> void f(T t) {  
> F&lt;T&gt;(); // Will select F&lt;T&gt;::operator()  
> }

> void test() {  
> f(T1()); // Will call F&lt;T1&gt;::operator()  
> f(T2()); // Will call F&lt;T2&gt;::operator()  
> }

> }  
> }

==&gt; Here overloading uses detail::f(tag_type&lt;T&gt;()) while direct meta-fucntionality uses F&lt;T&gt;().

==&gt; In this special case the two compile-time mechanisms (overload versus specialization) will work in ”the same way” (rule differences does not show)

==&gt; The semantic advantage of F&lt;T&gt;() is that it clearly separates the meta-fucntion F, its parameters T and the actual run-time call F&lt;T&gt;().

==&gt; The detail::f(tag_type&lt;T&gt;()) does not semantically separate the function selection and the function call (they are one).

...

…

Consider to delve deeper into this idea to regard function overloading as engaging of a hidden compile-time meta-function that returns the correct function o call given the provided call signature?

{% endraw %}
