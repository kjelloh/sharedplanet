# Todo: Darwinet - Consider to compare and possibly apply the "Flux" design pattern for MIV views?

```#a74330d0``` *As of 2016-12-07 12:53*

[mail plain/text](mail.txt)

{% raw %}
it seems the Facebook ”Flux” and ”React” approach to process user UI views of shared store states is something that relates very much to how we want Darwinet MIV views and state mutations (delta applications)?

1) The ”Flux” design patterns seems to be well described here (<https://facebook.github.io/flux/docs/overview.html>)?

==&gt; This seems to be a good talk on Facebook ”Flux” and ”React” (<https://youtu.be/nYkdrAPrdcw?list=PLb0IAmt7-GS188xDYE-u1ShQmFFGbrk0v>)?

2) They seem to stress the point of ”Flux” differs from the MVC pattern in that all Actions (external or user input) are dispatched the same way (as opposed to MVC idiom whene Model-view interactions are double directed)?

==&gt; It seems the motivation for Flux is to adress the cross coupling problem of scaled (multi-view) MVC?

![](<MVC model-view double direction interaction problem.tiff>)

==&gt; Note how hard it is to detect model-view-update loops (model updates view that updates other model that updates third model that updates first model again)?

==&gt; They seem to state why ”MVC Don’t Scale” at about 7:40 into the video (<https://youtu.be/nYkdrAPrdcw?list=PLb0IAmt7-GS188xDYE-u1ShQmFFGbrk0v>)?

==&gt; They seem to say that - the code become fragile because in MVC designs it was har to predict cascading Model-view cross-interactions?

==&gt; While in Flux User Input Actions are dispatched in the same pipe as any other external actions is (decoupling MVC model and view callbacks)?

![](<Flux design pattern single action dispacther.tiff>)

==&gt; Facebook seem to combine two new idioms - The FLYx and the REACT idiom?

![](<Facebook FLUX and REACT.tiff>)

==&gt; So Flux seems to change MVC so that the View and the Model are decoupled by an Action dispatcher (creating ”Single directional data flow”)?

==&gt; And the REACT turns MVC mutable views (imperative state mutations) into single-state (declarative) views (but still only update the Diff)?

==&gt; At about 30:35 into the video they describe how REACT View update only renders the ”Diff”?

![](<Facebook REACT diff view update.tiff>)

==&gt; So, although the view is fed the whole current state - only the state change is rendered?

==&gt; Consider how this relates to Darwinet MIV state change should trigger a View update?

==&gt; Consider how Darwinet arrives at a new state by applying the actual diff (so the diff is already known)?

==&gt; Consider how this makes it easy to implement the REACT idiom for a Darwinet MIV view?

...

3) Consider how this may be applied to Darwinet Delta -&gt; MIV -&gt; View implementation?

==&gt; Consider the Flux ”Action” is a Darwinet Delta?

==&gt; Consider the Flux ”Store” is a Darwinet MIV?

==&gt; Consider the Flux ”View” is a Darwinet MIV View?

…

Consider to delve into this idea of applying the FLUX and REACT idioms when designing Darwinet?

...

{% endraw %}
