# Todo: Darwinet - Consider to design File System to support changes defines by Unix/Linux/DOS File System Commands?

```#6a720e85``` *As of 2016-02-15 19:19*

[mail plain/text](mail.txt)

{% raw %}
Would it prove to be a good idea to use Command Line File Command to identify File System mutation that we need to implement as Deltas?

1) Consider this Unix/Linux Tutorial to get leads to basic File System Commands (e.g. cp, mv, rm) (<http://www.ee.surrey.ac.uk/Teaching/Unix/unix2.html>)?

==&gt; cp (copy)

==&gt; mv (move)

==&gt; rm (remove)

==&gt; mkdir (Make Directory)

==&gt; rmdir (Remove Directory)

2) Elaborate what it would mean to not allow file mutation (i.e. a “Functional” File System)

==&gt; Does this even make any sense?

==&gt; Can we imagine “File Transforms” as functions?

==&gt; Can we imagine this would mean that the File on disk is just one file (all File transforms “in flight” are totally different files)?

==&gt; Would this mean that we need to chain File Transforms in code (and not through the File on disk)?

3) Consider to elaborate on the consequences and idiom that Darwinet ability to track File State leads to?

==&gt; A Saved File would be a file in a new state which in theory means a Darwinet Client could be able to access them as separate instances?

==&gt; A Renamed file is also a file in a new state (Clients would be able to track the file cross name changes)

==&gt; A Moved File would be a file in a new State (promisingly the same file at a new location in the open view)?

==&gt; A Copied file would mean the same file referenced from two locations in a view?

==&gt; Consider to compare to String Clone on Write (COW)?

==&gt; COW Strings are abandoned now for some reason in C++11, Should we thus avoid COW files to?

==&gt; Herb Sutter seems to argue COW strings are bad because they are inefficient in multithreaded environments?

…

Consider to elaborate on existing command line File Commands and relate them to Darwinet File System Deltas and suitable idioms for Darwinet?

...

{% endraw %}
