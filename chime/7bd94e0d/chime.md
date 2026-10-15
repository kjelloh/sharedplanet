# Todo: C++ Tha - Consider how we can understand template specialisation as compile time Kind-constructor-dispatching (overloaded on argument lookup)?

```#7bd94e0d``` *As of 2020-04-14 12:10*

[mail plain/text](mail.txt)

{% raw %}
I want to try and apply the meta-defacto pattern also for kind-sort relations and suspects c++ "template" in fact defines a compile time Kind-construction function.

1) Consider the examples in "" of partial template specialisation ()

> **template**&lt;class T1, class T2, int I&gt;  
> class A {}; // primary template  
> **template**&lt;class T, int I&gt;  
> class A&lt;T, T\*, I&gt; {}; // #1: partial specialization where T2 is a pointer to T1

> **template**&lt;class T, class T2, int I&gt;  
> class A&lt;T\*, T2, I&gt; {}; // #2: partial specialization where T1 is a pointer  
> **template**&lt;class T&gt;  
> class A&lt;int, T\*, 5&gt; {}; // #3: partial specialization where T1 is int, I is 5,  
> // and T2 is a pointer

> **template**&lt;class X, class T, int I&gt;  
> class A&lt;X, T\*, I&gt; {}; // #4: partial specialization where T2 is a pointer

==&gt; Consider to print the C++ template specialisations for manual "scribbling" and note taking?

## Attachments

- [Tha C++ Template Specialisation Study.pages](<Tha C++ Template Specialisation Study.pages>)

{% endraw %}
