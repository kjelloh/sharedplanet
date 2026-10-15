# Todo: Meta Value Model - Consider value operations are defined as generic member function values (i.e., in Meh denoted wit path identifier "value.operation_x")?

```#e69bcddf``` *As of 2017-06-16 12:46*

[mail plain/text](mail.txt)

{% raw %}
Consider operations defined on values are modelled as the value composing these functions (having these operations as member values)?

1) Consider how the Set value gets a member operation ”**has_member**”?

==&gt; Consider a meta-0 set value?

Meh´.meta-0&gt; (identifier my_set (set 1 3)) // ”my_set” is a set of literal number values with set keys ”1” and ”3”

Meh´.meta-0&gt; (my_set.has_member 3) // applies ”my_set” member value ”has_member” as_function to literal 3

(bool true)

Meh´.meta-0&gt;

==&gt; Consider function has_member is in fact a **Generic** function (it gets instantiated and dispatched on its application)?

==&gt; Thus, the meta-0 set value member value ”has_member” is defined as Generic?

has_member: a -&gt; Bool // Would mean a function that takes any-type value and returns a Bool value?

has_member =

2) Consider to compare with other languages?

==&gt; Elm seem to also use the ”member function” idiom?

> ```
> > import String
> > String.length
> <function> : String -> Int
> ```

  
==&gt; Seems to read: ”String" type member ”length” is a function from String to Int?

==&gt; And Elm seem to support **Generic Types** as ”Generic data Structures” (<https://guide.elm-lang.org/types/union_types.html#generic-data-structures>)?

> ```
> > type List a = Empty | Node a (List a)
> ```

  
==&gt; Seems to read: The type ”List of any-type a” is an OR-type of Empty or (Node a (List a))

==&gt; And ”Node a (List a)” seems to read: A Node any-type a (Node type is a head,tail pair)

> ```
> > Empty
> Empty : List a

> > Node
> <function> : a -> List a -> List a
> ```

  
==&gt; Seems to read: Node is a function that takes an any-type value a and a List of any-type value a and returns a new List of any-type a?

**Hm… How does Elm pull this double reference off (List defined in terms of Node, and Node in terms of List)?  
**

> ```
> > Node "hi" Empty
> Node "hi" Empty : List String

> > Node 1.618 (Node 6.283 Empty)
> Node 1.618 (Node 6.283 Empty) : List Float
> ```

  
==&gt; Must be Instantiation of defacto Lists inferred from provided value?

==&gt; NOTE: Elm seems to require unions to contain same-type members (it is not possible to have a union of values of different (generic) types?

…

Consider to pin down exactly how modelled functions may be members of values and also Generic?

...

{% endraw %}
