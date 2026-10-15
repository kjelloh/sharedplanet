# Todo: C++ Editor - Consider the Editor should really understand and protect source code identifier integrity (copy-paste and edit should never break them)?

```#d8422252``` *As of 2017-07-25 12:57*

[mail plain/text](mail.txt)

{% raw %}
Consider we really would like a C++ editor to understand Identifier relations and never break them?

==&gt; Also see “Todo: Programming - Consider to elaborate on some cool features of the "Dream IDE" for C++ programming?"

==&gt; Also see “Todo: Dream C++ IDE - Consider a cut-and-paste function that adapts source code to the paste location (e.g. inline versus external definition of member methods)?”

==&gt; Also see “Todo: Programming - Consider to re-visit Pandora and design it as part of a Dream C++ IDE?"

1) Consider copy-paste of a class should render a pasted class withs its own name?

==&gt; Consider copy of this class?

> class My_Foo_1 {  
> My_Foo_1(My_Foo_1&& other) {}  
> };

==&gt; Pasting it should protect the original class by defining one with a new name?

> class My_Foo_2 {  
> My_Foo_2(My_Foo_2&& other) {}  
> };

==&gt; Consider editing a class identifier should result in all source code bound to that reference to change?

==&gt; Consider code with an Identifier used on several locations?

> class Plain_Foo_1 {};  
> class My_Foo_1 {  
> My_Foo_1(My_Foo_1&& other) {}  
> };  
> class My_Foo_2 {  
> My_Foo_2(My_Foo_2&& other) {}  
> };

> void test() {  
> Plain_Foo_1 foo1; // Ok, compiler default constructor  
> // My_Foo_1 foo2; // Error, No default constructor  
> }

==&gt; Consider deleting ‘1’ from the Identifier My_Foo_1 should change to protect code integrity (also in comments)?

> class Plain_Foo_1 {};  
> class My_Foo_ {  
> My_Foo_(My_Foo_&& other) {}  
> };  
> class My_Foo_2 {  
> My_Foo_2(My_Foo_2&& other) {}  
> };  
> void test() {  
> Plain_Foo_1 foo1; // Ok, compiler default constructor  
> // My_Foo_ foo2; // Error, No default constructor  
> }

…

2) Consider this would be possible with the Pandora view of C++ source code (code model understands Identifier bindings)?

…

…

Consider to add this to the wish-list of the C++ dream editor?

{% endraw %}
