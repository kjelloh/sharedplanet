# Todo: Meta Value Model - Consider to be able to print out all value declarations and definitions in correct Meta Model Language Syntax?

```#59d07f13``` *As of 2017-06-06 11:34*

[mail plain/text](mail.txt)

{% raw %}
Consider it would be good to define a scripting syntax to be used both for adding meta value declarations and definitions and for printing existing ditos as scripts?

==&gt; Also see ”[Todo: Meta Model - Consider to define a language to define meta-value computation (i.e., arrows alias functions)?](../5afafbd8/chime.md)”

1) Consider each identifier may be printed to show its current declaration and optional definition?

==&gt; Consider to model each meta-level to hold a list of identifiers (each identifier holds the identifier name, its meta value name and defined value)?

&gt;ls number1

\* Listing of /number1 \*

{name=”number1”, meta-value-name = ”meta/number”, value=null}

==&gt; Or should we use the proposed Meta Language Syntax?

\* Listing of /number1 \*

number1 = number null

2) Consider to be able to print whole or part structures?

&gt;ls -r record1

\* RecursiveListing of /record1 \*

record1 = record {

name = text ”value1”

value = number /null

}

…

==&gt; This would conform with the syntax of a meta-value also being an initializer function (and synax "meta-value-name value-name” implies the value )?

record1 : record {name : text, value : number }

record1 = {name = ”value1”, value = 5}

Or combined

record1 = record {name : text, value : number } {name = ”value1”, value = 5}

Or even…

record1 = record {name : text = ”value1", value : number = 5}

record1 = record {name = text ”value1", value = number 5}

3) Consider that a Model actually only contains declarations?

==&gt; It is in fact the client of the model that defines an instance of the model?

==&gt; Thus it is the print of all declarations that should be usable as a text representation of the model?

…

…

Consider to elaborate on possible print syntax and what printed data (declarations or declarations+definitions) that may be used to defined the model from text?

...

{% endraw %}
