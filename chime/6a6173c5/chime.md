# Todo: Tha functions - Consider to define the Tha model of functions in terms of closures?

```#6a6173c5``` *As of 2017-08-09 13:46*

[mail plain/text](mail.txt)

{% raw %}
It seems the term “closure” is what we are looking for to define how Tha should model functions?

-1) It seems closures are in fact function calls with bound arguments?

==&gt; Also see “Todo: Tha function types - Consider we can actually extend normal value-functions to also allow type-functions and kind-functions?”

**==&gt; Thus, a closure is modelled as binding of arguments in functions!**

...

==&gt; Seems currying thus is a sequence of binding each argument into a closure until the whole function call is “closed” and can be evaluated with the bound arguments?

...

1) Consider this wikipedia page on Closures (<https://en.wikipedia.org/wiki/Closure_(computer_programming)> )?

==&gt; It seems a closure is a record aggregating an environment with a function (binding function body free variables to the environment)?

> “ *Operationally, a closure is a record storing a **function** together with an **environment: **a **mapping** associating each **free variable** of the function (variables that are used locally, but defined in an enclosing scope) with the **value** or reference to which the name was bound **when the closure was created**.&#91;b&#93; A closure—unlike a plain function—allows the function to access those captured variables through the closure's copies of their values or references, even when the function is invoked outside their scope.*"

==&gt; Consider we shall stick with the term “value” both for data and code (as in functions)?

> “...both a and b are closures—or rather, variables with a **closure as value**—in both cases produced by returning a nested function with a free variable from an enclosing function, so that the free variable binds to the parameter x of the enclosing function."  
> “Note especially that the nested function definitions are not themselves closures: they have a free variable, which is not yet bound. Only once the enclosing function is evaluated with a value for the parameter is the free variable of the nested function bound, creating a closure, which is then returned from the enclosing function."

==&gt; It seems we can model this in C++?

==&gt; Consider to get some insight into Tha model using a C++ model of closures?

==&gt; See “/Users/kjell-olovhogdahl/BitTorrent Sync/XCode/MyClosureModelPlayground/MyClosureModelPlayground”

> template &lt;typename... FArgs&gt;  
> struct **environment** {  
> std::tuple&lt;FArgs...&gt; members;  
> environment(FArgs... args) : members{args...} {}  
> };

> template &lt;typename... FArgs&gt;  
> struct **closure** {  
> environment&lt;FArgs...&gt; e;  
> closure(FArgs... args) : e{args...} {}  
> };

> struct **my_closure** : public closure&lt;int&gt; {  
> my_closure(int k) : closure{k} {}  
> int operator()(int x) {  
> return (x\*x)+std::get&lt;0&gt;(e.members); // models f x = x\*x + k  
> }  
> };

> int main(int argc, const char \* argv&#91;&#93;) {  
> my_closure mc{2};  
> std::cout &lt;&lt; '\\n' &lt;&lt; "my_closure(4) = {4\*4 + 2} " &lt;&lt; **mc(****4****)**;  
> std::cout &lt;&lt; std::endl;  
> return 0;  
> }

==&gt; In this way the closure constructor captures free variables (stored in a std::tuple)

==&gt; And the user closure may be defined to capture free variables at construction and the use these in the lambda (operator() definition)?

==&gt; But - It seems a bit awkward to access the bound environment using indexed storage (the tuple members have no names)?

==&gt; And - there is no way in C++ to create a map of names to tuple members at compile time?

==&gt; Hm… we could use compile time generated she values of names and then look them up using run-time hash values of the same names?

==&gt; But the - van we be sure the same hash function is used compile time and run-time?

2) Consider this wikipedia page on lambda calculus (<https://en.wikipedia.org/wiki/Lambda_calculus>)

==&gt; It seems lambda calculus is about lambda terms and how to reduce them into (values?)

> Lambda calculus consists of constructing **lambda terms** and performing reduction operations on them. In the simplest form of lambda calculus, **terms are built** using only the following rules:  
> SyntaxNameDescriptionaVariableA character or string representing a parameter or mathematical/logical value(λx.M)AbstractionFunction definition (M is a lambda term). The variable x becomes bound in the expression.(M N)ApplicationApplying a function to an argument. M and N are lambda terms.

==&gt; It seems there are two ways to reduce lambda terms?

  
> The reduction operations include:  
> OperationNameDescription(λx.M&#91;x&#93;) → (λy.M&#91;y&#93;)α-conversionRenaming the bound (formal) variables in the expression. Used to avoid [name collisions](https://en.wikipedia.org/wiki/Name_collision).((λx.M) E) → (M&#91;x:=E&#93;)β-reductionSubstituting the bound variable by the argument expression in the body of the abstraction

==&gt; alpha conversions seems to be about renaming variables in abstractions (variable “x” in an abstraction can be converted into equivalent abstraction using variable “y”)?

==&gt; Beta conversions seems to be about replacing a variable bound in an expression with the body of the bound expression (e.g., f(x) : x\*x in f(x)\*2 becomes (x\*x)\*2)?

…

==&gt; It seems the syntax M&#91;…&#93; is used to apply operations to members of M (e.g. M&#91;x&#93; refers to x-bindings in M and M&#91;x:=E&#93; refers to replacement of all x with E within M)?

==&gt; It seems in C++ we are in fact talking about simply typed lambda calculus (<https://en.wikipedia.org/wiki/Simply_typed_lambda_calculus>)?

> “*The simply typed lambda calculus , a form of type theory, is a typed interpretation of the lambda calculus with only one type constructor: -&gt; that builds function types.*"

3) Consider how C++ lambdas map very well to Closures?

==&gt; Consider the syntax of a C++ lambda?

&#91;…1…&#93;(…2…) {…3…}

==&gt; 1 captures (binds) all free variables (those defined in enclosing scope os closure instantiation)

==&gt; 2 declares the function arguments (this that will be bound at calls to the closure)

==&gt; 2 defines the function body (variables are bound to captures free variables AND declared arguments)

==&gt; But NO - The lambda still has free arguments - so it is not a closure?

==&gt; But we can define a new lambda that binds the arguments of another one and thus get a lambda that is a closure?

...

…

Consider to delve deeper into closures and how we want to model functions and closures in Tha?

...

{% endraw %}
