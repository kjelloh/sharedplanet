# Todo: Zsh Shell on MacOS - Consider to set user proprietary PATH mutations in ~/.zprofile (to ensure location in PATH ) or in ~/.zshenv (if the PATH mutation is agnostic to PATH reordering by path_helper )?

```#6c6b1ab5``` *As of 2022-01-16 20:34*

[mail plain/text](mail.txt)

{% raw %}
1) Consider this github gist "Setting $PATH for zsh on macOS" ()<https://gist.github.com/Linerre/f11ad4a6a934dcf01ee8415c9457e7b2> )?

==&gt; It seems the bottom line is that if we append to PATH in ~/.zprofile it will mutate the PATH variable after the tool path_helper is called?

> *"**Using zsh, on macOS, avoid ~/.zshenv and choose ~/.zshrc or **~/.zprofile****"*

==&gt; The gist seems to propose the following order for how macOS using Zsh mutats the PATH to its final conetnt?

> *"*For [zsh](https://github.com/rbenv/rbenv/wiki/Unix-shell-initialization#zsh), the order is like this:
1. `/etc/zshenv` (no longer exists on macOS by default)
2. `~/.zshenv`
3. login mode:
  1. `/etc/zprofile` (calling `**path_helper**`)
  2. `**~/.zprofile**`

4. interactive: `/etc/zshrc` `~/.zshrc`
5. login mode: `/etc/zlogin` `~/.zlogin`*"*

NOTE: This should mean that if I do NOT care if my added path is reordered by path_helper I can also do the PATH mutation in ~/.zshenv?

2) It seems I can use pwd to append to ~/.zprofile and then edit the file to have the generated path added to PATH using the export statement?

=&gt;= In this example I add my own app "nudge" in a development directory to my Path for daily use :)

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro nudge % pwd &gt;&gt; ~/.zprofile  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro nudge % vi ~/.zprofile  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro nudge % cat ~/.zprofile

> **export PATH=$PATH:/Users/kjell-olovhogdal/Documents/Github/nudge**

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro nudge %

==&gt; IMPORTANT! No space is allowed in the assignment expression for "export"! (

> #The following **does NOT work** (spaces around '=' not allowed for some reason...)  
> #**export PATH = $PATH:**/User/skjell-olovhogdal/Documents/Github/nudge

...

{% endraw %}
