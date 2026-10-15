# Todo: Programming - Consider to find a way to manually edit a C++ file into a "Pandora View" of that file transformed into byte code?

```#54157cbf``` *As of 2017-04-17 15:14*

[mail plain/text](mail.txt)

{% raw %}
So, what tool can we imagine to use to manually produce a proof-of-concept of how a C++ File is transformed into byte code?

==&gt; Also see ”[Todo: Programming - Consider to check out the C++ visualisation and media library Cinder?](../b5bb37e7/chime.md)"

==&gt; Also See ”[Todo: Programming - Consider to define transform of C++ code into executable code as a stack-of-transformations?](../a2b1e6e4/chime.md)”

==&gt; Also See ”[Todo: Programming - Consider to re-visit Pandora and design it as part of a Dream C++ IDE?](../92b081ea/chime.md)”

1) Consider to use RAD Studio Firemonkey 3D components?

==&gt; Is there a way to work around the problem that we can’t format the text on the panes (RichEdit is not available as Firemonkey component)?

==&gt; It seems TMS Software provides a TTMSFMXRichEditor in their ”TMS FMX UI Pack" (<https://www.tmssoftware.com/site/tmsfmxpack.asp?s=fmxricheditor#features>)?

==&gt; It seems to cost 175 Euros?

==&gt; It seems we may use a Trial of ”TMS FMX UI Pack” before actually buying it?

==&gt; This seems to be the documentation of ”TMS FMX RichEditor" (<http://www.tmssoftware.biz/download/manuals/TMSFMXRichEditorDevGuide.pdf>)?

==&gt; It seems to have been a member of since version v2.8.0.0 (<https://www.tmssoftware.com/site/tmsfmxpack.asp?s=history>)?

==&gt; It seems we may place any 2D component in a 3D view by placing it on a ”FMX.Layers3D.TLayer3D” (<http://docwiki.embarcadero.com/RADStudio/Seattle/en/Creating_a_2D_Interface_in_a_3D_Application_(FireMonkey_3D_Tutorial))?>

> > ”*A 3D application cannot directly use 2D components such as buttons or lists. If a 2D component is dragged and dropped on a 3D container, the component will not be rendered but it will appear in the Structure View as a child control. However, there is a simple way to deal with this problem, by creating a bridge between the 3D and 2D scenes. FireMonkey provides the FMX.Layers3D.TLayer3D component for this purpose.*"

==&gt; It seems we may adjust the Opacity of the TLayer3D component (<http://docwiki.embarcadero.com/Libraries/Seattle/en/FMX.Controls3D.TControl3D.Opacity>)?

==&gt; Which may enable us to make child TTMSFMXRichEditor appear as if on a transparent pane?

==&gt; **Consider to download the trial and text if we can place formatted source code on transparent text panes stacked in a 3D view?**

**WE ARE HERE...**

2) Consider to map html page into WebGL and implement it as an Electron App?

==&gt; This Github project seem to state that Electron works just as well with a 3D HTML page as an ordinary one (<https://github.com/jeromeetienne/electron-threejs-example>)?

> ”*Then to add three.js, just replace their index.html by a webpage doing 3d with webgl. As electron running chromium, it supports WebGL, WebAudio or WebRTC without issue.*"

==&gt; I was able to download the zipped project and execute it with my quick-start located electron command (See ””)

> kjell-olov-hogdahls-macbook-pro:.bin kjell-olovhogdahl$ cd ~  
> kjell-olov-hogdahls-macbook-pro:~ kjell-olovhogdahl$ cd Downloads/  
> kjell-olov-hogdahls-macbook-pro:Downloads kjell-olovhogdahl$ cd electron-threejs-example-master/  
> kjell-olov-hogdahls-macbook-pro:electron-threejs-example-master kjell-olovhogdahl$ ls  
> Makefile README.md index.html main.js package.json vendor  
> kjell-olov-hogdahls-macbook-pro:electron-threejs-example-master kjell-olovhogdahl$ **/Users/kjell-olovhogdahl/Documents/GitHub/electron/electron-quick-start/node_modules/.bin/electron .**

**==&gt; Note: The quick install of Electron installs to HIDDEN (!!) location ”/Users/kjell-olovhogdahl/Documents/GitHub/electron/electron-quick-start/node_modules/.bin/” (Why oh Why?)**

==&gt; Anyhow - the application is quite cool (it renders a 3D cube transparently on top of the Desktop (the app has no visible frames at all)

![](<Electron app example - rotating 3D cibe with no visibale app frame.tiff>)

==&gt; It seems the ” *CSS3DRenderer*” in three.js is what we should use (<http://www.html5gamedevs.com/topic/11910-embedded-html/>)?

> ”*In Threejs, they've got a real dedicated renderer, called CSS3DRenderer which abstract dynamic CSS3 manipulations with other renderer (webGL, canvas2D) same call signatures. But this renderer has very little methods to deal with in terms of 3D, therefore it supports every DOM HTML interactions.*"

==&gt; This seems to be a good introduction and explanation on how ot use *CSS3DRenderer *(<https://jeanlescure.io/blog/threejs-and-css-3d-transforms/>)?

==&gt; This seem to be a demo closest to what we would like to do with source code (<https://threejs.org/examples/css3d_periodictable.html>)?

![](httpsthreejs.orgexamplescss3d_periodictable.html.tiff)

==&gt; This seem to be good post with leads into what CSS3DRenderer in three.js is all about (<http://www.lab4games.net/zz85/blog/2015/10/17/why-i-think-the-three-js-css3drenderer-is-awesome/>)?

==&gt; This seem to be a talk ”Joshua Koo: Cascading Perspectives with THREE CSS3DRenderer - CSSConf.Asia 2014” related to CSS3Renderer (<https://youtu.be/adxGGAQMv_k>)?

==&gt; Consider this example where plain text is rendered onto a 3D cube (<http://mrdoob.com/lab/javascript/threejs/css3d/>)?

![](<CSS3D and three.js 2D text mrdob example.tiff>)

==&gt;

==&gt; Consider this blog-post ”Mixing HTML Pages Inside Your WebGL” (<http://learningthreejs.com/blog/2013/04/30/closing-the-gap-between-html-and-webgl/>)?

==&gt; Consider this example where he projects a whole Web-browser window onto a 2D pane inside a WebGL 3D world (<https://youtu.be/ScZcUEDGjJI>)?

==&gt; Consider this article ”Embedding webpages in a 3D Three.js scene” (<http://adndevblog.typepad.com/cloud_and_mobile/2015/07/embedding-webpages-in-a-3d-threejs-scene.html>)?

==&gt; Consider this Github project that actually creates interactive web-pahes in a 3D world (<https://github.com/jeromeetienne/threex.htmlmixer>)?

==&gt; Consider this example (<http://jeromeetienne.github.io/threex.htmlmixer/examples/basic.html>)?

==&gt; Consider this example (<http://jeromeetienne.github.io/threex.htmlmixer/examples/demo.html>)?

==&gt; Consider leads given in this Javascript MIT licensed package ”gl-css3d” for using CSS3D to render an HTML page onto a pane in WebGL 3D world (<https://www.npmjs.com/package/gl-css3d>)?

==&gt; This package seems to to ”assuming you are using stackgl gl-now/game-shell:”?

==&gt; Consider this Github project rendering text onto a 2D pane in 3D world using three.js (<http://stemkoski.github.io/Three.js/CSS3D.html>)?

![](<three.js 2D text example Stemoski Github.tiff>)

==&gt; It seems to be defined by this html-page (<https://github.com/stemkoski/stemkoski.github.com/blob/master/Three.js/CSS3D.html>)?

==&gt; And rendered by this JavaScript (

==&gt; Consider this github project is more effeicint and reason (<https://github.com/PixelsCommander/HTML-GL>)?

==&gt; It seems to suggest that html objects are rendered directly onto WebGL surfaces?

> > ”*Using HTML GL you still work with HTML/CSS as you are common to, but DOM elements are just facades to their WebGL represenations. These GPU accelerated textures are very effective from resources consuming perspective and are very cheap to transform or animate.*"

3) Consider to use the Qt 3D (<http://doc.qt.io/qt-5/qt3d-index.html>)?

==&gt; Consider to implement a cross-platform front-end to show a Pandora View of a selected pice of C++ Source Code?

…

4) Consider to use some 3D designer tool that is cheap and easy to use to make a Pandora View of a selected piece of C++ File?

…

5) Consider to use Clang Tooling to create C++ AST and then map scoped code to 3D stacked panes?

==&gt; Consider what it would actually take to apply Clang tooling to automatically format C++ code onto 3D stacked scope-panes?

...

…

Consider to delve into this idea to find a way to visualize a Pandora View of all transformation phases when turning a C++ file into byte code?

...

{% endraw %}
