# Todo: Programming - Consider to write a C++ program and transpile to javascript using Emscrptem?

```#dcf1cc88``` *As of 2016-07-14 23:53*

[mail plain/text](mail.txt)

{% raw %}
Consider to try out the Emscriptem SDK by writing a simple C++ program and transpile it to Javascript for execution in the web browser?

1) Consider to document download and install of Emscriptem?

==&gt; The download seem to be published here (<https://s3.amazonaws.com/mozilla-games/emscripten/releases/emsdk-1.35.0-web-64bit.exe>)?

![](<Emscriptem 1.35 Unknown Publisher.tiff>)

Figure: Emscriptem installer is not signed (unknown publisher)

==&gt; The SDK installs to “C:\\Program Files\\Emscripten”

==&gt; The installer seem to download and unpack files from a remote host?

> Installing SDK 'sdk-1.35.0-64bit'..  
> Installing tool 'clang-e1.35.0-64bit'..  
> Downloading: C:/Program Files/Emscripten/zips/emscripten-clang_e1.35.0.zip from [**https://s3.amazonaws.com/mozilla-games/emscripten/packages/emscripten-clang_e1.35.0.zip](https://s3.amazonaws.com/mozilla-games/emscripten/packages/emscripten-clang_e1.35.0.zip)**  
> Unpacking 'C:/Program Files/Emscripten/zips/emscripten-clang_e1.35.0.zip' to 'C:/Program Files/Emscripten/clang/e1.35.0_64bit'  
> Done installing tool 'clang-e1.35.0-64bit'.  
> Installing tool 'node-4.1.1-64bit'..  
> Downloading: C:/Program Files/Emscripten/zips/node_4.1.1_64bit.zip from [**https://s3.amazonaws.com/mozilla-games/emscripten/packages/node_4.1.1_64bit.zip](https://s3.amazonaws.com/mozilla-games/emscripten/packages/node_4.1.1_64bit.zip)**  
> Unpacking 'C:/Program Files/Emscripten/zips/node_4.1.1_64bit.zip' to 'C:/Program Files/Emscripten/node/4.1.1_64bit'  
> Done installing tool 'node-4.1.1-64bit'.  
> Installing tool 'python-2.7.5.3-64bit'..  
> The contents of file '**python_2.7.5.3_64bit.zip**' **already exist** in destination 'C:/Program Files/Emscripten/python/2.7.5.3_64bit', skipping.  
> Done installing tool 'python-2.7.5.3-64bit'.  
> Installing tool 'emscripten-1.35.0'..  
> Downloading: C:/Program Files/Emscripten/zips/emscripten-1.35.0.zip from [**https://s3.amazonaws.com/mozilla-games/emscripten/packages/emscripten-1.35.0.zip](https://s3.amazonaws.com/mozilla-games/emscripten/packages/emscripten-1.35.0.zip)**  
> Unpacking 'C:/Program Files/Emscripten/zips/emscripten-1.35.0.zip' to 'C:/Program Files/Emscripten/emscripten/1.35.0’  
> ...

==&gt; It seems to install clang although I already have clang installed (or don’t I)?

==&gt; But it skips python_2.7.5.3_64bit.zip because it detects it already exists?

==&gt; Note: I may have failed to copy the whole script before it finished and closed?

==&gt; Install succeeded and I tried it out as the tutorial indicated.

> C:\\Users\\kjell-olovhogdahl\\Documents\\cpp\\MyEmcriptemPlayGround&gt;**emcc**  
> INFO:root:(Emscripten: Running sanity checks)  
> WARNING:root:no input files

> C:\\Users\\kjell-olovhogdahl\\Documents\\cpp\\MyEmcriptemPlayGround&gt;emxx  
> 'emxx' is not recognized as an internal or external command,  
> operable program or batch file.

> C:\\Users\\kjell-olovhogdahl\\Documents\\cpp\\MyEmcriptemPlayGround&gt;

==&gt; The command **emcc** seems to be installed ok?

2) Emscriptem seem to live here (<https://kripken.github.io/emscripten-site/index.html#>)?

==&gt; The tutorial seem to be here (<https://kripken.github.io/emscripten-site/docs/getting_started/Tutorial.html>)?

==&gt; Running emac -v seems to show the version of installed emscriptem compiler?

> C:\\Users\\kjell-olovhogdahl\\Documents\\cpp\\MyEmcriptemPlayGround&gt;emcc -v  
> emcc (Emscripten gcc/clang-like replacement + linker emulating GNU ld) 1.35.0  
> clang version 3.7.0 (<https://github.com/kripken/emscripten-fastcomp-clang> dbe68fecd03d6f646bd075963c3cc0e7130e5767) (<https://github.com/kripken/emscripten-fastcomp.git> 4e83be90903250ec5142edc57971ed4c633c5e25)  
> Target: x86_64-pc-windows-msvc  
> Thread model: posix  
> INFO:root:(Emscripten: Running sanity checks)

> C:\\Users\\kjell-olovhogdahl\\Documents\\cpp\\MyEmcriptemPlayGround&gt;

==&gt; I seem to have succeeded to create a hello world program as instructed by the tutorial?

> > C:\\Users\\kjell-olovhogdahl\\Documents\\cpp\\MyEmcriptemPlayGround&gt;touch hello_world.cpp

> > Touch Version 5.0 Copyright (c) 1995-2010 Embarcadero Technologies, Inc.  
> > C:\\Users\\kjell-olovhogdahl\\Documents\\cpp\\MyEmcriptemPlayGround&gt;

==&gt; I edited the created cpp-file and entered the basic hello world code.

==&gt; I then compiled it (it seem to succeed but with a lot of warnings)?

> > C:\\Users\\kjell-olovhogdahl\\Documents\\cpp\\MyEmcriptemPlayGround&gt;emcc hello_world.cpp

> > **WARNING:root:generating system library: libc.bc...**

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\dirent\\__getdents.c:12:1: warning: alias will

> > always resolve to __getdents even if weak definition of alias getdents is overridden &#91;-Wignored-attributes&#93;

> > LFS64(getdents);

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\libc.h:72:18: note: expanded from macro

> > 'LFS64'

> > #define LFS64(x) LFS64_2(x, x##64)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\libc.h:69:23: note: expanded from macro

> > 'LFS64_2'

> > #define LFS64_2(x, y) weak_alias(x, y)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\libc.h:66:48: note: expanded from macro

> > 'weak_alias'

> > extern __typeof(old) new __attribute__((weak, alias(#old)))

> > ^

> > 1 warning generated.

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\math\\fma.c:276:22: warning: ^ has lower

> > precedence than !=; != will be evaluated first &#91;-Wparentheses&#93;

> > if (bits_lost != 1 ^ (int)(uhi.i & 1)) {

> > ~~~~~~~~~~~~~~~^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\math\\fma.c:276:22: note: place parentheses around

> > the '!=' expression to silence this warning

> > if (bits_lost != 1 ^ (int)(uhi.i & 1)) {

> > ^

> > ( )

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\math\\fma.c:276:22: note: place parentheses around

> > the ^ expression to evaluate it first

> > if (bits_lost != 1 ^ (int)(uhi.i & 1)) {

> > ^

> > ( )

> > 1 warning generated.

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\mman\\mmap.c:40:1: warning: alias will always

> > resolve to __mmap even if weak definition of alias mmap is overridden &#91;-Wignored-attributes&#93;

> > LFS64(mmap);

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\libc.h:72:18: note: expanded from macro

> > 'LFS64'

> > #define LFS64(x) LFS64_2(x, x##64)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\libc.h:69:23: note: expanded from macro

> > 'LFS64_2'

> > #define LFS64_2(x, y) weak_alias(x, y)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\libc.h:66:48: note: expanded from macro

> > 'weak_alias'

> > extern __typeof(old) new __attribute__((weak, alias(#old)))

> > ^

> > 1 warning generated.

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\stat\\statvfs.c:62:1: warning: alias will always

> > resolve to __statfs even if weak definition of alias statfs is overridden &#91;-Wignored-attributes&#93;

> > LFS64(statfs);

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\libc.h:72:18: note: expanded from macro

> > 'LFS64'

> > #define LFS64(x) LFS64_2(x, x##64)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\libc.h:69:23: note: expanded from macro

> > 'LFS64_2'

> > #define LFS64_2(x, y) weak_alias(x, y)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\libc.h:66:48: note: expanded from macro

> > 'weak_alias'

> > extern __typeof(old) new __attribute__((weak, alias(#old)))

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\stat\\statvfs.c:64:1: warning: alias will always

> > resolve to __fstatfs even if weak definition of alias fstatfs is overridden &#91;-Wignored-attributes&#93;

> > LFS64(fstatfs);

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\libc.h:72:18: note: expanded from macro

> > 'LFS64'

> > #define LFS64(x) LFS64_2(x, x##64)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\libc.h:69:23: note: expanded from macro

> > 'LFS64_2'

> > #define LFS64_2(x, y) weak_alias(x, y)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\libc.h:66:48: note: expanded from macro

> > 'weak_alias'

> > extern __typeof(old) new __attribute__((weak, alias(#old)))

> > ^

> > 2 warnings generated.

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\stdio\\fseek.c:43:1: warning: alias will always

> > resolve to __fseeko even if weak definition of alias fseeko is overridden &#91;-Wignored-attributes&#93;

> > LFS64(fseeko);

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal/libc.h:72:18: note: expanded from macro

> > 'LFS64'

> > #define LFS64(x) LFS64_2(x, x##64)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal/libc.h:69:23: note: expanded from macro

> > 'LFS64_2'

> > #define LFS64_2(x, y) weak_alias(x, y)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal/libc.h:66:48: note: expanded from macro

> > 'weak_alias'

> > extern __typeof(old) new __attribute__((weak, alias(#old)))

> > ^

> > 1 warning generated.

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\stdio\\ftell.c:37:1: warning: alias will always

> > resolve to __ftello even if weak definition of alias ftello is overridden &#91;-Wignored-attributes&#93;

> > LFS64(ftello);

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal/libc.h:72:18: note: expanded from macro

> > 'LFS64'

> > #define LFS64(x) LFS64_2(x, x##64)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal/libc.h:69:23: note: expanded from macro

> > 'LFS64_2'

> > #define LFS64_2(x, y) weak_alias(x, y)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal/libc.h:66:48: note: expanded from macro

> > 'weak_alias'

> > extern __typeof(old) new __attribute__((weak, alias(#old)))

> > ^

> > 1 warning generated.

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\stdio\\__lockfile.c:14:1: warning: control reaches

> > end of non-void function &#91;-Wreturn-type&#93;

> > }

> > ^

> > 1 warning generated.

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\stdio\\__stdio_seek.c:7:37: warning: shift count

> > &gt;= width of type &#91;-Wshift-count-overflow&#93;

> > if (syscall(SYS__llseek, f-&gt;fd, off&gt;&gt;32, off, &ret, whence)&lt;0)

> > ^ ~~

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal/syscall.h:44:46: note: expanded from

> > macro 'syscall'

> > #define syscall(...) __syscall_ret(__syscall(__VA_ARGS__))

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal/syscall.h:41:53: note: expanded from

> > macro '__syscall'

> > #define __syscall(n, ...) __syscall_emscripten(n, ##__VA_ARGS__)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal/syscall.h:40:56: note: expanded from

> > macro '__syscall_emscripten'

> > #define __syscall_emscripten(n, ...) __syscall##n(n, ##__VA_ARGS__)

> > ^

> > 1 warning generated.

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\unistd\\lseek.c:9:40: warning: shift count &gt;=

> > width of type &#91;-Wshift-count-overflow&#93;

> > return syscall(SYS__llseek, fd, offset&gt;&gt;32, offset, &result, whence) ? -1 : result;

> > ^ ~~

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\syscall.h:44:46: note: expanded from

> > macro 'syscall'

> > #define syscall(...) __syscall_ret(__syscall(__VA_ARGS__))

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\syscall.h:41:53: note: expanded from

> > macro '__syscall'

> > #define __syscall(n, ...) __syscall_emscripten(n, ##__VA_ARGS__)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\syscall.h:40:56: note: expanded from

> > macro '__syscall_emscripten'

> > #define __syscall_emscripten(n, ...) __syscall##n(n, ##__VA_ARGS__)

> > ^

> > 1 warning generated.

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\unistd\\preadv.c:10:26: warning: shift count &gt;=

> > width of type &#91;-Wshift-count-overflow&#93;

> > (long)(ofs), (long)(ofs&gt;&gt;32));

> > ^ ~~

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\syscall.h:63:52: note: expanded from

> > macro 'syscall_cp'

> > #define syscall_cp(...) __syscall_ret(__syscall_cp(__VA_ARGS__))

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\syscall.h:60:37: note: expanded from

> > macro '__syscall_cp'

> > #define __syscall_cp(...) __syscall(__VA_ARGS__)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\syscall.h:41:53: note: expanded from

> > macro '__syscall'

> > #define __syscall(n, ...) __syscall_emscripten(n, ##__VA_ARGS__)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\syscall.h:40:56: note: expanded from

> > macro '__syscall_emscripten'

> > #define __syscall_emscripten(n, ...) __syscall##n(n, ##__VA_ARGS__)

> > ^

> > 1 warning generated.

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\unistd\\pwritev.c:10:26: warning: shift count &gt;=

> > width of type &#91;-Wshift-count-overflow&#93;

> > (long)(ofs), (long)(ofs&gt;&gt;32));

> > ^ ~~

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\syscall.h:63:52: note: expanded from

> > macro 'syscall_cp'

> > #define syscall_cp(...) __syscall_ret(__syscall_cp(__VA_ARGS__))

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\syscall.h:60:37: note: expanded from

> > macro '__syscall_cp'

> > #define __syscall_cp(...) __syscall(__VA_ARGS__)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\syscall.h:41:53: note: expanded from

> > macro '__syscall'

> > #define __syscall(n, ...) __syscall_emscripten(n, ##__VA_ARGS__)

> > ^

> > C:\\Program Files\\Emscripten\\emscripten\\1.35.0\\system\\lib\\libc\\musl\\src\\internal\\syscall.h:40:56: note: expanded from

> > macro '__syscall_emscripten'

> > #define __syscall_emscripten(n, ...) __syscall##n(n, ##__VA_ARGS__)

> > ^

> > 1 warning generated.

> > WARNING:root: ok

> > **WARNING:root:generating system library: dlmalloc.bc...**

> > WARNING:root: ok

> > C:\\Users\\kjell-olovhogdahl\\Documents\\cpp\\MyEmcriptemPlayGround&gt;

==&gt; But the file “a.out.js” was cerated ok!

==&gt; Note: I tried to execute it directly in the browser but gave up.

==&gt; To execute it I installed node.js (<http://nodejs.jp/nodejs.org_ja/download/>)

==&gt; I failed a couple of times until I found this download that seems to install ok (<https://nodejs.org/dist/v4.4.7/node-v4.4.7-x64.msi>)

==&gt; These failed or was insufficient!

==&gt; This seems to be the installer to use (<http://nodejs.org/dist/v0.11.11/x64/node-v0.11.11-x64.msi>)? NO!!! ==&gt; This one failed sector scan by windows!

==&gt; This seem to work through (<https://nodejs.org/dist/v4.4.7/win-x64/node.exe>)

==&gt; NOTE: It is a plain exe-file?!

==&gt; The installs seem tot install to “C:\\Program Files\\nodejs\\”?

![](<Node.js installer is code signed ok.tiff>)

==&gt; And the command is just node and the file to execute.

==&gt; Now I seem to be able to execute the generated javascript file using the node command?

> > C:\\Users\\kjell-olovhogdahl\\Documents\\cpp\\MyEmcriptemPlayGround&gt;**node a.out.js**

> > hello, world!

> > C:\\Users\\kjell-olovhogdahl\\Documents\\cpp\\MyEmcriptemPlayGround&gt;

==&gt; I also seem to be able to generate an html page to run the program in the browser?

> > C:\\Users\\kjell-olovhogdahl\\Documents\\cpp\\MyEmcriptemPlayGround&gt;emcc hello_world.cpp -o hello.html

> > C:\\Users\\kjell-olovhogdahl\\Documents\\cpp\\MyEmcriptemPlayGround&gt;

==&gt; And clicking the generated hello.html the program seems to run in the browser?

![](<Emscriptem Hello World in browser.tiff>)

…

Consider to delve deeper into Emscriptem programming, it seems fun and rewarding :)

...

{% endraw %}
