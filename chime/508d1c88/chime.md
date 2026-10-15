# Todo: Consider to document how (and where) my brew upgrade gcc to gcc13 went?

```#508d1c88``` *As of 2023-07-22 16:36*

[mail plain/text](mail.txt)

{% raw %}
I am still not comfortable with the obscuroty of what brew does behind the scenes but I went ahead and "upgraded" my brew gcc install anyways.

1) It seems my "brew upgrade gcc" installed gcc 13.1.0 (and removed my gcc 12.2.0)?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit % brew upgrade gcc  
> ==&gt; **Upgrading 1 outdated package:**  
> gcc 12.2.0 -&gt; 13.1.0  
> ==&gt; **Fetching dependencies for gcc: ****isl****, ****mpfr****, ****libmpc** **and ****xz**  
> ==&gt; **Fetching ****isl**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/isl/manifests/0.26>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/isl/blobs/sha256:0dcc555fd2517c6c93bca8999c741029bbdd821bfeb397505ec1f98deb79c551>**  
> #=#=- # # #=O#- # # -#O=- # # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****mpfr**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/mpfr/manifests/4.2.0-p12>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/mpfr/blobs/sha256:d6879fb531aac96a5898ee13d929d6a01d394a63906de0b2a24c1a5f67d067f5>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****libmpc**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/libmpc/manifests/1.3.1>**  
> ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/libmpc/blobs/sha256:c32f2c3fe7ab06e308e6fa74874e1d4d92ff6eb3598da6e0f8e6fa7a333350f5>**  
> #=#=- # # #=O#- # # -#O=- # # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****xz**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/xz/manifests/5.4.3>**  
> ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/xz/blobs/sha256:1197fc939b8c9722ad7b36d8b38ddee54531f03d2f9f1c33f5ca91e843b13e62>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****gcc**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/gcc/manifests/13.1.0>**  
> ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/gcc/blobs/sha256:f9cbc7eb14781df9228518a2d02590941206947e7dc419c0b232d523f39b1475>**  
> #=#=- # # #=O#- # # -#O=- # # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Upgrading ****gcc**  
> **12.2.0 -&gt; 13.1.0 **

> ==&gt; **Installing dependencies for gcc: ****isl****, ****mpfr****, ****libmpc** **and ****xz**  
> ==&gt; **Installing gcc dependency: ****isl**  
> ==&gt; **Pouring isl--0.26.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/isl/0.26: 73 files, 7.6MB  
> ==&gt; **Installing gcc dependency: ****mpfr**  
> ==&gt; **Pouring mpfr--4.2.0-p12.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/mpfr/4.2.0-p12: 30 files, 3MB  
> ==&gt; **Installing gcc dependency: ****libmpc**  
> ==&gt; **Pouring libmpc--1.3.1.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/libmpc/1.3.1: 12 files, 464KB  
> ==&gt; **Installing gcc dependency: ****xz**  
> ==&gt; **Pouring xz--5.4.3.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/xz/5.4.3: 162 files, 2.5MB  
> ==&gt; **Installing ****gcc**  
> ==&gt; **Pouring gcc--13.1.0.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/gcc/13.1.0: 1,606 files, 429.4MB  
> ==&gt; **Running \`brew cleanup gcc\`...**  
> Disable this behaviour by setting HOMEBREW_NO_INSTALL_CLEANUP.  
> Hide these hints with HOMEBREW_NO_ENV_HINTS (see \`man brew\`).  
> Removing: /usr/local/Cellar/gcc/12.2.0... (1,582 files, 405.2MB)  
> Warning: Formula freecad/freecad/python3.9 was renamed to python3.9.  
> Error: Could not get runtime dependencies from /usr/local/opt/pyside2/.brew/pyside2.rb!  
> Error: No available formula with the name "freecad/freecad/shiboken2@5.15.2". Did you mean freecad/freecad/shiboken2@5.15.5 or freecad/freecad/pyside2@5.15.5?  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit %

2) This seems to be a working configuration of VSCode to compile using the brew installed 13.1.0 gcc?

> "tasks": &#91;  
> {  
> "type": "cppbuild",  
> "label": "macOS C/C++: Brew installed g++-13 build cratchit",  
> "command": "/usr/local/Cellar/gcc/13.1.0/bin/g++-13",  
> "args": &#91;  
> "--sysroot=/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk",  
> "-fdiagnostics-color=always",  
> "-std=c++20",  
> "-g",  
> "${file}",  
> "-o",  
> "${workspaceFolder}/cratchit.out"  
> &#93;,  
> "options": {  
> "cwd": "${fileDirname}"  
> },  
> "problemMatcher": &#91;  
> "$gcc"  
> &#93;,  
> "group": "build",  
> "detail": "compiler: /usr/local/Cellar/gcc/13.1.0/bin/g++-13"  
> },

...

{% endraw %}
