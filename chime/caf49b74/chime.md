# Todo: Dream C++ IDE - Consider a cut-and-paste function that adapts source code to the paste location (e.g. inline versus external definition of member methods)?

```#caf49b74``` *As of 2017-05-24 12:00*

[mail plain/text](mail.txt)

{% raw %}
It just occurred to me when copying code from the Testbench to Xcode project “/Users/kjell-olovhogdahl/BitTorrent Sync/XCode/MyDataModelPlayground/“ how nice it would be to be able to cut the code of an external method definition and be able to paste it as inline into the class (having the editor remove the class_name:: selector from the code)

1) Consider how to design an editor that enables a cut-and-paste of a method definition between in-class location and separate location?

==&gt; Consider this in-class definition

> c_iPosNodeDefinition\* addNodeDefinition(c_iPosNodeDefinition\* pNodeDefinition);

==&gt; And its corresponding declaration/definition separation?

> c_iPosNodeDefinition\* c_iPosNodeDefinitions::addNodeDefinition(c_iPosNodeDefinition\* pNodeDefinition) {...}

…

2) Consider what the Editor must know about the location of the source of the cut source code to be able to paste it correctly at a new location?

==&gt; Consider for a member method declaration the Editor must remember the class it was a member of?

==&gt; In fact, the Editor should save a reference to the AST source location to know things like class hierarchy and namespace hierarchy?

==&gt; Then it will be able to paste the code into another namespace location and adjust the namespace specifiers in the pasted code?

...

...

3) Consider to find more examples where the C++ Editor could adjust the pasted source code to the location?

TBD...

4) Consider to what degree the Pandora Scoped-Pane-Model would enable context-aware C++ source code cut-and-paste?

==&gt; The Pandora model knows the location and meta-data relations between source code scoped parts.

…

…

Consider to delve into this idea of having a C++ editor be context-aware of both source and target of cut-and-pasted source code to be able to transform the C++ code correct for the target (e.g., inline definition versus declaration + definition of class methods)?

...

{% endraw %}
