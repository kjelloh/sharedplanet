# Todo: Git - Consider to understand Git by understanding its internal model of data and behaviour?

```#b9c29d8b``` *As of 2020-05-30 14:14*

[mail plain/text](mail.txt)

{% raw %}
I always gets confused by GIT and easily end up in strange behaviour and I need to get rid of this confusion.

1) Consider this youtube video "Lecture 6: Version Control (git) (2020)" (<https://youtu.be/2sjqTHE0zok> )?

==&gt; At around 15:20 he seems to give a goos model of GIT as pseudo code defining Gits internals "types" (<https://youtu.be/2sjqTHE0zok?t=922> )?

> *type blob = array&lt;byte&gt;*  
> *type tree = map &lt;string, tree | blob&gt;*  
> *type commit = struct {*  
> *parents = array&lt;commit&gt;*  
> *author = string*  
> *message = string*  
> *snapshot = tree*  
> *}*

> *So, GIT models a file as a "blob" which is just a binary array (file) of bytes. Git models each folder as a mapping between a name (file or folder name) and a tree or a blob.*

> *Now a commit is "just" a record that refers to parent commits (one or many depending on merge of branches or not), a snapshot of the tree committed together with metadata about who made the commit (author) and a message (comment) about what the commit is "about".*

> *Further, Git uses a model to store bobs, trees and commits to file storage using additional data types.*

> *type object = blob | tree | commit*

> *type objects = map &lt;string, object&gt;*

> *def store(object o) {*

> *id = sha1(o)*

> *objects&#91;id&#93; = o*

> *}*

> *So simple and elegant actually. So GIT stores objects that in turn is one of blob, tree or commit. And further, the storage of objects are a mapping between a key (named identifier) and corresponding object. Where the named identifier (the key) is "simply" the SHA1 hash of the object itself.*

..

{% endraw %}
