# Todo: Programming - Consider to study and list system tools to analyse C++ program performance on different platforms?

```#9edd1c4c``` *As of 2016-05-04 11:21*

[mail plain/text](mail.txt)

{% raw %}
Watching experienced programmers live-program on e.g., youtube it seems they know of and apply system tools to analyse performance of C++ programs?

1) Consider this clip by Jason Turner showing paralleled sorting och random integers (<https://www.youtube.com/watch?v=iCL6GYoi1RU>)?

==&gt; On Linux it seems we may use /usr/bin/time to run provided program and get a report of its run-time and CPU-usage?

> kjell-olovhogdahl@ubuntu:~$ /usr/bin/time  
> Usage: /usr/bin/time &#91;-apvV&#93; &#91;-f format&#93; &#91;-o file&#93; &#91;--append&#93; &#91;--verbose&#93;  
> &#91;--portability&#93; &#91;--format=format&#93; &#91;--output=file&#93; &#91;--version&#93;  
> &#91;--quiet&#93; &#91;--help&#93; command &#91;arg...&#93;  
> kjell-olovhogdahl@ubuntu:~$

==&gt; It seems to be available (in a slightly different flavour) on OS X also?

> Kjell-Olovs-MacBook-Pro:~ kjell-olovhogdahl$ /usr/bin/time  
> Kjell-Olovs-MacBook-Pro:~ kjell-olovhogdahl$ /usr/bin/time /usr/bin/time  
> 0.00 real 0.00 user 0.00 sys  
> Kjell-Olovs-MacBook-Pro:~ kjell-olovhogdahl$ /usr/bin/time -lp /usr/bin/time  
> real 0.00  
> user 0.00  
> sys 0.00  
> 675840 maximum resident set size  
> 0 average shared memory size  
> 0 average unshared data size  
> 0 average unshared stack size  
> 177 page reclaims  
> 0 page faults  
> 0 swaps  
> 0 block input operations  
> 0 block output operations  
> 0 messages sent  
> 0 messages received  
> 0 signals received  
> 0 voluntary context switches  
> 1 involuntary context switches  
> Kjell-Olovs-MacBook-Pro:~ kjell-olovhogdahl$ man time

> &#91;4&#93;+ Stopped man time  
> Kjell-Olovs-MacBook-Pro:~ kjell-olovhogdahl$

==&gt; The OS X version seems to be silent if no parameter is passed?

==&gt; On Linux there seem to be a file /proc/cpuinfo that carries information about the platform CPU?

> kjell-olovhogdahl@ubuntu:/proc$ cat cpuinfo  
> ... file content shown here...  
> kjell-olovhogdahl@ubuntu:/proc$

==&gt; He shows g++ (GCC) compiler switches for c++ standard version and optimisation?

g++ ./futures.cpp -std=c++14 -O3

==&gt; “-std=c++14” seem to mean “compile using c++14 language features”?

==&gt; -O3 seem to mean “Apply level 3 of optimisation”?

> kjell-olovhogdahl@ubuntu:~$ g++ --version  
> g++ (Ubuntu 5.3.1-14ubuntu2) 5.3.1 20160413  
> Copyright (C) 2015 Free Software Foundation, Inc.  
> This is free software; see the source for copying conditions. There is NO  
> warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

> kjell-olovhogdahl@ubuntu:~$

> kjell-olovhogdahl@ubuntu:~$ g++ --help=common | less  
> … help shown i less-mode …  
> -O&lt;number&gt; Set optimization level to &lt;number&gt;

> -Ofast Optimize for speed disregarding exact standards compliance

> -Og Optimize for debugging experience rather than speed or size

> -Os Optimize for space rather than speed  
> … help shown i less-mode …  
> &#91;3&#93;+ Stopped g++ --help=common | less  
> kjell-olovhogdahl@ubuntu:~$ ^C  
> kjell-olovhogdahl@ubuntu:~$

==&gt; The clang compiler dos NOT seem to mimic gcc optimisation options (no -O option)?

…

Consider to expand the list of good practices to use for c++ performance programming and analysing?

...

{% endraw %}
