# Todo: Consider to document how I was able to install latest stable LLVM (LLVM-14) with the suggested llvm install bash script on Linux Mint 20x?

```#f2a04a22``` *As of 2022-03-28 19:35*

[mail plain/text](mail.txt)

{% raw %}
I have long wanted to use the latest LLVM (clang) but failed to find a convenient way to install it on any OS.

-1) Consider what finally worked?

==&gt; It seems (1) the llvm automatic script + (2) apt install libc++-14-dev libc++abi-14-dev + (3) use FULL path to clang++ compiler works?

> parallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$ **/usr/lib/llvm-14/bin/clang++ -v -std=c++20 -stdlib=libc++ ./src/main.cpp**  
> Ubuntu clang version 14.0.0-++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105  
> Target: x86_64-pc-linux-gnu  
> Thread model: posix  
> InstalledDir: /usr/lib/llvm-14/bin  
> Found candidate GCC installation: /usr/lib/gcc/x86_64-linux-gnu/9  
> Selected GCC installation: /usr/lib/gcc/x86_64-linux-gnu/9  
> Candidate multilib: .;@m64  
> Selected multilib: .;@m64  
> "/usr/lib/llvm-14/bin/clang" -cc1 -triple x86_64-pc-linux-gnu -emit-obj -mrelax-all --mrelax-relocations -disable-free -clear-ast-before-backend -disable-llvm-verifier -discard-value-names -main-file-name main.cpp -mrelocation-model pic -pic-level 2 -pic-is-pie -mframe-pointer=all -fmath-errno -ffp-contract=on -fno-rounding-math -mconstructor-aliases -funwind-tables=2 -target-cpu x86-64 -tune-cpu generic -mllvm -treat-scalable-fixed-error-as-warning -debugger-tuning=gdb -v -fcoverage-compilation-dir=/home/parallels/github/cratchit -resource-dir /usr/lib/llvm-14/lib/clang/14.0.0 -internal-isystem /usr/lib/llvm-14/bin/../include/c++/v1 -internal-isystem /usr/lib/llvm-14/lib/clang/14.0.0/include -internal-isystem /usr/local/include -internal-isystem /usr/lib/gcc/x86_64-linux-gnu/9/../../../../x86_64-linux-gnu/include -internal-externc-isystem /usr/include/x86_64-linux-gnu -internal-externc-isystem /include -internal-externc-isystem /usr/include -std=c++20 -fdeprecated-macro -fdebug-compilation-dir=/home/parallels/github/cratchit -ferror-limit 19 -fgnuc-version=4.2.1 -fno-implicit-modules -fcxx-exceptions -fexceptions -fcolor-diagnostics -faddrsig -D__GCC_HAVE_DWARF2_CFI_ASM=1 -o /tmp/main-28d397.o -x c++ ./src/main.cpp  
> clang -cc1 version 14.0.0 based upon LLVM 14.0.0 default target x86_64-pc-linux-gnu  
> ignoring nonexistent directory "/usr/lib/gcc/x86_64-linux-gnu/9/../../../../x86_64-linux-gnu/include"  
> ignoring nonexistent directory "/include"  
> #include "..." search starts here:  
> #include &lt;...&gt; search starts here:  
> /usr/lib/llvm-14/bin/../include/c++/v1  
> /usr/lib/llvm-14/lib/clang/14.0.0/include  
> /usr/local/include  
> /usr/include/x86_64-linux-gnu  
> /usr/include  
> End of search list.  
> "/usr/bin/ld" -pie --hash-style=both --build-id --eh-frame-hdr -m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2 -o a.out /lib/x86_64-linux-gnu/Scrt1.o /lib/x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/9/crtbeginS.o -L/usr/lib/gcc/x86_64-linux-gnu/9 -L/usr/lib/gcc/x86_64-linux-gnu/9/../../../../lib64 -L/lib/x86_64-linux-gnu -L/lib/../lib64 -L/usr/lib/x86_64-linux-gnu -L/usr/lib/../lib64 -L/usr/lib/llvm-14/bin/../lib -L/lib -L/usr/lib /tmp/main-28d397.o -lc++ -lm -lgcc_s -lgcc -lc -lgcc_s -lgcc /usr/lib/gcc/x86_64-linux-gnu/9/crtendS.o /lib/x86_64-linux-gnu/crtn.o  
> parallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$

0) It seems we MUST install LLVM C++ library libc++ SEPARATELY?

> arallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$ apt search libc++ | grep libc++  
> p libc++-10-dev - LLVM C++ Standard library (development files)  
> p libc++-10-dev:i386 - LLVM C++ Standard library (development files)  
> p libc++-11-dev - LLVM C++ Standard library (development files)  
> p libc++-11-dev:i386 - LLVM C++ Standard library (development files)  
> p libc++-12-dev - LLVM C++ Standard library (development files)  
> p libc++-12-dev:i386 - LLVM C++ Standard library (development files)  
> p libc++-14-dev - LLVM C++ Standard library (development files)  
> p libc++-7-dev - LLVM C++ Standard library (development files)  
> p libc++-8-dev - LLVM C++ Standard library (development files)  
> p libc++-9-dev - LLVM C++ Standard library (development files)  
> p libc++-9-dev:i386 - LLVM C++ Standard library (development files)  
> p libc++-dev - LLVM C++ Standard library (development files)  
> p libc++-dev:i386 - LLVM C++ Standard library (development files)  
> v libc++-x.y -  
> v libc++-x.y:i386 -  
> v libc++-x.y-dev -  
> v libc++-x.y-dev:i386 -  
> p libc++1 - LLVM C++ Standard library  
> p libc++1:i386 - LLVM C++ Standard library  
> p libc++1-10 - LLVM C++ Standard library  
> p libc++1-10:i386 - LLVM C++ Standard library  
> p libc++1-11 - LLVM C++ Standard library  
> p libc++1-11:i386 - LLVM C++ Standard library  
> p libc++1-12 - LLVM C++ Standard library  
> p libc++1-12:i386 - LLVM C++ Standard library  
> p libc++1-14 - LLVM C++ Standard library  
> p libc++1-7 - LLVM C++ Standard library  
> p libc++1-8 - LLVM C++ Standard library  
> p libc++1-9 - LLVM C++ Standard library  
> p libc++1-9:i386 - LLVM C++ Standard library  
> p libc++abi-10-dev - LLVM low level support for a standard C++ library (development fil  
> p libc++abi-10-dev:i386 - LLVM low level support for a standard C++ library (development fil  
> p libc++abi-11-dev - LLVM low level support for a standard C++ library (development fil  
> p libc++abi-11-dev:i386 - LLVM low level support for a standard C++ library (development fil  
> p libc++abi-12-dev - LLVM low level support for a standard C++ library (development fil  
> p libc++abi-12-dev:i386 - LLVM low level support for a standard C++ library (development fil  
> p libc++abi-14-dev - LLVM low level support for a standard C++ library (development fil  
> p libc++abi-7-dev - LLVM low level support for a standard C++ library (development fil  
> p libc++abi-8-dev - LLVM low level support for a standard C++ library (development fil  
> p libc++abi-9-dev - LLVM low level support for a standard C++ library (development fil  
> p libc++abi-9-dev:i386 - LLVM low level support for a standard C++ library (development fil  
> p libc++abi-dev - LLVM low level support for a standard C++ library (development fil  
> p libc++abi-dev:i386 - LLVM low level support for a standard C++ library (development fil  
> v libc++abi-x.y -  
> v libc++abi-x.y:i386 -  
> v libc++abi-x.y-dev -  
> v libc++abi-x.y-dev:i386 -  
> p libc++abi1 - LLVM low level support for a standard C++ library  
> p libc++abi1:i386 - LLVM low level support for a standard C++ library  
> p libc++abi1-10 - LLVM low level support for a standard C++ library  
> p libc++abi1-10:i386 - LLVM low level support for a standard C++ library  
> p libc++abi1-11 - LLVM low level support for a standard C++ library  
> p libc++abi1-11:i386 - LLVM low level support for a standard C++ library  
> p libc++abi1-12 - LLVM low level support for a standard C++ library  
> p libc++abi1-12:i386 - LLVM low level support for a standard C++ library  
> p libc++abi1-14 - LLVM low level support for a standard C++ library  
> p libc++abi1-7 - LLVM low level support for a standard C++ library  
> p libc++abi1-8 - LLVM low level support for a standard C++ library  
> p libc++abi1-9 - LLVM low level support for a standard C++ library  
> p libc++abi1-9:i386 - LLVM low level support for a standard C++ library  
> parallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$ sudo apt install libc++-14-dev^C  
> parallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$ sudo apt install libc++1-14  
> &#91;sudo&#93; password for parallels:  
> Reading package lists... Done  
> Building dependency tree  
> Reading state information... Done  
> The following additional packages will be installed:  
> libc++abi1-14 libunwind-14  
> Suggested packages:  
> clang  
> The following NEW packages will be installed:  
> libc++1-14 libc++abi1-14 libunwind-14  
> 0 upgraded, 3 newly installed, 0 to remove and 0 not upgraded.  
> Need to get 486 kB of archives.  
> After this operation, 1,459 kB of additional disk space will be used.  
> Do you want to continue? &#91;Y/n&#93; Y  
> Get:1 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 libunwind-14 amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;69.8 kB&#93;  
> Get:2 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 libc++abi1-14 amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;111 kB&#93;  
> Get:3 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 libc++1-14 amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;305 kB&#93;  
> Fetched 486 kB in 3s (175 kB/s)  
> Selecting previously unselected package libunwind-14:amd64.  
> (Reading database ... 324732 files and directories currently installed.)  
> Preparing to unpack .../libunwind-14_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking libunwind-14:amd64 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package libc++abi1-14:amd64.  
> Preparing to unpack .../libc++abi1-14_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking libc++abi1-14:amd64 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package libc++1-14:amd64.  
> Preparing to unpack .../libc++1-14_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking libc++1-14:amd64 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up libunwind-14:amd64 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up libc++abi1-14:amd64 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up libc++1-14:amd64 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Processing triggers for libc-bin (2.31-0ubuntu9.7) ...  
> parallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$

==&gt; After this clang-14 still failed to find c++ include files so I suspected I had failed to install the correct package?

> parallels@parallels-Parallels-Virtual-Platform:~$ **sudo apt-get install libc++-14-dev libc++abi-14-dev**  
> &#91;sudo&#93; password for parallels:  
> Sorry, try again.  
> &#91;sudo&#93; password for parallels:  
> Reading package lists... Done  
> Building dependency tree  
> Reading state information... Done  
> The following additional packages will be installed:  
> libunwind-14-dev  
> The following NEW packages will be installed:  
> libc++-14-dev libc++abi-14-dev libunwind-14-dev  
> 0 upgraded, 3 newly installed, 0 to remove and 0 not upgraded.  
> Need to get 1,174 kB of archives.  
> After this operation, 10.1 MB of additional disk space will be used.  
> Do you want to continue? &#91;Y/n&#93; Y  
> Get:1 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 libunwind-14-dev amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;86.4 kB&#93;  
> Get:2 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 libc++-14-dev amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;953 kB&#93;  
> Get:3 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 libc++abi-14-dev amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;135 kB&#93;  
> Fetched 1,174 kB in 1s (850 kB/s)  
> Selecting previously unselected package libunwind-14-dev:amd64.  
> (Reading database ... 324759 files and directories currently installed.)  
> Preparing to unpack .../libunwind-14-dev_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking libunwind-14-dev:amd64 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package libc++-14-dev:amd64.  
> Preparing to unpack .../libc++-14-dev_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking libc++-14-dev:amd64 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package libc++abi-14-dev:amd64.  
> Preparing to unpack .../libc++abi-14-dev_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking libc++abi-14-dev:amd64 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up libunwind-14-dev:amd64 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up libc++abi-14-dev:amd64 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up libc++-14-dev:amd64 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> parallels@parallels-Parallels-Virtual-Platform:~$

==&gt; YES! clang-14 now compiles but FAILS TO LINK!

> It seems the magic path to libc++-14 header files are

> **/usr/lib/llvm-14/bin/../include/c++/v1**

> Where are the library files to link with?

1) It seems the <https://apt.llvm.org/llvm.sh> apt script on llvm download page works just fine on Linux Mint 20x (<https://apt.llvm.org/> )?

==&gt; It seems the apt bash script provided by LLVM downloads and installs llvm with tool-chain commands in /usr/bin?

> parallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$ **sudo bash -c "$(wget -O - <https://apt.llvm.org/llvm.sh>)"**  
> --2022-03-28 17:41:24-- <https://apt.llvm.org/llvm.sh>  
> Resolving [apt.llvm.org](http://apt.llvm.org) ([apt.llvm.org](http://apt.llvm.org))... 151.101.86.49  
> Connecting to [apt.llvm.org](http://apt.llvm.org) ([apt.llvm.org](http://apt.llvm.org))|151.101.86.49|:443... connected.  
> HTTP request sent, awaiting response... 200 OK  
> Length: 4978 (4.9K) &#91;application/octet-stream&#93;  
> Saving to: ‘STDOUT’

> - 100%&#91;======================================&gt;&#93; 4.86K --.-KB/s in 0s

> 2022-03-28 17:41:24 (17.0 MB/s) - written to stdout &#91;4978/4978&#93;

> &#91;sudo&#93; password for parallels:  
> + CURRENT_LLVM_STABLE=14  
> + needed_binaries=(lsb_release wget add-apt-repository)  
> + missing_binaries=()  
> + for binary in "${needed_binaries&#91;@&#93;}"  
> + which lsb_release  
> + for binary in "${needed_binaries&#91;@&#93;}"  
> + which wget  
> + for binary in "${needed_binaries&#91;@&#93;}"  
> + which add-apt-repository  
> + &#91;&#91; 0 -gt 0 &#93;&#93;  
> + LLVM_VERSION=14  
> + ALL=0  
> + '&#91;' 0 -ge 1 '&#93;'  
> ++ lsb_release -is  
> + DISTRO=Linuxmint  
> ++ lsb_release -sr  
> + VERSION=20.2  
> + DIST_VERSION=Linuxmint_20.2  
> + &#91;&#91; 0 -ne 0 &#93;&#93;  
> + declare -A LLVM_VERSION_PATTERNS  
> + LLVM_VERSION_PATTERNS&#91;9&#93;=-9  
> + LLVM_VERSION_PATTERNS&#91;10&#93;=-10  
> + LLVM_VERSION_PATTERNS&#91;11&#93;=-11  
> + LLVM_VERSION_PATTERNS&#91;12&#93;=-12  
> + LLVM_VERSION_PATTERNS&#91;13&#93;=-13  
> + LLVM_VERSION_PATTERNS&#91;14&#93;=-14  
> + LLVM_VERSION_PATTERNS&#91;15&#93;=  
> + '&#91;' '!' _ '&#93;'  
> + LLVM_VERSION_STRING=-14  
> + case "$DIST_VERSION" in  
> + REPO_NAME='deb <http://apt.llvm.org/focal/> llvm-toolchain-focal-14 main'  
> + wget -O - <https://apt.llvm.org/llvm-snapshot.gpg.key>  
> + apt-key add -  
> --2022-03-28 17:41:31-- <https://apt.llvm.org/llvm-snapshot.gpg.key>  
> Resolving [apt.llvm.org](http://apt.llvm.org) ([apt.llvm.org](http://apt.llvm.org))... 151.101.86.49  
> Connecting to [apt.llvm.org](http://apt.llvm.org) ([apt.llvm.org](http://apt.llvm.org))|151.101.86.49|:443... connected.  
> HTTP request sent, awaiting response... 200 OK  
> Length: 3145 (3.1K) &#91;application/octet-stream&#93;  
> Saving to: ‘STDOUT’

> - 100%&#91;======================================&gt;&#93; 3.07K --.-KB/s in 0s

> 2022-03-28 17:41:31 (67.1 MB/s) - written to stdout &#91;3145/3145&#93;

> OK  
> + add-apt-repository 'deb <http://apt.llvm.org/focal/> llvm-toolchain-focal-14 main'  
> + apt-get update  
> Get:1 <http://security.ubuntu.com/ubuntu> focal-security InRelease &#91;114 kB&#93;  
> Ign:2 <http://packages.linuxmint.com> uma InRelease  
> Hit:3 <http://archive.canonical.com/ubuntu> focal InRelease  
> Hit:4 <http://archive.ubuntu.com/ubuntu> focal InRelease  
> Hit:5 <http://packages.linuxmint.com> uma Release  
> Get:6 <http://security.ubuntu.com/ubuntu> focal-security/main amd64 DEP-11 Metadata &#91;40.7 kB&#93;  
> Get:7 <http://archive.ubuntu.com/ubuntu> focal-updates InRelease &#91;114 kB&#93;  
> Get:8 <http://packages.microsoft.com/repos/code> stable InRelease &#91;10.4 kB&#93;  
> Get:9 <http://security.ubuntu.com/ubuntu> focal-security/universe amd64 DEP-11 Metadata &#91;66.5 kB&#93;  
> Get:10 <http://security.ubuntu.com/ubuntu> focal-security/multiverse amd64 DEP-11 Metadata &#91;2,464 B&#93;  
> Get:12 <http://packages.microsoft.com/repos/code> stable/main arm64 Packages &#91;77.9 kB&#93;  
> Get:14 <http://archive.ubuntu.com/ubuntu> focal-backports InRelease &#91;108 kB&#93;  
> Get:15 <http://packages.microsoft.com/repos/code> stable/main amd64 Packages &#91;77.2 kB&#93;  
> Get:16 <http://packages.microsoft.com/repos/code> stable/main armhf Packages &#91;78.1 kB&#93;  
> Get:17 <http://archive.ubuntu.com/ubuntu> focal-updates/main amd64 DEP-11 Metadata &#91;278 kB&#93;  
> Get:18 <http://archive.ubuntu.com/ubuntu> focal-updates/universe amd64 DEP-11 Metadata &#91;390 kB&#93;  
> Get:19 <http://archive.ubuntu.com/ubuntu> focal-updates/multiverse amd64 DEP-11 Metadata &#91;944 B&#93;  
> Get:20 <http://archive.ubuntu.com/ubuntu> focal-backports/main amd64 DEP-11 Metadata &#91;7,984 B&#93;  
> Get:21 <http://archive.ubuntu.com/ubuntu> focal-backports/universe amd64 DEP-11 Metadata &#91;30.8 kB&#93;  
> Get:13 <https://apt.llvm.org/focal> llvm-toolchain-focal-14 InRelease &#91;6,827 B&#93;  
> Get:22 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 Packages &#91;10.6 kB&#93;  
> Get:23 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main i386 Packages &#91;1,837 B&#93;  
> Fetched 1,416 kB in 2s (568 kB/s)  
> Reading package lists... Done  
> + PKG='clang-14 lldb-14 lld-14 clangd-14'  
> + &#91;&#91; 0 -eq 1 &#93;&#93;  
> + apt-get install -y clang-14 lldb-14 lld-14 clangd-14  
> Reading package lists... Done  
> Building dependency tree  
> Reading state information... Done  
> The following additional packages will be installed:  
> binfmt-support icu-devtools lib32gcc-s1 lib32stdc++6 libc6-i386 libclang-common-14-dev libclang-cpp14  
> libclang1-14 libffi-dev libicu-dev liblldb-14 libllvm14 libncurses-dev libobjc-9-dev libobjc4 libpfm4  
> libstdc++-9-dev libtinfo-dev libxml2-dev libz3-4 libz3-dev llvm-14 llvm-14-dev llvm-14-linker-tools  
> llvm-14-runtime llvm-14-tools python3-lldb-14 python3-pygments  
> Suggested packages:  
> clang-14-doc icu-doc ncurses-doc libstdc++-9-doc llvm-14-doc python-pygments-doc ttf-bitstream-vera  
> The following NEW packages will be installed:  
> binfmt-support clang-14 clangd-14 icu-devtools lib32gcc-s1 lib32stdc++6 libc6-i386  
> libclang-common-14-dev libclang-cpp14 libclang1-14 libffi-dev libicu-dev liblldb-14 libllvm14  
> libncurses-dev libobjc-9-dev libobjc4 libpfm4 libstdc++-9-dev libtinfo-dev libxml2-dev libz3-4  
> libz3-dev lld-14 lldb-14 llvm-14 llvm-14-dev llvm-14-linker-tools llvm-14-runtime llvm-14-tools  
> python3-lldb-14 python3-pygments  
> 0 upgraded, 32 newly installed, 0 to remove and 0 not upgraded.  
> Need to get 125 MB of archives.  
> After this operation, 772 MB of additional disk space will be used.  
> Get:3 <http://archive.ubuntu.com/ubuntu> focal/universe amd64 binfmt-support amd64 2.2.0-2 &#91;58.2 kB&#93;  
> Get:1 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 libllvm14 amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;21.7 MB&#93;  
> Get:8 <http://archive.ubuntu.com/ubuntu> focal-updates/main amd64 libstdc++-9-dev amd64 9.4.0-1ubuntu1~20.04.1 &#91;1,722 kB&#93;  
> Get:17 <http://archive.ubuntu.com/ubuntu> focal-updates/universe amd64 libobjc4 amd64 10.3.0-1ubuntu1~20.04 &#91;42.8 kB&#93;  
> Get:19 <http://archive.ubuntu.com/ubuntu> focal-updates/universe amd64 libobjc-9-dev amd64 9.4.0-1ubuntu1~20.04.1 &#91;225 kB&#93;  
> Get:20 <http://archive.ubuntu.com/ubuntu> focal-updates/main amd64 libc6-i386 amd64 2.31-0ubuntu9.7 &#91;2,725 kB&#93;  
> Get:21 <http://archive.ubuntu.com/ubuntu> focal-updates/main amd64 lib32gcc-s1 amd64 10.3.0-1ubuntu1~20.04 &#91;49.2 kB&#93;  
> Get:22 <http://archive.ubuntu.com/ubuntu> focal-updates/main amd64 lib32stdc++6 amd64 10.3.0-1ubuntu1~20.04 &#91;525 kB&#93;  
> Get:23 <http://archive.ubuntu.com/ubuntu> focal-updates/main amd64 icu-devtools amd64 66.1-2ubuntu2.1 &#91;189 kB&#93;  
> Get:24 <http://archive.ubuntu.com/ubuntu> focal-updates/main amd64 libicu-dev amd64 66.1-2ubuntu2.1 &#91;9,451 kB&#93;  
> Get:25 <http://archive.ubuntu.com/ubuntu> focal/main amd64 libncurses-dev amd64 6.2-0ubuntu2 &#91;339 kB&#93;  
> Get:26 <http://archive.ubuntu.com/ubuntu> focal/main amd64 libtinfo-dev amd64 6.2-0ubuntu2 &#91;968 B&#93;  
> Get:27 <http://archive.ubuntu.com/ubuntu> focal-updates/main amd64 libxml2-dev amd64 2.9.10+dfsg-5ubuntu0.20.04.2 &#91;737 kB&#93;  
> Get:28 <http://archive.ubuntu.com/ubuntu> focal/main amd64 libffi-dev amd64 3.3-4 &#91;57.0 kB&#93;  
> Get:29 <http://archive.ubuntu.com/ubuntu> focal/main amd64 libpfm4 amd64 4.10.1+git20-g7700f49-2 &#91;266 kB&#93;  
> Get:30 <http://archive.ubuntu.com/ubuntu> focal-updates/main amd64 python3-pygments all 2.3.1+dfsg-1ubuntu2.2 &#91;579 kB&#93;  
> Get:31 <http://archive.ubuntu.com/ubuntu> focal/universe amd64 libz3-4 amd64 4.8.7-4build1 &#91;6,792 kB&#93;  
> Get:32 <http://archive.ubuntu.com/ubuntu> focal/universe amd64 libz3-dev amd64 4.8.7-4build1 &#91;67.5 kB&#93;  
> Get:2 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 libclang-cpp14 amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;11.0 MB&#93;  
> Get:4 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 libclang-common-14-dev amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;5,969 kB&#93;  
> Get:5 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 llvm-14-linker-tools amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;1,288 kB&#93;  
> Get:6 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 libclang1-14 amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;6,161 kB&#93;  
> Get:7 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 clang-14 amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;126 kB&#93;  
> Get:9 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 clangd-14 amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;2,738 kB&#93;  
> Get:10 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 liblldb-14 amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;3,637 kB&#93;  
> Get:11 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 lld-14 amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;1,192 kB&#93;  
> Get:12 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 llvm-14-runtime amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;494 kB&#93;  
> Get:13 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 llvm-14 amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;11.7 MB&#93;  
> Get:14 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 llvm-14-tools amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;429 kB&#93;  
> Get:15 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 llvm-14-dev amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;33.9 MB&#93;  
> Get:16 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 python3-lldb-14 amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;160 kB&#93;  
> Get:18 <https://apt.llvm.org/focal> llvm-toolchain-focal-14/main amd64 lldb-14 amd64 1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105 &#91;1,089 kB&#93;  
> Fetched 125 MB in 19s (6,739 kB/s)  
> Extracting templates from packages: 100%  
> Selecting previously unselected package binfmt-support.  
> (Reading database ... 319463 files and directories currently installed.)  
> Preparing to unpack .../00-binfmt-support_2.2.0-2_amd64.deb ...  
> Unpacking binfmt-support (2.2.0-2) ...  
> Selecting previously unselected package libllvm14:amd64.  
> Preparing to unpack .../01-libllvm14_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking libllvm14:amd64 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package libclang-cpp14.  
> Preparing to unpack .../02-libclang-cpp14_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking libclang-cpp14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package libstdc++-9-dev:amd64.  
> Preparing to unpack .../03-libstdc++-9-dev_9.4.0-1ubuntu1~20.04.1_amd64.deb ...  
> Unpacking libstdc++-9-dev:amd64 (9.4.0-1ubuntu1~20.04.1) ...  
> Selecting previously unselected package libobjc4:amd64.  
> Preparing to unpack .../04-libobjc4_10.3.0-1ubuntu1~20.04_amd64.deb ...  
> Unpacking libobjc4:amd64 (10.3.0-1ubuntu1~20.04) ...  
> Selecting previously unselected package libobjc-9-dev:amd64.  
> Preparing to unpack .../05-libobjc-9-dev_9.4.0-1ubuntu1~20.04.1_amd64.deb ...  
> Unpacking libobjc-9-dev:amd64 (9.4.0-1ubuntu1~20.04.1) ...  
> Selecting previously unselected package libc6-i386.  
> Preparing to unpack .../06-libc6-i386_2.31-0ubuntu9.7_amd64.deb ...  
> Unpacking libc6-i386 (2.31-0ubuntu9.7) ...  
> Selecting previously unselected package lib32gcc-s1.  
> Preparing to unpack .../07-lib32gcc-s1_10.3.0-1ubuntu1~20.04_amd64.deb ...  
> Unpacking lib32gcc-s1 (10.3.0-1ubuntu1~20.04) ...  
> Selecting previously unselected package lib32stdc++6.  
> Preparing to unpack .../08-lib32stdc++6_10.3.0-1ubuntu1~20.04_amd64.deb ...  
> Unpacking lib32stdc++6 (10.3.0-1ubuntu1~20.04) ...  
> Selecting previously unselected package libclang-common-14-dev.  
> Preparing to unpack .../09-libclang-common-14-dev_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking libclang-common-14-dev (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package llvm-14-linker-tools.  
> Preparing to unpack .../10-llvm-14-linker-tools_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking llvm-14-linker-tools (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package libclang1-14.  
> Preparing to unpack .../11-libclang1-14_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking libclang1-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package clang-14.  
> Preparing to unpack .../12-clang-14_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking clang-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package clangd-14.  
> Preparing to unpack .../13-clangd-14_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking clangd-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package icu-devtools.  
> Preparing to unpack .../14-icu-devtools_66.1-2ubuntu2.1_amd64.deb ...  
> Unpacking icu-devtools (66.1-2ubuntu2.1) ...  
> Selecting previously unselected package libicu-dev:amd64.  
> Preparing to unpack .../15-libicu-dev_66.1-2ubuntu2.1_amd64.deb ...  
> Unpacking libicu-dev:amd64 (66.1-2ubuntu2.1) ...  
> Selecting previously unselected package liblldb-14.  
> Preparing to unpack .../16-liblldb-14_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking liblldb-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package libncurses-dev:amd64.  
> Preparing to unpack .../17-libncurses-dev_6.2-0ubuntu2_amd64.deb ...  
> Unpacking libncurses-dev:amd64 (6.2-0ubuntu2) ...  
> Selecting previously unselected package libtinfo-dev:amd64.  
> Preparing to unpack .../18-libtinfo-dev_6.2-0ubuntu2_amd64.deb ...  
> Unpacking libtinfo-dev:amd64 (6.2-0ubuntu2) ...  
> Selecting previously unselected package libxml2-dev:amd64.  
> Preparing to unpack .../19-libxml2-dev_2.9.10+dfsg-5ubuntu0.20.04.2_amd64.deb ...  
> Unpacking libxml2-dev:amd64 (2.9.10+dfsg-5ubuntu0.20.04.2) ...  
> Selecting previously unselected package lld-14.  
> Preparing to unpack .../20-lld-14_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking lld-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package libffi-dev:amd64.  
> Preparing to unpack .../21-libffi-dev_3.3-4_amd64.deb ...  
> Unpacking libffi-dev:amd64 (3.3-4) ...  
> Selecting previously unselected package llvm-14-runtime.  
> Preparing to unpack .../22-llvm-14-runtime_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking llvm-14-runtime (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package libpfm4:amd64.  
> Preparing to unpack .../23-libpfm4_4.10.1+git20-g7700f49-2_amd64.deb ...  
> Unpacking libpfm4:amd64 (4.10.1+git20-g7700f49-2) ...  
> Selecting previously unselected package llvm-14.  
> Preparing to unpack .../24-llvm-14_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking llvm-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package python3-pygments.  
> Preparing to unpack .../25-python3-pygments_2.3.1+dfsg-1ubuntu2.2_all.deb ...  
> Unpacking python3-pygments (2.3.1+dfsg-1ubuntu2.2) ...  
> Selecting previously unselected package llvm-14-tools.  
> Preparing to unpack .../26-llvm-14-tools_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking llvm-14-tools (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package libz3-4:amd64.  
> Preparing to unpack .../27-libz3-4_4.8.7-4build1_amd64.deb ...  
> Unpacking libz3-4:amd64 (4.8.7-4build1) ...  
> Selecting previously unselected package libz3-dev:amd64.  
> Preparing to unpack .../28-libz3-dev_4.8.7-4build1_amd64.deb ...  
> Unpacking libz3-dev:amd64 (4.8.7-4build1) ...  
> Selecting previously unselected package llvm-14-dev.  
> Preparing to unpack .../29-llvm-14-dev_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking llvm-14-dev (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package python3-lldb-14.  
> Preparing to unpack .../30-python3-lldb-14_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking python3-lldb-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Selecting previously unselected package lldb-14.  
> Preparing to unpack .../31-lldb-14_1%3a14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105_amd64.deb ...  
> Unpacking lldb-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up libncurses-dev:amd64 (6.2-0ubuntu2) ...  
> Setting up libstdc++-9-dev:amd64 (9.4.0-1ubuntu1~20.04.1) ...  
> Setting up libobjc4:amd64 (10.3.0-1ubuntu1~20.04) ...  
> Setting up libffi-dev:amd64 (3.3-4) ...  
> Setting up python3-pygments (2.3.1+dfsg-1ubuntu2.2) ...  
> Setting up libz3-4:amd64 (4.8.7-4build1) ...  
> Setting up libpfm4:amd64 (4.10.1+git20-g7700f49-2) ...  
> Setting up binfmt-support (2.2.0-2) ...  
> Created symlink /etc/systemd/system/multi-user.target.wants/binfmt-support.service → /lib/systemd/system/binfmt-support.service.  
> Setting up icu-devtools (66.1-2ubuntu2.1) ...  
> Setting up libobjc-9-dev:amd64 (9.4.0-1ubuntu1~20.04.1) ...  
> Setting up libllvm14:amd64 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up libc6-i386 (2.31-0ubuntu9.7) ...  
> Setting up llvm-14-linker-tools (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up libicu-dev:amd64 (66.1-2ubuntu2.1) ...  
> Setting up llvm-14-tools (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up libtinfo-dev:amd64 (6.2-0ubuntu2) ...  
> Setting up libz3-dev:amd64 (4.8.7-4build1) ...  
> Setting up libclang1-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up libxml2-dev:amd64 (2.9.10+dfsg-5ubuntu0.20.04.2) ...  
> Setting up llvm-14-runtime (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up lib32gcc-s1 (10.3.0-1ubuntu1~20.04) ...  
> Setting up lib32stdc++6 (10.3.0-1ubuntu1~20.04) ...  
> Setting up libclang-common-14-dev (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up libclang-cpp14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up lld-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up clangd-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up liblldb-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up llvm-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up clang-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up python3-lldb-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up llvm-14-dev (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Setting up lldb-14 (1:14.0.0~++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105) ...  
> Processing triggers for man-db (2.9.1-1) ...  
> Processing triggers for install-info (6.7.0.dfsg.2-5) ...  
> Processing triggers for doc-base (0.10.9) ...  
> Processing 1 added doc-base file...  
> Processing triggers for libc-bin (2.31-0ubuntu9.7) ...  
> Processing triggers for systemd (245.4-4ubuntu3.15) ...  
> parallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$ clang-14 -v  
> Ubuntu clang version 14.0.0-++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105  
> Target: x86_64-pc-linux-gnu  
> Thread model: posix  
> InstalledDir: **/usr/bin**  
> Found candidate GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/9  
> Selected GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/9  
> Candidate multilib: .;@m64  
> Selected multilib: .;@m64  
> parallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$

...

{% endraw %}
