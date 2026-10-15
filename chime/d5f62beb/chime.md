# Todo: Consider ways to compile C++20 with clang++-14 but link with g++-11 libstdc++?

```#d5f62beb``` *As of 2022-06-10 20:04*

[mail plain/text](mail.txt)

{% raw %}
I want to compile C++ code version 20 with clang but want to link with gnu libstdc++ instead och llvm libc++ as the latter lacks in c++20 support compared to the former.

==&gt; Also see "Todo: Consider to document how I installed unofficial (PPA) g++-11 on my Linux Mint 20.2 Cinnamon (macOS Paralells virtual machine)"

1) It seems in Linux the works?

> ```
> parallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$ clang++ -v -stdlib=libstdc++ -std=c++20 src/main.cpp
> Ubuntu clang version 14.0.0-++20220316013304+add3ab7f4c8a-1~exp1~20220316133356.105
> Target: x86_64-pc-linux-gnu
> Thread model: posix
> InstalledDir: /usr/lib/llvm-14/bin
> Found candidate GCC installation: /usr/lib/gcc/x86_64-linux-gnu/11
> Found candidate GCC installation: /usr/lib/gcc/x86_64-linux-gnu/9
> Selected GCC installation: /usr/lib/gcc/x86_64-linux-gnu/11
> Candidate multilib: .;@m64
> Selected multilib: .;@m64
>  "/usr/lib/llvm-14/bin/clang" -cc1 -triple x86_64-pc-linux-gnu -emit-obj -mrelax-all --mrelax-relocations -disable-free -clear-ast-before-backend -disable-llvm-verifier -discard-value-names -main-file-name main.cpp -mrelocation-model pic -pic-level 2 -pic-is-pie -mframe-pointer=all -fmath-errno -ffp-contract=on -fno-rounding-math -mconstructor-aliases -funwind-tables=2 -target-cpu x86-64 -tune-cpu generic -mllvm -treat-scalable-fixed-error-as-warning -debugger-tuning=gdb -v -fcoverage-compilation-dir=/home/parallels/github/cratchit -resource-dir /usr/lib/llvm-14/lib/clang/14.0.0 -internal-isystem /usr/lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11 -internal-isystem /usr/lib/gcc/x86_64-linux-gnu/11/../../../../include/x86_64-linux-gnu/c++/11 -internal-isystem /usr/lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/backward -internal-isystem /usr/lib/llvm-14/lib/clang/14.0.0/include -internal-isystem /usr/local/include -internal-isystem /usr/lib/gcc/x86_64-linux-gnu/11/../../../../x86_64-linux-gnu/include -internal-externc-isystem /usr/include/x86_64-linux-gnu -internal-externc-isystem /include -internal-externc-isystem /usr/include -std=c++20 -fdeprecated-macro -fdebug-compilation-dir=/home/parallels/github/cratchit -ferror-limit 19 -fgnuc-version=4.2.1 -fno-implicit-modules -fcxx-exceptions -fexceptions -fcolor-diagnostics -faddrsig -D__GCC_HAVE_DWARF2_CFI_ASM=1 -o /tmp/main-dbe548.o -x c++ src/main.cpp
> clang -cc1 version 14.0.0 based upon LLVM 14.0.0 default target x86_64-pc-linux-gnu
> ignoring nonexistent directory "/usr/lib/gcc/x86_64-linux-gnu/11/../../../../x86_64-linux-gnu/include"
> ignoring nonexistent directory "/include"
> #include "..." search starts here:
> #include <...> search starts here:
>  /usr/lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11
>  /usr/lib/gcc/x86_64-linux-gnu/11/../../../../include/x86_64-linux-gnu/c++/11
>  /usr/lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/backward
>  /usr/lib/llvm-14/lib/clang/14.0.0/include
>  /usr/local/include
>  /usr/include/x86_64-linux-gnu
>  /usr/include
> End of search list.
>  "/usr/bin/ld" -pie --hash-style=both --build-id --eh-frame-hdr -m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2 -o a.out /lib/x86_64-linux-gnu/Scrt1.o /lib/x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/11/crtbeginS.o -L/usr/lib/gcc/x86_64-linux-gnu/11 -L/usr/lib/gcc/x86_64-linux-gnu/11/../../../../lib64 -L/lib/x86_64-linux-gnu -L/lib/../lib64 -L/usr/lib/x86_64-linux-gnu -L/usr/lib/../lib64 -L/usr/lib/llvm-14/bin/../lib -L/lib -L/usr/lib /tmp/main-dbe548.o -lstdc++ -lm -lgcc_s -lgcc -lc -lgcc_s -lgcc /usr/lib/gcc/x86_64-linux-gnu/11/crtendS.o /lib/x86_64-linux-gnu/crtn.o
> parallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$ ls
> a.out  bclang++13.sh  bclang++14.sh  bg++11.sh  cratchit.env  cratchit.out  cratchit.se<http://cratchit.se>  LICENSE  README.md  resources  src  to_bolagsverket
> parallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$ ls src
> main.cpp  sie
> parallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$ ls -la
> total 7216
> drwxrwxr-x 8 parallels parallels    4096 Jun 10 19:13 .
> drwxrwxr-x 3 parallels parallels    4096 Mar 28 17:03 ..
> -rwxrwxr-x 1 parallels parallels 3469768 Jun 10 19:13 a.out
> -rwxrwxr-x 1 parallels parallels     152 May  7 18:13 bclang++13.sh
> -rwxrwxr-x 1 parallels parallels      90 May  7 18:25 bclang++14.sh
> -rwxrwxr-x 1 parallels parallels     129 May  7 18:13 bg++11.sh
> -rw-rw-r-- 1 parallels parallels     122 Jun  6 16:51 cratchit.env
> -rwxrwxr-x 1 parallels parallels 3802304 Jun  6 16:55 cratchit.out
> -rw-rw-r-- 1 parallels parallels      14 Jun  6 16:51 cratchit.se<http://cratchit.se>
> drwxrwxr-x 8 parallels parallels    4096 Jun  6 16:56 .git
> -rw-rw-r-- 1 parallels parallels    4211 Mar 28 20:17 .gitignore
> -rw-rw-r-- 1 parallels parallels   35141 Mar 28 17:03 LICENSE
> -rw-rw-r-- 1 parallels parallels    8287 Mar 28 17:03 README.md
> drwxrwxr-x 2 parallels parallels    4096 May  7 18:10 resources
> drwxrwxr-x 3 parallels parallels    4096 Jun  6 16:28 src
> drwxrwxr-x 6 parallels parallels    4096 Jun  6 16:29 to_bolagsverket
> drwxrwxr-x 2 parallels parallels    4096 Mar 28 20:17 .vs
> drwxrwxr-x 2 parallels parallels    4096 May  7 18:10 .vscode
> parallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$ ./a.out

> Init from "/home/parallels/github/cratchit/cratchit.env"
> cratchit:>q

> By for now :)parallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$

> ```

  
2) It seems I can trace the #include tree with the compiler option -E (and pipe to a text file for view)?

> ```
> clang++ -v -stdlib=libstdc++ -std=c++20 src/main.cpp -E > cratchit_raw.txt
> ```

  
==&gt; So, for example I can in this way find why #include &lt;source_location&gt; (of gnu libstdc++ header) works but results in an empty include when compiled with clang++-14?

> // In produced cratchit_raw.txt  
> ...  
> # 32 "src/main.cpp" 2  
> # 1 "/usr/lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/source_location" 1 3  
> # 33 "src/main.cpp" 2  
> ...

> // In actual /usr/lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/source_location file  
> ...  
> #if __cplusplus &gt; 201703L && __has_builtin(__builtin_source_location)  
> ...

==&gt; So, we can conclude that clang++-14 does NOT have "built in source location" (__has_builtin(__builtin_source_location) is false)?

==&gt; It seems we find the content of the gnu libstdc++ header &lt;source_location&gt; in **/usr/include/c++/11**

  
> ```
> parallels@parallels-Parallels-Virtual-Platform:~/github/cratchit$ cd /usr/lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11
> parallels@parallels-Parallels-Virtual-Platform:/usr/include/c++/11$ pwd
> /usr/include/c++/11
> parallels@parallels-Parallels-Virtual-Platform:/usr/include/c++/11$ cat source_location
> // <source_location> -*- C++ -*-

> // Copyright (C) 2020-2021 Free Software Foundation, Inc.
> //
> // This file is part of the GNU ISO C++ Library.  This library is free
> // software; you can redistribute it and/or modify it under the
> // terms of the GNU General Public License as published by the
> // Free Software Foundation; either version 3, or (at your option)
> // any later version.

> // This library is distributed in the hope that it will be useful,
> // but WITHOUT ANY WARRANTY; without even the implied warranty of
> // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
> // GNU General Public License for more details.

> // Under Section 7 of GPL version 3, you are granted additional
> // permissions described in the GCC Runtime Library Exception, version
> // 3.1, as published by the Free Software Foundation.

> // You should have received a copy of the GNU General Public License and
> // a copy of the GCC Runtime Library Exception along with this program;
> // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
> // <http://www.gnu.org/licenses/<http://www.gnu.org/licenses/>>.

> /** @file include/source_location
>  *  This is a Standard C++ Library header.
>  */

> #ifndef _GLIBCXX_SRCLOC
> #define _GLIBCXX_SRCLOC 1

> #if __cplusplus > 201703L && __has_builtin(__builtin_source_location)
> #include <bits/c++config.h>

> namespace std
> {
> _GLIBCXX_BEGIN_NAMESPACE_VERSION

> #define __cpp_lib_source_location 201907L

>   /// A class that describes a location in source code.
>   struct source_location
>   {
>   private:
>     using uint_least32_t = __UINT_LEAST32_TYPE__;

>   public:

>     // [support.srcloc.cons], creation
>     static consteval source_location
>     current(const void* __p = __builtin_source_location()) noexcept
>     {
>       source_location __ret;
>       __ret._M_impl = static_cast <const __impl*>(__p);
>       return __ret;
>     }

>     constexpr source_location() noexcept { }

>     // [support.srcloc.obs], observers
>     constexpr uint_least32_t
>     line() const noexcept
>     { return _M_impl ? _M_impl->_M_line : 0u; }

>     constexpr uint_least32_t
>     column() const noexcept
>     { return _M_impl ? _M_impl->_M_column : 0u; }

>     constexpr const char*
>     file_name() const noexcept
>     { return _M_impl ? _M_impl->_M_file_name : ""; }

>     constexpr const char*
>     function_name() const noexcept
>     { return _M_impl ? _M_impl->_M_function_name : ""; }

>   private:
>     struct __impl
>     {
>       const char* _M_file_name;
>       const char* _M_function_name;
>       unsigned _M_line;
>       unsigned _M_column;
>     };

>     const __impl* _M_impl = nullptr;
>   };

> _GLIBCXX_END_NAMESPACE_VERSION
> } // namespace std
> #endif // C++20 && __builtin_source_location
> #endif // _GLIBCXX_SRCLOC
> parallels@parallels-Parallels-Virtual-Platform:/usr/include/c++/11$
> ```



...

{% endraw %}
