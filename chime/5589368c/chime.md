# Todo: Meh Tha - Consider to have litters be constructors of meta items (e.g., define the string literal to be the constructor of an Identifier)?

```#5589368c``` *As of 2017-06-21 12:04*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to make the string literal the constructor of an Identifier?

1) Consider what it would mean semantically in Meh to have the string literal be the constructor of Idnetifiers?

Meh´&gt; (”my_int” int) // would mean the identifier ”my_int” declared to be meta-value named ”int”?  
Meh´&gt; (my_int 5) // Would mean my_int defined to value 5?

==&gt; Q: Is this confusing (declaration uses ”” and definition does not)?

Meh´&gt; ((”my_int” int) 5) // ”my_int” declared as int and then defined as 5?  
Meh´&gt; (”my_int” int 5) // Enable Identifier constructor be generic and accept meta-value and value in one go (fully declared and defined)?  
…

==&gt; Consider to compare with how it works in Lisp and proposed in Meh?

List&gt; (define my_int int) //declares my_int as an int in Lisp?  
Meh´&gt; (identifier my_int int) // Declares idnetifier my_int to be meta-value int.  
...

2) Consider the int literal to be the constructor of a fixed sized vector?

Meh´&gt; (5 int) // Would mean anonymous vector of 5 ints?  
Meh¨&gt; (”my_vector” (5 int)) // Would mean value with name ”my_vector” declared as vector of five ints?  
Meh´&gt; ((”my_vector” (5 int)) 1 2 3 4 5) // Would mean my_int is a vector with 5 elements (1 2 3 4 5)?

Hm… what is the point with this?  
…

==&gt; Consider to compare with how it works in Lisp and proposed in Meh?

Lisp&gt;? // Lisp dos not define fixed sized lists (all sequences are immutable but dynamic in instance size)  
Meh´&gt;?? // In Meh we have not considered any fixed sized sequences (do we need them)?

==&gt; Consider in Meh we may bind a meta-0 value to a meta-1 value generic value as constraint (it applies cardinality matching)?  
...

…

Consider to put this idea in the back of my mind to see if it can be fond valuable for some aspect of programming in Meh?  
...

{% endraw %}
