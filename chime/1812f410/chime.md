# Todo: Programming - Consider to create a linux script that download href-referenced deb-files from an URL referenced web-page?

```#1812f410``` *As of 2016-07-28 17:12*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to learn how to design a Linux script to access an URL-refernced web-page and find and download all href-referenced deb-files on it?

1) Consider to modify the proposed script for automating download and install of Visual Studio Code (<https://gist.github.com/pomber/db44098f3413d5213aec>)

==&gt; Consider the latest zip-file for Linux as published on Microsoft official site (<https://code.visualstudio.com/Updates>)?

==&gt; 160728: The 1.3 update (recovery) link seems to be <https://az764295.vo.msecnd.net/stable/e6b4afa53e9c0f54edef1673de9001e9f0f547ae/VSCode-linux-x64-stable.zip>

==&gt; Note: 160728: The official link seem to be unchanged <https://go.microsoft.com/fwlink/?LinkID=620884> (published on <https://code.visualstudio.com/Docs/?dv=linux64>)?

==&gt; This seem to be the download, install and create command line short-cut part?

> curl -L <https://go.microsoft.com/fwlink/?LinkID=620884> &gt; /tmp/vscode.zip

> unzip -qq /tmp/vscode.zip -d /tmp

> sudo cp -r /tmp/VSCode-linux-x64 /opt/vscode

> sudo ln -s /opt/vscode/code /usr/local/bin/vscode

> sudo rm -rf /tmp/VSCode-linux-x64  
> sudo rm -f /tmp/vscode.zip

==&gt; This seem to be the advice to make a desktop presence of the application?

> sudo touch /usr/share/applications/vscode.desktop

> sudo chmod 777 /usr/share/applications/vscode.desktop

> sudo echo -e "&#91;Desktop Entry&#93;\\nName=VSCode\\nComment=Visual Studio Code\\nExec=/opt/vscode/code\\nIcon=/opt/vscode/resources/app/resources/linux/code.png\\nType=Application\\nVersion=1.0\\nTerminal=false\\nCategories=Development" &gt; /usr/share/applications/vscode.desktop

> sudo chmod 644 /usr/share/applications/vscode.deskto

...

2) Consider to edit the script to use sed-command to find the href-referenced zip-file (in case a new zip-file is published)?

==&gt; In this way the script would be able to work also when Microsoft decides to change the LinkID of the link to the zip?

...

3) Consider to understand how Microsoft publish both zip-files (unzip and use) and deb-files (install with package manager)?

==&gt; Note how I first mixed those up and tried to unzip a de-file (which could be done but with a very different content)?

...

4) Consider this page as good reference on regular expressions (<http://regexone.com>)?

==&gt; Consider to find the regular expression to use to find the href-referenced zip-files and assemble an URL for curls to use to download them (regardless of actual LinkId on the web page)?

…

…

Consider to delve into this idea of making the script “smarter” by it being able to search for referenced zip-files and download them (regardless of actual LinkId)?

...

{% endraw %}
