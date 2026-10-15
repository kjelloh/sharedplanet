# Todo: Tha - Consider Haskel "kind values" are in fact Tha meta-2 values?

```#bba1c0c9``` *As of 2017-07-31 13:25*

[mail plain/text](mail.txt)

{% raw %}
It seems when I study Haskel that what Haskel calls “the kind of a type” is in fact what we in Tha calls the meta-2 value (the type constructor)?

1) Consider this blog post (<http://www.parsonsmatt.org/2017/04/26/basic_type_level_programming_in_haskell.html>)?

==&gt; Its seems pretty clear that the author claims Haskel “kind value” defines a meta-2 value?

> Well, it turns out that types don’t have types (kind of, sort of). Types have *kinds*. We can ask GHCi about the *kind* of types with the `:kind` command:

  
> ```
> λ> :kind Maybe
> Maybe :: * -> *
> ```



==&gt; And ‘\*’ seems to represent types that has values?

==&gt; Q: Can Haskel have types that does not carry values (empty value sets)?

…

…

Consider to delve deeper into how the Tha model maps to the Haskel type system?

...

{% endraw %}
