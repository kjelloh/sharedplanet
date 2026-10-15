# Todo: C++ - Consider to make an "Immutable C++" language that generates C++ code where everything is const (immutable) by default?

```#590d5d4d``` *As of 2017-01-29 12:16*

[mail plain/text](mail.txt)

{% raw %}
Could ut be a fun and good idea to implement an Immutable C++ language that looks exactly like C++ but where everything is immutable (const) by default?

1) Consider a good working name for this ”Immutable C++” language?

==&gt; Consider to call it "C!!” ?

==&gt; Consider to call it "C const const”?

==&gt; No - sounds like related to C and not C++?

...

1) Consider what would be required by the Immutable C++ parser to understand C++ code and turn it into immutable C++?

==&gt; Every variable definition must be const and initiate to a value

**Immutable C++ Generated C++**

int a; const int a{init_value} // Imm C++ compiler error - Missing Initialization value

int a = 4 const int a{4}

==&gt; Every assignment must produce a new instance

**Immutable C++ Generated C++**

a += 3; const int a2 = a+3; // Imm C++ must then replace all following references to variable a in the code and replace with a2

2) Consider a base variant of Immutable C++ that only applies const by default (requiring the programmer to explicitly say what is mutable)?

==&gt; Consider all declarations in C++ code is generated to const C++ code by default?

**Immutable C++ Generated C++**

int a = 4; const int a{4};

==&gt; Consider to add a key-word to Immutable C++ to state a variable to be mutable?

**Immutable C++ Generated C++**

**state** int a = 4; int a = 4;

2) Consider Immutable C++ can apply an Immutable Data Type library and replace C++ code types with their Immutable replacements?

==&gt; Consider std::vector&lt;T&gt; is replaced by imm::vector&lt;T&gt;?

**C++ Immutable C++**

std::vector&lt;int&gt; v; imm::vector&lt;int&gt; v{};

v.push_back(4); auto v2 = v.push_back(4); // v2 shares v but has 4 added to end

…

==&gt; Consider state variables are turned into iterator into a history vector of immutable type

state int a = 4; std::vector&lt;const int&gt; a_history = {4};

auto a{a_history.begin()};

a += 3; \*(a++) = \*a + 3;

...

==&gt; Seems like this may cause quite a code bloat (large amounts of redundant history created)?

==&gt; Consider to combine with some efficient ”garbage collection” of never used history states?

...

…

Consider to elaborate on we can define Immutable C++ to compile C++ code into C++ code where all data is immutable by default?

{% endraw %}
