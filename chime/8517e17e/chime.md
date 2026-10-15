# Todo: Darwinet - Follow up on these thoughts about MIV Branching notes 150314?

```#8517e17e``` *As of 2015-11-17 12:39*

[mail plain/text](mail.txt)

{% raw %}
Consider to follow up on these ideas about MIV Branching (see below)

1) Seems branching may occur both the one main MIV trial (all-delta-trail) and on each MIV trail (deltas-targeting-specific-MIV)?

2) Seems the MIV:s state of a branch is defined by the corresponding main trail extended with the states of the breached MIV:s? If so, there is no need to mirror the unbranched MIV:s state in the branch?

3) Seems branched MIV:s that actually has the same state may be automatically merged (Their different histories is irrelevant for that specific state)? Consider to elaborate on a design that detects and “collapses” these MIV branches (e.g. using locally created merge-deltas)?

4) Seems two trails that have at least one or more MIV:s with a different state are branches of each other? Consider to design mechanisms of MIV processing that continuously searches for and applies “merges” to automatically keep (collapse) number of branches down to a minimum?

5) If merge is implemented as locally created merge-deltas, then they must be shared on the main trail (and also shared with all MIV of the domain)?

...

Consider to elaborate on these ideas and traits of branching and merging.

a) We need a term for individuals MIV:s and the “Whole MIV”. Consider to define a MIV to be a composite? Then we have the root-MIV, a number of leaf-MIVs and all other being composite-MIVs?

b) Elaborate on how locally created merge-deltas are synchronised through the Domain. How do we ensure the domain stabilises on a common set of merge-deltas when locally created ones conflict between nodes?

...

> Begin forwarded message:

> **From: **"Kjell-Olov Högdahl (itfied)" &lt;[kjell-olov.hogdahl@itfied.se](mailto:kjell-olov.hogdahl@itfied.se)&gt;  
> **Subject: ****Darwinet - branching**  
> **Date: **14 Mar 2015 08:27:55 CET  
> **To: **Kjell-olov Högdahl &lt;[kjell-olov.hogdahl@itfied.se](mailto:kjell-olov.hogdahl@itfied.se)&gt;

> Branching is detectable on main trail and individual MIV trail.

> To store several branched trail States only the branched MIVs States is needed.

> Individual MIVs in same state may be merged. Mechanism? Locally generated merge-Deltas?

> Two trails are branched as long as at least one MIV state differs.

> If all MIVs in two trails have same state then they may be automatically merged. Mechanism? Shared merge-Delta?

> Skickat från min iPhone

{% endraw %}
