# Todo: C++ Teaching - Consider to enable tutorials to select a UI that is either Textual (Console-ial), 2D Graphical or 3D-graphical through some rudimentary Open Source library developed for that purpose?

```#4ebea9b2``` *As of 2017-02-17 17:39*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to realise that a UI may in fact be just one of three possible categories 1) Console (Lines of scrolling Text in and out), 2) 2D graphical and 3) 3D Graphical?

1) Consider some simple API for these categories of UI that may later be replaced (or adapted to) actual platform existing UI of the same category?

==&gt; Consider the C++ Console APP already defines a cross platform UI API based on std::cin/cout, printf and a number of C-I/O routines?  
==&gt; Consider the basic (common denominator) for cross platform 2D UI:s?

==&gt; Consider “Console embedded in 2D GUI”?  
==&gt; Consider a mapping so that the code is written as-if a Console App (using std::cin/cout…) but the actual GUI is a 2D one (e.g., an Out text-box and an in-textbox with an &lt;Enter&gt; button)?

==&gt; Consider an API with the notion of common widgets (e.g., Window, Menu, Textbox and Button)?

2) Consider to design an API for this three categories based on selected C++ Exercises to learn to program for such UI:s?

==&gt; Consider Console UI:s are good for back-end applications (logging is what we like)?  
==&gt; Consider 2D UI:s are good for smartphone applications (touch interface is the restriction)?  
==&gt; Consider 3D UI:s are good for tutorials into the realm of game developing (or CAD like applications)?  
...

3) Consider how to handle the choice between a traditional 1) “mutable GUI” (e.g., VCL, Cocoa, or any MVC based) and 2) “Frame Rendered” (e.g., Immgui)?

==&gt; Consider if these are two viable categories of GUI:s?  
==&gt; Consider where Web-based GUI frameworks fall in this category (e.g. Electron, Elm, Clojure based ones)?  
…

…

Consider to delve deeper into this idea that in fact we have only three categories of UI:s and we should develop some lightweight cross platform library top provide some API to each one of them to be able to write C++ exercises (hide the platform hassle of interfacing actual UI frameworks)?  
...

{% endraw %}
