# Todo: C++ - Consider to understand the 14 type categories identified by Walter E. Brown?

```#ae99cc68``` *As of 2016-11-04 12:52*

[mail plain/text](mail.txt)

{% raw %}
1) The 14 type categories of C++ seems to be defined in this SO thread (<http://stackoverflow.com/questions/27032790/what-are-the-15-classifications-of-types-in-c>)?

> I spoke with Walter directly, and it was simply a miscount.

  
> > "Alas, I realized shortly thereafter that I'd miscounted and hence committed an off-by-one error during the talk: there are 14 (not 15) type classifications. See the list of primary type category predicates in clause &#91;meta.unary.cat&#93; in the C++ standard; these correspond to the classifications established for the core language in &#91;basic.types&#93;." --WEB

> That being said, they are:

> ```
> template <class T> struct is_void;
> template <class T> struct is_null_pointer; //<- arrived in C++11 (std::nullptr_t)
> template <class T> struct is_integral;
> template <class T> struct is_floating_point;
> template <class T> struct is_array;
> template <class T> struct is_pointer;
> template <class T> struct is_lvalue_reference;
> template <class T> struct is_rvalue_reference;
> template <class T> struct is_member_object_pointer;
> template <class T> struct is_member_function_pointer;
> template <class T> struct is_enum;
> template <class T> struct is_union;
> template <class T> struct is_class;
> template <class T> struct is_function;
> ```

  
2) These categories are mentioned in this CppCon 2014 talk by Walter E. Brown (at about 2:45 into <https://www.youtube.com/watch?v=a0FliKwcwXE>)

==&gt; Note that the SO thread above states that he admits miscounting. There are 14 categories, not 15 as states in the talk.

3) It seems these C++ type categories are cv-invariant (i.e., they don’t care about const or volatile qualifications)?

==&gt; This seems to be verified by the std::is_void definition?

  
> ### Possible implementation

  
> ```
> template< class T >
> struct is_void : std::is_same<http://en.cppreference.com/w/cpp/types/is_same><void, typename std::remove_cv<http://en.cppreference.com/w/cpp/types/remove_cv><T>::type> {};
> ```

  
==&gt; Note the ”std__remove_cv” in the meta-expression.

4) The additional cv-qualification of types seem to be defined here (<http://en.cppreference.com/w/cpp/language/cv>)?

==&gt; It seems most of the type categories may have an additional three variants of cv-qualitifation (Function Type and Reference Type are excluded)

> ”*For any type T (including incomplete types), other than function type or reference type, there are three more distinct types in the C++ type system: const-qualified T, volatile-qualified T, and const-volatile-qualified T.*"

==&gt; It seems that a Function Type being const or volatile makes no sense (and thus it can’t have cv-qialification)?

==&gt; It seems that a Reference Type being const or volatile makes no sense (It is an alias and cv-qialification shall be applied to the referenced type)?

==&gt; Could we understand a Function Type and a Reference Type as not being value types (we can’t instantiate a Reference Value or a Function Value)?

==&gt; A Reference Type Value does not exist (i.e., it is not a value but an alias)?

==&gt; A Function Type Value does not exists (we need to use a function pointer value)?

...

==&gt; Could we understand a Function Type and a Reference Type as Type Indirections (they have meaning only to refer to another Type)?

==&gt; A Reference Type is an alias referring to a Value Type (i.e., const int& is an alias to a const int value)?

==&gt; A Function Type is an alias referring to a Function Pointer Value Type (i.e., "int f(int)" is an alias to ”int (\*f)(int)”)?

…

Consider to delve into these categories to see what we can learn and what we can use this knowledge for?

...

{% endraw %}
