# Todo: Qt - Consider to document installation and configuration experiences on different platforms?

```#95ece13b``` *As of 2017-07-29 20:03*

[mail plain/text](mail.txt)

{% raw %}
Consider it could be a good idea to document how to and the result of installing the Qt development environment on different platforms?

1) Consider to document how I installed Qt on my MAC OS (Macbook Pro 2014)

==&gt; The selection between purchased and free version seems to be provided here (<https://info.qt.io/download-qt-for-application-development>)

==&gt; I downloaded the Open Source Installer from the Qt web-site ([https://www.qt.io/download-open-source/?hsCtaTracking=f977210e-de67-475f-a32b-65cec207fd03%7Cd62710cd-e1db-46aa-8d4d-2f1c1ffdacea](https://www.qt.io/download-open-source/?hsCtaTracking=f977210e-de67-475f-a32b-65cec207fd03|d62710cd-e1db-46aa-8d4d-2f1c1ffdacea))

==&gt; I ran the installer and had to create a Qt account (See separate documentation)

==&gt; The installer stated it would install to “**/Users/kjell-olovhogdahl/Qt**”

==&gt; I selected to install lastest versio 5.9.1.

==&gt; The size was stated to 21 Gb.

==&gt; The download and start of Qt creators seems to work alright :)

2) Consider to document how I installed Qt on my Linux Mate (Ubuntu 16.04) machine?

==&gt; I selected to download the open source version of Qt from this page (<https://info.qt.io/download-qt-for-application-development>)

==&gt; Firefox Web browser (or was it linux itself) offered to open the qt-unified-linux… .run with “Atril Document Viewer” (which I did not)

==&gt; I selected to download the \*.run fil as a file.

==&gt; Then I had to change the file to be executable (as all linux users know and love to do…\*sigh\*) (<https://askubuntu.com/questions/236811/how-do-i-install-qt5-which-comes-as-a-run-file>)

  
> ```
> kjell-olovhogdahl@ubuntu:~/Downloads$ pwd  
> /home/kjell-olovhogdahl/Downloads  
> kjell-olovhogdahl@ubuntu:~/Downloads$ ls  
> qt-unified-linux-x64-3.0.0-online.run  vscode  
> kjell-olovhogdahl@ubuntu:~/Downloads$ chmod u+x qt*.run  
> kjell-olovhogdahl@ubuntu:~/Downloads$ ls -l  
> total 32080  
> -rwxrw-r-- 1 kjell-olovhogdahl kjell-olovhogdahl 32841736 Jul 29 18:15 qt-unified-linux-x64-3.0.0-online.run  
> drwxrwxr-x 3 kjell-olovhogdahl kjell-olovhogdahl     4096 Jul 28  2016 vscode  
> kjell-olovhogdahl@ubuntu:~/Downloads$ ./qt-unified-linux-x64-3.0.0-online.run 

> ```

  
==&gt; The installer started and I logged in the my Qt account (installer started download)

==&gt; Installer stated it would install to “**/home/kjell-olovhogdahl/Qt**”

==&gt; I selected to install Qt version 5.9.1

==&gt; Installer stated the download size to be 1.47 Gb (much smaller than the MAC OS version!)

==&gt; Qt Creator now seems to start and run ok (but it fails to build a default Qt widgets application)!

==&gt; At this stage I tried to build and run a Qt Widgets application but failed and realised I had to install more stuff (e.g., see (<https://wiki.qt.io/Install_Qt_5_on_Ubuntu>))

==&gt; See attached log file of these installs to my Ubuntu 16.04 Mate machine.

## Attachments

- [QtCreatorAdditionalUbuntu16.04.Installs.rtf](QtCreatorAdditionalUbuntu16.04.Installs.rtf)

{% endraw %}
