# Todo: Consider Open Source CLI controlled and HTML5 (Javascript) based video editor "Editly" for inspiration for my "composable" video editor?

```#980d71be``` *As of 2020-11-11 18:57*

[mail plain/text](mail.txt)

{% raw %}
I want to be able to create videos using Tha based functional composing of video clips and transformations.

==&gt; Also see "Todo: Consider to switch from JoyShare Media Cutter to LosslessCut for my video recording tool chain to pre-cut recorded video to store only what I can use?"

==&gt; Also see "Todo: Consider to try out "Joyoshare Media Cutter for Mac" and see if I can use it to do lossless cut-down of raw video to reduce video I actually keep for video editing?"

==&gt; Also see "Todo: Consider to find video editing tools to 1) Save only raw footage go good quality and 2) Automate video cutting using pre-defined story-line templates"

==&gt; Also see "Todo: consider to understand video rendering, streaming, encoding, compressing and persistent storage?"

1) Consider Open Source CLI controlled and HTML5 (Javascript) based video editor "Editly" on GitHub (<https://github.com/mifi/editly> )?

> *"Editly is a tool and framework for declarative NLE (non-linear video editing) using Node.js and ffmpeg. Editly allows you to easily and programmatically create a video from a set of clips, images, audio and titles, with smooth transitions and music overlaid*.*"*

==&gt; It seems Editly processes a json5 file that defines what and how to cut together a video (<https://github.com/mifi/editly/blob/master/examples/commonFeatures.json5> )?

> { // width: 2166, height: 1650, fps: 30, width: 720, height: 1280, fps: 30, outPath: './commonFeatures.mp4', // outPath: './commonFeatures.gif', audioFilePath: './assets/High &#91;NCS Release&#93; - JPB (No Copyright Music)-R8ZRCXy5vhA.m4a', defaults: { transition: { name: 'random' }, layer: { fontPath: './assets/Patua_One/PatuaOne-Regular.ttf' }, }, clips: &#91; { duration: 3, transition: { name: 'directional-left' }, layers: &#91;{ type: 'title-background', text: 'EDITLY\\nVideo editing framework', background: { type: 'linear-gradient', colors: &#91;'#02aab0', '#00cdac'&#93; } }&#93; }, { duration: 4, transition: { name: 'dreamyzoom' }, layers: &#91;{ type: 'title-background', text: 'Multi-line text with animated linear or radial gradients', background: { type: 'radial-gradient' } }&#93; }, { duration: 3, transition: { name: 'directional-right' }, layers: &#91;{ type: 'rainbow-colors' }, { type: 'title', text: 'Colorful backgrounds' }&#93; }, { duration: 3, layers: &#91;{ type: 'pause' }, { type: 'title', text: 'and separators' }&#93; },  
> { duration: 3, transition: { name: 'fadegrayscale' }, layers: &#91;{ type: 'title-background', text: 'Image slideshows with Ken Burns effect', background: { type: 'linear-gradient' } }&#93; }, { duration: 2.5, transition: { name: 'directionalWarp' }, layers: &#91;{ type: 'image', path: './assets/vertical.jpg', zoomDirection: 'out' }&#93; }, { duration: 3, transition: { name: 'dreamyzoom' }, layers: &#91;{ type: 'image', path: './assets/img1.jpg', duration: 2.5, zoomDirection: 'in' }, { type: 'subtitle', text: 'Indonesia has many spectacular locations. Here is the volcano Kelimutu, which has three lakes in its core, some days with three different colors!' }, { type: 'title', position: 'top', text: 'With text' }&#93; }, { duration: 3, transition: { name: 'colorphase' }, layers: &#91;{ type: 'image', path: './assets/img2.jpg', zoomDirection: 'out' }, { type: 'subtitle', text: 'Komodo national park is the only home of the endangered Komodo dragons' }&#93; }, { duration: 2.5, transition: { name: 'simplezoom' }, layers: &#91;{ type: 'image', path: './assets/img3.jpg', zoomDirection: 'in' }&#93; },  
> { duration: 1.5, transition: { name: 'crosszoom', duration: 0.3 }, layers: &#91;{ type: 'video', path: 'assets/kohlipe1.mp4', cutTo: 58 }, { type: 'title', text: 'Videos' }&#93; }, { duration: 3, transition: { name: 'fade' }, layers: &#91;{ type: 'video', path: 'assets/kohlipe1.mp4', cutFrom: 58 }&#93; }, { transition: { name: 'fade' }, layers: &#91;{ type: 'video', path: 'assets/kohlipe2.mp4', cutTo: 2.5 }&#93; }, { duration: 1.5, layers: &#91;{ type: 'video', path: 'assets/kohlipe3.mp4', cutFrom: 3, cutTo: 30 }&#93; },  
> { duration: 3, transition: { name: 'crosszoom' }, layers: &#91;{ type: 'gl', fragmentPath: './assets/shaders/3l23Rh.frag' }, { type: 'title', text: 'OpenGL\\nshaders' }&#93; }, { duration: 3, layers: &#91;{ type: 'gl', fragmentPath: './assets/shaders/MdXyzX.frag' }&#93; }, { duration: 3, layers: &#91;{ type: 'gl', fragmentPath: './assets/shaders/30daysofshade_010.frag' }&#93; }, { duration: 3, layers: &#91;{ type: 'gl', fragmentPath: './assets/shaders/wd2yDm.frag', speed: 5 }&#93; },  
> { duration: 3, layers: &#91; { type: 'image', path: './assets/91083241_573589476840991_4224678072281051330_n.jpg' }, { type: 'news-title', text: 'BREAKING NEWS' }, { type: 'subtitle', text: 'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.', backgroundColor: 'rgba(0,0,0,0.5)' } &#93; },  
> { duration: 3, layers: &#91; { type: 'rainbow-colors' }, { type: 'video', path: './assets/tungestolen.mp4', resizeMode: 'contain', width: 0.4, height: 0.4, top: 0.05, left: 0.95, originY: 'top', originX: 'right' }, { type: 'title', position: 'bottom', text: 'Picture-in-Picture' } &#93; },  
> { duration: 3, layers: &#91;{ type: 'editly-banner' }&#93; }, &#93;,}

==&gt; Consider this youtube video "EDITLY: Super Quick Command Line Video Creator (FREE!)" created programatically using Editly (<https://youtu.be/LNeclLkxUEY> )?

2) Consider if I can make Editly programmable by enabling it to process an "Edit Decision List" (EDL) (<https://en.wikipedia.org/wiki/Edit_decision_list> )?

> *"An edit decision list or EDL is used in the post-production process of film editing and video editing. The list contains an ordered list of reel and timecode data representing where each video clip can be obtained in order to confo*rm the final cut.*"*

> *"**EDL formats such as CMX, GVG, Sony, Final Cut Pro, and Avid are similar but can differ in small (but important) ways. Particular attention should be paid to reel naming convention.**"*

...

{% endraw %}
