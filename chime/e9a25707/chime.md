# Todo: Darwinet - Consider how darwinet file system addresses conflicting asynchronous file system mutations?

```#e9a25707``` *As of 2016-05-05 20:07*

[mail plain/text](mail.txt)

{% raw %}
When studying proposed Boost AFIO (Asynchronous File System) motivations I came to think how Darwinet actually will have to adress merging of conflicting file system mutations (as part of general MIV merging that relates to the file system)?

1) Consider to study the AFIO library to get introduced to File System Races and how AFIO tries to address them?

==&gt; Consider this talk at Cppcon 2015 (https://www.youtube.com/watch?v=uhRWMGBjlO8)?  
==&gt; Consider this talk at ACCU 2016 (https://www.youtube.com/watch?v=elegewDwm64)?

==&gt; Consider to study the source code at github (https://github.com/ned14/boost.afio)?

2) Consider how multi-core and distributed computing adds more and more cases of Concurrency conflicts for different aspect of shared resources?

==&gt; Conflicting state of File System mutated by parallel operations?  
==&gt; Conflicting memor cache for multi-core processing?  
==&gt; Conflicting state of shared memory in multi-threaded applications?  
….

3) Consider to what degree Darwinet post-synchronization idiom is able to adress these parallel mutated shared state Issues?

==&gt; Consider there are cases where Darwinet approach to process as-if-private-state then merge parallel mutations is the ”best” choice?  
==&gt; Consider where the Darwinet approach can never work (to much overhead or will-never-catch-up)?  
…

…

Consider to elaborate on more such similar patterns of conflicting shared states Issues and how Darwinet may or shall adress them?  
...

{% endraw %}
