# Todo: Darwinet - Design MIV using type, model paths and instance paths

```#d55d38d6``` *As of 2015-10-28 10:46*

[mail plain/text](mail.txt)

{% raw %}
It seems we need three main aspects when designing MIVs?

1) Each M defines a ”type” in the same way as in programming language, i.e. a declaration of a data structure (structured or primitive).  
2) Each M is identified by one or more model paths, the path of M relations, leading to the M. There may be several paths leading to each M (it and other Ms in the path may be referenced by several other Ms)  
3) Each I is identified by one or more instance paths, the path of I relations leading to the I. There may be several paths leading to each I of the same reason the there may be several moel paths leading to each M.

So, does this work?

a) A Model Path may be a path of types each identifying its cardinality in this specific path?  
b) An instance path may be a path of instanced types, each identified by its index (allowing cardinality &gt; 1 for each type in the path).  
c) An instance path is valid if each instance index is within the cardinality defined by the instanced model path.

But with this approach we have a problem of knowing if an instance of an M that have more than one model path is unique or the same instance as another one?

i) Lets say the model node ”Employee&#91;\*&#93;.Name&#91;1&#93;” and ”ProjectMember&#91;\*&#93;.Name&#91;1&#93;” is the same type (number in brackets is the cardinality).  
ii) Then the instance ”Employee&#91;x&#93;.Name&#91;1&#93;” and ”ProjectMember&#91;y&#93;.Name&#91;1&#93;” (x and y instance indexes) may be the same or different instance of this type (the type defined by Name node). How do we know?  
iii) Note that in programming we know by looking at the adress where the value is stored. It is the same instance iof the value is stored at the same location. Does this suggest we need I:s to define its ”adress” of storage?  
…

So, what is going on here? Why does it seem there is something missing in this design of MIVs?

I) Seems we need model paths to also define the relations between the nodes of the path (aggregates, references)? What relations does UML define? (http://www.uml-diagrams.org/association.html)  
II) Instance Level Relationships seem to be ”Dependency”, ”Association”, ”Aggregation” and ”Composition” (https://en.wikipedia.org/wiki/Class_diagram)  
III) Class Level Relationships seem to be ”Generalization” (Inheritance or ”is a”) and ”Realization”.  
IV) Each Relationship defines ”Multiplicity” (cardinality).

Seems we need the model path to be accompanied with a path defining the Relationship of each of the nodes in the model path?  
...

{% endraw %}
