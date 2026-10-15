# Todo: Einhell 2025 - Consider to try and use a Power Control to regulate the saw speed (and apply manual soft start)?

```#0e09e3ed``` *As of 2017-12-15 23:28*

[mail plain/text](mail.txt)

{% raw %}
Consider it could be interesting and good education to design and build a power (speed) control for my Einhell 2025 table saw?

==&gt; Also see ”[Todo: Einhell Bordssåg - Kolla upp om motorn är en universalmotor (alltså en allströmsmotor med borstar)?](../0a98a37e/chime.md)”

==&gt; Also see ”[Todo: Einhell 2025 - Consider to document data about my table saw and possible ascessories?](../1d4fcb9a/chime.md)"

1) Consider the Conrad Power Control 2760VA (<https://www.conrad.com/ce/en/product/191343/Power-controller-Component-Conrad-Components-191343-230-Vac?ref=list>)?

==&gt; It seems they recommend and define an AC filter according to EC guideline 89/336/EWG EU EMC directive (<https://sv.wikipedia.org/wiki/EMC-direktivet>)?

2) Consider to build the AC filer for the Conrad Power Control 2760 according to the EU EMC directive (<https://sv.wikipedia.org/wiki/EMC-direktivet>)?

==&gt; This sems to be the operating instructions where the filter is defined (<http://www.produktinfo.conrad.com/datenblaetter/175000-199999/191343-an-01-ml-Power_Control_2760_de_en_fr_nl.pdf>)?

![](<Skärmavbild 2017-12-15 kl. 21.49.12.png>)

==&gt; This seems to be the components required?

==&gt; The Varistor seems to be Vrms 250V, Vdc 320, Imax (8/20 µs) 2500A, Wmax (2 ns) 38J, Pmax 0,4W

![](<Skärmavbild 2017-12-15 kl. 21.54.05.png>)

1 st Varistor (EPCOS code B72210S0251K101)

1 st 220 nF

1 st 680 nF

2 st 1.0 nF

2 st 15 mH

1 st 250 µH

==&gt; This seems to be the price when ordred from Elfa?

==&gt; NOTE: I wonder if a drossel marked 5A is for max or continuous current (if continuous we can get away with smaller ones)?

==&gt; Note that Einhell is marked as a 2000W motor (2000/240 = 8.3A) but what is the realistic current we must dimension the choke for?

...

![](<Skärmavbild 2017-12-15 kl. 23.20.56.png>)

…

Consider to update this Tod with findings if and when I try applying speed control (manual soft start) to the Einhell 2025 table saw?

{% endraw %}
