# Todo: Programming - Consider refactoring large functions into smaller ones bad based on decomposition being intransitive operations?

```#5e7d9731``` *As of 2016-05-22 15:38*

[mail plain/text](mail.txt)

{% raw %}
Inspired by Jonathan Blow about 9:00 into his talk (<https://www.youtube.com/watch?v=5Nc68IdNKdg&list=UUCuoqzrsHlwv1YyPKLuMDUQ>) I started top think under what circumstances it would be a bad idea to not refactor a large function into smaller ones?

1) Could we argue that relations between a large function A and its internal code is not transitive (not perserved if internal code is refactored into functions)?

==&gt; Consider how a piece of sequential imperative code a,b,c in a function relates (R) to the rest of the code in the function f.

==&gt; f R a (f has relation R to a) may not mean f R fa (fa being a function that does the same as a)?

==&gt; Can we argue that how the large function relates to this member piece is not the same as how the function relates to a refactored smaller function?

==&gt; Can we argue that how each piece of code in the larger function relates to each other is not the same as how refactored smaller functions relates to each other?

2) Could we argue that by refactoring a piece of code into a function we may be forced to create an “unnatural” function (one we should not have invented otherwise)?

==&gt; Consider it is not always true that a piece of code can be given a simple “purpose” in the form a function?

==&gt; Consider code that has many side-effects is hard to make into a function (and should not benefit from being refactored into one)?

…

3) Consider to elaborate on Jonathan Blows argument that making internal code into functions we expose them to other code (breaks encapsulation)?

==&gt; At about 10:00 into the talk above he states this argument.

==&gt; It seems he has a point as the exposed functions also makes the whole code base more complex (more parts)?

==&gt; And in C++ there is no way to state that a particular functions may only be called from just one super-function (the super function aggregates it)?

==&gt; Consider to propose a language feature where one can declare a function aggregate private sub-functions?

==&gt; Jonathan Blows calls this “Local scope functions” at about 18:15 into his talk.

==&gt; Consider to propose the use of C++ local scopes as an alternative to function call decomposition (Jonathan Blow at 18:00 into the talk above)?

==&gt; Consider that using a good IDE one will then be able to fold such code away and still be able to read a long function (readability accomplished without extra-function call-and-exposure issues)?

==&gt; Q: Is it not so that in refactoring techniques this is a proposed first step to identify code that may be made into functions?

==&gt; Consider to follow up if this is the case?

[mollyrocket.com/casey/stream_0019](http://mollyrocket.com/casey/stream_0019).html

3) Could we argue that function calls introduce call-overhead (stack administration and return value marshalling)?

4) Consider inline functions (or compile time generated code) to at least reduce the call-overhead problem?

…

Consider to elaborate more on this idea why decomposition into small-and-short pieces of imperative-sequences into named functions may not be a generally good idea?

...

{% endraw %}
