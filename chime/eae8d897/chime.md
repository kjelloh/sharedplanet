# Todo: Programming - Consider to check out the C++ Immutable Data Structures Library "Immer" and possibly if to use it with Darwinet implementation?

```#eae8d897``` *As of 2016-12-02 14:11*

[mail plain/text](mail.txt)

{% raw %}
The Immutable Data STructures C++ library ”Immer” seems to implement a good value-semantics and history-state idiom interesting in itself but also kind of relates to the Dartwinet asynchronous shared-state idea?

1) The C++ immutable containers library Immer seems to live here (<https://sinusoid.es/immer/>)?

2) Consider how Immutable Data Structures sharing ”shared unchanged state” on mutation correlates to Darwinet doign the same thing?

==&gt; A Darwinet MIV state change shares the state of all uncganged members (only the mutated element is updated)

==&gt; This seems to correlate very close with ”Immer” approach to instantiate a new data structure instance with the mutated member but share all previous instance state?

==&gt; Consider how this lead to the idea that we should use the C++ Immer library to implement MIVs?

…

3) The Immer library seem to be licenced using GPL license that makes programs based on it also requring GPL licensing (<https://www.gnu.org/licenses/gpl-3.0.en.html>)?

==&gt; Seems to be clear enough in this page (<https://www.gnu.org/licenses/gpl-faq.html#IfLibraryIsGPL>)?

> ” *If a library is released under the GPL (not the LGPL), does that mean that any software which uses it has to be under the GPL or a GPL-compatible license? (#IfLibraryIsGPL)*

> *Yes, because the software as it is actually run includes the library.*”

==&gt; So this must impliy Darwinet must be GPL licenced if we use ”Immer”?

==&gt; Consider how to implement Darwinet components (engine) as a separate executable to allow proprietary software to interact and still choose their own licensing?

==&gt; Consider this page about why one should use GPL and not ”Lesser” GPL for liubraries (<https://www.gnu.org/licenses/why-not-lgpl.html>)

> ”The GNU Project has two principal licenses to use for libraries. One is the GNU Lesser GPL; the other is the ordinary GNU GPL. The choice of license makes a big difference: using the Lesser GPL permits use of the library in proprietary programs; using the ordinary GPL for a library makes it available only for free programs."

==&gt; It seems the problem is the contradictions between ”free evolution” and ”competitive evolution” (<https://www.gnu.org/licenses/gpl-faq.html#WhyUseGPL>)?

> ”*Why should I use the GNU GPL rather than other free software licenses? (#WhyUseGPL)*  
> *Using the GNU GPL will require that all the released improved versions be free software. This means you can avoid the risk of having to compete with a proprietary modified version of your own work. However, in some special situations it can be better to use a more permissive license.*"

==&gt; Consider how this exposes the misconception between ”survival of the fittest” and ”survival of the strongest”?

==&gt; Consider for human kind we like to promote ideas that are ”survival of the fittest” while our economic system favors ”survival of the most powerful”?

...

==&gt; It seems GPL clashes with the incitements built in to the economic system we have chosen as the default for all of us?

> ”*Proprietary software developers have the advantage of money; free software developers need to make advantages for each other. Using the ordinary GPL for a library gives free software developers an advantage over proprietary developers: a library that they can use, while proprietary developers cannot use it.*"

==&gt; Thus, although humanity actually as a whole benefits from being able to collaborate freely, each separate person or organisation may loose out in the game of making money to bring ”food to the table”?

==&gt; Consider this an example how the economical incitements clash with the ”common good”?

…

Consider to delve into the ”Immer” C++ Immutable Data Structure library and optionally see if we are tempted to use it in Darwinet C++ implementation?

...

{% endraw %}
