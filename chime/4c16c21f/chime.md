# Todo: Programming - Consider to define service (abilities) of "Bang" Digital World service from how Visual Studio Code is installed on Windows, Linux and MacOS?

```#4c16c21f``` *As of 2016-07-29 14:54*

[mail plain/text](mail.txt)

{% raw %}
So, what can we learn about how Bang Digital World tool should behave from studying the different ways devices for installing Visual Studio Code on Windows, Linux and MacOS?

1) Consider the different sources of the download fro the different platforms?

==&gt; This seem to be the page with links to all platform downloads (<https://code.visualstudio.com/Download>)?

![](<Visual Studio Code download variants.tiff>)

&lt;As of 160729&gt;

==&gt; MacOS download link seems to be here  (<https://go.microsoft.com/fwlink/?LinkID=534106>)?

==&gt; Linux Deb-download seems to be here  (<http://go.microsoft.com/fwlink/?LinkID=760868>)?

==&gt; Linux rpm-download seems to be here (<https://go.microsoft.com/fwlink/?LinkID=760867>)?

==&gt; Linux zip-download seems to be here  (<https://go.microsoft.com/fwlink/?LinkID=620884>)?

==&gt; 32-bit Linux Deb-download seems to be here  (<https://go.microsoft.com/fwlink/?LinkID=760680>)?

==&gt; 32-bit Linux rpm-download seems to be here (<https://go.microsoft.com/fwlink/?LinkID=760681>)?

==&gt; 32-bit Linux zip-download seems to be here  (<https://go.microsoft.com/fwlink/?LinkID=620885>)?

==&gt; The windows installer seems to be here  (<https://go.microsoft.com/fwlink/?LinkID=623230>)?

==&gt; The windows zip-file seems to be here  (<https://go.microsoft.com/fwlink/?LinkID=623231>)?

2) Consider how “Bang" may accomplish creating a Visual Studio Code “world” on the machine where it is running?

==&gt; What “World Pastries” (layer of Worlds) would it be able to work in?

==&gt; The MacOS, x64, 64-bit world?

==&gt; The Linux::Deb, CPU?, nn-bit? world (built from source code using apt and platform tool chain for CPU and memory size)?

==&gt; Consider to try the deb-package on my Linux Machines to see if any of them works?

==&gt; Linux, x86, 64-bit World (executable in zip-file)?

==&gt; Windows, x86, 32/64 bit (from msi-installer and zip-file)?

…

3) Consider to initiate Bang development to have it being able to install Visual Studio Code world on all these platforms?

&gt;MacOS&gt; Bang vscode

1) Know it is a MacOS incarnation?

2) Know to download (<https://go.microsoft.com/fwlink/?LinkID=534106>)?

3) Know to move it to Applications folder?

4) Know to create a code-link in ??-Path

&gt;Linux::deb&gt; Bang vscode

1) Know it is a “true” Linux incarnation (not a Cygwin, MingGW or MSYS2 one)?

2) Identify that it runs on a Debian System (has Advanced Package Manager (APT) based on dpkg and possible aptitude user interface)?

3) Know to invoke sudo apt install (or available deb-package installer) on deb-file URL (<https://go.microsoft.com/fwlink/?LinkID=760680>)?

...

&gt;Linux::rpm&gt; Bang vscode (Red Hat Package Manager (<https://sv.wikipedia.org/wiki/RPM_Package_Manager>))

1) Know it is a “true” Linux incarnation (not a Cygwin, MingGW or MSYS2 one)?

2) Identify it running on a Red Hat distribution (Has a Red Hat package manager (<https://sv.wikipedia.org/wiki/RPM_Package_Manager>))?

3) Know to invoke available package manager (which one) on rpm-file from URL (<https://go.microsoft.com/fwlink/?LinkID=760681>)?

...

&gt;Linux::zip&gt; Bang viscid

1) Know it is a 64-bit, x86 Linux incarnation?

2) Decide to download the zip-file (when and why)?

==&gt; Choose zip-file if package manager fails Udeb or rpm package manager not available)?

3) Know how to download, unzip, move to installation folder and create links from URL (<https://go.microsoft.com/fwlink/?LinkID=620884>)?

See scripts in project “<https://github.com/kjelloh/VSCodeLinuxInstall>"

&gt;Windows&gt;Bang vscode

1) Know it is a Windows incarnation?

2) Know it is a 32-bit or 64-bit incarnation?

3) Know it is a 32-bit incarnation on a 64-bit Windows?

4) Decide on download of zip or exe-install file?

5) For exe-file, download and execute.

5) For zip-file, download, move to install location, add to PATH?

&gt;Windows::MinGW&gt;Bang vscode

&gt;Windows::CygWin&gt;Bang vscode

&gt;Windows::MSYS2&gt;Bang vscode

1) Same as plain Windows?

2) Know it can run Bash shell scripts?

...

3) Seems we can identify some entities that constitutes a world?

==&gt; The CPU entity (defines what final instructions is executable on the platform, e.g. x86)?

==&gt; The memory model (32-bit, 64-bit)? (Or is that defined by the CPU)?

==&gt; The Operating System API (at least for Console scripts we need to know what commands are available)?

…

Consider to delve deer into this idea to initiate the Bang tool project by having it install Visual Studio Code world on available platforms?

...

{% endraw %}
