# Todo: Programming - Consider to study, understand and possibly cross-translate between different build tool (pre-processor/compiler/linker) options?

```#21e2e79b``` *As of 2015-12-19 12:39*

[mail plain/text](mail.txt)

{% raw %}
Would it be possible to translate between then options of different C++ build tools (preprocessor/compiler/linker) so that if one knows the options for one compiler one is able to call another one to get the same result?

1) Consider to study the options and abilities of preprocessors (Visual Studio, BCC32, BCC64/Clang, true Clang, GCC)  
2) Consider to study the options and abilities of compilers (Visual Studio, BCC32, BCC64/Clang, true Clang, GCC)  
3) Consider to study the options and abilities of linkers (Visual Studio, Borland linker, Embarcadero ilink, Gnu linker)  
4) Also consider to model a build environment so that tool options may be referred to as what part of the model the affect (e.g. pre-processing/source/target, language, target processor/executor, memory model, optimization)?  
5) What can this model and understanding of options say about auto-discovering targets and tool-chain from source only?  
6) Can we say something about designing a language to program target-builds and hook it into LLVM tool-chain to generate executable build engines?  
…

Consider to delve into this subject and see if it is possible to understand and model the build tool chain in some sensible way?  
...

{% endraw %}
