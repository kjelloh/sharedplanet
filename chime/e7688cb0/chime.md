# Todo: Darwinet - Consider to treat Applications and Functors (Closures) as variants of the same concept "Executable Operation" interacting with Darwinet through Transactional- or Live Views?

```#e7688cb0``` *As of 2016-01-10 12:04*

[mail plain/text](mail.txt)

{% raw %}
It seems Darwinet could benefit from treating an Application and a Functor (Closure) as an Executable-Operation that just differs in how and where it executes?

1) An application often runs on the target platform by the user with a user interface and operates on files (but also on MIV if a Darwinet Enabled Application)

2) A functor (closure) is run by the Darwinet Engine and does not have a user interface (i.e. it may run on any node in the Domain as defined by the Grid-Computing mechanism)

3) But both interacts with the Darwinet Domain through views.

4) And the view may be a “Transactional View” where deltas are distributed at view close (generating only the net-result changes of all interaction during the view life)

5) Or the view may be a “Live View” where each change is recorded and synchronised within the domain at run-time.

6) An Application may be unaware it interacts with a Darwinet Domain by using Files that happens to be in a Darwinet Domain File System.

==&gt; Such an application operating through a “Transactional View” causes file changes to be recored as diffs from view open to view close (run-time changes not recorded)  
==&gt; A Programming IDE may operate through a “Live View” to enable changes to source code trigger build-operations on other nodes (grid-builds)

7) An Application may be unaware it interacts with a Darwinet Domain by using a DB interface that happens to be bound to a Darwinet Database

==&gt; Such an application may also operate on the Database through a Transactional- or Live-View?  
…

Consider to elaborate on this idea of treating Applications and Functors at some level as “equals” (different forms of executable operations) interacting with the Darwinet Domain trough Transactional- or Live Views?  
...

{% endraw %}
