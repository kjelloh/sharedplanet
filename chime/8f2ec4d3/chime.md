# Todo: Write about Darwinet MIV distribution

```#8f2ec4d3``` *As of 2015-08-09 13:51*

[mail plain/text](mail.txt)

{% raw %}
Darwinet data is to be distributed into storage at nodes in the domain. This distribution is defined by Access Distribution (who may access the data), Node Distribution (which nodes stores what part of data) and Storage Redundancy (how many duplicates of the same data is stored).

1) Access Distribution defines classes of accessors like A User, An Application, A Domain. In who way some data may be accessed by any actor in a domain or just by a defined application or be private to a specified user.  
2) Node Distribution defines what part of the MIV complex each node shall store. As a Darwinet Domain must be able to store global data of vast size it is not possible for every node to mirror the whole data body. Instead data must be distributed so that data most likely to be of interest to a local application or user is actually stored on they node. Any other data has to be fetched on demand from nodes that have it. The distribution mechanism must organize data distribution so that the time to retrieve it correlates to how often it is accessed. Each node also need to swap out other data when new data is fetched. One way to do this is to have each node store data in priority rings. The core never changes whilst the outer rings are very volatile.  
3) Storage Redundancy defines how many duplicates there should be of each data in the domain. The degree of redundancy needed must be based on the probability that data on a node will be erased (the device breaks down or Darwinet is uninstalled). Redundancy should also take into account the probability that nodes are offline or far away in access time (large temporal distance).

These three aspects of data distribution interacts and are dependent on each other. E.g., User private data (1) may be distributed primarily on user owned nodes (2) unless the storage redundancy is then to low (3) and thus other nearby nodes must be used. Service Providers may also provide nodes with high storage capacity and built in redundancy. Thus the domain may rely on such nodes to lower the need to distribute based on access, sub-MIV interest and redundancy concerns.

{% endraw %}
