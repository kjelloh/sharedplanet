# Todo: Consider to document install of Brew package manager on Macbook Pro 17" 2009?

```#7191fa4b``` *As of 2020-08-26 11:15*

[mail plain/text](mail.txt)

{% raw %}
I think it is a good thing to document how I install things on my computers

==&gt; Also see "[Todo: Cinsider to document install of Brew package manager on Macbook Pro 17" 2009?](../f3827d3f/chime.md)" (older wrong spelling "Cinsider")

1) This seems to be a log (Aug 2020) of a successful install off the Brew package manager on my Mac Pro 2013?

==&gt; Also see [https://brew.sh](https://brew.sh/)

==&gt; Also see <https://www.howtogeek.com/211541/homebrew-for-os-x-easily-installs-desktop-apps-and-terminal-utilities/>

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ % /bin/bash -c "$(**curl -fsSL <https://raw.githubusercontent.com/Homebrew/install/master/install.sh>**)"  
> Password:  
> **==&gt;** **This script will install:**  
> **/usr/local/bin**/brew  
> **/usr/local/share/doc**/homebrew  
> **/usr/local/share/man**/man1/brew.1  
> **/usr/local/share/zsh**/site-functions/_brew  
> **/usr/local/etc**/bash_completion.d/brew  
> **/usr/local**/Homebrew  
> **==&gt;** **The following existing directories will be made group writable:**  
> /usr/local/bin  
> /usr/local/include  
> /usr/local/lib  
> /usr/local/share  
> /usr/local/share/doc  
> /usr/local/share/man  
> /usr/local/share/man/man1  
> /usr/local/share/man/man8  
> **==&gt;** **The following existing directories will have their owner set to ****kjell-olovhogdal**:  
> /usr/local/bin  
> /usr/local/include  
> /usr/local/lib  
> /usr/local/share  
> /usr/local/share/doc  
> /usr/local/share/man  
> /usr/local/share/man/man1  
> /usr/local/share/man/man8  
> **==&gt;** **The following existing directories will have their group set to ****admin**:  
> /usr/local/bin  
> /usr/local/include  
> /usr/local/lib  
> /usr/local/share  
> /usr/local/share/doc  
> /usr/local/share/man  
> /usr/local/share/man/man1  
> /usr/local/share/man/man8  
> **==&gt;** **The following new directories will be created:**  
> **/usr/local/etc**  
> **/usr/local/sbin**  
> **/usr/local/var**  
> **/usr/local/opt**  
> **/usr/local/share/zsh**  
> **/usr/local/share/zsh/site-functions**  
> **/usr/local/var/homebrew**  
> **/usr/local/var/homebrew/linked**  
> **/usr/local/Cellar**  
> **/usr/local/Caskroom**  
> **/usr/local/Homebrew**  
> **/usr/local/Frameworks**  
> **==&gt;** **The Xcode Command Line Tools will be installed.**

> Press RETURN to continue or any other key to abort  
> **==&gt;** **/usr/bin/sudo /bin/chmod u+rwx /usr/local/bin /usr/local/include /usr/local/lib /usr/local/share /usr/local/share/doc /usr/local/share/man /usr/local/share/man/man1 /usr/local/share/man/man8**  
> **==&gt;** **/usr/bin/sudo /bin/chmod g+rwx /usr/local/bin /usr/local/include /usr/local/lib /usr/local/share /usr/local/share/doc /usr/local/share/man /usr/local/share/man/man1 /usr/local/share/man/man8**  
> **==&gt;** **/usr/bin/sudo /usr/sbin/chown kjell-olovhogdal /usr/local/bin /usr/local/include /usr/local/lib /usr/local/share /usr/local/share/doc /usr/local/share/man /usr/local/share/man/man1 /usr/local/share/man/man8**  
> **==&gt;** **/usr/bin/sudo /usr/bin/chgrp admin /usr/local/bin /usr/local/include /usr/local/lib /usr/local/share /usr/local/share/doc /usr/local/share/man /usr/local/share/man/man1 /usr/local/share/man/man8**  
> **==&gt;** **/usr/bin/sudo /bin/mkdir -p /usr/local/etc /usr/local/sbin /usr/local/var /usr/local/opt /usr/local/share/zsh /usr/local/share/zsh/site-functions /usr/local/var/homebrew /usr/local/var/homebrew/linked /usr/local/Cellar /usr/local/Caskroom /usr/local/Homebrew /usr/local/Frameworks**  
> **==&gt;** **/usr/bin/sudo /bin/chmod g+rwx /usr/local/etc /usr/local/sbin /usr/local/var /usr/local/opt /usr/local/share/zsh /usr/local/share/zsh/site-functions /usr/local/var/homebrew /usr/local/var/homebrew/linked /usr/local/Cellar /usr/local/Caskroom /usr/local/Homebrew /usr/local/Frameworks**  
> **==&gt;** **/usr/bin/sudo /usr/sbin/chown kjell-olovhogdal /usr/local/etc /usr/local/sbin /usr/local/var /usr/local/opt /usr/local/share/zsh /usr/local/share/zsh/site-functions /usr/local/var/homebrew /usr/local/var/homebrew/linked /usr/local/Cellar /usr/local/Caskroom /usr/local/Homebrew /usr/local/Frameworks**  
> **==&gt;** **/usr/bin/sudo /usr/bin/chgrp admin /usr/local/etc /usr/local/sbin /usr/local/var /usr/local/opt /usr/local/share/zsh /usr/local/share/zsh/site-functions /usr/local/var/homebrew /usr/local/var/homebrew/linked /usr/local/Cellar /usr/local/Caskroom /usr/local/Homebrew /usr/local/Frameworks**  
> **==&gt;** **/usr/bin/sudo /bin/mkdir -p /Users/kjell-olovhogdal/Library/Caches/Homebrew**  
> **==&gt;** **/usr/bin/sudo /bin/chmod g+rwx /Users/kjell-olovhogdal/Library/Caches/Homebrew**  
> **==&gt;** **/usr/bin/sudo /usr/sbin/chown kjell-olovhogdal /Users/kjell-olovhogdal/Library/Caches/Homebrew**  
> **==&gt;** **Searching online for the Command Line Tools**  
> **==&gt;** **/usr/bin/sudo /usr/bin/touch /tmp/.com.apple.dt.CommandLineTools.installondemand.in-progress**  
> **==&gt;** **Installing Command Line Tools for Xcode-11.5**  
> **==&gt;** **/usr/bin/sudo /usr/sbin/softwareupdate -i Command\\ Line\\ Tools\\ for\\ Xcode-11.5**  
> Software Update Tool

> Downloading Command Line Tools for Xcode  
> Downloaded Command Line Tools for Xcode  
> **Installing Command Line Tools for Xcode**  
> Done with Command Line Tools for Xcode  
> Done.  
> **==&gt;** **/usr/bin/sudo /bin/rm -f /tmp/.com.apple.dt.CommandLineTools.installondemand.in-progress**  
> **==&gt;** **/usr/bin/sudo /usr/bin/xcode-select --switch /Library/Developer/CommandLineTools**  
> **==&gt;** **Downloading and installing Homebrew...**  
> remote: Enumerating objects: 109, done.  
> remote: Counting objects: 100% (109/109), done.  
> remote: Compressing objects: 100% (96/96), done.  
> remote: Total 150794 (delta 46), reused 60 (delta 13), pack-reused 150685  
> Receiving objects: 100% (150794/150794), 37.48 MiB | 3.08 MiB/s, done.  
> Resolving deltas: 100% (111380/111380), done.  
> **From <https://github.com/Homebrew/brew>**  
> \* &#91;new branch&#93; dependabot/bundler/Library/Homebrew/elftools-1.1.3 -&gt; origin/dependabot/bundler/Library/Homebrew/elftools-1.1.3  
> \* &#91;new branch&#93; dependabot/bundler/Library/Homebrew/sorbet-0.5.5879 -&gt; origin/dependabot/bundler/Library/Homebrew/sorbet-0.5.5879  
> \* &#91;new branch&#93; dependabot/bundler/Library/Homebrew/sorbet-runtime-0.5.5878 -&gt; origin/dependabot/bundler/Library/Homebrew/sorbet-runtime-0.5.5878  
> \* &#91;new branch&#93; master -&gt; origin/master  
> \* &#91;new branch&#93; tapioca-update -&gt; origin/tapioca-update  
> \* &#91;new branch&#93; workflows-not-master -&gt; origin/workflows-not-master  
> \* &#91;new tag&#93; 0.1 -&gt; 0.1  
> \* &#91;new tag&#93; 0.2 -&gt; 0.2  
> \* &#91;new tag&#93; 0.3 -&gt; 0.3  
> \* &#91;new tag&#93; 0.4 -&gt; 0.4  
> \* &#91;new tag&#93; 0.5 -&gt; 0.5  
> \* &#91;new tag&#93; 0.6 -&gt; 0.6  
> \* &#91;new tag&#93; 0.7 -&gt; 0.7  
> \* &#91;new tag&#93; 0.7.1 -&gt; 0.7.1  
> \* &#91;new tag&#93; 0.8 -&gt; 0.8  
> \* &#91;new tag&#93; 0.8.1 -&gt; 0.8.1  
> \* &#91;new tag&#93; 0.9 -&gt; 0.9  
> \* &#91;new tag&#93; 0.9.1 -&gt; 0.9.1  
> \* &#91;new tag&#93; 0.9.2 -&gt; 0.9.2  
> \* &#91;new tag&#93; 0.9.3 -&gt; 0.9.3  
> \* &#91;new tag&#93; 0.9.4 -&gt; 0.9.4  
> \* &#91;new tag&#93; 0.9.5 -&gt; 0.9.5  
> \* &#91;new tag&#93; 0.9.8 -&gt; 0.9.8  
> \* &#91;new tag&#93; 0.9.9 -&gt; 0.9.9  
> \* &#91;new tag&#93; 1.0.0 -&gt; 1.0.0  
> \* &#91;new tag&#93; 1.0.1 -&gt; 1.0.1  
> \* &#91;new tag&#93; 1.0.2 -&gt; 1.0.2  
> \* &#91;new tag&#93; 1.0.3 -&gt; 1.0.3  
> \* &#91;new tag&#93; 1.0.4 -&gt; 1.0.4  
> \* &#91;new tag&#93; 1.0.5 -&gt; 1.0.5  
> \* &#91;new tag&#93; 1.0.6 -&gt; 1.0.6  
> \* &#91;new tag&#93; 1.0.7 -&gt; 1.0.7  
> \* &#91;new tag&#93; 1.0.8 -&gt; 1.0.8  
> \* &#91;new tag&#93; 1.0.9 -&gt; 1.0.9  
> \* &#91;new tag&#93; 1.1.0 -&gt; 1.1.0  
> \* &#91;new tag&#93; 1.1.1 -&gt; 1.1.1  
> \* &#91;new tag&#93; 1.1.10 -&gt; 1.1.10  
> \* &#91;new tag&#93; 1.1.11 -&gt; 1.1.11  
> \* &#91;new tag&#93; 1.1.12 -&gt; 1.1.12  
> \* &#91;new tag&#93; 1.1.13 -&gt; 1.1.13  
> \* &#91;new tag&#93; 1.1.2 -&gt; 1.1.2  
> \* &#91;new tag&#93; 1.1.3 -&gt; 1.1.3  
> \* &#91;new tag&#93; 1.1.4 -&gt; 1.1.4  
> \* &#91;new tag&#93; 1.1.5 -&gt; 1.1.5  
> \* &#91;new tag&#93; 1.1.6 -&gt; 1.1.6  
> \* &#91;new tag&#93; 1.1.7 -&gt; 1.1.7  
> \* &#91;new tag&#93; 1.1.8 -&gt; 1.1.8  
> \* &#91;new tag&#93; 1.1.9 -&gt; 1.1.9  
> \* &#91;new tag&#93; 1.2.0 -&gt; 1.2.0  
> \* &#91;new tag&#93; 1.2.1 -&gt; 1.2.1  
> \* &#91;new tag&#93; 1.2.2 -&gt; 1.2.2  
> \* &#91;new tag&#93; 1.2.3 -&gt; 1.2.3  
> \* &#91;new tag&#93; 1.2.4 -&gt; 1.2.4  
> \* &#91;new tag&#93; 1.2.5 -&gt; 1.2.5  
> \* &#91;new tag&#93; 1.2.6 -&gt; 1.2.6  
> \* &#91;new tag&#93; 1.3.0 -&gt; 1.3.0  
> \* &#91;new tag&#93; 1.3.1 -&gt; 1.3.1  
> \* &#91;new tag&#93; 1.3.2 -&gt; 1.3.2  
> \* &#91;new tag&#93; 1.3.3 -&gt; 1.3.3  
> \* &#91;new tag&#93; 1.3.4 -&gt; 1.3.4  
> \* &#91;new tag&#93; 1.3.5 -&gt; 1.3.5  
> \* &#91;new tag&#93; 1.3.6 -&gt; 1.3.6  
> \* &#91;new tag&#93; 1.3.7 -&gt; 1.3.7  
> \* &#91;new tag&#93; 1.3.8 -&gt; 1.3.8  
> \* &#91;new tag&#93; 1.3.9 -&gt; 1.3.9  
> \* &#91;new tag&#93; 1.4.0 -&gt; 1.4.0  
> \* &#91;new tag&#93; 1.4.1 -&gt; 1.4.1  
> \* &#91;new tag&#93; 1.4.2 -&gt; 1.4.2  
> \* &#91;new tag&#93; 1.4.3 -&gt; 1.4.3  
> \* &#91;new tag&#93; 1.5.0 -&gt; 1.5.0  
> \* &#91;new tag&#93; 1.5.1 -&gt; 1.5.1  
> \* &#91;new tag&#93; 1.5.10 -&gt; 1.5.10  
> \* &#91;new tag&#93; 1.5.11 -&gt; 1.5.11  
> \* &#91;new tag&#93; 1.5.12 -&gt; 1.5.12  
> \* &#91;new tag&#93; 1.5.13 -&gt; 1.5.13  
> \* &#91;new tag&#93; 1.5.14 -&gt; 1.5.14  
> \* &#91;new tag&#93; 1.5.2 -&gt; 1.5.2  
> \* &#91;new tag&#93; 1.5.3 -&gt; 1.5.3  
> \* &#91;new tag&#93; 1.5.4 -&gt; 1.5.4  
> \* &#91;new tag&#93; 1.5.5 -&gt; 1.5.5  
> \* &#91;new tag&#93; 1.5.6 -&gt; 1.5.6  
> \* &#91;new tag&#93; 1.5.7 -&gt; 1.5.7  
> \* &#91;new tag&#93; 1.5.8 -&gt; 1.5.8  
> \* &#91;new tag&#93; 1.5.9 -&gt; 1.5.9  
> \* &#91;new tag&#93; 1.6.0 -&gt; 1.6.0  
> \* &#91;new tag&#93; 1.6.1 -&gt; 1.6.1  
> \* &#91;new tag&#93; 1.6.10 -&gt; 1.6.10  
> \* &#91;new tag&#93; 1.6.11 -&gt; 1.6.11  
> \* &#91;new tag&#93; 1.6.12 -&gt; 1.6.12  
> \* &#91;new tag&#93; 1.6.13 -&gt; 1.6.13  
> \* &#91;new tag&#93; 1.6.14 -&gt; 1.6.14  
> \* &#91;new tag&#93; 1.6.15 -&gt; 1.6.15  
> \* &#91;new tag&#93; 1.6.16 -&gt; 1.6.16  
> \* &#91;new tag&#93; 1.6.17 -&gt; 1.6.17  
> \* &#91;new tag&#93; 1.6.2 -&gt; 1.6.2  
> \* &#91;new tag&#93; 1.6.3 -&gt; 1.6.3  
> \* &#91;new tag&#93; 1.6.4 -&gt; 1.6.4  
> \* &#91;new tag&#93; 1.6.5 -&gt; 1.6.5  
> \* &#91;new tag&#93; 1.6.6 -&gt; 1.6.6  
> \* &#91;new tag&#93; 1.6.7 -&gt; 1.6.7  
> \* &#91;new tag&#93; 1.6.8 -&gt; 1.6.8  
> \* &#91;new tag&#93; 1.6.9 -&gt; 1.6.9  
> \* &#91;new tag&#93; 1.7.0 -&gt; 1.7.0  
> \* &#91;new tag&#93; 1.7.1 -&gt; 1.7.1  
> \* &#91;new tag&#93; 1.7.2 -&gt; 1.7.2  
> \* &#91;new tag&#93; 1.7.3 -&gt; 1.7.3  
> \* &#91;new tag&#93; 1.7.4 -&gt; 1.7.4  
> \* &#91;new tag&#93; 1.7.5 -&gt; 1.7.5  
> \* &#91;new tag&#93; 1.7.6 -&gt; 1.7.6  
> \* &#91;new tag&#93; 1.7.7 -&gt; 1.7.7  
> \* &#91;new tag&#93; 1.8.0 -&gt; 1.8.0  
> \* &#91;new tag&#93; 1.8.1 -&gt; 1.8.1  
> \* &#91;new tag&#93; 1.8.2 -&gt; 1.8.2  
> \* &#91;new tag&#93; 1.8.3 -&gt; 1.8.3  
> \* &#91;new tag&#93; 1.8.4 -&gt; 1.8.4  
> \* &#91;new tag&#93; 1.8.5 -&gt; 1.8.5  
> \* &#91;new tag&#93; 1.8.6 -&gt; 1.8.6  
> \* &#91;new tag&#93; 1.9.0 -&gt; 1.9.0  
> \* &#91;new tag&#93; 1.9.1 -&gt; 1.9.1  
> \* &#91;new tag&#93; 1.9.2 -&gt; 1.9.2  
> \* &#91;new tag&#93; 1.9.3 -&gt; 1.9.3  
> \* &#91;new tag&#93; 2.0.0 -&gt; 2.0.0  
> \* &#91;new tag&#93; 2.0.1 -&gt; 2.0.1  
> \* &#91;new tag&#93; 2.0.2 -&gt; 2.0.2  
> \* &#91;new tag&#93; 2.0.3 -&gt; 2.0.3  
> \* &#91;new tag&#93; 2.0.4 -&gt; 2.0.4  
> \* &#91;new tag&#93; 2.0.5 -&gt; 2.0.5  
> \* &#91;new tag&#93; 2.0.6 -&gt; 2.0.6  
> \* &#91;new tag&#93; 2.1.0 -&gt; 2.1.0  
> \* &#91;new tag&#93; 2.1.1 -&gt; 2.1.1  
> \* &#91;new tag&#93; 2.1.10 -&gt; 2.1.10  
> \* &#91;new tag&#93; 2.1.11 -&gt; 2.1.11  
> \* &#91;new tag&#93; 2.1.12 -&gt; 2.1.12  
> \* &#91;new tag&#93; 2.1.13 -&gt; 2.1.13  
> \* &#91;new tag&#93; 2.1.14 -&gt; 2.1.14  
> \* &#91;new tag&#93; 2.1.15 -&gt; 2.1.15  
> \* &#91;new tag&#93; 2.1.16 -&gt; 2.1.16  
> \* &#91;new tag&#93; 2.1.2 -&gt; 2.1.2  
> \* &#91;new tag&#93; 2.1.3 -&gt; 2.1.3  
> \* &#91;new tag&#93; 2.1.4 -&gt; 2.1.4  
> \* &#91;new tag&#93; 2.1.5 -&gt; 2.1.5  
> \* &#91;new tag&#93; 2.1.6 -&gt; 2.1.6  
> \* &#91;new tag&#93; 2.1.7 -&gt; 2.1.7  
> \* &#91;new tag&#93; 2.1.8 -&gt; 2.1.8  
> \* &#91;new tag&#93; 2.1.9 -&gt; 2.1.9  
> \* &#91;new tag&#93; 2.2.0 -&gt; 2.2.0  
> \* &#91;new tag&#93; 2.2.1 -&gt; 2.2.1  
> \* &#91;new tag&#93; 2.2.10 -&gt; 2.2.10  
> \* &#91;new tag&#93; 2.2.11 -&gt; 2.2.11  
> \* &#91;new tag&#93; 2.2.12 -&gt; 2.2.12  
> \* &#91;new tag&#93; 2.2.13 -&gt; 2.2.13  
> \* &#91;new tag&#93; 2.2.14 -&gt; 2.2.14  
> \* &#91;new tag&#93; 2.2.15 -&gt; 2.2.15  
> \* &#91;new tag&#93; 2.2.16 -&gt; 2.2.16  
> \* &#91;new tag&#93; 2.2.17 -&gt; 2.2.17  
> \* &#91;new tag&#93; 2.2.2 -&gt; 2.2.2  
> \* &#91;new tag&#93; 2.2.3 -&gt; 2.2.3  
> \* &#91;new tag&#93; 2.2.4 -&gt; 2.2.4  
> \* &#91;new tag&#93; 2.2.5 -&gt; 2.2.5  
> \* &#91;new tag&#93; 2.2.6 -&gt; 2.2.6  
> \* &#91;new tag&#93; 2.2.7 -&gt; 2.2.7  
> \* &#91;new tag&#93; 2.2.8 -&gt; 2.2.8  
> \* &#91;new tag&#93; 2.2.9 -&gt; 2.2.9  
> \* &#91;new tag&#93; 2.3.0 -&gt; 2.3.0  
> \* &#91;new tag&#93; 2.4.0 -&gt; 2.4.0  
> \* &#91;new tag&#93; 2.4.1 -&gt; 2.4.1  
> \* &#91;new tag&#93; 2.4.10 -&gt; 2.4.10  
> \* &#91;new tag&#93; 2.4.11 -&gt; 2.4.11  
> \* &#91;new tag&#93; 2.4.12 -&gt; 2.4.12  
> \* &#91;new tag&#93; 2.4.13 -&gt; 2.4.13  
> \* &#91;new tag&#93; 2.4.2 -&gt; 2.4.2  
> \* &#91;new tag&#93; 2.4.3 -&gt; 2.4.3  
> \* &#91;new tag&#93; 2.4.4 -&gt; 2.4.4  
> \* &#91;new tag&#93; 2.4.5 -&gt; 2.4.5  
> \* &#91;new tag&#93; 2.4.6 -&gt; 2.4.6  
> \* &#91;new tag&#93; 2.4.7 -&gt; 2.4.7  
> \* &#91;new tag&#93; 2.4.8 -&gt; 2.4.8  
> \* &#91;new tag&#93; 2.4.9 -&gt; 2.4.9  
> **HEAD is now at 1359f2e32** Merge pull request #8493 from reitermarkus/document-pypi  
> ==&gt; **Homebrew is run entirely by unpaid volunteers. Please consider donating:**  
> <https://github.com/Homebrew/brew#donations>  
> ==&gt; **Tapping homebrew/core**  
> Cloning into '/usr/local/Homebrew/Library/Taps/homebrew/homebrew-core'...  
> remote: Enumerating objects: 108, done.  
> remote: Counting objects: 100% (108/108), done.  
> remote: Compressing objects: 100% (70/70), done.  
> remote: Total 783176 (delta 69), reused 58 (delta 38), pack-reused 783068  
> Receiving objects: 100% (783176/783176), 311.63 MiB | 3.14 MiB/s, done.  
> Resolving deltas: 100% (522538/522538), done.  
> Updating files: 100% (5455/5455), done.  
> Tapped 2 commands and 5200 formulae (5,480 files, 341.9MB).  
> Already up-to-date.  
> **==&gt;** **Installation successful!**

> **==&gt;** **Homebrew has enabled anonymous aggregate formulae and cask analytics.**  
> **Read the analytics documentation (and how to opt-out) here:**  
> [**https://docs.brew.sh/Analytics](https://docs.brew.sh/Analytics)**  
> No analytics data has been sent yet (or will be during this \`install\` run).

> **==&gt;** **Homebrew is run entirely by unpaid volunteers. Please consider donating:**  
> <https://github.com/Homebrew/brew#donations>

> **==&gt;** **Next steps:**  
> - **Run \`brew help\` to get started**  
> - Further documentation:  
> [https://docs.brew.sh](https://docs.brew.sh/)  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro ~ %

2) This seem to be a log (October 2016) of a successful install off the Brew package manager on my old Macbook Pro 17" 2009?

> kjell-olov-hogdahls-macbook-pro:build_xc kjell-olovhogdahl$ **/usr/bin/ruby -e "$(curl -fsSL <https://raw.githubusercontent.com/Homebrew/install/master/install>)"**  
> ==&gt; This script will install:  
> /usr/local/bin/brew  
> /usr/local/share/doc/homebrew  
> /usr/local/share/man/man1/brew.1  
> /usr/local/share/zsh/site-functions/_brew  
> /usr/local/etc/bash_completion.d/brew  
> /usr/local/Homebrew  
> ==&gt; The following existing directories will be made group writable:  
> /usr/local/bin  
> /usr/local/include  
> /usr/local/lib  
> /usr/local/lib/pkgconfig  
> ==&gt; The following existing directories will have their owner set to kjell-olovhogdahl:  
> /usr/local/bin  
> /usr/local/include  
> /usr/local/lib  
> /usr/local/lib/pkgconfig  
> ==&gt; The following existing directories will have their group set to admin:  
> /usr/local/bin  
> /usr/local/include  
> /usr/local/lib  
> /usr/local/lib/pkgconfig  
> ==&gt; The following new directories will be created:  
> /usr/local/Cellar  
> /usr/local/Homebrew  
> /usr/local/Frameworks  
> /usr/local/etc  
> /usr/local/opt  
> /usr/local/sbin  
> /usr/local/share  
> /usr/local/share/zsh  
> /usr/local/share/zsh/site-functions  
> /usr/local/var

> Press RETURN to continue or any other key to abort  
> ==&gt; /usr/bin/sudo /bin/chmod g+rwx /usr/local/bin /usr/local/include /usr/local/lib /usr/local/lib/pkgconfig  
> Password:  
> ==&gt; /usr/bin/sudo /usr/sbin/chown kjell-olovhogdahl /usr/local/bin /usr/local/include /usr/local/lib /usr/local/lib/pkgconfig  
> ==&gt; /usr/bin/sudo /usr/bin/chgrp admin /usr/local/bin /usr/local/include /usr/local/lib /usr/local/lib/pkgconfig  
> ==&gt; /usr/bin/sudo /bin/mkdir -p /usr/local/Cellar /usr/local/Homebrew /usr/local/Frameworks /usr/local/etc /usr/local/opt /usr/local/sbin /usr/local/share /usr/local/share/zsh /usr/local/share/zsh/site-functions /usr/local/var  
> ==&gt; /usr/bin/sudo /bin/chmod g+rwx /usr/local/Cellar /usr/local/Homebrew /usr/local/Frameworks /usr/local/etc /usr/local/opt /usr/local/sbin /usr/local/share /usr/local/share/zsh /usr/local/share/zsh/site-functions /usr/local/var  
> ==&gt; /usr/bin/sudo /bin/chmod u+rwx share/zsh share/zsh/site-functions  
> ==&gt; /usr/bin/sudo /usr/sbin/chown kjell-olovhogdahl /usr/local/Cellar /usr/local/Homebrew /usr/local/Frameworks /usr/local/etc /usr/local/opt /usr/local/sbin /usr/local/share /usr/local/share/zsh /usr/local/share/zsh/site-functions /usr/local/var  
> ==&gt; /usr/bin/sudo /usr/bin/chgrp admin /usr/local/Cellar /usr/local/Homebrew /usr/local/Frameworks /usr/local/etc /usr/local/opt /usr/local/sbin /usr/local/share /usr/local/share/zsh /usr/local/share/zsh/site-functions /usr/local/var  
> ==&gt; /usr/bin/sudo /bin/mkdir -p /Users/kjell-olovhogdahl/Library/Caches/Homebrew  
> ==&gt; /usr/bin/sudo /bin/chmod g+rwx /Users/kjell-olovhogdahl/Library/Caches/Homebrew  
> ==&gt; /usr/bin/sudo /usr/sbin/chown kjell-olovhogdahl /Users/kjell-olovhogdahl/Library/Caches/Homebrew  
> ==&gt; Downloading and installing Homebrew...  
> remote: Counting objects: 3523, done.  
> remote: Compressing objects: 100% (2478/2478), done.  
> remote: Total 3523 (delta 1657), reused 2243 (delta 905), pack-reused 0  
> Receiving objects: 100% (3523/3523), 2.22 MiB | 1.25 MiB/s, done.  
> Resolving deltas: 100% (1657/1657), done.  
> From <https://github.com/Homebrew/brew>  
> \* &#91;new branch&#93; master -&gt; origin/master  
> \* &#91;new tag&#93; 0.1 -&gt; 0.1  
> \* &#91;new tag&#93; 0.2 -&gt; 0.2  
> \* &#91;new tag&#93; 0.3 -&gt; 0.3  
> \* &#91;new tag&#93; 0.4 -&gt; 0.4  
> \* &#91;new tag&#93; 0.5 -&gt; 0.5  
> \* &#91;new tag&#93; 0.6 -&gt; 0.6  
> \* &#91;new tag&#93; 0.7 -&gt; 0.7  
> \* &#91;new tag&#93; 0.7.1 -&gt; 0.7.1  
> \* &#91;new tag&#93; 0.8 -&gt; 0.8  
> \* &#91;new tag&#93; 0.8.1 -&gt; 0.8.1  
> \* &#91;new tag&#93; 0.9 -&gt; 0.9  
> \* &#91;new tag&#93; 0.9.1 -&gt; 0.9.1  
> \* &#91;new tag&#93; 0.9.2 -&gt; 0.9.2  
> \* &#91;new tag&#93; 0.9.3 -&gt; 0.9.3  
> \* &#91;new tag&#93; 0.9.4 -&gt; 0.9.4  
> \* &#91;new tag&#93; 0.9.5 -&gt; 0.9.5  
> \* &#91;new tag&#93; 0.9.8 -&gt; 0.9.8  
> \* &#91;new tag&#93; 0.9.9 -&gt; 0.9.9  
> \* &#91;new tag&#93; 1.0.0 -&gt; 1.0.0  
> \* &#91;new tag&#93; 1.0.1 -&gt; 1.0.1  
> \* &#91;new tag&#93; 1.0.2 -&gt; 1.0.2  
> \* &#91;new tag&#93; 1.0.3 -&gt; 1.0.3  
> \* &#91;new tag&#93; 1.0.4 -&gt; 1.0.4  
> \* &#91;new tag&#93; 1.0.5 -&gt; 1.0.5  
> \* &#91;new tag&#93; 1.0.6 -&gt; 1.0.6  
> \* &#91;new tag&#93; 1.0.7 -&gt; 1.0.7  
> \* &#91;new tag&#93; 1.0.8 -&gt; 1.0.8  
> HEAD is now at 2b04900 Merge pull request #1330 from reitermarkus/spec-helper  
> ==&gt; Homebrew has enabled anonymous aggregate user behaviour analytics  
> Read the analytics documentation (and how to opt-out) here:  
> <https://git.io/brew-analytics>  
> ==&gt; Tapping homebrew/core  
> Cloning into '/usr/local/Homebrew/Library/Taps/homebrew/homebrew-core'...  
> remote: Counting objects: 3740, done.  
> remote: Compressing objects: 100% (3630/3630), done.  
> remote: Total 3740 (delta 12), reused 303 (delta 1), pack-reused 0  
> Receiving objects: 100% (3740/3740), 2.99 MiB | 1.45 MiB/s, done.  
> Resolving deltas: 100% (12/12), done.  
> Checking connectivity... done.  
> Tapped 3619 formulae (3,767 files, 9.3M)  
> Already up-to-date.  
> ==&gt; Installation successful!  
> ==&gt; Next steps  
> Run \`brew help\` to get started  
> Further documentation: <https://git.io/brew-docs>  
> kjell-olov-hogdahls-macbook-pro:build_xc kjell-olovhogdahl$

{% endraw %}
