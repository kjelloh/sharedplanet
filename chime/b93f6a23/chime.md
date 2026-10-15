# Todo: Consider to document how (and where) my brew upgrade llvm from 16.0.2 to 16.0.6 went?

```#b93f6a23``` *As of 2023-07-22 19:22*

[mail plain/text](mail.txt)

{% raw %}
I am still not comfortable with the obscuroty of what brew does behind the scenes but I went ahead and "upgraded" my brew gcc install anyways.

1) It seems my "brew upgrade llvm" installed llvm 16.0.6 (and removed my llvm 16.0.2)?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit % brew upgrade llvm  
> ==&gt; **Downloading <https://formulae.brew.sh/api/formula.jws.json>**

> ==&gt; **Downloading <https://formulae.brew.sh/api/cask.jws.json>**

> ==&gt; **Upgrading 1 outdated package:**  
> llvm 16.0.2 -&gt; 16.0.6  
> ==&gt; **Fetching dependencies for llvm: ****ca-certificates****, ****openssl@3****, ****sqlite****, ****python@3.11** **and ****z3**  
> ==&gt; **Fetching ****ca-certificates**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/ca-certificates/manifests/2023-05-30>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/ca-certificates/blobs/sha256:f664c0f185677a82689ada2a4e35c555e48885e6c2fb5e2dfcc82d9fb79cf870>**  
> #=#=- # # #=O#- # # -#O=- # # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****openssl@3**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/openssl/3/manifests/3.1.1_1>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/openssl/3/blobs/sha256:7d21b114cdeb9c924f3efa5ba6e120c6a852b0c7be0dda71354f6704b02e4883>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****sqlite**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/sqlite/manifests/3.42.0>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/sqlite/blobs/sha256:ab99129920b56e88f1d89bbcc07bb3f3278575029213fb070f4220b5bcd9f8d9>**  
> #=#=- # # #=O#- # # -#O=- # # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****python@3.11**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/python/3.11/manifests/3.11.4_1>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/python/3.11/blobs/sha256:fa258abf25b4f4bd6dcb7586a04faee606e07e6e480ff3dd2f04afc3db4c7a9f>**  
> #=#=- # # #=O#- # # -#O=- # # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****z3**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/z3/manifests/4.12.2>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/z3/blobs/sha256:80ce63d42c4377b4e4d30299bbb9a99f3adfd2d878936ad6717e63bd73fd28d9>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****llvm**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/llvm/manifests/16.0.6>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/llvm/blobs/sha256:ab4d69c11183a536f52dfd4eb8c14f3fc047b8433b03eff99cea76f778e61305>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Upgrading ****llvm**  
> **16.0.2 -&gt; 16.0.6 **

> ==&gt; **Installing dependencies for llvm: ****ca-certificates****, ****openssl@3****, ****sqlite****, ****python@3.11** **and ****z3**  
> ==&gt; **Installing llvm dependency: ****ca-certificates**  
> ==&gt; **Pouring ca-certificates--2023-05-30.monterey.bottle.tar.gz**  
> ==&gt; **Regenerating CA certificate bundle from keychain, this may take a while...**  
> 🍺 /usr/local/Cellar/ca-certificates/2023-05-30: 3 files, 216.2KB  
> ==&gt; **Installing llvm dependency: ****openssl@3**  
> ==&gt; **Pouring openssl@3--3.1.1_1.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/openssl@3/3.1.1_1: 6,495 files, 30.0MB  
> ==&gt; **Installing llvm dependency: ****sqlite**  
> ==&gt; **Pouring sqlite--3.42.0.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/sqlite/3.42.0: 11 files, 4.5MB  
> ==&gt; **Installing llvm dependency: ****python@3.11**  
> ==&gt; **Pouring python@3.11--3.11.4_1.monterey.bottle.tar.gz**  
> ==&gt; **/usr/local/Cellar/python@3.11/3.11.4_1/bin/python3.11 -m ensurepip**  
> ==&gt; **/usr/local/Cellar/python@3.11/3.11.4_1/bin/python3.11 -m pip install -v --no-deps --no-index --upgrade --isolated --target=/usr/local/lib/python3.11/site-packages /usr/local/Cellar/python@3.11/3.11.4_1/Frameworks/Python.framework/Versions/3.11/lib/python3.11/ensurepip/_bundled/setuptools-67.6.1-py3-none-any.whl /usr/local/Cellar/python@3.11/3.11.4_1/Framewor**  
> 🍺 /usr/local/Cellar/python@3.11/3.11.4_1: 3,286 files, 61.9MB  
> ==&gt; **Installing llvm dependency: ****z3**  
> ==&gt; **Pouring z3--4.12.2.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/z3/4.12.2: 118 files, 31.4MB  
> ==&gt; **Installing ****llvm**  
> ==&gt; **Pouring llvm--16.0.6.monterey.bottle.tar.gz**  
> ==&gt; **Caveats**  
> To use the bundled libc++ please add the following LDFLAGS:  
> LDFLAGS="-L/usr/local/opt/llvm/lib/c++ -Wl,-rpath,/usr/local/opt/llvm/lib/c++"

> llvm is keg-only, which means it was not symlinked into /usr/local,  
> because macOS already provides this software and installing another version in  
> parallel can cause all kinds of trouble.

> If you need to have llvm first in your PATH, run:  
> echo 'export PATH="/usr/local/opt/llvm/bin:$PATH"' &gt;&gt; ~/.zshrc

> For compilers to find llvm you may need to set:  
> export LDFLAGS="-L/usr/local/opt/llvm/lib"  
> export CPPFLAGS="-I/usr/local/opt/llvm/include"  
> ==&gt; **Summary**  
> 🍺 /usr/local/Cellar/llvm/16.0.6: 6,764 files, 1.6GB  
> ==&gt; **Running \`brew cleanup llvm\`...**  
> Disable this behaviour by setting HOMEBREW_NO_INSTALL_CLEANUP.  
> Hide these hints with HOMEBREW_NO_ENV_HINTS (see \`man brew\`).  
> Removing: /usr/local/Cellar/llvm/16.0.2... (6,779 files, 1.6GB)  
> Removing: /Users/kjell-olovhogdal/Library/Caches/Homebrew/llvm--16.0.2... (417.6MB)  
> Warning: Formula freecad/freecad/python3.9 was renamed to python3.9.  
> Error: Could not get runtime dependencies from /usr/local/opt/pyside2/.brew/pyside2.rb!  
> Error: No available formula with the name "freecad/freecad/shiboken2@5.15.2". Did you mean freecad/freecad/shiboken2@5.15.5 or freecad/freecad/pyside2@5.15.5?  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit %

2) This seems to be a working configuration of VSCode to compile using the brew installed 16.0.6 clang++?

> {  
> "type": "cppbuild",  
> "label": "macOS C/C++: Brew installed clang-16 build cratchit",  
> "command": "/usr/local/Cellar/llvm/16.0.6/bin/clang++",  
> "args": &#91;  
> "-fdiagnostics-color=always",  
> "-L/usr/local/Cellar/llvm/16.0.6/lib/c++/",  
> "-Wl,-rpath,/usr/local/Cellar/llvm/16.0.6/lib/c++",  
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
> "detail": "compiler: /usr/local/Cellar/llvm/16.0.6/bin/clang++"  
> },

...

{% endraw %}
