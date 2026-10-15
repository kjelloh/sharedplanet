# Todo: Darwinet - Consider the importance to automate (or make it trivial) to NOT synchronise "generated" (local bookkeeping) data and files?

```#637cb3f5``` *As of 2017-03-18 15:42*

[mail plain/text](mail.txt)

{% raw %}
It seems we should make it a key part of Darwinet synchronisation mechanism (both data and files) to really understand (and make correct) what to NOT synchronise (locally run-time created temporary data, files and state)?

1) Consider to study Programming tool-chains (and IDEs) to see how source files are shared but generated files are not?

==&gt; Consider to delve into “Todo: C++ Visual Studio - Consider ways to separate source files and output files in the same way Xcode does (enabling projects to be synced excluding the generated files)”

==&gt; Consider the problem of sharing with Sync or Dropbox is the same we like to have Darwinet solve in a trivial (automated) way?  
…

2) Consider one way is to identify “Platform” data as NOT to be synchronised?

==&gt; Consider the example of Visual Studio where the IDE defines compiled binaries and project database as truly “local state” (Should NOT be synced even with other nodes with Visual Studio installed)?

3) Consider categories of data that defines how to synchronise it?

==&gt; Consider “Local State” is data that is Node-only data (It should not be synched at all as it is a true local state)?

==&gt; Consider “Local State” in Darwinet means data totally detached from Darwinet?

==&gt; Consider “User State” is data that is synchronised but only accessible through views used by that user?

==&gt; Consider Darwinet Views to be layers of User on-top-of Application on-top-of Node on-top-of Domain?

…

…

Consider to delve into this issue of how Darwinet must make it automatic (or at least trivial) to know what files to sync and what files to expose in the file system view on each node in the domain to ensure we do NOT synchronise files that are in fact “local state”?  
...

{% endraw %}
