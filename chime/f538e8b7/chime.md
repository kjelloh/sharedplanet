# Todo: C++ Tha - Consider to do a runtime Tha type system in C++ (and then see if we can propose a compile time C++ Tha as a proposal)?

```#f538e8b7``` *As of 2018-06-08 20:26*

[mail plain/text](mail.txt)

{% raw %}
It seems to me at this point that if we first do a runtime C++ Tha we can then later see if and how we can propose a compile time C++ Tha?

1) Consider a runtime C++ Tha that uses only C++ Text and Number as atomic types (meta-2), Sum and Product compositions (meta-3) and Generics (meta-4) on those?

==&gt; It seems we can model Number and Text (meta-2) as class instances “Number” and “Text” that construct from C++ literals and {name Number/Text} arguments?

> class Number {private: std::tuple&lt;Name,int&gt; object{};};  
> class Text {private: std::tuple&lt;Name, std::string&gt; value{};}  
> ...

==&gt; It seems we can model Sum compositions (meta-3) using std::variant on any {name, object}?

class Product {private: std::vector&lt;std::tuple&lt;Name,Types...&gt;&gt;};

class Sum {private: std::vector&lt;std::tuple&lt;Name,Types...&gt;&gt;};

**Hm… No, now I use C++ compile time stuff. I need Product and Sum to work on dynamic argument lists at run-time!**

**TODO: Use std::vector&lt;NamedObjects&gt; to create argument lists to feed to Product and Sum singletons at runtime?**

==&gt; It seems we can model Product compositions (meta-3) using std::tuple on any {name, object}?

==&gt; It seems we can model Generics that can construct from meta-2 and meta-3 {name object} argument lists?

…

2) It seems Tha objects always are {name, object-impl} tuples?

==&gt; Consider the basic “atoms” of the Tha type system can be {name, Tha-object} tuples (always name referred objects)?

…

3) Consider initially we don’t concern the implementation with anonymous (unnamed) objects?

==&gt; Consider anonymous objects can later be added by using “hidden” names used only “internally” to pass those around?

==&gt; Consider anonymous objects are in fact only objects we don’t care what name they have (we can still bind names to them to re-use existing {name, object} tuple processing)?

...

4) Consider to extend the runtime C++ Tha implementation to use C++ Immer immutable type library?

==&gt; What immutable types can I use to model the whole Tha and its component objects?

...

…

Consider to delve into this idea to try and implement C++ Tha type system using selected Tha-objects and compose with them only as {name, tha_object} tuples?

...

{% endraw %}
