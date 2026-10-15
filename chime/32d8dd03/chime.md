# Todo: Meh - Consider to really understand how we should evaluate the Meh AST?

```#32d8dd03``` *As of 2017-06-22 13:29*

[mail plain/text](mail.txt)

{% raw %}
It seems it will serve us well to really understand how we should evaluate the parser created AST using the Tha as the environment?

==&gt; Also see ”[Todo: Meh - Consider to define the non terminal (AST nodes) and terminal (AST leafs) symbols of the Meh grammar?](../9bc437b4/chime.md)"

1) Consider to study github project ”Lisp in C++” (<https://github.com/klmr/lisp.cpp>)?

==&gt; It seems in code the ast is in variable ”expr”?

> auto&& expr = klmr::lisp::read_full(begin(line), end(line));  
> if (not expr)  
> return;  
> auto&& result = eval(\*expr, global_env);  
> std::cout &lt;&lt; result &lt;&lt; '\\n';

==&gt; It seems the eval function takes the ast (expr) and the environment to evaluate the expression in?

==&gt; Note: expr is an optional&lt;value&gt;, this \*expr is the value.

==&gt; It seems expr is a value that in turn is implemented as a variant of all terminal symbols of the grammar?

==&gt; Consider a simple Meh + expresson?

Meh´&gt; (+ 1 2)

==&gt; Then the AST would be?

variant(list)

|

values = {variant(symbol), variant(literal&lt;int&gt;(1)), variant(literal&lt;int&gt;(2))}

| | |

repr(”+”) value(1) value(2)

==&gt; The AST seems to be dispatched using visitor?

> auto eval(value expr, environment& env) -&gt; value {  
> return boost::apply_visitor(eval_visitor{env}, expr);  
> }

==&gt; And the visitor aggregates the environment?

==&gt; The visitor then dispatches a value to its underlaying c++ object?

==&gt; Each dispatch returns a new value (as variant of possible terminal symbols of the grammar)?

==&gt; Dispatch of a symbol simply returns the value with that name in the environment?

> auto operator ()(symbol const& sym) const -&gt; value {  
> return **env&#91;sym&#93;**;  
> }

==&gt; For Meh operating on Tha (as environment) this would mean the Tha be able to return values in the form they are represented in the AST?

==&gt; Or, can we imagine that Meh evaluator knows how to convert Tha values into AST values?

==&gt; Note: We need type to be an AST value as it may be used in further evaluations!

...

==&gt; Dispatch of a list evaluates the first member and applies it as a function to the evaluated values of the tail?

> auto operator ()(list const& cons) const -&gt; value {  
> if (empty(cons))  
> throw invalid_node{cons, "non-empty list"};  
> auto&& call = eval(head(cons), env);  
> return boost::apply_visitor(eval_call_visitor{env, tail(cons)}, call);  
> }

==&gt; Note: The List is implemented as a ”cons” (having head and tail)

==&gt; It seems list is implemented as a std::vector&lt;value&gt; and helper functions?

> > struct list {  
> > ...  
> > std::vector&lt;value&gt; values;  
> > ...

> > };



> > inline auto **head**(list const& list) -&gt; value const& {  
> > return list.values&#91;0&#93;;  
> > }

> > inline auto **tail**(list const& list) -&gt; list::const_range {  
> > return {begin(list.values) + 1, end(list.values)};  
> > }

==&gt; It seems it is c++ type ” eval_call_visitor” that applies a function to a tail?

> struct eval_call_visitor : boost::static_visitor&lt;value&gt; {  
> environment& env;  
> list::const_range args;

> ...

  
> auto operator ()(call const& call) const -&gt; value;  
> auto operator ()(macro const& macro) const -&gt; value;  
> };

==&gt; It seems to represent function as C++ type ”call” (with member operator() )?

> auto operator ()(call const& call) const -&gt; value {  
> auto evaluated_args = std::vector&lt;value&gt;(std::distance(begin(args), end(args)));  
> std::transform(begin(args), end(args), begin(evaluated_args),  
> &#91;this&#93;(value const& v) { return eval(v, env); });  
> return call(env, begin(evaluated_args), end(evaluated_args));  
> }

==&gt; It clearly evaluates the arguments before providing them to call() (using std::transform)!

==&gt; It seems to represent macro as C++ type ”macro”?

> auto operator ()(macro const& macro) const -&gt; value {  
> return macro(env, begin(args), end(args));  
> }

==&gt; It seems the environment is a node in a linked list of environments (each environment knows about its parent)?

> struct environment {  
> environment(environment\* parent = nullptr) : parent{parent} {}

> environment(environment&, std::vector&lt;symbol&gt;, call::iterator a, call::iterator b);

> auto operator &#91;&#93;(symbol const& sym) -&gt; value&;

> auto add(symbol const& sym, value val) -&gt; void;

> friend auto parent(environment const&) -&gt; environment\*;

> private:  
> std::unordered_map&lt;symbol, value&gt; frame;  
> environment\* parent;  
> };

==&gt; It clearly maps symbols to AST values!

==&gt; It seems the environment searches its own and its parent for symbols (terminating in global environment)?

> auto environment::operator&#91;&#93;(symbol const& sym) -&gt; value& {  
> for (auto current = this; current != nullptr; current = current-&gt;parent) {  
> auto&& it = current-&gt;frame.find(sym);  
> if (it != current-&gt;frame.end())  
> return it-&gt;second;  
> }

> throw name_error{sym};  
> }

==&gt; Note: Nice construct to iterate this and parent until no parent using a for-loop!

> for (auto current = this; current != nullptr; current = current-&gt;parent)

==&gt; Will start with this and continue with parent but break on null!

...

2) Consider to understand environment handling and content using github project ”Lisp in C++” (<https://github.com/klmr/lisp.cpp>)?

==&gt; It seems to populate the global environment” with language function and macro definitions?

> env.add(symbol{"define"},  
> macro{env, {"name", "expr"}, &#91;&#93; (environment& **env**) {  
> auto&& name = as_symbol(env&#91;"name"&#93;);  
> **parent(env)-&gt;add**(name, eval(env&#91;"expr"&#93;, \*parent(env)));  
> return eval(nil, env);  
> }}  
> );

==&gt; It seems ”define” macro is defined to add a new name (identifier) into the parent environment (why)?

...

3) Consider what effects (if any) it has that the environment (Tha) is persistent?

==&gt; Consider if we get into any problems with bindings to older values when Tha gets updated?

==&gt; Consider ”bind by name” could be safer as it will bind to whatever value the name is defined as when evaluated (current Tha state)?

==&gt; Consider ”bind by name” and lazy evaluation will ensure we use current state when evaluated (not state when defined)?

==&gt; Consider if there are cases when we actually want to bind to value at definition time (not at evaluation time)?

==&gt; Consider pure functions will ensure we use values at evaluation time (provided arguments are evaluated at call time)?

==&gt; Lazy evaluation of functions ensures the arguments gets evaluated at evaluation time, not call definition time)?

...

{% endraw %}
