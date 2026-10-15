# Todo: Consider we should actually be tempted to re-think current computers with centralised CPUs and instead imagine high performance tasks to be moved closer to the data in a pipe of data processing?

```#407960b6``` *As of 2019-03-03 14:16*

[mail plain/text](mail.txt)

{% raw %}
What can we imagine to gain by being able to delegate high performance processing from a central CPU to "migrated" cores to more efficient locations in a pipe of data processing?

==&gt; Also see "[Todo: Consider ways we can imagine to make components and functionality of graphical work tool-chains to become compassable by (make graphical operations compose to) the end user?](../5450fa0f/chime.md)"  
==&gt; Also see "[Todo: Consider to understand graphics card architectures and abilities based on the benchmarking made for evaluating the jan 2019 AMD Radeon VII vs Nvidia RTX 2080?](../9e6692ca/chime.md)"

1) Consider 3D games could benefit from having the gaming logic being moved closer to the GPU?

==&gt; Consider in games we have to process very large amounts of graphic data dictated by the current game state?

==&gt; But the actual bottle-neck is to render the current state on to the screen?

==&gt; The actual gaming logic "only" has to process user inputs and mutate the game state (which is in itself a quiet low data intensive task)?

==&gt; Consider that once the mutation required to get the new game state we actually only have to render the parts of the view that is affected by the new state?

==&gt; Consider that rendering of objects moving in relation to each other requires new ray tracing and rendering if changed shadows, colour reflections, new light shining through transparent areas etc (high demanding)?

==&gt; Consider that rendering of a new viewpoint (e.g., by moving the camera) should be less processing consuming as "only" the transformation of a rendered scene is involved?

==&gt; On the other hand, a moved view point may reveal parts of the scene that was not previously rendered due to optimisation (not rendering invisible parts of a scene)?

...

2) Consider video editing applications could benefit from having encoding moved close to the SSD and "scrubbing" and playback move close to the GPU (in-line with the display)?

...

3) Consider examples of hardware adaptation to actual pipes of data processing?

==&gt; Consider how the display is naturally placed after the GPU (no system uses the CPU to transfer rendered images to the display)?

==&gt; Consider how Intel Quicksync is a special video encoder hardware placed close to the CPU (to encode rendered video before streaming it back to the SSD)?

4) Consider an SSD with "Video Encoding Hardware" would enable any computer with very fast video encoding abilities?

==&gt; Consider we could integrate an H.264 encoding chip close and together with the SSD so that it can create video encoded files from a rendered file from the CPU?

==&gt; Or better still, if the GPU was able to stream rendering directly to the SSD for encoding and storage - then the CPU would only have to orchestrate it it all (process the editing model of the video to produce)?

...

{% endraw %}
