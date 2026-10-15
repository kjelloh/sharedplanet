# Todo: Meh and Tha - Consider using "defacto" as a function that creates a constructor that models a (meta-name, name) declaration as a closure of provided names?

```#607fee63``` *As of 2017-10-15 15:38*

[mail plain/text](mail.txt)

{% raw %}
Consider that it could prove a good idea to define the function ”defacto” as the thing that creates a constructor that is a closure of the name and meta-name to instantiate in the the system?

*Note: The discussion below identifies the problem of C++ class/struct types that injects name-dependent members - but gives no conclusion on how to separate this injection from the members provided by the user?*

1) Consider defacto type functions?

==&gt; Consider a C++ variable declaration?

> **int a; **

==&gt; Consider we model this as **defacto(”int”, ”a”)**?

==&gt; Now, we know in C++ the declaration introduces the name ”a” into the type system.

==&gt; We also know that the variable ”a” is NOT initialized.

==&gt; Consider a declared name is in fact a name bound to a initializer, i.e. a constructor?

> meta-2: ”int” = int_meta-1_factory {… defacto(meta-1-name name);}  
> meta-1: ”a” = defacto(”int”,”a”); // i.e. int_meta-1_factory::defacto(”a")

==&gt; Consider once defined, then variable ”a” is rebound to its ”value”?

> int a;  
> **a = 4;**

==&gt; Consider we model this as **defacto(”int”,”a”)(4)**?

==&gt; Then: defacto is a function that returns a closure of the provided meta-name and name?

==&gt; And this closure initiates (defines) the introduced variable name to be bound to a initialized object for that name?

2) Consider the defacto function is actually an update function that returns a new environment?

Environment = update(Environment,meta-name,name); // Declaration introducing ”name” bound to ”meta-name”

==&gt; Thus, a declaration is an update of the immutable environment with a new name bound to an existing meta-name?

Environment = update(Environment, name, initializer-args); // Definition of ”name” by rebinding it to the object created by passing the arguments to its constructor?

==&gt; Thus, a definition is an update of the environment with an existing name re-bound to a constructed value-object?

==&gt; Thus - it is the evaluation of a statement that updates the environment with new names!

==&gt; And we may use the defacto-function to be the thing that creates the value-object of the values defined by the meta-value?

3) SO - Instead consider the compiler is a statement-evaluator that returns an updated envrionment (name space, i.e. type system)?

*Environment = eval(**Environment**, **statement**);*

==&gt; Thus, the compiler in fact evaluates statements an stores the result as an updated Environment?

==&gt; Now consider a declaration is ”simply” a binding of a new name to an existing meta-name?

Environment = eval(Environment, ”int a”);

> Environment Environment  
> meta-2: ”int” = …  meta-2: ”int” = …  
> | *meta*  
> meta-1: **”a” = null**

==&gt; Now consider a definition is a re-binding of a declared name to an object holding its value?

Environment = eval(Environment, ”a = 4”);

> Environment Environment  
> meta-2: ”int” = …  meta-2: ”int” = …  
> | *meta  | meta*  
> meta-1: ”a” = null  meta-1: **”a” = auto int::defacto(4);**

4) Consider to model each defacto function as a C++ function object?

> struct int::defacto {  
> auto operator(); // default initialization of an int value object  
> auto operator(auto value); // returns an int-value object holding provided value  
> }

==&gt; Now, a declared name is bound to a defacto function object while a defined name is bound to the constructed value object!

Environment = eval(Environment, ”int a”);

> Environment Environment  
> meta-2: ”int” = …  meta-2: ”int” = …  
> | *meta*  
> meta-1: **”a” = int::defacto**

==&gt; Now consider a definition is a re-binding of a declared name to an object holding its value?

Environment = eval(Environment, ”a = 4”);

> Environment Environment  
> meta-2: ”int” = …  meta-2: ”int” = …  
> | *meta  | meta*  
> meta-1: ”a” = int::defacto  meta-1: **”a” = auto int::defacto(4);**

...

5) Consider how forward declarations now becomes meta-level value declarations?

> class A;

> class A {int a;}

> meta {

> class A;

> A = class {int a;}

> }

==&gt; Thus, a forward declared struct is in fact a meta-2 (type) level name declaration (that will later be defined)!

==&gt; BUT - This does NOT work (the class constructor need to **know the name** of the constructed class type)!!

==&gt; So, what is the thing that injects the name-dependent members of a class type?

???

==&gt; Consider we get some insight by repeating the value-level semantcis above but shifted to the type-level?

Environment = meta::eval(Environment, ”class a”);

> Environment Environment  
> meta-3: ”class” = …  meta-3: ”class” = …  
> | *meta*  
> meta-2: **”A” = class::defacto**

==&gt; Now consider a definition is a re-binding of a declared name to an object holding its value?

Environment = meta::eval(Environment, ”A = class {int a;}”);

> Environment Environment  
> meta-3: ”class” = …  meta-3: ”class” = …  
> | *meta  | meta*  
> meta-2: ”A” = class::defacto  meta-2: **”A” = auto class::defacto({int a;});**

==&gt; It’s clear that class::defacto **can NOT inject the members that depends on the name ”A”**!

…

6) It seems in C++ we need the defacto function to actually know the name bound to the created value object?

==&gt; Consider this kind-of follows from interpreting the C++ class declaration that takes the name of the class as argument?

> class A {int a;};

==&gt; In ”functional syntax” the semantics is that class is a function of type: class-name -&gt; member-list -&gt; class-type

> C++ syntax:  class A {int a; bool b;}; // type A  
> | |  
> ”Functional” syntax: class: name -&gt; class-member-list -&gt; class-type

…

7) Consider we stick with the original idea but allow the defacto function to be curryed?

==&gt; Then the full defacto-function is of type: meta-name -&gt; name -&gt; value-object-constructor -&gt; value-list -&gt; value-object

==&gt; Now the compiler may evaluate statements and update the Envrionment (type system) using curryed defacto-functions?

int a; // Environment += name ”a” bound to defacto(”int”, ”a”), i.e. function of type: value-object-constructor -&gt; value-list -&gt; value-object

==&gt; Note that for this pattern to be general we need to assume that integers uses a hidden value-object-constructor defined by the int-litteral?

==&gt; Note: The value-object-constructor is there to apply the same pattern to class types (class A {int a; bool b;} means the value-object-constructor is {int a; bool b;})?

a = 4; // Environment += name ”a” rebound to the value-object returned by defacto(”int”, ”a”)(int-value-constructor,4) (Where **int-value-constructor is inferred** from the litteral 4)?

…

…

Consider to try out some models to actually be able to emulate the C++ type system for class and struct kinds that actually injects **name-dependent members**?

{% endraw %}
