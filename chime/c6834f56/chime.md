# Todo: Consider to study Fusion 360 (editable?) Post Processors that generates Numerical Control (NC) code for different CNC machines?

```#c6834f56``` *As of 2018-09-23 17:02*

[mail plain/text](mail.txt)

{% raw %}
It seems Fusion uses so called “Post Processors” to generate CNC specific code for different CNC machines from the CAM model inside Fusion 360?

1) Consider this youtube video “Edit Fusion 360 Post Processors with Visual Studio Code” (<https://youtu.be/P9NJ6P1vd1Y>)?

==&gt; It seems Autodesk has published a Visual Studio Code extension “Autodesk HSM Post Editor for Visual Studio Code” to enable developing Post Processors in VSCode (<https://marketplace.visualstudio.com/items?itemName=Autodesk.hsm-post-processor>)?

==&gt; It seems Fusion 360 installation comes with a Post Processor executor named “post.exe” (<https://youtu.be/P9NJ6P1vd1Y?t=311>)?

==&gt; And we need to configure the “Autodesk HSM Post Editor for Visual Studio Code” plugin where Fusion 360 “post.exe” is located (I suppose it uses it to execute the Post Processor code we are editing)?

...

==&gt; It seems Autodesk provides a long list of post processors here (<https://cam.autodesk.com/hsmposts?_ga=2.215634775.1537792395.1537295631-1478464243.1529090184>)?

> *“This is the place to find post processors for common CNC machines and controls.*  
> *Make sure to read this important safety information before using any posts."*

==&gt; This seems to be the Autodesk manual about Fusion 360 CNC prost processors ([https://cam.autodesk.com/posts/posts/guides/Post%20Processor%20Training%20Guide.pdf](<https://cam.autodesk.com/posts/posts/guides/Post Processor Training Guide.pdf>))?

2) Consider that what 3D printers call G-code is actually part of the CNC standard of control commands (<https://en.wikipedia.org/wiki/G-code>)?

  
> SampleBlockCodeDescription%Signals start of data during file transfer. Originally used to stop tape rewind, not necessarily start of program. For some controls (FANUC) the first LF (EOB) is start of program. ISO uses %, EIA uses ER (0x0B).O4968 (OPTIONAL PROGRAM DESCRIPTION OR COMMENT)Sample face and turn program. Comments are enclosed in parentheses.N01M216Turn on load monitorN02G20 G90 G54 D200 G40Inch units. Absolute mode. Activate work offset. Activate tool offset. Deactivate tool nose radius compensation.N03G50 S2000Set maximum spindle speed in rev/min — This setting affects Constant Surface Speed modeN04T0300Index turret to tool 3. Clear wear offset (00).N05G96 S854 M03Constant surface speed &#91;automatically varies the spindle speed&#93;, 854 [sfm](https://en.wikipedia.org/wiki/Surface_feet_per_minute), start spindle CW rotationN06G41 G00 X1.1 Z1.1 T0303 M08Enable cutter radius compensation mode, rapid position to 0.55" above axial centerline (1.1" in diameter) and 1.1 inches positive from the work offset in Z, activate flood coolantN07G01 Z1.0 F.05Feed in horizontally at rate of 0.050" per revolution of the spindle until the tool is positioned 1" positive from the work offsetN08X-0.016Feed the tool slightly past center—the tool must travel by at least its nose radius past the center of the part to prevent a leftover scallop of material.N09G00 Z1.1Rapid positioning; retract to start positionN10X1.0Rapid positioning; next passN11G01 Z0.0 F.05Feed in horizontally cutting the bar to 1" diameter all the way to the datum, 0.05in/revN12G00 X1.1 M05 M09Clear the part, stop the spindle, turn off the coolantN13G91 G28 X0Home X axis — return the machine's home position for the X axisN14G91 G28 Z0Home Z axis — return to machine's home position for the Z axisN15G90Return to absolute mode. Turn off load monitorN16M30Program stop, rewind to top of program, wait for cycle start%Signal end of data during file transfer. Originally used to mark end of tape, not necessarily end of program. ISO uses %, EIA uses ER (0x0B).

3) Consider to capture a list of CNC machine vendors supported by Autodesk post processors and save as a CSV list for future use?

==&gt; Also see “Todo: Consider to document how I made screen shots of a vendor drop down list and used online OCR and OS X to turn it into a CSV list of vendor names?”

## Attachments

- [Screen%20Shot%202018-09-23%20at%2016.19.numbers](Screen%20Shot%202018-09-23%20at%2016.19.numbers)

{% endraw %}
