# Todo: C++ - Consider to understand member method "reference qualifiers" as "T&  value() &;  T&& value() &&; T const& value() const&;" ?

```#cdb30117``` *As of 2018-11-15 12:44*

[mail plain/text](mail.txt)

{% raw %}
Today I saw a C++ syntax I did not understand on the form “T&& f() &&”. What the heck does the trailing “&&” mean?

1) The youtube video “CppCon 2018: Juan Pedro Bolivar Puente “The Most Valuable Values”” where I saw this syntax seems to live here (<https://youtu.be/_oBx_NbLghY?t=1345>)?

![](<Screenshot 2018-11-15 at 12.20.44.png>)

Q: What does the “draw” method declaration with the “&&” before the body mean?

...

2) Consider this Andrzej blog post “Ref-qualifiers” explaining this syntax and motivation for member method ref-qualifiers (<https://akrzemi1.wordpress.com/2014/06/02/ref-qualifiers/>)?

==&gt; It seems in C++ 11 one added the possibility to define “reference qualifiers”?

==&gt; It seems the “ref-qualifiers for member functions” defines the nature of the reference to the called object (that is, if the caller calls the object referenced by value, by reference or by rvalue reference)?

> `template` `&lt;``typename` `T&gt;`  
> `class` `optional`  
> `{`  
> ` ``// ...`  
> ` ``T& value() &; //1`  
> ` ``T&& value() &&; //2`  
> ` ``T ``const``& value() ``const``&; //3`  
> `};`

…is equivalent to the free functions:

> `T & value(optional&lt;T&gt; & this_); //1`  
> `T && value(optional&lt;T&gt; && this_); //2`  
> `T ``const``& value(optional&lt;T&gt; ``const``& this_); //3`

==&gt; Thus the compiler is able to dispatch the call at compile time depending on the “nature” of the called object?

//1 - This function will be dispatched when the caller calls a mutable lvalue object (object in a named variable)

//2 - This function will be called when the caller calls on a mutable temporary rvalue object (anonymously created object)

//3 - This function will be dispatched when the caller calls on a const lvalue object (object in a named variable)

…

3) Consider this cpp reference article “Non-static member functions” on reference qualifiers (<https://en.cppreference.com/w/cpp/language/member_functions>)?

…

...

{% endraw %}
