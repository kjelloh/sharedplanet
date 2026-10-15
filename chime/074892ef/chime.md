# Todo: Programming - Consider to study the two Range concepts Iterator and Generator?

```#074892ef``` *As of 2016-07-14 20:31*

[mail plain/text](mail.txt)

{% raw %}
What can we learn from the idea that Ranges may actually be traversed using Iterator (Consumer driven) or using Generators (Producer driven)?

==&gt; Also see “[Todo: Programming - Consider to argue that Generators reflect structure in code whilst Iterators reflect structure in state?](../325f464b/chime.md)"

1) This seem like a good talk by Arno Schöld where this idea is presented and explained (<https://www.youtube.com/watch?v=vrCtS6FDay8>)?

==&gt; The Iterator concept means the Consumer is at bottom of stack calling the Iterator for Range members.

==&gt; Iterator must carry state and can’t use stack variables for storage.

==&gt; Iterating complex structures can be close to impossible and inefficient (restore state on each call)

==&gt; The Generator concept means the Producer (generator) is at bottom of stack calling the Consumer with Range Members.

==&gt; Generators can traverse structure in code (“State” mirrored in code)

==&gt; Generators can use stack variables.

==&gt; Consumer can be cheap to call (only need to act on provided range member)

==&gt; Consider to study how Generators can be made into Coroutines (pros and cons) (In the talk)

2) What can we say from comparing different prominent “Range” related C++ concepts?

==&gt; Consider Arno Schöld idiom and think-cell open source range library on github (<https://github.com/think-cell/range>)?

==&gt; At 4:30

==&gt; Conatiners are Ranges (owns elements, deep copying, deep constness)

==&gt; Views are basically begin/end iterator pairs (don’t own elements, shallow copying, shallow constness)

==&gt; At 6:30

==&gt; Range Adaptors (More interesting Views)

==&gt; Example “adapting” a Range of records into a Range of int members of each record.

==&gt; The Adaptor Range is lazy so nothing is created (adaption happens on access, i.e. the referenced record member int is returned).

==&gt; The Adaptor has a member base() that returns a reference to the “un-adapted” element reference (in this case the record)

==&gt; At 12:20 Key Point of self-sufficient adaptors creating large storage overhead.

==&gt; adaptor of adaptor of adaptor replicates functor and iterators (each adaptors self-sufficient)

==&gt; Boost::Ranges does this.

==&gt; At 13:20

==&gt; Enhance by having iterator point to range and base iterator

==&gt; Adaptor only carry common functor and end iterator.

==&gt; Consequence - Iterator life span restricted to Range life-span.

==&gt; State-of-the-art (Nibblers Range v3 does this)

==&gt; Still not great (still linear overhead)

==&gt; At 14:15 - The “Index” concept.

==&gt; All Index operations gets the Range as input (enables single storage location of Range)

==&gt; An Index-range uses Index as Begin/End (removes need to store self-sufficient iterators)

==&gt; Add increment/decrement index to the index range.

==&gt; Possible to co-exist with the “world” of Iterator Ranges.

==&gt; Key point - The Index type can be shared by base range and adapted range.

==&gt; At 20:11 - think-cell rvalue handling

==&gt; v3 does not allow creating a view to a temporary created range (the view must reference an existing range)

==&gt; think-cell ranges aggregates (move) the container when provided a temporary one (called with rvalue)

==&gt; think-cell range thus remains lazy.

**WE ARE HERE … 20:45**

==&gt; Consider Eric Niebler Range v3 (See “Todo: Programming - Consider to follow up and understand Eric Nibblers C++ Ranges concepts for the standard?”)?

==&gt; Consider Boost::Range (2.0 seem to be part of 1.59 <http://www.boost.org/doc/libs/1_59_0/libs/range/doc/html/index.html>)?

“ A Range is a concept similar to the STL Container concept.

A Range provides iterators for accessing a half-open range &#91;first,one_past_last) of elements

and provides information about the number of elements in the Range.

However, a Range has fewer requirements than a Container.”

“a Range

• does not necessarily own the elements that can be accessed through it,

• does not necessarily have copy semantics,"

3) Consider to delve into what the generator idea could mean to OPrime encode/Decode idioms?

==&gt; Could we imagine Encoder and Decoder to be Generators based on DSL-defined Element Tables?

…

Consider to delve into this aspect of Ranges to provide Iteraton and/or Generation and the pros and cons of the two approaches?

...

{% endraw %}
