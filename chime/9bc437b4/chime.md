# Todo: Meh - Consider to define the non terminal (AST nodes) and terminal (AST leafs) symbols of the Meh grammar?

```#9bc437b4``` *As of 2017-06-22 12:10*

[mail plain/text](mail.txt)

{% raw %}
It seems it could be a good idea to start documenting the Meg grammar in terms of its terminal symbols?

1) Consider a grammar is defined as a set or production rules that recurse on non-terminal symbols (nodes of the AST) and terminal symbols (reserved symbols of the language)?

==&gt; Also see ”Todo: Meta Value Model - Consider to compare context free grammar for English language as input to understand a PEG for Meh?”

![okänt.tiff](okänt.tiff)

==&gt; Thus non-terminal symbols (phrase types) of the grammar becomes nodes in the AST and terminal symbols (words) becomes leafs?

![](<AST example for English scentence.tiff>)

**==&gt; Thus, for Meh - the non-terminal symbols of the language are the possible ”constructs” and the leafs are the language ”reserved words”?**

2) Consider to understand how the production rules, the non-terminal and the terminal symbols are expressed in C++ boost spirit Qi?

==&gt; Also see ”Todo: Meta Value Model - Consider to try implementing Meh parser using C++ Boost Spirit Qi grammar library (Or newer Boost X3)?

==&gt; Consider the Lisp grammar defined in github project ”Lisp in C++” (<https://github.com/klmr/lisp.cpp>)?

> template &lt;typename Iterator&gt;  
> struct lisp_grammar : qi::grammar&lt;Iterator, value(), qi::ascii::space_type&gt; {  
> template &lt;typename Signature&gt;  
> using rule_t = qi::rule&lt;Iterator, Signature, qi::ascii::space_type&gt;;

> rule_t&lt;value()&gt; start;  
> rule_t&lt;symbol()&gt; sym;  
> rule_t&lt;value()&gt; lit;  
> rule_t&lt;literal&lt;bool&gt;()&gt; boolean;  
> rule_t&lt;literal&lt;double&gt;()&gt; number;  
> rule_t&lt;literal&lt;std::string&gt;()&gt; string;  
> rule_t&lt;list()&gt; lst;

> lisp_grammar() : lisp_grammar::base_type{start} {  
> using namespace qi;  
> using namespace boost::phoenix;  
> start %= sym | lit | lst;  
> sym %= eps &gt;&gt; lexeme&#91;+(char_("A-Za-z") | char_('-') | char_("+\*/%~&|^!=&lt;&gt;?"))&#93;;  
> lit %= boolean | number | string;  
> boolean %=  
> qi::lit("#t")&#91;_val = construct&lt;literal&lt;bool&gt;&gt;(true)&#93;  
> | qi::lit("#f")&#91;_val = construct&lt;literal&lt;bool&gt;&gt;(false)&#93;;  
> number %= double_;  
> string %= eps &gt;&gt; lexeme&#91;'"' &gt;&gt; \*(char_ - '"') &gt;&gt; '"'&#93;;  
> lst %= '(' &gt;&gt; \*start &gt;&gt; ')';  
> }  
> };

==&gt; It seems **rule_t** variables actually **declares** symbols of the grammar (non terminal and terminal symbols)?

==&gt; It seems the actual **production rules** are defined using special **operator ”%=”**?

> > start %= sym | lit | lst;

==&gt; Would defined production rule for symbol ”start” (it is a ”sym”, a ”lit” or a ”lst”)

==&gt; Thus production rules that are defined as composition of other rules defines **non terminal** symbols of the grammar?

> start %= sym | lit | lst;  
> lit %= boolean | number | string;  
> lst %= '(' &gt;&gt; \*start &gt;&gt; ')’;

==&gt; And production rules that only picks a symbol out of the ”sentence” defines **terminal** symbols?

> sym %= eps &gt;&gt; lexeme&#91;+(char_("A-Za-z") | char_('-') | char_("+\*/%~&|^!=&lt;&gt;?"))&#93;;  
> boolean %=  
> qi::lit("#t")&#91;_val = construct&lt;literal&lt;bool&gt;&gt;(true)&#93;  
> | qi::lit("#f")&#91;_val = construct&lt;literal&lt;bool&gt;&gt;(false)&#93;;  
> number %= double_;  
> string %= eps &gt;&gt; lexeme&#91;'"' &gt;&gt; \*(char_ - '"') &gt;&gt; '"'&#93;;

3) Consider to document the Meh language in terms of non-terminal symbols (constructs) and terminal symbols (reserved words)?

==&gt; It would seem we have a choice on how much we shall define Meh to forward operators to functions modelled in Tha?

==&gt; By forwarding to Tha the Meh language would need only a very small set of special constructs?

…

==&gt; Consider how Meh defines instantiation (creation) of Identifiers?

==&gt; Consider the string-literal to act as Identifier constructor?

Meh´&gt; (”count” number) // Would create new identifier in current environment (Tha) that declares count to be of meta-value number)?

==&gt; Consider Tha member value ”identifier” with as_function that instantiates a declared identifier?

Meh¨&gt; (**identifier** count number) // Would create new identifier in current environment (Tha) that declares count to be of meta-value number)?

==&gt; Consider ordinary lisp syntax?

==&gt; Consider make-symbol (<https://www.cs.cmu.edu/Groups/AI/html/cltl/clm/node110.html>)?

> > ”*(make-symbol print-name) creates a new uninterned symbol, whose print name is the string print-name. The value and function bindings will be unbound and the property list will be empty.*"

Meh´&gt; (make_symbol count)

...

…

…

Consider to update this Todo as the Meh language gest implemented and proved to work in a valuable way?

...

{% endraw %}
