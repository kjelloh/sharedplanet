# Todo: Programming - Consider to understand MPL Placeholders _1, _2 etc?

```#aa54e7ce``` *As of 2016-03-18 13:44*

[mail plain/text](mail.txt)

{% raw %}
So, how does C++ Boost Template Meta Programming Library placeholder _1, _2 and so on, actually “work”?

1) Consider to see what we can learn from “C++ Template Metaprogramming” by David Abrahams and Aleksey Gutrovoy?

// page 42

// Iterates two sequences of types in parallel and creates a new sequence of elements BinaryOperation&lt;T1,T2&gt;::type

template &lt;class Sequence1, class Sequence2, class BinaryOperation&gt;

struct transform;

// Page 43

// mpl::plys binary operator

// result will be initialised to compile time calculated value 5.

int result = mpl::plus&lt;mpl::int_&lt;2&gt;, mpl::int_&lt;3&gt; &gt;::type::value;

// From page 43 we deduce we can’t provide mpl::plus as template parameter for BinaryOperator (it is not a type but a template)

// Note: This is “old” C++? We now allow Template template parameters?

…

typedef mpl::transform&lt;D1,D2, **mpl::plus**&gt;::type type; // Wont compile, mpl::plus is a *template*, not a *type*

// Page 44, mpl::transform expects BinaryOperator to be a Metafunction class (a class with template function member apply)

struct plus_f {

template &lt;class T1, class T2&gt;

struct apply {

typedef typename mpl::plus&lt;T1,T2&gt;::type type;

};

}

// This is the preferred way to pass Metafunctions round as types (possible template parameters)

…

typedef mpl::transform&lt;D1,D2, **plus_f**&gt;::type type; // **Ok**. plus_f is a Metafunction class. mpl::transform will “call" plus_f::apply&lt;T1,T2&gt; (i.e. compile plus_f::apply&lt;T1,T2&gt;::type)

// At page 47 they define a shortcut to writing the boilerplate Metafunction class plus_f

…

typedef mpl::transform&lt;D1,D2, **mpl::plus&lt;_1,_2&gt; **&gt;::type type; // Ok (?). mpl::plus&lt;_1,_2&gt; is a Metafunction class with member apply with the following properties

mpl::plus&lt;**_1**,**_2**&gt; &lt;==&gt; template &lt;class **A1**, class **A2**, class A3, class A4&gt;

struct plus {

template &lt;class T1 = **A1**, class T2 = **A2**&gt;

struct apply {

typedef typename plus_impl&lt;T1,T2&gt;::type type;

}

};

mpl::plus&lt;**_3**,**_1**&gt; &lt;==&gt; template &lt;class **A1**, class A2, class **A3**, class A4&gt;

struct plus {

template &lt;class T1 = **A3**, class T2 = **A1**&gt;

struct apply {

typedef typename plus_impl&lt;T1,T2&gt;::type type;

}

};

// Page 54, A placeholder is a metafunction class of the form template &lt;int N&gt; struct arg.

template &lt;int N&gt; struct arg; // forward

struct void_; // No type

template &lt;&gt;

struct arg&lt;1&gt; {

template &lt;class A1, class A2 = void_, class A3 = void_ /\* … and so on \*/&gt;

struct apply {

typedef A1 type; // “Return” the first argument, i.e. apply::type is the type A1

};

}

typedef arg&lt;1&gt; _1;

template &lt;&gt;

struct arg&lt;2&gt; {

template &lt;class A1, class A2, class A3 = void_ /\* … and so on \*/&gt;

struct apply {

typedef A2 type; // “Return” the second argument, i.e. apply::type is the type A2

};

}

typedef arg&lt;2&gt; _2;

// On page 50 they recognise that mpl::plus&lt;mpl::int_&lt;2&gt;, mpl::int_&lt;3&gt; &gt; is different from mpl::plus&lt;_1,_2&gt;

typedef mpl::plus&lt;mpl::int_&lt;2&gt;,mpl::int_&lt;3&gt; &gt;::type concrete_plus; // Ok. type is mpl::int_&lt;5&gt;.

typedef mpl::plus&lt;_1,_2&gt;::type lamda_plus; // Fails (?). _1 and _2 are Metafiction classes, not Metafunctions.

// _1::apply&lt;T&gt;: IS a metafunction.

// At page 51 they define the mpl::lamda metafunction to cope with this.

// mpl::lambda generates an anonymous Metafiction Class from provided Metafunction.

==&gt; To re-capitulate

==&gt; Metafunctions are **Templates** with member type executed by compiling meta_function&lt;Args&gt;::type.

==&gt; Metafiction Classes are **Class Types** with template member apply executed by compiling meta_function_class::apply&lt;Args&gt;::type.

==&gt; Lamda Metafunctions are unnamed Metafunction Classes created by mpl::lamda metafunction executed by compiling mpl::lambda&lt;meta_function&gt;::apply&lt;Args&gt;::type;

==&gt; The apply metafunction does the same job when compiled as mpl::apply&lt;meta_function,Args&gt;::type.

==&gt; Thus, if we have a meta_function “called” with place-holders we get mpl::lamda metafunction executed by compiling mpl::lambda&lt;meta_function&lt;_1&gt; &gt;::apply&lt;Args&gt;::type;

==&gt; And when used in call to apply as mpl::apply&lt;meta_function&lt;_1&gt;,Args&gt;::type;

…

**WE ARE HERE...**

{% endraw %}
