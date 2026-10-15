# Todo: Programming - Consider that "Meaning" as in "Semantics" of a programming language syntax is in fact "Computing" (as in what actual computation does this syntax "mean")?

```#946f7049``` *As of 2019-06-28 14:43*

[mail plain/text](mail.txt)

{% raw %}
1) Consider the youtube video "The Lost Art of Denotational Semantics" (<https://www.youtube.com/watch?v=pQyH0p-XJzE&t=1052s> )?

==&gt; It seems he gives a good example of the intuition that the "meaning" we are talking about is the outcome of a computation (this "means" we get "this result")?

![](<Screenshot 2019-06-28 at 14.21.38.png>)

> *In his example of the developers partner "executing" the syntax "Run to the store and pick up a loaf of bread. If they have eggs, get a dozen". And because of the "semantics" he applied to this instruction he got home with 12 loaves of bread. The grocery store did in fact have eggs. But he interpreted "...then get a dozen" as "meaning" the number of loaves to buy.*

> *So the story gives a good example of how the "semantics" of the instruction refers to what "computation" we expect to happen?*

==&gt; He seems to define "Meaning" as the "Semantic Function" as the type of function that takes a Syntax and turns into "Semantics" (<https://youtu.be/pQyH0p-XJzE?t=651> )?

![](<Screenshot 2019-06-28 at 14.29.25.png>)

> *" and &#91;10:53&#93; that function takes syntax and turns it into semantics. Okay, so that's that's all **denotational semantics** is. So don't be scared, it's really just **a function** that takes abstract syntax and tells you what it means. So really all denotational semantics is is writing an **interpreter for a programming language**. Okay, but you write this interpreter in the language that we all understand or pretend we understand, namely lambda calculus or pure functions. Okay, so that's a goal..."*

==&gt; So from this we can infer that because "Meaning" is "Semantics" that is "how to interpret" and thus "Meaning" is definition of "Computation"?

> *If Denotational Semantics is the mapping between abstract syntax and the computation it "means", and we can use lambda calculus to define such computation, then we actually have all the pieces we need to what computation we expect to happen when we write a piece of computer program using the syntax of that language?*

==&gt; It seems he introduces "continuations" to enable talking about Statements (the computation of a Statement is the computation of a mutating "functions" that return "nothing")?

2) Consider the youtube video "An introduction to denotational semantics" (<https://www.youtube.com/watch?v=yorSVVbhsCY> )?

==&gt; It seems He uses storeO to mean "Read" (A Store Observation) and storeT as "Write" (A Store Transformation)

> So the "meaning" of executing an expression is the computation of a function that takes an expression and returns a store observer. Where execution of the Store Observer "means" the computation that transforms a store into a value.

> And the "meaning" of executing a statement is the computation of function that takes a statement and transforms it into a store transformation. Where execution of the store transformation "means" the computation that transforms a store into a store.

![](<Screenshot 2019-06-28 at 14.05.36.png>)

![](<Screenshot 2019-06-28 at 14.06.16.png>)

![](<Screenshot 2019-06-28 at 14.06.40.png>)

...

{% endraw %}
