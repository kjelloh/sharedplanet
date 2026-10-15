# Todo: External Drive Clone - Consider to use rsync on OS X to transfer a whole drive to another one

```#56c12c4b``` *As of 2022-09-07 21:39*

[mail plain/text](mail.txt)

{% raw %}
I bought a 4TB drive and needs to "clone" my previous (to small) 2 TB drive to it.

==&gt; Also see "Todo: External Drive Backup - Consider to use rsync on OS X to keep a backup of my Youtube video materials?"

1) It seems the rsync command does the job (and enables me to pick up where I left off should the copy be disrupted)?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro /Volumes % sudo rsync -vaE --delete --progress /Volumes/LaCie/ "/Volumes/LaCie 4TB"  
> building file list ...  
> ...

NOTE: The '/' at the end of the source path "/Volumes/LaCie/" means the content of the drive is copied (as opposed to leaving the '/' out and having a folder "LaCe" created at the target)

...

{% endraw %}
