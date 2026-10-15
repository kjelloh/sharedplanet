# Todo: Programming - Consider to enable the "Dream IDE" to understand and help the programmer to comply with "Concepts" (e.g. Input Iterator Concept)

```#df3bdffe``` *As of 2015-12-24 17:37*

[mail plain/text](mail.txt)

{% raw %}
C++ standard library (and the libraries) applies “Concepts” to convey in documentation the requirements for input and output parameters. But the C++ language itself does not provide any mechanisms to convey these requirements in code (e.g. providing template parameters that does not comply with the “Concept” of that parameter will cause compilation error at template instantiation which is har to debug).

1) C++ language concept support motivation and extension seem to be described in this paper (<http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2005/n1758.pdf>)?

2) Consider to have the IDE try to instantiate templates at the time they are referenced in code (e.g. don’t wait to compilation to provide feed-back to the programmer if the code calling for template code complies with the interface concept)?

3) Consider to have the IDE hold some “concept definition” (perhaps of the type proposed as future language support above) and apply this to help the programmer comply with the interface concepts?

4) Sidenote: Protocol requirements are in fact “Concepts” as defined in C++ interface documentation?

…

Elaborate on this idea (and study any proposals to adress this issue) to see if and how we may enhance a C++ programming environment with Concept-compliance knowledge and tools)?

...

{% endraw %}
