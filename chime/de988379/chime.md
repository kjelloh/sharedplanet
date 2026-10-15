# Todo: C++ Tha - Consider to assume we have a small set of STL containers available to compose meta-values in the model?

```#de988379``` *As of 2017-08-09 13:41*

[mail plain/text](mail.txt)

{% raw %}
It seems we need some way of composing meta-values to enable us to declare and define the C++ language compositions class, struct, union, enum, namespace?

==&gt; Also see “Todo: Tha function types - Consider we can actually extend normal value-functions to also allow type-functions and kind-functions?”

1) Consider we assume we can use selected containers from STL to compose with meta-values?

> namespace assume_stl_compositions {

> template &lt;typename... Ts&gt;  
> using void_t = void; // Until C++17

> using visibility = int;

> const int vis_undefined = -1;  
> const int vis_private = 0;  
> const int vis_protected = 1;  
> const int vis_public = 2;

> template &lt;typename T&gt;  
> using value = void_t&lt;T&gt;;  
> template &lt;typename T&gt; // value id meta_value id value data  
> using binding = std::tuple&lt;visibility,std::string, std::string, std::shared_ptr&lt;value&lt;T&gt;&gt;&gt;;  
> using environment = std::vector&lt;binding&lt;void&gt;&gt;;

> **meta** {

> // value &gt;&gt; type  
> // type &gt;&gt; kind

> // as if C++ struct was declared in meta-code  
> kind struct : public environment {  
> struct(environment env) : environment{env} {  
> for (auto binding : env) {  
> // default public  
> if (std::get&lt;0&gt;(binding) == vis_undefined) std::get&lt;0&gt;(binding) = vis_public;  
> }  
> // add default members based on what is already in provided environment...  
> // ...  
> }  
> }

> // as if C++ class was declared in meta-code  
> kind class : public environment {  
> struct(environment env) : environment{env} {  
> for (auto binding : env) {  
> // default private  
> if (std::get&lt;0&gt;(binding) == vis_undefined) std::get&lt;0&gt;(binding) = vis_private;  
> }  
> // add default members based on what is already in provided environment...  
> // ...  
> }  
> }

> // as if C++ has closures explicitly defined as the kind that creates lambda types  
> kind closure : private environment {  
> environment args;  
> statements body;  
> // &#91;captures&#93;(arguments) -&gt; value_type {environment}  
> // Note: A Closure Environment contains C++ statements?!  
> closure(environment captured, environment args, statements body)  
> : args{args},... {  
> // Hm... how do we make closure environment child of capture and arguments?  
> // We need to next environments...  
> }

> template &lt;typename... Vals&gt;  
> auto operator()(Vals... vals) {  
> // bind argument values in the order provided to member args (declared arguments)  
> // Note: bind is succesfull if all args are defined after binding.  
> // Default values already defined in args allowed.

> **defacto**(\*this); // Generate meta-1 statements  
> // Hm... We need to think more here to get this to work…?

> }  
> }

> }

…

Consider to come back to this idea as a way to defined compose operations in Tha (and thus implicitly the reflection API into such compositions)?

...

{% endraw %}
