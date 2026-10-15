# Todo: Darwinet - Consider different ways to implement the Darwinet Data Model (The M in the MIV)

```#8a5077e0``` *As of 2017-05-21 16:48*

[mail plain/text](mail.txt)

{% raw %}
Can we finally get an M up and working for the Darwinet MIV implementation by simply trying out different approaches and go with what works?

==&gt; Also see ”Todo: Darwinet - Model and Instance paths + ID:s and Names”

==&gt; Also see ”Todo: Darwinet - Design MIV using type, model paths and instance paths”

==&gt; Also see ”Todo: Darwinet - Consider MIV model to mimic the ontology of the Swift language”

1) Consider my own idea of modelling using Meta-layers could be quite viable?

==&gt; Consider each model layer has a meta layer that is ”about” the objects in the lower layer?

==&gt; Thus: The Meta-layer of Types defines Type Constructors (C++ Templates)?

==&gt; Thus: The Meta-Layer of Values defines Value Constructors, i.e., what we normally call Types?

==&gt; Consider each Meta-layer defines Sets on the layer below?

==&gt; Thus: Types defines Sets of Values (and functions that map between Sets of Values)?

==&gt; Thus: Templates defines Sets of Types (and meta-functions that map between Sets of Types)?

==&gt; Consider to define pattern matching to allow parameters to Meta-layer constructors go be implied from sub-layer declarations?

==&gt; Thus: RECORD template Member Type Parameters are implied by Value Layer Member value types?

==&gt; Thus: The RECORD template is actually defined to take member element types as parameters (e.g. RECORD(NUMBER, NUMBER) is a Record Type with two Number type members)

==&gt; And Value Layer:  (1) myRecordValue : RECORD

(2) myRecordValue.a : NUMBER

==&gt; (1) Binds myRecordValue to a type with Type constructor RECORD?

==&gt; (2) Binds Type Constructor RECORD first parameter to type NUMBER, and Value Constructor RECORD(NUMBER) first parameter to member value a?

==&gt; Consider pattern matching is just a way to bind meta-layer constructors to sub-layer values?

==&gt; Value Layer: myRecordValue : RECORD binds to unnamed type with Type Constructor RECORD.

==&gt; Value Layer: myRecordValue.a : NUMBER binds unnamed type Type Constructor RECORD firs parameter to NUMBER, and unnamed Type first parameter to value a.

==&gt; Consider if we may define some formal language to be able to re-sue abstractions on each meta-layer?

==&gt; Consider each meta-layer defines constructors of objects on the layer below (Type layer constructs values and Template layer constructs types)?

==&gt; Consider each meta-layer defines mappings between objects of the layer below (Type layer defines functions that maps Sets of values, and Template layer defines functions between Sets of Types)?

==&gt; Consider the actual functions are ”Values” on the layer below (A value level function is code for the function type between Sets of Values. And a Type level function is code for the template type between Sets of Types)?

…

==&gt; Consider if there is actually Meta-layers above Template-layer?

==&gt; Consider in C++ the actual syntax to write templates constitutes a Meta-layer that lets us talk ”about” templates?

==&gt; Consider in Darwinet Model what the Meta-layer above template can say about NUMBER, TEXT, RECORD, ARRAY?

==&gt; Consider what a ”Template Constructor” would actually imply?

==&gt; Could we say that the templates NUMBER, TEXT, RECORD and ARRAY ”just exist” (and thus how they are constructed are undefined and of no interest)?

...

2) Consider to try out the tPos Testbench approach for the iPOS Interface abstraction?

a) The Model consists of Definitions that defines Member Elements that are Usage Descriptions.

b) An Element Definition defines an Element Type (its Set of Values)

c) The Data Model is defined by an implicit root element with an Element Definition of a Structured (Record)

d) Usage Descriptors defines meta-data about member elements (The Element Presence Condition and its Type Definition)

==&gt; Consider to refactor this abstraction and use for Darwinet Model Implementation?

==&gt; Consider to rename Definiton to Type (Using the types Number, Text, Record and Array)?

==&gt; Consider a good name for the Meta-data ”Usage Descriptor” (e.g., as UML ”Association”)?

3) Consider to try out an implementation based on the Element Table Notation invented for Data Structures in Swedbank Specifications?

a) An Element is a Value with a Representation.

b) A Leaf Element is one with no sub-elements in the model (A number, a Text, A Flag)

c) A Structured Element models sub-elements

d) A Constructed Element has a fixed set of member Elements (A Record)

e) A Composed Element has Member Elements with presence defined by Conditions

f) An Element Presence may be Mandatory, Conditional or Optional

==&gt; Consider if this abstraction may be used to define Darwinet Data Models?

...

4) Consider to try out implementing some sub-set of the UML abstractions for Data Modeling?

==&gt; The UML 2.5 specification seems to live here (<http://www.omg.org/spec/UML/2.5/>)?

==&gt; The UML Language seems to allow definition of Elements and Relations?

==&gt; There seem to be Template Elements (UML Elements parametrized by other UML Elements)?

==&gt; NOTE: It seems UML does NOT use the abstractions of Metal-ayers (Templates, Types and Values)?

…

5) Consider a brute force approach using just Value, Type pairs in a recursive table as a way to define a Data Model?

a) Consider a root Value of type Record that always exists (No need to create the root Element)

b) Each Element defines a value on the form Name : Type.

c) Consider any entry to be only one level deep?

==&gt; A Record is defined as:  myRecordValue : RECORD

==&gt; Each Record Member is defined as:  myRecordValue.a : NUMBER

myRecordValue.b : RECORD

…

myRecordValue.b.s1 : TEXT

d) Consider only Arrays has Cardinality?

==&gt; An Array Type includes the member cardinality?

==&gt; Consider an Array with zero to nine elements as: myArrayValue : ARRAY(0,10)

…

e) Consider to apply a Model that operates on the meta levels Value, Type, Template?

==&gt; Consider the Meta Level defines Sets on its sub-level?

==&gt; Thus: Meta level Type defines Sets of Values?

==&gt; Thus: Meta Level Template defines Sets of Types?

==&gt; Consider each built in type to be defined by built in Template to construct these Types?

==&gt; Thus: NUMBER is a Type Constructor and NUMBER(0,1024) is an Integer Type and myNumber : NUMBER(0,1024) is a Value in the Set 0…1024

==&gt; Thus: TEXT is a Type Constructor and TEXT(ASCII,0,80) is a String Type of ASCII characters and myText : TEXT(ASCII,0,80) is a String value of 0…80 ASCII characters?

==&gt; Thus: RECORD is a Type Constructor and RECORD(NUMBER(0,10), TEXT(ASCII,0,80)) is a Record type and myRecordValue : RECORD(NUMBER(0,10), TEXT(ASCII,0,80))…?

==&gt; This seems awkward? We like to define the types of the Record Members NOT as template parameters?

…

==&gt; Consider implicit pattern matching to allow Meta-parameters to be implied by sub-level entries?

==&gt; A Record is defined as:  myRecordValue : RECORD

==&gt; Each Record Member is defined as:  myRecordValue.a : NUMBER

==&gt; Thus: myRecordValue.a : NUMBER implies myRecordValue : RECORD(NUMBER)?

…

…

…

Consider to try out the different approaches to implement a Model to see what works and what we can build on for Darwinet Model Implementation?

...

{% endraw %}
