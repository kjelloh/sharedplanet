# Todo: Programming - Consider to understand C++11 constexpr usage and implications?

```#2daa7ef9``` *As of 2016-03-14 23:14*

[mail plain/text](mail.txt)

{% raw %}
So, how does C++11 constexpr actually work?

1) This seem to be a good starting point to understand this beast (<http://www.cprogramming.com/c++11/c++11-compile-time-processing-with-constexpr.html>)?

==&gt; It seems constexpr expressions is evaluated at compile time if possible - otherwise it is turned into a runtime expression?

==&gt; If all code and data is known at compile-time it is compile time evaluated?

”A constexpr function has some very rigid rules it must follow:

• It must consist of single return statement (with a few exceptions)

• It can call only other constexpr functions

• It can reference only constexpr global variables”

”A constexpr function can have only a single line of executable code, but it may contain typedefs, using declarations and directives, and static_asserts.”

==&gt; It is turned into a run-time evaluated expression if provided with data known only at run-time?

”A function declared as constexpr can also be called at runtime if the argument to the function is a non-constant”

==&gt; One may ”construct and call” class objects by declaring applied constructors and methods as constexpr?

`class` `Circle`

`{`

` ``public``:`

` ``constexpr` `Circle (``int` `x, ``int` `y, ``int` `radius) : _x( x ), _y( y ), _radius( radius ) {}`

` ``constexpr` `double` `getArea () `

` ``{`

` ``return` `_radius \* _radius \* 3.1415926;`

` ``}`

` ``private``:`

` ``int` `_x;`

` ``int` `_y;`

` ``int` `_radius;`

`};`

`constexpr` `Circle c( 0, 0, 10 );`

`constexpr` `double` `area = c.getArea();`

”First, we need to declare the constructor as constexpr, and second, we need to declare the getArea function as constexpr”

==&gt; consexpr variables and functions are run-time const buy default. But const variables and functions are NOT constexpr by default.

==&gt; constexpr expressions may use floating point types whereas Template Functions may not (Template Value Parameters may be integer compatible only, e.g. int and bool)

2) This seem like a good introduction from cppcon 2015 about constexpr (<http://clang-developers.42468.n3.nabble.com/Review-CLion-a-great-way-to-develop-on-clang-td4043928.html>)?

==&gt; constexpr kind-of asks of the compiler to run a c++ “interpreter”.

==&gt; In C++11 the standard says what you CAN do (heavily constrained)

==&gt; single statement only (sub-statements ignored)

==&gt; Enables code ok only at run-time (as long as it does not evaluate at compile-time)

==&gt; An example is having throw in constexpr (ok as long as the throw does NOT evaluate at compile-time)

==&gt; ternary operator allowed (enables recursion through return &lt;predicate&gt;?&lt;recurse_call&gt;:&lt;terminate_expression&gt;;)

==&gt; Only literal types or refs to literal types.

==&gt; In C++14 the standard says what you CAN’T DO (less constrained)

==&gt; Means in C++14 the standard lists what the interpreter does not know how to interpret.

3) This seem like a good follow-up on the constexpr talks at cppcon 2015 (<https://channel9.msdn.com/Events/CPP/CppCon-2015/CPPConD02V023>)

==&gt; No way to force constexpr to be compile-time (compile-time must be enforced)

==&gt; Run-time call to constexpr function will silently be run-time (no way to get compile time error if run-time call is NOT intended)

==&gt; Hack (poisoned function called) “unresolved extern hack” by adding non-evaluated throw that tries to use static extern literal char\*.

==&gt; Seems invented by a guy named Howard Hinnant?

==&gt; This will cause linker error (can’t link to unresolved char\*)

==&gt; Not bullet proof - compiler allowed to exclude unevaluated throw and thus there will be no linker error.

==&gt; He introduces constexpr containers :)

==&gt; arrays allowed to be constexpr.

==&gt; Only arrays seems to be allowed constexpr containers (struct and class can’t be constexpr)?

==&gt; C++14 allows non-const constexpr to be compile-time evaluated to “construct” the final compile-time value.

==&gt; He shows an C++14 example of compile-time string manipulation (char arrays)

// Can’t use C++14 std::array, since element access is not defined as constexpr.

template &lt;typename T, std::size_t N&gt;

class array_result {

private:

constexpr static std::size_t size_ = N;

T data_&#91;N&#93;; // T must have a default constructor (a constexpr one to enable use of this code in constexpr statements)

public:  
// …  
constexpr T& operator&#91;&#93; (std::size_t n) {  
return data_&#91;n&#93;;  
}  
using iterator = T\*;  
constexpr iterator begin() {return \*data_&#91;0&#93;;}  
constexpr iterator end() {return &data_&#91;N&#93;;}  
// …  
}

**template &lt;std::size_t N&gt;  
constexpr auto constexpr_to_upper (const char(&in)&#91;N&#93;)  
-&gt; array_result&lt;char, N&gt;  
{  
array_result&lt;char, N&gt; out;  
for (Std::size_t i = 0; in&#91;i&#93; != 0; ++i)  
{  
char c : in&#91;i&#93;;  
out&#91;i&#93; = ((c &lt; ’a') II ( c &gt; ’2'))?  
c : c - ('a' - ’A');  
}  
return out;  
}**

main {  
static constexpr auto a =  
constexpr_to_upper(“Frank Lloyd Wright”);  
// a will be compiled to hold “FRANK LLOYD WRIGHT"  
}

==&gt; Uses user-defined array_result template to store constexpr array result

==&gt; array_result is a templatetized class with constexpr members.

==&gt; member size_ is static (each template instantiation will be a unique class type)

==&gt; Q: Why is not member data_ constexpr static?

==&gt; Q: Should not array_result be specialised for array to get size N determined by the supplied type?

**WE ARE HERE...**

4) Side Note: Consider to delve into this talk that seem to leverage on the constexpr ability to run compile-time and run-time to write code that runs both compile time AND runtime (<https://youtu.be/cg1wOINjV9U>)?

==&gt; He seems to basically write code that uses std::integral_constant&lt;type,value&gt; and constexpr to bridge compile-time and run-time with the same code?

==&gt; As long as ”value” is known at compile time the inegral_constant may be passed to Meta Functions and execute at compile time also for values?

…

Consider to delve deeper into compile time constexpr that enables run-time application also and optionally how proposed usage of integral_constant enables compile-time code to also execute as runtime code?

...

{% endraw %}
