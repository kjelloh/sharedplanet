# Todo: Darwinet - Consider the general relation between Meta-values and values (e.g., consider meta-value atom, record, array to be general)?

```#3bcffda8``` *As of 2017-06-02 19:23*

[mail plain/text](mail.txt)

{% raw %}
So, what can we say to be general relations between meta-values and values (e.g., between values and types as well as between types and meta-types)?

-2) It seems we have Leaf and Cpmposite Meta Values?

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
> \*\* Layer Specific \*\*  
> |  
> -------------  
> | |  
> AtomicMetaValue1 AtomicMetaValue2 ...  
> (Meta-1 Number) (Meta-1 Text) (Meta-1 POD)

> A Leaf Meta Value defines an atomic defacto value

> Meta Level 1 (types) has Atomic Meta Values for Number and Text.  
> ...

> A Composite Meta Value has member(s) that are Meat-Values

> An Array Meta Value has one Meta Value members that defines DeFacto values of a Defacto Array  
> A Meta Value Array is a typle of indexed Meta-Values  
> A Meta Value Record has named Meta Value members

> \*/

==&gt; Thus it seems each meta-level differs only in the Set of Atomic Meta Values?

…

-1) It seems the problem is in fact how to implement the Value-MetaValue idiom in a C++ implementation?

==&gt; All Values and MetaValues are in fact C++ objects (which can get confusing when naming necessary classes)

==&gt; E.g., A C++ Class is in fact a meta-value (a type)

MetaNumberValue mv;  
NumberValue v = mv(3); // MetaNumber value acts as constructor for NumberValue instances

…

1) Consider the meta-value allows composition of value declarations and definitions?

==&gt; An atom value is defined by an atom meta-value that defines an unstructured 1-to-1 relation?

A number value is defined by the meta-number value that is able to instantiate number values?  
A text value is defined by the meta-text value that is able to instantiate text values?

==&gt; The general relation is that a value is an Atom defined by a Meta-Atom?

==&gt; A record value is defined by a meta-record value that defines a composition of value-declarations {name, meta-value}?

A record meta-value provides operations to add/remove member declarations.  
In this way meta-record definitions mutate the member declarations of the record.

==&gt; Thus a meta-record may be defined and once defined meta-record members may be declared

meta-record definition = {name, meta-record-value}  
meta-record member declaration = {record_name.member_name, meta-value}

Note: How this makes meta-record a composite of meta-values (each meta-value being any of the meta-atoms, meta-record or meta-array)!

==&gt; Thus the general relation is that a record value is defined by a meta-record with members being meta-declared and value defined.

==&gt; An array value is defined by a meta-array value

...

==&gt; Record composition of declarations and array composition of definitions suggests we need to separate the two ways of name binding (name repetition required)?

A record requires composition of declarations (each member declaration is explicitly named and requires a separate definition to be instantiated)  
An Array requires composition of definitions (each member definition is implicitly named by its index and is defined on array mutation)

2) It seems we need to find a way to define operations on values depending on the value structures?

==&gt; It seems atomic values may only change state (value).

==&gt; But a Text value is in fact a structured type (allowing for range insert and delete)?

==&gt; It seems a Record value must provide member accessors to allow member value operations?

...

3) It seems in C++ we must use top-down and not bottom-up implementation?

==&gt; Bottom up would mean Value&lt;MetaValue&gt; which does not work as it is the MetaValue that defines the Value it defines?(!)

==&gt; Thus we should try to specialize MetaValue based on Value type?

template &lt;Value&gt; class MetaValue {} // Primary template  
template &lt;&gt; class MetaValue&lt;AtomicValue&gt; { .. Specialization for Atomic values…}  
template &lt;&gt; class MetaValue&lt;RecordValue&gt; { … Specialization for Record Values…}  
template &lt;&gt; class MetaValue&lt;ArrayValue&gt; { … Specialization for Array values …}

==&gt; Now we can define what the specializations must generally do?

meta_value(value_constructor_type v) constructs a Value  
record_meta_value.declare_member(std::string name, value_declaration) declares a record member  
record_value.define_member(std::string name, value_constructor_type v) defines a record member.  
…

==&gt; Or, consider it is the declaration operator() that acts as constructor?

layer.definition&#91;path&#93; = layer.declaration&#91;path&#93;(value_constructor_type v) ?  
==&gt; But this only means the declaration IS the MetaValue?  
…

==&gt; So maybe a Layer is just name bindings where each binding is a pair or a meta value and an optional value?

Declaration then becomes layer.binding&#91;path&#93;.left = meta_value  
Definition then becomes layer.binding&#91;path&#93;.right = meta_value(value);

==&gt; But this is awkward as this would just mean that pair.right is created by pair.left(value) (the meta-value creates the value)

==&gt; So, consider a declaration is able to cache the defined value?

==&gt; But this means that declarations must be mutable which also seems awkward?

==&gt; Consider in fact that paths are always through definitions (actual value instances)?

==&gt; A Declaration is just an optional definition (represented as a name bound to a meta-value)?  
==&gt; Thus the name is a path to a value name that is not yet bound to a value (it only defines the location in the declared structure)?

==&gt; Thus NO - The declared path is into a structure of declarations!  
==&gt; It is the definition that requires the parent to be defined (we can bind a value only to value members)?

==&gt; Or, are constant values allowed to be defined although their parent value is still not (…)

{% endraw %}
