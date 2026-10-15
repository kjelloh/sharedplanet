# Todo: Programming - Consider to study the Juce open source C++ audio library for Trudelutt app (multitrack audio recorder and playback)?

```#f38fc1c2``` *As of 2016-06-09 17:06*

[mail plain/text](mail.txt)

{% raw %}
Could the Open Source C++ audio library JUCE be a good library to use to implement the Trudelutt app (multitrack audio recorder and playback)?

1) The JUCE project seem to live on Github (https://github.com/julianstorer/JUCE)?

==&gt; It seem to be both for Audio processing and GUI development?

“Develop powerful, cross-platform audio, interactive, embedded or graphic applications with the JUCE library."

2) The JUCE community seem to live here (https://www.juce.com)?

3) This seem to be a good talk centered on JUCE from Cppcom 2015 (https://channel9.msdn.com/Events/CPP/CppCon-2015/CPPConD01V012)?

4) This seem to be a good example to process MIDI events using JUCE (https://www.juce.com/doc/tutorial_handling_midi_events)?

==&gt; The example is based on pre-written project code here (https://www.juce.com/doc/projects/tutorial_handling_midi_events.zip)?  
==&gt; The Project seems to come ready for XCOde (MAC), makefile (Linux) and solution-file (Windows Visual Studio)

==&gt; The project seem to define a Main.cpp and MainComponent.cpp that does not contain any #ifdefs for platform (and thus implies the JUCE library hides also the GUI platform)?

==&gt; This seem to indicate that JUCE comes with a GUI framework that bridges to Linux, MAC and Windows platform in a uniform way?  
…

5) Consider to try and write some simple multi-channel recorder and playback mixer using JUCE?

…

…

Consider to delve deeper into the JUCE open source audio library to see how it works, what we can learn and if we can use it for the Trudelutt app?  
...

{% endraw %}
