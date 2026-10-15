# Todo: Programming - Consider a Dream C++ IDE (build environment) to detect Strongly Connected Components (SCC:s) in source as build-able libraries?

```#4a574ba5``` *As of 2016-03-26 13:16*

[mail plain/text](mail.txt)

{% raw %}
Can we imagine a C++ build environment to detect libraries and interfaces in source by analysing the code using a Strongly Connected Component detection algorithm?

1) A Strongly Connected Component is one of Nodes that only refers to other nodes wishing the component ([https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm](https://en.wikipedia.org/wiki/Tarjan's_strongly_connected_components_algorithm))

==&gt; Consider that groups of functions and classes that only references each other are subjects for library components?

==&gt; Q: Dows this include components that uses call-backs?

==&gt; Yes - it only means that the call-back interface is part of the SCC?

==&gt; And it will be as C++ wont compile unless all types are known?

==&gt; Consider that SCC detection must be able to identify both Template Components and run-time components?

==&gt; A SCC of Templates takes types as inout but still only contains internal references using provided types and internal types?

==&gt; An SCC with no exposed templates only uses runtime provided parameters?

==&gt; It seems we must be able to detect library boundaries of Compile time Interfaces (Template Parameters) and runtime interfaces (value parameters)?

2) Consider to compare with the Eclipse Plugin that uses this algorithm to view template/constexpr instantiations?

==&gt; See “Todo: C++ - Consider to study template specialisation to understand it better"

==&gt; At 9:20 in (<https://www.youtube.com/watch?v=ltfmBUAmePE>) he shows a cool feature showing a (Strongly Connected Component, SCC?) graph of the generated println?

==&gt; It seem to be the Eclipse/Cevelop plug-in demonstrated intros youtube clip (<https://www.youtube.com/watch?v=iRsTR9SsqmA>)?

==&gt; Peter Sommerland seem to demo this tool here (<https://channel9.msdn.com/Events/CPP/CppCon-2015/CPPConD02V008>)?

==&gt; Still no publicly available version of Templator (as of Cppcon 2015)?

==&gt; He seem to state that Cevelop and Templator plug-in is developed as university/student projects?

==&gt; Cevelop seem to be part of an EU-funded project called REPARA (<http://repara-project.eu/?page_id=248>)?

“co-funded by the European Commission within the Seventh Framework Programme"

==&gt; LLVM seem to talk about SCC as part of the “Writing an LLVM Pass”” (<http://llvm.org/docs/WritingAnLLVMPass.html>)?

==&gt; LLVM seem to apply (refer to) Tarjans SCC Algorithm defined here ([https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm](https://en.wikipedia.org/wiki/Tarjan's_strongly_connected_components_algorithm))?

“The algorithm takes a directed graph as input, and produces a partition of the graph's vertices into the graph's strongly connected components”

==&gt; Side-note: Boost seem to provide an SCC algorithm in the Graph library (<http://www.boost.org/doc/libs/1_57_0/libs/graph/doc/strong_components.html>)?

3) Consider to engage LLVM front-end to generate an AST from which to find SCC:s?

==&gt; Could we simply compile the source code to get an AST (Abstract Syntax Tree) and find the SCC:s in that tree?

==&gt; Then - how do we detect search-paths to include files to have pre-processing work correctly?

==&gt; Seems auto-configuration of the pre-processor phase needs a separate mechanism?

…

…

Consider to elaborate on this idea to detect source code components using an SCC algorithm on C++ AST:s?

...

{% endraw %}
