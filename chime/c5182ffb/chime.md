# Todo: Consider to document how I removed and re-installed Freecad 0.21 using brew on my macOS?

```#c5182ffb``` *As of 2024-06-05 17:41*

[mail plain/text](mail.txt)

{% raw %}
I got an error when upgrading LLVM and GCC using brew that indicated something is wrong with freecad python interoperations so I tried to repair it through brew.

==&gt; Also see "Todo: Consider to try out Freecad again in november 2023 and document my observations and usability for my needs to "build stuff"?"

==&gt; Also see "Todo: FreeCad Cheat Sheet - Consider the recommendations by youtube viewer on "best" way to start a sketch and configure for landing GUI?"

==&gt; Also see "Todo: Consider to document how I tried to build FreeCad from Github latest branch on mac OS?"

==&gt; Also see "Todo: Consider to study and try out the 2D CAD application LibreCAD, a fork of QCAD (as a companion to 3D CAD FreeCAD)?"

==&gt; Also see "Todo: Consider to study and try out the Open Source 2D CAD application QCAD (NOT CuteCAD as a companion to 3D CAD FreeCAD)?"

==&gt; Also see "Todo: Consider to study and try out the 2D CAD application CuteCAD (as a companion to 3D CAD FreeCAD)?"

==&gt; Also see "Todo: Build House - Consider to really give FreeCad a try to see if I can rely on it to design, model and produce plans using it BIM style?"

==&gt; Also see "Todo: Consider to check out Open Source FreeCAD tool for 3D Design?"

1) Consider the error I got in 'brew upgrade llvm'?

==&gt; Also see "Todo: Consider to document how (and where) my brew upgrade llvm from 17.0.5 to 18.1.6 went?"

> ==&gt; **Running \`brew cleanup llvm\`...**  
> Disable this behaviour by setting HOMEBREW_NO_INSTALL_CLEANUP.  
> Hide these hints with HOMEBREW_NO_ENV_HINTS (see \`man brew\`).  
> Removing: /usr/local/Cellar/llvm/17.0.5... (7,207 files, 1.7GB)  
> Error: Could not get runtime dependencies from /usr/local/opt/pyside2/.brew/pyside2.rb!  
> Error: No available formula with the name "freecad/freecad/shiboken2@5.15.2". Did you mean freecad/freecad/shiboken2@5.15.5, freecad/freecad/shiboken2@5.15.11, freecad/freecad/shiboken2@5.15.11_py310 or freecad/freecad/pyside2@5.15.5?  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit %

2) Consider the error I got in 'brew upgrade gcc'?

==&gt; Also see "Todo: Consider to document how (and where) my brew upgrade gcc to gcc14 went?"

> ==&gt; **Running \`brew cleanup gcc\`...**  
> Disable this behaviour by setting HOMEBREW_NO_INSTALL_CLEANUP.  
> Hide these hints with HOMEBREW_NO_ENV_HINTS (see \`man brew\`).  
> Removing: /usr/local/Cellar/gcc/13.2.0... (1,606 files, 424.3MB)  
> Error: Could not get runtime dependencies from /usr/local/opt/pyside2/.brew/pyside2.rb!  
> Error: No available formula with the name "freecad/freecad/shiboken2@5.15.2". Did you mean freecad/freecad/shiboken2@5.15.5, freecad/freecad/shiboken2@5.15.11, freecad/freecad/shiboken2@5.15.11_py310 or freecad/freecad/pyside2@5.15.5?  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit %

3) Consider the result of trying to "repair" freecad files through brew commands?

==&gt; It seems I successfully installed freecad 0.21 to the macOS application folder?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit % brew install --cask freecad  
> ==&gt; **Downloading <https://github.com/FreeCAD/FreeCAD/releases/download/0.21.2/FreeCAD-0.21.2-macOS-intel-x86_64.dmg>**  
> ==&gt; **Downloading from <https://objects.githubusercontent.com/github-production-release-asset-2e65be/5736080/52eb64f2-fa84-4246-9cc9-127ae33f4193?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=releaseassetproduction%2F20240605%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240605T150030Z&X-Amz-Expires=300&X-Amz-Signature=bf42ba8d9843d8b24168680ee2561fe545cb5f5768d>**  
> ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Installing Cask ****freecad**  
> ==&gt; **Moving App 'FreeCAD.app' to '/Applications/FreeCAD.app'**  
> 🍺 freecad was successfully installed!  
> ==&gt; **\`brew cleanup\` has not been run in the last 30 days, running now...**  
> Disable this behaviour by setting HOMEBREW_NO_INSTALL_CLEANUP.  
> Hide these hints with HOMEBREW_NO_ENV_HINTS (see \`man brew\`).  
> ==&gt; **Downloading <https://formulae.brew.sh/api/formula.jws.json>**  
> #=#=- # #  
> ==&gt; **Autoremoving 2 unneeded formulae:**  
> python@3.10  
> python@3.11  
> Uninstalling /usr/local/Cellar/python@3.10/3.10.2... (3,133 files, 56.4MB)  
> python@3.10 3.10.1 is still installed.  
> To remove all versions, run:  
> brew uninstall --force python@3.10  
> Uninstalling /usr/local/Cellar/python@3.11/3.11.3... (3,176 files, 61.4MB)  
> Error: Permission denied @ apply2files - /usr/local/share/ghostscript/9.27/Resource/CIDFSubst/ipaexg.ttf  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit %

==&gt; But it seems there is still something wrong with the python framework as seen by brew?

> Uninstalling /usr/local/Cellar/python@3.10/3.10.2... (3,133 files, 56.4MB)  
> python@3.10 3.10.1 is still installed.  
> To remove all versions, run:  
> brew uninstall --force python@3.10  
> Uninstalling /usr/local/Cellar/python@3.11/3.11.3... (3,176 files, 61.4MB)  
> Error: **Permission denied** @ apply2files - /usr/local/share/ghostscript/9.27/Resource/CIDFSubst/ipaexg.ttf  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit %

4) Consider it is beacuse macOS has "screwed up" the permissions on the /usr/local folder tree (<https://stackoverflow.com/questions/61899041/macos-permission-denied-apply2files-usr-local-lib-node-modules-expo-cli-n> )?

> This issue appeared after upgrading macOS to **Mojave 10.14.X onwards**.

> Therefore, you need to reset the permissions in **/usr/local**:

> ```
> sudo chown -R $(whoami):admin /usr/local/* \
> && sudo chmod -R g+rwx /usr/local/*

> ```

  
> Source: <https://github.com/Homebrew/homebrew-core/issues/45009#issuecomment-543795948>

==&gt; It seems the fix above made the command 'brew cleanup' work ok?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit % sudo chown -R $(whoami):admin /usr/local/\* \\  
> && sudo chmod -R g+rwx /usr/local/\*  
> Password:  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit % ls /usr/local/Cellar/gcc/14.1.0_1/bin/g++\*  
> /usr/local/Cellar/gcc/14.1.0_1/bin/g++-14  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit % ls /usr/local/Cellar/llvm/18.1.6/bin/clang\*  
> /usr/local/Cellar/llvm/18.1.6/bin/clang /usr/local/Cellar/llvm/18.1.6/bin/clang-cl /usr/local/Cellar/llvm/18.1.6/bin/clang-include-fixer /usr/local/Cellar/llvm/18.1.6/bin/clang-query /usr/local/Cellar/llvm/18.1.6/bin/clang-tblgen  
> /usr/local/Cellar/llvm/18.1.6/bin/clang++ /usr/local/Cellar/llvm/18.1.6/bin/clang-cpp /usr/local/Cellar/llvm/18.1.6/bin/clang-linker-wrapper /usr/local/Cellar/llvm/18.1.6/bin/clang-refactor /usr/local/Cellar/llvm/18.1.6/bin/clang-tidy  
> /usr/local/Cellar/llvm/18.1.6/bin/clang-18 /usr/local/Cellar/llvm/18.1.6/bin/clang-doc /usr/local/Cellar/llvm/18.1.6/bin/clang-move /usr/local/Cellar/llvm/18.1.6/bin/clang-rename /usr/local/Cellar/llvm/18.1.6/bin/clangd  
> /usr/local/Cellar/llvm/18.1.6/bin/clang-apply-replacements /usr/local/Cellar/llvm/18.1.6/bin/clang-extdef-mapping /usr/local/Cellar/llvm/18.1.6/bin/clang-offload-bundler /usr/local/Cellar/llvm/18.1.6/bin/clang-reorder-fields /usr/local/Cellar/llvm/18.1.6/bin/clangd-xpc-test-client  
> /usr/local/Cellar/llvm/18.1.6/bin/clang-change-namespace /usr/local/Cellar/llvm/18.1.6/bin/clang-format /usr/local/Cellar/llvm/18.1.6/bin/clang-offload-packager /usr/local/Cellar/llvm/18.1.6/bin/clang-repl  
> /usr/local/Cellar/llvm/18.1.6/bin/clang-check /usr/local/Cellar/llvm/18.1.6/bin/clang-include-cleaner /usr/local/Cellar/llvm/18.1.6/bin/clang-pseudo /usr/local/Cellar/llvm/18.1.6/bin/clang-scan-deps  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit % brew cleanup  
> Warning: Skipping aom: most recent version 3.9.0 not installed  
> Warning: Skipping assimp: most recent version 5.4.1 not installed  
> Warning: Skipping boost: most recent version 1.85.0 not installed  
> Warning: Skipping boost-python3: most recent version 1.85.0 not installed  
> Warning: Skipping cjson: most recent version 1.7.18 not installed  
> Warning: Skipping cmake: most recent version 3.29.4 not installed  
> Warning: Skipping dav1d: most recent version 1.4.2 not installed  
> Warning: Skipping exercism: most recent version 3.4.0 not installed  
> Warning: Skipping ffmpeg: most recent version 7.0.1 not installed  
> Warning: Skipping fontconfig: most recent version 2.15.0 not installed  
> Warning: Skipping frei0r: most recent version 2.3.2 not installed  
> Warning: Skipping fribidi: most recent version 1.0.14 not installed  
> Warning: Skipping gettext: most recent version 0.22.5 not installed  
> Warning: Skipping giflib: most recent version 5.2.2 not installed  
> Warning: Skipping git: most recent version 2.45.2 not installed  
> Warning: Skipping git-lfs: most recent version 3.5.1 not installed  
> Warning: Skipping git-svn: most recent version 2.45.2 not installed  
> Warning: Skipping glib: most recent version 2.80.2 not installed  
> Warning: Skipping gnutls: most recent version 3.8.4 not installed  
> Warning: Skipping gobject-introspection: most recent version 1.80.1 not installed  
> Warning: Skipping harfbuzz: most recent version 8.5.0 not installed  
> Warning: Skipping hdf5: most recent version 1.14.3_1 not installed  
> Warning: Skipping helix: most recent version 24.03 not installed  
> Warning: Skipping highway: most recent version 1.2.0 not installed  
> Warning: Skipping hwloc: most recent version 2.10.0 not installed  
> Warning: Skipping icu4c: most recent version 74.2 not installed  
> Warning: Skipping imath: most recent version 3.1.11 not installed  
> Warning: Skipping jasper: most recent version 4.2.4 not installed  
> Warning: Skipping jpeg: most recent version 9f not installed  
> Warning: Skipping jpeg-turbo: most recent version 3.0.3 not installed  
> Warning: Skipping jpeg-xl: most recent version 0.10.2 not installed  
> Warning: Skipping leptonica: most recent version 1.84.1 not installed  
> Warning: Skipping libarchive: most recent version 3.7.4 not installed  
> Warning: Skipping libass: most recent version 0.17.2 not installed  
> Warning: Skipping libidn2: most recent version 2.3.7 not installed  
> Warning: Skipping libmicrohttpd: most recent version 1.0.1 not installed  
> Warning: Skipping libnghttp2: most recent version 1.61.0 not installed  
> Warning: Skipping libpng: most recent version 1.6.43 not installed  
> Warning: Skipping librist: most recent version 0.2.10_1 not installed  
> Warning: Skipping libunibreak: most recent version 6.1 not installed  
> Warning: Skipping libunistring: most recent version 1.2 not installed  
> Warning: Skipping libvmaf: most recent version 3.0.0 not installed  
> Warning: Skipping libx11: most recent version 1.8.9 not installed  
> Warning: Skipping libxcb: most recent version 1.17.0 not installed  
> Warning: Skipping libxdmcp: most recent version 1.1.5 not installed  
> Warning: Skipping libxext: most recent version 1.3.6 not installed  
> Warning: Skipping little-cms2: most recent version 2.16 not installed  
> Warning: Skipping mbedtls: most recent version 3.6.0 not installed  
> Warning: Skipping md4c: most recent version 0.5.2 not installed  
> Warning: Skipping mpg123: most recent version 1.32.6 not installed  
> Warning: Skipping netcdf: most recent version 4.9.2_1 not installed  
> Warning: Skipping numpy: most recent version 1.26.4 not installed  
> Warning: Skipping open-mpi: most recent version 5.0.3_1 not installed  
> Warning: Skipping openblas: most recent version 0.3.27 not installed  
> Warning: Skipping opencascade: most recent version 7.7.2_4 not installed  
> Warning: Skipping openexr: most recent version 3.2.4 not installed  
> Warning: Skipping openjpeg: most recent version 2.5.2 not installed  
> Warning: Skipping openssl@1.1: most recent version 1.1.1w not installed  
> Warning: Skipping opus: most recent version 1.5.2 not installed  
> Warning: Skipping pandoc: most recent version 3.2 not installed  
> Warning: Skipping pango: most recent version 1.52.2 not installed  
> Warning: Skipping pcre2: most recent version 10.43 not installed  
> Warning: Skipping pyqt: most recent version 6.7.0 not installed  
> Warning: Skipping pyqt@5: most recent version 5.15.10 not installed  
> Warning: Skipping python-setuptools: most recent version 70.0.0 not installed  
> Warning: Skipping python@3.10: most recent version 3.10.14 not installed  
> Warning: Skipping python@3.8: most recent version 3.8.19 not installed  
> Warning: Skipping python@3.9: most recent version 3.9.19 not installed  
> Warning: Skipping qt: most recent version 6.7.0_1 not installed  
> Warning: Skipping qt@5: most recent version 5.15.13_1 not installed  
> Warning: Skipping rav1e: most recent version 0.7.1 not installed  
> Warning: Skipping sdl2: most recent version 2.30.3 not installed  
> Warning: Skipping sip: most recent version 6.8.3_1 not installed  
> Warning: Skipping snappy: most recent version 1.2.1 not installed  
> Warning: Skipping subversion: most recent version 1.14.3_1 not installed  
> Warning: Skipping svt-av1: most recent version 2.1.0 not installed  
> Warning: Skipping tbb: most recent version 2021.12.0 not installed  
> Warning: Skipping tcl-tk: most recent version 8.6.14 not installed  
> Warning: Skipping tesseract: most recent version 5.3.4_1 not installed  
> Warning: Skipping tree: most recent version 2.1.1_1 not installed  
> Warning: Skipping unbound: most recent version 1.20.0 not installed  
> Warning: Skipping webp: most recent version 1.4.0 not installed  
> Warning: Skipping x265: most recent version 3.6 not installed  
> Warning: Skipping xorgproto: most recent version 2024.1 not installed  
> ==&gt; **Autoremoving 1 unneeded formula:**  
> python@3.10  
> Uninstalling /usr/local/Cellar/python@3.10/3.10.1... (3,132 files, 56MB)  
> **Pruned 346 symbolic links and 31 directories from /usr/local**  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit %

...

{% endraw %}
