# Todo: C++ - Consider to study template specialisation to understand it better

```#27273c2c``` *As of 2016-03-17 15:00*

[mail plain/text](mail.txt)

{% raw %}
The c++ concept of template specialisation turns out to be a “language of its own” (the meta programming language mpl). Consider to grasp this concept a bit better to be able to read and use these concepts more readily in code.

1) This seem to be a good answer and input on template specialisation (<http://stackoverflow.com/questions/8061456/c-function-template-partial-specialization>)

In functional languages, selections are done using *Pattern Matching*:

```
-- An instance of Maybe is either nothing (None) or something (Just a)
-- where a is any type
data Maybe a = None | Just a

-- declare function isJust, which takes a Maybe
-- and checks whether it's None or Just
isJust :: Maybe a -> Bool

-- definition: two cases (_ is a wildcard)
isJust None = False
isJust Just _ = True
```

As you can see, we *overload* the definition of `isJust`.

==&gt; This seem to be a good model to understand what goes on in mpl in general (and in template specialisation in specific)?

2) The same answer above also talks about the order of finding a function overload and then a template match

“For template functions, specialization is somewhat more awkward: it conflicts somewhat with overload resolution. As such, it has been decided that a specialization would relate to a non-specialized version, and specializations would not be considered during overload resolution. Therefore, the algorithm for selecting the right function becomes:

• Perform overload resolution, among regular functions and non-specialized templates

• If a non-specialized template is selected, check if a specialization exist for it that would be a better match"

3) Here seems a good page explaining function templates (<http://www.gotw.ca/gotw/049.htm>)

4) Actually, Herb Sutter seems like a guy to turn to for explanation about c++ stuff (<http://www.gotw.ca>)?

5) Consider to study this Peter Sommerland talk about variadic and variable templates (<https://www.youtube.com/watch?v=ltfmBUAmePE>)?

==&gt; At 5:00

==&gt; “plain” Functions are matched using argument type matching (problem of imbuigity for multiple “equally good” matches)

==&gt; Function templates are resolved using the function parameter types (no need to provide template parameters at function call)

==&gt; Class templates are “resolved” using template parameter matching.

==&gt; Class templates can be partially specialised - Function templates can not.

==&gt; In Metaprogramming the template partial specialisation is the “if” or the “switch”.

==&gt; A Variadic Template Function is a function that depends on a variadic number of template parameters.

template &lt;typename …ARGS&gt;  // (1) …ARGS

void variadic(ARGS…args) { // (2) ARGS…args

println(std::cout,args…) // (3) args...

}

1. Ellipsis symbol prefixing a name defines the name as a placeholder for a variable number of elelements (a Parameter Pack)

2. Ellipsis used between two names defines the second one as a list-of-parameters given by the first name.

3. Ellipsis used after a pack-name (or expression with pack name) expands the name into a comma separated list of parameters (Pack Extension)

==&gt; sizeof…(pack) yields the count of parameters in pack.

==&gt; At 8:00

==&gt; Variadic template functions must be implemented using compile-time recursion.

==&gt; No Template parameter and single function parameter base case (termination specialisation handling no data, i.e. does not recurse)

==&gt; Type + Type Parameter Pack template function that process head and recurse on tail parameter pack.

// Non-template argument base-case (stops recursion)

void **println**(std::stream& out) {

our &lt;&lt; “\\n”; // end recursion with new-line.

}

// Recursive template function taking Head type and Tail Type Pack.

template &lt;typename Head, typename… Tail&gt;

void **println**(std::stream& out, Head const& head, Tail const& …tail) {

our &lt;&lt; head; // process head

if (sizeof…(tail) &gt; 0) {

out &lt;&lt; “, “; // add separator before next element

}

**println**(out,tail…); // recurse using unpacked tail (head removed)

}

==&gt; Own note: Template functions cant be partially specialised. Thus the base case must always be a non-template function?

==&gt; At 9:20 he shows a cool feature showing a (Strongly Connected Component, SCC?) graph of the generated println?

==&gt; It seem to be the Eclipse/Cevelop plug-in demonstrated intros youtube clip (<https://www.youtube.com/watch?v=iRsTR9SsqmA>)?

==&gt; Peter Sommerland seem to demo this tool here (<https://channel9.msdn.com/Events/CPP/CppCon-2015/CPPConD02V008>)?

==&gt; Still no publicly available version of Templator (as of Cppcon 2015)?

==&gt; He seem to state that Cevelop and Templator plug-in is developed as university/student projects?

==&gt; Cevelop seem to be part of an EU-funded project called REPARA (<http://repara-project.eu/?page_id=248>)?

“co-funded by the European Commission within the Seventh Framework Programme"

==&gt; Very cool! Where can I get it?

==&gt; He states it is a feature not yet in Cedevelop (is he using a Cedevelop Beta?)

==&gt; Or is he using some other tool?

==&gt; LLVM seem to talk about SCC as part of the “Writing an LLVM Pass”” (<http://llvm.org/docs/WritingAnLLVMPass.html>)?

==&gt; LLVM seem to apply (refer to) Tarjans SCC Algorithm defined here ([https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm](https://en.wikipedia.org/wiki/Tarjan's_strongly_connected_components_algorithm))?

“The algorithm takes a directed graph as input, and produces a partition of the graph's vertices into the graph's strongly connected components”

==&gt; It seems a group of nodes that is “closed” in that they refer to no nodes outside the group forms a strongly connected component See animation on wikipedia page)?

==&gt; The tool he shows seem to show each println-instance as an SCC and is able to show how each links “recurse” to the next?

==&gt; Side-noet: Boost seem to provide an SCC algorithm in the Graph library (<http://www.boost.org/doc/libs/1_57_0/libs/graph/doc/strong_components.html>)?

==&gt; At 15:30 he starts talking about Template Classes

==&gt; std::tupe is about passing variadic members as type packs.

==&gt; At 20:10 he mentions Template template parameters.

==&gt; Template template parameters seem to be defined here (<http://stackoverflow.com/tags/template-templates/info>)?

==&gt; Key thing is that we are allowed to define template parameters to be types, non-types (scalars?) and templates?

A C++ template can have parameters which are types (such as int), non-types (such as the integer 2) or templates. The latter are called template template parameters.

For example this class template has a template template parameter called Templ and a template type parameter called Type:

template&lt;template&lt;typename&gt; class Templ, typename Type&gt;

struct Apply

{

typedef Templ&lt;Type&gt; type;

};

To instantiate the class template Apply the argument substituted for Templ must be the name of a class template or alias template taking a single type parameter e.g.

Apply&lt;std::shared_ptr, int&gt;::type ptr;

The nested typedef type is a synonym for std::shared_ptr&lt;int&gt;.  
==&gt; Note that the template (not type) std::shared_ptr is passed as template parameter!

6) Consider to study and understand the ellipsis as the C++ ellipsis operator?

This seem to be the standard defining Parameter Packs (<http://en.cppreference.com/w/cpp/language/parameter_pack>)

“A *template parameter pack* is a template parameter that accepts zero or more template arguments (non-types, types, or templates). A *function parameter pack* is a function parameter that accepts zero or more function arguments. A template with at least one parameter pack is called a *variadic template*."

==&gt; The ellipsis symbol is used to *Define* parameter pack and *Expand* parameter pack.

==&gt; Parameter Packs may be defined as compile-time “Type Packs” (Template Parameter Pack) or runtime function parameter pack.

template &lt;typename … Types&gt; struct myStruct {};

template &lt;typename … Types&gt; void myFunction(Types … args);

==&gt; “typename … Types” defines a compile-time type parameter pack and “Types … args” defines a runtime function parameter pack args.

==&gt; It seems the pattern… may be seen as a “expand pattern” operator used at compile time?

==&gt; typename…Types // “Expands” provided variadic number of types into a Type Parameter Pack named Types?

==&gt; Types…args // “Expands” provided parameter Pack Types into runtime-parameters args.

==&gt; The compiler matches the “call” and “Expands” provided variadic number of parameters into a comma-separated-list representation of the Parameter Pack?

==&gt; “template&lt;typename … Types&gt; struct myT {}” called with myT&lt;int,int&gt; is “Expanded” by the compiler to instantiate specialisation template&lt;&gt; myT&lt;int,int&gt; struct {}?

==&gt; “template&lt;typename … Types&gt; void myF(Types … args)” called with myF(a,ib) is “Expanded” by the compiler to instantiate specialisation myF&lt;int,int&gt;(a,b) is a and b are ints?

> > ```
> > template<class ...Us> void f(Us... pargs) {}
> > ```

  
> > ```
> > template<class ...Ts> void g(Ts... args) {
> > ```

  
> > ```
> >     f(&args...); // “&args...” is a pack expansion
> > ```

  
> > ```
> >                  // “&args” is its pattern
> > ```

  
> > ```
> > }
> > ```

  
> > ```
> > g(1, 0.2, "a"); // Ts... args expand to int E1, double E2, const char* E3
> > ```

  
> > ```
> >                 // &args... expands to &E1, &E2, &E3
> > ```

  
> > ```
> >                 // Us... pargs expand to int* E1, double* E2, const char** E3
> > ```



> > ```
> > template<typename...> struct Tuple {};
> > ```

  
> > ```
> > template<typename T1, typename T2> struct Pair {};
> > ```

  
> > ```
> >  
> > ```

  
> > ```
> > template<class ...Args1> struct zip {
> > ```

  
> > ```
> >     template<class ...Args2> struct with {
> > ```

  
> > ```
> >         typedef Tuple<Pair<Args1, Args2>...> type;
> > ```

  
> > ```
> > //        Pair<Args1, Args2>... is the pack expansion
> > ```

  
> > ```
> > //        Pair<Args1, Args2> is the pattern
> > ```

  
> > ```
> >     };
> > ```

  
> > ```
> > };
> > ```

  
> > ```
> >  
> > ```

  
> > ```
> > typedef zip<short, int>::with<unsigned short, unsigned>::type T1;
> > ```

  
> > ```
> > // Pair<Args1, Args2>... expands to
> > ```

  
> > ```
> > // Pair<short, unsigned short>, Pair<int, unsigned int>
> > ```

  
> > ```
> > // T1 is Tuple<Pair<short, unsigned short>, Pair<int, unsigned>>
> > ```



This seem like a good reference page on the ellipsis symbol (<http://www.cplusplus.com/articles/EhvU7k9E/>)?

==&gt; In C the ellipsis symbol (…) may be uses to declare a variable number of function parameters or variable number of pre-processor macro arguments.

void printf(const char\* format,…)

#define MY_MACRO(…)

==&gt; In C++ the ellipsis symbol may be used as the ellipsis-operator

==&gt; catch(…) // catch anything

...

…

Consider to find more clues into how to imagine and understand this mechanism?

{% endraw %}
