# Todo: Programming - Consider a Language Semantics where we can use abstractions to model subroutines, coroutines and coroutines as well as how we engage with them?

```#1b520c38``` *As of 2017-02-07 17:22*

[mail plain/text](mail.txt)

{% raw %}
Consider we can imagine a programming language syntax that enables us to programmatically express the messaging method for functions we write and also how we invoke them?

1) Consider the keyword subroutine, coroutine and goroutine to express what messaging mechanism a function should have?

subroutine f(int a) { return 42;} // A ”stacked” function producing an int

coroutine f(int a) { return 42;} // A ”heaped” resumable function producing an int

goroutine f(int a) { return 32;} // A ”process” function producing an int

==&gt; Consider for ”stacked” functions we now also may integrate the already existing notion of different subroutine Calling Conventions (<https://en.wikipedia.org/wiki/Calling_convention>)?

==&gt; Consider to expand the meaning of Calling Convention to encompass the messaging scheme for any of the types?

==&gt; Thus the Calling Convention for ”subroutine” will be a stack-frame (and the produced value is implicitly returned to caller)?

==&gt; Thus the Calling Convention for ”coroutine” will be a heap-frame (and the produced value is implicitly accessible by the caller through a future-API)?

==&gt; Thus the Calling Convention for ”goroutine” will be an immutable message (and the produced value may be passed to a continuation)?

==&gt; Consider to compare Go Language where goroutines must use channels (and I suppose a channel may be passed to the routine as a kind-of ”continuation”)?

==&gt; Consider to compare how Erlang Processes interact (are they able to return or send on as they please)?

...

2) Consider we use a model where functions ”produce” a value without specifying how the produced value is passed?

auto result = call f(33); // We require f to return to us

tell f(33); // We require f to go do whatever it wants.

==&gt; Consider we can call or tell any function type?

==&gt; If we call a subroutine the compiler will generate code so that the produced value of f ir returned to us.

==&gt; If we tell a subroutine we ignore the value produced by f.

==&gt; If we call a coroutine the compiler will generate code so the produced value is returned as a future to us.

==&gt; If we tell a coroutine we ignore the value produced by f.

==&gt; Consider call and tell DOES NOT compose?

string subroutine f(int);

float subroutine g(string);

call g(call f(33)); // ??

tell g(call f(33)); // ??

tell g(tell f(33)); // \*Error\*??

3) Consider from a functional point of view ”tell” (ignore result) has no meaning?

==&gt; Consider mathematical functions always maps between sets (the function always produce values)?

==&gt; tell f(33) would mean **f: int -&gt; nothing** ?

==&gt; Can we compose something from nothing?

…

…

Consider to elaborate on this idea to be able to express both the messaging mechanism of ”routines” as well as how we engage with them?

...

{% endraw %}
