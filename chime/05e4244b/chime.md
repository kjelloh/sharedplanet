# Todo: Consider the different OS X Hibernate (Sleep) modes and research how the different modes affects power consumption in, and start-up time from, sleep?

```#05e4244b``` *As of 2019-04-06 19:31*

[mail plain/text](mail.txt)

{% raw %}
When I moved from my MacBook Pro mid 2014 to my Mac Pro late 2013 I suspect my electrical bill has gone up to provide for a more power hungry Mac Pro sleep mode?

1) Consider to use the command line “pmset” command to interrogate and set the sleep mode of my Mac Pro late 2013?

==&gt; Consider this article “Mac Sleep Settings for Performance and Battery Life” that explains the OS X power modes and how to use the pmset command (<https://www.lifewire.com/change-mac-sleep-settings-2260804> )?

> *“**Apple supports three main types of sleep modes for desktops and portables. The three modes are Sleep, Hibernation, and Safe Sleep…"*

> *“**Sleep *  
> *The Mac's RAM is left powered on while it's sleeping. This allows the Mac to wake up very quickly…"*

> *“Hibernation *

> *In this mode, the contents of RAM are copied to your drive before the Mac enters sleep. Once the Mac is sleeping, power is removed from the RAM. “*

> *“Safe Sleep *

> *The RAM contents are copied to the startup drive before the Mac enters sleep, but the RAM remains powered while the Mac is sleeping.”*

> *“Find Out Which Sleep Mode Your Mac is Using **You can find out which sleep mode your Mac is using by opening the Terminal application, located at /Applications/Utilities/. **When the Terminal window opens, enter the following at the prompt (you can triple-click the line below to select it, then copy/paste the text into Terminal):*

> **pmset -g | grep hibernatemode**

> *You should see one of the following responses:*

> *• hibernatemode 0*

> *• hibernatemode 1*

> *• hibernatemode 3*

> *• hibernatemode 25**"*



> *“Zero means normal sleep and is the default for desktops; 1 means hibernate mode and is the default for older portables (pre 2005); 3 means safe sleep and is the default for portables made after 2005; 25 is the same as hibernate mode, but is the setting used for newer (post 2005) Mac portables."*

==&gt; It seems my Mac Pro late 2013 uses hibernate (sleep) mode 0 (RAM is kept powered on and intact and no RAM is written to disk)?

> Last login: Thu Apr 4 02:17:19 on console  
> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$ pmset -g | grep hibernatemode  
> **hibernatemode 0**  
> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$

2) Consider to test how different hibernate modes behaves (will the computer wake up from keyboard or mouse input in all modes)?

==&gt; This seems to be the way I succeeded to set my Mac Pro late 2013 hibernation mode to 25 (hibernation with RAM powered off)

> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$ sudo **pmset -a hibernatemode 25**  
> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$

==&gt; It seems hibernation (mode 25) works on my Mac Pro late 2013 (while in “sleep” the power button light does NOT “breathe” but the computer wakes up on keyboard input ok)

TODO: Measure the difference in power consumption between hibernation mode 0 (RAM powered) and 25 (RAM on disk and powered off)

...

{% endraw %}
