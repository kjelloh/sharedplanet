# Todo: Meta Value Model - Consider ways to have evaluations result in both optional value mutation as well as actual evaluation result (separate values)?

```#fb6f684b``` *As of 2017-06-10 19:47*

[mail plain/text](mail.txt)

{% raw %}
Consider how we can apply operations to a Meta Value Model instance and allow both querying (evaluate non-mutating operations) as well as mutating operations (evaluation returns a new instance of itself)?

1) Consider what it means that Immutable data structures requires mutation to result in a new instance with non-mtated values shared with the previous instance?

==&gt; Consider evaluating mutating script operation: (append . (declaration count number))?

==&gt; The ”.” would mean current parent and append would mutate current-parent with a new declaration.

==&gt; Consider we implement this as the current_parent.evaluate(”(append . (declaration count number))”)?  
==&gt; And this results in a new value for current_parent value (immutable)

==&gt; The client must detect that the evaluation returned a new instance (and not the instance that was called)?

==&gt; Consider we implement this by having the return value be a pair {new_value,result_value}?

==&gt; The caller may then check (called_value &lt;&gt; new_value) and if so know it must make a new instance of itself up along the path to the immutable data structure root?  
…

==&gt; Consider evaluating a non-mutating ”quering” operation: count

==&gt; This would mean to evaluate the identifier ”count”  
==&gt; Consider to implement this with the return value pair {new_value, result_value}

==&gt; Now, the client may detect that the called value was NOT mutated (called_value == new_value)?  
…

2) Consider that the REPL is in fact the Client of the Model (i.e., for Darwinet the MIV would actually live and be owned by the Client, synchronized through the view)?

…

3) Consider how the REPL may implement the Elm immutable data observer idiom?

Consider each call to evaluate returns the pair {new_value, result_value}

struct repl {  
Model current_model

repl() : current_model{} {  
auto result = view.current_model();  
auto virtual_model = diff(result.new_value,current_model);  
this-&gt;update(virtual_model);  
}

void update(VirtualModel diff) {  
// Update us according to the changes provided in diff  
...  
}

std::string evaluate(script) {  
// Evaluate provided script by current model.  
auto result = current_model.evaluate(script);  
// Observe model state change  
auto virtual_model = diff(result.new_value,current_model);  
this-&gt;update(virtual_model); // For repl update to model mutation  
// Return expression evaluation result as text for console output  
return as_text(result.result_value); // for console output of script result  
}  
}

…

Consider to delve deeper into this issue of how to pass around both value-mutation result and expression evaluation result as separate entities?  
...

{% endraw %}
