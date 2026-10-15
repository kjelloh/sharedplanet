# Todo: External Drive Backup - Consider to use rsync on OS X to keep a backup of my Youtube video materials?

```#6868462b``` *As of 2022-09-08 21:42*

[mail plain/text](mail.txt)

{% raw %}
-4) Consider the new rsync command to backup from my new 4TB Lacie drive to the 4TB Seagate backup drive?

> **sudo rsync -vaE --delete --progress "/Volumes/LaCie 4TB" /Volumes/Seagate_4TB**

NOTE: For this to work I first renamed the previous "LaCie" folder on the Seagate drive to "LaCie 4TB".

> *Basically, the source path "/Volumes/LaCie 4TB" refers to the drive as-a-folder soo it will be copied to the target "/Volumes/Seagate_4TB/LaCie 4TB. And as the previous drive was named LaCie I had to rename it to the new drive name to have rsync transfer to the correct target (where the previous backups was located).*

-3) Consider to document how to backup to new 4TB Seagate HD?

==&gt; I Used OS X “Disk Utility” to erase the new Seagate 4TB drive (and renamed it to “Seagate_4TB”) setting the file system to MAC OS X Extended (Journaled)

==&gt; Thus the path to the new drive when connected is “/Volumes/Seagate_4TB”

==&gt; I decided to use the previous Backup 2TB disk “LaCie” as my new working drive (I needed the 2TB space)

==&gt; Thus, the rsync command to backup from the LaCie drive to the new should be: /Volumes/Seagate_4TB

> Kjell-Olovs-MacBook-Pro-2014:~ kjell-olovhogdahl$ sudo **rsync** -vaE **--delete** --progress /Volumes/LaCie /Volumes/Seagate_4TB

-2) It seems i need to use rsync with a parameter that ensures the target is a mirror of the source (don’t keep files that are no longer present in the source)?

==&gt; It seems i should use the argument —delete?

> Kjell-Olovs-MacBook-Pro-2014:~ kjell-olovhogdahl$ sudo **rsync** -vaE **--delete** --progress /Volumes/Kjell-Olovs\\ Passport\\ Hard\\ Drive /Volumes/LaCie

==&gt; Consider to save the result of rsync with delete from my external youtube gard drive to an empty LaCie drive?

## Attachments

- [rsync backup using delete argument 180630.rtf.zip](<rsync backup using delete argument 180630.rtf.zip>)
- [rsync with delete argument when there is nothing to do 180701.rtf.zip](<rsync with delete argument when there is nothing to do 180701.rtf.zip>)

{% endraw %}
