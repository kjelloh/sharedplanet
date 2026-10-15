# Todo: Darwinet - Consider the MIV is actually immutable (each delta creates a new MIV) making Darwinet suitable for a function composition  design?

```#99684f2f``` *As of 2017-01-15 19:35*

[mail plain/text](mail.txt)

{% raw %}
Could we argue that a Darwinet MIV is actually immutable in that each Delta in fact creates a new MIV (the MIV as it is in the new state)?

1) Consider to relate to this talk at roughly 36:00 where she talks about the Elm language UI model (<https://www.youtube.com/watch?v=X25xOhntr6s>)?

==&gt; Consider this Elm Immutable Model View to be how we actually would like a Darwinet MIV view should behave?

![](<Elm Immutable Model View.tiff>)

==&gt; ”Events” in Darwinet are in fact Deltas (locally or network received)?

==&gt; ”Immutable MODEL” in Darwinet is the MIV?

==&gt; ”Update Function” is in Darwinet the application of the received Deltas?

...

{% endraw %}
