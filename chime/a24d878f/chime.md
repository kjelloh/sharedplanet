# Todo: Meta Value Model - Consider to try implementing Meh parser using C++ Boost Spirit Qi grammar library (Or newer Boost X3)?

```#a24d878f``` *As of 2017-06-17 20:50*

[mail plain/text](mail.txt)

{% raw %}
Could it be worth the initial learning curve (and become boost dependent) to try to implement the Meh parser using Boost Spirit Qi?

==&gt; Also see ”[Todo: Meta Value Model - It seems to parse and evaluate Meh expressions I really need to get a grip on s-expressions explicitly and grammar parsing i general?](../2f41063b/chime.md)"

1) Consider this Boost X3 example with a complete Grammar C++ X3 based Repl including an AST and AST printer (<https://github.com/djowel/spirit_x3/blob/master/example/x3/calc5.cpp>)

==&gt; It seems this is a good role model for our Meh Repl and in modern C++?

...

2) Consider this Github published Cpp-file that implements a Lisp interpreter (<https://github.com/klmr/lisp.cpp>)?

==&gt; It seems to apply fairly modern C++ coding standards by relying on variants and smart memory objects?

==&gt; The repl is really nice looking!

> auto repl(std::string prompt) -&gt; void {  
> auto global_env = get_global_environment();

> for (;;) {  
> std::cout &lt;&lt; prompt &lt;&lt; std::flush;  
> auto line = std::string{};  
> if (not getline(std::cin, line))  
> return;

> try {  
> auto&& expr = klmr::lisp::read_full(begin(line), end(line));  
> if (not expr)  
> return;  
> auto&& result = eval(\*expr, global_env);  
> std::cout &lt;&lt; result &lt;&lt; '\\n';  
> }  
> catch (klmr::lisp::error const& err) {  
> std::cerr &lt;&lt; err.what() &lt;&lt; '\\n';  
> }  
> }  
> }

==&gt; Nice - using read: string -&gt; expr (the AST) and then eval(expr,env). Very clean :)

==&gt; And the Lisp grammar seem to fit in just a few lines when using Qi?

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
> qi::lit("#t")&#91;_val = construct&lt;literal&lt;bool&gt;&gt;(true)&#93; |  
> qi::lit("#f")&#91;_val = construct&lt;literal&lt;bool&gt;&gt;(false)&#93;;  
> number %= double_;  
> string %= eps &gt;&gt; lexeme&#91;'"' &gt;&gt; \*(char_ - '"') &gt;&gt; '"'&#93;;  
> lst %= '(' &gt;&gt; \*start &gt;&gt; ')';  
> }  
> };

==&gt; It seems one first defines the non-terminal symbols rule_t variables?

==&gt; Then one composes production rules using operator ”%=” on terminal and non-terminal symbols?

==&gt; TODO: Make it compile in Xcode (for now it does not find

3) Consider this JSon parser in C++ using Qi (<http://codegist.net/snippet/c/jsoncpp_yamamushi_c>)

> `#include &lt;boost/any.hpp&gt;`  
> `#include &lt;boost/spirit/include/qi.hpp&gt;`  
> `#include &lt;boost/fusion/include/std_pair.hpp&gt; `  
> `#include &lt;vector&gt;`  
> `#include &lt;map&gt;`  
> `#include &lt;iostream&gt;`  
> `namespace` `json {`  
> `namespace` `qi = boost::spirit::qi;`  
> `namespace` `ascii = boost::spirit::ascii;`  
> `struct` `nullptr_t_ : qi::symbols&lt; ``char``, ``void` `\* &gt; {`  
> ` ``nullptr_t_() {`  
> ` ``add( ``"null"``, nullptr );`  
> ` ``}`  
> `} nullptr_;`  
> `template``&lt; ``typename` `Iterator &gt;`  
> `struct` `Grammar : qi::grammar&lt; Iterator, boost::any(), ascii::space_type &gt; {`  
> ` ``Grammar(): Grammar::base_type( start ) {`  
> ` ``using` `qi::lexeme;`  
> ` ``using` `qi::double_;`  
> ` ``using` `qi::bool_;`  
> ` ``using` `ascii::char_;`  
> ` ``start = value_rule.alias();`  
> ` ``object_rule = ``'{'` `&gt;&gt; pair_rule % ``','` `&gt;&gt; ``'}'``;`  
> ` ``pair_rule = string_rule &gt;&gt; ``':'` `&gt;&gt; value_rule;`  
> ` ``value_rule = object_rule | array_rule | string_rule | nullptr_ | double_ | bool_;`  
> ` ``array_rule = ``'&#91;'` `&gt;&gt; value_rule % ``','` `&gt;&gt; ``'&#93;'``;`  
> ` ``string_rule = lexeme&#91; ``'\\"'` `&gt;&gt; \*( char_ - ``'\\"'` `) &gt;&gt; ``'\\"'` `&#93;;`  
> ` ``}`  
> ` ``qi::rule&lt; Iterator, boost::any(), ascii::space_type &gt; start;`  
> ` ``qi::rule&lt; Iterator, std::map&lt; std::string, boost::any &gt;(), ascii::space_type &gt; object_rule;`  
> ` ``qi::rule&lt; Iterator, std::pair&lt; std::string, boost::any &gt;(), ascii::space_type &gt; pair_rule;`  
> ` ``qi::rule&lt; Iterator, boost::any(), ascii::space_type &gt; value_rule;`  
> ` ``qi::rule&lt; Iterator, std::vector&lt; boost::any &gt;(), ascii::space_type &gt; array_rule;`  
> ` ``qi::rule&lt; Iterator, std::string(), ascii::space_type &gt; string_rule;`  
> `};`  
> `}`  
> `int` `main() {`  
> ` ``const` `std::string source = ``"&#91; null &#93;"``;`  
> ` ``json::Grammar&lt; std::string::const_iterator &gt; g;`  
> ` ``boost::any v;`  
> ` ``auto bit = source.begin();`  
> ` ``auto eit = source.end();`  
> ` ``bool` `r = boost::spirit::qi::phrase_parse( bit, eit, g, boost::spirit::ascii::space, v );`  
> ` ``if``( r ) {`  
> ` ``auto a = boost::any_cast&lt; std::vector&lt; boost::any &gt; &gt;( v );`  
> ` ``for``( auto it = a.begin(); it != a.end(); ++it ) {`  
> ` ``std::cout &lt;&lt; boost::any_cast&lt; ``void` `\* &gt;( \*it ) &lt;&lt; std::endl;`  
> ` ``}`  
> ` ``}`  
> ` ``return` `0;`  
> `}`

4) It seems we may like to decorate the AST generated by Qi to bind the AST back to the original code evaluated?

==&gt; Consider this live video of a guy answering a stack overflow question about this (<https://www.liveedu.tv/sehe/ZWroO-answering-boost-questions-daily/poyDG-enriching-ast-for-variable-references-vs-qd/>)?

==&gt; This is the stack overflow question with a solution on how to make Qi decorate the produced AST while parsin (<https://stackoverflow.com/questions/32500379/how-to-print-the-variables-matched-by-the-symbol-table-in-boost-spirit-parser/32501192#32501192>)?

==&gt; Consider we may want to do this to be able to point out syntax errors to the user when we fail to produce the AST (parsing error)?

…

…

Consider to elaborate on this idea to use Boost Spriti Qi (or newer Boost X3) to implement a Meh evaluator?

...

{% endraw %}
