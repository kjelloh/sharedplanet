# Todo: Programming - Consider to always use RAII objects with throwing constructors (and apply to current clang-bcc process RAII class)?

```#3b2e1ebc``` *As of 2016-07-24 15:11*

[mail plain/text](mail.txt)

{% raw %}
It seems like a good advice with sound rationals to always have RAII objects throw on failure to acquire the resource?

1) Consider that a two-stage RAII object with lazy init-on-access gains is nothing?

==&gt; Consider to change the RAII Process class in clang-bcc project?

...

2) Consider what the Core Guidelines has to say about RAII and exceptions (<https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#e6-use-raii-to-prevent-leaks>)?

3) Consider to understand how to use smart resource owners to delete created resources when destructor is not called after constructors throw?

==&gt; Consider this article as having good leans to the rules of throwing constructors (<http://en.cppreference.com/w/cpp/language/raii>)

==&gt; It seems the destructor is not called if the constructors throws?

==&gt; But it seems constructed members objects are still destructed?

== &gt;So, by wrapping acquired requires in RAII classes those constructed ok will be released even if the aggregating (owning) class destructor is not called?

...

==&gt; Consider this post on RAII and exceptions from microsoft (<https://msdn.microsoft.com/en-us/library/hh279653.aspx>)?

4) Consider this C++ argument about why using exceptions in the post place (<https://isocpp.org/wiki/faq/exceptions>)?

5) Consider Stroustrup on RAII (<http://www.stroustrup.com/bs_faq2.html#finally>)?

6) Consider the C++ standard proposal of ”RAII Wrappers” to the Standard Library (<http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3677.html>)?

==&gt; Seems like a good design idiom?

...

{% endraw %}
