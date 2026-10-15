# Todo: C++ Tha - Consider how making Text and Number meta-agnostic (they exist on any level) makes dependent types (and any dependent meta) to "dissappear"?

```#19db81c8``` *As of 2019-06-25 11:01*

[mail plain/text](mail.txt)

{% raw %}
I still don't like the concept of dependent types and I have a hunch they actually do not have to exist if we just model our type system in a different way?

1) Consider what it would mean to have Text and Number to exist in Tha in a meta-agnostic manner?

> *In Tha we are trying to leverage the observation that its seems we can break down any model into levels of meta-defacto relationships where any "defacto thing" is created and defined by a "meta thing". So that our well known "variable has type" relationship is just a special case of this "defacto is of meta" relation?*

> *Now, we cant start with nothing. SO my intuition is that we start with Numbers and with Text as this is the basis of our own language to represent any model of reality we may come up with. So from the fact that any computer language we come up with, any language of any sort in fact, starts with the existence of Numbers and Text. Where Text is the general way of representing things we can talk and think about in written form. So Numbers can themselves we written down as Text. And in computer science we have leveraged the observation that any text can be encoded using just numbers if we just device a model of how to do this.*

> *Now if we accept that Numbers and Text just "exist" and is the very basic building blocks of our language to express a model of a "type system", then Number and Text are NOT Types, they are the things we use to make Types and all other stuff from. So in that sense, Numbers and Texts are meta-agnostic in Tha. Number and Text "values" can be instantiated and used in expression on any meta level. So, we can use Text as names and to write expressions. And we can use Text to write Numbers and use in expressions that evaluates to anything in our model?*

> *The conclusion is, in Tha we shall treat Text and Number as universals. They exist on all meta-levels and are thus meta-level-agnostic!*

2) Consider dependent types are in fact "just" meta-bridging dependancy as in using defacto INT to construct a sized specified tuple?

> *So far I have seen no other dependent types than those defined as length specified tuples (written using Martin Löf PI function notation) and value type pairs (written using Martin Löf Sigma function notation). But if we observe that in both cases we are using a "value" defined by a Number type combined with an actual Type in an expression that produces a type that uses the value to define the type. And further, so far the only value I have seen used in any practical meaning are a value from the natural numbers or a value from the Boolean type. So we can create a dependent tuple type by taking say the natural number 4 and create a 4 element length tuple of types. I can go even further and state that it seems the tuples we create this way hs always been tuples of the same type as in an array or vector of the same type? Anyhow, we can also create dependent pair types where the first element is a Boolean value true or false and the second element is some type. And in this way we can represent conditional pairs so that if the first element is true the second element is type A otherwise the second element is type B.*

> *I can't escape the intuition that if we "accept" that Numbers just exist, NOT as a type like any other type on the Tha "type" meta-level, but on any meta-level as part of our universe to count any kind of way to divide "things" into "separate things", then we do not need to treat "dependent types" as anything special. And so far I see no reason to fear we will loose anything from getting rod of them? In practice, as humans, we use Numbers and Text as a "technology" to model any level of reality into separate things. With numbers we have the tool label different things in the "same way" to be able to "count" them, or as we also say, enumerate them. But we can also refer ti things not as having a number, but having a name. We use Text to represent these names in written form and with Text we can, let's say, be more personal and add more flavour and context to the things we are talking about. Not the least, with Text we can differentiate between "things" and "things of things". With Text we can write expressions that compute with numbers.*

> *So, from this observation we should be able to draw the conclusion that any "type system" we design should treat Text and Numbers as a universal, not as just a Type. In fact, we see this universal existence of Text and Number in how we accept the existence of "literals". A Literal is "just" a piece of Text that evaluates to either a Text (as say a name or label) or to a number (as in an index or a count argument). So, the just exist in our universe where the Type System is created just as the real universe exists having matter from which itself and we create life and tools.*

> *Anyhow, I want to get rid of Dependent Types and replace them with Type Constructors that are allowed to take Numbers or Text as arguments and compute them into Types. Let's see what happens if we do that, shall we?*

3) Consider we can still define Types that represent Texts and Numbers to allow our Type System to define computation on Text and Numbers in different and specialised ways?

> *To write programs that compute with Text and Numbers we must still define "things" that defines more specific "types" of Texts and Numbers. But as the universal Text and Number exists as defined by our rules for Literals we can easily do this by specialising them into say English.character-text and Integer numbers of 32 binary digits. We can have signed and unsigned Numbers, we can have representation of real numbers, complex numbers, fractions and so on. And in this way we get a clear understanding of the isomorphism between Text representation and Number representation of in fact any "value"! Which now gives us a new understanding of why our computer programs over and over have the need to convert values into text for logging and human interaction. It is because as humans we use Text as the universal representation to communicate anything! So that is why our computer programs need to be able to do the same, that is be able to communicate anything it knows or does into a Text representation.*

...

{% endraw %}
