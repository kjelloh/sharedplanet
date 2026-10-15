# Todo: Consider to grep for "-libstdc++" in LLVM clang source files (to see what we can learn about how clang tries to find headers for gcc c++ library)?

```#f7cf08b2``` *As of 2022-11-06 21:52*

[mail plain/text](mail.txt)

{% raw %}
I want to be able to compile C++20 code on macOS with clang but with the option to link with gny libstdc++

1) It seems there are a lot of refernces in the LLVM / clang source files to "libstdc++"?

> grep -rnw ./clang -e 'libstdc++' &gt; libstdc++_refs_in_clang_files.txt

{% endraw %}
