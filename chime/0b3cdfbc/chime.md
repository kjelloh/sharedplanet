# Todo: Consider to document how I installed unofficial (PPA) g++-13 on my Linux Mint 20.2 Cinnamon (macOS Parallels virtual machine)

```#0b3cdfbc``` *As of 2023-12-16 22:16*

[mail plain/text](mail.txt)

{% raw %}
I want to compile C++20 with Clang using Gny libstdc++ on Linux.

==&gt; Also see "[Todo: Consider to document how I installed unofficial (PPA) g++-11 on my Linux Mint 20.2 Cinnamon (macOS Paralells virtual machine)](../dea7bb7d/chime.md)"

1) It seems I can use "apt install" from a PPA to get g++-13 installed as the latest gcc and libstdc++ release?

==&gt; It seems I can use the PPA **ppa:ubuntu-toolchain-r/test**?

*Note: I used "Copy as HTML" in Ubuntu Mint to copy-paste with colours and formatting to this mail in macOS*

  
> ```
> parallels@parallels-Parallels-Virtual-Platform:~$ sudo add-apt-repository ppa:ubuntu-toolchain-r/test
> You are about to add the following PPA:
>  Toolchain test builds; see https://wiki.ubuntu.com/ToolChain<https://wiki.ubuntu.com/ToolChain>

>  More info: https://launchpad.net/~ubuntu-toolchain-r/+archive/ubuntu/test<https://launchpad.net/~ubuntu-toolchain-r/+archive/ubuntu/test>
> Press Enter to continue or Ctrl+C to cancel

> Executing: /tmp/apt-key-gpghome.upjTUGkstp/gpg.1.sh --keyserver hkps://keyserver.ubuntu.com:443<hkps://keyserver.ubuntu.com:443> --recv-keys 60C317803A41BA51845E371A1E9377A2BA9EF27F
> gpg: key 1E9377A2BA9EF27F: "Launchpad Toolchain builds" not changed
> gpg: Total number processed: 1
> gpg:              unchanged: 1
> parallels@parallels-Parallels-Virtual-Platform:~$ sudo apt install g++-13

> ```



==&gt; It seems I can now install the gnu g++-11 package using the apt installer?

> ```

> ```
> parallels@parallels-Parallels-Virtual-Platform:~$ sudo apt install g++-13
> Reading package lists... Done
> Building dependency tree
> Reading state information... Done
> The following additional packages will be installed:
>   cpp-13 gcc-13 gcc-13-base libasan8 libatomic1 libcc1-0 libgcc-13-dev
>   libgcc-s1 libgomp1 libhwasan0 libitm1 liblsan0 libquadmath0 libstdc++-13-dev
>   libstdc++6 libtsan2 libubsan1
> Suggested packages:
>   gcc-13-locales cpp-13-doc g++-13-multilib gcc-13-doc gcc-13-multilib
>   libstdc++-13-doc
> The following NEW packages will be installed:
>   cpp-13 g++-13 gcc-13 gcc-13-base libasan8 libgcc-13-dev libhwasan0
>   libstdc++-13-dev libtsan2
> The following packages will be upgraded:
>   libatomic1 libcc1-0 libgcc-s1 libgomp1 libitm1 liblsan0 libquadmath0
>   libstdc++6 libubsan1
> 9 upgraded, 9 newly installed, 0 to remove and 523 not upgraded.
> Need to get 215 MB of archives.
> After this operation, 958 MB of additional disk space will be used.
> Do you want to continue? [Y/n] Y
> Get:1 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 gcc-13-base amd64 13.1.0-8ubuntu1~20.04.2 [19.1 kB]
> Get:2 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 libgcc-s1 amd64 13.1.0-8ubuntu1~20.04.2 [58.3 kB]
> Get:3 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 libstdc++6 amd64 13.1.0-8ubuntu1~20.04.2 [708 kB]
> Get:4 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 cpp-13 amd64 13.1.0-8ubuntu1~20.04.2 [62.3 MB]
> Get:5 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 libcc1-0 amd64 13.1.0-8ubuntu1~20.04.2 [44.0 kB]
> Get:6 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 libgomp1 amd64 13.1.0-8ubuntu1~20.04.2 [127 kB]
> Get:7 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 libitm1 amd64 13.1.0-8ubuntu1~20.04.2 [26.5 kB]
> Get:8 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 libatomic1 amd64 13.1.0-8ubuntu1~20.04.2 [9,596 B]
> Get:9 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 libasan8 amd64 13.1.0-8ubuntu1~20.04.2 [2,704 kB]
> Get:10 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 liblsan0 amd64 13.1.0-8ubuntu1~20.04.2 [1,112 kB]
> Get:11 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 libtsan2 amd64 13.1.0-8ubuntu1~20.04.2 [2,359 kB]
> Get:12 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 libubsan1 amd64 13.1.0-8ubuntu1~20.04.2 [1,021 kB]
> Get:13 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 libhwasan0 amd64 13.1.0-8ubuntu1~20.04.2 [1,166 kB]
> Get:14 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 libquadmath0 amd64 13.1.0-8ubuntu1~20.04.2 [146 kB]
> Get:15 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 libgcc-13-dev amd64 13.1.0-8ubuntu1~20.04.2 [2,550 kB]
> Get:16 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 gcc-13 amd64 13.1.0-8ubuntu1~20.04.2 [71.3 MB]
> Get:17 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 libstdc++-13-dev amd64 13.1.0-8ubuntu1~20.04.2 [2,221 kB]
> Get:18 http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu<http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu> focal/main amd64 g++-13 amd64 13.1.0-8ubuntu1~20.04.2 [67.4 MB]
> Fetched 215 MB in 30s (7,059 kB/s)
> Selecting previously unselected package gcc-13-base:amd64.
> (Reading database ... 442835 files and directories currently installed.)
> Preparing to unpack .../gcc-13-base_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking gcc-13-base:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up gcc-13-base:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> (Reading database ... 442840 files and directories currently installed.)
> Preparing to unpack .../libgcc-s1_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking libgcc-s1:amd64 (13.1.0-8ubuntu1~20.04.2) over (11.1.0-1ubuntu1~20.04) ...
> Setting up libgcc-s1:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> (Reading database ... 442840 files and directories currently installed.)
> Preparing to unpack .../libstdc++6_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking libstdc++6:amd64 (13.1.0-8ubuntu1~20.04.2) over (11.1.0-1ubuntu1~20.04) ...
> Setting up libstdc++6:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Selecting previously unselected package cpp-13.
> (Reading database ... 442840 files and directories currently installed.)
> Preparing to unpack .../00-cpp-13_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking cpp-13 (13.1.0-8ubuntu1~20.04.2) ...
> Preparing to unpack .../01-libcc1-0_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking libcc1-0:amd64 (13.1.0-8ubuntu1~20.04.2) over (11.1.0-1ubuntu1~20.04) ...
> Preparing to unpack .../02-libgomp1_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking libgomp1:amd64 (13.1.0-8ubuntu1~20.04.2) over (11.1.0-1ubuntu1~20.04) ...
> Preparing to unpack .../03-libitm1_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking libitm1:amd64 (13.1.0-8ubuntu1~20.04.2) over (11.1.0-1ubuntu1~20.04) ...
> Preparing to unpack .../04-libatomic1_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking libatomic1:amd64 (13.1.0-8ubuntu1~20.04.2) over (11.1.0-1ubuntu1~20.04) ...
> Selecting previously unselected package libasan8:amd64.
> Preparing to unpack .../05-libasan8_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking libasan8:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Preparing to unpack .../06-liblsan0_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking liblsan0:amd64 (13.1.0-8ubuntu1~20.04.2) over (11.1.0-1ubuntu1~20.04) ...
> Selecting previously unselected package libtsan2:amd64.
> Preparing to unpack .../07-libtsan2_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking libtsan2:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Preparing to unpack .../08-libubsan1_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking libubsan1:amd64 (13.1.0-8ubuntu1~20.04.2) over (11.1.0-1ubuntu1~20.04) ...
> Selecting previously unselected package libhwasan0:amd64.
> Preparing to unpack .../09-libhwasan0_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking libhwasan0:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Preparing to unpack .../10-libquadmath0_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking libquadmath0:amd64 (13.1.0-8ubuntu1~20.04.2) over (11.1.0-1ubuntu1~20.04) ...
> Selecting previously unselected package libgcc-13-dev:amd64.
> Preparing to unpack .../11-libgcc-13-dev_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking libgcc-13-dev:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Selecting previously unselected package gcc-13.
> Preparing to unpack .../12-gcc-13_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking gcc-13 (13.1.0-8ubuntu1~20.04.2) ...
> Selecting previously unselected package libstdc++-13-dev:amd64.
> Preparing to unpack .../13-libstdc++-13-dev_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking libstdc++-13-dev:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Selecting previously unselected package g++-13.
> Preparing to unpack .../14-g++-13_13.1.0-8ubuntu1~20.04.2_amd64.deb ...
> Unpacking g++-13 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up cpp-13 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up libgomp1:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up libquadmath0:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up libatomic1:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up libubsan1:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up libhwasan0:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up libasan8:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up libtsan2:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up libcc1-0:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up liblsan0:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up libitm1:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up libgcc-13-dev:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up libstdc++-13-dev:amd64 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up gcc-13 (13.1.0-8ubuntu1~20.04.2) ...
> Setting up g++-13 (13.1.0-8ubuntu1~20.04.2) ...
> Processing triggers for man-db (2.9.1-1) ...
> Processing triggers for libc-bin (2.31-0ubuntu9.7) ...
> parallels@parallels-Parallels-Virtual-Platform:~$
> ```

> ```



2) Consider to document how the GCC compiler version 13 gets installed and configured by apt when installed to my Mint virtual machine?

==&gt; It seems the command g++-13 gets installed to **/usr/bin**/g++-13?

> ```
> parallels@parallels-Parallels-Virtual-Platform:~$ g++-13 -v
> Using built-in specs.
> COLLECT_GCC=g++-13
> COLLECT_LTO_WRAPPER=/usr/libexec/gcc/x86_64-linux-gnu/13/lto-wrapper
> Target: x86_64-linux-gnu
> Configured with: ../src/configure -v --with-pkgversion='Ubuntu 13.1.0-8ubuntu1~20.04.2' --with-bugurl=file:///usr/share/doc/gcc-13/README.Bugs<file:///usr/share/doc/gcc-13/README.Bugs> --enable-languages=c,ada,c++,go,d,fortran,objc,obj-c++,m2,rust --prefix=/usr --with-gcc-major-version-only --program-suffix=-13 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/libexec --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --enable-libphobos-checking=release --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --enable-cet --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
> Thread model: posix
> Supported LTO compression algorithms: zlib zstd
> gcc version 13.1.0 (Ubuntu 13.1.0-8ubuntu1~20.04.2)
> parallels@parallels-Parallels-Virtual-Platform:~$

> ```

> ```

> ```
> parallels@parallels-Parallels-Virtual-Platform:~$ which g++-13
> /usr/bin/g++-13
> parallels@parallels-Parallels-Virtual-Platform:~$ ls -la /usr/bin/g++-13
> lrwxrwxrwx 1 root root 23 Jul 11 10:50 /usr/bin/g++-13 -> x86_64-linux-gnu-g++-13
> parallels@parallels-Parallels-Virtual-Platform:~$ ls -la /usr/bin/x86_64-linux-gnu-g++-13
> -rwxr-xr-x 1 root root 1752352 Jul 11 10:50 /usr/bin/x86_64-linux-gnu-g++-13
> parallels@parallels-Parallels-Virtual-Platform:~$
> ```

> ```



...

{% endraw %}
