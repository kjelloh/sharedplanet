# Todo: Meta-model - Consider to elaborate on meta-model layers by comparing with C++ language meta layer mechanisms

```#cbc8139a``` *As of 2017-06-02 19:23*

[mail plain/text](mail.txt)

{% raw %}
So, what can we learn by deconstructing C++ language into meta-layers of mechanisms and express them as nested meta-layers using the same abstractions on each layer?

1) Consider to compare with recognized meta-value basic pattern?

==&gt; See ”Todo: Darwinet - Consider the general relation between Meta-values and values (e.g., consider meta-value atom, record, array to be general)?”

> // Basic meta-value constructs  
> /\*

> \*  
> MetaV {declares DeFactoV} &lt;-----------|  
> | |  
> ----------------------------------------- |  
> | | 1 |  
> AtomicMetaValue CompositeMetaValue ---------|  
> | |  
> | ---------------------------------  
> | | | |  
> | ArrayMetaValue MetaValueArray MetaValueRecord  
> | MetaV vector&lt;MetaV&gt; vector&lt;&lt;Name,MetaV&gt;&gt;  
> |  
> \*\* Layer Specific \*\*  
> |  
> -------------  
> | |  
> AtomicMetaValue1 AtomicMetaValue2 ...  
> (Meta-1 Number) (Meta-1 Text) (Meta-1 POD)

> A Leaf Meta Value defines an atomic defacto value

> Meta Level 1 (types) has Atomic Meta Values for Number and Text.  
> ...

> A Composite Meta Value has member(s) that are Meat-Values

> An Array Meta Value has one Meta Value members that defines DeFacto values of a Defacto Array  
> A Meta Value Array is a typle of indexed Meta-Values  
> A Meta Value Record has named Meta Value members

> \*/

==&gt; Each layer Meta-value is the DeFacto Value of the Meta-layer above

...

|

----------------------

|

v

Level n+1: Meta-Value -&gt; { DeFacto Values }

|

----------------------

|

v

Level n: Meta-Value -&gt; { DeFacto Values }

|

----------------------

|

v

…

1) Consider the C++ value, type relation

{

Value: C++ data values (instances of types)

Meta-Values: C++ built in and declared types

int a = 4; // a is of class: int and value 4

std::string s(”Hello”); // s is of class: std::string and of value ”Hello"

std::string f(int x) {return std::to_string(x);} // f is of class: int -&gt; std::string and of value {return std::to_string(x);}

...

}

2) Consider the C++ type, meta-type relation

meta {

// meta-value = type layer

Values = C++ types

Meta-values = C++ type constructors (user template types)

auto a = int; // a is of class:

}

…

Consider to think more about what we know about C++ meta-layers and syntax to identify the ”true” nature of the general Meta-value, DeFacto value relations?

...

{% endraw %}
