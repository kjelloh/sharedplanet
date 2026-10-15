# Todo: programming - Consider to implement iterative range-mapping parsing using design inspired by Boost Spirit?

```#ad8b2410``` *As of 2016-01-16 02:36*

[mail plain/text](mail.txt)

{% raw %}
Studying Boost Spirit using “rules” that may be composed into “grammars” it seems we may not us that for data message decomposition but the same design may be applied?

==&gt; Also See “Todo: Programming - Consider to elaborate on data-structure paring/mapping using iterator ranges?"

1) Consider to name this design OPrime (from optimus prime, the great transformer)?

2) Let Prime apply rules in the same way as Boost Spirit?

==&gt; Each rule returns a Range (Corresponds to Qi raw&#91;&#93; rule)?

==&gt; That is, separating decoding into a special post-operation.

==&gt; Rule-composition should be possible “EBNF-style”?

...

3) Consider the following design of iterative-range-mapping?

==&gt; Each iteration uses a rule to parse one range into a list of ranges.

==&gt; Each range in the list is in a touple together with an ID assigned by the rule (thus each “element” gets an ID)

==&gt; Each iteration ends with applying decodings to ranges as mapped from provided decoders and range-ids.

==&gt; Each range that is decoded results in creation of a new vector to hold decoded data and having the range changed to refer to decoded data.

==&gt; End result is a list of couples of ranges (each having an unique ID) and some referring to new (decoded) data.

==&gt; The list carries enabled or disabled ranges (disabled ranges used to remember ranges active on lower levels but now excluded)

==&gt; Each range has the same interface but may be a range of vector iterators to source data, a range of adapter iterators (performing byte-by-byte transform of source) or range of new (decoded) vector data).

==&gt; Provide a special concatenate-iterator that “lifts” a list or ranges into a single range again

==&gt; The concatenate-iterator skips disabled iterators and iterates only through each active range in the list (making it appear as one range)

==&gt; Now the range-list produced by one iteration may be used as input to the next (using new rule and list of decodings)

4) Consider to aim at the following grammar for BERTLV parsing?

(See “T-REC-X.690-200811-I!!PDF-E.pdf” in ITfied Köpta Digitala Media)

bertlv :== (primitive_bertlv | composite_bertlv)

composite_bertlv :== composite_ber_type &gt;&gt; composite_ber_tail

composite_ber_tail :== (definite_ber_tail | indefinite_ber_tail)

primitive_bertlv :== primitive_ber_type &gt;&gt; definite_ber_length &gt;&gt; ber_value

==&gt; Seems Prime rules must be able to handle more general data constructs that the Qi Parser (that requires all tokens to have an end-separator)?

==&gt; OPrime needs to be able to parse ASN.1 structures?

==&gt; OPrime needs to be able to parse length-prefixed structures

==&gt; OPrime needs to be able to parse fixed-size structures?

==&gt; OPrime needs to be able to parse “Constructs” (structures with optional element presence)?

5) Consider to use Boost 1.55 Sprit design of “rules”, rule-composition and parser design for OPrime?

==&gt; This may be a good talk by Michael Caisse about Sprit V2 Qi and Karma (<https://www.youtube.com/watch?v=9iU9_45DoFc&index=73&list=PLlV-f5Ed71tfmz0VLoY1_ttOJ6WhA_zxW>)?

==&gt; This seem to be even better, although about C++11 Sprit X3 in the making (<https://www.youtube.com/watch?v=XZKZZy_v7hE>)

==&gt; The designed or Spirit seem to guide how Spirit is designed (including all parser inheriting from parser&lt;&gt;, how context works etc)

==&gt; At 13:15 he claims all parsers extend parser&lt;Derived&gt; (e.g. struct MyParser : parser&lt;MyParser&gt; {…}?

==&gt; This would be great. Is it the same in Qi 2?

==&gt; REALLY COOL design of Context that realies on compiler optimisation to actually allow client to get direct access directly to referenced stack frame variables (cross stack frames)!

==&gt; Created /Shared/workplace/RAD_Studio/MyQiPlayground/QiContextMagic.cpp with code

> //---------------------------------------------------------------------------

> #pragma hdrstop

> #include "QiContextMagic.h"  
> #include &lt;utility&gt; // std::declval  
> #include &lt;boost/mpl/identity.hpp&gt; // boost::mpl::identity  
> //---------------------------------------------------------------------------  
> #pragma package(smart_init)

> // From 31:30 into (<https://www.youtube.com/watch?v=XZKZZy_v7hE>)

> template &lt;typename ID, typename T, typename NextContext&gt;  
> struct **context** {

> context(T const& val, NextContext const& next_ctx)  
> : _val(val), _next_ctx(next_ctx) {}

> /\*\*  
> \* Explicit get of our T value (called with our ID).  
> \* Compiler matches this for call to get(ID& id)  
> \* boost::mpl::identity&lt;ID&gt; is eqvivalent to template &lt;typename X&gt; struct {typedef X type;} // <http://www.boost.org/doc/libs/1_60_0/libs/mpl/doc/refmanual/identity.html>  
> \* Thus get() takes a parameter that is an empty struct that is default constructable only from ID (hides all other implicit type conversion to ID)  
> \*/  
> T const& **get**(boost::mpl::identity&lt;ID&gt;) const {  
> return _val;  
> }

> /\*\*  
> \* Compiler always matches a call to get(NOT_ID& id) to this one (i.e. get called with type other than our ID)  
> \* Compiler will instanciate a call to the matching get in _next.ctx.  
> \*  
> \* <http://en.cppreference.com/w/cpp/utility/declval>  
> \*  
> \*/  
> template &lt;typename Identity&gt;  
> decltype(std::declval&lt;NextContext&gt;().get(Identity()))  
> **get**(Identity id) const {  
> /\*\*  
> \* This will expand to either  
> \*  _next_ctx.get(boost::mpl::identity&lt;Identity&gt;)  
> \* or template &lt;typename Identity&gt; decltype(std::declval&lt;NextContext&gt;().get(Identity())) get(Identity id)  
> \*  
> \* The second will then expand the same way until the compiler finds a macthing get(boost::mpl::identity&lt;Identity&gt;)  
> \*  
> \* Compiler optimazation will then remove redundant code to create a direct call to the correct get in the chain...  
> \*  
> \* ==&gt; (**magic**)!  
> \*  
> \* Note: The chain must end with the empty_context to ensure the compiler always finds a match if no context in the chain has a value to get for provided Identity  
> \*/  
> return _next_ctx.get(id);  
> }

> T const& _val;  
> NextContext const& _next_ctx;

> };

> // From 33:20 into (<https://www.youtube.com/watch?v=XZKZZy_v7hE>)

> struct empty_context {  
> struct undefined {};

> template &lt;typename ID&gt;  
> undefined get(ID id) const {  
> return undefined();  
> }

> };

> namespace example_1 {

> // From 34:10 into (<https://www.youtube.com/watch?v=XZKZZy_v7hE>)

> struct **foo_id**;

> template &lt;typename Context&gt;  
> void bar(Context const& ctx) {  
> ctx.get(boost::mpl::identity&lt;**foo_id**&gt;());  
> // Will return the value of (int i) in foo stack frame :)  
> }

> void foo() {  
> int i = 123;  
> empty_context empty_ctx;

> context&lt;**foo_id**,int,empty_context&gt; ctx(i,empty_ctx);

> bar(ctx);  
> }  
> }

==&gt; We may use this pattern for OPrime parsers to share data (e.g. have BERTLV length parser forward the number of bytes to read to the BERTLV content parser)

==&gt; Q: May we extend Qi with OPrime parsers and only use raw&#91;&#93; boost ranges as returns?

==&gt; Or do we have to re-invent the engine but use the Qi design pattern?

==&gt; Would be good if we could extend as Qi already has so much to offer for text parsing (and semi-binary parsing)?

==&gt; Consider to mail Joel de Guzman about enabling Qi X3 with this feature?

**WE ARE HERE...**

==&gt; Boost Spirit seems to be documented here (<http://www.boost.org/doc/libs/1_55_0/libs/spirit/doc/html/spirit/introduction.html>)?

==&gt; Seems Lex is about splitting “text” into “tokens” (<http://www.boost.org/doc/libs/1_55_0/libs/spirit/doc/html/spirit/lex/lexer_introduction.html>)

==&gt; Consider to borrow the idea of a tokeniser that tags matched tokens?

==&gt; This seem like a good starting point to understand Qi (<http://www.boost.org/doc/libs/1_55_0/libs/spirit/doc/html/spirit/qi/tutorials/quick_start.html>)?

==&gt; This seem to be a clear introduction Michael Caisse about Sprit X3 (<https://www.youtube.com/watch?v=xSBWklPLRvw>)?

==&gt; X3 Seem to be in the latest boost release Nov 2015 (<http://boost-spirit.com/home/2015/05/16/spirit-3-0-0/>)?

==&gt; Oh, this talk is actually based on his V2 talk above.

…

Consider to elaborate more on this design and try to build a simple app to text some basic simple concepts?

...

{% endraw %}
