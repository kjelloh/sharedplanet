# Todo: Functional Programming - Consider cashed functional composition result may be modelled as path of values arg-&gt;arg-&gt;arg-&gt;result?

```#8bb543bd``` *As of 2017-06-14 11:07*

[mail plain/text](mail.txt)

{% raw %}
Consider it could be a good idea to model a cache of function composition call result as a path of cached values arg-&gt;arg-&gt;arg-&gt;result?

1) Consider caching the result of calling one function is arg-&gt;result?

==&gt; Consider f: int -&gt; int; f x = x+2;  
==&gt; Calling it with 3 would yield f 3 =&gt; 5  
==&gt; We can cache this result as pair {3,5}

2) Now consider caching the result of calling the composition of two functions g f?

==&gt; Consider g : int -&gt; int; g y = y\*y;  
==&gt; Composing it with f (above) would yield g o f: int -&gt; int -&gt; int  
==&gt; And g o f x = g (f x) = (x+2)(x+2)  
==&gt; So g o f 3 =&gt; g 5 =&gt; 25.  
==&gt; And caching the result of g can be done as {5 25}  
==&gt; But f 3 is already cached so g o f 3 can be cached as {3 5 25}

3) It seems we can thus cache calls to function compositions as paths of arg-&gt;arg-&gt;result?

==&gt; Each adjacent nodes in the path can be seen as the cache of one function arg-&gt;result cache?  
==&gt; Thus the cache for g o f on x = 1…5 can be modelled as the paths:

{1 3 9}  
{2 4 16}  
{3 5 25}  
{4 6 36}  
{5 7 49}

…

4) Consider that the cache paths will be tuples of values of different types (as functions may map argument type to different result type)?

==&gt; Consider f: int -&gt; double and g: double -&gt; &#91;double&#93;  
==&gt; Then the cached path will be values of type {int, double, &#91;double&#93;}

5) Consider the meta-value path will model the function composition types?

==&gt; As each adjacent node in the path is the arr-&gt;result cache for a function,  
==&gt; It follows that each adjacent node types will be the signature of a function Fn: arg_type -&gt; result_type.  
==&gt; And so the meat-path will be type-&gt;type-&gt;type.  
...

6) Consider if it would be valuable to also use the meta-meta values of the cache path of a function composition?

==&gt; Consider the meta-meta cache path would be type-constructor-&gt;type-contructor-&gt;type-constructor?  
==&gt; Consider we can use this to apply type conversions on the cache path?

==&gt; Consider it is the type-constructor that ”knows” how to create a type from another type?  
==&gt; E.g., the type-constructor for float may define a constructor that accepts an integer (in effect defining int-&gt;float conversion)?  
==&gt; Then the meta-path int-&gt;int-&gt;int may be used to instantiate the meta-path float-&gt;float-&gt;float?  
==&gt; And provided the the cache value path 1 -&gt; 3 -&gt; 9 we can instantiate 1.0 -&gt; 3.0 -&gt; 9.0?

==&gt; Consider we can even use this to generically create f: float -&gt; float from f: int -&gt; int (without having to write any new code)?

==&gt; Either we can take the meta-body of existing f: int-&gt;int and instantiate new code where all int values are replaced with float values?  
==&gt; And repeat this recursively through all function calls in the body?  
==&gt; Or wrap existing f: int-&gt;int with an f: float-&gt;float that calls original f and then returns a float from original f int?  
==&gt; Or, a combination of the two?

7) Consider creation of generic function from existing one using meta-meta defined type-cast requires function dispatching also on return type?

==&gt; Consider turning f: int-&gt;int into f: float-&gt;float requires identifying (and dispatching) also on return type?  
...

8) Consider where this model of function composition result caches may be helpful?

…

…

Consider to elaborate on this idea of modeling function composition result cache as path of adjacent arg-&gt;result nodes of values?  
...

{% endraw %}
