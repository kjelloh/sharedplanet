# Todo: Programming - Consider there are three C++ idioms for reading and writing files?

```#41022431``` *As of 2016-06-03 13:11*

[mail plain/text](mail.txt)

{% raw %}
I seems, inspired by a tweet, that there are three C++ idioms for reading and writing files?

==&gt; Also see “[Todo: Programming - Consider to propose that a C++ File System is actually a special case of a Composite Data Model accessible through key-paths?](../dfcb19b0/chime.md)"

1) Consider to delve into the C++ code in this tweet about bench marking three C++ file handling on different platforms (<https://cristianadam.eu/20160410/c-plus-plus-i-slash-o-benchmark/>)?

==&gt; The C-idiom file idiom with the API of fopen, fread, fwrite.

==&gt; C++ idiom file stream idiom with the API of std::ifstream and std::ofstream.

==&gt; The POSIX idiom with the API of open, read, write.

2) Consider that Boost File System is actually about interacting with the System of Files, not reading or writing the actual files per se (<http://www.boost.org/doc/libs/1_34_0/libs/filesystem/doc/index.htm>)?

*“The Boost Filesystem Library provides portable facilities to query and manipulate paths, files, and directories"*

==&gt; Consider a "File System” to be about the API to manipulate organisation of files, not mutating of the files themselves?

==&gt; Boost Filesystem is actually all about file paths and mutation of storage organisation (directory structures)?

3) Consider that also the experimental C++17 proposed File System that is more-or-less the Boost Filesystem (<http://en.cppreference.com/w/cpp/filesystem>)?

“The Filesystem library provides facilities for performing operations on file systems and their components, such as paths, regular files, and directories”

==&gt; This seem to confirm that a File System is all about file organisation, not file mutation per se?

…

Consider to delve deeper into this notion of C++ having three different idioms for file mutation?

...

{% endraw %}
