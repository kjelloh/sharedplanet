# Todo: Darwinet - Consider to enable File System to understand what files are "temporary" (dead) and does not need to be synchronised (not evolve)

```#64ce946e``` *As of 2016-01-10 11:48*

[mail plain/text](mail.txt)

{% raw %}
Thinking about how much more efficient a version control system is if only “source files” are tracked, it should be a good idea to enable also a Darwinet File System to understand some files as “temporary”?

1) All tools generate temporary files that we have no interest in tracking or synchronising to other nodes (e.g. compiler intermediates, word backup temporary or Doc-To-Help compiler temporaries).

2) In fact - even generated files (e.g. exe- and dll-files, doc-to-help targets) may at times not be of interest to track at the location they are created but rather in another location where they are deployed?

3) Consider to design an easy-to-use and easy-to-understand mechanism in Darwinet File System to mark what files are “source” (required to synchronise with a delta-history) and which are “generated” and treated as momentary instances?

4) It seems we should want to be able to do the same with all MIV content (some data are “source” and others are just temporaries that exist just momentarily during run-time)?

5) So, we have at least two “data-creatures” - Evolving Data and Momentary Data?

6) If so, it should be the model (M) that defines if a data is Evolving (alive) or Momentary (dead)?

==&gt; The benefit of having M define this property is that we then are able to treat change of this property (dead &lt;—&gt; alive) change as a delta and enable time-travel to create the correct view of the MIV?

7) We would then be able to provide models for known tools to identify alive and dead data (e.g. word, Visual Studio, Doc-to-help)

==&gt; Would this make it possible to have Darwinet automatically configure alive and dead files when a the user decides to populate a domain with a tool?

…

Consider to elaborate on this idea of having the MIV “know” what data is Evolving and what data is just Momentary?  
...

{% endraw %}
