# Todo: Programming - Consider to compare my Meta Value Levels model of C++ with the standard Reflection Proposal?

```#267b326a``` *As of 2017-05-29 16:42*

[mail plain/text](mail.txt)

{% raw %}
Could it be interesting to compare my own Meta Value Levels model of C++ with the C++ Standard committee Reflection proposal?

1) The latest proposal seems to be ” p0385r1” and live here (<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0385r1.pdf>)?

2) It seems t could prove valuable to try and propose the Meta Value levels approach instead of the new Syntax for the Meta Class (Viewing Meta Class) as just a new level above templates)?

==&gt; Could we infer that the Meta Class is to be able to reflect both Values, Types and Templates?

==&gt; Thus, the proposals talk about namespaces and typedefs not being ”reflectable” cvan instead be stated that typedefs and namespaces are in fact aliases (not meta values)?

…

3) Consider to try out the meta {} scoping approach as a possible C++ meta value scoping syntax?

==&gt; Consider {} would remain as ordinary value-sematics for C++ values (functions being regarded as values)?

==&gt; Consider meta { &lt;meta-scope&gt; } would define value semantics in meta-scope for types?

meta {

// At the meta-level values are Meta-values (i.e., types)

// A function returns types

meta-value f(meta-value t1, meta-value t2) {

return struct { t1 member1; t2 member 2;};

}

// Re-use existing C++ syntax (but allow calling meta-functions)

using type2 = f(int, std::string); // type2 is now struct {int member1; std::string member2;};

}

==&gt; Consider meta::meta { &lt;meta-meta-scope&gt; } would define value semantics for templates in meta-meta-scope?

meta::meta {

// meta-meta values are meta-types (i.e., more or less C++ templates)

meta-type f(meta-type t1, meta-type t2) {

return template &lt;typename T&gt; struct { t1&lt;T&gt; member 1; t2&lt;T&gt; member 2;}

}

// re-use value-sematic syntax but use meta-meta-values (i.e., templates)

auto myTemplate = f(std::vector, std::optional); // myTemplate is now template&lt;typename T&gt; struct {std::vetor&lt;T&gt; member 1; std::optional&lt;T&gt; member2;}

}

4) Consider what C++ syntax that may be replaced with re-used ordinary syntax but for Meta-level?

==&gt; Consider decltype(&lt;value expression&gt;) can be written as meta(&lt;value-expression&gt;) (i.e., get the Meta-value of the expression result)

==&gt; From this follows that meta(&lt;type expression&gt;) is a Meta-type (and we can defined C++ Meta-type members like if (meta(&lt;type expression&gt;) == std::vector))?

==&gt; Consider what Meta-type data we may be interested in?

==&gt; Note that it is the Meta-value that defines a variable size in memory and other type-related information!

==&gt; Meta-types are ”about types” and are in a way traits for Type-constructors (e.g., template name if created from template)?

...

==&gt; Consider how we can use Meta-value syntax to replace declval?

==&gt; Consider declval(&lt;type member value expression&gt;) is used to get a Reference Type to a types member (i.e., query for a member type of another type)?

==&gt; Consider the example (<http://en.cppreference.com/w/cpp/utility/declval>)

> > ```
> > struct NonDefault
> > {
> >     NonDefault(const NonDefault&) { }
> >     int foo() const { return 1; }
> > };
> >  
> > int main()
> > {
> > //  decltype(NonDefault().foo()) n2 = n1;               // error: no default constructor
> >     decltype(std::declval<NonDefault>().foo()) n2 = n1; // type of n2 is int
> >     std::cout<http://en.cppreference.com/w/cpp/io/cout> << "n1 = " << n1 << '\n'
> >               << "n2 = " << n2 << '\n';
> > }
> > ```



==&gt; Consider decltype(std::declval&lt;NonDefault&gt;().foo()) can be written as meta(NonDefault::foo).value_type (i.e., the type of the value returned by function foo)?

...

…

Consider to delve into this idea to allow C++ scoping on Meta-value levels and re-use ordinary C++ syntax on Meta-levels?

...

{% endraw %}
