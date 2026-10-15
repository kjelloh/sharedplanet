# Todo: Programming - Consider to understand how correct swap is found by the compiler using ADL (Argument Dependent Lookup)?

```#7a34e307``` *As of 2016-01-13 16:40*

[mail plain/text](mail.txt)

{% raw %}
While understanding Alexandrescu proposal for Expected&lt;T&gt; swap works I came to realise I don’t in-depth understand how the proposed way to implement swap enables the compiler to choose correctly between specialised member swap, specialised namespace unary swap and std::swap?

1) This seem to be one good starting point on the subject of swap (<http://stackoverflow.com/questions/11562/how-to-overload-stdswap/2684544#2684544>)?

...

2) This thread refers to the “standard” idiom uses std:.swap + unqualified swap (<http://stackoverflow.com/questions/6380862/how-to-provide-a-swap-function-for-my-class>)?

// some algorithm in your code

```
template<class T>
void foo(T& lhs, T& rhs){
  using std::swap; // enable 'std::swap' to be found
                   // if no other 'swap' is found through ADL
  // some code ...
  swap(lhs, rhs); // unqualified call, uses ADL and finds a fitting 'swap'
                  // or falls back on 'std::swap'
  // more code ...
}
```

==&gt; And specialise swap in appropriate namespace

```
namespace Foo{

class Bar{}; // dummy

void swap(Bar& lhs, Bar& rhs){
  // ...
}

}
```

3) This seem to be the source for std::swap definition (<http://en.cppreference.com/w/cpp/algorithm/swap>)?

“std::swap may be *specialized in namespace std* for user-defined types, but such specializations *are not found by ADL* (the namespace std is not the associated namespace for the user-defined type). The expected way to make a user-defined type swappable is to provide a non-member function swap in the same namespace as the type: see Swappable for details.”

4) Swappable seem to be defined here (<http://en.cppreference.com/w/cpp/concept/Swappable>)

“Typical implementations either

1) Define a *non-member swap* in the enclosing namespace, which may forward to a member swap if access to non-public data members is required

2) Define *a friend function in-class* (this approach hides the class-specific swap from name lookup other than ADL)"

3) So, how are the compiler able to find member swap (unary) when called using namespace swap (binary)?

==&gt; They don’t?

**WE ARE HERE **

...

Consider to delve deeper into this to understand how Argument Dependent Lookup (ADL) will find the correct swap (in std namespace or in user namespace).

{% endraw %}
