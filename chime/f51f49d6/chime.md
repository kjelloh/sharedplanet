# Todo: Programming - Consider to read and understand "C++ Template Metaprogramming" by Abrahams/Gurtovoy?

```#f51f49d6``` *As of 2016-02-26 12:00*

[mail plain/text](mail.txt)

{% raw %}
Would it not be fun to read and understand C++ Meta Programming better, e.g. by reading "C++ Template Metaprogramming" by Abrahams/Gurtovoy?

1) Consider to list the current top-insights about Template Metaprogramming as I learn the techniques?

==&gt; C++ Meta-functions (MF) operates on types in a similar way runtime functions (RF) operate on values.

==&gt; Meta-Functions could be read as “about functions”

==&gt; C++ Metaprogramming heavily relies on templates instantiated with different types are in themselves different types regardless of provided types are manifested in runtime code!

template &lt;class A, class B&gt;

struct my_struct {};

Then: my_struct&lt;int,int&gt; is NOT the same type as my_struct&lt;int,char&gt;

==&gt; A C++ Meta-function takes template arguments as input and returns a type

MF: Meta-function&lt;Template Args&gt;::type

RF: type function(args)

==&gt; Meta-functions can be seen as “executed” at compile-time (by the C++ compiler) similar to runtime-functions being executed by the computer

==&gt; A C++ Meta-function is “executed” by compiling it!

==&gt; And the result of a Meta-function is a type (optionally a type that carries a constant value type::value)

==&gt; Meta-function execution flow control can use “if” and “recursion” in the form of template-specialisations.

==&gt; “If” is accomplished “calling” a template-specialisation on boolean value true/false (matching appropriate meta-function)

==&gt; Recursion is accomplished by “calling” a new specialisation one one-self (bathing either the same or a terminating specialisation)

// Meta-function “if” example in semi-pseudo-code (Almost C++)

template &lt;bool flag&gt; struct my_if_function {}

template &lt;&gt; struct my_if_function&lt;true&gt; {typedef … type;} // specialised for true

template &lt;&gt; struct my_if_function&lt;false&gt; {typedef … type;} // specialised for false

template &lt;args&gt; struct use_true_instance {const type value = …;} // specialised into struct with a value true or false

template &lt;args&gt; struct my_meta_function { typedef my_if_function&lt;use_true_instance&lt;args&gt;::value&gt;::type type; }

// Meta-function recursion example in semi-pseudo-code (Almost C++)

template &lt;args&gt; struct my_recursive_function {}

template &lt;variable-part&gt; struct &lt;fixed-part&gt; my_recursive_function {typedef my_recursive_function&lt;specialised-args&gt;::type type;} // specialised for recursive “call"

template &lt;&gt; struct &lt;fixed-part&gt; my_recursive_function {typedef static-type type;} // specialised for “termination” call

==&gt; Meta-function execution failures are reported as compile errors

==&gt; BOOST_STATIC_ASSERT() generates a compiler error similar to runtime assert() generates and exception.

==&gt; A Meta-function that operates on and returns other Meta-functions are called Higher-order Meta-function.

==&gt; A C++ Meta-function is a template, not a type (and can thus not be operated on, passed to, a meta-function)

==&gt; A C++ higher-order Meta-Function is implemented as a Meta-function Class (a static type with a template member *apply)*.

==&gt; “Execute” the Meta-function Class “higher_order_meta_function” by compiling higher_order_meta_function::template apply&lt;args&gt;

==&gt; The “result” is also a Meta-function class (a type that also have a member template called apply)

==&gt; A C++ Meta-function can forward its “call” to another Meta-function using C++ inheritance.

==&gt; template &lt;args&gt; struct meta_function : other_meta_function&lt;args&gt; {}

“Executing” meta_function&lt;args&gt;::type will “Execute” inherited other_meta_function&lt;args&gt;::type.

==&gt; template &lt;args&gt; struct higher_meta_function : other_higher_meta_function::template apply&lt;args&gt; {}

“Executing” higher_meta_function::template apply&lt;args&gt; will “Execute” inherited other_higher_meta_function::template apply&lt;args&gt;

==&gt; Meta-function results (types) turn up in the runtime code ONLY if the are used to generate runtime code.

==&gt; Meta-function “execution” can also be used only to yield a compile-time result :)

==&gt; A weird way to display the result is to turn it into a compiler error (readable by the user)!

2) Page 31 seem to sum up the basics of meta-programming in chapter “2.9 Details”

&lt;meta-function programming&gt;

==&gt; C++ Metadata is a “value” (e.g. a type or a type::value) that can be manipulated by the C++ compile time machinery.

==&gt;  The Compile Time Part of C++ shall be seen as a “Pure Functional Language” in that it uses Metadata which can’t be mutated and thus no meta-functions has side effects (are pure)

==&gt; C++ Meta-Functions are template structs on the form meta-function&lt;template parameters&gt;::type

==&gt; C++ Numerical Meta Functions are meta-functions where the ::type has a member ::value (In boost library accessible directly though meta-function&lt;args&gt;::value)

==&gt; Compile-time *Meta-function&lt;Arg1, Arg2&gt;::type* is equivalent of *runtime-function(arg1,arg2)*

==&gt; Avoid “Blobs” (meta-functions that is used to return more than one ::type) as these break polymorphic application of the function.

==&gt; Meta-function Polymorphism refers to “having many forms” and is best leveraged by restricting all meta-functions to the one-form meta-function&lt;args&gt;::type (optionally ::value)

==&gt; A C++ Nullary Meta-function is one that can be called without any type arguments

==&gt; C++ Traits is a technique to non-intrusively use template specialisation to define associations between Metadata.

==&gt; C++ Type Traits is the Boost Meta-Function library to support C++ Traits that returns “traits of types” (using the meta-function&lt;args&gt;::type (::value) idiom)

&lt;template mechanisms&gt;

==&gt; Template specialisation refers to the two cases of 1) Full or partial specialisation declaration and 2) Referred to (written) with all type argument “known” (e.g. in a variable definition)

==&gt; Template specialisation mechanism comprises Primary Template (general with no specialisations) followed by Partial- and Full- Specialisation.

==&gt; Template instantiations happens when meta-function&lt;args&gt;::type is used in a definition (e.g. a variable definition)

==&gt; Template member definitions are NOT instantiated until “accessed in code” (see page 32)

3) Page 17: meta-function-name&lt;type parameters&gt;::type

==&gt; Seems like a good base definition of what a meta-function is (i.e. a compile time function that operates on types)?

4) page 13 initiates traits-type as a meta-function that returns a “blob” with traits about provided type(s)

==&gt; traits-type-name&lt;type(s)&gt;::trait_n seem to be the general form (where trait_n symbolises one to many members that defines the traits)

5) page 16 defines “blobs” with compile-time defined member names (e.g. traits-type members) as an anti-pattern (an idiom to avoid)

==&gt; “Blobs” contains polymorphism in that one can only provide blobs with the correct compile-time named members.

6) Page 22 sem to initiate definition of Meta-Programming “if” mechanisms?

a) Forward declare a template struct xxx_impl specialised for bool value  
b) define a use_xxx bool value made up of meta-functions whore “return types” carries a ::value member of type bool (e.g. boost::is_same and boost::is_reference)  
Example: bool const use_xxx = boost::is_same&lt;T1,T2&gt;::type::value (shorthand boost::is_same&lt;T1,T2&gt;::value)  
c) Specialise template struct xxx_imp for boolean value true and false and provide a static member function xxx_impl::do_it(….)  
==&gt; static member enables calling it without having to construct an object (the struct is there just to enable partial specialisation which is not allowed for template functions)  
d) Now the meta-function “if” is written as xxx_impl&lt;use_xxx&gt;::do_it(…)  
==&gt; Corresponds to meta-code "if (use_xxx) xxx_impl&lt;true&gt; else xxx_impl&lt;false&gt;”

7) Page 30 concludes ALL meta-functions shall provide::type and Boolean value meta-functions shall provide ::value

8) Page 31 defines Explicit- (full) and Partial- specialisation as the key tool for meta-function programming

a) General Partial Specialisation is written in C++ on the form:

template &lt;variable-part&gt;

struct template-name&lt;fixed-part&gt;

==&gt; At least one parameter in the fixed-part depends on members in variable-part (is specialised).

b) And Explicit (full) specialisation is just when the variable part is empty

template &lt;&gt;

struct template-name&lt;fixed part&gt;

9) Consider as side-track to study “Iterators using proxy references” on page 21

==&gt; The Iterator::operator\* returns a proxy temporary (**reference** type)  
==&gt; The Proxy::**operator=** accepts a value of the true type (the type the proxy stands in for)  
==&gt; The Proxy has a type-cast member operator to provide implicit conversion to the “real” type (allow real_value = proxy_value)  
==&gt; In this way \*iter1 = \*iter2 will be translated to Iterator::operator=(Proxy&lt;type&gt; proxy_value)

==&gt; See std::vector&lt;bool&gt;::iterator that is specialised to use bitwise internal storage and still allow iterating as if an array of bool (it uses proxies to map to/from internal bits)

==&gt; The vector&lt;bool&gt;::**reference** seem to be defined here (<http://en.cppreference.com/w/cpp/container/vector_bool/reference>)?

==&gt; It defines an operator= to allow assignment TO the proxied value.

==&gt; And an operator bool to allow assignment FROM the proxied value

==&gt; std::vector&lt;bool&gt;::operator&#91;&#93; returns a proxy that thus may be assigned TO or assigned FROM based on proxy members above.

operator=

assigns a bool to the referenced bit  
(public member function)

**operator bool**

returns the referenced bit  
(public member function)

==&gt; NOTE: Wont work for general swap!  
1) Compiler gives an error when asked to type-cast a temporary proxy to non-const ref to value as input to swap (it does not know our proxy actually would work)

==&gt; It seems the general rule for proxied iterators is to provide and apply a specialised swap of two proxies (e.g. as for vector&lt;bool&gt;::**reference **<http://en.cppreference.com/w/cpp/container/vector_bool/swap>)

…

Consider to continue to study C++ meta-programming to gather knowledge about MPL explicitly and other insight in general

{% endraw %}
