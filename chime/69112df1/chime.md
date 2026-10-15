# Todo: Programming - Consider to use the C++ ternary operator 32 bit optimisation as an example of "meaning" versus "encoding"?

```#69112df1``` *As of 2016-06-15 12:04*

[mail plain/text](mail.txt)

{% raw %}
Watching the Visual Studio 2016 Update 3 optimisation features for the ternary operator I come to think this could be a good example of “meaning” versus “encoding”?

1) The C++ ternary operator optimisation is mentioned at 14:15 into (<https://channel9.msdn.com/Shows/C9-GoingNative/GoingNative-50-New-Visual-C-Code-Optimizer>)

Expression:  int b = (a&lt;0)?1:0;

Optimised:  int b = a&gt;&gt;31;

==&gt; This optimisation works on 32 bit machine as a shifted 31 bits to the right will have the “sign bit” remaining (32 bit two complements implementation of negative numbers).

2) Consider how the intention or “meaning” is to assign b with 1 if a is negative but how b assigned to a right shifted 31 bits does not convey this?

==&gt; Consider this to be an example of how the “meaning” (the intention of the statement from the programmers point of view) is not conveyed from the “encoding” of the statement?

“Meaning": if (a &lt; 0) then b=1 else b=0;

“Encoding”: b = a&gt;&gt;31;

3) Consider to find more examples of code that is written (encoded) in a way so that the intention (meaning) is hidden?

==&gt; Is in fact all programming examples of “hiding” of intention (but as a programmer you recognise the intention as design patterns)?

…

4) Consider coding design patterns as “good encodings” that programmers may learn to use and recognise as intention (i.e, “meaning”)?

…

5) Consider C++ String-encoding as an example where string manipulation semantics “mean” one thing but where encoding breaks the code from working?

==&gt; Consider std::find on UTF-8 string “Välkommen” to find location of letter ‘ä’?

...

…

Consider to elaborate on this idea and optionally write a blog-post about this thinking and how to apply it to programming?

...

{% endraw %}
