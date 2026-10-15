# Todo: Darwinet - Consider the network should promote convergence of active views (not converge to consistent state)?

```#cc8a9904``` *As of 2017-02-22 16:12*

[mail plain/text](mail.txt)

{% raw %}
Could it be a god idea to think of Darwinet MIV evolution as the aim is NOT to have eventual state consistence (we actually embrace branching on conflicting state mutations) but to have convergence on what view (fittest branch) ends up being used by all users?

1) Consider from allowing branching follows view divergence (separate view for each branch)?

==&gt; Consider branching branch 1 into branches 1.1 and 1.2?

1.1: - B —&gt; C  = View&lt;1.1.\*&gt;

/

1: A —&gt; B

\\

1.2: - B —&gt; C’ = View&lt;1.2.\*&gt;

==&gt; Each Branch clones the state before branching, i.e. Branch 1.1 and Branch 1.2 both has the initial state B)

==&gt; Each Branch then applies the conflicting Delta to create the Branch State (i.e., Branch 1.1 mutates to state C and branch 1.2 mutates to state C’)

2) Consider merging only results in same state on merged branches but NOT same view (branches still separate but in same state)?

==&gt; Consider Branch 1.1.\* and 1.2.\* create ”Merge Candidates” B&lt;1.1.\*&gt; and B&lt;1.2.\*&gt; together with views of these merges?

1.1: - B —&gt; C  = View&lt;1.1.\*&gt;

/  \\

/  \\ B&lt;1.1.\*&gt;  = View&lt;B&lt;1.1.\*&gt;&gt;

1: A —&gt; B

\\  / B&lt;1.2.\*&gt; = View&lt;B&lt;1.2.\*&gt;&gt;

\\  /

1.2: - B —&gt; C’ = View&lt;1.2.\*&gt;

==&gt; Consider B&lt;1.1.\*&gt; tries to be close to 1.2.\* branch and B&lt;1.2.\*&gt; tries to be close to branch 1.1.\* state?

3) Consider Darwinet should now promote actors (users, applications and services) to converge somehow into using the same view (any of the branch views or any of the merge candidate views)?

1.1: - B —&gt; C  = View&lt;1.1.\*&gt; // \*\*RIP\*\*

/  \\

/  \\ B&lt;1.1.\*&gt;  = View&lt;B&lt;1.1.\*&gt;&gt; … Fittest survives!

1: A —&gt; B

\\  / B&lt;1.2.\*&gt; = View&lt;B&lt;1.2.\*&gt;&gt; // \*\*RIP\*\*

\\  /

1.2: - B —&gt; C’ = View&lt;1.2.\*&gt; // \*\*RIP\*\*

==&gt; Consider in this way we do NOT strive for State Consistency but View Consistency (in the end all operates on the same state but some conflicting mutations may have died of in abandoned branches)?

==&gt; Consider this may be a safe way have the ”fittest” State survive without silently abandon conflicting mutations?

…

4) Consider Human View Selection strategies may differ from computer driven Application and Service Competing View selection?

==&gt; Consider if we can imagine Human Users and Computer Actors using the same basic View Selection Mechanism?

==&gt; Consider what Human User GUI to propose to enable Applications expose Merge Conflicts and have users agree on how conflicting input should be merged (and what view to carry on in)?

==&gt; Consider what programming API to propose to enable Darwinet Applications and Services to detect branching and to negotiate what common view to converge into using?

...

…

Consider to elaborate on this idea to embrace branching, automatically generate branch candidates and promote survival of the fittest view?

...

{% endraw %}
