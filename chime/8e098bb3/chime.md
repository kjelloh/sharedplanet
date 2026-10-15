# Todo: Meta Value Model - Consider to base design on Identifiers and Identifier compositions?

```#8e098bb3``` *As of 2017-06-07 22:31*

[mail plain/text](mail.txt)

{% raw %}
It seems at this stage of thinking that the core item of the Meta Value Model is the Identifier binding a name to a meta-value and storing an optional value?

1) Consider the Identifier contents and its relation to Declaration and definition?

==&gt; Consider the Identifier stores a meta-value reference and a value instance?

MetaValueIdentifier {

Name name;

MetaMetaValueReference meta_meta_value;

MetaValue value;

}

==&gt; Consider to use the term ”Value” to mean the Values of the meta-layer where the Identifier lives?

ValueIdentifier {

Name name;

MetaValueReference meta_value_ref;

Value value;

}

2) Consider a Declaration and Definition is operations relating to an Identifier (not objects themselves)?

==&gt; Consider a Declaration brings an Identifier into existence (by binding a value name to a meta-value reference)

number1 : number

Corresponds to…

**miv&#91;”number”&#93; = new Identifier(”number1”, &miv&#91;”meta/number”&#93;)**

==&gt; Consider a Definition binds an Identifier to a Value instance?

number1 = 4

Corresponds to…

**miv&#91;”number”&#93;-&gt;value = 4;**

3) Now consider each meta-layer built in Identifier compositions?

==&gt; Consider Identifier relations between meta-layers?

^ ...

| | Construction

| Definition v

meta-n+1: Array of Identifier {name, meta-n+2 Value Reference} -----------&gt; meta-n+1 value = Set {defacto layer n values}

^ |

| |

----------------------------------------- |

| Declaration |

| -------------------------

| | Construction

| Definition v

meta-n: Array of Identifier {name, meta-n+1 Value Reference} -----------&gt; meta-n value = Set {defacto layer n-1 values}

^ |

| |

----------------------------------------- |

| Declaration |

| -------------------------

| | Construction

| Definition v

meta-n-1: Array of Identifier {name, meta-n Value Reference} -----------&gt; meta-n-1 value = Set {defacto layer n-2 values}

^ |

| |

... v

==&gt; Consider a model of built-in basic compositions?

==&gt; Consider each meta-n layer comes with implicit meta-n+1 ”array”, ”record” values?

> meta-n+1

> "array" = ArrayMetaValue{}  
> "record" = RecordMetaValue{}

> ArrayMetaValue RecordMetaValue  
> DeFactoArray {...} DeFactoRecord {...}

> ... Value  
> ^  
> ............................................|...............................  
> |  
> ------------------------|------------------------------------------  
> | | | |  
> v | | |  
> meta-n Identifier | | |  
> name | | "myarray" = array &lt;identifier&gt; |  
> meta-value-ref ------------ | "myrecord" = record &lt;identifiers&gt; |  
> value-instance | |  
> | | |  
> | | |  
> v | |  
> Value | |  
> ^ | |  
> | | |  
> -----------------------------------------|------------- |  
> | | | | |  
> | DeFactoArray { | DeFactoRecord { |  
> \* meta-n \* Identifier value-id -- |  
> | Value operator&#91;index&#93; Identifier operator&#91;name&#93;--  
> | vector&lt;Value&gt; vector&lt;Identifier&gt;  
> | } | }  
> | |  
> ........|............................|.....................................  
> | |  
> v v  
> meta-n-1 Value meta-n-1 Value  
> NOTE: We want all compositions to reference same-layer or deFacto layer Identifier.

> In this way we can have each layer define its DeFacto layer (avoiding recursive dependancy through meta-layer)  
> Compare C++ meta-2 layer that defines built in composites &#91;&#93;, struct/class, template

> NOTE: It is the Identifier that refers to meta-layer "Above"

> NOTE: Each layer defines its own Atomic Values.

> Compare C++ meta-1 layer that defines built in types int, char, float...

...

…

Consider to delve deeper into this approach to try and get a first working implementation of a Meta Data Model?

...

{% endraw %}
