# Todo: Programming - Consider to understand the Linux File modes and how to set them appropriately using the chmod command?

```#261aa90d``` *As of 2016-08-02 17:42*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to understand the Linux file modes and how to set them for required file behaviour using the chmod command?

1) This seem like a good page for leads on the file modes of Linux (<https://www.linux.com/learn/understanding-linux-file-permissions>)?

==&gt; Each file has Permission settings for Read (r), Write (w) and Execute (x) (If ON Shown as rwx)

==&gt; An unset option is shown as underscore ‘_’ (e.g., r__ means read but not write or execute permission)

==&gt; Each setting may be applied to group Owner, Group and All (Permissions for these are shown in order as rwxrwxrwx)

==&gt; Permissions are set with chmod command using hexadecimal representation of one digit for each group (e.g. chmod 111 ==&gt; __x__x__x)

chmod 111 ==&gt; __x__x__x

chmod 222 ==&gt; _w__w__w_

chmod 444 ==&gt; r__r__r__

chmod 765 ==&gt; rwx_rw_r_x (Owner may Read, Write and Execute, Group may read and Write and Anyone (ALL) may Read and Write)

==&gt; It seems we may view the file mode of files using the **ls -l** command?

> kjell-olovhogdahl@ubuntu:~/Documents/GitHub/cratchit/source$ **ls -l**  
> **-rw-rw-r--** 1 kjell-olovhogdahl kjell-olovhogdahl 218 Aug 2 16:22 linux_me.sh  
> kjell-olovhogdahl@ubuntu:~/Documents/GitHub/cratchit/source$ **chmod 765 linux_me.sh**  
> kjell-olovhogdahl@ubuntu:~/Documents/GitHub/cratchit/source$ **ls -l**  
> **-rwxrw-r-x** 1 kjell-olovhogdahl kjell-olovhogdahl 218 Aug 2 16:22 linux_me.sh  
> kjell-olovhogdahl@ubuntu:~/Documents/GitHub/cratchit/source$

…

2) Consider to understand the options of the chmod command?

==&gt; This seem to be what chmod —help produces?

> kjell-olovhogdahl@ubuntu:~/Documents/GitHub/cratchit/source$ chmod --help  
> Usage: chmod &#91;OPTION&#93;... MODE&#91;,MODE&#93;... FILE...  
> or: chmod &#91;OPTION&#93;... OCTAL-MODE FILE...  
> or: chmod &#91;OPTION&#93;... --reference=RFILE FILE...  
> Change the mode of each FILE to MODE.  
> With --reference, change the mode of each FILE to that of RFILE.

> -c, --changes like verbose but report only when a change is made  
> -f, --silent, --quiet suppress most error messages  
> -v, --verbose output a diagnostic for every file processed  
> --no-preserve-root do not treat '/' specially (the default)  
> --preserve-root fail to operate recursively on '/'  
> --reference=RFILE use RFILE's mode instead of MODE values  
> -R, --recursive change files and directories recursively  
> --help display this help and exit  
> --version output version information and exit

3) Consider to make a simple command line tool to change File Modes using some easier user interface?

==&gt; Consider a command that accepts setting on the form “rwxrwxrwx”?

&gt;x_chmod rwx_rw_r_x

…

Consider to delve into the realms of the file mode and chmod command mysteries for practical application?

...

{% endraw %}
