# Todo: Meta Value Model - Consider to follow up on Common Lisp Object System (CLOS) and Meta Object Protocols?

```#73924a55``` *As of 2017-06-13 15:28*

[mail plain/text](mail.txt)

{% raw %}
It seems the idea of handling meta-values as ”about values” in computer programming is not a new one and it seems like a good idea to follow up on what has been tried out in this area?

1) Consider to follow up and compare Common Lisp Object System (CLOS) with our Meta Value Model design (<https://en.wikipedia.org/wiki/Common_Lisp_Object_System>)?

> ”*CLOS is a powerful dynamic object system which differs radically from the OOP facilities found in more static languages such as C++ or Java.*"

==&gt; CLOS seem to have the notion of meta-levels but talks about them as class (meta) and superclass (of meta-meta)?

> ”*The basic building blocks of CLOS are classes and their methods, instances of those classes, and generic functions.*"

==&gt; Here ”generic functions” seem to refer to functions chosen through dispatch (<https://en.wikipedia.org/wiki/Generic_function>)?

> > ”*In statically typed languages (such as C++ and Java), the term generic functions refers to a mechanism for compile-time polymorphism (static dispatch)…*"  
> > ”*In ... Common Lisp Object System (CLOS)&#91;1&#93; and Dylan, a generic function is an entity made up of all methods having the same name. Typically a generic function is an instance of a class that inherits both from function and standard-object.*"

==&gt; CLOS seem to provide some of the abstractions we propose for our Meta-Lisp?

==&gt; Compare this with our ”Todo: Meta Value Model - Consider ways to implement function meta-value hierarchy (meta-2...meta-0 declaration, definition operations)?"

> ```
> ; declare the common argument structure prototype
> (defgeneric f (x y))

> ```

  
==&gt; Seems to correspond to meta-1 declaration of identifier ”f” as a generic function taking two parameters named ”x” and ”y"?

==&gt; Consider what we have proposed for our meta-lisp syntax?

meta-0&gt; (declare f (function number number number)) // declares identifier ”f” to be meta-1 identifier ”function” applied to identifiers ”number”

==&gt; Thus, in meta-lisp we declare the argument types of f (but not the names)?

==&gt; But CLOS declares the argument names (but not their types)?

**==&gt; It seems the CLOS way allows for dynamic dispatching on argument types (and we want this also for our meta-lisp)?**

**WE ARE HERE...**

==&gt; In CLOS we can defined functions with different argument types and match calls to correct generic function with that name?

  
> ```
> ; define an implementation for (f integer t), where t matches all types
> (defmethod f ((x integer) y) 1)

> ```

  
==&gt; Seems to define a function with x declared as integer but y still undeclared?

Note: f is defined for ”any argument type y” (possible as y is not used in the function body)?

Q: But, Does this mean that if f body would have used y, then f with y:float would have been instantiated for (f 1 2.0)?

...



> ```
> (f 1 2.0) => 1
> ```

  
==&gt; Seems to bind ”y” to ”float” (type of value ”2.0”) thus dispatching to f: integer -&gt; float -&gt; integer 1

> ```
> ; define an implementation for (f integer real)
> (defmethod f ((x integer) (y real)) 2)

> (f 1 2.0) => 2 ; dispatch changed at runtime
> ```



2) MetaObject and ”Meta Object Protocol” seems to be a ”known” abstraction in programming (<https://en.wikipedia.org/wiki/Metaobject#Metaobject_protocol>)?

==&gt; It seems I should consider to read the book ”The Art of the Metaobject Protocol” (<https://en.wikipedia.org/wiki/The_Art_of_the_Metaobject_Protocol>)?

3) This paper ”Structure of a Programming Language Revolution” seems like good reading on a Meta perspective on ”Mixins” (<http://www.dreamsongs.com/Files/Incommensurability.pdf>)?

==&gt; It seems one may see a ”MixIn” as a mechanism to mutate the dispatch of functions (e.g., as in Mixin-based inheritance of OO languages)?

==&gt; This article shows some interesting examples of CLOS mixin syntax

&gt;(defclass person () ((name :accessor name :initarg :name :initform “”)))

> ”*defines a class named person which has a slot accessed by a method named name. is class has no declared superclasses. But behind the scenes it does, including one that de nes a generic function called print-object*"

&gt;(defmethod print-object ((person person) stream)

(format stream “~A” (name person)))

&gt;

…

Consider to delve deeper into existing Meta Object ”ideas” to see what we can learn and or how it can be used to affect the design of our Meta Value Model?

...

{% endraw %}
