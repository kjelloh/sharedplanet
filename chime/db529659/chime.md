# Todo: C++ - Consider to write blog post about meta functions and their ability to process value, type and template parameters?

```#db529659``` *As of 2017-01-10 11:34*

[mail plain/text](mail.txt)

{% raw %}
In C++ it is possible to write functions executed at compile time. These functions may take integral values, types or templates as parameters and return new integral values, types or templates or additionally run-time functions. Yes, you guessed it, these functions are templates, more exactly class or function templates.

Reasoning about templates as compile time executed functions that return types is very powerful and enables reading ”templated" code a lot easier.

Consider the compile time function F. We may define it to take any combination of integrals values, types or templates and return new ”stuff” of the same sort. So, how can we do that?

Consider that F takes some type and returns some other type. In C++ we may write such a meta-function in two basic ways.

The traditional way is to define it as a class template with a member type as the return ”value”.

**struct input_type_1 {/\* … \*/};**

**struct return_type_1 { /\* … \*/};**

**template &lt;typename T&gt;**

**class _F {}; // Primary template. error if used (return type unknown)**

**template &lt;&gt;**

**class _F&lt;input_type_1&gt; {**

**using type = return_type_1;**

**};**

**template &lt;typename T&gt;**

**using F = _F&lt;T&gt;::type;**

With this code we may write F&lt;some_type&gt; to ”execute” F at compile time and get the returned type to use for something.

In C++14 we can encapsulate the return type as return type of functions and use decltype to calculate it at compile time.

**struct input_type_1 {/\* … \*/};**

**auto _F(const input_type_1&) {**

**struct return_type_1 { /\* … \*/};**

**return return_type_1();  **

**}**

**template &lt;typename T&gt;**

**using F = decltype(_F(T()));**

And now we can use F&lt;some_type&gt; to ”execute” F at compile time and use the returned type for something interesting.

Now, realizing that C++ allows template parameters to be any combination of integrals values, types and templates we may expand this thinking to allow F to take and return any combinations of these.

**struct input_type_1 {/\* … \*/};**

**struct return_1 {**

**struct type { /\* … \*/ };**

**const int value = 3;**

**template &lt;…&gt;**

**struct result_template_1 { /\* … \*/ }**

**};**

**template &lt;typename T&gt;**

**class _F {}; // Primary template. error if used (return type unknown)**

**template &lt;&gt;**

**class _F&lt;input_type_1&gt; {**

**using type = return_1;**

**};**

**template &lt;typename T&gt;**

**using F = _F&lt;T&gt;::type;**

Using this code we are suddenly free to define any return type members depending on the provided inout parameters (which in turn may be any combination of integral values, types or templates)!

We do not have these options for functions that return encapsulated types. We may then overload only on types! But the returned type may have any combination of integral value, type or template!

**struct input_type_1 {/\* … \*/};**

**auto _F(const input_type_1&) {**

**struct return_1 {**

**struct type { /\* … \*/ };**

**const int value = 3;**

**template &lt;…&gt;**

**struct result_template_1 { /\* … \*/ }**

**};**

**return return_1();  **

**}**

**template &lt;typename T&gt;**

**using F = decltype(_F(T()));**

The basic pattern to see here is how we are able to pass integral values, types and templates to compile time functions and get any combination of integral values, types and templates back.

- F&lt;input_value_1, input_type_1, input_template_1&gt; may return any combination of return_value_1, return_type_1 and return_template_1.

...

{% endraw %}
