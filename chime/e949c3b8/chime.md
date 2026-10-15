# Todo: Consider to document what I did in relation to re-installing llvm@17 with brew?

```#e949c3b8``` *As of 2024-06-15 16:22*

[mail plain/text](mail.txt)

{% raw %}
I had a bad experience with upgrading to llvm 18 so I re-installed llvm 17 with brew to compare.

1) It seems brew install llvm 17 worked fine?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % brew install llvm@17  
> ==&gt; **Auto-updating Homebrew...**  
> Adjust how often this is run with HOMEBREW_AUTO_UPDATE_SECS or disable with  
> HOMEBREW_NO_AUTO_UPDATE. Hide these hints with HOMEBREW_NO_ENV_HINTS (see \`man brew\`).  
> ==&gt; **Auto-updated Homebrew!**  
> Updated 3 taps (freecad/freecad, homebrew/core and homebrew/cask).  
> ==&gt; **New Formulae**  
> batt codecov-cli dep-tree geni kubelogin poutine typstyle  
> chsrc cyctl freecad/freecad/freecad@0.21.2_py310 gensio libpeas@1 toipe zfind  
> ==&gt; **New Casks**  
> clion@eap font-edu-au-vic-wa-nt-hand font-playwrite-ar font-playwrite-be-wal font-playwrite-cz font-playwrite-hr font-playwrite-pe get-api material-maker xnapper  
> elgato-capture-device-utility font-fustat font-playwrite-at font-playwrite-cl font-playwrite-dk-loopet font-playwrite-hr-lijeva font-wittgenstein itermai proton-pass  
> emclient@beta font-ga-maamli font-playwrite-be-vlg font-playwrite-cu font-playwrite-dk-uloopet font-playwrite-hu font-zain macsymbolicator vcam

> You have **87** outdated formulae and **1** outdated cask installed.

> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/llvm/17/manifests/17.0.6>**  
> ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****llvm@17**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/llvm/17/blobs/sha256:77fa86ddbbdaa8abd9afa9e3e1b3471ebf3817ce6a8f018901d5d2889a2d8e0d>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Pouring llvm@17--17.0.6.monterey.bottle.tar.gz**  
> ==&gt; **Caveats**  
> To use the bundled libc++ please add the following LDFLAGS:  
> LDFLAGS="-L/usr/local/opt/llvm@17/lib/c++ -Wl,-rpath,/usr/local/opt/llvm@17/lib/c++"

> llvm@17 is keg-only, which means it was not symlinked into /usr/local,  
> because this is an alternate version of another formula.

> If you need to have llvm@17 first in your PATH, run:  
> echo 'export PATH="/usr/local/opt/llvm@17/bin:$PATH"' &gt;&gt; ~/.zshrc

> For compilers to find llvm@17 you may need to set:  
> export LDFLAGS="-L/usr/local/opt/llvm@17/lib"  
> export CPPFLAGS="-I/usr/local/opt/llvm@17/include"  
> ==&gt; **Summary**  
> 🍺 /usr/local/Cellar/llvm@17/17.0.6: 6,642 files, 1.5GB  
> ==&gt; **Running \`brew cleanup llvm@17\`...**  
> Disable this behaviour by setting HOMEBREW_NO_INSTALL_CLEANUP.  
> Hide these hints with HOMEBREW_NO_ENV_HINTS (see \`man brew\`).  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ %

2) Consider to try and use clang++ tool chain using environment variables as recommended to see if my issues goes away?

==&gt; LDFLAGS="-L/usr/local/opt/llvm@17/lib/c++ -Wl,-rpath,/usr/local/opt/llvm@17/lib/c++"

==&gt; CPPFLAGS="-I/usr/local/opt/llvm@17/include"

...

{% endraw %}
