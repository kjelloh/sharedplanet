# Todo: Design Darwinet photo database

```#d05cbc77``` *As of 2015-08-12 17:11*

[mail plain/text](mail.txt)

{% raw %}
Design a Darwinet photo database where one may access as very large photo database also on a device with very small local storage available.

1) This may serve as a proof of concept of Darwinet Data Distribution algorithm. Darwinet is able to distribute storage with full redundancy on the totally available data storage on the domain devices. This would mean at least Total memory/2. Say we have there devices with 12 GB, 34 GB and 1 GB made available to the photo database. The total available storage is then 12+34+1 = 47 GB. With at least double redundancy this would make the database carry 23 GB. But on the 1 GB device only that is actually available locally. So, if a photo that is not available locally is accessed it has to be fetched and some other local photo swapped out. Note that the swapping must protect the integrity of redundancy. It must ensure that a what is swapped out is actually still available at the two other nodes (double redundancy).

Also see the photo-augmented-map Darwiunet application in another Todo-mail where locally available photos are determined by the spatial location of the device (most probably photos from where you are is the ones you like to view).

{% endraw %}
