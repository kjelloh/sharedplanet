# Todo: C++ std::function - Consider why I can't instantiate a std::function from std::to_string (hint - can't resolve overloaded functions and std::to_string is overloaded)?

```#0402780a``` *As of 2020-10-05 13:37*

[mail plain/text](mail.txt)

{% raw %}
1) Consider to understand why I get a compiler error if I try to instantiate an std::function to wrap the std::to_string?

==&gt; The following test code may be a clue?

> std::string my_to_string(**int** x) {  
> **return** std::to_string(x);  
> }

> **int** main(**int** argc, **const** **char** \* argv&#91;&#93;) {  
> std::function&lt;std::string(**int**)&gt; f = my_to_string; // (1) OK  
> std::function&lt;std::string(**int**)&gt; g = std::to_string;// (2) Error: No viable conversion from '&lt;overloaded function type&gt;' to 'std::function&lt;std::string (int)&gt;'  
> std::function&lt;std::string, **int**&gt; h = std::to_string; // (3) Error: Too many template arguments for class template 'function'  
> **return** 0;  
> }

> *So, for some reason I can construct an **std::function&lt;std::string(int)&gt; from **std::string my_to_string(int x) {...} but NOT from std::to_string;?*

> *This is to me an inconvenience but also opaque and confusing.*

> *Now std::function is defined as:*

> template&lt; class R, class... Args &gt;  
> class function&lt;R(Args...)&gt;;

> *Which I read as asking the compiler to deduce the return type R and argument parameter pack Args from the syntax R&lt;Args...&gt;. *Also, as indicated by (3) I do NOT seem to be able to use this std::function template with two arguments because that is "too many" template argument? Wot?!

> *As indicated by (2) the compiler fails to "convert" from std::to_string to std::function&lt;std::string(int)&gt; although there is an overload of std::to_string that at least has the signature std::string(int)?*

> [std::string](http://en.cppreference.com/w/cpp/string/basic_string) to_string( int value );  
> (1) (since C++11)  
> [std::string](http://en.cppreference.com/w/cpp/string/basic_string) to_string( long value );  
> (2) (since C++11)  
> [std::string](http://en.cppreference.com/w/cpp/string/basic_string) to_string( long long value );  
> (3) (since C++11)  
> [std::string](http://en.cppreference.com/w/cpp/string/basic_string) to_string( unsigned value );  
> (4) (since C++11)  
> [std::string](http://en.cppreference.com/w/cpp/string/basic_string) to_string( unsigned long value );  
> (5) (since C++11)  
> [std::string](http://en.cppreference.com/w/cpp/string/basic_string) to_string( unsigned long long value );  
> (6) (since C++11)  
> [std::string](http://en.cppreference.com/w/cpp/string/basic_string) to_string( float value );  
> (7) (since C++11)  
> [std::string](http://en.cppreference.com/w/cpp/string/basic_string) to_string( double value );  
> (8) (since C++11)  
> [std::string](http://en.cppreference.com/w/cpp/string/basic_string) to_string( long double value );  
> (9) (since C++11)  
> *Is there a problem in that std::to_string is overloaded itself? That the compiler needs to choose which overload I "mean"? To mee as a programmer it is evident I want to use the std::string(int) overload of std::to_string. But maybe this is not clear to the compiler?*

> *AHA - Sure enough! If I overload my own int-to-string function I get the same compiler error for (1)!*

> std::string my_to_string(**int** x) {  
> **return** std::to_string(x);  
> }

> std::string my_to_string(**double** x) {  
> **return** std::to_string(x);  
> }

> **int** main(**int** argc, **const** **char** \* argv&#91;&#93;) {  
> std::function&lt;std::string(**int**)&gt; f = my_to_string; // (1.2) // No viable conversion from '&lt;overloaded function type&gt;' to 'std::function&lt;std::string (int)&gt;' (aka 'function&lt;basic_string&lt;char, char_traits&lt;char&gt;, allocator&lt;char&gt; &gt; (int)&gt;')

> *And now I SEE IT! The compiler error actually states &lt;**overloaded **function type&gt;! So std::function can NOT be instantiated from an overloaded function?*

> *Some googling confirms that this is true (as adressed in this stackoverflow thread*  
> [*https://stackoverflow.com/questions/30393285/stdfunction-fails-to-distinguish-overloaded-functions](https://stackoverflow.com/questions/30393285/stdfunction-fails-to-distinguish-overloaded-functions) ). *

> *"*It's obvious to us which function you intend to be chosen, but **the compiler has to follow the rules of C++** not use clever leaps of logic (or even not so clever ones, as in simple cases like this!)

> The relevant constructor of `std::function` is:

> ```
> template<class F> function(F f);

> ```

> which is a template that accepts any type.

> The C++14 standard does constrain the template (since [LWG DR 2132](http://cplusplus.github.io/LWG/lwg-defects.html#2132)) so that it:

  
> > shall not participate in overload resolution unless `f` is Callable (20.9.12.2) for argument types `ArgTypes...` and return type `R`.

> which means that the compiler will only allow the constructor to be called when `Functor` is compatible with the call signature of the `std::function`.



> However, the compiler can't test the "`f` is Callable for argument types ..." constraint until it knows the type of `f`, which means it needs to have already disambiguated between ... &#91;the overloaded alternatives&#93; ... before it can apply the constraint that would allow it to reject one of those functions!

> So there's a chicken and egg situation, which unfortunately means that you need to help the compiler out by specifying exactly which overload ... you want to use, and then the compiler can apply the constraint and (rather redundantly) decide that it is an acceptable argument for the constructor.

  
> It is conceivable that we could change C++ so that in cases like this all the overloaded functions are tested against the constraint (so we don't need to know which one to test before testing it) and if only one is viable then use that one, but that's not how C++ works. *"*

> *OK, to be able to instantiate an std::function to wrap an overloaded function I need to first type cast it to the overload I want to use. In this way the compiler will first resolve the overload and only then match the function to the constructor of std::function!*

> *So we now have the following "observations" and at least one viable solution to pass a suitable lambda to std::function that resolves any overloaded function I want to use?*

> std::string my_not_overloaded_to_string(**int** x) {  
> **return** std::to_string(x);  
> }

> std::string my_overloaded_to_string(**int** x) {  
> **return** std::to_string(x);  
> }

> std::string my_overloaded_to_string(**double** x) {  
> **return** std::to_string(x);  
> }

> **int** main(**int** argc, **const** **char** \* argv&#91;&#93;) {  
> std::function&lt;std::string(**int**)&gt; f1 = my_not_overloaded_to_string; // (1) OK  
> std::function&lt;std::string(**int**)&gt; f2 = my_overloaded_to_string; // (2) No viable conversion from '&lt;overloaded function type&gt;' to 'std::function&lt;std::string (int)&gt;' (aka 'function&lt;basic_string&lt;char, char_traits&lt;char&gt;, allocator&lt;char&gt; &gt; (int)&gt;')  
> std::function&lt;std::string(**int**)&gt; f3 = **static_cast**&lt;std::string(**int**)&gt;(my_overloaded_to_string); // (3) Address of overloaded function 'my_overloaded_to_string' cannot be static_cast to type 'std::string (int)'  
> std::function&lt;std::string(**int**)&gt; f4 = &#91;&#93;(**int** x) {**return** my_overloaded_to_string(x);}; // (4) OK  
> std::function&lt;std::string(**int**)&gt; f5 = std::to_string;// (5) Error: No viable conversion from '&lt;overloaded function type&gt;' to 'std::function&lt;std::string (int)&gt;'  
> std::function&lt;std::string, **int**&gt; f6 = std::to_string; // (6) Error: Too many template arguments for class template 'function'  
> std::function&lt;std::string(**int**)&gt; f7 = &#91;&#93;(**int** x) {**return** std::to_string(x);}; // (7) OK.

> /\*\*

> (1) OK (no overload problem)  
> (2) The compiler can't resolve the function overload in the template argument resolution phase  
> (3) The "type" of syntax std::string(int) does not "match" the overload int -&gt; std::string  
> (4) OK (no overload problem for unique lambda)  
> (5) The compiler can't resolve the function overload of std::to_string in the template argument resolution phase  
> (6) The std::function&lt;typename R, typename... Args&gt; does not exist although the specification says it does?  
> (7) OK (No overload problem for unique lamda)

> \*/

> *...*

...

{% endraw %}
