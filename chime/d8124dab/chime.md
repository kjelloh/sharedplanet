# Todo: Programming - Consider to provide odysseus library with clang/gcc __PRETTY_FUNCTION__ and msvc __FUNCSIG__ template function?

```#d8124dab``` *As of 2016-09-29 14:12*

[mail plain/text](mail.txt)

{% raw %}
So, could it be a good idea (and a proof of concept) to add a run-time function type information strings as a template function?

1) Consider to use this Cppcon 2016 talk as leads to how one may generate cross platform function type information strings (17:30 into <https://www.youtube.com/watch?v=vwrXHznaYLA&index=12&list=PLHTh1InhhwT7J5jl4vAhO1WvGHUUFgUQH>)?

![](<__PRETTY_FUNCTION__ output for template function.tiff>)

2) Consider a design that enables the odysseus template function to generate function type information string for clang, gcc and msvc?

==&gt; Consider to apply __PRETTY_FUNCTION__ for clang/gcc tool-chain (<https://gcc.gnu.org/onlinedocs/gcc/Function-Names.html>)?

> void sub (int i);

> __FUNCTION__ = sub  
> __PRETTY_FUNCTION__ = void a::sub(int)

==&gt; This seem to be a good stack overflow thread on the subject for clang and gcc (<http://stackoverflow.com/questions/4384765/whats-the-difference-between-pretty-function-function-func>)?

> ```
> #include <iostream>

> namespace N {
>     class C {
>         public:
>             template <class T>
>             static void f() {
>                 std::cout << __func__ << std::endl
>                           << __FUNCTION__ << std::endl
>                           << __PRETTY_FUNCTION__ << std::endl;
>             }
>     };
> }

> int main() {
>     N::C::f<int>();
> }
> ```

> Output GCC 4.8:

> ```
> f
> f
> static void N::C::f() [with T = int]
> ```



==&gt; Consider to apply __FUNCSIG__ for Visual Studio tool-chain (<https://msdn.microsoft.com/en-us/library/b0084kay.aspx>)?

> This example uses the **__FUNCDNAME__**, **__FUNCSIG__**, and **__FUNCTION__** macros to display function information.  
> [C++]()

> ```
> // Demonstrates functionality of __FUNCTION__, __FUNCDNAME__, and __FUNCSIG__ macros
> void exampleFunction()
> {
> 	printf("Function name: %s\n", __FUNCTION__);
> 	printf("Decorated function name: %s\n", __FUNCDNAME__);
> 	printf("Function signature: %s\n", __FUNCSIG__);

> 	// Sample Output
> 	// -------------------------------------------------
> 	// Function name: exampleFunction
> 	// Decorated function name: ?exampleFunction@@YAXXZ
> 	// Function signature: void __cdecl exampleFunction(void)
> }
> ```



==&gt; Consider some home rolled one based on typeinfo is non of the above?

…

3) It seems this is pure pre-processor stuff and we can’t warp it into a template function?

==&gt; It seems we must have the pre-processor generate the text string at the location within the function we want to have the text generated for?

==&gt; There can’t be any way of instituting a template function based on the type of the function (there are no pre-processor macro that provides the function type)?

…

==&gt; So, it seems odysseus will fail to hide this pre-processor mechanism into a type generated function?

4) Consider to compare what the different pre-processing macros generate for template functions (in case we would move forward to create odysseus template function for this)?

==&gt; It seems __PRETTY_FUNCTION__ adds information about the template function type parameters (See above from Cppcon 2016 talk)

...

…

Consider to elaborate on this idea to have odysseus library map a template function from pre-processor generated function type information?

...

{% endraw %}
