# Todo: Programming - Consider we can use HTML and Animated CSS to implement an algorithm and model animation app?

```#d7c392ca``` *As of 2017-08-01 18:09*

[mail plain/text](mail.txt)

{% raw %}
Consider we could use HTML and CSS animations to make an app that can animate system and algorithm models (e.g., messaging flows)?

1) Consider this talk “ABC of CSS3 animations - Ronald Mavarez” with leads into CSS animation basics (<https://www.youtube.com/watch?v=k-eU8_-174g&index=92&list=PL03Lrmd9CiGewi0lbnahxEpisoP5WZocX>)?

…

2) It seems CSS just decorates HTML elements with “styles” (<https://www.w3schools.com/css/default.asp>)?

> “*CSS is a language that describes the style of an HTML document. CSS describes how HTML elements should be displayed.*”

==&gt; It seems each CSS element refers to an html element to “decorate” (as in render)?

==&gt; It seems it is the HTML document that links to CSS using the &lt;style&gt; tag (<https://www.w3schools.com/html/html_css.asp>)?

> CSS can be added to HTML elements in 3 ways:

- **Inline** - by using the **style** attribute in HTML elements
- **Internal** - by using a **&lt;style&gt;** element in the &lt;head&gt; section
- **External** - by using an **external** CSS file



==&gt; And this seems to be good examples of the three ways of defining CSS for an HTML document?

==&gt; Inline...

> &lt;h1 **style**="color:blue;"&gt;This is a Blue Heading&lt;/h1&gt;

==&gt; Internal (HTML head.style CSS elements)



> &lt;head&gt;  
> &lt;**style**&gt;  
> body {background-color: powderblue;}  
> h1 {color: blue;}  
> p {color: red;}  
> &lt;**/style**&gt;  
> &lt;/head&gt;  
> ...

==&gt; External (link element with href to css file)

> &lt;head&gt;  
> &lt;**link** rel="stylesheet" href="**styles.css**"&gt;  
> &lt;/head&gt;

3) It seems we can animate chains of transitions by listing them (<https://css-tricks.com/using-multi-step-animations-transitions/>)?

==&gt; First, its seems CSS works a little “backwards” (it defines an end-frame target values for properties and transition properties separately)?

> .box {  
> width: 150px;  
> height: 150px;  
> background-color: red;  
> transition: 1s;  
> }

> .box:hover {  
> width: 300px;  
> background-color: orange;  
> }

==&gt; This seems to mean that “on hover” the width shall change to 300 and background-color to orange?

==&gt; BUT: In “.box” the transition is set to 1 second duration.

==&gt; So - The CSS rendering interprets this as when making the transition from “.box” initial values to “.box:hover” values it shall animate the transition over 1 second?

==&gt; Further, if we define the transition property to be a list, then we get a multi-step transition (each transition defining what proper values to “animate”=

> ...  
> transition:  
> /\* step 1 \*/  
> width 1s,  
> /\* step 2 \*/  
> background 0.5s 1s;  
> }

> .box:hover {  
> width: 300px;  
> background-color: orange;  
> }

==&gt; Now “on hover” will execute the transition where the “width” property first animates to 300 over 1 second.

==&gt; And then - the background color animates to orange over one second (with 0.5 seconds initial delay)

==&gt; This implicit “transition” function and parameters is a little odd?

...

4) Consider we should thus be able to write an app that animates HTML elements and thus can show animated system models (e.g., messaging, imperative statement execution…)?

…

5) Consider ways to define system models and animations in HTML and CSS for view in the animation app?

…

6) Consider if we can write the animation app in Elm?

==&gt; The seems to be a try to provide Css style processing into Elm using a library (<https://github.com/rtfeldman/elm-css>)?

==&gt; Although unclear if it supports CSS 3 animation, transition etc?

==&gt; This seem to be a try to provide Elm css animation using an elm library (<https://github.com/mdgriffith/elm-style-animation>)?

…

…

Consider to elaborate on this idea to implement system model or algorithm animation app in HTMML using CSS animations?

...

{% endraw %}
