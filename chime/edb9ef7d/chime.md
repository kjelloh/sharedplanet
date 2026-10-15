# Todo: Programming - Consider to document how to build the Jucipp C++ IDE from Github source?

```#edb9ef7d``` *As of 2016-07-17 18:40*

[mail plain/text](mail.txt)

{% raw %}
So, how easy is it to actually build the open source Jucipp from github project source code?

-1) Consider to document impressions on the jucipp IDE behaviour?

==&gt; Opening a folder with an existing CMake project does not make jucipp know settings (e.g., “C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\build”)?

==&gt; It complains on boost includes although the CMakeLists.txt knows how to find boost libraries?

==&gt; Q: Is it because “C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\build” is now a MinGW based project (it is a Visual Studio one)?

==&gt; No, it seems jucipp does not understand cmake settings (<http://stackoverflow.com/questions/36241190/how-to-automatically-update-cmake-files-in-jucipp>)?

==&gt; Jucipp does not come with built in help?

...

1) Consider to document how to build it on Windows 10?

==&gt; I cloned "<https://github.com/cppit/jucipp.git>” from Github web-page triggering Github desktop.

![](<Github Desktop clone jucipp.tiff>)

==&gt; To build and install on Windows we seem to need M2SYS command line shell (<https://github.com/cppit/jucipp/blob/master/docs/install.md#windows-with-msys2-httpsmsys2githubio>)

==&gt; The M2SYS installer and instructions seem to live here (<https://msys2.github.io/>)?

==&gt; The actual installer (64 bit) seems to be here (<http://repo.msys2.org/distrib/x86_64/msys2-x86_64-20160205.exe>)?

![](<M2SYS 64 bit installer download.tiff>)

==&gt; I installed to default “C:\\msys64”.

==&gt; I started the M2SYS command line shell and performed the update operations as instructed.

==&gt; NOTE: The shell does not seem to support a paste-from-clipboard operation (I failed to copy-paste the commands to perform)?

==&gt; NOTE: Copy-to-clipboard seem to work by

a) drag-copy followed by &lt;enter&gt;.

b) drag-copy and right-click many &lt;copy&gt;

> > kjell-olovhogdahl@KJELL-OLOVHA74E MSYS ~

> > $ **pacman -Sy pacman**

> > :: Synchronizing package databases...

> > mingw32 278.9 KiB 850K/s 00:00 &#91;#####################&#93; 100%

> > mingw32.sig 96.0 B 0.00B/s 00:00 &#91;#####################&#93; 100%

> > mingw64 278.5 KiB 893K/s 00:00 &#91;#####################&#93; 100%

> > mingw64.sig 96.0 B 0.00B/s 00:00 &#91;#####################&#93; 100%

> > msys 135.6 KiB 404K/s 00:00 &#91;#####################&#93; 100%

> > msys.sig 96.0 B 0.00B/s 00:00 &#91;#####################&#93; 100%

> > resolving dependencies...

> > looking for conflicting packages...

> > Packages (1) pacman-5.0.1-1

> > Total Download Size: 6.81 MiB

> > Total Installed Size: 33.72 MiB

> > Net Upgrade Size: 0.12 MiB

> > :: Proceed with installation? &#91;Y/n&#93; Y

> > :: Retrieving packages ...

> > pacman-5.0.1-1-x86_64 6.8 MiB 1821K/s 00:04 &#91;#####################&#93; 100%

> > (1/1) checking keys in keyring &#91;#####################&#93; 100%

> > (1/1) checking package integrity &#91;#####################&#93; 100%

> > (1/1) loading package files &#91;#####################&#93; 100%

> > (1/1) checking for file conflicts &#91;#####################&#93; 100%

> > (1/1) checking available disk space &#91;#####################&#93; 100%

> > :: Processing package changes...

> > (1/1) upgrading pacman &#91;#####################&#93; 100%

> > kjell-olovhogdahl@KJELL-OLOVHA74E MSYS ~

> > $ **pacman -Syu**

> > :: Synchronizing package databases...

> > mingw32 is up to date

> > mingw64 is up to date

> > msys is up to date

> > :: Starting core system upgrade...

> > warning: terminate other MSYS2 programs before proceeding

> > resolving dependencies...

> > looking for conflicting packages...

> > Packages (4) bash-4.3.046-1 filesystem-2016.07-1 mintty-1~2.3.6-1

> > msys2-runtime-2.5.2-2

> > Total Download Size: 4.26 MiB

> > Total Installed Size: 18.09 MiB

> > Net Upgrade Size: -0.12 MiB

> > :: Proceed with installation? &#91;Y/n&#93; Y

> > :: Retrieving packages...

> > msys2-runtime-2.5.2... 2.2 MiB 1021K/s 00:02 &#91;#####################&#93; 100%

> > bash-4.3.046-1-x86_64 1876.6 KiB 1174K/s 00:02 &#91;#####################&#93; 100%

> > filesystem-2016.07-... 37.3 KiB 7.29M/s 00:00 &#91;#####################&#93; 100%

> > mintty-1~2.3.6-1-x86_64 154.7 KiB 117K/s 00:01 &#91;#####################&#93; 100%

> > (4/4) checking keys in keyring &#91;#####################&#93; 100%

> > (4/4) checking package integrity &#91;#####################&#93; 100%

> > (4/4) loading package files &#91;#####################&#93; 100%

> > (4/4) checking for file conflicts &#91;#####################&#93; 100%

> > (4/4) checking available disk space &#91;#####################&#93; 100%

> > warning: could not get file information for mingw32/

> > warning: could not get file information for mingw32/bin/

> > warning: could not get file information for mingw32/etc/

> > warning: could not get file information for mingw32/include/

> > warning: could not get file information for mingw32/lib/

> > warning: could not get file information for mingw32/share/

> > warning: could not get file information for mingw64/

> > warning: could not get file information for mingw64/bin/

> > warning: could not get file information for mingw64/etc/

> > warning: could not get file information for mingw64/include/

> > warning: could not get file information for mingw64/lib/

> > warning: could not get file information for mingw64/share/

> > warning: could not get file information for opt/

> > :: Processing package changes...

> > (1/4) upgrading msys2-runtime &#91;#####################&#93; 100%

> > (2/4) upgrading bash &#91;#####################&#93; 100%

> > (3/4) upgrading filesystem &#91;#####################&#93; 100%

> > 2 &#91;main&#93; pacman (2756) C:\\msys64\\usr\\bin\\pacman.exe: \*\*\* fatal error - cygheap base mismatch detected - 0x180326400/0x18033A408.

> > This problem is probably due to using incompatible versions of the cygwin DLL.

> > Search for cygwin1.dll using the Windows Start-&gt;Find/Search facility

> > and delete all but the most recent version. The most recent version \*should\*

> > reside in x:\\cygwin\\bin, where 'x' is the drive on which you have

> > installed the cygwin distribution. Rebooting is also suggested if you

> > are unable to find another cygwin DLL.

> > 0 &#91;main&#93; pacman 6876 fork: child -1 - forked process 2756 died unexpectedly, retry 0, exit code 0xC0000142, errno 11

> > error: could not fork a new process (Resource temporarily unavailable)

> > (4/4) upgrading mintty &#91;#####################&#93; 100%

> > warning: terminate MSYS2 without returning to shell and check for updates again

> > warning: for example close your terminal window instead of calling exit

==&gt; It seems I have to force-close the MSYS2 command line shell window?

![](<MSYS2 Install Restart - Close Anyway.tiff>)

==&gt; But the installed short-cuts to “C:\\msys64\\msys2_shell.bat” does not seem to work?

> > 'C:\\msys64\\msys2_shell.bat' is not recognized as an internal or external command,

> > operable program or batch file.

==&gt; It seems the path should be “C:\\msys64\\msys2_shell.cmd”?

==&gt; **\*SIGH\***

==&gt; I fixed the short-cuts by editing them at “C:\\Users\\kjell-olovhogdahl\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\MSYS2”

==&gt; Existing short-cut seem to be “C:\\Windows\\System32\\cmd.exe /A /Q /K C:\\msys64\\msys2_shell.bat”?

==&gt; I simply created a new one to “C:\\msys64\\msys2_shell.cmd” that seem to work just fine?

==&gt; I now performed the final step of MSYS2 update.

> > kjell-olovhogdahl@KJELL-OLOVHA74E MSYS ~

> > $ pacman -Su

> > :: Starting core system upgrade...

> > there is nothing to do

> > :: Starting full system upgrade...

> > :: Replace repman-git with msys/pactoys-git? &#91;Y/n&#93; Y

> > resolving dependencies...

> > looking for conflicting packages...

> > Packages (37) bash-completion-2.3-1 bsdcpio-3.2.0-1 bsdtar-3.2.0-1

> > coreutils-8.25-1 crypt-1.3-1 curl-7.49.1-1 file-5.25-1

> > gcc-libs-5.3.0-3 gettext-0.19.7-3 gmp-6.1.0-2 gnupg-1.4.20-1

> > grep-2.22-3 gzip-1.7-1 heimdal-libs-1.5.3-9 libarchive-3.2.0-1

> > libasprintf-0.19.7-3 libassuan-2.4.2-1 libcrypt-1.3-1

> > libcurl-7.49.1-1 libexpat-2.1.1-1 libgettextpo-0.19.7-3

> > libgpg-error-1.23-1 libgpgme-1.6.0-1 libintl-0.19.7-3

> > liblzma-5.2.2-1 libnettle-3.2-1 libopenssl-1.0.2.h-1

> > libssh2-1.7.0-1 mpfr-3.1.4-1

> > msys2-launcher-git-0.3.29.4028b6c-1 ncurses-6.0.20160220-1

> > openssl-1.0.2.h-1 pactoys-git-r2.07ca37f-1 rebase-4.4.2-1

> > repman-git-r23.87bf865-1 &#91;removal&#93; wget-1.17.1-3 xz-5.2.2-1

> > Total Download Size: 15.66 MiB

> > Total Installed Size: 82.08 MiB

> > Net Upgrade Size: 6.33 MiB

> > :: Proceed with installation? &#91;Y/n&#93; Y

> > :: Retrieving packages...

> > bash-completion-2.3... 184.1 KiB 596K/s 00:00 &#91;#####################&#93; 100%

> > gcc-libs-5.3.0-3-x86_64 783.6 KiB 1234K/s 00:01 &#91;#####################&#93; 100%

> > libintl-0.19.7-3-x86_64 25.6 KiB 6.26M/s 00:00 &#91;#####################&#93; 100%

> > libgettextpo-0.19.7... 110.7 KiB 4.51M/s 00:00 &#91;#####################&#93; 100%

> > libasprintf-0.19.7-... 11.8 KiB 11.5M/s 00:00 &#91;#####################&#93; 100%

> > gettext-0.19.7-3-x86_64 1524.1 KiB 1386K/s 00:01 &#91;#####################&#93; 100%

> > liblzma-5.2.2-1-x86_64 76.6 KiB 5.34M/s 00:00 &#91;#####################&#93; 100%

> > gmp-6.1.0-2-x86_64 369.2 KiB 1191K/s 00:00 &#91;#####################&#93; 100%

> > libnettle-3.2-1-x86_64 101.1 KiB 4.70M/s 00:00 &#91;#####################&#93; 100%

> > coreutils-8.25-1-x86_64 2.2 MiB 1184K/s 00:02 &#91;#####################&#93; 100%

> > ncurses-6.0.2016022... 1147.2 KiB 1409K/s 00:01 &#91;#####################&#93; 100%

> > bsdcpio-3.2.0-1-x86_64 747.1 KiB 1199K/s 00:01 &#91;#####################&#93; 100%

> > bsdtar-3.2.0-1-x86_64 785.4 KiB 1208K/s 00:01 &#91;#####################&#93; 100%

> > libcrypt-1.3-1-x86_64 13.5 KiB 13.2M/s 00:00 &#91;#####################&#93; 100%

> > crypt-1.3-1-x86_64 13.9 KiB 6.76M/s 00:00 &#91;#####################&#93; 100%

> > libopenssl-1.0.2.h-... 803.0 KiB 1035K/s 00:01 &#91;#####################&#93; 100%

> > heimdal-libs-1.5.3-... 592.7 KiB 959K/s 00:01 &#91;#####################&#93; 100%

> > openssl-1.0.2.h-1-x... 1354.4 KiB 972K/s 00:01 &#91;#####################&#93; 100%

> > gzip-1.7-1-x86_64 97.0 KiB 4.51M/s 00:00 &#91;#####################&#93; 100%

> > libssh2-1.7.0-1-x86_64 170.7 KiB 563K/s 00:00 &#91;#####################&#93; 100%

> > libexpat-2.1.1-1-x86_64 56.9 KiB 5.05M/s 00:00 &#91;#####################&#93; 100%

> > libcurl-7.49.1-1-x86_64 191.1 KiB 1172K/s 00:00 &#91;#####################&#93; 100%

> > curl-7.49.1-1-x86_64 608.4 KiB 966K/s 00:01 &#91;#####################&#93; 100%

> > file-5.25-1-x86_64 396.5 KiB 847K/s 00:00 &#91;#####################&#93; 100%

> > gnupg-1.4.20-1-x86_64 1026.9 KiB 945K/s 00:01 &#91;#####################&#93; 100%

> > grep-2.22-3-x86_64 230.3 KiB 752K/s 00:00 &#91;#####################&#93; 100%

> > libarchive-3.2.0-1-... 743.4 KiB 934K/s 00:01 &#91;#####################&#93; 100%

> > mpfr-3.1.4-1-x86_64 238.5 KiB 738K/s 00:00 &#91;#####################&#93; 100%

> > msys2-launcher-git-... 28.5 KiB 4.64M/s 00:00 &#91;#####################&#93; 100%

> > rebase-4.4.2-1-x86_64 236.4 KiB 773K/s 00:00 &#91;#####################&#93; 100%

> > libgpg-error-1.23-1... 108.9 KiB 4.62M/s 00:00 &#91;#####################&#93; 100%

> > libassuan-2.4.2-1-x... 91.7 KiB 4.97M/s 00:00 &#91;#####################&#93; 100%

> > libgpgme-1.6.0-1-x86_64 175.7 KiB 1072K/s 00:00 &#91;#####################&#93; 100%

> > wget-1.17.1-3-x86_64 570.7 KiB 903K/s 00:01 &#91;#####################&#93; 100%

> > xz-5.2.2-1-x86_64 142.5 KiB 891K/s 00:00 &#91;#####################&#93; 100%

> > pactoys-git-r2.07ca... 33.1 KiB 5.39M/s 00:00 &#91;#####################&#93; 100%

> > (36/36) checking keys in keyring &#91;#####################&#93; 100%

> > (36/36) checking package integrity &#91;#####################&#93; 100%

> > (36/36) loading package files &#91;#####################&#93; 100%

> > (36/36) checking for file conflicts &#91;#####################&#93; 100%

> > (37/37) checking available disk space &#91;#####################&#93; 100%

> > warning: could not get file information for mingw32.exe

> > warning: could not get file information for mingw32.ini

> > warning: could not get file information for mingw64.exe

> > warning: could not get file information for mingw64.ini

> > warning: could not get file information for msys2.exe

> > warning: could not get file information for msys2.ini

> > warning: could not get file information for autorebasebase1st.bat

> > :: Processing package changes...

> > (1/1) removing repman-git &#91;#####################&#93; 100%

> > ( 1/36) upgrading bash-completion &#91;#####################&#93; 100%

> > ( 2/36) upgrading gcc-libs &#91;#####################&#93; 100%

> > ( 3/36) upgrading libintl &#91;#####################&#93; 100%

> > ( 4/36) upgrading libgettextpo &#91;#####################&#93; 100%

> > ( 5/36) upgrading libasprintf &#91;#####################&#93; 100%

> > ( 6/36) upgrading gettext &#91;#####################&#93; 100%

> > ( 7/36) upgrading liblzma &#91;#####################&#93; 100%

> > ( 8/36) upgrading gmp &#91;#####################&#93; 100%

> > ( 9/36) upgrading libnettle &#91;#####################&#93; 100%

> > (10/36) upgrading coreutils &#91;#####################&#93; 100%

> > (11/36) upgrading ncurses &#91;#####################&#93; 100%

> > (12/36) upgrading bsdcpio &#91;#####################&#93; 100%

> > (13/36) upgrading bsdtar &#91;#####################&#93; 100%

> > (14/36) upgrading libcrypt &#91;#####################&#93; 100%

> > (15/36) upgrading crypt &#91;#####################&#93; 100%

> > (16/36) upgrading libopenssl &#91;#####################&#93; 100%

> > (17/36) upgrading heimdal-libs &#91;#####################&#93; 100%

> > (18/36) upgrading openssl &#91;#####################&#93; 100%

> > (19/36) upgrading gzip &#91;#####################&#93; 100%

> > (20/36) upgrading libssh2 &#91;#####################&#93; 100%

> > (21/36) upgrading libexpat &#91;#####################&#93; 100%

> > (22/36) upgrading libcurl &#91;#####################&#93; 100%

> > (23/36) upgrading curl &#91;#####################&#93; 100%

> > (24/36) upgrading file &#91;#####################&#93; 100%

> > (25/36) upgrading gnupg &#91;#####################&#93; 100%

> > gpg: /etc/pacman.d/gnupg/trustdb.gpg: trustdb created

> > gpg: no ultimately trusted keys found

> > gpg: Generating pacman keyring master key...

> > gpg: skipping control \`%no-protection' ()

> > .+++++

> > ......+++++

> > gpg: key 8C1A69EA marked as ultimately trusted

> > gpg: Done

> > ==&gt; Updating trust database...

> > gpg: 3 marginal(s) needed, 1 complete(s) needed, PGP trust model

> > gpg: depth: 0 valid: 1 signed: 0 trust: 0-, 0q, 0n, 0m, 0f, 1u

> > ==&gt; Appending keys from msys2.gpg...

> > gpg: 3 marginal(s) needed, 1 complete(s) needed, PGP trust model

> > gpg: depth: 0 valid: 1 signed: 0 trust: 0-, 0q, 0n, 0m, 0f, 1u

> > ==&gt; Locally signing trusted keys in keyring...

> > -&gt; Locally signing key D55E7A6D7CE9BA1587C0ACACF40D263ECA25678A...

> > -&gt; Locally signing key 123D4D51A1793859C2BE916BBBE514E53E0D0813...

> > -&gt; Locally signing key B91BCF3303284BF90CC043CA9F418C233E652008...

> > -&gt; Locally signing key 9DD0D4217D75A33B896159E6DA7EF2ABAEEA755C...

> > ==&gt; Importing owner trust values...

> > gpg: setting ownertrust to 4

> > gpg: setting ownertrust to 4

> > gpg: setting ownertrust to 4

> > gpg: inserting ownertrust of 4

> > ==&gt; Updating trust database...

> > gpg: 3 marginal(s) needed, 1 complete(s) needed, PGP trust model

> > gpg: depth: 0 valid: 1 signed: 4 trust: 0-, 0q, 0n, 0m, 0f, 1u

> > gpg: depth: 1 valid: 4 signed: 3 trust: 0-, 0q, 0n, 4m, 0f, 0u

> > gpg: depth: 2 valid: 3 signed: 0 trust: 3-, 0q, 0n, 0m, 0f, 0u

> > (26/36) upgrading grep &#91;#####################&#93; 100%

> > (27/36) upgrading libarchive &#91;#####################&#93; 100%

> > (28/36) upgrading mpfr &#91;#####################&#93; 100%

> > (29/36) upgrading msys2-launcher-git &#91;#####################&#93; 100%

> > (30/36) upgrading rebase &#91;#####################&#93; 100%

> > (31/36) installing libgpg-error &#91;#####################&#93; 100%

> > (32/36) installing libassuan &#91;#####################&#93; 100%

> > (33/36) installing libgpgme &#91;#####################&#93; 100%

> > (34/36) installing wget &#91;#####################&#93; 100%

> > Optional dependencies for wget

> > ca-certificates: HTTPS downloads &#91;installed&#93;

> > (35/36) upgrading xz &#91;#####################&#93; 100%

> > (36/36) installing pactoys-git &#91;#####################&#93; 100%

> > kjell-olovhogdahl@KJELL-OLOVHA74E MSYS ~

==&gt; And that seems to be it?

==&gt; Installing what seems to be the tool-chain using paceman in MSYS2 seems to be a mouthful but works ok?

> kjell-olovhogdahl@KJELL-OLOVHA74E MSYS ~  
> $ **pacman -S git mingw-w64-x86_64-cmake make mingw-w64-x86_64-toolchain mingw-w64-x86_64-clang mingw-w64-x86_64-gtkmm3 mingw-w64-x86_64-gtksourceviewmm3 mingw-w64-x86_64-boost mingw-w64-x86_64-aspell mingw-w64-x86_64-aspell-en mingw-w64-x86_64-libgit2 mingw-w64-x86_64-universal-ctags-git**  
> :: There are 16 members in group mingw-w64-x86_64-toolchain:  
> :: Repository mingw64  
> 1) mingw-w64-x86_64-binutils 2) mingw-w64-x86_64-crt-git 3) mingw-w64-x86_64-gcc  
> 4) mingw-w64-x86_64-gcc-ada 5) mingw-w64-x86_64-gcc-fortran 6) mingw-w64-x86_64-gcc-libgfortran  
> 7) mingw-w64-x86_64-gcc-libs 8) mingw-w64-x86_64-gcc-objc 9) mingw-w64-x86_64-gdb  
> 10) mingw-w64-x86_64-headers-git 11) mingw-w64-x86_64-libmangle-git  
> 12) mingw-w64-x86_64-libwinpthread-git 13) mingw-w64-x86_64-make 14) mingw-w64-x86_64-pkg-config  
> 15) mingw-w64-x86_64-tools-git 16) mingw-w64-x86_64-winpthreads-git

> Enter a selection (default=all):  
> resolving dependencies...  
> looking for conflicting packages...  
> warning: dependency cycle detected:  
> warning: mingw-w64-x86_64-gcc-libgfortran will be installed before its mingw-w64-x86_64-gcc-libs dependency  
> warning: dependency cycle detected:  
> warning: mingw-w64-x86_64-harfbuzz will be installed before its mingw-w64-x86_64-cairo dependency  
> warning: dependency cycle detected:  
> warning: mingw-w64-x86_64-harfbuzz will be installed before its mingw-w64-x86_64-freetype dependency

> Packages (133) db-5.3.28-2 expat-2.1.1-1 gdbm-1.11-3 heimdal-1.5.3-9 libgdbm-1.11-3  
> mingw-w64-x86_64-adwaita-icon-theme-3.20-1 mingw-w64-x86_64-atk-2.20.0-1  
> mingw-w64-x86_64-atkmm-2.24.2-1 mingw-w64-x86_64-bzip2-1.0.6-5  
> mingw-w64-x86_64-c-ares-1.11.0-1 mingw-w64-x86_64-ca-certificates-20150426-2  
> mingw-w64-x86_64-cairo-1.15.2-2 mingw-w64-x86_64-cairomm-1.12.0-1  
> mingw-w64-x86_64-curl-7.49.1-1 mingw-w64-x86_64-expat-2.1.1-1  
> mingw-w64-x86_64-fontconfig-2.12.0-1 mingw-w64-x86_64-freetype-2.6.5-1  
> mingw-w64-x86_64-gdbm-1.12-1 mingw-w64-x86_64-gdk-pixbuf2-2.35.1-1  
> mingw-w64-x86_64-gettext-0.19.7-1 mingw-w64-x86_64-glib2-2.48.1-1  
> mingw-w64-x86_64-glibmm-2.48.1-1 mingw-w64-x86_64-gmp-6.1.0-1  
> mingw-w64-x86_64-gnome-common-3.18.0-1 mingw-w64-x86_64-gnutls-3.5.2-1  
> mingw-w64-x86_64-graphite2-1.3.8-4 mingw-w64-x86_64-gtk3-3.20.6-1  
> mingw-w64-x86_64-gtksourceview3-3.20.3-1 mingw-w64-x86_64-harfbuzz-1.2.7-2  
> mingw-w64-x86_64-hicolor-icon-theme-0.15-2 mingw-w64-x86_64-http-parser-2.5.0-1  
> mingw-w64-x86_64-icu-57.1-1 mingw-w64-x86_64-isl-0.16.1-1 mingw-w64-x86_64-jansson-2.7-2  
> mingw-w64-x86_64-jasper-1.900.1-4 mingw-w64-x86_64-json-glib-1.2.0-1  
> mingw-w64-x86_64-jsoncpp-1.7.2-2 mingw-w64-x86_64-libarchive-3.2.0-1  
> mingw-w64-x86_64-libcroco-0.6.11-1 mingw-w64-x86_64-libepoxy-1.3.1-1  
> mingw-w64-x86_64-libffi-3.2.1-3 mingw-w64-x86_64-libiconv-1.14-5  
> mingw-w64-x86_64-libidn-1.32-3 mingw-w64-x86_64-libjpeg-turbo-1.4.2-2  
> mingw-w64-x86_64-libmetalink-0.1.3-1 mingw-w64-x86_64-libpng-1.6.21-1  
> mingw-w64-x86_64-librsvg-2.40.16-1 mingw-w64-x86_64-libsigc++-2.8.0-1  
> mingw-w64-x86_64-libssh2-1.7.0-1 mingw-w64-x86_64-libsystre-1.0.1-2  
> mingw-w64-x86_64-libtasn1-4.8-1 mingw-w64-x86_64-libtiff-4.0.6-1  
> mingw-w64-x86_64-libtre-git-r122.c2f5d13-4 mingw-w64-x86_64-libxml2-2.9.4-1  
> mingw-w64-x86_64-llvm-3.8.0-3 mingw-w64-x86_64-lzo2-2.09-2 mingw-w64-x86_64-mpc-1.0.3-2  
> mingw-w64-x86_64-mpfr-3.1.4-3 mingw-w64-x86_64-ncurses-6.0.20160220-2  
> mingw-w64-x86_64-nettle-3.2-1 mingw-w64-x86_64-nghttp2-1.12.0-1  
> mingw-w64-x86_64-openssl-1.0.2.h-1 mingw-w64-x86_64-p11-kit-0.23.2-2  
> mingw-w64-x86_64-pango-1.40.1-1 mingw-w64-x86_64-pangomm-2.40.0-1  
> mingw-w64-x86_64-pcre-8.38-1 mingw-w64-x86_64-pixman-0.34.0-2  
> mingw-w64-x86_64-python2-2.7.11-4 mingw-w64-x86_64-readline-6.3.008-1  
> mingw-w64-x86_64-rtmpdump-git-r512.fa8646d-1 mingw-w64-x86_64-shared-mime-info-1.4-2  
> mingw-w64-x86_64-tcl-8.6.5-1 mingw-w64-x86_64-termcap-1.3.1-2 mingw-w64-x86_64-tk-8.6.5-1  
> mingw-w64-x86_64-windows-default-manifest-6.4-2 mingw-w64-x86_64-wineditline-2.101-4  
> mingw-w64-x86_64-xz-5.2.2-1 mingw-w64-x86_64-zlib-1.2.8-9 openssh-7.1p2-1 perl-5.22.1-1  
> perl-Authen-SASL-2.16-2 perl-Convert-BinHex-1.123-2 perl-Encode-Locale-1.04-1  
> perl-Error-0.17024-1 perl-File-Listing-6.04-2 perl-HTML-Parser-3.71-3  
> perl-HTML-Tagset-3.20-2 perl-HTTP-Cookies-6.01-2 perl-HTTP-Daemon-6.01-2  
> perl-HTTP-Date-6.02-2 perl-HTTP-Message-6.06-2 perl-HTTP-Negotiate-6.01-2  
> perl-IO-Socket-SSL-2.016-1 perl-IO-stringy-2.111-1 perl-LWP-MediaTypes-6.02-2  
> perl-MIME-tools-5.506-1 perl-MailTools-2.14-1 perl-Net-HTTP-6.09-1 perl-Net-SMTP-SSL-1.02-1  
> perl-Net-SSLeay-1.72-1 perl-TermReadKey-2.33-1 perl-TimeDate-2.30-2 perl-URI-1.68-1  
> perl-WWW-RobotRules-6.02-2 perl-libwww-6.13-1 vim-7.4.1721-1 git-2.9.1-1 make-4.2.1-1  
> mingw-w64-x86_64-aspell-0.60.7.20131207-2 mingw-w64-x86_64-aspell-en-7.1-1  
> mingw-w64-x86_64-binutils-2.25.1-5 mingw-w64-x86_64-boost-1.60.0-3  
> mingw-w64-x86_64-clang-3.8.0-3 mingw-w64-x86_64-cmake-3.6.0-1  
> mingw-w64-x86_64-crt-git-5.0.0.4680.362c947-1 mingw-w64-x86_64-gcc-5.4.0-1  
> mingw-w64-x86_64-gcc-ada-5.4.0-1 mingw-w64-x86_64-gcc-fortran-5.4.0-1  
> mingw-w64-x86_64-gcc-libgfortran-5.4.0-1 mingw-w64-x86_64-gcc-libs-5.4.0-1  
> mingw-w64-x86_64-gcc-objc-5.4.0-1 mingw-w64-x86_64-gdb-7.11.1-2  
> mingw-w64-x86_64-gtkmm3-3.20.0-1 mingw-w64-x86_64-gtksourceviewmm3-3.18.0-1  
> mingw-w64-x86_64-headers-git-5.0.0.4680.362c947-1 mingw-w64-x86_64-libgit2-0.24.0-1  
> mingw-w64-x86_64-libmangle-git-5.0.0.4669.7de6266-1  
> mingw-w64-x86_64-libwinpthread-git-5.0.0.4670.00cda6f-1  
> mingw-w64-x86_64-make-4.1.2351.a80a8b8-1 mingw-w64-x86_64-pkg-config-0.29.1-1  
> mingw-w64-x86_64-tools-git-5.0.0.4669.7de6266-1  
> mingw-w64-x86_64-universal-ctags-git-r2635.80256f4-1  
> mingw-w64-x86_64-winpthreads-git-5.0.0.4670.00cda6f-1

> Total Download Size: 352.94 MiB  
> Total Installed Size: 2019.48 MiB

> :: Proceed with installation? &#91;Y/n&#93; Y  
> :: Retrieving packages...  
> mingw-w64-x86_64-gmp-6.1.0-1-any 477.1 KiB 766K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libwinpthread-git-... 34.5 KiB 4.81M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gcc-libgfortran-5.... 275.7 KiB 889K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gcc-libs-5.4.0-1-any 540.6 KiB 1131K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-c-ares-1.11.0-1-any 124.1 KiB 130K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-expat-2.1.1-1-any 117.1 KiB 187K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libiconv-1.14-5-any 600.2 KiB 1258K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gettext-0.19.7-1-any 3.0 MiB 1605K/s 00:02 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libidn-1.32-3-any 224.9 KiB 664K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libmetalink-0.1.3-... 59.4 KiB 5.27M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libtasn1-4.8-1-any 181.3 KiB 538K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libffi-3.2.1-3-any 34.5 KiB 4.82M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-p11-kit-0.23.2-2-any 204.3 KiB 674K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-ca-certificates-20... 382.1 KiB 1151K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-bzip2-1.0.6-5-any 77.9 KiB 5.44M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-zlib-1.2.8-9-any 148.6 KiB 965K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-openssl-1.0.2.h-1-any 3.4 MiB 1156K/s 00:03 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libssh2-1.7.0-1-any 223.7 KiB 170K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libtre-git-r122.c2... 69.2 KiB 112K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libsystre-1.0.1-2-any 9.3 KiB 4.56M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-nettle-3.2-1-any 404.5 KiB 301K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gnutls-3.5.2-1-any 1661.6 KiB 890K/s 00:02 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-rtmpdump-git-r512.... 156.6 KiB 168K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-jansson-2.7-2-any 53.6 KiB 86.6K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-nghttp2-1.12.0-1-any 162.1 KiB 858K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-curl-7.49.1-1-any 923.4 KiB 1169K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-jsoncpp-1.7.2-2-any 101.0 KiB 4.70M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-lzo2-2.09-2-any 85.9 KiB 4.94M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-xz-5.2.2-1-any 290.5 KiB 952K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libarchive-3.2.0-1-any 625.6 KiB 992K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-cmake-3.6.0-1-any 4.0 MiB 1194K/s 00:03 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-binutils-2.25.1-5-any 11.9 MiB 2.31M/s 00:05 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-headers-git-5.0.0.... 5.0 MiB 2.11M/s 00:02 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-crt-git-5.0.0.4680... 2.7 MiB 1801K/s 00:02 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-isl-0.16.1-1-any 534.5 KiB 1536K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-mpfr-3.1.4-3-any 276.3 KiB 909K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-mpc-1.0.3-2-any 62.3 KiB 4.68M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-windows-default-ma... 1484.0 B 0.00B/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-winpthreads-git-5.... 43.6 KiB 5.32M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gcc-5.4.0-1-any 25.2 MiB 2.54M/s 00:10 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gcc-ada-5.4.0-1-any 16.6 MiB 2.67M/s 00:06 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gcc-fortran-5.4.0-... 7.7 MiB 2.46M/s 00:03 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gcc-objc-5.4.0-1-any 12.4 MiB 2.55M/s 00:05 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gdbm-1.12-1-any 164.1 KiB 167K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-ncurses-6.0.201602... 1800.5 KiB 1052K/s 00:02 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-termcap-1.3.1-2-any 12.6 KiB 12.3M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-readline-6.3.008-1-any 327.4 KiB 938K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-tcl-8.6.5-1-any 2.9 MiB 1754K/s 00:02 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-tk-8.6.5-1-any 1869.2 KiB 1734K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-python2-2.7.11-4-any 10.9 MiB 2.16M/s 00:05 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gdb-7.11.1-2-any 2.8 MiB 2046K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libmangle-git-5.0.... 26.7 KiB 6.51M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-make-4.1.2351.a80a... 103.2 KiB 4.80M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-pkg-config-0.29.1-... 237.1 KiB 175K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-tools-git-5.0.0.46... 257.4 KiB 333K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-llvm-3.8.0-3-any 69.7 MiB 2.83M/s 00:25 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-clang-3.8.0-3-any 62.1 MiB 2.84M/s 00:22 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gnome-common-3.18.... 10.2 KiB 9.96M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-wineditline-2.101-... 32.7 KiB 4.57M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-pcre-8.38-1-any 859.1 KiB 1597K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-glib2-2.48.1-1-any 2.8 MiB 1728K/s 00:02 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-atk-2.20.0-1-any 311.0 KiB 252K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libsigc++-2.8.0-1-any 88.8 KiB 143K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-glibmm-2.48.1-1-any 1267.2 KiB 1360K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-atkmm-2.24.2-1-any 163.3 KiB 486K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-graphite2-1.3.8-4-any 165.0 KiB 126K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-harfbuzz-1.2.7-2-any 345.9 KiB 445K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libpng-1.6.21-1-any 279.1 KiB 883K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-freetype-2.6.5-1-any 498.5 KiB 1052K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-fontconfig-2.12.0-... 220.6 KiB 718K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-pixman-0.34.0-2-any 287.7 KiB 934K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-cairo-1.15.2-2-any 755.3 KiB 952K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-cairomm-1.12.0-1-any 117.5 KiB 4.41M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-pango-1.40.1-1-any 380.5 KiB 1112K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-pangomm-2.40.0-1-any 133.2 KiB 849K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-hicolor-icon-theme... 15.4 KiB 3.75M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libjpeg-turbo-1.4.... 370.1 KiB 1101K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-jasper-1.900.1-4-any 225.9 KiB 1298K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libtiff-4.0.6-1-any 906.1 KiB 957K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gdk-pixbuf2-2.35.1... 671.8 KiB 1045K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libxml2-2.9.4-1-any 1416.9 KiB 915K/s 00:02 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libcroco-0.6.11-1-any 159.4 KiB 133K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-librsvg-2.40.16-1-any 186.9 KiB 241K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-adwaita-icon-theme... 11.7 MiB 1847K/s 00:06 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-json-glib-1.2.0-1-any 156.6 KiB 81.2K/s 00:02 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libepoxy-1.3.1-1-any 415.7 KiB 482K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-shared-mime-info-1... 428.5 KiB 1291K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gtk3-3.20.6-1-any 9.7 MiB 1962K/s 00:05 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gtkmm3-3.20.0-1-any 2.2 MiB 2042K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gtksourceview3-3.2... 848.3 KiB 1693K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-gtksourceviewmm3-3... 178.6 KiB 527K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-icu-57.1-1-any 15.8 MiB 2.32M/s 00:07 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-boost-1.60.0-3-any 17.5 MiB 2.51M/s 00:07 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-aspell-0.60.7.2013... 751.1 KiB 1399K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-aspell-en-7.1-1-any 1007.5 KiB 1520K/s 00:01 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-http-parser-2.5.0-... 28.0 KiB 5.47M/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-libgit2-0.24.0-1-any 535.2 KiB 1503K/s 00:00 &#91;###################################&#93; 100%  
> mingw-w64-x86_64-universal-ctags-gi... 228.6 KiB 750K/s 00:00 &#91;###################################&#93; 100%  
> expat-2.1.1-1-x86_64 22.7 KiB 4.44M/s 00:00 &#91;###################################&#93; 100%  
> vim-7.4.1721-1-x86_64 6.2 MiB 1593K/s 00:04 &#91;###################################&#93; 100%  
> heimdal-1.5.3-9-x86_64 546.6 KiB 811K/s 00:01 &#91;###################################&#93; 100%  
> openssh-7.1p2-1-x86_64 653.4 KiB 1057K/s 00:01 &#91;###################################&#93; 100%  
> db-5.3.28-2-x86_64 41.7 KiB 5.81M/s 00:00 &#91;###################################&#93; 100%  
> libgdbm-1.11-3-x86_64 20.4 KiB 130K/s 00:00 &#91;###################################&#93; 100%  
> gdbm-1.11-3-x86_64 108.5 KiB 4.41M/s 00:00 &#91;###################################&#93; 100%  
> perl-5.22.1-1-x86_64 12.4 MiB 2.15M/s 00:06 &#91;###################################&#93; 100%  
> perl-Error-0.17024-1-any 17.1 KiB 4.16M/s 00:00 &#91;###################################&#93; 100%  
> perl-Authen-SASL-2.16-2-any 42.4 KiB 4.14M/s 00:00 &#91;###################################&#93; 100%  
> perl-Encode-Locale-1.04-1-any 9.7 KiB 9.46M/s 00:00 &#91;###################################&#93; 100%  
> perl-HTTP-Date-6.02-2-any 8.6 KiB 4.21M/s 00:00 &#91;###################################&#93; 100%  
> perl-File-Listing-6.04-2-any 7.7 KiB 7.51M/s 00:00 &#91;###################################&#93; 100%  
> perl-HTML-Tagset-3.20-2-any 10.3 KiB 5.01M/s 00:00 &#91;###################################&#93; 100%  
> perl-HTML-Parser-3.71-3-x86_64 76.9 KiB 5.01M/s 00:00 &#91;###################################&#93; 100%  
> perl-LWP-MediaTypes-6.02-2-any 18.0 KiB 4.40M/s 00:00 &#91;###################################&#93; 100%  
> perl-URI-1.68-1-any 75.6 KiB 5.27M/s 00:00 &#91;###################################&#93; 100%  
> perl-HTTP-Message-6.06-2-any 71.3 KiB 4.97M/s 00:00 &#91;###################################&#93; 100%  
> perl-HTTP-Cookies-6.01-2-any 20.4 KiB 4.99M/s 00:00 &#91;###################################&#93; 100%  
> perl-HTTP-Daemon-6.01-2-any 14.2 KiB 3.48M/s 00:00 &#91;###################################&#93; 100%  
> perl-HTTP-Negotiate-6.01-2-any 11.4 KiB 11.2M/s 00:00 &#91;###################################&#93; 100%  
> perl-Net-HTTP-6.09-1-any 19.8 KiB 4.83M/s 00:00 &#91;###################################&#93; 100%  
> perl-WWW-RobotRules-6.02-2-any 12.2 KiB 3.99M/s 00:00 &#91;###################################&#93; 100%  
> perl-libwww-6.13-1-any 122.2 KiB 374K/s 00:00 &#91;###################################&#93; 100%  
> perl-TimeDate-2.30-2-any 35.9 KiB 5.85M/s 00:00 &#91;###################################&#93; 100%  
> perl-MailTools-2.14-1-any 58.4 KiB 5.18M/s 00:00 &#91;###################################&#93; 100%  
> perl-IO-stringy-2.111-1-any 52.6 KiB 5.14M/s 00:00 &#91;###################################&#93; 100%  
> perl-Convert-BinHex-1.123-2-any 30.1 KiB 5.87M/s 00:00 &#91;###################################&#93; 100%  
> perl-MIME-tools-5.506-1-any 180.4 KiB 128K/s 00:01 &#91;###################################&#93; 100%  
> perl-Net-SSLeay-1.72-1-x86_64 199.9 KiB 321K/s 00:01 &#91;###################################&#93; 100%  
> perl-IO-Socket-SSL-2.016-1-any 112.5 KiB 4.39M/s 00:00 &#91;###################################&#93; 100%  
> perl-Net-SMTP-SSL-1.02-1-any 3.5 KiB 3.44M/s 00:00 &#91;###################################&#93; 100%  
> perl-TermReadKey-2.33-1-x86_64 20.9 KiB 2.91M/s 00:00 &#91;###################################&#93; 100%  
> git-2.9.1-1-x86_64 3.8 MiB 1803K/s 00:02 &#91;###################################&#93; 100%  
> make-4.2.1-1-x86_64 414.8 KiB 1284K/s 00:00 &#91;###################################&#93; 100%  
> (133/133) checking keys in keyring &#91;###################################&#93; 100%  
> (133/133) checking package integrity &#91;###################################&#93; 100%  
> (133/133) loading package files &#91;###################################&#93; 100%  
> (133/133) checking for file conflicts &#91;###################################&#93; 100%  
> (133/133) checking available disk space &#91;###################################&#93; 100%  
> :: Processing package changes...  
> ( 1/133) installing expat &#91;###################################&#93; 100%  
> ( 2/133) installing vim &#91;###################################&#93; 100%  
> ( 3/133) installing heimdal &#91;###################################&#93; 100%  
> ( 4/133) installing openssh &#91;###################################&#93; 100%  
> ( 5/133) installing db &#91;###################################&#93; 100%  
> ( 6/133) installing libgdbm &#91;###################################&#93; 100%  
> ( 7/133) installing gdbm &#91;###################################&#93; 100%  
> ( 8/133) installing perl &#91;###################################&#93; 100%  
> ( 9/133) installing perl-Error &#91;###################################&#93; 100%  
> ( 10/133) installing perl-Authen-SASL &#91;###################################&#93; 100%  
> ( 11/133) installing perl-Encode-Locale &#91;###################################&#93; 100%  
> ( 12/133) installing perl-HTTP-Date &#91;###################################&#93; 100%  
> ( 13/133) installing perl-File-Listing &#91;###################################&#93; 100%  
> ( 14/133) installing perl-HTML-Tagset &#91;###################################&#93; 100%  
> ( 15/133) installing perl-HTML-Parser &#91;###################################&#93; 100%  
> ( 16/133) installing perl-LWP-MediaTypes &#91;###################################&#93; 100%  
> ( 17/133) installing perl-URI &#91;###################################&#93; 100%  
> ( 18/133) installing perl-HTTP-Message &#91;###################################&#93; 100%  
> ( 19/133) installing perl-HTTP-Cookies &#91;###################################&#93; 100%  
> ( 20/133) installing perl-HTTP-Daemon &#91;###################################&#93; 100%  
> ( 21/133) installing perl-HTTP-Negotiate &#91;###################################&#93; 100%  
> ( 22/133) installing perl-Net-HTTP &#91;###################################&#93; 100%  
> ( 23/133) installing perl-WWW-RobotRules &#91;###################################&#93; 100%  
> ( 24/133) installing perl-libwww &#91;###################################&#93; 100%  
> Optional dependencies for perl-libwww  
> perl-LWP-Protocol-HTTPS: for https:// url schemes  
> ( 25/133) installing perl-TimeDate &#91;###################################&#93; 100%  
> ( 26/133) installing perl-MailTools &#91;###################################&#93; 100%  
> ( 27/133) installing perl-IO-stringy &#91;###################################&#93; 100%  
> ( 28/133) installing perl-Convert-BinHex &#91;###################################&#93; 100%  
> module test... pass.  
> ( 29/133) installing perl-MIME-tools &#91;###################################&#93; 100%  
> ( 30/133) installing perl-Net-SSLeay &#91;###################################&#93; 100%  
> ( 31/133) installing perl-IO-Socket-SSL &#91;###################################&#93; 100%  
> ( 32/133) installing perl-Net-SMTP-SSL &#91;###################################&#93; 100%  
> ( 33/133) installing perl-TermReadKey &#91;###################################&#93; 100%  
> ( 34/133) installing git &#91;###################################&#93; 100%  
> Optional dependencies for git  
> python2: various helper scripts  
> subversion: git svn  
> ( 35/133) installing mingw-w64-x86_64-gmp &#91;###################################&#93; 100%  
> ( 36/133) installing mingw-w64-x86_64-libwinpthread-git &#91;###################################&#93; 100%  
> ( 37/133) installing mingw-w64-x86_64-gcc-libgfortran &#91;###################################&#93; 100%  
> ( 38/133) installing mingw-w64-x86_64-gcc-libs &#91;###################################&#93; 100%  
> ( 39/133) installing mingw-w64-x86_64-c-ares &#91;###################################&#93; 100%  
> ( 40/133) installing mingw-w64-x86_64-expat &#91;###################################&#93; 100%  
> ( 41/133) installing mingw-w64-x86_64-libiconv &#91;###################################&#93; 100%  
> ( 42/133) installing mingw-w64-x86_64-gettext &#91;###################################&#93; 100%  
> ( 43/133) installing mingw-w64-x86_64-libidn &#91;###################################&#93; 100%  
> ( 44/133) installing mingw-w64-x86_64-libmetalink &#91;###################################&#93; 100%  
> ( 45/133) installing mingw-w64-x86_64-libtasn1 &#91;###################################&#93; 100%  
> ( 46/133) installing mingw-w64-x86_64-libffi &#91;###################################&#93; 100%  
> ( 47/133) installing mingw-w64-x86_64-p11-kit &#91;###################################&#93; 100%  
> ( 48/133) installing mingw-w64-x86_64-ca-certificates &#91;###################################&#93; 100%  
> ( 49/133) installing mingw-w64-x86_64-bzip2 &#91;###################################&#93; 100%  
> ( 50/133) installing mingw-w64-x86_64-zlib &#91;###################################&#93; 100%  
> ( 51/133) installing mingw-w64-x86_64-openssl &#91;###################################&#93; 100%  
> ( 52/133) installing mingw-w64-x86_64-libssh2 &#91;###################################&#93; 100%  
> ( 53/133) installing mingw-w64-x86_64-libtre-git &#91;###################################&#93; 100%  
> ( 54/133) installing mingw-w64-x86_64-libsystre &#91;###################################&#93; 100%  
> ( 55/133) installing mingw-w64-x86_64-nettle &#91;###################################&#93; 100%  
> ( 56/133) installing mingw-w64-x86_64-gnutls &#91;###################################&#93; 100%  
> ( 57/133) installing mingw-w64-x86_64-rtmpdump-git &#91;###################################&#93; 100%  
> ( 58/133) installing mingw-w64-x86_64-jansson &#91;###################################&#93; 100%  
> ( 59/133) installing mingw-w64-x86_64-nghttp2 &#91;###################################&#93; 100%  
> ( 60/133) installing mingw-w64-x86_64-curl &#91;###################################&#93; 100%  
> ( 61/133) installing mingw-w64-x86_64-jsoncpp &#91;###################################&#93; 100%  
> ( 62/133) installing mingw-w64-x86_64-lzo2 &#91;###################################&#93; 100%  
> ( 63/133) installing mingw-w64-x86_64-xz &#91;###################################&#93; 100%  
> ( 64/133) installing mingw-w64-x86_64-libarchive &#91;###################################&#93; 100%  
> ( 65/133) installing mingw-w64-x86_64-cmake &#91;###################################&#93; 100%  
> Optional dependencies for mingw-w64-x86_64-cmake  
> mingw-w64-x86_64-qt5: CMake Qt GUI  
> ( 66/133) installing make &#91;###################################&#93; 100%  
> ( 67/133) installing mingw-w64-x86_64-binutils &#91;###################################&#93; 100%  
> ( 68/133) installing mingw-w64-x86_64-headers-git &#91;###################################&#93; 100%  
> ( 69/133) installing mingw-w64-x86_64-crt-git &#91;###################################&#93; 100%  
> ( 70/133) installing mingw-w64-x86_64-isl &#91;###################################&#93; 100%  
> ( 71/133) installing mingw-w64-x86_64-mpfr &#91;###################################&#93; 100%  
> ( 72/133) installing mingw-w64-x86_64-mpc &#91;###################################&#93; 100%  
> ( 73/133) installing mingw-w64-x86_64-windows-default-manifest &#91;###################################&#93; 100%  
> ( 74/133) installing mingw-w64-x86_64-winpthreads-git &#91;###################################&#93; 100%  
> ( 75/133) installing mingw-w64-x86_64-gcc &#91;###################################&#93; 100%  
> ( 76/133) installing mingw-w64-x86_64-gcc-ada &#91;###################################&#93; 100%  
> ( 77/133) installing mingw-w64-x86_64-gcc-fortran &#91;###################################&#93; 100%  
> ( 78/133) installing mingw-w64-x86_64-gcc-objc &#91;###################################&#93; 100%  
> ( 79/133) installing mingw-w64-x86_64-gdbm &#91;###################################&#93; 100%  
> ( 80/133) installing mingw-w64-x86_64-ncurses &#91;###################################&#93; 100%  
> ( 81/133) installing mingw-w64-x86_64-termcap &#91;###################################&#93; 100%  
> ( 82/133) installing mingw-w64-x86_64-readline &#91;###################################&#93; 100%  
> ( 83/133) installing mingw-w64-x86_64-tcl &#91;###################################&#93; 100%  
> ( 84/133) installing mingw-w64-x86_64-tk &#91;###################################&#93; 100%  
> ( 85/133) installing mingw-w64-x86_64-python2 &#91;###################################&#93; 100%  
> ( 86/133) installing mingw-w64-x86_64-gdb &#91;###################################&#93; 100%  
> ( 87/133) installing mingw-w64-x86_64-libmangle-git &#91;###################################&#93; 100%  
> ( 88/133) installing mingw-w64-x86_64-make &#91;###################################&#93; 100%  
> ( 89/133) installing mingw-w64-x86_64-pkg-config &#91;###################################&#93; 100%  
> ( 90/133) installing mingw-w64-x86_64-tools-git &#91;###################################&#93; 100%  
> ( 91/133) installing mingw-w64-x86_64-llvm &#91;###################################&#93; 100%  
> /  
> ( 92/133) installing mingw-w64-x86_64-clang &#91;###################################&#93; 100%  
> ( 93/133) installing mingw-w64-x86_64-gnome-common &#91;###################################&#93; 100%  
> ( 94/133) installing mingw-w64-x86_64-wineditline &#91;###################################&#93; 100%  
> ( 95/133) installing mingw-w64-x86_64-pcre &#91;###################################&#93; 100%  
> ( 96/133) installing mingw-w64-x86_64-glib2 &#91;###################################&#93; 100%  
> No schema files found: doing nothing.  
> ( 97/133) installing mingw-w64-x86_64-atk &#91;###################################&#93; 100%  
> ( 98/133) installing mingw-w64-x86_64-libsigc++ &#91;###################################&#93; 100%  
> ( 99/133) installing mingw-w64-x86_64-glibmm &#91;###################################&#93; 100%  
> (100/133) installing mingw-w64-x86_64-atkmm &#91;###################################&#93; 100%  
> (101/133) installing mingw-w64-x86_64-graphite2 &#91;###################################&#93; 100%  
> (102/133) installing mingw-w64-x86_64-harfbuzz &#91;###################################&#93; 100%  
> Optional dependencies for mingw-w64-x86_64-harfbuzz  
> mingw-w64-x86_64-icu: harfbuzz-icu support &#91;pending&#93;  
> (103/133) installing mingw-w64-x86_64-libpng &#91;###################################&#93; 100%  
> (104/133) installing mingw-w64-x86_64-freetype &#91;###################################&#93; 100%  
> (105/133) installing mingw-w64-x86_64-fontconfig &#91;###################################&#93; 100%

> Fontconfig configuration is done via /mingw64/etc/fonts/conf.avail and conf.d.  
> Read /mingw64/etc/fonts/conf.d/README for more information.

> updating font cache... done.  
> (106/133) installing mingw-w64-x86_64-pixman &#91;###################################&#93; 100%  
> (107/133) installing mingw-w64-x86_64-cairo &#91;###################################&#93; 100%  
> Optional dependencies for mingw-w64-x86_64-cairo  
> mingw-w64-x86_64-glib2: libcairo-gobject &#91;installed&#93;  
> (108/133) installing mingw-w64-x86_64-cairomm &#91;###################################&#93; 100%  
> (109/133) installing mingw-w64-x86_64-pango &#91;###################################&#93; 100%  
> (110/133) installing mingw-w64-x86_64-pangomm &#91;###################################&#93; 100%  
> (111/133) installing mingw-w64-x86_64-hicolor-icon-theme &#91;###################################&#93; 100%  
> (112/133) installing mingw-w64-x86_64-libjpeg-turbo &#91;###################################&#93; 100%  
> (113/133) installing mingw-w64-x86_64-jasper &#91;###################################&#93; 100%  
> (114/133) installing mingw-w64-x86_64-libtiff &#91;###################################&#93; 100%  
> (115/133) installing mingw-w64-x86_64-gdk-pixbuf2 &#91;###################################&#93; 100%  
> (116/133) installing mingw-w64-x86_64-libxml2 &#91;###################################&#93; 100%  
> Compiling /mingw64/lib/python2.7/site-packages...  
> (117/133) installing mingw-w64-x86_64-libcroco &#91;###################################&#93; 100%  
> (118/133) installing mingw-w64-x86_64-librsvg &#91;###################################&#93; 100%  
> Optional dependencies for mingw-w64-x86_64-librsvg  
> mingw-w64-x86_64-gtk3: for rsvg-view-3 &#91;pending&#93;  
> (119/133) installing mingw-w64-x86_64-adwaita-icon-theme &#91;###################################&#93; 100%  
> (120/133) installing mingw-w64-x86_64-json-glib &#91;###################################&#93; 100%  
> (121/133) installing mingw-w64-x86_64-libepoxy &#91;###################################&#93; 100%  
> (122/133) installing mingw-w64-x86_64-shared-mime-info &#91;###################################&#93; 100%  
> (123/133) installing mingw-w64-x86_64-gtk3 &#91;###################################&#93; 100%  
> (124/133) installing mingw-w64-x86_64-gtkmm3 &#91;###################################&#93; 100%  
> (125/133) installing mingw-w64-x86_64-gtksourceview3 &#91;###################################&#93; 100%  
> (126/133) installing mingw-w64-x86_64-gtksourceviewmm3 &#91;###################################&#93; 100%  
> (127/133) installing mingw-w64-x86_64-icu &#91;###################################&#93; 100%  
> (128/133) installing mingw-w64-x86_64-boost &#91;###################################&#93; 100%  
> (129/133) installing mingw-w64-x86_64-aspell &#91;###################################&#93; 100%  
> (130/133) installing mingw-w64-x86_64-aspell-en &#91;###################################&#93; 100%  
> (131/133) installing mingw-w64-x86_64-http-parser &#91;###################################&#93; 100%  
> (132/133) installing mingw-w64-x86_64-libgit2 &#91;###################################&#93; 100%  
> (133/133) installing mingw-w64-x86_64-universal-ctags-git &#91;###################################&#93; 100%

> kjell-olovhogdahl@KJELL-OLOVHA74E MSYS ~  
> $

==&gt; It seems MSYS2 is a Cygwin-like she for windows?

==&gt; The documentation seems to live in a wiki on source forge (<https://sourceforge.net/p/msys2/wiki/Home/>)?

==&gt; Cygwin FAQ seem to live here (<https://www.cygwin.com/faq.html>)?

==&gt; Cygwin seem to create a Linux folder structure at “C:\\msys64\\”?

==&gt; Note: I had to use MacOS tree command to restrict tree level (windows tree does not support -L option)

> > Kjell-Olovs-MacBook-Pro:msys64 kjell-olovhogdahl$ pwd

> > /Volumes/C/msys64

> > Kjell-Olovs-MacBook-Pro:msys64 kjell-olovhogdahl$ tree -L 1

> > .

> > ├── InstallationLog.txt

> > ├── autorebase.bat

> > ├── autorebasebase1st.bat

> > ├── components.xml

> > ├── dev

> > ├── etc

> > ├── home

> > ├── maintenancetool.dat

> > ├── maintenancetool.exe

> > ├── maintenancetool.ini

> > ├── mingw32

> > ├── mingw32.exe

> > ├── mingw32.ini

> > ├── mingw64

> > ├── mingw64.exe

> > ├── mingw64.ini

> > ├── msys2.exe

> > ├── msys2.ico

> > ├── msys2.ini

> > ├── msys2_shell.cmd

> > ├── network.xml

> > ├── opt

> > ├── tmp

> > ├── usr

> > └── var

> > 9 directories, 16 files

> > Kjell-Olovs-MacBook-Pro:msys64 kjell-olovhogdahl$

==&gt; It seems I need to switch to a MinGW shell to actually build the jucipp application?

*“Note that juCi++ must be built and run in a MinGW Shell (for instance MinGW-w64 Win64 Shell).”*

**==&gt; Easy to miss the need to switch to MinGW shell?!!**

==&gt; Note: The installed shortcut does not work!

**==&gt; Running “C:\\msys64\\mingw64.exe” seem to work?**

==&gt; It seems to operate on my “C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\” from MINGW I go to its corresponding Linux path “/c/Users/kjell-olovhogdahl/Documents/GitHub”?

==&gt; Thus - it seems to build jucipp that I have cloned to “C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\jucipp” I start of at “/c/Users/kjell-olovhogdahl/Documents/GitHub/jucipp”?

> > kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 ~

> > $ pwd

> > /home/kjell-olovhogdahl

> > kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 ~

> > $ cd /c/Users/kjell-olovhogdahl/Documents/GitHub/jucipp

> > kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 /c/Users/kjell-olovhogdahl/Documents/G itHub/jucipp

> > $ pwd

> > /c/Users/kjell-olovhogdahl/Documents/GitHub/jucipp

> > kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 /c/Users/kjell-olovhogdahl/Documents/G itHub/jucipp

> > $ mkdir build

> > kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 /c/Users/kjell-olovhogdahl/Documents/G itHub/jucipp

> > $ cd build

> > kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 /c/Users/kjell-olovhogdahl/Documents/G itHub/jucipp/build

> > $ cmake -G"MSYS Makefiles" -DCMAKE_INSTALL_PREFIX=/mingw64 ..

> > -- The C compiler identification is GNU 5.4.0

> > -- The CXX compiler identification is GNU 5.4.0

> > -- Check for working C compiler: C:/msys64/mingw64/bin/gcc.exe

> > -- Check for working C compiler: C:/msys64/mingw64/bin/gcc.exe -- works

> > -- Detecting C compiler ABI info

> > -- Detecting C compiler ABI info - done

> > -- Detecting C compile features

> > -- Detecting C compile features - done

> > -- Check for working CXX compiler: C:/msys64/mingw64/bin/g++.exe

> > -- Check for working CXX compiler: C:/msys64/mingw64/bin/g++.exe -- works

> > -- Detecting CXX compiler ABI info

> > -- Detecting CXX compiler ABI info - done

> > -- Detecting CXX compile features

> > -- Detecting CXX compile features - done

> > -- Found LibClang: C:/msys64/mingw64/lib/libclang.dll.a

> > liblldb not found. Building juCi++ without debugging support

> > -- Boost version: 1.60.0

> > -- Found the following Boost libraries:

> > -- system

> > -- filesystem

> > -- Found ASPELL: C:/msys64/mingw64/lib/libaspell.dll.a

> > -- Found PkgConfig: C:/msys64/mingw64/bin/pkg-config.exe (found version "0.29.1")

> > -- Checking for module 'gtkmm-3.0'

> > -- Found gtkmm-3.0, version 3.20.0

> > -- Checking for module 'gtksourceviewmm-3.0'

> > -- Found gtksourceviewmm-3.0, version 3.18.0

> > -- Checking for module 'libgit2'

> > -- Found libgit2, version 0.24.0

> > -- Could NOT find plantuml (missing: PLANTUML_JARFILE)

> > -- Could NOT find Doxygen (missing: DOXYGEN_EXECUTABLE)

> > -- Configuring done

> > -- Generating done

> > -- Build files have been written to: C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/build

> > kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 /c/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/build

> > $ make

> > Scanning dependencies of target project_shared

> > &#91; 2%&#93; Building CXX object src/CMakeFiles/project_shared.dir/cmake.cc.obj

> > In file included from C:/msys64/mingw64/include/c++/5.4.0/cassert:43:0,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:6,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:14,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[cmake.cc](http://cmake.cc):4:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp: In member function 'char boost::property_tree::json_parser::detail::utf8_utf8_encoding::to_internal_trivial(char) const':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:71:22: warning: comparison is always true due to limited range of data type &#91;-Wtype-limits&#93;

> > assert(c &lt;= 0x7f);

> > ^

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/cmake.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[cmake.cc](http://cmake.cc):1:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp: At global scope:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 4%&#93; Building CXX object src/CMakeFiles/project_shared.dir/ctags.cc.obj

> > In file included from C:/msys64/mingw64/include/c++/5.4.0/cassert:43:0,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:6,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:14,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[ctags.cc](http://ctags.cc):2:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp: In member function 'char boost::property_tree::json_parser::detail::utf8_utf8_encoding::to_internal_trivial(char) const':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:71:22: warning: comparison is always true due to limited range of data type &#91;-Wtype-limits&#93;

> > assert(c &lt;= 0x7f);

> > ^

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/ctags.h:4,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[ctags.cc](http://ctags.cc):1:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp: At global scope:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 7%&#93; Building CXX object src/CMakeFiles/project_shared.dir/dispatcher.cc.obj

> > &#91; 9%&#93; Building CXX object src/CMakeFiles/project_shared.dir/filesystem.cc.obj

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/filesystem.h:5,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[filesystem.cc](http://filesystem.cc):6:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 12%&#93; Building CXX object src/CMakeFiles/project_shared.dir/git.cc.obj

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/git.h:11,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[git.cc](http://git.cc):1:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 14%&#93; Building CXX object src/CMakeFiles/project_shared.dir/project_build.cc.obj

> > In file included from C:/msys64/mingw64/include/c++/5.4.0/cassert:43:0,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:6,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:14,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/project_build.cc:2:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp: In member function 'char boost::property_tree::json_parser::detail::utf8_utf8_encoding::to_internal_trivial(char) const':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:71:22: warning: comparison is always true due to limited range of data type &#91;-Wtype-limits&#93;

> > assert(c &lt;= 0x7f);

> > ^

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/project_build.h:4,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/project_build.cc:1:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp: At global scope:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 17%&#93; Building CXX object src/CMakeFiles/project_shared.dir/source.cc.obj

> > In file included from C:/msys64/mingw64/include/c++/5.4.0/cassert:43:0,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:6,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:14,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[source.cc](http://source.cc):2:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp: In member function 'char boost::property_tree::json_parser::detail::utf8_utf8_encoding::to_internal_trivial(char) const':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:71:22: warning: comparison is always true due to limited range of data type &#91;-Wtype-limits&#93;

> > assert(c &lt;= 0x7f);

> > ^

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/source_diff.h:4,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/source.h:4,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[source.cc](http://source.cc):1:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp: At global scope:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 19%&#93; Building CXX object src/CMakeFiles/project_shared.dir/source_clang.cc.obj

> > In file included from C:/msys64/mingw64/include/c++/5.4.0/cassert:43:0,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:6,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:14,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/source_clang.cc:2:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp: In member function 'char boost::property_tree::json_parser::detail::utf8_utf8_encoding::to_internal_trivial(char) const':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:71:22: warning: comparison is always true due to limited range of data type &#91;-Wtype-limits&#93;

> > assert(c &lt;= 0x7f);

> > ^

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/source_diff.h:4,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/source.h:4,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/source_clang.h:9,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/source_clang.cc:1:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp: At global scope:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 21%&#93; Building CXX object src/CMakeFiles/project_shared.dir/source_diff.cc.obj

> > In file included from C:/msys64/mingw64/include/c++/5.4.0/cassert:43:0,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:6,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:14,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/source_diff.cc:2:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp: In member function 'char boost::property_tree::json_parser::detail::utf8_utf8_encoding::to_internal_trivial(char) const':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:71:22: warning: comparison is always true due to limited range of data type &#91;-Wtype-limits&#93;

> > assert(c &lt;= 0x7f);

> > ^

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/source_diff.h:4,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/source_diff.cc:1:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp: At global scope:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 24%&#93; Building CXX object src/CMakeFiles/project_shared.dir/source_spellcheck.cc.obj

> > In file included from C:/msys64/mingw64/include/c++/5.4.0/cassert:43:0,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:6,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:14,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/source_spellcheck.cc:2:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp: In member function 'char boost::property_tree::json_parser::detail::utf8_utf8_encoding::to_internal_trivial(char) const':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:71:22: warning: comparison is always true due to limited range of data type &#91;-Wtype-limits&#93;

> > assert(c &lt;= 0x7f);

> > ^

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:4,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/source_spellcheck.cc:2:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp: At global scope:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 26%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/libclangmm/src/CodeCompleteResults.cc.obj

> > &#91; 29%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/libclangmm/src/CompilationDatabase.cc.obj

> > &#91; 31%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/libclangmm/src/CompileCommand.cc.obj

> > &#91; 34%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/libclangmm/src/CompileCommands.cc.obj

> > &#91; 36%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/libclangmm/src/CompletionString.cc.obj

> > &#91; 39%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/libclangmm/src/Cursor.cc.obj

> > &#91; 41%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/libclangmm/src/Diagnostic.cc.obj

> > &#91; 43%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/libclangmm/src/Index.cc.obj

> > &#91; 46%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/libclangmm/src/SourceLocation.cc.obj

> > &#91; 48%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/libclangmm/src/SourceRange.cc.obj

> > &#91; 51%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/libclangmm/src/Token.cc.obj

> > &#91; 53%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/libclangmm/src/Tokens.cc.obj

> > &#91; 56%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/libclangmm/src/TranslationUnit.cc.obj

> > &#91; 58%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/libclangmm/src/Utility.cc.obj

> > &#91; 60%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/tiny-process-library/process.cpp.obj

> > &#91; 63%&#93; Building CXX object src/CMakeFiles/project_shared.dir/__/tiny-process-library/process_win.cpp.obj

> > &#91; 63%&#93; Built target project_shared

> > Scanning dependencies of target juci

> > &#91; 65%&#93; Building CXX object src/CMakeFiles/juci.dir/config.cc.obj

> > In file included from C:/msys64/mingw64/include/c++/5.4.0/cassert:43:0,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:6,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:14,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[config.cc](http://config.cc):1:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp: In member function 'char boost::property_tree::json_parser::detail::utf8_utf8_encoding::to_internal_trivial(char) const':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:71:22: warning: comparison is always true due to limited range of data type &#91;-Wtype-limits&#93;

> > assert(c &lt;= 0x7f);

> > ^

> > In file included from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:16:0,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[config.cc](http://config.cc):1:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/standard_callbacks.hpp: In member function 'Ptree& boost::property_tree::json_parser::detail::standard_callbacks&lt;Ptree&gt;::new_tree() &#91;with Ptree = boost::property_tree::basic_ptree&lt;std::__cxx11::basic_string&lt;char&gt;, std::__cxx11::basic_string&lt;char&gt; &gt;&#93;':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/standard_callbacks.hpp:132:9: warning: control reaches end of non-void function &#91;-Wreturn-type&#93;

> > }

> > ^

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:4,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[config.cc](http://config.cc):1:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp: At global scope:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 68%&#93; Building CXX object src/CMakeFiles/juci.dir/dialogs.cc.obj

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/dialogs.h:4,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[dialogs.cc](http://dialogs.cc):1:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 70%&#93; Building CXX object src/CMakeFiles/juci.dir/dialogs_unix.cc.obj

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/dialogs.h:4,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/dialogs_unix.cc:1:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 73%&#93; Building CXX object src/CMakeFiles/juci.dir/directories.cc.obj

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/directories.h:7,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[directories.cc](http://directories.cc):1:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 75%&#93; Building CXX object src/CMakeFiles/juci.dir/entrybox.cc.obj

> > &#91; 78%&#93; Building CXX object src/CMakeFiles/juci.dir/info.cc.obj

> > &#91; 80%&#93; Building CXX object src/CMakeFiles/juci.dir/juci.cc.obj

> > In file included from C:/msys64/mingw64/include/c++/5.4.0/cassert:43:0,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:6,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:14,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[juci.cc](http://juci.cc):6:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp: In member function 'char boost::property_tree::json_parser::detail::utf8_utf8_encoding::to_internal_trivial(char) const':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:71:22: warning: comparison is always true due to limited range of data type &#91;-Wtype-limits&#93;

> > assert(c &lt;= 0x7f);

> > ^

> > In file included from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:16:0,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[juci.cc](http://juci.cc):6:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/standard_callbacks.hpp: In member function 'Ptree& boost::property_tree::json_parser::detail::standard_callbacks&lt;Ptree&gt;::new_tree() &#91;with Ptree = boost::property_tree::basic_ptree&lt;std::__cxx11::basic_string&lt;char&gt;, std::__cxx11::basic_string&lt;char&gt; &gt;&#93;':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/standard_callbacks.hpp:132:9: warning: control reaches end of non-void function &#91;-Wreturn-type&#93;

> > }

> > ^

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/juci.h:32,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[juci.cc](http://juci.cc):1:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp: At global scope:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 82%&#93; Building CXX object src/CMakeFiles/juci.dir/menu.cc.obj

> > In file included from C:/msys64/mingw64/include/c++/5.4.0/cassert:43:0,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:6,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:14,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[menu.cc](http://menu.cc):2:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp: In member function 'char boost::property_tree::json_parser::detail::utf8_utf8_encoding::to_internal_trivial(char) const':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:71:22: warning: comparison is always true due to limited range of data type &#91;-Wtype-limits&#93;

> > assert(c &lt;= 0x7f);

> > ^

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:4,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[menu.cc](http://menu.cc):2:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp: At global scope:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 85%&#93; Building CXX object src/CMakeFiles/juci.dir/notebook.cc.obj

> > In file included from C:/msys64/mingw64/include/c++/5.4.0/cassert:43:0,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:6,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:14,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[notebook.cc](http://notebook.cc):2:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp: In member function 'char boost::property_tree::json_parser::detail::utf8_utf8_encoding::to_internal_trivial(char) const':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:71:22: warning: comparison is always true due to limited range of data type &#91;-Wtype-limits&#93;

> > assert(c &lt;= 0x7f);

> > ^

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/source_diff.h:4,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/source.h:4,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/notebook.h:6,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[notebook.cc](http://notebook.cc):1:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp: At global scope:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 87%&#93; Building CXX object src/CMakeFiles/juci.dir/project.cc.obj

> > In file included from C:/msys64/mingw64/include/c++/5.4.0/cassert:43:0,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:6,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:14,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[project.cc](http://project.cc):2:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp: In member function 'char boost::property_tree::json_parser::detail::utf8_utf8_encoding::to_internal_trivial(char) const':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:71:22: warning: comparison is always true due to limited range of data type &#91;-Wtype-limits&#93;

> > assert(c &lt;= 0x7f);

> > ^

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/project.h:5,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[project.cc](http://project.cc):1:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp: At global scope:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 90%&#93; Building CXX object src/CMakeFiles/juci.dir/selectiondialog.cc.obj

> > &#91; 92%&#93; Building CXX object src/CMakeFiles/juci.dir/terminal.cc.obj

> > In file included from C:/msys64/mingw64/include/c++/5.4.0/cassert:43:0,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:6,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:14,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[terminal.cc](http://terminal.cc):2:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp: In member function 'char boost::property_tree::json_parser::detail::utf8_utf8_encoding::to_internal_trivial(char) const':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:71:22: warning: comparison is always true due to limited range of data type &#91;-Wtype-limits&#93;

> > assert(c &lt;= 0x7f);

> > ^

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/terminal.h:7,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[terminal.cc](http://terminal.cc):1:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp: At global scope:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91; 95%&#93; Building CXX object src/CMakeFiles/juci.dir/tooltips.cc.obj

> > &#91; 97%&#93; Building CXX object src/CMakeFiles/juci.dir/window.cc.obj

> > In file included from C:/msys64/mingw64/include/c++/5.4.0/cassert:43:0,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:6,

> > from C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/read.hpp:14,

> > from C:/local/boost_1_60_0/boost/property_tree/json_parser.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:3,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[window.cc](http://window.cc):2:

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp: In member function 'char boost::property_tree::json_parser::detail::utf8_utf8_encoding::to_internal_trivial(char) const':

> > C:/local/boost_1_60_0/boost/property_tree/detail/json_parser/narrow_encoding.hpp:71:22: warning: comparison is always true due to limited range of data type &#91;-Wtype-limits&#93;

> > assert(c &lt;= 0x7f);

> > ^

> > In file included from C:/local/boost_1_60_0/boost/filesystem/path_traits.hpp:23:0,

> > from C:/local/boost_1_60_0/boost/filesystem/path.hpp:25,

> > from C:/local/boost_1_60_0/boost/filesystem.hpp:16,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/config.h:4,

> > from C:/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/src/[window.cc](http://window.cc):2:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp: At global scope:

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:221:36: warning: 'boost::system::posix_category' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & posix_category = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:222:36: warning: 'boost::system::errno_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & errno_ecat = generic_category();

> > ^

> > C:/local/boost_1_60_0/boost/system/error_code.hpp:223:36: warning: 'boost::system::native_ecat' defined but not used &#91;-Wunused-variable&#93;

> > static const error_category & native_ecat = system_category();

> > ^

> > &#91;100%&#93; Linking CXX executable juci.exe

> > &#91;100%&#93; Built target juci

> > kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 /c/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/build

> > $

==&gt; finally make the install seems to work ok?

> > kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 /c/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/build

> > $ make install

> > &#91; 63%&#93; Built target project_shared

> > &#91;100%&#93; Built target juci

> > Install the project...

> > -- Install configuration: ""

> > -- Installing: C:/msys64/mingw64/bin/juci.exe

> > kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 /c/Users/kjell-olovhogdahl/Documents/GitHub/jucipp/build

> > $

==&gt; And I may open a cpp file ok?

![](<Jucipp tree main.cpp file view.tiff>)

…

2) Consider to document how to build it on Linus?

TBD…

3) Consider to document how to build it on MacOS?

TBD...

{% endraw %}
