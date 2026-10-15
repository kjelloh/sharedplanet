# Todo: Tha - Consider to compare basic meta-value compositions with those defined as basic for programming languages in general?

```#a6ee0a24``` *As of 2017-06-29 12:04*

[mail plain/text](mail.txt)

{% raw %}
Consider what we can learn by studying what composite types computer languages in general are based on?

1) Consider the listing of wikipedia article ”Data type” (<https://en.wikipedia.org/wiki/Data_type>)?

==&gt; It seems there exists a small set of composite types on which all other compositions tend to be based?

> ”*An **array** stores a number of elements of the same type in a specific order. They are accessed randomly using an integer to specify which element is required (although the elements may be of almost any type). Arrays may be fixed-length or expandable.*

> *A **list** is similar to an array, but its contents are strung together by a series of references to the next element.*

> ***Record** (also called tuple or struct) Records are among the simplest data structures. A record is a value that contains other values, typically in fixed number and sequence and typically indexed by names. The elements of records are usually called fields or members.  
> *

> ***Union**. A union type definition will specify which of a number of permitted primitive types may be stored in its instances, e.g. "float or long integer". Contrast with a record, which could be defined to contain a float and an integer; whereas, in a union, there is only one type allowed at a time.  
> *

> *A **tagged union** (also called a variant, variant record, discriminated union, or disjoint union) contains an additional field indicating its current type, for enhanced type safety.  
> *

> *A **set** is an abstract data structure that can store certain values, without any particular order, and no repeated values. Values themselves are not retrieved from sets, rather one tests a value for membership to obtain a boolean "in" or "not in".  
> *

> *An **object** contains a number of data fields, like a record, and also a number of subroutines for accessing or modifying them, called methods.*"

==&gt; Hm… This article is not such a good one, is it?

==&gt; It seems to confuse structure with implementation?

2) Consider how we may provide the general composite types as meta-values in Tha?

==&gt; It seems our Tha compositions based on Identifier and value compositions becomes all-covering?

==&gt; An Array of same meta-value values, i.e. an **array** (e.g. Array&lt;Int&gt;)

==&gt; Member access by index.

==&gt; An Array of Identifiers, i.e. a **record**, struct or map (e.g. Array&lt;Identifier&gt;)

==&gt; Member access by name.

==&gt; An Array of any value, i.e. a **tuple** (e.g. Array&lt;Value&lt;n&gt;&gt;, n being the meta-level)

==&gt; Member access by index.

==&gt; Note: **It seems we need to distinguish between Identifiers and Values** (we cant mix Identifiers and other values in a tuple)?

...

==&gt; A Set of same-level values, i.e. a **set** (members are restricted to a defined array of possible values)

==&gt; Consider a Set based on array becomes a Set of value all with the same meta-value (e.g. a C++ set)?

==&gt; Consider a Set based on record becomes a tagged Set (value is Identifier)

==&gt; Consider a Set based on tuple becomes a Set with values of different meta-values (i.e. value is variant)?

...

==&gt; Consider if the meta-value ”function” is a type composition or an atomic type?

==&gt; It seems to be a composition as we need to provide argument declarations and environment (capture) declarations?

…

==&gt; Consider we also want "Union Types” as Elm (<https://clojuredocs.org/clojure.core/def>) has?

==&gt; Consider in C++ this is std::variant&lt;&gt;?

==&gt; Consider this is a Tha meta-value Set?

…

Consider to elaborate more on computer science composite data types to learn what we need to provide good basic meta-values for Tha to model them?

...

{% endraw %}
