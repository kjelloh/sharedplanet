# Todo: Darwinet Repl - Consider we may decorate the Meh Repl with a meta-processor (Cling C++ Repl style) to implement repl commands separate from the Meh language Tha mutations?

```#b2e9849f``` *As of 2017-08-03 20:10*

[mail plain/text](mail.txt)

{% raw %}
Reading about the C++ Repl Cling meta-processor that decorates the C++ language with repl state commands to be able to perform tasks not related to C++ source?

1) Consider to read about Cling Repl here (<https://root.cern.ch/cling>)?

==&gt; It seems the meta-processor is to enable the user to give commands to the repl itself to do things like load a file or library?

  
> ### Metaprocessor

  
> Cling Metaprocessor provides convenient and easy to use interface for changing the interpreter's internal state or for executing handy commands. Cling provides the following metaprocessor commands:

> **syntax:** *.(command), where command is:*

- .x filename.cxx - loads filename and calls void filename() if defined
- .L library | filename.cxx - loads library or filename.cxx
- .printAST - shows the abstract syntax tree after each processed entity
- .I path - adds an include path



2) It seems we have the same need for our Darwinet Meh Repl (We need to be able to give commands to the Repl to do non-Tha related operations)?

==&gt; Consider the non-Tha related commands we like to be able to give to the Meh Repl?

==&gt; Consider we want to to travel the Tha using a “current path” (in effect set the current environment change-directory-style)?

> > Meh’Tha&gt;cd projects  
> > Meh’Tha/projects&gt;**cd** trudelutt  
> > Meh’Tha/projects/trudelutt&gt;**ls**

> > Element Tha/projects/trudelutt : record {  
> > app : record {  
> > …  
> > }

> > Meh’Tha/projects/trudelutt&gt;

==&gt; Consider ways to wrap a meta-processor round the Meh Repl?

…

…

Consider to elaborate on this idea of having a meta-processor to extend Meh language with repo-specific commands?

...

{% endraw %}
