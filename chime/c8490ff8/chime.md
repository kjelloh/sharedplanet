# Todo: Darwinet - Consider what Deltas we may have to evolve Immutable MIVs (e.g. new I:s can only be done with value provided)

```#c8490ff8``` *As of 2017-01-21 16:49*

[mail plain/text](mail.txt)

{% raw %}
So, what would it mean for Darwinet Deltas to be able to operate on Immutable MIVs?

1) Consider MIV being immutable means new M or I must be made with a provided value (can’t mutate later)?

==&gt; Consider this is a good thing as it defines that I Delta = new V must come with a value (We don’t need to allow default-construct + mutate)?  
==&gt; Consider the same goes for M Delta = new M

==&gt; Note that this corresponds to Immutable C++ types that can’t have a default constructor (they can only be cerated with its immutable value)  
…

…

Consider to elaborate more on these Delta aspects to operate on Immutable MIV insatnces?  
...

{% endraw %}
