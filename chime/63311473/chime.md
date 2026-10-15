# Todo: Consider the etags shell command to create a look up text file of C (and C++) program identifiers?

```#63311473``` *As of 2026-02-26 10:32*

[mail plain/text](mail.txt)

{% raw %}
I want a simpler and less bloated C++ development environment

1) Consider youtube video "Insane Shadow Data Technique in C" at around 2:42 (<https://youtu.be/gtk3RZHwJUA?t=162> )?

==&gt; He seems to give the command 'etags stb_ds.h'

2) It seems 'etags' is a GNU envirnment command to create man pages (<https://www.gnu.org/software/emacs/manual/html_node/emacs/Tags-Tables.html> )

> *"To produce a tags table, you run the etags shell command on a document or the source code file. The ‘etags’ program writes the tags to a tags table file, or tags file in short. The conventional name for a tags file is TAGS"*

3) Consider how to get and use the etags command on macOS?

==&gt; It seems etags is installed with EMacs?

> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/cratchit % etags --v  
> etags (GNU Emacs 29.4)  
> Copyright (C) 2024 Free Software Foundation, Inc.  
> This program is distributed under the terms in ETAGS.README  
> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/cratchit %

==&gt; It seems I can use the shell to feed etags with all the source file for my ceratchit C++ application?

> etags $(find src -type f \\( -name "\*.cpp" -o -name "\*.hpp" -o -name "\*.cc" -o -name "\*.hh" -o -name "\*.h" \\))

==&gt; It seems I also have 'ctags' that outputs in another format

> ctags $(find src -type f \\( -name "\*.cpp" -o -name "\*.hpp" -o -name "\*.cc" -o -name "\*.hh" -o -name "\*.h" \\))

4) Consider the VSCode support for ctags extensions?

==&gt; Consider 'ctags-code' (<https://marketplace.visualstudio.com/items?itemName=harikalyan.ctags-code> )?

> ## Features

- Jump to symbol definitions using Ctags
- Fast and scalable tag lookups powered by LevelDB
- Quick symbol search via VSCode's Quick Pick UI
- Supports many programming languages through Ctags
- Lightweight and configurable

...

{% endraw %}
