# Todo: Meta Value Model - Consider in Meh we define meta-1 name "a" as a generic (any) type to be inferred from (Haskel and Elm style)?

```#9e687519``` *As of 2017-06-16 01:51*

[mail plain/text](mail.txt)

{% raw %}
Consider it would be a good idea to have a way to denote ”any type” the same way as the term ’a’ is used in Haskel and Elm?

1) Consider to understand how ’a’ (any or not yet defined) type is used and applied in the Haskel and Elm languages?

==&gt; It seems to denote generic type in Haskel (See ”Type variables” in <http://learnyouahaskell.com/types-and-typeclasses>)?

1. ghci&gt; :t head
2. head :: &#91;a&#93; -&gt; a



==&gt; Seems to read the type of (:t) identifier head is a function from a list of any-type (’a’) to any-type?

==&gt; Q: Does this also read that a is the-same type on both sides?

==&gt; YES: To denote different any-type we can use &#91;a&#93; -&gt; b (any lower case character denotes a ”type variable”)

==&gt; In Haskel it is called a ”type variable” and any lower case identifier will do?

> ”*Because it's not in capital case it's actually a type variable*"

==&gt; This seems to show that different lower-case characters can be used to denote different any-type types?

1. ghci&gt; :t fst
2. fst :: (a, b) -&gt; a



==&gt; Seems to read: type of (:t) fst is a function that takes a tuple of two any-types and return something of the first tuple member type.

==&gt; Q: It does not necessarily say it returns the first value in the tuple (only that it returns a value of the same type as the first member)?

...

==&gt; In Elm the ’a’ seems to mean the same thing (<https://guide.elm-lang.org/types/reading_types.html>)?



> ```
> > []
> [] : List a
> ```

  
==&gt; This seem to read: the empty list is of type List a (meaning a List of values with any-type ’a’)?

==&gt; And Elm seem to use Haskel notion of using lower case names as type variables any-type ()?

> &gt; (,)  
> &lt;function&gt; : a -&gt; b -&gt; ( a, b )  
> &gt;

==&gt; Seems to read: A function that takes any-type a and any-type b and returns a list (a , b)?

2) Consider how we can provide an any-tipe meta-1 value named ’a’ in our Meta Value Model?

==&gt; Consider we can provide the same functionality in Meh with the meta-1 value ’a’ declared as meta-2 value AnyDeFacto?

==&gt; Consider if it is possible to provide a type constructor (meta-2 value) that is capable of constructing any meta-1 value?

==&gt; Or, maybe thats is **NOT** the way to go (hard to define such meta-2 value given that meta-2 values may change over time)?

==&gt; Instead, consider to have meta-1 identifier that is unbound (no meta-value declared nor value defined)?

==&gt; Then we can use ’a’ to infer types using pattern matching?

==&gt; Then we can define generic function fst as in Haskel?

1. ghci&gt; :t fst
2. fst :: (a, b) -&gt; a



==&gt; In Meh we could implement the fst function as a generic ”return first in tuple” function?

Meh´&gt; (identifier fst (function (list a b) (quote (b)))

fst : (function a b (b)) // Hm… is this good syntax (it is not lisp syntax)?

==&gt; We can now instantiate fst by applying it to any list

Meh´&gt; (fst (list 1 2 3 4 5))

1

Meh´&gt;

==&gt; Meh will infer the types for and by from the meta-value of the provided list?

==&gt; Pattern matching will yield that a is 1 and can execute the body and return it?

**NO! Now we have defined a and b as meta-0 generic values (not types)!**

==&gt; And, to be able to use a,b,c… as generic types we would have to fill meta-1 space with them in advance?

==&gt; Hm… We need to give this more though?

...

Consider to elaborate on this idea to have Meh denote any-type with lower case names a,b,c…?

...

{% endraw %}
