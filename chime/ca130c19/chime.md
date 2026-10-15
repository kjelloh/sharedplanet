# Todo: Programming - Consider to design a "task-pump" for build-tool-chain members to post build tasks for dispatching by threads, processes or grid nodes?

```#ca130c19``` *As of 2015-12-13 22:25*

[mail plain/text](mail.txt)

{% raw %}
When thinking about a ”dream build environment” an idea popped up that maybe we can think of concurrent build tasks as functors posted to a task-queue for dispatching by concurrent operations?

1) Consider to model any build as a chain of operations layered into domains of representations

==&gt; Pre-processing domain  
==&gt; Front-end compilation domain  
==&gt; Back-end compilation domain  
==&gt; Target linking domain

2) Each domain performs build operations on modules or units (e.g. cpp-files)

==&gt; Each module build operation normally does not depend on other module builds and may thus be down concurrently (e.g. pre-processing a cpp-file or compiling a preprocessed cpp-file)  
==&gt; Using pre-compiled headers (pch-files) module dependencies may occur (several modules may try to build the same pch.file).  
==&gt; Darwinet would branch on same file (e.g. pch-file) write by different MIV instances which may be inefficient but not an error (same file)

3) Thus build operations may be prosted to a build-operation-queue for dispatching and processing by concurrent build members.

==&gt; Each tool-chain-domain posts module build operations to the queue.  
==&gt; Each build-member dispatches an operation and performs it.  
==&gt; The result of a build operation is a new operation portsed to the queue?  
==&gt; Build is done when all build-members are idle and the queue is empty?

4) We seem to need a scheduler and a mechanism to synchronize depended build operatons?

==&gt; We may want a module-compile to wait for a pre-comiled-header to be build (the build-operation needs to know if another build is working on creating the shared pch).  
==&gt; Synchronization may be made using ”Futures” queued by ongoing concurrent build-operations (the future defines what will be delivered when operation succeeds).  
==&gt; Each build-task thus needs to search for dependencies on currently queued futures and register for the results it is dependent on.  
==&gt; When a build task finalizes it signals all registered listeners (depended build-operations) and optionally posts new build-tasks to the queue.

5) The build-operation-queue should be designed to enable sharing by interprocess threads, build platform processes and grid-build platform members.

==&gt; It should be possible to design the build-operation-queue so that threads may share it?  
==&gt; The same design should enable several processes to share it?  
==&gt; If we design it carefully the same design may be used for several computers (grid-build platforms) to share it?

==&gt; Consider the build-operation-queue to be P2P-services using REST interfaces?  
==&gt; Or should one computer be the ”master” controlling a master queue with all ”slaves” (threads, processes, computers) accessing it through REST interfaces?  
…

Elaborate on this idea to see if this is something to work more on?

a) Consider to use OLE Automation to generate IDE-native builds for windows IDEs?

==&gt; Visual Studio is a COM Automation Server https://social.msdn.microsoft.com/Forums/vstudio/en-US/eb4f6ed3-c753-4d0c-b5f7-1ef36f92b8c6/programmatically-start-vs-and-attach-it-to-a-process?forum=vsx)?  
...

{% endraw %}
