# Todo: Programming C++ - Consider to create a "React Like" C++ GUI framework that views and operates on an Immutable Persistent Data Structure?

```#93abb6f6``` *As of 2017-01-29 15:44*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to think about a design for a C++ GUI framework that enables implementation of a View and Control of an Immutable Data Model?

1) Consider how a C++ version of Javascript React may look like?

==&gt; React seem to produce GUI updates based on a diff of last updated state and the new state (state itself being immutable)?

2) Consider to study the Elm language model of GUI update (which is also producing a mutable GUI based on new instances of an Immutable Data Model)?

==&gt; Also see ”Todo: Darwinet - Consider to apply the Elm language Model, Update, View architecture for Darwinet MIV, Update View?"

==&gt; Elm seem to focus very hard on Model, View and Update?

==&gt; The View in Elm seems to be something that takes an Immutable model and creates an Immutable instance of html code?

==&gt; The Model in elm seems to be an immutable data type of any structure (it seems to be up to the view to map it into html)?

==&gt; The Update in Elm seems to be something that takes an action and a model and creates a new model based on the action?

==&gt; It seems Elm is an example of desgning a language semantics to express Functional Reactive Programming (<https://en.wikipedia.org/wiki/Functional_reactive_programming>)?

…

…

Consider to delve deeper into this idea of aiming for a C++ framework to build a GUI that views and interacts with an Immutable Data Model?

...

{% endraw %}
