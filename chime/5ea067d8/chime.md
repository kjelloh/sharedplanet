# Todo: Consider the first POC for an ffmpeg based snippet generator and snippets-to-video tool?

```#5ea067d8``` *As of 2026-08-03 17:44*

[mail plain/text](mail.txt)

{% raw %}
I want to semi-automate my youtube video creation as I find video editors to primitive and boring to use.

0) COnsider what could serve as a 'seed' to get going on this idea?

==&gt; Consider a github repo?

==&gt; Consider a manual test using a video file and calling ffmpeg CLI-tool?

==&gt; Consider it as a tool and give it a name?

==&gt; Consider to decide if the tool should generate text arguments an feed to CLI-ffmpeg or be a C++ app interacting with ffmpeg library?

1) So what initial basic functionality would I like to have to create simple youtube videos really easy?

==&gt; We would like to be able to define a set of video files to use as snippet sources?

==&gt; We would like to be able to mark locations in video files 'of interest'?

==&gt; We would like to turn 'video locations of interest' into vieo-snippets?

==&gt; We would like to define a sequence of video-snippets?

> *"The basic idea is to separate the marking of locations from the operation to create snippet-ranges. In this way we can manually place markers at locations. Or we can imagine some automation that creates markers at locations with loud noises (e.g., to mark at music beats) or at locations with some large change in the video itself (e.g., turning camera to a new scene)?*

> *Then I imagine we can manually define ranges based on selected location markers? Or we can provide operations that can select markers and automate creation of snippet-ranges (e.g., pick a half-second snippet at each beat-marker)?**"*

2) Consider an editor based on my four meta tier model but for videos?

==&gt; It seems tier 0 consists of 'snippets' (file, in-point, out-point)?

> *"I also need 'text' values and 'number' values to provide parameters to snippets. That is, I need values to define video file and the in and out points?"*

==&gt; It seems tier 1 consists of the snippet type (snippet constructors)?

> *"In total we get text-type, number-type and snippet-type?"*

==&gt; It seems tier 2 consists of the AND-kind and OR-kind?

> *"So with the AND-kind and OR-kind we can construct this-and-this-and-this-types as well as this-or-this-or-this types?*  
> *Do we also need ''kinds' to construct text-types and number-types?"*

==&gt; It seems tier 3 consists of 'kind constructors'?

> "It seems this tier is populated with things that corresponds to what the C++ template' keyword (operator) defines?

> That is something on tier-3 that we can 'call' with types and values and have it produce a type-constructor (tier-2)"

==&gt; It seems tier 4 consists of 'generics'?

> *"It seems this corresponds to C++ 'template' operator. That is a function that we define to take types and values and create something we can call to create a type constructor.*

> *It seems we need to develop a terminology to talk about all this stuff?*

> *The C++ 'template' keyword seems to live on tier 4? We can use it to construct a tier 3 'thing'. This thing on tier 3 can construct type-constructors?*

> *"*

==&gt; Suppose we imagine a user interface with five panes?

> pane 4: Thing(s) used to create (define) kind-constructors?

> This is already mind-blowing  
> Whaty on earth could this even mean in the world of video editing?

> pane 3: Current kind constructors

> What could a 'kind constructor' imply in our world of tier 0 video snippets aggregations?  
> What can we understand if this is what a template-construct creates in C++?  
> It seems we have functions: types and/or values -&gt; type-constructor  
> The mind explodes!

> pane 2: Current 'kinds' (type constructors)

> How can we imagine to visualise and work with a set of 'kinds'?  
> What would those 'kinds' represent in our video editor?  
> Especially 'kinds' created by tier 3 'kind constructors'?  
> This gets complicated fast!

> pane 1: Current 'types'. I imagine mostly different topologies of vide snippets?  
> The obvious AND-type is the snippet-sequence?  
> Can we also imagine some OR-type where we can try out different alternative snippets in some topology?

> pane 0: The 'real deal' with actual video snippet aggregations

> So is there only one resulting video (snippet aggregation)?  
> Or can we imagine to instantiate several 'types' (different type instantiations)?  
> It seems even if we allow only one, this may be a type with OR-type-value contents) so we can 'or-ing' options anyhow?

...

{% endraw %}
