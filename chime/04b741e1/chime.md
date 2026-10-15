# Todo: Meta Value Model - Consider to design a scripting REPL to try out the Meta Model implementation?

```#04b741e1``` *As of 2017-06-11 20:28*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to design a REPL (Read Evaluate Print Loop) to try out the Meta Model implementation using scripting?

1) Consider to compare with Clojure REPL (<https://clojure.org/about/dynamic>)?

...

2) Consider a REPL with a prompt that shows the current Meta Value level?

==&gt; Consider ”meta-0” is the bottom value level?

meta-0&gt;

==&gt; Consider ”meta-x” as the command to enter a new meta-level?

meta-0&gt;meta-1

meta-1&gt;

3) Consider to mimic a file directory structure for the Path into the Meta Model?

==&gt; Consider the prompt then shows the current location (Meta Value Path)?

meta-0&gt;cd /meta-1

meta-1&gt;ls

\* Listing of meta-1 names

number = darwinet_type ”number"

text = darwinet_type ”text”

meta-1&gt;my_record : record {{name: text}, {value:number}} = {name=”entry1”, value=5}

my_record = record {name = ”entry1”, value=5}

meta-1&gt;

…

4) Consider a root called miv?

miv/meta-0&gt;cd /miv

miv&gt;ls

meta-0

meta-1

meta-2

miv&gt;

5) Consider miv and meta-x ”folders” are also Meta-values?

==&gt; How can we imagine miv and meta-x to be of some basic meta-value?

==&gt; It would seem for the ”File System Metaphor” we need the meta-levels to nest?

miv&gt;cd meta-0

miv/meta-0&gt;cd meta-1

miv/meta-0/meta-1&gt;

**==&gt; In fact it seems we need each meta-level to be a subfolder named ”meta"?**

&gt;cd meta

meta&gt;cd meta

meta/meta&gt;ls

\* Listing of meta/meta \*

darwinet_type = {number, text, array, record}

meta/meta&gt;

…

Consider to elaborate on the design of a possible REPL to work with a Meta Model implementation (to test it out)?

...

{% endraw %}
