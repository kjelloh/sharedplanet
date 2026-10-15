# Todo: Tha - There seems to be something we miss in modelling C++ in Tha?

```#15cba893``` *As of 2017-08-28 09:31*

[mail plain/text](mail.txt)

{% raw %}
It seems to me that there is something we have not yet pinned down when it comes to meta-value/value relations and name-value bindings?

1) We would like templates to create function kind that takes only types as parameters (not template, type or literal)?

==&gt; It does not seem “clean” that a template definition can take template template parameters, type parameters and literal parameters?

==&gt; It seems to break the meta-value/value dualism (it accepts meta-1 literals, meta-2 types AND meta-3 kinds as parameters)?

==&gt; But - it that actually true or have we not understood the template parameters correctly?

Consider a template definition that takes all three sorts of parameters?

template &lt;&gt;

2) It seems we would like Kind to construct composed types with value constructors as members (not value declarations)?

3) It seems meta-values as Sets constructs enumerations of that Set?

==&gt; Could it be that we can see a variable of a type as an enumeration of the values of that type?

==&gt; An int variable seems to be an enumeration of all int values (and at any time it is set to one of them)?

meta-2: “int” = {…,-2,-1,0,1,2,3,…} // AND value = Set

meta-1: “i” = {… or -2 or -1 or 0 or 1 or 2 or 3 or …} // OR value = variant

==&gt; But it is not a tagged enum, it is a variant

4) It seems a literal is in fact a singleton Set with a nullary constructor?

==&gt; Consider the literal 3 as the Set {int 3}?

meta-2: “3” = {3}

meta-1: “a” = 3{} // value instance of “3"

5) Consider assignment is an imperativ operation (that true functional programming does not have)?

==&gt; It seems there is something to understand in the difference between a bound variable (mutable value) and a bound value (immutable)?

a = 3; // mutate the value bound to “a”

int b = 5; // instantiate a new binding “b” and init its bound mutable value to 5

int const c = 7; // instantiate a new binding “c” and init its immutable value to 7

==&gt; Consider assignment to a variable is implemented as assignment to its bound name?

{% endraw %}
