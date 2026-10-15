# Todo: Programming - Consider to talk/blog on all "layers" C++ source code goes through before becoming in-memory executable processed by the CPU?

```#72d98653``` *As of 2017-01-26 11:30*

[mail plain/text](mail.txt)

{% raw %}
Watching a Juce talk on JIT-compiled C++ using the Pro-Jucer IDE I got inspired to use leads in this talk to explain all the phases the exists to turn C++ source code into the executable that are actually processed by the CPU on the target machine?

==&gt; Also see ”Todo: Programming - Consider a source-file-system for c++ that exposes a "representation-view" of representation-invariant (e.g. AST-graph) c++ translation units? ”

==&gt; Also see ”Todo: Programming - Consider to define transform of C++ code into executable code as a stack-of-transformations?”

==&gt; Also see ”Todo: programming - Consider to implement a C++ open source library to compile-time identify the build tool chain and target platform?"

1) The Juce talk ”Behind the Scenes of the Pro-Jucer Live-Build Engine” by Stefan Gränitz about this seem to live here (<https://www.youtube.com/watch?v=x2GnSXlSpwk>)?

2) Consider to make an image of all the steps involved in turning C++ source code into code that actually executes on the CPU?

==&gt; Consider to elaborate on the image designed by Gränits?

![](<Source Code Static Build Phases.tiff>)

3) Consider to expand on the findings about C++ build steps in ”Todo: programming - Consider to implement a C++ open source library to compile-time identify the build tool chain and target platform?”?

==&gt; Consider to target the C++ “stack” of mechanisms to find what runtime code to generate?

==&gt; Consider to use leads presented by Stephan T. Lavavej in this prevention of his (<https://channel9.msdn.com/Series/C9-Lectures-Stephan-T-Lavavej-Core-C-/Stephan-T-Lavavej-Core-C-1-of-n>)?

==&gt; It seems a C++ compiler uses a pre-set of phases to find a referenced function?

First Name Lookup (<http://en.cppreference.com/w/cpp/language/lookup>)

  
> > > *“Name lookup is the procedure by which a name, when encountered in a program, is associated with the declarationthat introduced it."*

Name lookup seems to honour name visibility (<http://www.cplusplus.com/doc/tutorial/namespaces/>)?

Unqualified name lookup seems to define what is “seen” without explicitly stating so in the reference (<http://en.cppreference.com/w/cpp/language/unqualified_lookup>)?

Then Template Argument Deduction (<http://en.cppreference.com/w/cpp/language/template_argument_deduction>)

  
> > > *“In order to instantiate a function template, every template argument must be known, but not every template argument has to be specified. When possible, the compiler will deduce the missing template arguments from the function arguments. This occurs when a function call is attempted, when an address of a function template is taken, and in some other contexts:"*

Then Overload Resolution (<http://en.cppreference.com/w/cpp/language/overload_resolution>)

  
> > > *“ &#91;if previous&#93;... steps produce more than one candidate function, then overload resolution is performed to select the function that will actually be called."*

Then Access Control

==&gt; Access Control seem to be about honouring the access specifiers public, protected and private (<http://en.cppreference.com/w/cpp/language/access>)?

==&gt; Q: It does not seem to have anything to do with visibility (see above)?

Then Virtual Function Binding (<http://www.cplusplus.com/doc/tutorial/polymorphism/>)

==&gt; It seems we should see the pre-processing step as pre-pending the compiler steps (<http://www.cplusplus.com/doc/tutorial/preprocessor/>)?

> Pre-processor steps  
> ...  
> Compiler steps  
> First Name Lookup (<http://en.cppreference.com/w/cpp/language/lookup>)  
> Then Template Argument Deduction (<http://en.cppreference.com/w/cpp/language/template_argument_deduction>)  
> Then Overload Resolution (<http://en.cppreference.com/w/cpp/language/overload_resolution>)  
> Then Access Control  
> Then Virtual Function Binding (<http://www.cplusplus.com/doc/tutorial/polymorphism/>)  
> Linker steps  
> …

4) Consider to add to the model all the linker phases where generated code gets placed at relocatable memory adresses in several steps?

==&gt; It seems in binary object files memory location are ”named” using name-mangled symbols?

==&gt; It seems Clang generates ”extra” intermediate memory locations to link function calls to their actual fucntion location (

![](<Clang relocation stubs.tiff>)

==&gt; It seems on executable load the operating system places the code and data in virtual memory (thus fixate named memory locations)

…

5) Consider how the CPU actually processes code and data in virtual memory by swapping in memory and also cashing it in several steps?

==&gt; It would seem code in virtual memory gets swapped in to be executed by the CPU (e.g. simulating 32 bit address space on 64 bit machine)?

==&gt; It would seem memory is then replicated into L3, L2 and L1 caches for execution by the CPU?

...

6) Consider to follow up on the leads Gränitz makes to articles about compiler topics and output formats?

![](<Gränitz References to Compiler output formats.tiff>)

…

Consider to elaborate on this kind of model for all the steps involved in transforming C++ source code into target CPU executed code?

...

{% endraw %}
