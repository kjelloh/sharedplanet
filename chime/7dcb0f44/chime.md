# Todo: C++ - Consider to really try and understand C++ arrays, their types and copy semantics (especially for template specialisation)?

```#7dcb0f44``` *As of 2017-08-06 00:10*

[mail plain/text](mail.txt)

{% raw %}
So, it seems I still have not wrapped my head around C++ raw arrays. Especially how we can capture their type for template specialisation and provide wrappers for char&#91;N&#93; stuff!

1) Consider to try out code using raw C++ arrays in a C++ Console Project?

==&gt; See Synced “/Users/kjell-olovhogdahl/BitTorrent Sync/XCode/MyCppRawArrayPlayground/MyCppRawArrayPlayground”

…

2) Consider to understand how the raw array element count template specialisation actually works?

==&gt; It seems to be based on an obscure C++ syntax for C+ array reference?

> template &lt;typename T, size_t N&gt;  
> size_t static_element_count(T (&pX)&#91;N&#93;)  
> {  
> return N;  
> }

==&gt; This seems to mean that static_element_count takes a fixed sized raw C parameter **by reference**?

==&gt; Raw arrays always has a static capacity (declared at compile time)

==&gt; A raw array T&#91;N&#93; (some type T and element count N) seems to have type signature "T (&pX)&#91;N&#93;”?

==&gt; And we can specialise a template function on this type to capture raw array size at compile time

> namespace raw_1 {

> struct A {  
> int x;  
> int y;  
> };

> void test_and_print() {  
> int i&#91;3&#93;;  
> float f&#91;5&#93;;  
> A a&#91;7&#93;;  
> std::cout &lt;&lt; '\\n' &lt;&lt; "test_and_print output..." &lt;&lt; '\\n';  
> std::cout &lt;&lt; '\\n' &lt;&lt; "int i&#91;3&#93; \\t has capacity for " &lt;&lt; static_element_count(i) &lt;&lt; " int{} objects";  
> std::cout &lt;&lt; '\\n' &lt;&lt; "float f&#91;5&#93; \\t has capacity for " &lt;&lt; static_element_count(f) &lt;&lt; " float{} objects";  
> std::cout &lt;&lt; '\\n' &lt;&lt; "A a&#91;7&#93; \\t\\t has capacity for " &lt;&lt; static_element_count(a) &lt;&lt; " A{} objects";  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\"Hello\\"\\t\\t has capacity for " &lt;&lt; static_element_count("Hello") &lt;&lt; " char{} objects";  
> }

> }

> **test_and_print output...**

> **int i&#91;3&#93;   has capacity for 3 int{} objects**  
> **float f&#91;5&#93;   has capacity for 5 float{} objects**  
> **A a&#91;7&#93;   has capacity for 7 A{} objects**  
> **"Hello"  has capacity for 6 char{} objects**

==&gt; C++ raw arrays are in fact C arrays!

==&gt; They don’t support copy semantics but C++ range for loop can iterate over them.

> namespace raw_2 {

> void test_and_print() {  
> std::cout &lt;&lt; '\\n' &lt;&lt; "test_and_print output..." &lt;&lt; '\\n';  
> int i&#91;3&#93;;  
> // int j&#91;3&#93; = i; // Error Array initializer must be an initializer list  
> std::cout &lt;&lt; '\\n' &lt;&lt; "int i&#91;3&#93;;";  
> std::cout &lt;&lt; '\\n' &lt;&lt; "int j&#91;3&#93; = i; // Error: Array initializer must be an initializer list";  
> std::cout &lt;&lt; '\\n' &lt;&lt; "C++ range for loop works on C arrays";  
> std::cout &lt;&lt; '\\n' &lt;&lt; "for (auto e : i) {";  
> for (auto e : i) {  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\te = " &lt;&lt; e;;  
> }  
> std::cout &lt;&lt; '\\n' &lt;&lt; "}";  
> }  
> }

> **test_and_print output...**

> **int i&#91;3&#93;;**  
> **int j&#91;3&#93; = i; // Error: Array initializer must be an initializer list**  
> **C++ range for loop works on C arrays**  
> **for (auto e : i) {**  
> **e = 32767**  
> **e = 0**  
> **e = 1**  
> **}**

==&gt; It seems we can actually work with string literals (as long as we know the obscure C++ syntax for const references)?

==&gt; See const char(&sz2)&#91;6&#93; = "Okey “; below!

> namespace raw_3 {  
> void test_and_print() {  
> std::cout &lt;&lt; '\\n' &lt;&lt; "test_and_print output..." &lt;&lt; '\\n';  
> std::cout &lt;&lt; '\\n' &lt;&lt; "C++ range for loop works on string literals";  
> std::cout &lt;&lt; '\\n' &lt;&lt; "for (auto e : \\"Hello\\") {";  
> for (auto e : "Hello") {  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\te = ";  
> if (e &gt;= ' ') std::cout &lt;&lt; e; else std::cout &lt;&lt; "\\\\" &lt;&lt; std::to_string(e);  
> }  
> std::cout &lt;&lt; '\\n' &lt;&lt; "}";  
> auto sz = "Ouups"; // sz will be const char\*, NOT char(&sz)&#91;6&#93;  
> std::cout &lt;&lt; '\\n' &lt;&lt; "auto sz = \\"Ouups\\"; // sz decays to const char\*, from const char(&sz)&#91;6&#93;";  
> // static_element_count(sz); // Error - No matching function for call to 'static_element_count'  
> std::cout &lt;&lt; '\\n' &lt;&lt; "static_element_count(sz); // Error - No matching function for call to 'static_element_count' ";  
> const char(&sz2)&#91;6&#93; = "Okey "; // Obscure C syntax!  
> std::cout &lt;&lt; '\\n' &lt;&lt; "const char(&sz2)&#91;6&#93; = \\"Okey \\"; \\t has capacity for " &lt;&lt; static_element_count(sz2) &lt;&lt; " int{} objects";  
> }  
> }

> **test_and_print output...**

> **C++ range for loop works on string literals**  
> **for (auto e : "Hello") {**  
> **e = H**  
> **e = e**  
> **e = l**  
> **e = l**  
> **e = o**  
> **e = \\0**  
> **}**  
> **auto sz = "Ouups"; // sz decays to const char\*, from const char(&sz)&#91;6&#93;**  
> **static_element_count(sz); // Error - No matching function for call to 'static_element_count' **  
> **const char(&sz2)&#91;6&#93; = "Okey ";   has capacity for 6 int{} objects**

==&gt; We need to beware of raw array decay to pointer!

> namespace raw_4 {  
> // Inspired by <https://stackoverflow.com/questions/1461432/what-is-array-decaying>

> // "const T array&#91;&#93;" same type as "const T\* array"  
> template &lt;typename T&gt; void by_value_1(const T\* array) {  
> std::cout &lt;&lt; '\\n' &lt;&lt; "template &lt;typename T&gt; void by_value_1(const T\* array) called.";  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\tarray is T\*, element count unknown";  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\tarray = \\"" &lt;&lt; array &lt;&lt; '\\"';  
> //std::cout &lt;&lt; '\\n' &lt;&lt; "static_element_count(array) = " &lt;&lt; static_element_count(array); // Error - No matching function for call to 'static_element_count'  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\tstatic_element_count(array); // Error - No matching function for call to 'static_element_count'";  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\tsizeof(array) = " &lt;&lt; sizeof(array) &lt;&lt; " = memory byte count (including allignment)";  
> }

> // "const T array&#91;&#93;" same type as "const T\* array"  
> template &lt;typename T&gt; void by_value_2(const T array&#91;&#93;) {  
> std::cout &lt;&lt; '\\n' &lt;&lt; "template &lt;typename T&gt; void by_value_1(const T\* array) called.";  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\tarray is T\*, element count unknown";  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\tarray = \\"" &lt;&lt; array &lt;&lt; '\\"';  
> //std::cout &lt;&lt; '\\n' &lt;&lt; "static_element_count(array) = " &lt;&lt; static_element_count(array); // Error - No matching function for call to 'static_element_count'  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\tstatic_element_count(array); // Error - No matching function for call to 'static_element_count'";  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\tsizeof(array) = " &lt;&lt; sizeof(array) &lt;&lt; " = memory byte count (including allignment)";  
> }

> template &lt;typename T, size_t N&gt; void by_pointer(const T (\*array)&#91;N&#93;) {  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\ttemplate &lt;typename T, size_t N&gt; void by_pointer(const T (\*array)&#91;N&#93;) called";  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\tarray = \\"" &lt;&lt; array &lt;&lt; '\\"';  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\tstatic_element_count(array) = " &lt;&lt; static_element_count(array) &lt;&lt; " ok";  
> }

> template &lt;typename T, size_t N&gt; void by_reference(const T (&array)&#91;N&#93;) {  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\ttemplate &lt;typename T, size_t N&gt; void by_reference(const T (&array)&#91;N&#93;) called";  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\tarray = \\"" &lt;&lt; array &lt;&lt; '\\"';  
> std::cout &lt;&lt; '\\n' &lt;&lt; "\\tstatic_element_count(array) = " &lt;&lt; static_element_count(array) &lt;&lt; " ok";  
> }

> void test_and_print() {  
> std::cout &lt;&lt; '\\n' &lt;&lt; "test_and_print output..." &lt;&lt; '\\n';  
> std::cout &lt;&lt; '\\n' &lt;&lt; "by_value_1(\\"Hello\\");";  
> by_value_1("Hello");  
> std::cout &lt;&lt; '\\n' &lt;&lt; "by_value_2(\\"Hello\\");";  
> by_value_2("Hello");  
> std::cout &lt;&lt; '\\n' &lt;&lt; "by_pointer(\\"Hello\\"); // Error - No matching function for call to 'by_pointer'";  
> // by_pointer("Hello"); // Error - No matching function for call to 'by_pointer'  
> std::cout &lt;&lt; '\\n' &lt;&lt; "by_reference(\\"Hello\\");";  
> by_reference("Hello");  
> }  
> }

> **test_and_print output...**

> **by_value_1("Hello");**  
> **template &lt;typename T&gt; void by_value_1(const T\* array) called.**  
> **array is T\*, element count unknown**  
> **array = "Hello"**  
> **static_element_count(array); // Error - No matching function for call to 'static_element_count'**  
> **sizeof(array) = 8 = memory byte count (including allignment)**  
> **by_value_2("Hello");**  
> **template &lt;typename T&gt; void by_value_1(const T\* array) called.**  
> **array is T\*, element count unknown**  
> **array = "Hello"**  
> **static_element_count(array); // Error - No matching function for call to 'static_element_count'**  
> **sizeof(array) = 8 = memory byte count (including allignment)**  
> **by_pointer("Hello"); // Error - No matching function for call to 'by_pointer'**  
> **by_reference("Hello");**  
> **template &lt;typename T, size_t N&gt; void by_reference(const T (&array)&#91;N&#93;) called**  
> **array = "Hello"**  
> **static_element_count(array) = 6 ok**

==&gt; The obscure C++ C array reference syntax seems to work for template parameter also?

> namespace raw_5 {

> template &lt;typename T&gt; struct A {T t;};

> void test_and_print() {  
> std::cout &lt;&lt; '\\n' &lt;&lt; "test_and_print output..." &lt;&lt; '\\n';  
> std::cout &lt;&lt; '\\n' &lt;&lt; "template &lt;typename T&gt; struct A {T t;};";  
> A&lt;const char(&)&#91;6&#93;&gt; a{"Okey "};  
> std::cout &lt;&lt; '\\n' &lt;&lt; "A&lt;const char(&)&#91;6&#93;&gt; a{\\"Okey \\"}; \\t a.t has capacity for " &lt;&lt; static_element_count(a.t) &lt;&lt; " int{} objects";  
> }

> }

> **test_and_print output...**

> **template &lt;typename T&gt; struct A {T t;};**  
> **A&lt;const char(&)&#91;6&#93;&gt; a{"Okey "};   a.t has capacity for 6 int{} objects**

==&gt; …

…

Consider to complete this study of C arrays in C++?

...

{% endraw %}
