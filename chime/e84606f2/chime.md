# Todo: Lisp - Consider to really understand the basic Lisp syntax and evaluation rules of Lisp expressions as base of our Meh (Meta Lisp) Repl?

```#e84606f2``` *As of 2017-06-15 13:44*

[mail plain/text](mail.txt)

{% raw %}
It seems like a good idea to really get down and understand the syntax of Lisp expressions and the terms used to define those expressions?

1) Consider this article ”(How to Write a (Lisp) Interpreter (in Python))” by Peter Norvig (<http://norvig.com/lispy.html>)?

==&gt; It emphases on the simplicity of Scheme?

> ”The beauty of Scheme is that the full language only needs 5 keywords and 8 syntactic forms."

==&gt; It seems to define read-and-evaluate in a clean way using **parse** and then **eval**?

> program ➡ parse ➡ abstract syntax tree ➡ eval ➡ result

program: The source code in Lisp grammar

abstract syntax tree: Also called AST. An internal tree representation of the program

result: The result of evaluating the AST

==&gt; It seems the AST is an expression which is a composite of expressions?

==&gt; Combined with a good example of what these steps involve?

> ```
> >> program = "(begin (define r 10) (* pi (* r r)))"

> >>> parse(program)  
> ['begin', ['define', 'r', 10], ['*', 'pi', ['*', 'r', 'r']]]

> >>> eval(parse(program))  
> 314.1592653589793
> ```

  
==&gt; Here (in python syntax) the AST is a list of lists (&#91;&#93; enclosed) and sequences (comma ’,’ separated)?

==&gt; It seems parsing generates an AST in two steps (lexical analysis ==&gt; &#91;token&#93;) and syntactic analysis =&gt; AST of tokens)?

> ”*Parsing is traditionally separated into two parts: lexical analysis, in which the input character string is broken up into a sequence of tokens, and syntactic analysis, in which the tokens are assembled into an abstract syntax tree.*"

==&gt; There are only **three Lisp tokens** (Parenthese, Symbol and Number)?

> ”The Lispy tokens are parentheses, symbols, and numbers"

==&gt; The Python parser in this article tokenize by adding spaces around each parentesis and then split on space?

==&gt; It seems we should then accomplish the same in C++ by using a boost::tokenizer with appropriate separator (<http://www.boost.org/doc/libs/1_60_0/libs/tokenizer/introduc.htm>)?

boost::char_separator&lt;char&gt; sep("-;|”); // Use ’-’,’;’ and ’|’ as token separators skipped in oputput

boost::char_separator&lt;char&gt; sep("-;", "|", boost::keep_empty_tokens); // Use token separators ’-’,’;’ skpped and ’|’ kept in oputput

==&gt; It seems we need to define our own TokenizerFunction concept to match paren-encolosed tokes (<https://stackoverflow.com/questions/9383749/boost-tokenizer-for-quotation-marks-and-parentheses>)?

==&gt; The TokenizerConcept seems to be defined here (<http://www.boost.org/doc/libs/1_48_0/libs/tokenizer/tokenizerfunction.htm>)?

==&gt; It seems for Lisp we want to keep ’”()” and skip ’ ’ when separating tokens (to be able to detect list tokens)?

==&gt; It seems parse is implemented using **tokenize** ==&gt; &#91;token&#93; and then **read_from_tokens** =&gt; AST

> ”*Our function parse will take a string representation of a program as input, call tokenize to get a list of tokens, and then call read_from_tokens to assemble an abstract syntax tree*"

==&gt; Now token = List (’(’&lt;characters&gt;’)’) or Atom (&lt;characters&gt;)

...

==&gt; Evaluation of AST seems to be performed by **eval** and requires an environment (**env**) in which to perform the evaluation?

> ”*The function eval takes two arguments: an expression, x, that we want to evaluate, and an environment, env, in which to evaluate it*"

==&gt; It seems environment is where names are bound to values?

> ”*An environment is a mapping from variable names to their values*"

environment := List of &#91;name, value&#93;

==&gt; This would mean for Meh the environment is our Meta Value Model and the mapping is implemented as Identifier values?

meh_environment := Meta Value Model

Meta Value Model := List of Identifier

**Q: In Meh Only Identifiers ”survive” (any unbound value or meta-value are temporaries and gets garbage collected when freed)?**

==&gt; This article Scheme implementation populates the global environment wth a small set of symbols

> ```
>         '+':op.add, '-':op.sub, '*':op.mul, '/':op.div,  
>         '>':op.gt, '<':op.lt, '>=':op.ge, '<=':op.le, '=':op.eq,  
>         'abs':     abs,  
>         'append':  op.add,    
>         'apply':   apply,  
>         'begin':   lambda *x: x[-1],  
>         'car':     lambda x: x[0],  
>         'cdr':     lambda x: x[1:],  
>         'cons':    lambda x,y: [x] + y,  
>         'eq?':     op.is_,  
>         'equal?':  op.eq,  
>         'length':  len,  
>         'list':    lambda *x: list(x),  
>         'list?':   lambda x: isinstance(x,list),  
>         'map':     map,  
>         'max':     max,  
>         'min':     min,  
>         'not':     op.not_,  
>         'null?':   lambda x: x == [],  
>         'number?': lambda x: isinstance(x, Number),    
>         'procedure?': callable,  
>         'round':   round,  
>         'symbol?': lambda x: isinstance(x, Symbol),

> ```



==&gt; It seems some basic symbols of List is NOT implemented as member functions of the global environment (why)?

> ```
> def eval(x, env=global_env):  
>     "Evaluate an expression in an environment."  
>     if isinstance(x, Symbol):      # variable reference  
>         return env[x]  
>     elif not isinstance(x, List):  # constant literal  
>         return x                  
>     elif x[0] == 'if':             # conditional  
>         (_, test, conseq, alt) = x  
>         exp = (conseq if eval(test, env) else alt)  
>         return eval(exp, env)  
>     elif x[0] == 'define':         # definition  
>         (_, var, exp) = x  
>         env[var] = eval(exp, env)  
>     else:                          # procedure call  
>         proc = eval(x[0], env)  
>         args = [eval(arg, env) for arg in x[1:]]  
>         return proc(*args)
> ```



A Constant Literal is explicitly treated by eval

”if” is a special keyword (explicitly interpreted by eval)

”define” is a special keyword (explicitly interpreted by eval)

Apart from that x is evaluated as_value or as_function (referred to as proc)

==&gt; Consider what changes for Meh evaluation due to ALL values having as_value, as_function defined?

==&gt; We don’t need ”defn”?

Meh&gt; (**function** (**list** *argument-identifiers*) (**quote** *function-expression*)) // defines a generic function value (argument-identifiers not bound to anything = generic)

...

==&gt; At this stage we still have NOT implemented the Repl?

> eval(parse("(define r 10)”)) // parse and eval expression "(define r 10)”

==&gt; Se we need the Repl to implicitly **assume (eval (parse(read)))** (where read gets a string input from the console)?

2) Consider to study this implementation of Scheme in 90 lines of C++ (<https://gist.github.com/ofan/721464>)?

==&gt; Consider to compare terms used in this code with those in other Lisp syntax descriptions?

...

3) Consider in what way Meh is even simpler than Scheme in that it applies the all-things-meta-value idiom?

==&gt; In Meh we don’t need ”defn”?

==&gt; In Meh functions are meta-values just as any other value?

Meh&gt; (**function** (**list** *argument-identifiers*) (**quote** *function-expression*)) // defines a generic function value (argument-identifiers not bound to anything = generic)

Meh&gt; (identifier square (**function** (**list** (**identifier** x)) (**quote (quote** (\* x x)))) // declares square as generic function

Meh&gt; (square (x int)) // instantiates square for int (return value inferred from instantiated function body meta-value)?

Meh&gt; (square (x double)) // instantiates square for double (return value inferred from instantiated function body meta-value)?

Meh&gt; (square 5) // Applies square to 5 (dispatches to square(int))?

Q: How can we dispatch (square (x int)) to generic instantiation and (square 5) to generic call?

==&gt; Consider generic function call would instantiate generic function from inferred argument types (C++ template style)?

Meh&gt; (square 5) // would infer argument x to be int and instantiate square&lt;int&gt; and call square&lt;int&gt;(5)?

...

==&gt; In Meh we don’t need ”lambda”

==&gt; In Meg we have meta-1 ”function”?

Meh&gt; (**function** (**list** *argument-identifiers*) (**quote** *function-expression*)) // defines a generic function value (argument-identifiers not bound to anything = generic)

==&gt; In Meh We don’t need set! ?

(set! var exp) // set variable named ”var” to evaluation result of expression

==&gt; In Meh we re-define Identifiers (we have no variables, only immutable values)

Meh&gt; (var exp) // Identifier ”var” will have as_function to mean ”define me” to provided value (the evaluation of expression)

…

…

Consider to delve deeper into Lisp syntax evaluation as a base for implementing our Meta Lisp (Meh) evaluator?

...

{% endraw %}
