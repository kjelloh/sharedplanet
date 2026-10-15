# Todo: Consider to investigate Dune 3D open source CAD program?

```#d3628db2``` *As of 2026-03-12 09:47*

[mail plain/text](mail.txt)

{% raw %}
I want an easy to use and cost effective CAD program to design my house and things I build.

0) Consider the bottom line?

==&gt; Dune 3D seems to be a CAD for designing enclosures for electronics projects?

1) Consider youtube video "Dune 3D - The Interesting New 3D Modeling Platform" (<https://youtu.be/T1VNpC0nwF4> )?

==&gt; It seems Dune 3D is CAD only (No CAM)?

2) It seems Dune 3D lives on Github (<https://github.com/dune3d/dune3d> )?

==&gt; It seems to be a C++ application (<https://github.com/dune3d/dune3d/blob/main/src/main.cpp> )?

==&gt; It seems to be based on 'Horizon EDA' PCB design tool that he also wrote (<https://github.com/horizon-eda/horizon> )?

> *"Having solved the similar problem for PCB CAD by developing Horizon EDA, I began pondering whether I could pull off the same thing for 3D CAD. After all, what does it take to make a 3D CAD?*

> *Geometry kernel to do extrusions, intersections, chamfers, etc.: *

> *While it's not a nice library to work with, Open CASCADE is the only viable choice if we want to have STEP import/export and fillets/chamfers. Fortunately, I have some experience with it from dealing with STEP files in Horizon EDA.*

> *3D viewport: *

> *Obviously, we need a way to put 3D geometry on screen, zoom/pan and select things. The 3D preview in Horizon EDA already does all of this, so I have a well-understood codebase I can reuse.*

> *Constraint solver: *

> *U**nlike with Horizon EDA where things just stay where you last moved them, in 3D CAD, it's commonplace to specify where things go by means of constraints that need to be solved. Turns out that Solvespace's solver is available as a library1, so that part's also covered.*

> *Editor infrastructure: *

> *Last but not least, we need code that takes care of the tools, undo/redo and all of the other bits and pieces that make up an interactive editor. While there'll be some differences, I felt confident that I could reuse and adapt the interactive manipulator from Horizon EDA."*

==&gt; It seems 'Wayland' is the protocol used in Linux for applications to talk 'user interface window' with the kernel (<https://en.wikipedia.org/wiki/Wayland_(protocol)> )?

> "Wayland is a communication protocol that specifies the communication between a display server and its clients, as well as a C library implementation of that protocol"

==&gt; It seems to use GLM (<https://glm.g-truc.net/0.9.9/> )?

> "In dune3d/src/render/renderer.hpp #include &lt;glm/glm.hpp&gt;"

==&gt; It seems to use GTK ()?

> "In dune3d/src/dune3d_application.hpp #include &lt;gtkmm.h&gt;"

3) Consider 'Solvespace' that is mentioned in the youtube video comments (<https://solvespace.com/index.pl> )?

==&gt; It seems to come for Windows, Linux and macOS (<https://solvespace.com/download.pl> )?

> "Version Released Platforms  
> 3.1 stable June 01, 2022 Windows Vista–10, Linux, Mac  
> 3.0 stable April 17, 2021 Windows Vista–10, Linux, Mac  
> 2.3 stable December 23, 2016 Windows XP–10, Linux, Mac  
> 2.0 stable July 28, 2013 Windows XP–10"

...

{% endraw %}
