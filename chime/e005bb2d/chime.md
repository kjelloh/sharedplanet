# Todo: Programming - Consider to implement services to pipe text through platform console commands (process stdin ==&gt; stdout) as a C++ open source library?

```#e005bb2d``` *As of 2016-07-27 18:31*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to implement a C++ library where one easily can create system processes to execute console commands and stream text through them in a “piping” manner?

1) Consider a good name for such a library?

==&gt; Consider a name that refers to “streaming”, “piping” and putting head-to-tail of such pipes?  
==&gt; Consider the name “Mario” (as a reference to the famous plumber in the game with the same name)  
…

2) Consider to have this processes implement streaming operators?

==&gt; Consider: process &lt;&lt; “Hello”; ?  
==&gt; Consider: process &gt;&gt; sText; ?

==&gt; Consider the streams to be lazy?

==&gt; Consider a lazy stream that is being read consumes data on read?  
==&gt; Consider for a lazy stream a write does nothing but bind the written data to the stream for later reading?  
==&gt; Consider written data to be owned by the stream to which it has been written (the written data is not deleted on destruction of the source of the written data)?  
…

3) Or - consider to have processes implement the pipe ‘|’ operator?

==&gt; Consider it should be possible to do: sMyString | Process(“grep”,”hello”) | sMyResult; ?  
==&gt; Consider to have the piping operator operate on an java-like iterator with “has_next” member?

==&gt; Consider to not use nibblers ranges idiom with sentinel-iterator?  
==&gt; Consider the motivation is that a stream is NOT a range.  
==&gt; Consider a Range is always of known size?  
...

4) Consider the processes to always be managed asynchronously?

==&gt; Consider process creation is asynchronously execution (non blocking construction)?  
==&gt; Consider stream and pipe binding to compile-time detect thread boundaries and generate thread messaging when required automatically?

==&gt; Consider the asynchronous execution of processes to be used to “give up” on time out (unresponsive processes)?  
…

5) Consider a process can take start parameters and provide an services to bind to a lazy input and output stream?

==&gt; Consider it must be possible to: sMyString &gt;&gt; Process(“grep”,”hello”) &gt;&gt; sMyResult; ?

==&gt; Considere the process to provide a “write file handle” to bind to its “input stream” (we may write to the process in this way)?  
==&gt; Consider the process to provide a “Read file handle” to bind to its “output stream” (we may read from the process in this way)?  
...

…

Consider to elaborate on this idea to provide a neat interface to the platform console commands and ability to pipe such command together for text processing?  
...

{% endraw %}
