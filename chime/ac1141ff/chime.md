# Todo: C++ - Consider to follow up on leads into understanding Category Theory and Monads as pointed out by Meetup friend Ramon Horvath

```#ac1141ff``` *As of 2017-01-27 14:52*

[mail plain/text](mail.txt)

{% raw %}
After having a discussion after a C++ meetup over a beer Horvath messaged me and gave some leads he thinks are good for me to follow to understand about how Category Theory may be applied to functional programming in C++.

1) Consider to follow up on leads into understanding Category Theory and Monads as pointed out by Meetup friend Ramon Horvath?

> ”*Hi, I thought after our last conversation that I would call your attention to a list of lectures on youtube that you probably know of but just in case if you don't: Category theory for programmers by Bartosz Milewski, his background is also in physics. The other thing I would like to call your attention to is a book by Saunders MacLane, Categories for the working mathematician. This is arguably the best comprehensive introduction to the subject by one of its founding fathers. You don't even have to buy it, pdfs can be found here and there if you search for it. Best, Ramon*"

2) Consider to reda the original paper by *Saunders MacLane "Categories for the working mathematician”?*

*==&gt; Consider this scanned (but not UCR:ed) (<http://www.maths.ed.ac.uk/~aar/papers/maclanecat.pdf>)?*

*==&gt; It seems we can’t find an OCR:ed (searchable) copy of this paper on the web)?*

*...*

3) Consider this paper as a good alternative to explain category theory (<http://www.cs.ox.ac.uk/people/bob.coecke/ctfwp1_final.pdf>)?

==&gt; Turn raw potato (Set A) into cooked potato (Set B)  f: A —&gt; B

==&gt; Turn Cooked potato into salted cooked potato g: B —&gt; C

==&gt; Combine cooking and salting g\*f: A —&gt; C

==&gt; Functions transforms one Object into another one (here set of raw potatotes and cooked potatoes)

==&gt; Combining functions is chaining transformations of objects

==&gt; Do nothing to Vegetable (Category X) 1x: X —&gt; X

==&gt; Then Doing nothing combined with any process 1x\*f == f\*1x == f: X —&gt; Y

==&gt; The Identity transformation works on all Objects (in our case all objects in the category Vegetables)

==&gt; Given Frying a Carrot h: D —&gt; E

==&gt; Then Cook Potato (Set A) and fry Carrot (Set D) at same time f ⊗ h : A ⊗ D —&gt; B ⊗ E

==&gt; For our sets this is the cartesian product

==&gt; Set A and Set B is transformed to the ”pair” {D, E} as defined by f ⊗ h

==&gt; See Category Theory Product (<https://en.wikipedia.org/wiki/Product_(category_theory))>

![](<Category Theory Product.tiff>)

==&gt; For us Y is the Set of pairs {A, D} (Raw potatoes and raw carrots)

==&gt; f1 is then the transformation f1 : {A, D} —&gt; B (applying Cooking f: A —&gt; B)

==&gt; f2 is then the transformation f2 : {A, D} —&gt; E (applying frying h : D —&gt; E)

==&gt; Now we may turn raw potatoes A and Carrots D into Meal M

==&gt; Given Peppering the Carrot k : E —&gt; F

==&gt; And above Salting the potato g: B —&gt; C

==&gt; And given Mash Salted Cooked potatoes and Peppered Fried Carrots x: C ⊗ F —&gt; M

![](<Category Vegitibles transform potatoes A and carrots D into meal M.tiff>)

==&gt; A ⊗ D (Set of ”paired” Raw potatoes and raw carrots)

==&gt; f ⊗ h (Transform ”paired” Raw potatoes and raw carrots into ”paired” cooked potatoes and fried carrots)

==&gt; g ⊗ k (transform ”paired” cooked potatoes and fried carrots into ”paired” Salted Potatoes and Peppered Carrots)

==&gt; x then transforms Cooked Salted Potatoes C and Fried Peppered Carrots F into Potato and Carrot Mesh M

==&gt; The whole transformation may then be combined as x ◦ (g ⊗ k) ◦ (f ⊗ h) : A ⊗ D —&gt; M

==&gt; We may read this as (Cook Potatos while fry carrot) and then (Salt the potatoes while Pepper the Carrots) and then Mech

==&gt; NOTE: The order of operations in the mathematical expression is THE OPPOSITE of the order they are applied.

==&gt; We note that the order of how we combine the operations does not matter!

==&gt; Mesh of Salted Potatoes and Peppered Carrots == Salted and Peppered ( Mesh of Cooked Potatoes and Fried Carrots)

==&gt; The operations ”Commute”

...

4) Consider this talk by Bartosz Milewski "Categories for the working cpp programmer” (<https://www.youtube.com/watch?v=GN5IV8mQtMY>)?

==&gt; He seems to define the C++ category of interest to be the Category of Types with functions as transforms between types?

![](<C++ Category of Types with functions as transformations.tiff>)

==&gt; He seems to call this Category for ”Set” (Category of types (sets of set of values for each type) and functions to transform between sets of values (types))

==&gt; The Objects are the Types (Each object is a set of all values of a type)

…

==&gt; At 21:00 he defines that it is enough if each Type (Object) has an Identity function (we do not need one that works for the whole Category of types)?

==&gt; At 38:30 he defines compose that chain embellished (semi-lifted diagonal) functions

![](<Compose Diagonal Functions.tiff>)

==&gt; thus compose takes two functions f: A —&gt; Writer&lt;B&gt; and g: B —&gt; Writer&lt;C&gt; and returns compose: A —&gt; Writer&lt;C&gt;

==&gt; At 42:45 he states that the embellished (modified to ”semi-lifted”) function types form a NEW CATEGORY!

![](<Category of Embellished Functions.tiff>)

==&gt; This seems to be what Scott Wlaschin calls ”Diagonal Functions” (See ”Todo: Programming - Consider to understand Monoids and Monads using the "Railway Oriented Programming" model?)”)

==&gt; At 44:30 he defines this new Category AND ITS IDENTITY

![](<Identity for Embellished type.tiff>)

==&gt; AHA - The Identity does NOT produce A it produce an Embellished A!

==&gt; The Identity is the transformation into the new type but without transforming the ”lifted” value!

==&gt; Idenity: A —&gt; std::pair&lt;A,std::string&gt;

==&gt; Compare this with applying diagonal lifting function f: A —&gt; std::pair&lt;B,std::string&gt; (Maps Set A to Set B in the pair)

==&gt; This Idenity will compose with f: A —&gt; std::pair&lt;B, std::string&gt;

==&gt; f ◦ Identity : (A —&gt; std::pair&lt;A, std::string&gt;) —&gt; std::pair&lt;B, std::string&gt; ok

==&gt; Identity ◦ f : (A —&gt; std::pair&lt;B, std::string&gt;) —&gt; std::pair&lt;B, std::string&gt; ok

==&gt; NOTE: This works because the ”combinator” itself is defined to glue together Diagonal Functions : A —&gt; std::pair&lt;B,std::string&gt;!

5) Consider in C++ we operate on the Category of Types?

==&gt; Our functions turns one type into another one (e.g. std::optional&lt;HANDLE&gt; fopen(std::path))

==&gt; The function fopen : std::path —&gt; std::optional&lt;HANDLE&gt;

==&gt; Q: What is our identity (the function that takes ANY TYPE and just returns the same type)?

==&gt; According to Milewski (above talk at 21:00) it is enough if there is an Identity to be combined for each function that adds no extra effect?

==&gt; It seems the confusion is that if we deal with functions that creates type with a new topology (say f: A —&gt; std::pair&lt;B,string&gt;) the Idenity: A —&gt; std::pair&lt;A, string&gt;)?

==&gt; NO - It is still unclear what the identity for fopen : std::path —&gt; std::optional&lt;HANDLE&gt; would be?

==&gt; Given The function fopen : std::path —&gt; std::optional&lt;HANDLE&gt;

==&gt; And the function readLine: std::optional&lt;HANDLE&gt; —&gt; std::optional&lt;std::string&gt;

==&gt; The combined function readLine ◦ fopen : std::path —&gt; std::optional&lt;std::string&gt;

==&gt; The Identtity for fopen would be something that when combined with readLn would have ”no effect”?

==&gt; OR, Identity: A —&gt; std::optional&lt;A&gt; for any A?

==&gt; But then we will be unable to compose with this identity (readLine ◦ Identity will not work as the result of Identity does not compose with readLine)?

**==&gt; It ssems (See above about composing embellished functions) the trick is to define the compose operation so that it works with the Identity operation?**

==&gt; In this case readLine: std::optional&lt;HANDLE&gt; —&gt; std::optional&lt;std::string&gt;

==&gt; Thus the Identity must be able to provide std::optional&lt;HANDLE&gt; to readLine AND it must be able to accept std::optional&lt;std::string&gt; from readLine?

==&gt; Is there such an Identity (And if not, we have defined our Category in the wrong way)?

**==&gt; Consider we apply the Embellished types and Diagonal functions in the Milewski example?**

==&gt; We would have function fopen : std::path —&gt; std::optional&lt;HANDLE&gt; (Diagonal function plain —&gt; embellished type)

==&gt; But readLine: HANDLE —&gt; std::optional&lt;std::string&gt; (Diagonal function plain —&gt; embellished type)

==&gt; The combined function readLine ◦ fopen : std::path —&gt; std::optional&lt;std::string&gt; (Diagonal function plain —&gt; embellished type)

==&gt; Now the Identity&lt;T&gt;: T —&gt; std::optional&lt;T&gt; will work as NO-OP with our combine for diagonal functions!

==&gt; fopen ◦ Identity&lt;path&gt;: (path —&gt; optional&lt;path&gt;) —&gt; optional&lt;HANDLE&gt; ok.

==&gt; Identity ◦ fopen : (path —&gt; optional&lt;HANDLE&gt;) —&gt; optional&lt;HANDLE&gt; ok.

...

==&gt; It seems we have three Categories to define an ”Algerbra” for to make it work?

==&gt; The plain types and function transforms f: A —&gt; B (Composition is chaining g(f(x))

==&gt; Diagonally Embellished types and transforms d&lt;f&gt;: A —&gt; Embellished&lt;B&gt; (Composition by chaining diagonal functions, unwrap and chain to next diagonal function)

**==&gt; NOTE: This is the Monad bind!**

==&gt; Fully lifted Embellished types and transforms map&lt;f&gt;: Embellished&lt;A&gt; —&gt; Embellished&lt;B&gt; (Composition is now plain chaining of fully lifted functions)

...

==&gt; It seems function composition now has value in our C++ program?

==&gt; Given The function fopen : std::path —&gt; std::optional&lt;HANDLE&gt;

==&gt; And the function readLine: std::optional&lt;HANDLE&gt; —&gt; std::optional&lt;std::string&gt;

==&gt; The combined function readLine ◦ fopen : std::path —&gt; std::optional&lt;std::string&gt;

==&gt; It seems in C++ we are able to do this at run-time by chaining the output value to the input value?

==&gt; Q: But are we able to write C++ code to define a new function that we may call with std::path and get an std::string in return?

...

==&gt; Q: How do we define ”Type Multiplication” to have any value in our C++ program?

==&gt; Consider we look for C++ program pattern f ⊗ h : A ⊗ D —&gt; B ⊗ E

==&gt; Then A ⊗ D could be std::pair&lt;A,D&gt; and f ⊗ h : std::pair&lt;A,D&gt; —&gt; std::pair&lt;B,E&gt;

==&gt; Consider if A and D are THE SAME TYPE (which is ok)?

==&gt; Also Consider f and g being TEH SAME FUNCTION (which is ok)?

==&gt; Then A ⊗ A = std::pair&lt;A&gt; and f ⊗ h == f ⊗ f : std::pair&lt;A&gt; —&gt; std::pair&lt;B&gt; (where std::pair&lt;B&gt; == std::pair&lt;f A&gt;, i.e. a pair with member transformed by f)?

…

{% endraw %}
