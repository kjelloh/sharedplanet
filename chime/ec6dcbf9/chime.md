# Todo: Meh and Tha - Consider there seem to be a strong relationship (isomorphism even?) between SUM composition, SET and the ability to represent transformation of value and structure in the presence of time?

```#ec6dcbf9``` *As of 2019-06-25 12:06*

[mail plain/text](mail.txt)

{% raw %}
If time caused no change then we would not require the ability to describe something being able to be different things (at different times)?

1) Consider a SET and a SUM type are in fact a model of how a value may be "different" at different point in time?

> *Consider the binary value in a memory cell of a computer. If the cell is used to store the result of some computation, then we model this as the value being of a Type that somehow defines the possible values in the cell (and also the possible computations to get this value). But the key thing to notice is that if the memory cell value could NOT change, then we would not need to model it as a Type with many values. We could just state its value. There would never be any change. There would never be any computation. We are already at the state we will for ever stay in.*

> *The same observation can be made for SUM types. Here we take the concept of a SET defining possible values of a value having that type and extend it to values being able to be of two or more types. So with the Type also specifying the computation you can do to arrive at a value we now have a composite Type where values can be computed in different ways depending on what type they have "inside" the computation sub-universe made up by the SUM composition of the types we have composed. But again, this enables us to model the "change of type" in presence of time passing. So a SUM type is "just" a way to model how things may change when time passes. If nothing changes or if to time is required to make the change, then we have no need to model "different types at different time" in the series of computations?*

2) Consider how we can understand what value SET and SUM Types even have in functional programming (as in timeless computation)?

> *Could we say that in functional programming we do not have intermediate time-points, just the start-computation and end-computation time point. So our need for SET and SUM types are just there to model the possible result value and structure, not any intermediate state values? But then I suppose it follows that if the result of the computation can be a value that are also of possible different types, then this will affect also the internal composition of the computation. It must follow that if the result is modelled as being a value of a SUM type, then the computation itself must deal with SUM types?*

> *So even in Functional programming we need "this or that" type, value, function and so on just because this enables us to model a function we may use at actual different point in time with different input values even if the actual computation does not "care" about what point in time each step of the computation takes place. The trait we call "no side effects" is just another way to say that the computation does not interact with anything in space at any point in time during its computation. And so its internal computation does not have to care about things changing with time in the "real world".*

3) Consider what it would mean that in Tha we allow any meta on any level to be a SET and or SUM composition of defacto "things" on its lower defacto levels?

> *So in Tha we expand the idea of SET (Type) and SUM Type (meta 2 i.e., Type) into Kind and SUM Kind (meta 3 i.e., Kind), Sort and SUM Sort (meta 4 i.e., Sort) and so on. And with this we can re-use SET and SUM composition as a "universal".*

> *Now, question becomes, what is then a SUM Kind? Like in having a Kind that is either a "struct" or an "enum"? Is this even practically useful for anything? I mean, for PRODUCT it is easy to see that a Kind that is both a "struct" and a "enum" would mean it can instantiate Types with one member being a defacto-struct (type) and another being a defacto-enum (type). And an instance (defacto) of such a type would have one member being able to hold struct-type-values and the other member being able to hold enum-type-values. But from this reasoning follows that in fact we do know what a SUM Kind is modelling. A defacto SUM-kind of "struct" (kind) and "enum" (kind) is a type that can be either of type defacto-struct or the type defacto-enum and in instance of this type would be able to either hold a value as defined by the defacto-struct (type) or the defacto-enum (type). So the SUM property propagates down the meta-levels.*

> *Can we even understand what a SUM Sort can be used for? Let's try to build some intuition using the C++ Sorts. Now right now I am unsure if C++ has any other Sort than "template", a function that takes Number, Type or Kind arguments and produces a type-constructor (a Sort) or a constant-constructor (a type-defacto). From the C++ refernce we get:*

> *"*A template is a C++ entity that defines one of the following:
- a family of classes ([class template](https://en.cppreference.com/w/cpp/language/class_template)), which may be [nested classes](https://en.cppreference.com/w/cpp/language/member_template)
- a family of functions ([function template](https://en.cppreference.com/w/cpp/language/function_template)), which may be [member functions](https://en.cppreference.com/w/cpp/language/member_template)
- an alias to a family of types ([alias template](https://en.cppreference.com/w/cpp/language/type_alias)) (since C++11)
- a family of variables ([variable template](https://en.cppreference.com/w/cpp/language/variable_template)) (since C++14)
- a concept ([constraints and concepts](https://en.cppreference.com/w/cpp/language/constraints)) (since C++20)*"*

  
> *Now, is there anything else in C++ that is able to create Sorts, as in type constructors? Right now nothing comes to mind. So in C++ we can express SUM Kinds using "template" Sort instantiated Kinds (say one Kind that evaluates to a defacto-struct (type) and one that evaluates to a defacto-enum (type)). But right now I can see no usage in C++ to be able to define SUM-template, as this sum would only be able to say that the SUM-Sort is either "template" or "template" which makes no sense as they are the same Sort. In teh same way it makes no sense to be able to define a PRODUCT-template, a Sort with a member that is "template" and another that is also "template". A template-tuple is just as worthless as no matter what member of the tuplet we use in a computation we get the same Sort, the "template".*

> *Maybe we can imagine to infer a new Sort from the structure and content of the result of a Kind expression? I have to think about that more...*

...

{% endraw %}
