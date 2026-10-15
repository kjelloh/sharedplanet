# Todo: Tha - Consider we need a better name that "Identifier" for the thing that binds a name, a meta-value and a value together in the model?

```#f3cfa1ad``` *As of 2017-06-29 18:54*

[mail plain/text](mail.txt)

{% raw %}
It seems we need a better name than ”Identifier” for the thing that binds a name, a meta value and a value together as these bindings may come in almost any combination (including anonymous bindings with no names in which case it is not an ”identifier” per se)?

1) Consider the problems with the term ”Identifier”?

==&gt; Consider it is not an Identifier if it has no bound name (e.g., only a value bound to a meta-value)?

==&gt; Consider a C++ compiler still invents a name for anonymous values 8or does it not)?

==&gt; Consider in C++ unnamed values are called r-values (and they are only a value bound to a meta-value, i.e. value with a type)?

…

==&gt; Consider in pattern matching we sometimes are only interested in binding values to meta-values (we do not care about naming these bindings)?

…

2) Consider to use the term ”Frame” (as in the small C++ Lisp implementation <https://github.com/klmr/lisp.cpp>)?

==&gt; It seems ”Frame” refers to the current environment (list of name, value mappings) in the stack of environments?

> struct environment {  
> ...  
> auto operator &#91;&#93;(symbol const& sym) -&gt; value&;  
> auto add(symbol const& sym, value val) -&gt; void;  
> friend auto parent(environment const&) -&gt; environment\*;  
> private:  
> std::unordered_map&lt;symbol, value&gt; **frame**;  
> environment\* parent;  
> };

==&gt; It seems the actuals ”things” in the frame ”std::unordered_map&lt;symbol, value&gt; frame;” are not named per se (it is just a sequence of mappings from name to value)?

==&gt; Consider this clashes with Emacs Lisp that defines a ”Frame” as the Lisp object referring to the screen frame (<https://www.gnu.org/software/emacs/manual/html_node/elisp/Frames.html>)?

> ”*In Emacs Lisp, a frame object is a Lisp object that represents a frame on the screen. See Frame Type.*"

==&gt; Thus, The term ”Frame” should at least be reserved as the current top of the stack of environments with name-value mappings?

…

3) Consider our named meta-value, value ”thing” does not exist in Lisp or any other of the common programming languages (thus we need a new term for this named binding)?

==&gt; It seems in computer science a ”binding” as a way of naming ”objects” to be expressed in a computer language (<http://www.fact-index.com/b/bi/binding__computer_science_.html>)?

==&gt; As such, binding provides the menas to bind the grammar terminal symbols with run-time computations or values?

> ”*In computer science, binding is associating objects and implementations with names in programming **language** so that those objects and implementtions can be **accessed by the names**.*"

==&gt; In Common Lisp a binding is a name (symbol) bound to a value (<http://www.n-a-n-o.com/lisp/cmucl-tutorials/LISP-tutorial-11.html>)?

==&gt; It seems in Clojure a binding is also a name bound to a value (<https://clojuredocs.org/clojure.core/binding>)?

==&gt; In Clojure a declaration seems to just state the existence (forward) a name that is still NOT bound to a type (<https://clojuredocs.org/clojure.core/declare>)?

==&gt; But Clojure uses define to mean ”bind to a value, actual implementation” (<https://clojuredocs.org/clojure.core/def>)?

==&gt; It seems in C++ a declaration binds a name to a type and a definition binds a name to a value (<http://www.cprogramming.com/declare_vs_define.html>)?

> ”*Defining a function means providing a function body; defining a class means giving all of the methods of the class and the fields. Once something is defined, that also counts as declaring it; so you can often both declare and define a function, class or variable at the same time. But you don't have to.*"

==&gt; It seems in Scheme the ”name” identifies a ”variable” whose values is ”the object” (See ”Structure and Interpretation of Computer Programs” 1.1.2 Naming and the Environment)

==&gt; But Tha is a typed (meta-valued) immutable model so we ned an alternative for ”variable” and an addition to handle meta-value binding?

==&gt; In C++ it seems it is actually the ”name” that may be declared to bind to an ”entity”. Type being an entity (<http://en.cppreference.com/w/cpp/language/identifiers>)?

> ”*An **identifier** can be used to **name** objects, references, functions, enumerators, **types**, class members, namespaces, templates, template specializations, parameter packs, goto labels, and other entities*”

> ”*Every name that denotes an entity is introduced into the program by a declaration.*"

==&gt; But then C++ confuses things by stating that declarations may be definitions (<http://en.cppreference.com/w/cpp/language/declarations>)?

> ”*Declarations introduce (or re-introduce) names into the C++ program. Each kind of entity is declared differently. Definitions are declarations that are sufficient to use the entity identified by the name. *  
> *A **declaration** is one of the following:  
> *  
> *• Function **definition**  
> *  
> *• Template **declaration**  
> *  
> *• Explicit template **instantiation**  
> *  
> *• Explicit template **specialization**  
> *  
> *• Namespace **definition**  
> *  
> *• Linkage **specification**  
> *  
> *• Attribute **declaration** (attr ;) (since C++11)  
> *  
> *• Empty **declaration** (;) (since C++11)  
> *  
> *• A function **declaration** without a decl-specifier-seq:*"

==&gt; So, no help there for our Tha terminology?

4) Consider the term ”Entry”?

==&gt; Then an Environment would consist of a sequence of Entries?

==&gt; But, entries of \*what\*?

…

5) What do we now about the thing that binds a name, a meta-value and a value together as a unit?

==&gt; It seems normally we like all the three bound (naming a value as being described by its meta-value)?

==&gt; But it seems we can in special cases have meta-value bound to a value without actually having a name (anonymous or temporary values, i.e., C++ r-values)?

==&gt; It seems these ”things” are the stuff that an environment (frame) consists of?

…

6) What can we say about the ”thing” from the point of view that it is used to declare and define values?

==&gt; What is it we declare when we bind a name to a meta-value (declare a value)?

==&gt; What is it we define when we bind a name to a value (define a value)?

==&gt; Are there cases when we declare a value with no name?

==&gt; NO - We need the name to create a declaration?

==&gt; Or, in pattern matching we may infer the declared meta-value before we have a name bound to the declaration?

==&gt; Or, does the pattern require named ”things” to be able to perform the match?

==&gt; It seems the ”thing” is in fact a ”variable” (although in Tha it is immutable)?

==&gt; But then, what is an immutable Variable (a constant)?

==&gt; And what is a variable with no name (A temporary or an r-value)?

…

7) Consider the term ”Entity” (as in ”unique instance”) and term the bound values as ”objects” (<https://stackoverflow.com/questions/2550197/whats-the-difference-between-entity-and-class>)?

==&gt; Consider this means a Tha is a stack of Frames, each listing Entities that binds names to meta-objects and objects?

Value

^

|

----------------------------------

| |

Entity Object

Name Literal&lt;Text&gt; ^

Object meta-object |

Object object ------------------------

| |

Atom Composite

^ ^

| |

------------------------- --------------------------------------

| | | | | | |

Literal&lt;Double&gt; Literal&lt;Text&gt; Array Record Tuple Set Function

…

Consider to return to this todo and update it if new terms are of need to define the the Tha model?

...

{% endraw %}
