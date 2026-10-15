# Todo: Sisyphus - Consider to add a zip-iterator that arranges members that matches in the provided "zipped" ranges (to generate tables of overlapping sets)?

```#f09cb8e6``` *As of 2016-08-10 15:07*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to have C++ iterator library Sisyphus provide a zip-iterator service that may be used to iterate of sets sorted in degree of matches?

1) Consider to use this zip-iterator to generate tables of matching compiler pre-defined macros gcc, clang and msvc on different platforms?

==&gt; For listings see “Todo: programming - Consider to implement a C++ open source library to compile-time identify the build tool chain and target platform?”  
…

2) Consider the zip-iterator to sort the output from full-match (nodes present in all ranges) down to nodes with no matches between sets?

…

3) Consider the zip-iterator to accept some key-picker to enable turning set entries into the key used for matching (i.e., the macro name in “#define __GNUC__ 4”)?

...

4) Consider the zip-iterator be auto-generate empty (null) entries if provided sets (ranges) are of different lengths?

…

…

Consider to delve into this idea of having the Sisyphus C++ iterator (generator) range library provide a service to “zip” two or more sets into one sorted in shared member presence order?  
...

{% endraw %}
