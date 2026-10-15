# Todo: Meta Value Model - Consider we need the "pair" composition to be able to operate on arrays (lists) as head-tail pairs?

```#d0816141``` *As of 2017-06-10 15:23*

[mail plain/text](mail.txt)

{% raw %}
It seems we need the composition ”pair” to be able to operate on arrays (lists) as head-tail pairs?

==&gt; Also see ”Todo: Meta Value Model - Consider all values (and the whole mode) is immutable (all mutations create new instance)?”

==&gt; Also see ”Todo: Meta Value Model - Consider to enable "Meta Value Lisp" scripting language to allow name-paths to refer to structure members ”

==&gt; Also see ”Todo: Meta Value Model - Consider to define built-in value compositions using syntax Value&lt;level 2,1,0&gt; and members as_function, as_value, as_text?"

1) Consider the Pair&lt;meta-n&gt; meta-layer Values?

Pair&lt;meta2&gt; would be the unstructured (**Atomic**) meta-value that defines the Set { …any Pair&lt;meta1&gt;… } // **Initial** meta-layer

Identifier ”**pair**” defined to value Pair&lt;meta2&gt;

Function defacto(Value&lt;meta1&gt; first, Value&lt;meta1&gt; second) returns Value Pair&lt;meta1&gt;

Pair&lt;meta1&gt; would be the structured (pair {first_type, second_type}) meta-value that defines the Set { … any Pair&lt;meta0&gt; …} , defacto(Value&lt;meta0&gt;, Value&lt;meta0&gt;)

Value operation (”**first**” Pair&lt;meta1&gt;) returns first pair member Value&lt;meta1&gt;

Value operation (”**second**” Pair&lt;meta1&gt;) returns second pair member Value&lt;meta1&gt;

Pair&lt;meta0&gt; would be structured (pair {first_value, second_value}) value that defines Set { void }, defacto = void // **Terminating** meta-layer

Value operation (”**first**” Pair&lt;meta0&gt;) returns first pair member Value&lt;meta0&gt;

Value operation (”**second**” Pair&lt;meta0&gt;) returns second pair member Value&lt;meta0&gt;

...

2) Consider the Array&lt;meta-n&gt; meta-layer Values?

Array&lt;meta2&gt; would be unstructured (**Atomic**) meta-value that defines the Set {… any Array&lt;meta1&gt; …} // **Initial** meta-layer

Identifier ”**array**” bound to value Array&lt;meta2&gt;

Function defacto(Value&lt;meta1&gt; value_type)

Array&lt;meta1&gt; would be structured (aggregates Identifier&lt;meta1&gt; value_type) meta-value that defines the Set {… any Array&lt;meta0&gt; …}

Array&lt;meta0&gt;

Value operation (”**append**” Array&lt;meta1&gt; Value&lt;meta1&gt; ) returns Array&lt;meta1&gt; with argument array extended with argument value

Value operation (”**head**” Array&lt;meta0&gt;) returns the first Value&lt;meta0&gt; in the array.

Value operation (”**tail**” Array&lt;meta0&gt;) returns an Array&lt;meta0&gt; which is the original array with first value removed

...

…

{% endraw %}
