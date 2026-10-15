# Todo: Programming - Consider to check out Visual Studio Code for Windows, MAC and Linux?

```#6729f029``` *As of 2016-07-28 17:03*

[mail plain/text](mail.txt)

{% raw %}
So, it seems Microsoft just launched a cross platform code editor called Visual Studio Code that seem like a goodie to look into?

1) This seem to be a good talk where Visual Studio Code is presented (<https://channel9.msdn.com/Events/Build/2016/C-Discussion>)?

==&gt; The talk shows how the product is installed and used on Ubuntu.

2) The product seem to be downloadable here (<http://code.visualstudio.com/>)?

==&gt; I downloaded the Ubuntu 64-bit stable version (named VSCode-linux-x64.zip) and extracted it to “/home/parallels/Desktop/“ (I failed to find out where programs on ubuntu actually should go)

==&gt; In Visual Studio Code top command line (click on the frame above the editor) enter “ext install c++” (and select the C++ extension as shown in the talk above at 16:30)

==&gt; Note 1604xxx: The deb-installer (beta) did not work. And it seems it is due to it being for AMD processor?

==&gt; Consider the latest zip-file for Linux as published on Microsoft official site (<https://code.visualstudio.com/Updates>)?

==&gt; 160728: The 1.3 update (recovery) link seems to be <https://az764295.vo.msecnd.net/stable/e6b4afa53e9c0f54edef1673de9001e9f0f547ae/VSCode-linux-x64-stable.zip>

==&gt; 160728: The official link seem to be <https://go.microsoft.com/fwlink/?LinkID=620884> (published on <https://code.visualstudio.com/Docs/?dv=linux64>)

==&gt; Consider to store it as sub-folder to “/opt” (<https://gist.github.com/pomber/db44098f3413d5213aec>)

==&gt; This seem to be the advice to download and copy the tool onto the system (for command line access as vscode)?

==&gt; Note: 160728: The official link seem to be unchanged <https://go.microsoft.com/fwlink/?LinkID=620884> (published on <https://code.visualstudio.com/Docs/?dv=linux64>)?

- curl -L <https://go.microsoft.com/fwlink/?LinkID=620884> &gt; /tmp/vscode.zip
- unzip -qq /tmp/vscode.zip -d /tmp
- sudo cp -r /tmp/VSCode-linux-x64 /opt/vscode
- sudo ln -s /opt/vscode/code /usr/local/bin/vscode
- sudo rm -rf /tmp/VSCode-linux-x64
- sudo rm -f /tmp/vscode.zip

==&gt; This seem to be the advice to make a desktop presence of the application?

- sudo touch /usr/share/applications/vscode.desktop
- sudo chmod 777 /usr/share/applications/vscode.desktop
- sudo echo -e "&#91;Desktop Entry&#93;\\nName=VSCode\\nComment=Visual Studio Code\\nExec=/opt/vscode/code\\nIcon=/opt/vscode/resources/app/resources/linux/code.png\\nType=Application\\nVersion=1.0\\nTerminal=false\\nCategories=Development" &gt; /usr/share/applications/vscode.desktop
- sudo chmod 644 /usr/share/applications/vscode.deskto

==&gt; Consider to install it to “/usr/share/applications” as indicated by deb-package <https://go.microsoft.com/fwlink/?LinkID=760868> (<https://code.visualstudio.com/Docs/?dv=linux64_deb>)

==&gt; See attached vscode_zip_content_tree.txt for the content of downloaded zip-file (unzipped with MATE file explorer)

{% endraw %}
