# Todo: Programming - Consider to study ASN.1 based parsers in comparison to PEG grammar based ones?

```#9329eb70``` *As of 2016-01-16 22:55*

[mail plain/text](mail.txt)

{% raw %}
Although tempting it seems PEG (Parsing Expression Grammar) has its drawbacks if tried to applied to data stream message parsing? Consider to study how the ASN.1 grammar compares to PEG grammar and what differs a data stream message parser from a text language parser?

1) PEG (Parsing Expression Grammars) seems well defined by wikipedia (<https://en.wikipedia.org/wiki/Parsing_expression_grammar>)?

==&gt; PEG grammars defines a parser that transforms a text stream into an AST (Abstract Syntax Tree), i.e. a Composite.

2) ASN.1 seem to live on this site (<http://www.itu.int/en/ITU-T/asn1/Pages/introduction.aspx>)

==&gt; I can’t help it, ASN.1 just does not seem like a readable syntax (just to complicated and talkative)?

3) Consider to relate to C++ Boost Sprit library “Todo: programming - Consider to implement iterative range-mapping parsing using design inspired by Boost Spirit?”

==&gt; Spriti Qi (and experimental successor x3) implements PEG using C++ Expression Templates ([https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Expression-template](https://en.wikibooks.org/wiki/More_C++_Idioms/Expression-template))

4) This seem to be a C++ code generator using ASN.1 input to generate a parser (<http://www.oss.com/asn1/products/asn1-cpp/asn1-cpp.html>)?

==&gt; Note that this approach does not facilitate a C++ Template Grammar?

5) Consider to select if to implement with C++ Template Grammar or some runtime created grammar?

==&gt; C++ Template Grammars are static objects declared at compile time (applying template “magic”) to optima and build the parsing code.

==&gt; If we like grammars to be created from configuration files at run-time we can’t build it using Template Grammars?

...

5) Consider to study parsing terminology to get some background to understand parsing?

==&gt; An Abstract Syntax Tree (AST) leaves out details in the “real” syntax (e.g. parenthesis, if-keywords an C++) (<https://en.wikipedia.org/wiki/Abstract_syntax_tree>)

==&gt; A Concrete Syntax Tree (CTX(?) or just Syntax Tree) keep all the details of the passed input (<https://en.wikipedia.org/wiki/Parse_tree>)

==&gt; The Syntax Tree is made up of nodes being root or branch (non-terminal) and leaf (terminal) “functions" (<https://en.wikipedia.org/wiki/Terminal_and_non-terminal_functions>)

6) Seems OPrime for each layer shall map a range to an ordered set of ranges AND a Syntax Tree of ID:s?

==&gt; Each node has an ID and refers to the range in the input of the match.

==&gt; Sub-nodes will thus always refer to sub-ranges of the parent node range.

==&gt; All ranges are ranges of the same Code Points (e.g. char/octet, UCS/32-tet)

**==&gt; Each new iteration will now create a new Syntax Tree for each mapped output range of the level before! **

7) Consider to create an application to play around with OPrime mechanisms and idioms?

==&gt; Created “/Shared/workplace/RAD_Studio/MyOprimePlayground”

==&gt; Created document “/Shared/workplace/RAD_Studio/MyOprimePlayground/doc/GrammarDataPlayGround.docx” with actual data (SPDH, iPOS)

==&gt; Would b e nice to have a complete TCP/IP Frame to SPDh HOST (emulate by adding TCP/IP length field)?

…

…

Consider to delve deeper into comparing ASN.1 and PEG grammar and see how/what fits parsing OPrime-style the best?

{% endraw %}
