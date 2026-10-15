# Todo: Type Systems - Consider to understand the syntax of the mathematical and computer science fields in play in type theory?

```#3756b5be``` *As of 2017-10-12 19:21*

[mail plain/text](mail.txt)

{% raw %}
It seems we need to be able to read and use the syntax of several mathematical and computer science “languages”?

1) Consider to follow up on this video “Propositions as Types - Computerphile” by professor Thorsten Altenkirch to get leads into (<https://www.youtube.com/watch?v=SknxggwRPzU>)?

==&gt; In “Classical Logic” (Zeroth Order, or Propositional, Logic) we use ⋀ (AND, Conjunction), ⋁ (OR, Disjunction), —&gt; (Implication), ¬ (NOT, negation)

==&gt; In “Predicate Logic” (First Order Logic) we use ∀ (For all, Universal Quantification), ∃ (There Exist, Existential Quantification).

==&gt; He seems to give a nice translation between Propositional syntax and operations on types?

![](<Propositions as Types - Overview.tiff>)

Proposition: P ⋀ Q translates to Type: P x Q (Cartesian Product = pair (P,Q))

Reads: P and Q Rule: x : P y : Q

———————————

(x,y) : P x Q

Reads: Given x of type P and y of type Q, then we can conclude that the pair (x,y) is in (is ot type) P x Q.

Proposition: P ⋁ Q translates to Type: P + Q (Disjunct Union, each member may be a P or a Q)

Reads: P or Q Rules: x : P y : Q

—————— ————————

left(x) : P + Q right(x) : P + Q

Reads: Given x of type P, then there is a function “left" that maps x into (type) P + Q.

…And Given an y of type Q, then there exists a function “right” that maps y into (type) P + Q.

Proposition: P —&gt; Q translates to: ∀ f : P —&gt; Q

Reads: P implies Q Reads: There is a function that maps values in (of type) P to values (of type) Q.

==&gt; It seems that in type theory functions are primitive mathematical objects (they are not exponentials as in category theory for Sets)?

==&gt; Also, I seem to recollect from some talk, that the types that represents propositions are single element sets (the corresponding proposition is true if the type is populated)?

==&gt; Intuitionally this seem to correspond to the fact that we need to keep track of what proposition each proof belong to)?

==&gt; So, even if each proposition may have several proofs, each proof can’t prove several propositions?

...

==&gt; In type theory a proposition that lacks a proof is represented by the empty set (a type with no member, i.e. no proof).

==&gt; But this means we can’t prove that a proof does not exists (we can’t write a function that maps into the empty set).

...

2) Consider this wikipedia page on Propositional Logic stating that it is Zeroth Order Logic (<https://en.wikipedia.org/wiki/Propositional_calculus>)?

> “*Propositional calculus (also called **propositional logic**, statement logic, sentential calculus, sentential logic, or sometimes **zeroth-order logic**)*"

3) Consider the wikipedia page on “First Order Logic” stating that this is “Predicate Logic” (<https://en.wikipedia.org/wiki/First-order_logic>)?

> “***First-order logic**—also known as first-order predicate calculus and **predicate logic**...*"

4) Consider the wikipedia page on Devotional Semantics that also seem to re-use symbols and syntax with same or different semantics (<https://en.wikipedia.org/wiki/Denotational_semantics>)?

> “*In computer science, **denotational semantics** … is an approach of formalizing the meanings of programming languages by constructing **mathematical objects** (called **denotations**) that describe the meanings of expressions from the languages.*"

…

Consider to continue to study the grammar of the languages used in type theory to express types and type operations?

...

{% endraw %}
