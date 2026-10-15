# Todo: Darwinet - Consider to delve deeper into existing both text and binary file delta algorithms?

```#18d5bcb6``` *As of 2016-05-06 17:32*

[mail plain/text](mail.txt)

{% raw %}
Really browsing for version control systems I stumbled cross some interesting leads to existing delta tools and algorithms.

1) This seem to be an interesting thesis on binary delta diff algorithm (<http://www.daemonology.net/papers/thesis.pdf>)?

2) The author has implemented this algorithm in the tool bsdiff published here (<http://www.daemonology.net/bsdiff/>)

3) Compression algorithms seem to be based on a pre-step creating a delta-byte-stream (<https://en.wikipedia.org/wiki/Delta_encoding>)?

==&gt; Consider to study such delta-streams to see how this may be applied to binary file diffs?

==&gt; E.g. could it be that comparing compressed files is better than comparing original files?

4) Consider to study VCDIFF, described in RFC 3284 (<https://tools.ietf.org/html/rfc3284>)

*"A common way to deal with memory limitation is to*

*partition an input file into chunks called "windows" and process them*

*separately. Here, except for unpublished work by Vo, little has been*

*done on designing effective windowing schemes. Current techniques,*

*including Vdelta, simply use source and target windows with*

*corresponding addresses across source and target files."*

==&gt; Note the mention of Windows Partitioning?

==&gt; Is there a c++ library for this diff-format?

5) Consider RFC 3229, "Delta encoding in HTTP" (<https://tools.ietf.org/html/rfc3229>)?

6) This seem to be a good wikipedia page about the text diff utilities (<https://en.wikipedia.org/wiki/Diff_utility>)?

...

Consider to delve deeper into existing diff algorithm to see if we can find one to use for Darwinet?

{% endraw %}
