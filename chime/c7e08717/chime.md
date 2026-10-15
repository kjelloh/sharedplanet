# Todo: Programming - Consider to study the pattern of composition in C++ using templates as layers of Sets?

```#c7e08717``` *As of 2016-12-24 16:55*

[mail plain/text](mail.txt)

{% raw %}
Consider to elaborate on the patterns we can recognize from studying composition of types using templates in C++?

1) Consider the three layers Type T, Composed type F&lt;T&gt; and the template F?

Layer 1) Set of one parameter Templates, F being one

Layer 2) Set of Objects of Composed Type F&lt;T&gt;

Layer 3) Set of objects T

2) Consider examples of such layers using some known one parameter templates?

==&gt; Consider template std::vector

Layer 1) The template std::vector

Layer 2) Set of Objects of Composed Type std::vector&lt;T&gt;

Layer 3) Set of objects T

==&gt; Consider template std::optional

Layer 1) The template std::optional

Layer 2) Set of Objects of Composed Type std::optional&lt;T&gt;

Layer 3) Set of objects T

==&gt; Consider template std::future

Layer 1) The template std::future

Layer 2) Set of Objects of Composed Type std::future&lt;T&gt;

Layer 3) Set of objects T

3) Consider how the elements on each layer corresponds to just one element in the Set in the layer above (and a multiplicity of elements in the Set of the layer below)

==&gt; Consider each Set in layers one (e.g. The Set of int, bool, std::path…) corresponds to just one Set in layer 2 (std::vector&lt;int or bool or std::path&gt; or std::optional&lt;int or bool or std::path&gt; or std::future&lt;int or bool or std::path&gt;

Layer 2) Set of std::vector&lt;int&gt; {{0}, {0,2,16}, {0,1,2,3,4},...}

Layer 1) Set of int {0,1,2,3,4,5,6,…}

4) Consider the composition layer 2 may actually be repeated to create composition-of-composition, composition-of-composition-of-composition,…

==&gt; Consider this corresponds to T, TT, TTT?

==&gt; Consider std::vector&lt;T&gt;, std::vector&lt;std::vector&lt;T&gt;&gt;, std::vector&lt;std::vector&lt;std::vector&lt;T&gt;&gt;&gt;,…

==&gt; Consider std::optional&lt;T&gt;, std::optional&lt;std::optional&lt;T&gt;&gt;, std::optional&lt;std::optional&lt;std::optional&lt;T&gt;&gt;&gt;,…

==&gt; Consider std::future&lt;T&gt;, std::future&lt;std::future&lt;T&gt;&gt;, std::future&lt;std::future&lt;std::future&lt;T&gt;&gt;&gt;,…

**==&gt; Consider these composition layers are in fact what the ”Functor” defines?**

5) Consider how important it is that the Closed Binary Operations in Layer 3 is preserved in Layer 2?

==&gt; Consider how nice it becomes if std::vector&lt;int&gt; v1 + std::vector&lt;int&gt; v2 = std::vector&lt;int + int&gt; v3?

==&gt; Layer 2) std::vector: {x} + {y} = {z}

==&gt; Layer 2) std::optional: std::optional(x) + std::optional(y) = std::optional(z)

==&gt; Layer 2) std::future: std::future(x) + std::future(y) = std::future(z)

==&gt; Layer 1) int: x + y = z

6) Consider the patterns that emerge when we have functions that maps between Sets on the same layer?

==&gt; Consider the function is_even that maps the set of int to the Set of bool?

Layer 1) Set A of int {0,1,2,3,4,…} —&gt; is_even(a) —&gt; Set B of bool {false, true}

==&gt; Consider how we may compose functions to apply them to compositions of T?

==&gt; Consider Composition std::vector

Layer 2) Set of std::vector&lt;int&gt; —&gt; ??&lt;is_even&gt; —&gt; Set of std::vector&lt;bool&gt;

Layer 1) Set A of int {0,1,2,3,4,…}  —&gt; is_even(a) —&gt; Set B of bool {false, true}

==&gt; Consider Composition std::optional

Layer 2) Set of std::optional&lt;int&gt; —&gt; ??&lt;is_even&gt; —&gt; Set of std::optional&lt;bool&gt;

Layer 1) Set A of int {0,1,2,3,4,…}  —&gt; is_even(a) —&gt; Set B of bool {false, true}

==&gt; Consider Composition std::future

Layer 2) Set of std::future&lt;int&gt; —&gt; ??&lt;is_even&gt; —&gt; Set of std::future&lt;bool&gt;

Layer 1) Set A of int {0,1,2,3,4,…}  —&gt; is_even(a) —&gt; Set B of bool {false, true}

…

7) Consider how important it is that the function behaves well with the closed operations on both the source and target Sets?

==&gt; Layer 1) Set A of int {0,1,2,3,4} we have ’+’ and ’\*’ so that the result remains in the same Set (the operations are Closed)

==&gt; 3+7 = 10 is still an int.

==&gt; 3\*7 = 21 is still an int.

Layer 1) Set A of int {0,1,2,3,4,…}  —&gt; is_even(a) —&gt; Set B of bool {false, true}

==&gt; is_even(3+7) != is_even(3) + is_even(7) ==&gt; The function may or may not perserve the relations between members of source and target Set (in this case the relation IS NOT perserved)

==&gt; is_even(3\*7) != is_even(3) \* is_even(7) ==&gt; The function may or may not perserve the relations between members of source and target Set (in this case the relation IS NOT perserved)

==&gt; NOTE: The binary operations in Set A and Set B may be totally different (in this case operator+(int,int) and operator\*(int,int) ins Set&lt;int&gt; is totally unrelated to operator&&(bool,bool) and operator||(bool, bool) in Set&lt;bool&gt;)

==&gt; NOTE: We are able to define mapping of the binary operations in Set&lt;int&gt; to the Set&lt;bool&gt; for is_even!

==&gt; is_even(x + y) == is_even(x) XOR is_even(y)

==&gt; is_even(x\*y) == is_even(x) OR is_even(y)

…

Consider to elaborate on these patterns more to recognize what patterns are actually the most relevant ones?

...

{% endraw %}
