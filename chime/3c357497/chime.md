# Todo: Meta Value Model - Consider to use the Visitor pattern to implement model double-dispatching for model instantiations (value-as-function value-as-argument) and scripting (head-as-function tail-as-script)?

```#3c357497``` *As of 2017-06-09 12:19*

[mail plain/text](mail.txt)

{% raw %}
It seems we have several occasions of the double-dispatch problem that we may solve by applying the visitor design pattern?

1) Consider wikipedia visitor design pattern page (<https://en.wikipedia.org/wiki/Visitor_pattern>)

![](<Visitor design pattern (in UML).tiff>)

==&gt; The visitor design pattern seems to enable double-dispatch in languages with only single-dispatch abilities?

==&gt; And C++ is a single-dispatch language (through inheritance).

==&gt; A ”Client” seems to be able to decorate a Composite (part/whole) ”Object Structure”

first (1) level dispatcher second (2) level dispatcher

|  |

virtual Element::accept( Visitor& visitor ) = 0; // pure = force dispatch to Concrete Element

|

| (1) first run-time dispatch to Concrete Elements 1…N

v

virtual ConcreteElement_n::accept(Visitor& visitor) {

visitor.accept(\*this);

}

virtual Visitor::accept(ConcreteElement_n& element_n) = 0; // pure = force dispatch to Concrete Visitor

|

| (2) second run-time dispatch to Concrete Visitors 1…M

v

virtual ConcreteVisitor_m::accept(ConcreteElement_n& element_n) {

// implement {ConcreteElement_n, ConcreteVisitor_m} operation

}

==&gt; It seems we may view this as a matrix of operations for double-dispatch pairs {Element_n, Visitor_m}?

Element\\Visitor Visitor_1 Visitor_2 … Visitor_M

Element_1 **op_11 op_12 … op_1M**

Element_2 **op_21 op_22 … op_2M**

…

Element_N **op_N1 op_N2 … op_NM**

2) Consider a visitor pattern to decorate meta-values with ”as function” and ”as value” operations?

==&gt; It seems we may view our goal as double-dispatch pairs of {Value_x, Operation_y} pairs?

==&gt; It seems we have such a matrix for **each meta-n layer**?

meta-2 layer

Value\\Operation as_function as_value

Array&lt;2&gt; **new_Array&lt;1&gt; Array&lt;2&gt;**

Record&lt;2&gt; **new_Record&lt;1&gt; Record&lt;2&gt;**

meta-1 layer

Value\\Operation as_function as_value

Atomic&lt;0,1&gt; **new_Atomic&lt;0,0&gt; Atomic&lt;0,1&gt; // Layer 0 Atomics Meta**

Array&lt;1&gt; **new_Array&lt;0&gt; Array&lt;1&gt;**

Record&lt;1&gt; **new_Record&lt;0&gt; Record&lt;1&gt;**

meta-0 layer

Value\\Operation as_function as_value

Atomic&lt;0,0&gt; **?? Atomic&lt;0,0&gt;**

Array&lt;0&gt; **?? Array&lt;0&gt;**

Record&lt;0&gt; **?? Record&lt;0&gt;**

==&gt; Consider how we may express this not be able to nest layers?

-----------------------------------------------------------------------

meta-4 layer

Value\\Operation as_function as_value

Atomic&lt;4,1&gt; **new_Atomic&lt;4,0&gt; Atomic&lt;4,1&gt; // Layer 4 Atomic**

Array&lt;2&gt; **new_Array&lt;1&gt; Array&lt;2&gt;**

Record&lt;2&gt; **new_Record&lt;1&gt; Record&lt;2&gt;**

-----------------------------------------------------------------------

meta-3 layer

Value\\Operation as_function as_value

-----------------------------------------------------------------------

from meta-4 layer

Value\\Operation as_function as_value

Atomic&lt;4,0&gt; **?? Atomic&lt;4,0&gt; // Layer 4 Atomic**

Array&lt;1&gt; **new_Array&lt;0&gt; Array&lt;1&gt;**

Record&lt;1&gt; **new_Record&lt;0&gt; Record&lt;1&gt;**

-----------------------------------------------------------------------

Atomic&lt;3,1&gt; **new_Atomic&lt;3,0&gt; Atomic&lt;3,1&gt; // Layer 3 Atomic**

Array&lt;2&gt; **new_Array&lt;1&gt; Array&lt;2&gt;**

Record&lt;2&gt; **new_Record&lt;1&gt; Record&lt;2&gt;**

-----------------------------------------------------------------------

-----------------------------------------------------------------------

meta-2 layer

Value\\Operation as_function as_value

-----------------------------------------------------------------------

from meta-4 layer

Value\\Operation as_function as_value

Array&lt;0&gt; ?? **Array&lt;0&gt;**

Record&lt;0&gt; ?? **Record&lt;0&gt;**

-----------------------------------------------------------------------

-----------------------------------------------------------------------

// from meta-3

Value\\Operation as_function as_value

Array&lt;1&gt; **new_Array&lt;0&gt; Array&lt;1&gt;**

Record&lt;1&gt; **new_Record&lt;0&gt; Record&lt;1&gt;**

-----------------------------------------------------------------------

Atomic&lt;2,1&gt; **new_Atomic&lt;2,0&gt; Atomic&lt;2,1&gt; // Layer 2 Atomic**

Array&lt;2&gt; **new_Array&lt;1&gt; Array&lt;2&gt;**

Record&lt;2&gt; **new_Record&lt;1&gt; Record&lt;2&gt;**

-----------------------------------------------------------------------

meta-1 layer

Value\\Operation as_function as_value

-----------------------------------------------------------------------

// from meta-3

Value\\Operation as_function as_value

Array&lt;0&gt; **?? Array&lt;0&gt;**

Record&lt;0&gt; **?? Record&lt;0&gt;**

-----------------------------------------------------------------------

-----------------------------------------------------------------------

// from meta-2

Atomic&lt;2,0&gt; **?? Atomic&lt;1,0&gt;**

-----------------------------------------------------------------------

Atomic&lt;1,1&gt; **new_Atomic&lt;1,0&gt; Atomic&lt;1,1&gt; // Layer 1 Atomic**

Array&lt;1&gt; **new_Array&lt;0&gt; Array&lt;1&gt;**

Record&lt;1&gt; **new_Record&lt;0&gt; Record&lt;1&gt;**

-----------------------------------------------------------------------

meta-0 layer

Value\\Operation as_function as_value

Atomic&lt;1,0&gt; **?? Atomic&lt;1,0&gt;**

Array&lt;0&gt; **?? Array&lt;0&gt;**

Record&lt;0&gt; **?? Record&lt;0&gt;**

3) Consider a visitor pattern to enable a scripting engine to operate on the model?

==&gt; Consider the scripting engine must parse the script into declare/define operations?

(: count number)  // declares name count as meta-value number

(= count 4) // defines name to value 4

==&gt; Consider Lisp-style where a list always evaluates to first-element as-function applied to the list-tail as-values)?

==&gt; A list value = list-head applied to list-tail?

==&gt; An identifier value = its bound value?

==&gt; Consider what this means to implement scripting of declarations and definitions?

Declaration:  (: name meta-value)

Definition: (= name value)

==&gt; Would indicate we need to have scripting engine implement ’:’ and ’\*’ functions?

==&gt; Now, we have proposed a meta-value is a function that creates values?

==&gt; Thus Declaration = meta-value applied to initializer value list?

meta_value.apply(initializer-value-list)

==&gt; And we already defined the lisp scripting language to be only nested list-values and identifier values?

evaluate script := evaluate(list) | evaluate(identifier)

evaluate(list) := apply(list.head, list.tail)

evaluate(identifier) := identifier.as_value

apply(head,tail) := head.as_function(tail)

==&gt; Consider ”declaration” to be a meta-value with as_function to create an Identifier?

==&gt; I.e., declare defines the Set {Identifiers}?

(declaration count number) would translate to apply(declaration.as_function,{”count”, ”number”} instantiating a Declaration{”count”, ”number”}

==&gt; But then, how to we define the layer to hold that value?

==&gt; We would need the layer to be a list of identifiers?

==&gt; And we would need to define an append method (lisp built-in function)?

**WE ARE HERE...**

…

Consider to elaborate and try-out using the Visitor Design Pattern to decorate the Meta Value Model with declare/design operations and scripting operations?

...

{% endraw %}
