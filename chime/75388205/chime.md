# Todo: Darwinet - Model and Instance paths + ID:s and Names

```#75388205``` *As of 2015-11-07 13:43*

[mail plain/text](mail.txt)

{% raw %}
Seem we still have to solve the problem of M paths and I paths and also how to actually create new ID:s of domains, nodes and MIV:s?

Also see: ”Todo: Darwinet - Design MIV using type, model paths and instance paths"

&lt;Model Paths&gt;

a) Consider to try M path to be path of relations (edges) between model types (declarations)?  
b) Each node of a model path would then be made up of UML relations?  
c) Each Relation then defines Relation Type , Source and Target (See UML http://www.uml-diagrams.org/association.html)

&lt;Instance Paths&gt;

d) How do we assign a name to each individual instance (corresponding to location in memory (address) in computer programming)?

&lt;About unique ID:s&gt;

e) It seems we need to use GUID:s for Domain and Node names (As Domains and Nodes are temporarily separated and no locally created name can be assured to be unique)?  
f) Anything created by an existing Node may be assigned a unique ID using the Node ID and a locally synchronously created unique name?  
g) But - this would mean we may create Domain names and Node names using the Node ID of an existing node? All we need is the first unique Node and the rest may grow from there?  
h) Should Darwinet allow several totally separated domains to be created (each potentially using the same Domain and Node names)? How then do we bridge two such domains should we later want to?

Consider to go on along these thoughts (and previous Darwinet notes) to come up with a working design to start programming?

{% endraw %}
