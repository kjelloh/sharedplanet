# Todo: JSon Darwinet, Meh and Tha - Consider that a Tha model and Meh syntax for Json data structures only is in fact small but complete and may serve well as a proof of concept for Darwinet implementation?

```#a4165e7e``` *As of 2017-07-31 18:07*

[mail plain/text](mail.txt)

{% raw %}
It seems the Tha model is now mature enough so that we can model Json data structures and get something that is in fact complete to use for some Meh and Darwin proof-of-concept?

==&gt; Also see “[Todo: C++ JSON - Consider to find a good and stable modern C++ library for Json processing?](../9723a879/chime.md)"

1) Consider we can define the Tha for the JSon data structure in a very compact and clear way?

==&gt; Consider this page on JSon data types and values (<https://www.w3schools.com/js/js_json_datatypes.asp>)?

==&gt; Consider this is the complete JSOn data structure in Tha?

meta-2: **list**, **object**

meta-1: **number** {-MAX_FLOAT…MAX_FLOAT}, **text** {“”...”&lt;utf-8 text&gt;"}, **boolean** {true, false}

meta-0: **true**, **false**

==&gt; list and object are defined on meta-2 level and provides constructors for meta-1 values?

==&gt; Consider a List type is constrained to list of indexed values of a single type.

==&gt; Consider an Object type is a list of declared values (name and type)

==&gt; Consider number and text are meta-1 values that provide constructors for meta-0 values?

==&gt; Consider to support UTF-8 text only (and use “” syntax in Meh to infer text type)?

==&gt; Consider floating point number support only (and use 0.0 or 0 syntax in Meh to infer number type)?

2) Consider the Meh syntax to operate on the JSon Type Model Tha?

==&gt; Consider to extend Tha with members for Meh operations?

meta-2: -

meta-1: identifier // named types

meta-0: identifier // named values/variables

==&gt; Consider operator dispatching on provided meta-value (to apply correct meta-n identifier operator)?

(identifier “my_list” list int) // dispatch to meta-2::identifier: text -&gt; meta-2-value -&gt; meta-1-value -&gt; meta-1-declaration?

(identifier “my_int” int) // dispatch to meta-1::identifier: text -&gt; meta-1-value -&gt; meta-0-value -&gt; meta-0-declaration

**==&gt; Hm… should we put some operators into the Meg language itself?**

==&gt; Maybe declarations and definitions should go into the Meh language (not applied by decorating the Tha)?

…

…

Consider to elaborate more on the Tha model and the Meh language to implement the small JSon data type and value set for a Darwinet proof-of-concept (To later extend for more complicated types and operations)?

...

{% endraw %}
