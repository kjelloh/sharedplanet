# Todo: Consider to use subversion by branching only on each tool change

```#d2b7ddde``` *As of 2015-09-30 16:32*

[mail plain/text](mail.txt)

{% raw %}
Today I branch each time I update the IDE (Embarcadero RAD Studio) and I only work at branches!

1) Consider to instead always work on the main branch.  
2) Each time I do an upgrade on any part of the environment i Branch (e.g. update of IDE, update of InstallShield, remove compliance of source to certain platform)  
3) I then should name each branch with the change made (e.g. “RAD Studio ZE 7”, “InstallShield 2012”, “Windows XP incompatible”)

In this way I may work along the main branch as long as I am at HEAD of things. But if I would need to go back and develop on a pervious branch I will be able to find that spot and do that on the branch. I may then later merge back top the main branch the stuff I need to "live on”?

{% endraw %}
