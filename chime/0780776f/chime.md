# Todo: Programming - Consider a DSL for Protocol Stacks using the pipe-operator versus variadic template parameter list?

```#0780776f``` *As of 2016-03-28 13:08*

[mail plain/text](mail.txt)

{% raw %}
Could we imagine to define a stack of protocols using a DSL where the pipe-operator defines interfaces between stacked protocols? And if so, how does this compare to enable stacking using variadic template parameter list?

1) Consider a Stack to be a sequence of protocols “piped” into a sequence?

==&gt; The pipe-symbol is established in Unix, DOS and some C++ DSLs so it could be a good candidate?

auto myStack = protocol1 | protocol2 | protocol3; // myStack now is a Protocol with “Uppstack” interface of protocol1 and “Downstack" interface of protocol3.

2) Consider to enable the DSL to generate a stack where each piped protocol are “executors”?

==&gt; A protocol is an executor if it has operations running in parallel with external code (e.g. multithreaded or using C++ Coroutines)?

3) Consider a “protocol” to be a composite type of a single or “stacked” protocols of the same interface?

Protocol&lt;SPDH&gt; protocol1;  
Protocol&lt;ACISTD&gt; protocol2;  
auto protocol3 = protocol1 | protocol2;

==&gt; This should mean protocol3 is SPDH over ACISTD?

Protocol&lt;TCP_IP&gt; protocol 4;  
auto protocol5 = protocol3 | protocol4;

==&gt; Would mean SPDH over ACISTD over TCP/IP?

4) Consider to compare this approach to specifying the stack as variadic template parameter list?

Protocol&lt;SPDH,ACISTD,TCP_IP&gt; protocol1;

==&gt; This would mean protocol1 is SPDH over ACISTD over TCP_IP?

typedef Protocol&lt;SPDH&gt; protocol1_type;  
typedef Protocol&lt;ACISTD&gt; protocol2_type;  
Protocol&lt;protocol1_type,protocol2_type&gt; protocol3;

==&gt; This would mean protocol is SPDH over ACISTD?

==&gt; It seems “stacking” protocol types at compile time (template parameters) should enable us to perform compile-time specialisations?  
...

…

Consider on this idea to express “stacking” of protocol engines using the “pipe” operator?  
...

{% endraw %}
