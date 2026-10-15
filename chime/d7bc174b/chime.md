# Todo: Meta Value Model - Consider to enable "Meta Value Lisp" scripting language to allow name-paths to refer to structure members

```#d7bc174b``` *As of 2017-06-10 13:54*

[mail plain/text](mail.txt)

{% raw %}
Could it prove a good idea to allow the scripting Lisp language for Meta Value Model processing to allow value reference using names that are path into the value structure?

1) Consider any Name can be a Path (an array of name selectors)?

(define miv.some_person.name ”kjell-olov”) would mean the member ”name” of member ”some_person” of the miv value is set to ”kjell-olov”?  
…

2) Consider how this may solve the problem of - how to look up names?

==&gt; Consider the root environment is the empty path ””?

==&gt; Consider the Meta Value Model instance owns the root environment?

==&gt; Thus - mutation of the root environment implicitly updates its state?

(declare miv (record)) // miv is an empty record implicitly appended to the root environment?  
(append miv (declare count number)) // miv is mutated = owner root-environment state is changed with new miv value (old state persists with old miv value)

==&gt; Consider any mutation changes the state of the value that owns the mutated value?

”” root&#91;0&#93; ==&gt; ”” root&#91;0&#93; ”” root&#91;1&#93;  
| | |  
”miv” record ”miv” record ”miv” record  
| | |  
null null --------------------  
| |  
head tail  
| |  
”count” number null  
…

…

Consider to elaborate on this idea on how to have a meta-value lisp language that can operate using name-paths into immutable Meta Value Model?  
...

{% endraw %}
