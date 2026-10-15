# Todo: C++ - Consider the Move Semantics and Perfect Forwarding actually is only for the compiler to short-cut construction and assignment to the most optimal location in the code (allow emplacement and copy elision)?

```#31cac2c7``` *As of 2017-07-25 13:25*

[mail plain/text](mail.txt)

{% raw %}
So, can we understand the Move Semantics and perfect forwarding simply as a way to guide the compiler to understand when actually copying is not required?

1) Consider the std::forward example in [cppreference.com](http://cppreference.com) (<http://en.cppreference.com/w/cpp/utility/forward>)?

==&gt; std::forward is specialised to return an lvalue or rvalue depending on the type passed.

> template&lt; class T &gt;  
> T&& forward( typename [std::remove_reference](http://en.cppreference.com/w/cpp/types/remove_reference)&lt;T&gt;::type& t ) noexcept;(1) (since C++11)  
> (until C++14)template&lt; class T &gt;  
> constexpr T&& forward( typename [std::remove_reference](http://en.cppreference.com/w/cpp/types/remove_reference)&lt;T&gt;::type& t ) noexcept;(1) (since C++14)template&lt; class T &gt;  
> T&& forward( typename [std::remove_reference](http://en.cppreference.com/w/cpp/types/remove_reference)&lt;T&gt;::type&& t ) noexcept;(2) (since C++11)  
> (until C++14)template&lt; class T &gt;  
> constexpr T&& forward( typename [std::remove_reference](http://en.cppreference.com/w/cpp/types/remove_reference)&lt;T&gt;::type&& t ) noexcept;(2) (since C++14)

==&gt; Consider std::remove_reference simply turns any T& or T&& into T (<http://en.cppreference.com/w/cpp/types/remove_reference>)

> ```
> template< class T > struct remove_reference      {typedef T type;};
> template< class T > struct remove_reference<T&>  {typedef T type;};
> template< class T > struct remove_reference<T&&> {typedef T type;};
> ```



==&gt; Consider what we can learn from the wrapper example called in different ways?

> ```
> template<class T>
> void wrapper(T&& arg)
> {
>     // arg is always lvalue
>     foo(std::forward<T>(arg)); // Forward as lvalue or as rvalue, depending on T
> }
> ```



==&gt; Calling wrapper with a temporary…

> int main() {  
> wrapper(std::string{“Hello"});  
> // A std::string&& is passed but inside wrapper the argument is T  
> }

2) Consider this blog post explaining Move Semantics, temporaries and rvalues (<http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html>)?

==&gt; Consider a rvalue reference is a mutable reference to a temporary (as an extension to C++03 immutable const& to temporaries)?

> `const` `string& name = getName(); // C++03`  
> `string&& name = getName(); // C++11`

==&gt; In &gt; C++11 the compiler will detect that getName returns by value (thus it is a temporary) and treat it as an rvalue reference (T&&)

==&gt; Thus, name being T&& is allowed to bind to the returned temporary (keeping it alive)

==&gt; Consider in C++ we can overload on T& or T&& to guide the compiler to generated different code?

> `printReference (``const` `String& str) `{  
> ` ``cout &lt;&lt; str;`  
> `}`  
> `printReference (String&& str) `{  
> ` ``cout &lt;&lt; str;`  
> `}`

==&gt; And this gets useful to write special constructors and assignment operators for rvalues (temporaries)?

> ` / move constructor`  
> ` ``ArrayWrapper (ArrayWrapper&& other)`  
> ` ``: _p_vals( other._p_vals )`  
> ` ``, _size( other._size )`  
> ` ``{`  
> ` ``other._p_vals = NULL;`  
> ` ``other._size = 0;`  
> ` ``}`

==&gt; As we know this code is for treating a reference to a temporary we are free to “steal” its content (no-one will get sorry)

==&gt; Note how we are allowed to mutate the “moved-from” object to indicate the sealed data (nullified pointer)

==&gt; It seems we can understand that a defined rvalue reference (named) is actually an lvalue in its scope!

> “*in our constructor, the object has a name; it will be alive for the entire duration of our function. ... the temporary object has a defined location that truly persists for the entire function. It's an **lvalue** in the true sense*"

==&gt; Thus we have to convert it back to an rvalue if we like to pass it on as such.

> `MetaData (MetaData&& other)`  
> ` ``: _name( **std::move**( other._name ) ) ``// steal other.name`  
> ` ``: _size( other._size )`  
> `{}`

==&gt; It seems we benefit from understanding when the compiler stops generating default constructors?

> “*As you know, in C++ when you declare any constructor, the compiler will no longer generate the default constructor for you. The same is true here: adding a move constructor to a class will require you to declare and define your own default constructor. On the other hand, declaring a move constructor does not prevent the compiler from providing an implicitly generated copy constructor, and declaring a move assignment operator does not inhibit the creation of a standard assignment operator.*"

==&gt; So, adding any constructors **inhibits** compiler generated **default constructor** (but default copy constructor is still generated)?

3) Consider to understand the mechanism and rules for compiler generated move constructors (<http://en.cppreference.com/w/cpp/language/move_constructor>)?

==&gt; Also see “/Users/kjell-olovhogdahl/BitTorrent Sync/XCode/MyCompilerDefaultClassMemberPlayGround/MyCompilerDefaultClassMemberPlayGround"

==&gt; It seems the compiler will generate a default move constructor if it can (See complicated rules)

==&gt; It seems one may force the compiler to generate a default move constructor although a specialised move constructor has already been defined?

> “ *If some user-defined move constructors are present, the user may still force the generation of the implicitly declared move constructor with the keyword default.*"

...

…

Consider to delve deeper into the mechanisms of rvalues and perfect forwarding in C++ as I learn more and understand the important aspects of them?

..

{% endraw %}
