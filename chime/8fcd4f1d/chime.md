# Todo: Tha infer - Consider Tha may implement any inference (operation infer or meta-2 value inferred) by defining matching between binding lists?

```#8fcd4f1d``` *As of 2017-08-12 19:50*

[mail plain/text](mail.txt)

{% raw %}
It seems we may define all Tha infer operations as matching operations between binding lists?

==&gt; Also see “[Todo: Tha - Consider to define mtea-2 value "inferred" that constructs generic meta-1 value (they apply pattern matching to define meta-0 values)?](../bde9b9a8/chime.md)”

==&gt; Also see ”[Todo: Meta Value Model - Consider in Meh we define meta-1 name "a" as a generic (any) type to be inferred from (Haskel and Elm style)?](../9e687519/chime.md)”

==&gt; Also see ”[Todo: Meta Value Model - Consider mechanisms to create and apply pattern matching using existing model meta-values and explicit UML-like model patterns?](../a6a889cc/chime.md)”

==&gt; Also see ”[Todo: Meta Value Model - Consider to implement a value-to-meta-value-contract matching ability as implemented by Clojure.spec?](../c40aa5b0/chime.md)”

1) Consider what inference operations we can implement just based on &#91;binding&#93; -&gt; &#91;binding&#93; operations?

==&gt; Consider infer is a Tha operation?

infer: &#91;binding&#93; -&gt; &#91;binding&#93; -&gt; &#91;binding&#93; // matches two binding lists and returns a resulting binding list

==&gt; Consider infer succeeds if the inferred list of bindings carries the information required (we may infer structure, declaration, definitions or names)?

==&gt; Consider the result of infer is a list that is isomorphic in structure to the source binding list?

==&gt; In this way we can match a record to a tuple or a list or any sequenced data structure?

==&gt; Also see Clojure.spec (Se referenced Todo above)

…

2) Consider to compare with C++ binding lists (and identified C++ inferences)?

==&gt; It seems we can make some observations regarding how different forms of “lists” are expressed and defined in C++?

==&gt; It seems C++ functions are declared using (binding, binding, binding) for the argument-list (<http://en.cppreference.com/w/cpp/language/function>)

==&gt; So **(binding, binding, binding)** &lt;=&gt; **{binding;binding;binding}** is syntactic sugar to make functions look like its mathematical counterpart?

==&gt; C++ also uses the syntax {literal, literal, literal} for initialiser-lists, also called braced-initilizer-list (<http://en.cppreference.com/w/cpp/utility/initializer_list>)?

==&gt; AND - the initialiser-list can only contain literals (it is a compile-time only instance) (<http://en.cppreference.com/w/cpp/utility/initializer_list/initializer_list>)?

==&gt; Further - Lambda captures defines the capture list on the form &#91;binding, binding, binding&#93; (<http://en.cppreference.com/w/cpp/language/lambda#Lambda_capture>)?

{binding, binding; binding} = environment member list (braced comma separated list)

(binding, binding, binding) = function argument list (parenthesised comma separated list)

{literal, literal, literal} = std::initialiser_list (braced coma separated list

&#91;binding, binding, binding&#93; = lambda capture list (bracketed comma separated list)

{binding, binding; binding} = {literal, literal, literal} // environment definition = value binding

&#91;binding, binding, binding&#93; = {binding, binding, binding} // lambda capturing

{binding, binding; binding} = {binding, binding; binding} // copy instantiation

...

…

Consider to elaborate in this proposal to define an infer operation that operates solely on list of bindings?

{% endraw %}
