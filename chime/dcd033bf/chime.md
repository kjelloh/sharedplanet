# Todo: Programming - Consider that C++ std::accumulate is the runtime version of template folding expressions?

```#dcd033bf``` *As of 2017-01-18 15:20*

[mail plain/text](mail.txt)

{% raw %}
It just seems to be that what std::accumulate does is a runtime folding and that there should be a meta programming variant and that one is fold?

1) This seems to be the C++ fold definition (http://en.cppreference.com/w/cpp/language/fold)?

==&gt; It seems C++ allows both left and right folds

==&gt; 1) Unary right fold (E op ...) becomes E1 op (... op (EN-1 op EN))

==&gt; It seems a more understandable way ti write this is (E op ...) becomes E1 op ( E2 op ( E3 op (… (EN-1 op EN))))?

template &lt;typename… Args&gt;  
bool all(Args… args) {  
return (args && ...);  
}

bool b = all(true, true, true, false, true);

==&gt; typename… Args would be bool, bool, bool, bool, bool  
==&gt; Args… args would be bool b1, bool b2, bool b3, bool b4, bool b5 (some expanded and named parameters)  
==&gt; (args && …) would be b1 && (b2 && (b3 && (b4 && b5))) // right fold

==&gt; NOTE: Here we fold function parameters using an operator (not on types)  
==&gt; NOTE: As fold only works for binary operators we cant fold on the actual types (bool && bool makes no sense)!  
...

==&gt; The interesting thing with fold expressions seems to be that we are allowed to mix types in the pack?

template &lt;typename… Args&gt;  
bool accumulate(Args… args) {  
return (args + ...);  
}

auto result = accumulate(1,0.75,4, std::string(”Hello")); // Would expand to 1 + (0.75 + (4 + std::string(”Hello")))  
Which would be ok as long as we have and int operator+(std::string&& s) defined?  
...

2) This seems to be the C++ std::accumulate definition (http://en.cppreference.com/w/cpp/algorithm/accumulate)?

3) This seems to be the wikipedia general definition of fold (https://en.wikipedia.org/wiki/Fold_(higher-order_function))?

4) Can we imagine a compile time Fold&lt;typename… Args&gt; that return a ”folded type”?

template &lt;typename… Args&gt;  
struct MyFold {  
using type = ?? // error, we cant use a fold expression here!  
}

==&gt; It seems the fold expression only makes sense on function parameter packs (not

…

Consider to delve deeper into this idea to find the ”fold” pattern on the value-level and the type-level?

{% endraw %}
