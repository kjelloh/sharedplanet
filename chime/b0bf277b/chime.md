# TODO: Darwinet - View Delta-trail as TreeTable with deltas in columns

```#b0bf277b``` *As of 2015-03-06 13:58*

[mail plain/text](mail.txt)

{% raw %}
Display Delta trail affect on MIV as TreeTable with deltas in columns.

\* The Whole MIV as a tree in the left column.  
\* The Main Delta Trail and branches at the Top for the root node with a new column for each delta.  
\* Each delta also in the row of the MIV it affects.

In this way it is easy to read the main Delta trail and also each individual MIV affected my each Delta.

Try if this approach works also fro branches?

\* Branch due to individual delta conflict (same state approached by a delta)  
\* Branch due to main delta trail conflict. In this case the approached Delta does not conflict. But the local delta trail state conflicts. The main trail state at the node where the Delta was created differs from the trail state where it is applied. This means that two different deltas have the same previous delta in the main trail.

{% endraw %}
