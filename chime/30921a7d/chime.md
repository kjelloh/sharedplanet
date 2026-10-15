# Todo: Darwinet - Consider to follow up on research by Lindsey Kuper about LVars and its correlation with CRDTs?

```#30921a7d``` *As of 2017-02-23 13:01*

[mail plain/text](mail.txt)

{% raw %}
It seems there is a correspondence between LVar research by Lindsey Kuper and and CRDT Research? Consider to follow up on Lindsey Kuper work to find out how it relates to CRDT:s and what we can or should reuse in the implementation of Darwinet MIVs?

1) Consider to follow up on Lindsey Kuper work and publications?

==&gt; Consider her Github Repositories (<https://github.com/lkuper>)?

==&gt; Consider to read her Personal Research Blog (<http://composition.al>)?

==&gt; Consider her own listing of blog posts on LVar (<http://composition.al/blog/categories/lvars/>)?

==&gt; Consider her Blog Post ”What's the difference between LVars and CRDTs?” (<http://composition.al/blog/2015/05/29/whats-the-difference-between-lvars-and-crdts/>)?

> ”*In fact, in order to implement an incrementable counter, we need the ability to do writes that are inflationary and commutative, but not idempotent.*"

==&gt; Consider to read her Official Indiana University Blog (<http://www.cs.indiana.edu/~lkuper/>)?

==&gt; It seems LVars is a Haskel library that implements the LVar programming idiom (<http://www.cs.indiana.edu/~rrnewton/papers/effectzoo-draft.pdf>)?

> ”*The recently proposed LVars programming model, and the ac- companying LVish Haskell library, took a step toward broadly- applicable guaranteed-deterministic parallel programming.*”  
> ”*LVish provides a Par monad for parallel computation that encapsulates determinism-preserving effects while allowing a more flexible form of communication between parallel tasks than previous guaranteed-deterministic models provided.*"

...

2) Consider how the Darwinet MIV (SEPSI) corresponds with LVar and CRDT research?

==&gt; CRDT:s seem to require Monitonic Growth and Idempotent mutations (and thus they are not fully suitable for Darwinet MIVs)?

==&gt; Or, can we imagine to combine MIV branching (to remain persistent) with LVar/CRDT merge proposals (to enable view convergence)?

==&gt; It seems Kuper argues that LVars mutations as opposed to CRDT:s does NOT have to be idempotent (See her ”What's the difference between LVars and CRDTs?” blog post)?

…

3) Consider to watch Videos with Lindsey Kuper on the web?

==&gt; Consider this talk ”LVars: lattice-based data structures for deterministic parallelism (Lindsey Kuper) - RICON West 2013” where I first encountered Lindsey Kuper (<https://www.youtube.com/watch?v=8dFO5Ir0xqY>)?

==&gt; Consider ”” (<https://www.youtube.com/watch?v=Ti9qqAe_NF4>)?

==&gt; Consider this video Podcast interview (<https://www.youtube.com/watch?v=nqctAvyTgEk>)?

==&gt; Consider this talk ”&#91;SPLASH-I&#93; Prospect: Finding and Exploiting Parallelism in a Productivity Language” (<https://www.youtube.com/watch?v=O6PN-kpbNTw>)?

==&gt; Consider ”Lindsey Kuper, "A Lattice-Based Approach to Deterministic Parallelism", MPI-SWS, 30 January 2013” (<https://www.youtube.com/watch?v=ekCZfFYwkcY>)?

==&gt; Consider this talk on the Rust language ”Intern Presentation: Rust Typeclasses" (<https://air.mozilla.org/rust-typeclasses/>)?

...

4) Consider to use Lindsey Kuper research and writings to assemble a list of published papers on CRDT:s, LVars and related topics?

==&gt; Consider the research by Marc Shapiro… CRDT:s…

==&gt; Consider the research by Lindsey Kuper on LVars (LWish)

…

…

Consider to delve deeper into the research by Lindsey Kuper and follow up to related works on CRDT:s and Eventual Consensus in Distributed systems?

...

{% endraw %}
