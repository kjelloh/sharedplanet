# Todo: Consider it seems Apple Time Machine can be configured to backup also external drives (although by default it lists them in the exclude-list)?

```#92293ef5``` *As of 2019-04-10 13:27*

[mail plain/text](mail.txt)

{% raw %}
I think I am now ready to start buying external drive(s) ensured that I can have them backed up with Apple Time Machine?

==&gt; Also see “[Todo: Consider an external PCIe enclosure over Thunderbolt 3 to create an external M.2 NVMe SSD storage?](../d695139e/chime.md)”

==&gt; Also see “[Todo: Consider to document and understand the technical specs of my Macbook Pro mid 2014 lap-top (e.g., what ports it has and how to interface external devices through these ports)?](../0bf142e5/chime.md)”

==&gt; Also see “[Todo: Consider a motorised external storage cabinet for portable drives that circulates a master and one or more backups in a mechanical round-robin configuration?](../eb39d80c/chime.md)”

==&gt; Also see “[Todo: External Drive Backup - Consider to use rsync on OS X to keep a backup of my Youtube video materials?](../6868462b/chime.md)"

1) Consider this article “How to make sure Time Machine backs up external drives” (<https://www.macworld.com/article/3153995/how-to-make-sure-time-machine-backs-up-external-drives.html> )?

2) Consider I seem to have confirmed that once an external drive has been identified by OS X and then removed from the “excluded items list” it remains part of Time Machine Backup?

==&gt; I added a “new” (not added before) external drive (my LaCie 2TB drive) and OS X Time Machine added it to the “exclude Items” list

![](<Screenshot 2019-04-10 at 13.01.26.png>)

*Time Machine backup size 145 GB with external drive excluded*

==&gt; I removed the external drive from the list “Exclude these items from backups”

![](<Screenshot 2019-04-10 at 13.02.33.png>)

*Time Machine backup size 1.7 TB with external drive NOT excluded (i.e., included)*

==&gt; It seems Apple claims Time Machine can back from any but only to NON APFS drives (<https://support.apple.com/en-gb/guide/mac-help/mh15139/mac> )?

> “Important: You can back up from an HFS+ or APFS-formatted disk to an HFS+ disk; however, Time Machine can’t back up to an APFS-formatted disk."

3) Consider to investigate what may happen with Time Machine Backups if they are taken while an external drive is disconnected?

==&gt; Consider Time Machine has a “Restore To” option which we may potentially use to manually find and get back an external drive backup?

> *Here we speculate that if a backup is created while the external drive was unconnected it will not be part of that backup. Thus, we can’t restore an external drive from that backup. But we should be able to go back to an older backup where the external drive was connected and thus backed up? So then, should we need to we can always restore from some of the older backups that has actually backed up also the external drive?*

==&gt; Consider that if we restore the whole computer from a backup, it will leave any connected external drive that is NOT in the backup untouched?

> *Here we speculate that if an external drive is not present in a backup but connected to the system at the tome of the restore operation, then if will NOT do anything with the external drive. At the very least we should hope that it does not do something crazy with the external drive based on it NOT being part of the back up? Lets hope that it does not delete its contents, disconnects it NOR formats it?*

4) Consider to aim for a system with a fixed set of always connected external drives and then the Time MAChine Backup once set up will work just fine?

==&gt; Consider to go for a always-connected say either a single 512 GB SSD or two 256 GB SSD in RAID 0?

...

...

{% endraw %}
