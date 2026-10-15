# Todo: Python - Consider to document how I got Python "up and running" on my new Mac Pro?

```#c29e4c42``` *As of 2019-05-27 17:18*

[mail plain/text](mail.txt)

{% raw %}
So, here we go again manually configuring a computer to be able to operate in some language, in this case Python, framework?

==&gt; Also see ""

==&gt; Also see "Todo: Consider to document how to correctly make Python work on OS X preferably with VSCode?"

1) Consider to document the steps I actually turned out going down to have Python running on my Mac Pro?

\*) I decided to install the official Python 3.7.3 (<https://www.python.org/ftp/python/3.7.3/python-3.7.3-macosx10.9.pkg> )

\*) And now I could enter the Python3 console OK!

2) Consider what version of Python I should install on my Mac Pro (<https://www.python.org/downloads/mac-osx/> )?

==&gt; It seems I should install version 3.7.3 (<https://www.python.org/ftp/python/3.7.3/python-3.7.3-macosx10.9.pkg> )?

![](<Screenshot 2019-05-27 at 13.17.06.png>)

*Python version 3.7.3 and 2.7.16 is the preferred releases as of March 25 2019*

2) Consider to carefully choose the correct path to install Python as recommended on Mac OS (<https://docs.python.org/3/using/mac.html> )?

> *"*  
> *What you get after installing is a number of things:

> *  
> *• A **MacPython 3.6** folder in your **Applications folder**. In here you find **IDLE**, the development environment that is a standard part of official Python distributions; **PythonLauncher**, which handles double-clicking Python scripts from the Finder; and the **“Build Applet” tool,** which allows you to package Python scripts as standalone applications on your system.  
> *  
> *• A framework **/Library/Frameworks/Python.framework**, which includes the Python executable and libraries. The installer **adds** this location **to your shell path**. To uninstall MacPython, you can simply remove these three things. A **symlink** to the Python **executable** is placed in **/usr/local/bin/**."*

==&gt; Consider the youtube video "How to Read Emails using IMAP Download Attachments Python 3 for Beginners 2018" shows using only a python console and a text editor (<https://www.youtube.com/watch?v=e-OZeAHFpkw&t=177s> )?

==&gt; It seems Mac OS comes pre-installed with Python 2.7 (So I should install Python 3)?

> Last login: Thu May 23 09:11:50 on console  
> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$ **python -v**  
> # installing zipimport hook  
> import zipimport # builtin  
> # installed zipimport hook  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site.py  
> import site # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/os.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/os.py  
> import os # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/os.pyc  
> import errno # builtin  
> import posix # builtin  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/posixpath.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/posixpath.py  
> import posixpath # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/posixpath.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/stat.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/stat.py  
> import stat # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/stat.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/genericpath.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/genericpath.py  
> import genericpath # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/genericpath.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/warnings.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/warnings.py  
> import warnings # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/warnings.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/linecache.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/linecache.py  
> import linecache # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/linecache.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/types.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/types.py  
> import types # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/types.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/UserDict.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/UserDict.py  
> import UserDict # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/UserDict.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/_abcoll.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/_abcoll.py  
> import _abcoll # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/_abcoll.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/abc.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/abc.py  
> import abc # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/abc.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/_weakrefset.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/_weakrefset.py  
> import _weakrefset # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/_weakrefset.pyc  
> import _weakref # builtin  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/copy_reg.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/copy_reg.py  
> import copy_reg # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/copy_reg.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/traceback.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/traceback.py  
> import traceback # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/traceback.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/sysconfig.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/sysconfig.py  
> import sysconfig # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/sysconfig.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/re.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/re.py  
> import re # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/re.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/sre_compile.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/sre_compile.py  
> import sre_compile # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/sre_compile.pyc  
> import _sre # builtin  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/sre_parse.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/sre_parse.py  
> import sre_parse # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/sre_parse.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/sre_constants.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/sre_constants.py  
> import sre_constants # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/sre_constants.pyc  
> dlopen("/System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/lib-dynload/_locale.so", 2);  
> import _locale # dynamically loaded from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/lib-dynload/_locale.so  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/_sysconfigdata.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/_sysconfigdata.py  
> import _sysconfigdata # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/_sysconfigdata.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/_osx_support.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/_osx_support.py  
> import _osx_support # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/_osx_support.pyc  
> import encodings # directory /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/encodings  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/encodings/__init__.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/encodings/__init__.py  
> import encodings # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/encodings/__init__.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/codecs.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/codecs.py  
> import codecs # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/codecs.pyc  
> import _codecs # builtin  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/encodings/aliases.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/encodings/aliases.py  
> import encodings.aliases # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/encodings/aliases.pyc  
> # /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/encodings/utf_8.pyc matches /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/encodings/utf_8.py  
> import encodings.utf_8 # precompiled from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/encodings/utf_8.pyc  
> Python 2.7.10 (default, Feb 22 2019, 21:55:15)  
> &#91;GCC 4.2.1 Compatible Apple LLVM 10.0.1 (clang-1001.0.37.14)&#93; on darwin  
> Type "help", "copyright", "credits" or "license" for more information.  
> dlopen("/System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/lib-dynload/readline.so", 2);  
> import readline # dynamically loaded from /System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/lib-dynload/readline.so  
> &gt;&gt;&gt;

==&gt; It seems the Mac OS built in Python is installed at

> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$ **which python**  
> **/usr/bin/python**  
> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$

==&gt; And there are some symlinks for Python 2.7 already in /usr/bin/ (and all these are Apple controlled as part of the Mac OS distribution)?

> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$ **ls -l /usr/bin/py\***  
> -rwxr-xr-x 4 root wheel 925 Aug 18 2018 /usr/bin/pydoc  
> lrwxr-xr-x 1 root wheel 74 Jan 16 04:22 /usr/bin/pydoc2.7 -&gt; ../../System/Library/Frameworks/Python.framework/Versions/2.7/bin/pydoc2.7  
> -rwxr-xr-x 1 root wheel 66880 May 4 09:04 /usr/bin/python  
> -rwxr-xr-x 4 root wheel 925 Aug 18 2018 /usr/bin/python-config  
> lrwxr-xr-x 1 root wheel 75 Jan 16 04:22 /usr/bin/python2.7 -&gt; ../../System/Library/Frameworks/Python.framework/Versions/2.7/bin/python2.7  
> lrwxr-xr-x 1 root wheel 82 Jan 16 04:22 /usr/bin/python2.7-config -&gt; ../../System/Library/Frameworks/Python.framework/Versions/2.7/bin/python2.7-config  
> -rwxr-xr-x 1 root wheel 66880 May 4 09:04 /usr/bin/pythonw  
> lrwxr-xr-x 1 root wheel 76 Jan 16 04:22 /usr/bin/pythonw2.7 -&gt; ../../System/Library/Frameworks/Python.framework/Versions/2.7/bin/pythonw2.7  
> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$

==&gt; It seems installing 3.7.3 LEAVES /usr/bin/ untouched but adds stuff to /usr/local/bin (and PATH environment variable contains enough to find both python 2.7 and 3.7.3 installations)?

> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$ **ls -l /usr/bin/py\***  
> -rwxr-xr-x 4 root wheel 925 Aug 18 2018 /usr/bin/pydoc  
> lrwxr-xr-x 1 root wheel 74 Jan 16 04:22 /usr/bin/pydoc2.7 -&gt; ../../System/Library/Frameworks/Python.framework/Versions/2.7/bin/pydoc2.7  
> -rwxr-xr-x 1 root wheel 66880 May 4 09:04 /usr/bin/python  
> -rwxr-xr-x 4 root wheel 925 Aug 18 2018 /usr/bin/python-config  
> lrwxr-xr-x 1 root wheel 75 Jan 16 04:22 /usr/bin/python2.7 -&gt; ../../System/Library/Frameworks/Python.framework/Versions/2.7/bin/python2.7  
> lrwxr-xr-x 1 root wheel 82 Jan 16 04:22 /usr/bin/python2.7-config -&gt; ../../System/Library/Frameworks/Python.framework/Versions/2.7/bin/python2.7-config  
> -rwxr-xr-x 1 root wheel 66880 May 4 09:04 /usr/bin/pythonw  
> lrwxr-xr-x 1 root wheel 76 Jan 16 04:22 /usr/bin/pythonw2.7 -&gt; ../../System/Library/Frameworks/Python.framework/Versions/2.7/bin/pythonw2.7  
> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$

> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$ **ls -l /usr/local/bin/py\***  
> lrwxr-xr-x 1 root wheel 68 May 27 14:03 /usr/local/bin/pydoc3 -&gt; ../../../Library/Frameworks/Python.framework/Versions/3.7/bin/pydoc3  
> lrwxr-xr-x 1 root wheel 70 May 27 14:03 /usr/local/bin/pydoc3.7 -&gt; ../../../Library/Frameworks/Python.framework/Versions/3.7/bin/pydoc3.7  
> lrwxr-xr-x 1 root wheel 69 May 27 14:03 /usr/local/bin/python3 -&gt; ../../../Library/Frameworks/Python.framework/Versions/3.7/bin/python3  
> lrwxr-xr-x 1 root wheel 76 May 27 14:03 /usr/local/bin/python3-config -&gt; ../../../Library/Frameworks/Python.framework/Versions/3.7/bin/python3-config  
> lrwxr-xr-x 1 root wheel 71 May 27 14:03 /usr/local/bin/python3.7 -&gt; ../../../Library/Frameworks/Python.framework/Versions/3.7/bin/python3.7  
> lrwxr-xr-x 1 root wheel 78 May 27 14:03 /usr/local/bin/python3.7-config -&gt; ../../../Library/Frameworks/Python.framework/Versions/3.7/bin/python3.7-config  
> lrwxr-xr-x 1 root wheel 72 May 27 14:03 /usr/local/bin/python3.7m -&gt; ../../../Library/Frameworks/Python.framework/Versions/3.7/bin/python3.7m  
> lrwxr-xr-x 1 root wheel 79 May 27 14:03 /usr/local/bin/python3.7m-config -&gt; ../../../Library/Frameworks/Python.framework/Versions/3.7/bin/python3.7m-config  
> lrwxr-xr-x 1 root wheel 68 May 27 14:03 /usr/local/bin/pyvenv -&gt; ../../../Library/Frameworks/Python.framework/Versions/3.7/bin/pyvenv  
> lrwxr-xr-x 1 root wheel 72 May 27 14:03 /usr/local/bin/pyvenv-3.7 -&gt; ../../../Library/Frameworks/Python.framework/Versions/3.7/bin/pyvenv-3.7  
> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$

> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$ env | grep PATH  
> **PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin**  
> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$

==&gt; It seems Mac OS installation of Python 3.7.3 adds applications "IDLE" and "Python Launcher" to the Launchapd?

![](<Screenshot 2019-05-27 at 14.19.41.png>)

Python 3.7.3 applications added to Mac OS Launhpad

==&gt; And it seems I now can enter the python console with the command line "Python3"?

> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$ **python3**  
> Python 3.7.3 (v3.7.3:ef4ec6ed12, Mar 25 2019, 16:52:21)  
> &#91;Clang 6.0 (clang-600.0.57)&#93; on darwin  
> Type "help", "copyright", "credits" or "license" for more information.  
> **&gt;&gt;&gt;**

3) Consider what editor I can use to edit Python scripts?

==&gt; It seems I should prefer "IDLE" app to edit python scrip files (over say Textedit app)?

==&gt; I first tried Textedit but had some struggle to get rid of the extension ".rtf" and then to remove the RTF format data that had been added to the file...

==&gt; It seems I CAN use Mac OS "Textedit" if I set preferences so files are "Plain Text" and NO add extension option is selected on saving file?

NOTE: Prefer to edit with the IDLE app (See above).

![](<Screenshot 2019-05-27 at 14.45.11.png>) ![](<Screenshot 2019-05-27 at 14.45.48.png>)

*Textedit preferences Format "Plain Text" and &lt;When Saving a File&gt; NO add extension option selected*

NOTE: I had to rename the file in Finder and then right-click open the file with Textedit to prohibit the .rtf extension!

NOTE: I actually failed to get Textedit to create a plain text file (I gave up and used the IDLE app instead)

**THIS SUCKS! Why does the Textedit app go to such length of stopping me from editing plain text files in plain text format with the extension I want?**

3) Consider to document the installation fo the official Python 3.7.3 on my Mac Pro 2013?

![](<Screenshot 2019-05-27 at 13.47.42.png>)

*Don't forget to click on the &lt;Install Certificates&gt; at the end of the main installation*

![](<Screenshot 2019-05-27 at 13.50.52.png>)

*Consider the "Read Me" information on the installed Python 3.7.3*

> *"This package will install Python 3.7.3 for macOS 10.9 or later for the following architecture(s): x86_64.

> Which installer variant should I use?

> For Python.3.7, [python.org](http://python.org) currently provides two installer variants for download: one that installs a **64-bit-only** Python capable of running on **macOS 10.9** (Mavericks) **or later**; and one that installs a **64-bit/32-bit** Intel Python capable of running on **macOS 10.6** (Snow Leopard) **or later**. (This ReadMe was installed with the 10.9 or later variant.) If you are running on macOS 10.9 or later and if you have no need for compatibility with older systems, use the 10.9 variant. Use the 10.6 variant if you are running on macOS 10.6 through 10.8 or if you want to produce standalone applications that can run on systems from 10.6. The Pythons installed by these installers are built with private copies of some third-party libraries not included with or newer than those in macOS itself. The list of these libraries varies by installer variant and is included at the end of the License.rtf file.

> Certificate verification and OpenSSL

> This variant of Python 3.7 **includes** its own private copy of **OpenSSL** 1.1.0. The deprecated Apple-supplied OpenSSL libraries are no longer used. This means that the trust certificates in system and user keychains managed by the Keychain Access application and the security command line utility are no longer used as defaults by the Python ssl module. A sample command script is included in /Applications/Python 3.7 to install a curated bundle of default root certificates from the third-party certifi package (<https://pypi.org/project/certifi/>). If you choose to use certifi, you should consider subscribing to the project's email update service to be notified when the certificate bundle is updated.

> The bundled pip included with this installer has its own default certificate store for verifying download connections.

> Using IDLE or other Tk applications

> Both installer variants now come with their **own private version of Tcl/Tk 8.6**. They no longer use system-supplied or third-party supplied versions of Tcl/Tk as in previous releases.

> Other changes

> For other changes in this release, see the What's new section in the Documentation Set for this release and its Release Notes link at https://www.python.org/downloads/.

> Python 3 and Python 2 Co-existence

> Python.org Python 3.7 and 2.7.x versions can both be installed on your system and will not conflict. **Command names for Python 3 contain a 3 in them**, python3 (or python3.7), idle3 (or idle3.7), pip3 (or pip3.7), etc. **Python 2.7 command names contain a 2 or no digit**: python2 (or python2.7 or python), idle2 (or idle2.7 or idle), etc."*

NOTE: ALL Python 3 commands has a '3' in them!

![](<Screenshot 2019-05-27 at 13.57.26.png>)

*Consider the Python 3.7.3 License*

> *"*  
> *HISTORY AND LICENSE

> HISTORY OF THE SOFTWARE

> Python was created in the early 1990s by **Guido van Rossum** at Stichting Mathematisch Centrum (CWI, see <http://www.cwi.nl>) in the Netherlands as a successor of a language called ABC. Guido remains Python's principal author, although it includes many contributions from others.

> In 1995, Guido continued his work on Python at the Corporation for National Research Initiatives (CNRI, see <http://www.cnri.reston.va.us>) in Reston, Virginia where he released several versions of the software.

> In May 2000, Guido and the Python core development team moved to [BeOpen.com](http://BeOpen.com) to form the BeOpen PythonLabs team. In October of the same year, the PythonLabs team moved to Digital Creations (now Zope Corporation, see <http://www.zope.com>). In 2001, the Python Software Foundation (PSF, see <http://www.python.org/psf/>) was formed, a non-profit organization created specifically to own Python-related Intellectual Property. Zope Corporation is a sponsoring member of the PSF.

> All Python releases are Open Source (see <http://www.opensource.org> for the Open Source Definition). Historically, most, but not all, Python releases have also been GPL-compatible; the table below summarizes the various releases.

> Release Derived Year Owner GPL-  
> from compatible?

> 0.9.0 thru 1.2 n/a 1991-1995 CWI yes  
> 1.3 thru 1.5.2 1.2 1995-1999 CNRI yes  
> 1.6 1.5.2 2000 CNRI no  
> 2.0 1.6 2000 [BeOpen.com](http://BeOpen.com) no  
> 1.6.1 1.6 2001 CNRI no  
> 2.1 2.0+1.6.1 2001 PSF no  
> 2.0.1 2.0+1.6.1 2001 PSF yes  
> 2.1.1 2.1+2.0.1 2001 PSF yes  
> 2.1.2 2.1.1 2002 PSF yes  
> 2.1.3 2.1.2 2002 PSF yes  
> 2.2 and above 2.1.1 2001-now PSF yes

> Note: GPL-compatible doesn't mean that we're distributing Python under the GPL. All Python **licenses**, unlike the GPL, **let you distribute a modified version without making your changes open source**. The GPL-compatible licenses make it possible to combine Python with other software that is released under the GPL; the others don't.

> Thanks to the many outside volunteers who have worked under Guido's direction to make these releases possible.

> TERMS AND CONDITIONS FOR ACCESSING OR OTHERWISE USING PYTHON

> **PYTHON SOFTWARE FOUNDATION LICENSE VERSION 2**

> 1. This LICENSE AGREEMENT is between the Python Software Foundation ("PSF"), and the Individual or Organization ("Licensee") accessing and otherwise using this software ("Python") in source or binary form and its associated documentation.

> 2. Subject to the terms and conditions of this License Agreement, PSF hereby grants Licensee a nonexclusive, royalty-free, world-wide license to reproduce, analyze, test, perform and/or display publicly, prepare derivative works, distribute, and otherwise use Python alone or in any derivative version, provided, however, that PSF's License Agreement and PSF's notice of copyright, i.e., "Copyright (c) 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016 Python Software Foundation; All Rights Reserved" are retained in Python alone or in any derivative version prepared by Licensee.

> 3. In the event Licensee prepares a derivative work that is based on or incorporates Python or any part thereof, and wants to make the derivative work available to others as provided herein, then Licensee hereby agrees to include in any such work a brief summary of the changes made to Python.

> 4. PSF is making Python available to Licensee on an "AS IS" basis. PSF MAKES NO REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED. BY WAY OF EXAMPLE, BUT NOT LIMITATION, PSF MAKES NO AND DISCLAIMS ANY REPRESENTATION OR WARRANTY OF MERCHANTABILITY OR FITNESS FOR ANY PARTICULAR PURPOSE OR THAT THE USE OF PYTHON WILL NOT INFRINGE ANY THIRD PARTY RIGHTS.

> 5. PSF SHALL NOT BE LIABLE TO LICENSEE OR ANY OTHER USERS OF PYTHON FOR ANY INCIDENTAL, SPECIAL, OR CONSEQUENTIAL DAMAGES OR LOSS AS A RESULT OF MODIFYING, DISTRIBUTING, OR OTHERWISE USING PYTHON, OR ANY DERIVATIVE THEREOF, EVEN IF ADVISED OF THE POSSIBILITY THEREOF.

> 6. This License Agreement will automatically terminate upon a material breach of its terms and conditions.

> 7. Nothing in this License Agreement shall be deemed to create any relationship of agency, partnership, or joint venture between PSF and Licensee. This License Agreement does not grant permission to use PSF trademarks or trade name in a trademark sense to endorse or promote products or services of Licensee, or any third party.

> 8. By copying, installing or otherwise using Python, Licensee agrees to be bound by the terms and conditions of this License Agreement.

> [BEOPEN.COM](http://BEOPEN.COM) LICENSE AGREEMENT FOR PYTHON 2.0

> BEOPEN PYTHON OPEN SOURCE LICENSE AGREEMENT VERSION 1

> 1. This LICENSE AGREEMENT is between [BeOpen.com](http://BeOpen.com) ("BeOpen"), having an office at 160 Saratoga Avenue, Santa Clara, CA 95051, and the Individual or Organization ("Licensee") accessing and otherwise using this software in source or binary form and its associated documentation ("the Software").

> 2. Subject to the terms and conditions of this BeOpen Python License Agreement, BeOpen hereby grants Licensee a non-exclusive, royalty-free, world-wide license to reproduce, analyze, test, perform and/or display publicly, prepare derivative works, distribute, and otherwise use the Software alone or in any derivative version, provided, however, that the BeOpen Python License is retained in the Software, alone or in any derivative version prepared by Licensee.

> 3. BeOpen is making the Software available to Licensee on an "AS IS" basis. BEOPEN MAKES NO REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED. BY WAY OF EXAMPLE, BUT NOT LIMITATION, BEOPEN MAKES NO AND DISCLAIMS ANY REPRESENTATION OR WARRANTY OF MERCHANTABILITY OR FITNESS FOR ANY PARTICULAR PURPOSE OR THAT THE USE OF THE SOFTWARE WILL NOT INFRINGE ANY THIRD PARTY RIGHTS.

> 4. BEOPEN SHALL NOT BE LIABLE TO LICENSEE OR ANY OTHER USERS OF THE SOFTWARE FOR ANY INCIDENTAL, SPECIAL, OR CONSEQUENTIAL DAMAGES OR LOSS AS A RESULT OF USING, MODIFYING OR DISTRIBUTING THE SOFTWARE, OR ANY DERIVATIVE THEREOF, EVEN IF ADVISED OF THE POSSIBILITY THEREOF.

> 5. This License Agreement will automatically terminate upon a material breach of its terms and conditions.

> 6. This License Agreement shall be governed by and interpreted in all respects by the law of the State of California, excluding conflict of law provisions. Nothing in this License Agreement shall be deemed to create any relationship of agency, partnership, or joint venture between BeOpen and Licensee. This License Agreement does not grant permission to use BeOpen trademarks or trade names in a trademark sense to endorse or promote products or services of Licensee, or any third party. As an exception, the "BeOpen Python" logos available at <http://www.pythonlabs.com/logos.html> may be used according to the permissions granted on that web page.

> 7. By copying, installing or otherwise using the software, Licensee agrees to be bound by the terms and conditions of this License Agreement.

> CNRI LICENSE AGREEMENT FOR PYTHON 1.6.1

> 1. This LICENSE AGREEMENT is between the Corporation for National Research Initiatives, having an office at 1895 Preston White Drive, Reston, VA 20191 ("CNRI"), and the Individual or Organization ("Licensee") accessing and otherwise using Python 1.6.1 software in source or binary form and its associated documentation.

> 2. Subject to the terms and conditions of this License Agreement, CNRI hereby grants Licensee a nonexclusive, royalty-free, world-wide license to reproduce, analyze, test, perform and/or display publicly, prepare derivative works, distribute, and otherwise use Python 1.6.1 alone or in any derivative version, provided, however, that CNRI's License Agreement and CNRI's notice of copyright, i.e., "Copyright (c) 1995-2001 Corporation for National Research Initiatives; All Rights Reserved" are retained in Python 1.6.1 alone or in any derivative version prepared by Licensee. Alternately, in lieu of CNRI's License Agreement, Licensee may substitute the following text (omitting the quotes): "Python 1.6.1 is made available subject to the terms and conditions in CNRI's License Agreement. This Agreement together with Python 1.6.1 may be located on the Internet using the following unique, persistent identifier (known as a handle): 1895.22/1013. This Agreement may also be obtained from a proxy server on the Internet using the following URL: <http://hdl.handle.net/1895.22/1013>".

> 3. In the event Licensee prepares a derivative work that is based on or incorporates Python 1.6.1 or any part thereof, and wants to make the derivative work available to others as provided herein, then Licensee hereby agrees to include in any such work a brief summary of the changes made to Python 1.6.1.

> 4. CNRI is making Python 1.6.1 available to Licensee on an "AS IS" basis. CNRI MAKES NO REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED. BY WAY OF EXAMPLE, BUT NOT LIMITATION, CNRI MAKES NO AND DISCLAIMS ANY REPRESENTATION OR WARRANTY OF MERCHANTABILITY OR FITNESS FOR ANY PARTICULAR PURPOSE OR THAT THE USE OF PYTHON 1.6.1 WILL NOT INFRINGE ANY THIRD PARTY RIGHTS.

> 5. CNRI SHALL NOT BE LIABLE TO LICENSEE OR ANY OTHER USERS OF PYTHON 1.6.1 FOR ANY INCIDENTAL, SPECIAL, OR CONSEQUENTIAL DAMAGES OR LOSS AS A RESULT OF MODIFYING, DISTRIBUTING, OR OTHERWISE USING PYTHON 1.6.1, OR ANY DERIVATIVE THEREOF, EVEN IF ADVISED OF THE POSSIBILITY THEREOF.

> 6. This License Agreement will automatically terminate upon a material breach of its terms and conditions.

> 7. This License Agreement shall be governed by the federal intellectual property law of the United States, including without limitation the federal copyright law, and, to the extent such U.S. federal law does not apply, by the law of the Commonwealth of Virginia, excluding Virginia's conflict of law provisions. Notwithstanding the foregoing, with regard to derivative works based on Python 1.6.1 that incorporate non-separable material that was previously distributed under the GNU General Public License (GPL), the law of the Commonwealth of Virginia shall govern this License Agreement only as to issues arising under or with respect to Paragraphs 4, 5, and 7 of this License Agreement. Nothing in this License Agreement shall be deemed to create any relationship of agency, partnership, or joint venture between CNRI and Licensee. This License Agreement does not grant permission to use CNRI trademarks or trade name in a trademark sense to endorse or promote products or services of Licensee, or any third party.

> 8. By clicking on the "ACCEPT" button where indicated, or by copying, installing or otherwise using Python 1.6.1, Licensee agrees to be bound by the terms and conditions of this License Agreement.

> ACCEPT

> CWI LICENSE AGREEMENT FOR PYTHON 0.9.0 THROUGH 1.2

> Copyright (c) 1991 - 1995, Stichting Mathematisch Centrum Amsterdam, The Netherlands. All rights reserved.

> Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of Stichting Mathematisch Centrum or CWI not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.

> STICHTING MATHEMATISCH CENTRUM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL STICHTING MATHEMATISCH CENTRUM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

> LICENSES AND ACKNOWLEDGEMENTS FOR INCORPORATED SOFTWARE

> This installer incorporates portions of the following third-party software:

> OpenSSL 1.1.0j  
> Tcl 8.6.8  
> Tk 8.6.8  
> XZ 5.2.3  
> NCurses 5.9  
> SQLite 3.22.0

> For licenses and acknowledgements for these and other third-party software incorporated in this Python distribution, please refer to the on-line documentation here.**"*

![](<Screenshot 2019-05-27 at 14.00.57.png>)

*Mac OS standard dialog to accept the license agreement*

![](<Screenshot 2019-05-27 at 14.01.40.png>)

*Python 3.7.3 for Mac OS requires 108 MB of space on the computer disk*

![](<Screenshot 2019-05-27 at 14.02.43.png>)

*Mac OS requires login by user to authorise installation*

![](<Screenshot 2019-05-27 at 14.03.39.png>)

*Python 3.7.3 installation script in in "mid step"*

![](<Screenshot 2019-05-27 at 14.04.35.png>)

Succesful Python 3.7.3 installation

![](<Screenshot 2019-05-27 at 14.07.33.png>)

*The "Install Certificates" command (script) in installed "Python 3.7" folder in user &lt;Applications&gt;*

![](<Screenshot 2019-05-27 at 14.09.04.png>)

*The output of running the "Install Certificates" command (script) in installed "Python 3.7" folder in user &lt;Applications&gt;*

  
> *"*Last login: Mon May 27 13:29:02 on ttys000  
> /Applications/Python\\ 3.7/Install\\ Certificates.command ; exit;  
> Kjell-Olovs-Mac-Pro:~ kjell-olovhogdal$ /Applications/Python\\ 3.7/Install\\ Certificates.command ; exit;  
> -- pip install --upgrade certifi  
> Collecting certifi  
> Downloading <https://files.pythonhosted.org/packages/60/75/f692a584e85b7eaba0e03827b3d51f45f571c2e793dd731e598828d380aa/certifi-2019.3.9-py2.py3-none-any.whl> (158kB)  
> 100% |████████████████████████████████| 163kB 3.3MB/s  
> Installing collected packages: certifi  
> Successfully installed certifi-2019.3.9  
> You are using pip version 19.0.3, however version 19.1.1 is available.  
> You should consider upgrading via the 'pip install --upgrade pip' command.  
> -- removing any existing file or link  
> -- creating symlink to certifi certificate bundle  
> -- setting permissions  
> -- update complete  
> logout  
> Saving session...  
> ...copying shared history...  
> ...saving history...truncating history files...  
> ...completed.  
> Deleting expired sessions...13 completed.

> &#91;Process completed&#93;  
> *"*

**\*THIS SUCKS\* My fresh install of Python 3.7.3 warns me I have an outdated pip (pip version 19.0.3 instead of 19.1.1)**

...

{% endraw %}
