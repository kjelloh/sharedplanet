# Todo: C++ Inductive Types - Consider Copperspice

```#2e7dddac``` *As of 2019-06-26 20:03*

[mail plain/text](mail.txt)

{% raw %}
1) Consider this copperspice talk "" at 37:45 where they talk about registration of enumerated signal slots (<https://youtu.be/LHgaVgMEHjA?list=PL_AKIMJc4roU0F3w20Ac77YeOFyvFmaJD&t=2265> )?

==&gt; Consider that Copperspice uses macros at compile time and then run-time reflection to enumerate signal slots using a "templated int class"?

![](<Screenshot 2019-06-26 at 16.42.45.png>)

*Copperspice uses macros at compile time and registration code at run-time to make the signal slot enumeration "work"*

==&gt; Consider the copperspice code written into a namespace?

> **namespace** slots {  
> #define SLOT(X) \\  
> static constexpr const int value_##X = decltype(cs_counter(CSInt&lt;255&gt;{}))::value; \\  
> static constexpr CSInt&lt;value_##X + 1&gt; cs_counter(CSInt&lt;value_##X + 1&gt;)

> *// CSInt is a "typed int" to enable function overload type dispacthing*  
> **template**&lt;**int** N&gt;  
> **class** CSInt : **public** CSInt&lt;N-1&gt; {  
> **public**:  
> **static** **constexpr** **const** **int** value = N;  
> };

> **template**&lt;&gt;  
> **class** CSInt&lt;0&gt; {  
> **public**:  
> **static** **constexpr** **const** **int** value = 0;  
> };

> **template**&lt;**int** N&gt;  
> **static** **void** cs_register(CSInt&lt;N&gt;) { }

> **static** **constexpr** CSInt&lt;0&gt; cs_counter(CSInt&lt;0&gt;);

> *// SLOT(42); expands to*  
> **static** **constexpr** **const** **int** value_42 = **decltype**(cs_counter(CSInt&lt;255&gt;{}))::value; \\  
> **static** **constexpr** CSInt&lt;value_42 + 1&gt; cs_counter(CSInt&lt;value_42 + 1&gt;);

> *// SLOT(43); expands to*  
> **static** **constexpr** **const** **int** value_43 = **decltype**(cs_counter(CSInt&lt;255&gt;{}))::value; \\  
> **static** **constexpr** CSInt&lt;value_43 + 1&gt; cs_counter(CSInt&lt;value_43 + 1&gt;);

> }

==&gt; It seems in expanded SLOT(42) the cs_counter(CSInt&lt;255&gt;) "call" will "dispatch" to cs_counter(CSInt&lt;0&gt;) and ::value will evaluate to 0 (<https://youtu.be/LHgaVgMEHjA?list=PL_AKIMJc4roU0F3w20Ac77YeOFyvFmaJD&t=2734> )?

> *" &#91;45:4&#93;7 ...what data type would it evaluate to? Well, we're calling this method called "cs_counter" and we're passing it a wrapped 255... and the only declaration of cs_counter that's in scope is this one &#91;pointing at "static constexpr CSInt&lt;0&gt; cs_counter(CSInt&lt;0&gt;);"&#93;. And since 255 inherits from 254 inherits from 253, eventually inherits all the way up to 0 we will &#91;the compiler will match&#93; call this version get back a wrapped 0. Then we can apply the colon colon value yielding 0 at compile time. Which means value 42 is 0 because it's a constant expression."*

==&gt; Finally the SLOT(42) expansion code declares a new overload for cs_counter that takes a type of a templated int one higher that the one we just used (and remembered in value_42)

==&gt; So in a way "value_42" is a compile-time variable to remember the index we have used and then declare a new cs_counter overload with a type wrapping the next higher index?

> *I am trying to condense down the most terse understanding of what is going on here. So we start off with the declaration of base case *CSInt&lt;0&gt; cs_counter(CSInt&lt;0&gt;); *Then we use a macro to get a line-number-dependent name to compile-time define a constant value defined by ***decltype**(cs_counter(CSInt&lt;255&gt;{}))::value *. Now the magic is that *cs_counter(CSInt&lt;255&gt;{})*will engage function overloading on the type *CSInt&lt;255&gt;*. Which in turn applies function polymorphism as *CSInt&lt;0&gt; *inherits from *CSInt&lt;254&gt; inherits from CSInt&lt;253&gt;*... and so on down to *CSInt&lt;0&gt;*. So the compiler will bind *cs_counter(CSInt&lt;255&gt;{})  
> *to *CSInt&lt;0&gt; cs_counter(CSInt&lt;0&gt;);*. The next this is now that ***decltype**(cs_counter(CSInt&lt;0&gt;{}))*will evaluate to *CSInt&lt;0&gt; *(the return type of *cs_counter(CSInt&lt;0&gt;)*. Finally we evaluate the indirection operator :: to reference *CSInt&lt;0&gt;::value *which is defined as 0. **So we end up with *value_42 = 0.

> *The next thing we do is that we use our *value_42 = 0 *to overload a new *CSInt&lt;value_42 + 1&gt; cs_counter(CSInt&lt;value_42 + 1&gt;);*. *

> *So in practice we now have *CSInt&lt;1&gt; cs_counter(CSInt&lt;1&gt;); *in the namespace.*

> *Now, when we repeat this for value_43 we go through the same compile-time evaluation. But this time the difference is that the compiler will bind *cs_counter(CSInt&lt;255&gt;{})

> *to *cs_counter(CSInt&lt;1&gt;);

> *. This is so because due to the polymorphic overload rules the type *CSInt&lt;1&gt;

> *more closely matches *CSInt&lt;255&gt;{} *than *CSInt&lt;1&gt; *does.*

> *So the bottom line is that we mutate the C++ type environment for our program in steps to incrementally define integer constant values 0...n **.*

==&gt; Consider we can understand the copperspice code as a "ratchet" code generator?

> *The copperspice code seems to work like a ratchet. Each "turn" adds a new constant with an incremented counter value. It is based on preprocessor generated code that transform a line number into a counter constant name. And each new constant is assigned an incremented integer value based on function overloads on each counter value type so far.*

> *0) A macro is expanded into code with a constant named uniquely depending on the line number of the macro.*

> *pre-pocessor: line-number -&gt; unique-constant-name*

> *1) Crank pull: The compiler defines a new constant value n by dispatching INT&lt;255&gt; to current "top matching" INT&lt;n&gt;*

> *compiler: **INT&lt;255&gt; -&gt; INT&lt;n&gt; -&gt; n // Using cs_counter overload and dispatch in INT&lt;255&gt; &lt;- INT&lt;254&gt; &lt;- ... INT&lt;0&gt; polymorphic hierachy*

> *2) Crank push: The compiler "pushes" a new function overload onto the "stack" of previously overloads using a type wrapped int with the counter value n+1. *

> *compiler: declare INT&lt;n+1&gt; f(INT&lt;n+1&gt;)*

> \*) Each time we repeat 0...2 we will get a new constant wit a value +1 of previous one, and a new function overload to "remember" it.

> *Note that we are in fact using the overloaded functions f(INT&lt;0&gt;), f(INT&lt;1&gt;), ... f(INT&lt;n&gt;) to "remember" what count value n we are to use "next time". This is interesting and I suppose I shopuld remember this trick for future use to get something close to C++ inductive types?*

==&gt; Consider the slides (<https://www.copperspice.com/pdf/CopperSpice-CppNow-2016.pdf> )?

![](<Screenshot 2019-06-26 at 16.15.30.png>)

*The CSInt&lt;0...n&gt; builds an inheritance hierarchy to enable function overload to "dispatch" to lowest matching current declaration.*

2) Consider the Copperspice CSInt&lt;&gt; does NOT in fact have inductive powers?

> #include &lt;iostream&gt;

> **template**&lt;**int** N&gt;  
> **class** CSInt : **public** CSInt&lt;N-1&gt; {  
> **public**:  
> **static** **constexpr** **const** **int** value = N;  
> };

> **template**&lt;&gt;  
> **class** CSInt&lt;0&gt; {  
> **static** **constexpr** **const** **int** value = 0;  
> };

> **int** main(**int** argc, **const** **char** \* argv&#91;&#93;) {  
> *// insert code here...*  
> std::cout &lt;&lt; "Hello, World!\\n";  
> CSInt&lt;255&gt; count0 {};  
> CSInt&lt;255&gt; count1 {};  
> CSInt&lt;255&gt; count2 {};  
> std::cout  
> &lt;&lt; "count0:" &lt;&lt; count0.value  
> &lt;&lt; " count1:" &lt;&lt; count1.value  
> &lt;&lt; " count2:" &lt;&lt; count2.value  
> &lt;&lt; "/nl";  
> **return** 0;  
> }

> // outputs...

> **Hello, World!**  
> **count0:255 count1:255 count2:255/nlProgram ended with exit code: 0**

==&gt; Can we somehow have CSInt&lt;N&gt; reduce to CSInt&lt;I&gt; where I is M+1 of the current last instantiated CSInt&lt;M&gt;?

> *What we want is something that instantiates a class with an int value that is one above the int value of the last instantiation of this specialised template?*

3) Consider if there are other ways to somehow get C++ inductive types?

> *So the "copperspice way" is to use function polymorhic overloading to have f(INT&lt;255&gt;) match the current "top-of-stack" declared INT&lt;n&gt; f(INT&lt;n&gt;). Now this is neat and all, but requires that we use macros to actually generate the code that leverage this mechanism. But for a true inductive type we would like lazy-evaluation of the-next-higher index type. We would like a compile-time next_index() to increment the last used one and return a type indexed with this next one? This would be possible if the compile-time evaluation of next_index() left a trace in the C++ environment of the last used index so that we could use that to increment a new one.*

> *Now already here we see that because the C++ environment is immutable, any storage of the last-used-index must have a **new name**. And of course there are currently no mechanism in C++ to compile-time-declare names? So that is why copperspice used macros to generate code, including the name of the constant that "remembers" the last used index.*

...

{% endraw %}
