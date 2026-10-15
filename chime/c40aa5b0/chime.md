# Todo: Meta Value Model - Consider to implement a value-to-meta-value-contract matching ability as implemented by Clojure.spec?

```#c40aa5b0``` *As of 2017-06-11 20:28*

[mail plain/text](mail.txt)

{% raw %}
Consider it could be a good idea to have the Meta Value Model be able to match a values structure and definition to a contract meta-value (A meta-value composed of pattern-predicate pairs)?

==&gt; Also see (<https://www.w3.org/TR/2014/REC-rdf11-concepts-20140225/>)?

==&gt; Also see (<https://docs.racket-lang.org/guide/contracts.html>)?

1) It seems Clojure.spec values consists of maps and list compositions of Identifiers that bind ”patterns” to predicates?

==&gt; Consider we allow Pattern to be composed as any other value?

==&gt; **NO: Patterns can only be composed of other Patterns**?

==&gt; Compare with Clojure Pattern&lt;2&gt; value ”clojure.spec.alpha”?

==&gt; It seems to add its own ”define” to define predicates in its own namespace?

**(require '&#91;clojure.spec.alpha :as s&#93;)** // bind s to Value&lt;2&gt; clojure.spec.alpha

…requires list of arguments to be defined (Clojure can’t separate declaration from definition?)

**(s/def ::even? (s/and integer? even?))** // apply ”s" member ”define” that binds member ”even?” to predicate

…more member definitions

…finalize with defining s itself

(def s predicate-composition) // define s to the value predicate-composition

==&gt; A predicate composition seems to be

==&gt; It adds sequence composition member pattern operators (regular expression style)

> > ” • **cat** - a concatenation of predicates/patterns

> > • **alt** - a choice of one among a set of predicates/patterns

> > • **\*** - zero or more occurrences of a predicate/pattern

> > • **+** - one or more

> > • **?** - one or none

> > • **&** - takes a regex op and further constrains it with one or more predicates"

==&gt; It also adds composition of predicates for required and optional values in target Value&lt;0&gt;

> > ”A spec for a map is produced by calling **keys** with **:req** and **:opt** keyword arguments mapping to vectors of key names. :req keys support the logical operators **and** and **or**."

==&gt; Thus Consider Patterns to use its own composition abstractions defined in Specification?



> Specification&lt;2&gt;  
> as_function = constructs Specification&lt;1&gt;  
> |  
> ----------------------------  
> | define ”clojure.spec.alpha”  
> v  
> Specification&lt;1&gt;  
> as_function = constructs Specification&lt;0&gt;  
> |  
> ----------------------------  
> | define ”s”  
> |  
> |  
> v  
> Specification&lt;0&gt; = Array&lt;0&gt; of P_Identifier

> --------- ----------  
> | | | |  
> | v v |  
> | P_Identifier = pair {name, P_Member} |  
> | ^ |  
> | | |  
> | -------------| |  
> | | | |  
> | Predicate Pattern |  
> | ^ |  
> | | |  
> | -----------------------| |  
> | | | |  
> ---IdentifierArray MemberArray--|  
> cat \* - zero or more occurrences of a predicate/pattern  
> alt + - one or more  
> ? - one or none  
> & - takes a regex op and further constrains it with one or more predicates

**==&gt; Hm… It is NOT yet correct?**

...

2) Consider matching is in fact a Contract&lt;0&gt; instantiation where Contract&lt;1&gt; takes a Value&lt;0&gt; as argument?

==&gt; The Contract matches if all member predicates instantiates to TRUE?

**==&gt; instantiation just consumes Value&lt;0&gt; as defined by Contract&lt;1&gt;?**

**WE ARE HERE...**

3) Clojure.spec values seems to be both meta (name,meta-value) and value (name, value) maps? (<https://clojure.org/about/spec>)?

==&gt; It seems clojure key is Identifier and spec may be a value of map(keyset) or Set of {key, value} pairs

> ”*Decomplect maps/keys/values*

> *Keep map (keyset) specs separate from attribute (key→value) specs.*"

==&gt; Thus map(keyset) is an Array&lt;1&gt; value of declared Identifer&lt;0&gt; values?

==&gt; And Set of {key, value} is an Array&lt;0&gt; value of defined Identifier&lt;0&gt; values (i.e., a record)

4) Clojure.spec specify members presence requirements?

==&gt; It seems Clojure.spec is more like the Element Table Notation defined for Swedbank specification of protocol data elements?

> ”Sets (maps) are about membership, that’s it

> ...Map checking is two-phase, required key presence then key/value conformance."

==&gt; Consider to have our Meta Value Model provide ”Constructed” and ”Composite” compositions (see ISO_8583-1;2003(E)-Character_PDF_document.pdf ”5.4.1 Data element types”)?

> ”A **primitive** data element is a data element where the content has no further part or sub-elements”  
> ”A **constructed** data element is a data element where the content consists of a fixed number of sub-elements”  
> ”...Each **composite** data element ... contain a variable number of different datasets"

==&gt; Consider we can accomplish this by defining meta-data ”optional” and ”conditional”?

==&gt; Clojure.spec seems to be like a key-presence predicate composition?

> ”The basic idea is that **specs** are nothing more than a logical **composition of predicates**"

==&gt; Clojure spec seem to differentiate between spec map and sequence?

==&gt; (spec/cat sequence-predicate)

==&gt; (spec/cat map-predicate)

==&gt; Clojure seems to use the keywords ”:req” and ”:opt” to define required and optional spec members in map-predicate?

> (spec/keys :req &#91;::x ::y (or ::secret (and ::user ::pwd))&#93; :opt &#91;::z&#93;)

==&gt; Seems to define a map spec (a list of keys)?

Required key names are ”x,y” and ”secret” or ”user,pwd”?

Optional key name is ”z"

==&gt; And it does NOT seem to specify any types (specify only key names)?

==&gt; It seems a Clojure spec Sequence is now just a regular expression to match the spec to provided value composition?

> ”Specs for sequences/vectors use a set of standard **regular expression operators**, with the standard semantics of regular expressions”

> ” • **cat** - a concatenation of predicates/patterns  
> • **alt** - a choice of one among a set of predicates/patterns

> • **\*** - zero or more occurrences of a predicate/pattern  
> • **+** - one or more  
> • **?** - one or none  
> • **&** - takes a regex op and further constrains it with one or more predicates"

==&gt; All operators seem to be predicate patterns?

==&gt; It seems ”require” is used to bind a spec name to a spec type?

> user=&gt; (require '&#91;clojure.spec.alpha :as s&#93;)  
> (s/def ::even? (s/and integer? even?))  
> (s/def ::odd? (s/and integer? odd?))  
> (s/def ::a integer?)  
> (s/def ::b integer?)  
> (s/def ::c integer?)  
> (def s (s/cat :forty-two #{42}  
> :odds (s/+ ::odd?)  
> :m (s/keys :req-un &#91;::a ::b ::c&#93;)  
> :oes (s/\* (s/cat :o ::odd? :e ::even?))  
> :ex (s/alt :odd ::odd? :even ::even?)))

==&gt; It seems identifiers are referenced using full namespace paths (e.g., ”s/keys”) or relative (path ”:") ?

==&gt; It seems sub-member relative path is ”::” (e.g., ”::a”)

==&gt; ”user=&gt;” seems to be the Console prompt?

==&gt; (require '&#91;clojure.spec.alpha :as s&#93;)seems to bind ”clojure.spec.alpha” spec type to s?

==&gt; Thus, ”clojure.spec.alpha” is the meta&lt;2&gt; value for a Clojure.spec?

==&gt; Clojure seem to allow s member definition using ”s/def” (specialization of ”clojure.spec.alpha”)?

==&gt; In effect we seem to be able to add predicates to the s namespace?

==&gt; Actual s is defined using a map {name pattern}

==&gt; (s/def ::a integer?) seems to bind ”s” member ”a” to predicate ”integer?”

==&gt; :m (s/keys :req-un &#91;::a ::b ::c&#93;)seems to bind predicate name ”m” to keys-pattern

==&gt; And keys-pattern defines a ”required” list and ”optional” list

==&gt; Each keys-pattern list seems to be a list of predicates?

==&gt;  It seems ”conform” performs a pattern matching of a spec ot a value?

==&gt; In effect ”conform” takes a meta-value (the spec) and matches it to a defined Value&lt;0&gt;?

...

> user=&gt; (s/conform s &#91;42 11 13 15 {:a 1 :b 2 :c 3} 1 2 3 42 43 44 11&#93;)

==&gt; It seems ”&#91;&#93;” means list (indexed members) and {} means map (named members)?

==&gt;  Thus the spec is applied as a reg-exp and the result is the bound values if all matched predicates return true?

> > &#91;42 11 13 15 {:a 1 :b 2 :c 3} 1 2 3 42 43 44 11&#93;  
> > | ------ | | | | | | | | | |  
> > | ------ | | | | | | | | | :ex (s/alt :odd ::odd? :even ::even?)  
> > | | | | | | | | | | | {:odd 11}  
> > | | | | | | | | | | --------------|  
> > | | | | | | | | | -------| |  
> > | | | | | | | | --------------------|  
> > | | | | | | | -------------| |  
> > | | | | | | -------------------------|  
> > | | | | | -----------------| |  
> > | | | | | | |  
> > | | | | | :oes (s/\* (s/cat :o ::odd? :e ::even?))  
> > | | | | | |  
> > | | | | | -------&#91;{:o 1 :e 2}  
> > | | | | | {:o 3 :e 42}  
> > | | | | | {:o 43 :e 44}&#93;  
> > | | | | -----------------  
> > | | | ------------------ |  
> > | | ------------------- | |  
> > | | | | |  
> > | | :m (s/keys :req-un &#91;::a ::b ::c&#93;)  
> > | | |  
> > | | ------------{:a 1 :b 2 :c 3}  
> > | :odds (s/+ ::odd?)  
> > | |  
> > | &#91;11 13 15&#93;  
> > :forty-two #{42}  
> > |  
> > 42

==&gt; The result is printed to the console as:

> {:forty-two 42,  
> :odds &#91;11 13 15&#93;,  
> :m {:a 1, :b 2, :c 3},  
> :oes &#91;{:o 1, :e 2} {:o 3, :e 42} {:o 43, :e 44}&#93;,  
> :ex {:odd 11}}

…

Consider to delve deeper into this idea of having Meta Value Model ability to match a value to a Specification (or contract) meta-value?

...

{% endraw %}
