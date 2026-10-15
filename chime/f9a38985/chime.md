# Todo: Tha - Consider that the fold operations of a structured type is a catamorphism of its constructors (fold deconstructs the structure that the constructor constructs)?

```#f9a38985``` *As of 2017-08-09 13:37*

[mail plain/text](mail.txt)

{% raw %}
It seems to me, from a talk on generalised fold (See below), that fold operations is a kind-of “reversal” of the construction of structured type values?

1) Consider this talk “Gabriel Claramunt: All About a Fold - λC 2016” (<https://www.youtube.com/watch?v=AAGBfOa2fnY>)?

==&gt; At 7:33 he seems to generalise fold over list types (<https://youtu.be/AAGBfOa2fnY?t=453>)?

![](<Some generalised fold over list types.tiff>)

==&gt; So, for lists we fold (collapse the list structure) by applying the “folding operation” to each element and the apply the “collapse structure” operation on the result and fold on the rest of the list?

sum fold : sum(head:tail) = head + sum(tail)

tostring fold  : tostring(head:tail) = tostring(head) + tostring(tail)

all f fold : f(head:tail) = f(head) + all(f,tail)

==&gt; At 12:53 he expands the fold to other data structures (generalise from list to trees) (<https://youtu.be/AAGBfOa2fnY?t=773>)?

==&gt; Side Note: the ?t=xxx in the youtube URL seems to be the time in seconds into the clip (12:53 = 60\*12 + 53 = 773 seconds) :)

==&gt; At 16:03 he seems to generalise the fold over trees (<https://youtu.be/AAGBfOa2fnY?t=963>)?

==&gt; It seems he defines fold to take one “structure deconstructor” function “f”, and one “value fold operator” g?

![](<Generalised fold over tree structures.tiff>)

==&gt; It seems in the definition of BTree that ‘a’ is a tree node type and the BTree is either a branch of two tree nodes OR a leaf node?

==&gt; It seems “Branch” and “Leaf” are **constructors** used by BTree constructor?

==&gt; It seems in rec_tree fold definition, ‘b’ is the branch type (composite) and ‘a’ is the value type (leaf)?

==&gt; A bit confusing but semanticly correct?

==&gt; Then (b -&gt; b -&gt; b) is a **branch deconstructor** operator (makes two branches into one branch)?

==&gt; And (a -&gt; b) is a leaf **value deconstructor** (takes a value and returns a branch)?

==&gt; And the fold operation rec_tree is a **tree deconstructor** (takes any tree and returns a branch (with a single value)?

==&gt; Hm… why does rec_tree return a branch ‘b’ and not a value ‘a’?

==&gt; Is it because it is recursive (and the only way to recurse the tree is to return a type that can represent any deconstructed tree)?

==&gt; Yes, thats it: rec_tree **dispatches** to rec_tree(f,g,leaf) or rec_tree(f,g,branch)

==&gt; And Yes, it seems the fold matches the constructor signature (but as deconstruct instead of construct)?

Constructor: (Branch | Leaf) -&gt; Tree // A Tree is a branch or a Leaf

Constructor: Tree -&gt; Tree -&gt; Branch // A Branch is two trees

Constructor: Value -&gt; Leaf // A Leaf carries a value

Destructor: (Branch_D | Leaf_D) -&gt; Tree_D // A Tree Destructor is a Branch destructor OR a Leaf Destructor

Destructor: Tree_D -&gt; Tree_D -&gt; Branch_D // A Branch Destructor is two Tree Destructors

Destructor: Value_D -&gt; Leaf_D // A Leaf destructor carries a destructed Value

==&gt; Thus - A fold takes a Branch Destructor Branch_D (In the talk called ‘f’) and a Leaf Destructor Leaf_D (in the talk called ‘g’).

==&gt; The result is a closure that Destructs trees (Tree_D = rec_tree f g)

==&gt; At 17:02 he seems to see a strong relation between List **construct** with List **fold**?

![](<List construct and list fold strongly related.tiff>)

Construct &#91;1,2,3&#93; = Cons 1 (Cons 2 (Cons 3 (Nil)))

| | | | | | |

Fold f g &#91;1 2 3&#93; = f 1 ( f 2 ( f 3 z))

==&gt; At 18:18 he seems to see a strong relation between Tree **construct** and Tree **fold**?

![](<Tree construct and Tree fold strongly related.tiff>)

> > Construct

> > b  
> > / \\  
> > b a  
> > / \\ |  
> > a a 3  
> > | |  
> > 1 2 = Branch (Branch (Leaf 1) (Leaf 2)) (Leaf 3)

> > | | | | | | | |

> > Fold f g ... = f ( f ( g 1) ( g 2)) ( g 3)

==&gt; At 20:18 he seems to see strong relations between Maybe and Either **construct** and **fold**?

==&gt; Note that these are NOT recursive data structures (Previous List and Trees ARE recursive)!

![](<Maybe and Either construct and Maybe and Either fold strongly related.tiff>)

==&gt; ThusEither a b is a static-ly wrapped type a OR b (a union)

==&gt; And Maybe is a special case of Either a Nothing?

==&gt; To fold over Either would mean to fold either a value of type ‘a' or a value of type ‘b’?

==&gt; It would be the structure destructor ‘f’ would need to dispatch an (Either a b) to a (g a) or (g b)?

f: (Either a b) -&gt; g a | g b

g: (a | b) -&gt; c

==&gt; And the special case for Maybe a:

f: (Either a Nothing) -&gt; g a | g Nothing

g: (a | Nothing) -&gt; c

==&gt; But Either aggregates two types - what common type can we fold to?

==&gt; Consider an (Either int String) can fold to int (assuming the string carries an integer representation)?

==&gt; Consider a (Maybe bool) can fold to bool (assuming Nothing folds to false)?

==&gt; Consider a (Maybe String) can fold to String (assuming Nothing folds to an empty string)?

…

==&gt; AHA - The structure deconstructor ‘f’ is actually a dispatcher for ‘g’?

==&gt; ‘f’ knows the structure and can recursively travel the structure and apply g to each leaf value of the structure)?

**==&gt; Thus, it is ‘f’ that defines it what order the values in the structure shall be the subject of g application?**

…

==&gt; At 23:47 he introduces the category theory term “**catamorphism**” as the definition of fold (<https://youtu.be/AAGBfOa2fnY?t=1427>)?

==&gt; He seems to state that the result of a fold can be a new structure (it just have to follow and apply g to values of the structure as defined by an f)?

![](<Fold transforms a structured value into something else.tiff>)

==&gt; NO - A fold always collapses a structure into “one thing” like in a “catastrophy” (<https://youtu.be/AAGBfOa2fnY?t=1467>)?

**==&gt; So, serialisation of data structures is a fold?!**

==&gt; And “cata” is greek that means something like “downwards” or “according to”?

==&gt; At 24:55 he hints on how a catamorphism “works” (<https://youtu.be/AAGBfOa2fnY?t=1495>)?

==&gt; At 27:40 he states that the algebra for any datatype can be expressed as a small set of functors (<https://youtu.be/AAGBfOa2fnY?t=1660>)?

==&gt; Consider the functors **1,K, I, +, \***

1 is the “Unit” (e.g., empty list, Nothing appropriate for the type we operate on)?

K is the Type value (type as embellished value)?

I is the “Identity”

+ is the Sum (union)

\* is the Product (Set)

==&gt; Now, I get the feeling that somehow this is related to a Category (A Category for types)?

==&gt; And ‘+’ is somehow related to union types (e.g., variants)?

==&gt; And ‘\*’ is somehow related to An types (e.g., structs)?

==&gt; Is K in some sense the meta-value as we propose in Tha?

==&gt; And this is all about algebraic types?

**==&gt; But the whole “Functor” and “Category” thing is still a bit fuzzy to me...**

==&gt; The Identity somehow relates to the property of the algebra that all operations stay within the Category (types stay types)?

==&gt; Or, Identity enables us to operate on recursive data types (terminate with Identity when the structure terminates)?

2) Consider the wikipedia page on Catamorhism (<https://en.wikipedia.org/wiki/Catamorphism>)?

==&gt; It seems a catamorhism in this wikipedia article restricts the fold to operate only on lists?

> “*In functional programming, catamorphisms provide generalizations of folds of lists to arbitrary algebraic data types, which can be described as initial algebras.*”

==&gt; It seems a hylomorphism is the composition of fold (a catamorhism) and an un-fold (an anamorphism)?

> “*The dual concept is that of anamorphism that generalize unfolds. A hylomorphism is the composition of an anamorphism followed by a catamorphism.*"

==&gt; Consider this example code to get a grip on “Algebra” and other terms used to talk about catamorphisms?

==&gt; It seems to be Haskel code (

> ```
> type StepAlgebra b = (b, b->b) -- the algebras, which we encode as pairs (nil, next)

> data Nat = Zero | Succ Nat -- which is the initial algebra for the functor described above

> foldSteps :: StepAlgebra b -> (Nat -> b) -- the catamorphisms map from Nat to b
> foldSteps (nil, next) Zero       = nil
> foldSteps (nil, next) (Succ nat) = next $ foldSteps (nil, next) nat
> ```

  
==&gt; The StepAlgerbra builds pairs from values (a value of type b is transformed into a pair of that value AND a function that transforms b values b -&gt; b)  
==&gt; The “Initial Algebra” seems to be the algebra we like to transform (using a catamorphism)?

==&gt; In this case the algebra is recursive in that the Nat type is either Zero OR Succ Nat

==&gt; The Catamorphism is defined by the recursive foldSteps function that dispatches on Zero or Succ Nat?

foldSteps takes a StepAlgebra on values of type b, and returns a function that maps a Nat to a b.

...

...

==&gt; Consider the relation of catamorhism and F-algebra (A catamorphism maps one F-algebra to another)?

> “*In category theory, the concept of catamorphism (from the Greek: κατά "downwards" and μορφή "form, shape") denotes the unique homomorphism from an initial algebra into some other algebra.*"

==&gt; Consider the wikipedia page on F-Algebra (<https://en.wikipedia.org/wiki/F-algebra>)?

> “*F-algebras can also be used to represent data structures used in programming, such as lists and trees.*"

==&gt; Hm.. Is this why F system is about types?

…

…

Consider to delve deeper into this idea that folds can in theory be defined totally by reflection of the constructor (they operate on the same structure)?

...

{% endraw %}
