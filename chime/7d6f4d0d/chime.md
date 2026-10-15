# Todo: Programming - Consider to study issues with recognizing text (string) encoding and character set (script) when provided with raw input?

```#7d6f4d0d``` *As of 2016-08-07 13:44*

[mail plain/text](mail.txt)

{% raw %}
Could ti be a good idea to try to study, understand and document known or experienced issues with correctly recognizing the actual encoding and character set (script) of raw input of text (string)?

==&gt; Also see ”[Todo: Programming - Consider to investigate what Code Point(s) a character 'Ä' or string "Ä" gets in runtime and compile time scenarios in C++?](../91e2c282/chime.md)”

==&gt; Also see ”[Todo: Programming - Consider the code point and encode aware C++ Text class library to help bridging text encoding to and from the platform API?](../36d4c8ae/chime.md)”

==&gt; Also see ”[Todo: Programming - Consider to design a Text streaming framework based on Iterator adaptors and Universal 32 bit Code Points?](../2cddd345/chime.md)"

==&gt; Also see ”[Todo: Programming - Consider to implement services to pipe text through platform console commands (process stdin ==&gt; stdout) as a C++ open source library?](../e005bb2d/chime.md)"

==&gt; Also see ”[Todo: Programming - Consider mapping of keyboard keys to character code points as a form of Text encoding?](../acee3047/chime.md)"

==&gt; Also see ”[Todo: Programming - Consider C++ strings actually lack both a Code Point View and a Meaning View?](../a43ec238/chime.md)”

==&gt; Also see ”[Todo: Programming - Consider the resemblances between Audio Encoded into bit-streams and Spoken Language encoded into character streams (strings)?](../d5c403a6/chime.md)”

==&gt; Also see ”[Todo: Programming - Consider to design a String "type" that bridges text "meaning" and text encoding?](../0ada7e65/chime.md)”

==&gt; Also see ”[Todo: Programming - Consider to find an enhanced C++ String representation and manipulation with a proper value semantics and view abstraction?](../ba28d3a5/chime.md)”

==&gt; Also see ”[Todo: Programming - Consider to implement Code Point and Encode aware "strings" as a C++ library?](../1c192a58/chime.md)”

==&gt; Also see ”[Todo: Programming - Consider to implement Encoding Aware String types based on C++ Template runtime zero-overhead Metafunctionality?](../3c9f09f2/chime.md)”

==&gt; Also see ”[Todo: programming - Consider a printf-design using C++ template "magic" to create lazy-fixed-size range-tree and fully parallelised string-from-variable generators?](../26902720/chime.md)”

==&gt; Also see ”[Todo: Programming - Consider to write a C++ Standard Proposal for String character-set-and-encode aware semantics?](../8e9a0a6c/chime.md)"

1) Consider to study how MacOS tree command piped to text file results in a file that can’t handle Swedish characters?

==&gt; Consider using tree command to file on the ”Tonsillerna Archive” with Swedish file names?

> Kjell-Olovs-MacBook-Air:Tonsillerna Archive kjell-olov$ pwd  
> /Users/kjell-olov/BitTorrent Sync/Sync/Tonsillerna_DropBox_Copy/Tonsillerna Archive  
> Kjell-Olovs-MacBook-Air:Tonsillerna Archive kjell-olov$ tree -P \*.mp3 &gt; mp3_tree_160807.txt  
> Kjell-Olovs-MacBook-Air:Tonsillerna Archive kjell-olov$

==&gt; Tree command actually seems to fail to generate correct unicode output of unicode encoded file names?

![](<Tree command line fails to output unicode file names.tiff>)

==&gt; So the resulting file does not ”know” it contains UTF-8 characters?

==&gt; Pages seem to fail to correctly understand the content?

![](<Pages fails to understand Unicode text file.tiff>)

2) It seems we may generalize the raw-string problem into what sources of raw string we can identify?

==&gt; Consider C++ standard Console input/output streams?

==&gt; It seems they all share the notion of a ”locale” for text encoding (and formatting)?

==&gt; Consider MacOS console input/output streams?

==&gt; Consider Windows Console input/Output streams?

==&gt; Consider Linux input/output streams?

==&gt; Consider the text in Card Payment System Messaging (i.e., ISO-8583, SPDH HISO and more)?

==&gt; Consider C++ source code file string literals (using the encoding of the file)?

==&gt; Q: Is there a way for C++ compilers to compile-time determine the encoding of the source file (and thus the content of a string literal)?

…

==&gt; Consider the strings passed to the platform API?

==&gt; Consider strings passed to windows API functions (char\* = UTF-8 or wchar_t\* = UTF-16)?

==&gt; Consider strings passed to Linux API?

==&gt; Consider strings passed to MacOS API?

...

…

Consider to delve into more issues with failing to understand what encoding and character set ”raw” strings is using?

...

{% endraw %}
