# Todo: Cinsider to document install of Brew package manager on Macbook Pro 17" 2009?

```#f3827d3f``` *As of 2016-10-20 12:31*

[mail plain/text](mail.txt)

{% raw %}
This seem to be a log of a succesfull install of the Brew package manager on my old Macbook Pro 17" 2009?

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
