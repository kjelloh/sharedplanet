# Todo: Design Darwinet photo-augmented map application to find distributed data storage algorithm

```#6dbe336d``` *As of 2015-08-03 18:25*

[mail plain/text](mail.txt)

{% raw %}
Consider to design a Darwinet map application where the user may share and access photos related to that location.

1) The Darwinet domain must distribute storage of photos so that they are accessible only by those interested.  
2) Any user should be able to access photos of a particular geographic location when needed without having to provide storage of these photos at all time. Darwinet need some distributed storage that allows JIT-access (brought t to client when needed), distributed storage (each node can’t store all the worlds photos) and RAID properties (each photo needs to be stored at several locations to protect it from data loss and node inaccessibility).

This could be a proof-of-conect application to enable Darwinet to store global scale data in a peer-to-peer network. I suppose some of the existing Distributed Hash algorithms should suffice?

{% endraw %}
