# Todo: C++ Protocol Library - Consider to leverage the relation between "Structure Construct" and "Structure Fold" as a catamorhisms to enable both serialisation and de-serialisation using a single structure definition?

```#34be19a5``` *As of 2017-08-08 14:28*

[mail plain/text](mail.txt)

{% raw %}
It seems we have been correct all along that there is a strong relation between structure construct and structure fold. It comes from fold and construct operating on the same structure and defined in category theory as a catamorhism?

==&gt; Also see “Todo: Tha - Consider that the fold operations of a structured type is a catamorphism of its constructors (fold deconstructs the structure that the constructor constructs)?”

1) Consider to leverage that folds are catamorphisms to have the C++ protocol library define serialisation as a fold on the protocol frame data structure?

…

…

Consider to delve deeper into this idea to really understand catamorphisms and enable a C++ library to define serialisation based on a definition of de-serialiasation (i.e. construct)?  
...

{% endraw %}
