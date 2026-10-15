# Todo: Programming - Why does not a C++ compiler implement constexpr by compile-and-run to get the compile-time value?

```#e921b5ee``` *As of 2016-03-15 14:07*

[mail plain/text](mail.txt)

{% raw %}
Why does it seem C++ compilers uses a special C++ interpreter to “run” constexpr expressions at compile time? Would it not be “better” if it boot-strapped itself to actually compile-and-run the constexpr code to get the compile-time value to use?

1) This should enable constexpr code to use any run-time available code?

==&gt; Compiler compiles the code, runs it on the platform and retrieves the returned value?  
==&gt; Both compile-time and run-time uses the same compiled code?

2) Generally, why does the compiler need to “interpret” the code rather that just compile-and-run it?

==&gt; Consider to elaborate on this question to find why it may/or may not work?

3) Errors in constexpr code would show up as compile, link or run-time code just as “ordinary” code?

4) Can we make this approach solve the problem of turning string-literals into template type parameters?

==&gt; We would like something like...

template &lt;int tag,char\* name&gt;  
struct Element {  
static int _tag = Tag;  
static char\* _name = name;  
};

typedef Element&lt;0xFF7E32,”cdoOP_INIT”&gt; cdoOP_INIT;

Hm… More thinking needed…

…

Anyhow, consider to delve deeper into this idea why not have the compiler generate and run constexpr code at compile-time to get the compile-time values to put into code to generate final run-time code?  
...

{% endraw %}
