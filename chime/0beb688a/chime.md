# Todo: C++ Teaching - Consider to design a C++ REPL Programming IDE or find some existing ones?

```#0beb688a``` *As of 2017-08-04 12:53*

[mail plain/text](mail.txt)

{% raw %}
So, can we imagine to design a C++ REPl IDE to enable programming in C++ using JIT-compiled and run C++ code?

1) Consider this wikipedia definition of REPL ([https://en.wikipedia.org/wiki/Read–eval–print_loop](https://en.wikipedia.org/wiki/Read%E2%80%93eval%E2%80%93print_loop))?

…

2) Consider to try out the Cling C++ Repl based on Clang (<https://root.cern.ch/cling>)?

==&gt; It seems to come as github project and build on several platforms using cmake (<https://root.cern.ch/cling-build-instructions>)?

==&gt; This page seems to state that we need to build the whole cern llvm package?

> > ```
> > git clone http://root.cern.ch<http://root.cern.ch>/git/llvm.git src
> > cd src
> > git checkout cling-patches
> > cd tools
> > git clone http://root.cern.ch<http://root.cern.ch>/git/cling.git
> > git clone http://root.cern.ch<http://root.cern.ch>/git/clang.git
> > cd clang
> > git checkout cling-patches
> > cd ../..
> > ```



==&gt; This seems to be a Github (fork?) of Cling (<https://github.com/root-project/cling> )?

==&gt; This project also seems to tag to jupyter?

==&gt; And build using provided python cpt script seems to work ok (See console output file below)?

## Attachments

- [Cling build with python cpt script - mac OS example.rtf](<Cling build with python cpt script - mac OS example.rtf>)

{% endraw %}
