# Todo: Darwinet - Consider Model-paths to be able to handle the Model Meta layers (Value definition, Type definition, Type Constructor Definition)?

```#151291f4``` *As of 2017-05-29 13:20*

[mail plain/text](mail.txt)

{% raw %}
So, how can we define a Path semantics to be able to change model state on different Meta Layers (value, Type, Type Constructors)?

1) Consider in Darwinet the Meta-layers terminate into ONE SINGLE Meta-Value?

==&gt; Consider the Meta-Layer of the Type Constructors to simply have one single ”Type Constructor Constructor”?

Value: {myInt, meta::int}  
Type: {int, meta::int-constrcutor}  
Meta-Type: {int-constructor, meta:type_constructor_constructor}  
Meta-Meta-Type: {type_constructor_constructor, \*\* built in \*\*}

type_constructor_constructor&lt;number&gt; instantiates a type-constructor that creates number types.  
type_constructor_constructor&lt;text&gt; instantiates a type-constructor that creates text types.  
type_constructor_constructor&lt;record&gt; instantiates a type-constructor that creates record types.  
type_constructor_constructor&lt;array&gt; instantiates a type-constructor that creates array types.

==&gt; The Darwinet Paths would then be:

Value: ”myInt”  
Type: ”meta.int”  
Meta-Type: ”meta.meta.int-constructor”  
Meta-Meta-Type: ”meta.meta.meta. type_constructor_constructor”  
…

2) Consider it is so ”Bad” that we actually have Model, Instance, Value on EACH META-Layer?

==&gt; Consider each layer defines Value = {name, Meta-Value}.  
==&gt; Then we may create or destroy a Value on each Meta-layer (using a Meta-layer specific path)?

NEW ”myInt” 3, would create an integer value 3 named myInt  
NEW ”meta.my_int_type” ”meta.int”, would create a new type with the same value as the built-in int type?  
NEW ”meta.meta.my_int_constructor” ”meta.meta.int-constructor”, would create a new type-constructor with the same value as the built-in int-constructor?

3) Consider actually a Darwinet Client may only operate on values and types (one meta-layer)?

==&gt; A Darwinet Client may define named records and arrays and modify these types (Meta-values)?

// Type ”values” are created by setting them to built-in values (types)  
Type: NEW ”meta.myRecordType” ”meta.RECORD” (instantiate to the built-in value meta.RECORD, i.e., the RECORD type)  
Type: NEW ”meta.myRecordType.member1” ”meta.number” (instantiate to the built-in value meta.number i.e., the number type)  
Type: NEW ”meta.myRecordType.member2” ”meta.text” (instantiate to the built-in value meta.text i.e., the text type)  
Type: NEW ”meta.myRecordType.member2” ”meta.ARRAY” (instantiate to the built-in value meta.ARRAY i.e., the ARRAY type)  
Type: NEW ”meta.myRecordType.member3” ”meta.RECORD” (instantiate to the built-in value meta.number i.e., the number type)

NO - The above does NOT WORK!

==&gt; On each level we need to be able to define {name, meta-value} and instantiate {name, value} SEPARATELY!

==&gt; Consider: DECLARE {name, meta-value} and UNDECLARE {name} to modify value presence traits?  
==&gt; Consider: CREATE {name, value} and DESTROY {name} to modify actual value instance?  
==&gt; Consider: MUTATE {name,value} to modify value of an existing instance?  
...

…

Consider to try out approaches to be able to both implement Darwinet MIV and be able to use Path as identifier to element in the MIV to reference?  
...

{% endraw %}
