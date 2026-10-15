# Todo: Tha function types - Consider we can actually extend normal value-functions to also allow type-functions and kind-functions?

```#e4335466``` *As of 2017-08-09 13:36*

[mail plain/text](mail.txt)

{% raw %}
Consider if it could have valuable meaning to extend the concept of value-functions (mappings between types) to also talk about type-functions and kind-functions?

1) Consider the Tha modelling of “normal” value-functions (type mappings)?

==&gt; Consider a value-function maps values form one type to values of another type?

value_f: type_1 - &gt; type_2

==&gt; Consider a function declaration binds a name to an instance of the function argument environment?

**int f(int x);**

type: “_” ----&gt; {{“x”, “int", null}, {“_”,”int", null}} // type: int -&gt; int

^

|

value: “f” ----&gt; null // name “f” not yet defined = no body

==&gt; Thus, the function type can be modelled as an environment listing the mappings x -&gt; y -&gt; z (the last binding is the return meta-value declaration)?

==&gt; Consider a call to a declared function instantiates a “call environment” and binds provided arguments in this call environment?

const int k = 4;

int f(int x) {

return x\*x + k;

}

void main() {

int a;

int y = f(a); // binds “k” to call environment (stack frame)

}

declaration_namespace {

// models int -&gt; int

int x; // argument name

int _; // last = return value (no name)

}

definition_namespace {

int k = 4;

}

execution_namespace {

scope env = {definition_namespace, declaration_namespace}

body = vector&lt;statements&gt;;

operator(environment arguments) {

// evaluate statements in the our environment

}

}

==&gt; Hm… still a bit fuzzy (we need a clear way of modelling environments from declaration, definition and call to functions)

function declaration: instantiate an argument and return value environment (argument bindings)?

function definition: instantiate an execution environment with bound (captured) free and local names?

function call: Create a call-environment where function arguments are bound to the passed one.

==&gt; Then pass the call-environment to the function to evaluate the body in this context (captured plus called values)

...

2) Consider to generalise value-functions to any value-&gt;meta-value reaction?

==&gt; Consider a the-function maps values of one meta-value to values of another meta-value?

tha_f: meta-value-1 -&gt; meta-value-2

==&gt; Consider a tha-function declaration binds a name to an instance of the function argument environment?

**meta-value-name-2 f(meta-value-name-1 x);**

meta: “_” ----&gt; {{“x”, meta-value-name-1, null}, {“_”,meta-value-name-2, null}} // type: meta-value-name-1 -&gt; meta-value-name-2

defacto: “f” ----&gt; null // not yet defined = no body

==&gt; Thus, the function type can be modelled as an environment listing the mappings x -&gt; y -&gt; z (the last binding is the return meta-value declaration)?

3) Then a type-function would map types of one kind into types of another kind?

type_f: kind_1 -&gt; kind_2

==&gt; Now, what would type-functions mean?

==&gt; It seems they are close to “concepts” (they define what types the function accepts and what types it produces)?

==&gt; A function template with type arguments would be a C++ type-function?



> template &lt;typename T&gt;  
> struct F {};

> template &lt;&gt;  
> struct F&lt;int&gt; {  
> using type = char;  
> }

> template &lt;&gt;  
> struct F&lt;bool&gt; {  
> using type = int;  
> }

==&gt; Which is a type-function?

f int = char

f bool = int

4) Now, what would a kind-function mean?

==&gt; First problem is we still don’t know what we shall call meta-4 values (kind of kinds)?

kind_f: kind-of-kinds-1 -&gt; kind-of-kinds-2

==&gt; Consider of mapping between C++ kinds can have any meaning at all?

kind_f struct = struct; // Identity - no operation?

kind_f struct = class; // Would enable a type_f to query a type of its kind (meta(some_type)) and then create a class-type of a struct-type?

kind_f struct = enum; // Just nonsense (the struct kind and enum kind share no properties that can be transferred)?

…

==&gt; It seems we can give kind-functions meaning for user defined kinds?

==&gt; A my_enum ind that enumerates the members of a struct instance?

...

…

Consider to elaborate on if the “function concept” can be re-used on any Tha-value level?

...

{% endraw %}
