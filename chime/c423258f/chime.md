# Todo: Consider to study  Microsoft developer Sy Brand take on interfacing FFmpeg with C++ using coroutines?

```#c423258f``` *As of 2022-01-28 19:23*

[mail plain/text](mail.txt)

{% raw %}
==&gt; Also see "[Todo: Consider youtube video "LIVESTREAM: Setting up FFmpeg and OpenGL in C++ for real-time video processing" to follow to setup a C++ cross platform FFMPeg video player and and OpenGL video viewer basics](../4c0da55c/chime.md)"

1) Consider the youtube video "C++ GUIs with coroutines, WinUI3, C++/WinRT and FFMPEG" with this part showing a seemingly nice C++ wrapping of the FFmpeg C API (<https://youtu.be/OSYXGyMw9GE?t=1636> )?

==&gt; For his purpose to capture random shots from a video file and store as png he uses three ffmpeg libraries?

> ![](PastedGraphic-1.png)

==&gt; It seems he encapsulates all ffmpeg operation into a class Shottaker?

> ![](PastedGraphic-3.png)

==&gt; He seems to have another include from FFmep in the cpp file?

> ![](PastedGraphic-4.png)

==&gt; This seems to be the ShotTaker constructor?

> ![](PastedGraphic-5.png)

> ![](PastedGraphic-6.png)

==&gt; This seems to be the InitializeDecoder method?

> ![](PastedGraphic-7.png)

==&gt; This seems to be the InitializeEncoder method?

> ![](PastedGraphic-8.png)  
> ![](PastedGraphic-10.png)

==&gt; This seems to be the InitializeColorSpaceConverter?

> ![](PastedGraphic-11.png)

==&gt; This seems to be the InitaiizationError and the destructor?

> ![](PastedGraphic-12.png)

==&gt; This seems to be the Cleanup method?

> ![](PastedGraphic-13.png)

==&gt; This seems to be the TakeShots method?

> ![](PastedGraphic-14.png)  
> ![](PastedGraphic-18.png)

==&gt; This seems to be the free function EncodeNextFrameAsPng

> ![](PastedGraphic-19.png)

==&gt; And these seems to be the free fucntions called from EncodeNextFrameAsPng?

> ![](PastedGraphic-20.png)

> ![](PastedGraphic-21.png)

> ![](PastedGraphic-22.png)

==&gt; This seems to be the DemuxVideoPacket

> ![](PastedGraphic-23.png)

2) Consider to re.implement hsi ShotTaker class as a way to learn his way of interfacing ffmpeg C API from C++?

==&gt; I Created Github project ShotTAker (<https://github.com/kjelloh/ShotTaker> )

...

{% endraw %}
