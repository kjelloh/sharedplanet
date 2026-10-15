# Todo: Tha in C++ - Consider we can implement Tha meta-value stack in C++ by "laying it down" (each meta-value layer becomes a C++ value, types, kind, template stack)?

```#4cab98ed``` *As of 2017-08-12 20:26*

[mail plain/text](mail.txt)

{% raw %}
Can we imagine that implementing Tha meta-value stack in C++ by imagine “last it down” so that each meta-value later becomes C++ value, type, kinds and template stacks?

1) Consider the Tha meta-value stack plus the Binding Set?

==&gt; Consider the Tha meta-value stack?

> meta-4 (kinds-of-kinds) : (meta-4-values, meta-4-operations)  
> meta-3 (kinds) : (meta-3-values, meta-3-operations)  
> meta-2 (types) : (meta-2-values, meta-2-operations)  
> meta-1 (values) : (meta-1-values, meta-1-operations)  
> ^  
> |  
> **Tha Stack**

==&gt; Consider the Tha Binding Set?

> Binding: { Name x Name x Value } // All triplets of (name, name,value)

==&gt; Consider in Tha we use “meta” and “defacto” functions to transform between meta-level bindings?

> meta : binding -&gt; Maybe binding  
> meta a =  find_first bindings (meta_name a)

> defacto : binding -&gt; name -&gt; value-initilizer-list -&gt; Maybe binding // E.g., defacto int a 3; defacto struct a {int x};  
> defacto a b c = let d = bound_value a in binding a b (defacto d c) // dispatch to bound meta-value as constructor

> defacto: value -&gt; initialiser-list -&gt; value  
> defacto a b = apply (as_function a) b // dispatch to value as constructor (we expect a to be the meta-value taking b as argument list)

> defacto: binding -&gt; &#91;binding&#93;  
> defacto a = find bindings (meta_name a)

==&gt; Consider Tha kinds (meta-3 values) are function and a set of Sum and Product types?

==&gt; Consider how we express the algebra for function (lambda) kind, type and value?

==&gt; Also see “[Todo: Tha function model - Consider to once and for all define how Tha should model function kind, type, value and call?](../4ca21428/chime.md)"

==&gt; It seems the function kind: name -&gt; argument-list -&gt; binding // A function type declaration

==&gt; It seems the function-type: binding -&gt; value-initialiser-list -&gt; function-body // A function value definition

==&gt; It seems the function-apply: binding -&gt; value-initialiser-list -&gt; value // A function call

2) Consider in the we have both “anonymous” and named value constructors (compare function and lambda in C++)

==&gt; It seems in C++ we cant declare anonymous kinds, types not values (they all must be declared using a valid name)?

==&gt; But C++ has added lambda as anonymous functions for convenience.

==&gt; Thus , we can imagine Tha can generalise this to allow any meta-value to be instantiated “as value” and have the “declare” operation use the anonymous one?

==&gt; Thus Tha C++ would allow:

> > meta {  
> > auto a = struct {  
> > // Anonymous struct (no value-semantics as C++ requires the struct to be named to declare actors and dtors)  
> > int x;  
> > }  
> > }

==&gt; This would enable Tha C++ to enable user-defined constructors that constructs named instances (and thus control presence of actors and dtors?

==&gt; Consider Tha uses neutral names (e.g., defacto) for all construct functions?

==&gt; And can model Tha C++ anonymous instances to use the C++ keyword as ctor, door names (to be renamed by named instance member constructor)?

> > meta {  
> > auto a = struct {  
> > // Anonymous struct = generated “struct” ctors, dtor?!  
> > int x;  
> > }

> > auto a : struct { // Extend struct kind  
> > a(struct::initialiser_list ns) : struct{ns} {} // pass provided struct namespace  
> > }  
> > }

==&gt; Consider if we should allow value to be mutable in Tha C++ (or how do we specialise the namespace when we extend struct = remove or add members)?

...

3) Consider laying the Tha stack down and imp,event each layer as a C++ value, type, kind and template stack?

==&gt; Consider In C++ back level meta-value is a C++ value having a type, a kind and a template mapping level -&gt; kind?

> **Tha Stack** —&gt; meta-1 meta-2 meta-3 meta-4

> C++ template value % % %  
> C++ kind value&lt;1&gt; value&lt;2&gt; value&lt;3&gt; value&lt;4&gt;  
> C++ type value&lt;1&gt;::type value&lt;2&gt;::type value&lt;3&gt;::type value&lt;4&gt;::type  
> C++ value meta_1_value meta_2_value meta_4_value meta_4_value  
> ^  
> |  
> C++ Stack

==&gt; Now we can imagine the Algebra of each meta-value to be defined by member operations of the type?

…

Consider to elaborate and experiment with C++ implementation of Tha (try out small parts to recursively get something that works)?

...

{% endraw %}
