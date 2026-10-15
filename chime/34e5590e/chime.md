# Todo: http://emergenceawareprogramming.blogspot.se - "C++ decltype Meta Functions"

```#34e5590e``` *As of 2017-04-01 16:25*

[mail plain/text](mail.txt)

{% raw %}
”In C++14 we can hide function return types within the function itself. Combined with decltype this opens up for a different way to write type returning Meta Functions.

##

Consider this C++14 construct. Function f returns local (hidden) type.

struct input_type_1 {};

auto f(const input_type_1&) {

struct result_type_1 {};

return result_type_1();

}

This allows us to define a Meta Function F that creates the type returned by f.

struct input_type_1 {};

auto f(const input_type_1&) {

struct result_type_1 {};

return result_type_1();

}

template &lt;typename T&gt;

using F = decltype(f(T()));

We can now use f **overloading** to compute different return types.

struct input_type_1 {};

struct input_type_2 {};

auto f(const input_type_1&) {

struct result_type_1 {};

return result_type_1();

}

auto f(const input_type_2&) {

struct result_type_2 {};

return result_type_2();

}

template &lt;typename T&gt;

using F = decltype(f(T()));

Result of F can now be accessed only through ”calling” F.

Compare with how we normally define Meta Functions using Template Specialization. F as return type of f is more direct.

struct input_type_1 {};

namespace detail {

struct result_type_1 {};

template &lt;typename T&gt;

struct F {};

template &lt;&gt;

struct F&lt;input_type_1&gt; {

using type = result_type_1;

};

}

template &lt;typename T&gt;

using F = typename detail::F&lt;T&gt;::type;

F as template specialization ”leaks” the return type (It is accessible outside F). F as return type of f is accessible ONLY as return type of f, result of F.

Back to our decltype based Meta Function.

template &lt;typename T&gt;

using F = decltype(f(T()));

F can compute only input types that can differentiate in function overloading (<http://en.cppreference.com/w/cpp/language/overload_resolution>). Could be a good or a bad thing? At least it is interesting?

While in ordinary template specialization we may apply the full range of type computation rules (<http://en.cppreference.com/w/cpp/language/template_specialization>). They are more powerful, which can be good, but also more complicated and obscure which can be a bad thing when this power is not required?

Thats all for now. Question is, can we use Meta Functions as decltype of f return type for anything meaningful?

Feel free to comment!

"

{% endraw %}
