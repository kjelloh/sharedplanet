# Todo: Tha meta-value stack - Consider "namespace" is meta-4 level that defines a Set of Kinds?

```#65aa532a``` *As of 2017-08-09 12:26*

[mail plain/text](mail.txt)

{% raw %}
Could it be that in fact the Tha meta-value level 4 is namespaces that defines Sets of Kinds?

-1) It seems NO, meta-value level 4 (kind of kinds) are not namespaces?

==&gt; A namespace seems to be a list of bindings between any level?

==&gt; Thus, an environment doe not “exist” on any specific level but spans all levels?

==&gt; An a namespace is about membership (declared) and accessibility (private/public) of bindings?

==&gt; Also, “template” is a meta-4 value (able to instantiate kind-functions, type-functions and value-functions)?

**==&gt; Bottom line - meta-level 4 (kind of kinds) are NOT namespaces (and kinds are not namespace instances)?**

...

1) Consider the Tha meta-value stack having namespaces as level 4?

==&gt; Consider the basic model of meta-value bindings on stacked level?

> namespace: name ----&gt; Set {kind, kind, kind,...}  
> kind: name ----&gt; Set {type, type, type,...}  
> type: name ----&gt; Set {value, value, value,...}  
> value: name ----&gt; Set {exe, exe, exe, ...}

==&gt; And the bindings are {name, meta-name, data\*}

> namespace: name ----&gt; Set {kind, kind, kind,…}  
> ^ |  
> | -------  
> | |  
> | v  
> kind: name ----&gt; Set {type, type, type,...}  
> ^ |  
> | -------  
> | |  
> | v  
> type: name ----&gt; Set {value, value, value,...}  
> ^ |  
> | -------  
> | |  
> | v  
> value: name ----&gt; Set {exe, exe, exe, ...}  
> ^ |  
> | -------  
> | |  
> | v

==&gt; Consider what we mean when we say a kind is a namespace instance?

==&gt; Consider the struct kind is a namespace with bindings that are by default public?

> > struct = namespace {“struct”}; // struct is a namespace instance?

==&gt; Hm… No, struct is a namespace kind specialisation (NOT a namespace instance)?

> > kind struct : public namespace {  
> > // struct is a specialised namespace?  
> > }

==&gt; Or, is struct a namespace instance (NOT a namespace kind specialisation)?

...

==&gt; Consider what we can do if kind is a namespace instance (as opposed to if namespace is a kind we can specialise)?

==&gt; With kind as namespace instantiation we can streamline the instance (we do not need to find a common base namespace)?

==&gt; A class and struct namespace instance contains constructor to create class and struct types.

==&gt; A C++ “namespace” is a kind that defines a type that can NOT be instantiated as a value.

2) Consider what it means that a namespace instance is in fact a Set of bindings?

==&gt; Consider a binding as {defacto_name, meta_name, value&}?

> meta: **name**  
> **^**  
> **|**  
> **|**  
> **|**  
> defacto: **name** **----&gt;** value = Set {type, type, type,...}

==&gt; So there are namespace instances on each meta-value level (defining bindings on that level)?

==&gt; Hm… are there kinds that is NOT a namespace instance?

==&gt; What about C++ template kinds (are they all namespace instances)?

==&gt; A class template is a namespace instance (a parametrised class kind)?

==&gt; A function template is a namespace instance (a parametrised function namespace kind)?

==&gt; An alias template is NOT a namespace instance (or is it)?

> > template &lt;typename.. Args&gt;  
> > using my_name = other_template_name&lt;Args…&gt;;

==&gt; It seems this names a kind (“my_name”) to a “function value” (with template arguments being types)?

==&gt; So, a C++ template instance is a kind-function with types as arguments?

==&gt; And an alias template is also a kind-function bound to kind-function?

...

3) Consider to what degree a function is a composition of statements (expressions) that can have meaning on different Tha meta-value levels?

==&gt; Consider the “normal” function (as in C++)?

> // Enclosing environment...  
> int k = 4;  
> ...  
> int f(int x) {  
> // f environment  
> return x\*x + k; // use k captured from enclosing environment  
> }

==&gt; The function declaration seems to define an environment in which the argument names are bound to meta-vales)?

> int f(int x); // f declaration

> // Tha model  
> kind: “_” ----&gt; Set {}  
> type: “_” ----&gt; {int, {int x}} // return type and environment with argument bindings  
> value: “f” ----&gt; null // “f” declared but not defined = no body

==&gt; The function call seems to bind provided names to argument names?

> void main() {  
> // calling environment…  
> int a = 17;  
> int y = f(a); // call to f  
> }

> // Tha model  
> value: “main” ----&gt; scope

4) Consider how we can model nested environments, scopes and namespaces in Tha?

==&gt; Consider environment, scope, namespace concepts?

> **environment** = stack&lt;scope&gt; // An environment is a scope stack (inner specialise outer)?  
> **scope** = set&lt;namespace&gt; // A scope is a set of namespaces (overlapping names not allowed)  
> **namespace** = list&lt;binding&gt; // a namespace is a list bindings (defacto_name, meta_name, value&)

==&gt; Now, this would mean an *environment would span all meta-value levels* (bindings exist between all meta-value levels)?

==&gt; Then, how can we call meta-value level 4 for namespaces (and a namespace instance is a kind)?

**WE ARE HERE...**

5) Consider the C++ type systems in Tha meta-value stack model?

==&gt; Consider the C++-defined namespaces, kinds, types and values?

> namespace: “_" ----&gt; Set {struct, class, union, enum, array, function,...}  
> kind: “struct" ----&gt; Set {...}  
> “class" ----&gt; Set {...}  
> “union" ----&gt; Set {...}  
> “enum" ----&gt; Set {...}  
> “array" ----&gt; Set {...}  
> “function" ----&gt; Set {...}  
> ...  
> type: “bool" ----&gt; Set {true, false}  
> “int” ----&gt; Set {...}  
> “char” ----&gt; Set {…}  
> ...

> value: “true" ----&gt; Set {...}  
> “false” ----&gt; Set {...}

==&gt; Consider the struct namespace to have default public member bindings?

…

Consider to delve deeper into how we relate the concepts of environment, namespace and scope to the Tha model and what the f\*ck meta-value level 4 (kind of kinds) should be called?

...

{% endraw %}
