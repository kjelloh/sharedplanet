# Todo: Meta Value Stack - Consider the meta value stack dat structure and a corresponding path expressions to interact with this data structure?

```#562500b7``` *As of 2017-06-03 14:03*

[mail plain/text](mail.txt)

{% raw %}
Can we imagine to define a path expression semantics to interact with with the meta model stack declarations and definitions?

1) It seems we need to define the actual Meta-value Stack structure?

==&gt; Consider the default value is meta-0.

”x.y.z” is a path into the value-tree on meta-0 layer.

==&gt; Consider each meta-layer is stored in sub-node ”meta”

{

{ ”” , {

{meta-0-name, meta-1-value, meta-0-value}

{meta-0-name, meta-1-value, meta-0-value}

{meta-0-name, meta-1-value, meta-0-value}

…

}

}

{ ”meta” , {

{meta-1-name, meta-2-value, meta-1-value}

{meta-1-name, meta-2-value, meta-1-value}

{meta-1-name, meta-2-value, meta-1-value}

…

}

}

{ ”meta.meta” , {

{meta-2-name, meta-3-value, meta-2-value}

{meta-2-name, meta-3-value, meta-2-value}

{meta-2-name, meta-3-value, meta-2-value}

…

}

}

...

}

==&gt; Consider this is the complete **miv**?

==&gt; Consider to split each definition into m, i, v levels of completion?

full definition {meta-n-name, meta-n+1-value, meta-n-value}

is in fact {”m”

,{meta-n-name

,{”i"

,{meta-n+1-value

,{”v”, meta-n-value}

}

}

}

”x.y.@m” is {name,{…}}

”x.y.@i” is {meta-value-name, {…}}

”x.y.@v” is value

**…WE ARE HERE**

2) Consider some simple semantics to define path and selectors into the Meta-Value data structure?

==&gt; Consider to use a path-of-names to select a value in the composite structure?

”x.y.z” refers to member element z in member element y in composite element x.

==&gt; Consider how to refer to members of ArrayMetaValue, MetaValueArray, MetaValueRecord

> // Basic meta-value constructs  
> /\*

> \*  
> MetaV {declares DeFactoV} &lt;-----------|  
> | |  
> ----------------------------------------- |  
> | | 1 |  
> AtomicMetaValue CompositeMetaValue ---------|  
> | |  
> | ---------------------------------  
> | | | |  
> | ArrayMetaValue MetaValueArray MetaValueRecord  
> | MetaV vector&lt;MetaV&gt; vector&lt;&lt;Name,MetaV&gt;&gt;  
> |  
> \*\* Layer Specific Atomic Meta Values (e.g., meta-1 Number, Text, POD) \*\*  
> |

Given meta-value definitions:

{”meta.my_array_value”,”meta.number”} // defines name ”meta.my_array_value” to named value ”meta.number” (built in meta-value)

{”meta.my_meta_value_array” // defines ” meta.my_meta_value_array” to have two member meta-values

,{

”meta.number” // Array meta value 1

, ”meta.text” // Array meta-value 2

}

}

{”meta.my_record”

, {

{”x”, ”meta.number”} // Record named meta-value ”x"

, {”y”, ”meta.text”} // Record named meta-value ”y"

}

}

” meta.my_array_value"

==&gt; It seems we can observe that ”.” travels down into defined hierarchy on the same level?

”x.y” refers to meta-0 member vale named ”y” in meta-0 value named ”x”?

==&gt; Then ”meta” indirects the path up to next meta-value hierarchy?

”x.meta.y” refers to member value named ”y” in meta-value of meta-0 value named ”x” (i.e., the declaration of member y)?

==&gt; And ”defacto” indirects to an array of defacto values of the parent path meta-vaule?

”x.meta.defacto” refers to an array of all defacto values declared to be of the same meta-value as ”x"

”x.meta.defacto&#91;”a.b.c”&#93;” tries to select defacto value ”a.b.c” declared to bind to meta-value bound to defacto value ”x"

...

3) Consider to use XPath query language (<https://en.wikipedia.org/wiki/XPath>)?

==&gt; This seems to be the XPath 1.0 specification (<https://www.w3.org/TR/xpath/>)?

==&gt; XPath define expressions that evaluates to elements in the XML document (nodes, properties, values)

…

==&gt; Or maybe we should aim to use XPointer semantics (<https://www.w3.org/TR/WD-xptr>)?

==&gt; XPointer seems to be an EXTENSION of XPath?

> > ”*XPointer is built on top of the XML Path Language &#91;XPath&#93;, which is an expression language underlying the XSL Transformations (XSLT) language. XPointer's extensions to XPath allow it to:*

> > *• Address points and ranges as well as whole nodes*

> > *• Locate information by string matching*

> > *• Use addressing expressions in URI references as fragment identifiers (after suitable escaping)*"

==&gt; Consider existing C++ XPath source code to try out?

==&gt; Consider ”pugixml” (<https://github.com/zeux/pugixml>)?

==&gt; It seems to implement XPath 1.0?

…

Consider to elaborate more on Meta-value structure and corresponding Path expressions to interact with this data structure?

{% endraw %}
