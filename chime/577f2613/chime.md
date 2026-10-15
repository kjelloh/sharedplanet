# Todo: Consider Tha-modelling command line tools arguments into inferred and user editable GUI front ends?

```#577f2613``` *As of 2019-03-06 21:04*

[mail plain/text](mail.txt)

{% raw %}
Consider we should be able to Tha-model the arguments to command line tools and then from that infer a GUI that a user may then edit to good usability?

1) consider a Tha-model of command line tool arguments should be basically a Product with Products of SUMs if the options?

==&gt; It seems each possible argument name should be a Pair of a name and a SUM of its possible values?

==&gt; It seems the whole argument list should be a meta-Product of interdependent argument name-value pairs?

==&gt; Consider we need value-dependent meta-values (types) to handle restrictions on what combinations of arguments that are actually allowed?

...

2) Consider how we may infer a GUI based on the Tha-model of the command line argument list?

==&gt; Consider the Tha-model in itself will contain each argument options as well as the restrictions on valid combinations of arguments and values?

==&gt; Consider a way to infer a GUI with, let say, columns of argument options (so the user may choose the argument line of choice)?

==&gt; Consider we want the Tha-model of the command line artguments to also be able to model aggregates of ready-to-use operations (combinations of arguments with a specific outcome)

...

3) Consider to model the command plus the argument list as a "morphism" (a function) to enable function composition of command line operations?

...

4) Consider the inferred GUI to be edited by the user into a layout of choice?

==&gt; Consider to model the GUI as meta-layers of compositions of layers below?

==&gt; Consider Products can be mapped to any suitable Product widget (row, column)?

==&gt; Consider SUMs can be mapped to any suitable SUM (option) widget (drop-down-list, option-wheels, option-buttons, menus)?

==&gt; Consider higher meta-layers maps to widget composition in the same way as basic Product and SUM widgets (but now with row or column widgets and suitable option-wheels from widget SUMs)?

...

{% endraw %}
