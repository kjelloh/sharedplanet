# Todo: Tha - Consider to elaborate on how to model Haskell type classes (e.g. Seq, Ord...) in Tha meta-values?

```#4eb73938``` *As of 2017-06-27 17:37*

[mail plain/text](mail.txt)

{% raw %}
Could we imagine that Haskell typ classes are in fact in Tha just meta values that defines a set of types that fulfills the type class ”contract”?

1) Consider this definition of Haskell type classes (<http://learnyouahaskell.com/types-and-typeclasses#typeclasses-101>)?

==&gt; It seems a types can be a ”member” of a type class?

> ”*A typeclass is a sort of interface that defines some behavior. If a type is a part of a typeclass, that means that it supports and implements the behavior the typeclass describes. *"

==&gt; It seems Haskell shows type class membership as part of a type using the ”=&gt;” symbol?

1. ghci&gt; :t (==)
2. (==) :: (Eq a) =&gt; a -&gt; a -&gt; Bool



==&gt; Which seem to read: The ”==” operator takes a value of any type a and another of any type a and returns a bool (given a i the member of the type class Eq)?

==&gt; It seems a lot of functions and constants are in fact generic on the members of a type class?

> ”minBound and maxBound are interesting because they have a type of (**Bounded** a) =&gt; a. In a sense they are polymorphic constants.”

1. ghci&gt; minBound :: Int
2. -2147483648
3. ghci&gt; maxBound :: Char
4. '\\1114111'
5. ghci&gt; maxBound :: Bool
6. True
7. ghci&gt; minBound :: Bool
8. False



==&gt; Note: ”::” is used to provide a type annotation (telling the compiler what type the expression should have)

==&gt; Thus, using the Int type annotation the generic minBound that returns an Int is called (dispatched to)?

==&gt; So, how do we make a type into a member of a type class?

…

2) Consider this tutorial on how to define your own types and type classes (<http://learnyouahaskell.com/making-our-own-types-and-typeclasses>)?

==&gt; It seems Haskell types are defined as a Set of values?

> ”*data means that we're defining a new data type. The part before the = denotes the type, which is Bool. The parts after the =are value constructors. They specify the different values that this type can have.*”

1. data Bool = False | True



1. data Int = -2147483648 | -2147483647 | ... | -1 | 0 | 1 | 2 | ... | 2147483647



==&gt; Note: Pseudo-code. Its impractical to define Int this way (although theoretical possible)?

==&gt; Thus, in Haskell a new type is defined using the keyword ”**data**”?

==&gt; It seems Haskell types act as *value constructor* (and uses lisp like operator syntax)?

> ”*Value constructors are actually functions that ultimately return a value of a data type.*”

1. ghci&gt; :t Circle
2. Circle :: Float -&gt; Float -&gt; Float -&gt; Shape



==&gt; Would read: The type of Circle is a function that takes three Floats and return a Shape?

==&gt; It seems in Haskell one makes a type of member of type call by using the keyword ”**deriving**”?

1. data Shape = Circle Float Float Float | Rectangle Float Float Float Float deriving (Show)



==&gt; Would read: Declare the type ”Shape” as the Set of type constructors ”Circle” or ”Float”, both members of type class ”Show”?

> ”*Haskell automagically makes that type part of the Show typeclass.*”

==&gt; It seems the type class ”Show” is able to infer ”to string” operators for its member class values (in this case for our new type Shape)?

==&gt; Q: How does it do that?

==&gt; Q: Could it be that it break down any type into atomic Haskell types (for which there is already ”to string” operators)?

==&gt; Anyhow, after defining our type ”Shape” to be member of type class ”Show” we are able to request Haskell to print Shape values?

1. ghci&gt; Circle 10 20 5
2. Circle 10.0 20.0 5.0



==&gt; If Shape had not been declared as member of ”Show” this would have failed with an error (Haskell would be unable to turn Circle into a string representation for output)?

==&gt; It seems Haskell uses the same keyword to declare type constructors (”Type parameters” in <http://learnyouahaskell.com/making-our-own-types-and-typeclasses>)?

> ”*type constructors can take types as parameters to produce new types.*”

1. data Maybe a = Nothing | Just a



==&gt; Seem to read: Type constructor ”Maybe” takes any type a and defines the Set of the types ”Nothing” or ”Just a"

==&gt; Consider Haskell type constructors are Tha meta-2 values?

==&gt; Meta-2 values defines a set of meta-1 values (i.e. constructs types) just as Haskell type constructors do?

3) Consider how Haskell type classes are able to infer operatons on user declared types made members of them (

==&gt; Haskell type class Show seems able to infer ”to string” operation on our own records (vector of declared identifiers)?

1. data Person = Person { firstName :: String
2.  , lastName :: String
3.  , age :: Int
4.  , height :: Float
5.  , phoneNumber :: String
6.  , flavor :: String
7.  } deriving (Show)



==&gt; Note how this closely mirrors how records are declared in other languages (as a list of declared identifiers, i.e., name-type pairs)?

==&gt; Q: Again - How is the type-class ”Show” able to infer a ”to string” operation to this record type?

==&gt; It seems in Haskell type constructors are Generic Types declared using lower case ”any types”?

1. data Car a b c = Car { company :: a
2.  , model :: b
3.  , year :: c
4.  } deriving (Show)



==&gt; Would read: Car is a generic type taking any type a,b and c and return a record with members declared using provided types?

==&gt; Consider in Meh we can accomplish this with a meta-2 value that can be used to infer unbound member identifier types from provided types (or values)?

==&gt; See ”Todo: Tha - Consider to define mtea-2 value "inferred" that constructs generic meta-1 value (they apply pattern matching to define meta-0 values)?”

...

==&gt; Compare the corresponding non-generic type?

1. data Car = Car { company :: String
2.  , model :: String
3.  , year :: Int
4.  } deriving (Show)



==&gt; It seems one uses the ”=&gt;” syntax to declare type class constraints in the type declaration (not recommended) and to function type declarations (aiming type constraints only when required by operation)?

1. data (Ord k) =&gt; Map k v = ...



==&gt; Not recommended - but defines generic ”Map” on any type k and v with restriction on k to be a member of type class Ord?

==&gt; Instead one should apply the ”(Ord k) =&gt; ” restriction to function declarations that actually requires the restriction to work?

...



4) It actually seems one declares a type as member of a type class by ”deriving” from it (See ”Derived instances” in <http://learnyouahaskell.com/making-our-own-types-and-typeclasses>)?

> ”*A type can be made an instance of a typeclass if it supports that behavior.*"

==&gt; It seems it is actually true that Haskell can infer user type operations derived from a set of some common type classes?

> ”*Haskell can automatically make our type an instance of any of the following typeclasses: Eq, Ord, Enum, Bounded, Show, Read.*"

…

…

Consider to elaborate more on how we may model Haskell type classes application for type constraints in Tha meta-model?

{% endraw %}
