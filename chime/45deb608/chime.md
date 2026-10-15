# Todo: Programming - Consider to delve into the Faust DSP language echo-system from the talk "FAUST DSP language ecosystem meets JUCE" by Stephane Letz?

```#45deb608``` *As of 2017-01-26 14:13*

[mail plain/text](mail.txt)

{% raw %}
Watching the talk ”FAUST DSP language ecosystem meets JUCE” by Stephane Letz I got really interested in understanding how they enabled cross platform and cross API audio processing software development by leveraging a new language called Faust to build tool chains executed both compile time and run time to generate audio processing software!

1) The talk ”FAUST DSP language ecosystem meets JUCE, Stephane Letz” seem to live here (<https://www.youtube.com/watch?v=VCaQNnDOHR8>)?

==&gt; It seems Faust is a functional programming language?

==&gt; It seem to support time dimensional functions (not supporting frequency domain processing, e.g., no spectrum analysis yet)?

![](<Faust language functional time domain support.tiff>)

==&gt; It seems Faust plugs into a large number of build tool chains to produce an executable image?

![](<Faust multi language generation targets.tiff>)

==&gt; This seems like a neat example of Faust to C++ translation?

![](<Faust Example of C++ generated code.tiff>)

==&gt; It seems Faust is able to define user interface control too (See vslider)?

==&gt; Faust code seem to be able to plug in to Static C++ build tool chain?

![](<Faust to Static C++ compilation.tiff>)

==&gt; Faust code can also be dynamically (run-time) built using LibFaust (Creates LLVM IR) and LibLLVM (creates executable code from LLVM IR)!

![](<Faust run-time LLVM IR target generation.tiff>)

**==&gt; WOW!**

==&gt; Faust seem to model an application having the generated DSP (written in Faust) wrapped by User Interface module and back-end Audio Driver API?

![](<Faust DSP, UI and Audio Driver architecture.tiff>)

2) The Faust eco-system seems to come with a set of different development tools?

==&gt; There seem to be a REPL IDE called FaustLive (Allowing for fast code write and test in GUI environment)?

![](<Faust Live IDE.tiff>)

==&gt; It seems to provide run-time build and run using LibFaust (Creates LLVM IR) and LibLLVM (creates executable code from LLVM IR)?

==&gt; There seem to be a lightweight web-browser executed development environment with a quite cool graphical user interface to develop and connect DPSs?

![](<Faust Emscripten based playground.tiff>)

==&gt; It seems to be based on Emsciptem compiled LibFaust (C++ to LLVM IR and back to JavaScript) and then using that LLVM to generate asm.js for web-browser execution of generated DSP?

==&gt; Thus, both the LLVM Faust frontend (LibFaust) AND the generated DPS may be fully executed as JavaScript in the web browser - **COOL!**

3) Consider to delve deeper into the example code he demoes at around 28:30 into the talk?

==&gt; He seems to show a lot of different ways to defines a DSP and then execute it rhough different GUI controls and also use MIDI devices to ”play” the developed DPS?

…

…

Consider to delve deeper into this eco-system for Faust both to learn about how to develop DPSs, but also to understand the idioms applied to transform Faust Code to DSP applications through different tool chains and connecting with different platform back-end APIs?

...

{% endraw %}
