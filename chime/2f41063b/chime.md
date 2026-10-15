# Todo: Meta Value Model - It seems to parse and evaluate Meh expressions I really need to get a grip on s-expressions explicitly and grammar parsing i general?

```#2f41063b``` *As of 2017-06-17 20:44*

[mail plain/text](mail.txt)

{% raw %}
At this stage I need a small stable and sufficient s-expression parser and Meh lisp-like evaluator to get the Meh Repl going and it seems I need to understand parsing and evaluation of lisp-like languages better to implement this?

==&gt; Also see ”[Todo: Meta Value Model - Consider to try implementing Meh parser using C++ Boost Spirit Qi grammar library (Or newer Boost X3)?](../a24d878f/chime.md)"

1) Consider to use (Extended) Backhaus-Naur Form ((E)BNF) to express Meh syntax (<https://en.wikipedia.org/wiki/Extended_Backus–Naur_form>)?

==&gt; It seems the most compact definition of a grammar is A grammar is formally defined as the ordered quadruple &lt;N, ∑, P, S&gt;?

==&gt; N is the set of non-terminal symbols, also called syntactic variables (symbols used in production rules to express recursive decomposition)?

==&gt; Thus, these symbols change with the grammar (production rules) of the grammar?

==&gt; And, they DO NOT appear in the output of the grammar production?

==&gt; ∑ is the set of terminal symbols (symbols, or literals, that appear in the output of the grammar production)

==&gt; These symbols have meaning in the grammar (takes part in evaluation of grammar expressions)?

==&gt; P is the set of production rules specifying how sequence of symbols break down into text containing only terminal symbols?

==&gt; P: (N∪∑)\*N(N∪∑)\* -&gt; (N∪∑)\*

==&gt; Which reads (right hand side) ”one or more symbols” is (left hand side) ”one or more symbols” followed by "any non-terminal symbol” followed by ”one or more symbols”

==&gt; Thus, the production rules seems to define how well formed strings are produced in the grammar (not how strings are parsed)?

==&gt; But, parsing strings are just application of the production rules ”in reverse” (parsed string is well formed if it may be produced by the grammar rules)?

==&gt; S is the starting terminal symbol

==&gt; There seems ISO EBNF standard ISO/IEC 14977 defines a small set of

==&gt; It seems Lisp requires EBNF to be expressed?

==&gt; Consider general s-expression in BNF (<http://matt.might.net/articles/parsing-s-expressions-scala/>)?

> ### Minimalist S-Expressions

> The grammar for the simplified dialect of S-Expressions in this post is:

> ```
>   <file> ::= <s-exp-list>

>   <s-exp> ::= <atom>
>            |  '(' <s-exp-list> ')'

>   <s-exp-list> ::= <sexp> <s-exp-list>
>                 |

>   <atom> ::= <symbol>
>           |  <integer>
>           |  #t  |  #f
> ```

  
==&gt; It seems &lt;file&gt; is our start symbol S?

==&gt; Recursion is &lt;s-exp-list&gt; is ”token” (s_exp) followed by remaining s-exp-list (in fact head,tail decomposition)?

==&gt; A ”token” s-exp is either an &lt;atom&gt; or framed s-exp-list (framed with ’(’,’)’)?

==&gt; Finally &lt;atom&gt; is a symbol (identifier), an integer or # or #t (whatever those last ones are)?

2) It seems we may model parsing as ”inferring” an AST value from AST pattern (the grammar production rules) from provided text?

==&gt; Consider that the production rules of a grammar in effect specify patterns?

==&gt; Thus, if we can express the grammar production rules as meta-value patterns we can apply Meta Value Model inference rules to instantiate AST values from text?

meta-2: AST&lt;2&gt; = Set of {…any AST&lt;1&gt; value…}

meta-1: Meh = AST&lt;2&gt;.as_function(meta-1 values defining production rules = patterns)?

Meh.as_function = matcher. creates AST&lt;0&gt; value from provided meta-0 Text value

meta-0: ast = produced instance of meta-value Meh from provided meta-0 Text (the expression to parse)?

2) It seems Lisp is an example a language based on s-expressions?

==&gt; True s-expressions seem to be a representation of List (head,tail) trees (<https://en.wikipedia.org/wiki/S-expression>)

> ” ...In the usual parenthesized syntax of Lisp, an s-expression is classically defined as  
> 1. an atom, or  
> 2. an expression of the form (x . y) where x and y are s-expressions.

> "

==&gt; s-expressions are thus in effect binary trees (nodes are atom,list pairs)?

![](<s-expression example AST.tiff>)

**==&gt; Note how left member are always an atom?**

==&gt; This seem to give a short clear answer to s-expressions and its relation to Lisp /<https://www.computerhope.com/jargon/s/s-expression.htm>)?

> ”*An s-expression, also known as a sexpr or sexp, is a way to represent a nested list of data. It stands for "symbolic expression”...*"

==&gt; This blog post seem to be about s-expresiions as data model realting it to alternatives like XML (<https://igor.io/2012/12/06/sexpr.html>)?

> ”"

==&gt; The ”cons” operation seems central to create cells {car,cdr} to represent linked Lists (<https://en.wikipedia.org/wiki/Cons>)?

![](<Lisp linked list of Cons Cells Example.tiff>)

2) Consider to model the Meh syntax in a Meta Value Model?

==&gt; Consider to base this model on a model of Lisp s-expressions?

...

3) It seems it could prove valuable to write Meh meta-circual (in Meh) just as Lisp can be written in Lisp (<https://igor.io/2013/04/03/sexpr-meta-eval.html>)?

==&gt; The original Lisp seems to be based on a very small set of primitive operators (functions)?

> The original Lisp consists of seven primitive operators:

-

>   **(quote x)**: Quotes a value. `'foo` is a shortcut for `(quote foo)`.

-

>   **(atom? x)**: Checks if a value is an atom. `(atom? (quote foo))` returns `true`.

-

>   **(eq? x y)**: Checks if two values are equal.

-

>   **(car x)**: Returns the first element of the list `x`.

-

>   **(cdr x)**: Returns the rest of the list `x` (everything but the first element).

-

>   **(cons x y)**: Constructs a list by prepending `x` to the list `y`.

> `(cons (quote foo) (quote (bar)))` returns the list `(foo bar)`.

- **(cond (p1 e1) ... (pn en))**: Conditional execution. Takes a list of pairs.

> The first element of each pair is a predicate, the second is an expression. If the predicate evaluates to `true`, the expression is evaluated and its return value returned. If the predicate evaluates to `false`, the next predicate is checked.



==&gt; Consider this Lisp evaluator written in Lisp?

> ```
> (defun null. (x)
>   (eq x '()))

> (defun and. (x y)
>   (cond (x (cond (y 't) ('t '())))
>         ('t '())))

> (defun not. (x)
>   (cond (x '())
>         ('t 't)))

> (defun append. (x y)
>   (cond ((null. x) y)
>         ('t (cons (car x) (append. (cdr x) y)))))

> (defun list. (x y)
>   (cons x (cons y '())))

> (defun pair. (x y)
>   (cond ((and. (null. x) (null. y)) '())
>         ((and. (not. (atom x)) (not. (atom y)))
>          (cons (list. (car x) (car y))
>                (pair. (cdr x) (cdr y))))))

> (defun assoc. (x y)
>   (cond ((eq (caar y) x) (cadar y))
>         ('t (assoc. x (cdr y)))))

> (defun eval. (e a)
>   (cond
>     ((atom e) (assoc. e a))
>     ((atom (car e))
>      (cond
>        ((eq (car e) 'quote) (cadr e))
>        ((eq (car e) 'atom)  (atom   (eval. (cadr e) a)))
>        ((eq (car e) 'eq)    (eq     (eval. (cadr e) a)
>                                     (eval. (caddr e) a)))
>        ((eq (car e) 'car)   (car    (eval. (cadr e) a)))
>        ((eq (car e) 'cdr)   (cdr    (eval. (cadr e) a)))
>        ((eq (car e) 'cons)  (cons   (eval. (cadr e) a)
>                                     (eval. (caddr e) a)))
>        ((eq (car e) 'cond)  (evcon. (cdr e) a))
>        ('t (eval. (cons (assoc. (car e) a)
>                         (cdr e))
>                   a))))
>     ((eq (caar e) 'label)
>      (eval. (cons (caddar e) (cdr e))
>             (cons (list. (cadar e) (car e)) a)))
>     ((eq (caar e) 'lambda)
>      (eval. (caddar e)
>             (append. (pair. (cadar e) (evlis. (cdr e) a))
>                      a)))))

> (defun evcon. (c a)
>   (cond ((eval. (caar c) a)
>          (eval. (cadar c) a))
>         ('t (evcon. (cdr c) a))))

> (defun evlis. (m a)
>   (cond ((null. m) '())
>         ('t (cons (eval.  (car m) a)
>                   (evlis. (cdr m) a)))))
> ```

  
…

Consider to delve deeper into the field of s-expressions and grammar parsing as I see fit to get the knowledge and clues I need for a Meh parse and evaluate system?

...

{% endraw %}
