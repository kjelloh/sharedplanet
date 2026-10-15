# Todo: Programming - Consider to propose that a C++ File System is actually a special case of a Composite Data Model accessible through key-paths?

```#dfcb19b0``` *As of 2016-06-03 13:10*

[mail plain/text](mail.txt)

{% raw %}
So, what can we learn by taking the view that a File System is actually just a special case of an instance of a Composite Data Model with members accessible by key-paths?

1) Consider to elaborate on the point that a File and a Folder are just composites in the tree of objects in the File System?

2) Consider to elaborate on the benefits of identifying more data objects that conforms to the same Composite Data Model as a File System?

==&gt; Consider the Windows Registry?  
==&gt; Consider an XML-file?  
==&gt; Consider an HTML-file?

3) Consider the problem of self-referencing members of Composite Data Models?

==&gt; Consider a member referenced by another member actually has two paths to the same element?  
==&gt; Consider this is the “problem” of file “short-cuts” (A file that is actually a proxy for another file/folder)?  
==&gt; Consider the problem of circular references (e.g. a file short-cut to a folder that aggregates the short-cut in its sub-tree)?  
…

4) Consider allowing mixing aggregated and referenced objects is the root to the problem of modelling composite data models?

==&gt; If only aggregated members where allowed all Composite Data Models would be top-down structures of single-instance members?  
==&gt; Allowing references as proxies for “real” instances confuses what path to an element is the “real” one (and what the effects of mutating a member are)?  
…

5) Consider allowing references introduces the problem of Identity and Ownership?

==&gt; Consider allowing references means the key-path to the element is not enough to identify the element?  
==&gt; Consider allowing references introduces the problem of deciding what Element Deletion means (deleting a proxy has no effect as the referenced element must remain)?

==&gt; Consider file references actually introduces exactly the same problems as pointers and references in computer programming?  
…

6) Consider to propose a Boost Library with Key-paths and Composites that is able to handle File Systems as justa special case?

==&gt; Consider such library to provide a common front end to allow creation, deletion and access to Model elements using key-paths?  
==&gt; Consider such a library to allow different back-ends for File System, Windows Registry or proprietary in-memory containers?  
==&gt; Consider such a library to provide some idiom for handling the difference between element proxies (references) and element instances?

==&gt; Consider to compare with the solutions proposed by C++ smart pointers for data objects?  
==&gt; Consider owning and non-owning references as provided by std::unique_ptr and std::shared_ptr (and for the same reason)?  
…

…

Consider to delve deeper into what we can learn to view a File System as an instance of a Composite Data Model allowing both element instances and element proxies (references)?  
...

{% endraw %}
