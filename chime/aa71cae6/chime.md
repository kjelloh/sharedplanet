# Todo: Programming in Scratch - Consider to document how to install and run the stand-alone Scratch server locally (and use for slide animation)?

```#aa71cae6``` *As of 2017-08-01 23:49*

[mail plain/text](mail.txt)

{% raw %}
Consider ot would be a good idea to document how to install and run a Scratch server locally to animate HTML slides?

==&gt; Also see “Todo: Programming Slides - Consider if we can animate HTML slides using the Scratch Language?”

...

1) The Scratch stand-alone server seems to live here (<https://github.com/LLK/scratch-www>)?

> Kjell-Olovs-MacBook-Pro:~ kjell-olovhogdahl$ cd Documents/  
> Kjell-Olovs-MacBook-Pro:Documents kjell-olovhogdahl$ cd GitHub/  
> Kjell-Olovs-MacBook-Pro:GitHub kjell-olovhogdahl$ **git clone** <https://github.com/LLK/scratch-www.git> --recursive  
> Cloning into '**scratch-www**'...  
> remote: Counting objects: 12894, done.  
> remote: Compressing objects: 100% (7/7), done.  
> remote: Total 12894 (delta 1), reused 3 (delta 0), pack-reused 12887  
> Receiving objects: 100% (12894/12894), 209.42 MiB | 1.59 MiB/s, done.  
> Resolving deltas: 100% (8234/8234), done.  
> Kjell-Olovs-MacBook-Pro:GitHub kjell-olovhogdahl$ pwd  
> /Users/kjell-olovhogdahl/Documents/GitHub  
> Kjell-Olovs-MacBook-Pro:GitHub kjell-olovhogdahl$ cd scratch-www/  
> Kjell-Olovs-MacBook-Pro:scratch-www kjell-olovhogdahl$ pwd  
> **/Users/kjell-olovhogdahl/Documents/GitHub/scratch-www**  
> Kjell-Olovs-MacBook-Pro:scratch-www kjell-olovhogdahl$

2) Consider to document installation of npm?

> Kjell-Olovs-MacBook-Pro:~ kjell-olovhogdahl$ **brew install npm**  
> Updating Homebrew...  
> ==&gt; **Auto-updated Homebrew!**  
> Updated 1 tap (homebrew/core).  
> ==&gt; **New Formulae**  
> apng2gif  
> ==&gt; **Updated Formulae**  
> allure folly lean-cli qemu  
> angular-cli fontforge libcds rakudo-star  
> ansifilter fonttools libgit2-glib re2  
> apktool forego libpng redis@3.2  
> arx-libertatis fs-uae logstalgia rlvm  
> ascii gedit mal4s rtags  
> awslogs geoserver mediaconch saltstack  
> basex getdns micro sbcl  
> bash-snippets **glew ****✔** msitools skinny  
> blastem gnuplot nzbget supertux  
> coffeescript goad openal-soft swiftformat  
> collector-sidecar gofabric8 openclonk tomcat  
> cppcheck gource opencsg translate-toolkit  
> dcm2niix grafana openmsx vim  
> emscripten gsoap paket watson  
> etsh idris passenger widelands  
> ffmpeg imagemagick ponyc wimlib  
> fibjs imagemagick@6 ppsspp yle-dl  
> flawfinder jenkins pwntools youtube-dl

> ==&gt; **Installing dependencies for node: ****icu4c**  
> ==&gt; **Installing node dependency: ****icu4c**  
> ==&gt; **Downloading <https://homebrew.bintray.com/bottles/icu4c-58.2.el_capitan.bottl>**  
> ==&gt; **Downloading from <https://akamai.bintray.com/f8/f8267df67e76db7412baf967dd9ef>**  
> ######################################################################## 100.0%  
> ==&gt; **Pouring icu4c-58.2.el_capitan.bottle.tar.gz**  
> ==&gt; **Using the sandbox**  
> ==&gt; **Caveats**  
> This formula is keg-only, which means it was not symlinked into /usr/local,  
> because macOS provides libicucore.dylib (but nothing else).

> If you need to have this software first in your PATH run:  
> echo 'export PATH="/usr/local/opt/icu4c/bin:$PATH"' &gt;&gt; ~/.bash_profile  
> echo 'export PATH="/usr/local/opt/icu4c/sbin:$PATH"' &gt;&gt; ~/.bash_profile

> For compilers to find this software you may need to set:  
> LDFLAGS: -L/usr/local/opt/icu4c/lib  
> CPPFLAGS: -I/usr/local/opt/icu4c/include  
> For pkg-config to find this software you may need to set:  
> PKG_CONFIG_PATH: /usr/local/opt/icu4c/lib/pkgconfig

> ==&gt; **Summary**  
> 🍺 /usr/local/Cellar/icu4c/58.2: 242 files, 65MB  
> ==&gt; **Installing ****node**  
> ==&gt; **Downloading <https://homebrew.bintray.com/bottles/node-8.2.1.el_capitan.bottl>**  
> ==&gt; **Downloading from <https://akamai.bintray.com/ab/ab78a487ceeaa1c335ded6dfe094d>**  
> ######################################################################## 100.0%  
> ==&gt; **Pouring node-8.2.1.el_capitan.bottle.tar.gz**  
> ==&gt; **Caveats**  
> Bash completion has been installed to:  
> /usr/local/etc/bash_completion.d  
> ==&gt; **Summary**  
> 🍺 /usr/local/Cellar/node/8.2.1: 4,151 files, 46MB  
> Kjell-Olovs-MacBook-Pro:~ kjell-olovhogdahl$

3) It seems I need to struggle a bit to get it to install, build and run on my MAC OS?

==&gt; The install seems to run ok (See attached console output file)?

## Attachments

- [Scratch-www MAC OS npm install example.rtf](<Scratch-www MAC OS npm install example.rtf>)
- [Scratch-www npm run build MAC OS failed - try 1.rtf](<Scratch-www npm run build MAC OS failed - try 1.rtf>)
- [Scratch-www npm run build MAC OS failed - try 2.rtf](<Scratch-www npm run build MAC OS failed - try 2.rtf>)

{% endraw %}
