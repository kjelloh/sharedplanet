# Todo: C++ - Write a blog post about the "layers" of compile-time computations value --&gt; type --&gt; template?

```#8954f695``` *As of 2016-12-23 14:06*

[mail plain/text](mail.txt)

{% raw %}
Consider to write a blog post about how C++ allows compile time computation to use values to compute types, types to compute other types and templates to compute types and even templates?

1) Consider how C++ templates allows a template to compute a type from an integral value?

template &lt;int I&gt; struct F { using type = …}

2) Consider how C++ allows a template to compute a type from another type?

template &lt;typename T&gt; struct F { using type = …}

3) Consider how C++ allows a template to compute a template from a type?

template &lt;typename T&gt; struct F { template &lt;typename U&gt; struct G {}; };

4) Consider how C++ allows a template to compute a value, a type AND a template from an integral value, type AND template template parameter?

…

5) Consider to visualize these levels and ”functions” mapping a Set on one level to the next?

==&gt; Consider lifting from integral values to types (using scalar template parameter specialization)?  
==&gt; Consider lifting from ”simple” types to ”compound” types using class templates (e.g. vector&lt;T&gt;)  
==&gt; Consider lifting from types to templates using class template member templates?

==&gt; Consider it should be possible to compute a class with a member template and then use that template (i.e. the computed template)?

==&gt; Consider each such level defines morphisms from one closed Set to another?

==&gt; Set of scalars I to Set of types F&lt;I&gt;?  
==&gt; Set of ”simple” Types T to set of ”Compound” Types G&lt;T&gt;?  
==&gt; Set of Types U to Set of Templates H&lt;U&gt;::template G?  
…

{% endraw %}
