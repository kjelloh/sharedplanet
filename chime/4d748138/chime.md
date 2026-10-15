# Todo: C++ - Consider if we can map C++ code to Unicode symbol representation that is shorter and easier to read?

```#4d748138``` *As of 2017-04-07 11:18*

[mail plain/text](mail.txt)

{% raw %}
Could we imagine we can map existing C++ source code multi character elements and replace them with less and more readable unicode symbols?

1) Consider this page that lists basic two byte unicode characters (<https://unicode-table.com/en/>)?

2) Consider to find single symbols to replace control statement keywords?

==&gt; Can we write ”for” using some easy to read unicode character(s)?

==&gt; Can we write ”if” -”-

…

3) Consider if we can map run-time functions and meta-functions (templates) to some symbols to reuse the same patterns for value morphisms and type morphisms?

==&gt; Consider current C++ uses F(value) for value-functions and F&lt;type&gt; for type-functions?

==&gt; Can we do better if we can use Unicode characters and symbols?

…

4) Consider using mathematical summation and multiplication for algorithms based on this concept?

==&gt; Consider the Unicode symbol ”N-Ary Summation” (U+2211) ’∑’?

std::accumulate(begin,end,init) becomes ∑\*iter (<http://en.cppreference.com/w/cpp/algorithm/accumulate>)?

==&gt; Consider the Unicode symbol "N-Ary Product" U+220F ’∏’?

==&gt; Consider if ”accumulation” and ”multiplication” actually differs in C++ syntax of range algorithms?

==&gt; Consider operator+ and operator\* is in fact just a binary operator and std::accumulate may be used with operator\* to create n-ary multiplication?

...

5) It seems to leverage usage of symbols (e.g., ∑) we need to be able to decorate them above and below (e.g., defining the range of ∑)?

==&gt; Consider how it is NOT enough to just replace sequences of C++ source code characters with Unicode symbols (we need also to leverage the notion of ”above”, ”below”, ”subscript” and ”superscript” etc.)?

...

6) What is C++ current take on Unicode in source code files?

…

…

Consider to elaborate on this idea to map existing C++ source code elements and abstractions to more compact and readable representations using Unicode symbols with ”decorations” like ∑ range definitions?

...

{% endraw %}
