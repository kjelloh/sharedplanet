# Todo: Meta Layers - Consider what we can say about the relationship between the meta-layers of programming languages?

```#b6285590``` *As of 2017-05-25 16:58*

[mail plain/text](mail.txt)

{% raw %}
So, couild it be valuable to try and state some iteratable relationsships between each meta-layer of a programming language (e.g., between values, types, templates etc. of C++)?

1) Consider each meta layer ”values” defines a Set of values on the layer below?

Preprocessor == Set of C++ Code  
|  
---------------------------  
|  
C++ == Set of Templates X  
|  
---------------------------  
|  
Template X == Set of Type T  
|  
---------------------------  
|  
Type T == Set of Value V  
|  
---------------------------  
|  
Value V

==&gt; A Type defines a Set of values

An int is the Set of Integer Values {INT_MIN... INT_MAX} (http://www.cplusplus.com/reference/climits/)

==&gt; A Template defines a Set of Types

std::vector is the Set of Types std::vector&lt;T&gt; (T is some type)

==&gt; The C++ language template semantics defines Sets of Templates

template &lt;typename T&gt; is the Set of possible templates Some_Template  
struct Some_Template {…}

2) Consider each Meta-layer is information about the layer below?

==&gt; A Type defines both a Set of Values and ways to map to values of that type

A Constructor is a function that maps Identity (default constructor), a value of same type (Copy Constructor) or another value (Constructor with argument of other type) to a value in the Set of values defined by the Type.

int{} maps void to 0.  
int{3} maps value 3 in the Integer Literal Set to the value 3 in a new int instance Set?

==&gt; A Template defines bot a Set of Types and ways to map to those Types

std::vector&lt;int&gt; maps the type int to the type std::vector&lt;int&gt; in the Set of types std::vector&lt;T&gt; (any T)

==&gt; C++ Syntax defines a way to define both a Set of Templates and ways to map C++ code to such templates

C++ Syntax: template &lt; parameter-list &gt; class-declaration maps to the Set of any Class Template (instantiated in the compiler type system)

3) Consider mappings between Meta-Layers that enables a value on one Layer to be a selected one from a Set in the Meta-layre above?

==&gt; Consider a value to be A COPY from the Set of value instances defined by its type?

int a = 4; (The State of a is a copy of value 4 from the int Set {INT_MIN... INT_MAX}  
std::vector&lt;int&gt; myV = {1,3,5} is a copy of vector {1,3,5} from the Set of vectors {some int, some int, ...}  
…

Type T == Set of Value V void (Identity?)  
| |  
-------- Constructor -- |  
| |  
| ----------------------------Default Constructor ----  
Value V

==&gt; Consider a Type to be a selection from the Set of Types defined by the language and defined Templates?

Consider int to be an instance of C++ language ”Template” INTEGER&lt;INT_MIN... INT_MAX&gt;?  
Consider std::vector&lt;int&gt; MyV; to be a Type selected from the Set of types std::vector&lt;T&gt; (any T)?

4) Consider each Meta-layer defines mappings (functions) between ”values” within the same layer?

==&gt; Consider functions to be ”values” of code that defines how the input value is transformed into the output value?

Type: int(int)

Value: int f(int v) {return v\*v;} maps 2 to 4, 3 to 6 and so on.

==&gt; NOTE; It seems C++ functions creates COPIES (as opposed to mathematical functions that maps between Sets of existing values)?

==&gt; Consider Meta-functions to be ”values” of type declaration

5) Consider C++ ”Declaration” is in fact a Type while the definition is a Value?

==&gt; Note: In fact in C++ a template is also a declaration?  
==&gt; Thus it seems C++ only separates between definition (values and functions) and declarations (types or templates)?  
==&gt; Consider we may find a cleaner nomenclature using separated Meta-layers?  
…

…

Consider to elaborate on what iteratable pattern we may identify between Meta-layers of the C++ (or any) programming language?  
...

{% endraw %}
