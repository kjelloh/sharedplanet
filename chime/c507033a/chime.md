# Todo: Meta Value Model - Consider to compare our "Meta Lisp Repl" with other language Repl available online?

```#c507033a``` *As of 2017-06-16 01:51*

[mail plain/text](mail.txt)

{% raw %}
It seems it could be a good idea to compare our Meta-Lisp Repl with other language Repls by using some online repl service for that language?

1) Clojure seem to provide a Repl here (<http://www.tryclj.com>)?

> &gt; +  
> #&lt;core$_PLUS_ clojure.core$_PLUS_@36dd768d&gt;  
> &gt; + 1  
> #&lt;core$_PLUS_ clojure.core$_PLUS_@36dd768d&gt;  
> &gt; + 1 1  
> #&lt;core$_PLUS_ clojure.core$_PLUS_@36dd768d&gt;  
> &gt; (+ 1 1)  
> 2  
> &gt;

==&gt; Clojure seem to be able to print also function values?

+ evaluates to ”#&lt;core$_PLUS_ clojure.core$_PLUS_@36dd768d&gt;” (what is the ”#”)?

==&gt; The ’#’ in Clojure seems to mean ”dispatch”and the following character defines what kind of dispatch it is (See ”Dispatch (#)” in <https://clojure.org/reference/reader>)?

...

==&gt; This page seems to provide good and clean examples to show Clojure syntax (<https://kimh.github.io/clojure-by-example/#about>)?

...

2) Elm seem to provide an online repl here (<http://elmrepl.cuberoot.in>)?

==&gt; It seems Elm does not express type restrictions like Haskel does?

> &gt; (==)  
> &lt;function&gt; : a -&gt; a -&gt; Bool  
> &gt;

==&gt; Seems to read: == is a function that takes any-type a and any-type a and returns Bool (no restrictions on a)?

==&gt; Elm == operation seem to handle also composites?

  
> &gt; (1,2) == (1,2)  
> True : Bool  
> &gt;

==&gt; Thus, Elm does not restrict the types to generic == function?

...

3) This seems to provide a Common Lisp repl (<http://learnlispthehardway.org/try-lisp/>)?

> CL-USER&gt; +  
> NIL  
> CL-USER&gt; + 1  
> +  
> CL-USER&gt; (+ 1)  
> 1  
> CL-USER&gt; (+ 1 1)  
> 2  
> CL-USER&gt;

==&gt; It seems Common lisp always aims to print the value?

+ evaluates to NIL (no value)?

+ 1 evaluates to + (+ is binary to + 1 is + bind to its first argument 1)?

+ 1 1 evaluates to 2 (+ applied to 1 and 1)

4) This may be a good enough scheeme Repl (<https://repl.it/languages/scheme>)?

> &gt; +  
> =&gt; #&lt;Function +&gt;  
> &gt; + 1  
> =&gt; 1  
> &gt; + 1 1  
> =&gt; 1  
> &gt; (+ 1 1)  
> =&gt; 2

==&gt; Note: The result is pre-fixed with ”=&gt;”

==&gt; This repl seems to be able to print function values?

+ evaluates to ”#&lt;Function +&gt;” (what is ’#’)?

+ 1 evaluates to ”1” (+ applied to single argument 1 is unary +)?

+ 1 1 evaluates to ”1” (entry is not a list so + dispatch to unary + and consumes single value, second ”1” is orphaned)?

(+ 1 1) evaluates to ”2” (the list evaluates to as_function ”+” binds to unary + which is applied to tail of values)?

==&gt; ’#’ seem to mean ”"(<https://stackoverflow.com/questions/4873810/what-does-mean-in-lisp>)?

(function functionname) can be written #’functionname, i.e. #(quote functionname)

==&gt; The ’ (tick) seem to be shorthand for quote (pass expression un-evaluated)?

5) This seem like a good Haskel tutorial Repl (<https://www.tryhaskell.org>)?

==&gt; Haskel seem to use ”normal” algebra syntax?

> λ 5 + 7  
> 12  
> :: Num a =&gt; a  
> λ

==&gt; ”:: Num a =&gt; a” seem to be the type of the expression (whatever Num a means)

==&gt; It seems ”=&gt;” separates a constraint from the type (i.e. a constraint on the type) (<http://learnyouahaskell.com/types-and-typeclasses>)?

1. ghci&gt; :t (==)
2. (==) :: (Eq a) =&gt; a -&gt; a -&gt; Bool



==&gt; Thus ”==” is a function any-type a -&gt; any-type a -&gt; Bool (But a must be from the Eq class)?

> ”*Everything before the =&gt; symbol is called a class constraint. ... The type of those two values must be a member of the Eq class (this was the class constrain*t)."

==&gt; NOTE: Elm does not seem to have this ability to express type constraints?

==&gt; A string literal seems to default to char array &#91;Char&#93; (called a list)

> λ "chris"  
> "chris"  
> :: &#91;Char&#93;

==&gt; Haskel seem to use Lisp syntax operator arguments?

> λ sort &#91;42,13,22&#93;  
> &#91;13,22,42&#93;  
> :: (Num a, Ord a) =&gt; &#91;a&#93;  
> λ

Note: Haskel is pure functional so the result as a new list!

==&gt; Haskel seems to use ”()” to define tuples?

> λ (28,"chirs")  
> (28,"chirs")  
> :: Num t =&gt; (t, &#91;Char&#93;)  
> λ

==&gt; Seams to read: a tuple (t, list-of-chars) where t is Num (i.e. numeral)?

==&gt; Could it be that the type of a value defines the constructor for values of that type?

> λ (1,"hats",23/35)  
> (1,"hats",0.6571428571428571)  
> :: (Fractional t1, Num t) =&gt; (t, &#91;Char&#93;, t1)  
> λ

==&gt; But ”=&gt;” is not arrow ”-&gt;” (as in function)?

==&gt; Its more like left side declares argument for the right side (t1 is Fractional and t is Num in ”=&gt;” tuple (t, &#91;char&#93;, t1)

==&gt; Q: Why is &#91;char&#93; stated as type and not argument on right side?

==&gt; Q: Or, why is Fractional and Num not stated directly in the tuple)?

==&gt; Haskel seems to have special syntax to bind a name to a value and then use it in an expression?

> λ let x = 4 in x \* x  
> 16  
> :: Num a =&gt; a  
> λ

==&gt; Seems to mean, bind x to expression 4 and then use it in body ”x\*x”

==&gt; The whole expression evaluates to 16.

==&gt; Haskel seems to bind types implicitly?

> λ let villain = (28,"chirs") in fst villain  
> 28  
> :: Num a =&gt; a  
> λ

==&gt; Here villain is bound to a tuple value, then fst is applied to that value.

==&gt; Haskel seems to use ’:’ as binary operator to bind a value to a list?

> λ 'a' : &#91;&#93;  
> "a"  
> :: &#91;Char&#93;  
> λ

==&gt; Seems to be equal to lisp cons?

==&gt; It seems Haskel let is kind of a way to produce a named lambda and pass to another function?

> λ let square x = x \* x in map square &#91;1..10&#93;  
> &#91;1,4,9,16,25,36,49,64,81,100&#93;  
> :: (Enum b, Num b) =&gt; &#91;b&#93;  
> λ

==&gt; Here square is defined as a function named square passed to map on a list (resulting in a new map with elements created by square

==&gt; Haskel seems to support pattern matching (values bound based on same topological position)?

> λ let (a,b) = (10,12) in a \* 2  
> 20  
> :: Num a =&gt; a  
> λ

==&gt; Here a and b are bound to 10 and 12 based on left side having the same pattern as right side?

==&gt; Note: Left side has no types either (values comes with types so it is not required)?

==&gt; Haskel seem to define pattern matching using deconstruction (based on construction pattern)?

> ”*Values are pattern matched, or deconstructed, by writing* however they were constructed.”

==&gt; This would mean - in our meta-lisp we could pattern match by asking for the meta-value of a defined value and a declared value?

==&gt; Then we can bind the members of the declared value using the arguments to the constructor of the defined value?

**Hm… nees some thinking... **

==&gt; This seem to be the Haskel specification (<https://www.haskell.org/definition/haskell2010.pdf>)?

==&gt; Haskel constructors are operators prefixed with ”:”.

==&gt; Haskel seems to separate declaration (::) from definition (=)?

  
> > ```
> > push :: a -> Stack a -> Stack a
> > push x s = MkStack x s

> > ```

  
==&gt; Nice syntax :)

==&gt; Haskel ”-&gt;” seem to mean function (as maps-to)

==&gt; Thus, push is declared to take an ”a” and a ”Stack a” and return a ”Stack a"

6) This may be a good site listing Repls of virtually all languages (<http://joel.franusic.com/Online-REPs-and-REPLs/>)?

…

Consider to document how these services work and update with better resources when appropriate?  
...

{% endraw %}
