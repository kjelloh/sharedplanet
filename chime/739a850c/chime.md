# Todo: Consider to document installation and usage of the Ninja build system using Brew on my Macbook Pro 17"?

```#739a850c``` *As of 2017-06-27 10:47*

[mail plain/text](mail.txt)

{% raw %}
1) This seems to be the result of installing Ninja on my Macbook Pro 17”?

> kjell-olov-hogdahls-macbook-pro:immutable-cpp kjell-olovhogdahl$ **brew** install ninja  
> Updating Homebrew...  
> ==&gt; **Auto-updated Homebrew!**  
> ...  
> ==&gt; **Downloading <https://homebrew.bintray.com/bottles/ninja-1.7.2.el_capitan.bott>**  
> ######################################################################## 100,0%  
> ==&gt; **Pouring ninja-1.7.2.el_capitan.bottle.tar.gz**  
> ==&gt; **Using the sandbox**  
> ==&gt; **Caveats**  
> Bash completion has been installed to:  
> /usr/local/etc/bash_completion.d

> zsh completions have been installed to:  
> /usr/local/share/zsh/site-functions  
> ==&gt; **Summary**  
> 🍺 /usr/local/Cellar/ninja/1.7.2: 7 files, 269KB  
> kjell-olov-hogdahls-macbook-pro:immutable-cpp kjell-olovhogdahl$

2) This seems to be the home of the Ninja build system (<https://ninja-build.org>)?

> ”*Where other build systems are high-level languages Ninja aims to be an assembler.*"

3) The immutable-cpp project seems to use the Ninja build system (<https://github.com/rsms/immutable-cpp>)?

> Configure:

  
> ```
> ./configure.py --debug
> ```

  
> To build and run tests:

  
> ```
> ninja && build/debug/bin/test
> ```

  
> To build and debug:

  
> ```
> ninja && lldb -bo r build/debug/bin/test
> ```



…

...

Consider to update this Todo regarding installation and using of the Ninja build system?

{% endraw %}
