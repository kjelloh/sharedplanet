# Todo: Programming - Consider to parse bank account transaction reports from web service to analyse spendings?

```#f09b9dd5``` *As of 2016-05-09 12:13*

[mail plain/text](mail.txt)

{% raw %}
So, can we imagine creating a bank account transaction report parser application that uses acquired information to analyse spendings?

-1) Consider to design the application using front-end, core and back-end idiom?

==&gt; The front-end is the user interface and user input interfaces?

==&gt; Consider one front-end to allow reading of pre-stored csv-files (manually exported from web-service)?  
==&gt; Consider front-end extension that enables automation of the users bank web-service to acquire data (html-5 browser automation)?  
…

==&gt; The core is the internal processing and representation of transaction data, label matching and optional services related to this data?

==&gt; The back-end is the interface to the platform?

==&gt; One back-end is able to read csv-files from the file system?  
==&gt; Consider a sharing-back-end that is able to interact with other nodes to share label mappings?  
==&gt; Consider one sharing mechanism using a shared but torrent file?  
==&gt; =Consider another sharing mechanism based on some Darwinet-like mechanism?  
...

1) Consider to implement such a parser as open source on Github?

==&gt; Consider this library to be based on the same encoding/decoding idiom as for SIE-file library (and general protocol message encoder/decoder)?

2) Consider to recognise transactions based on transaction labels (e.g. “Kortköp 160426 COOP KONSUM KALLHALL”)?

==&gt; Consider the label to determine who sent or received the money?

3) Consider to implement some simple Darwinet- like sharing of the transaction-label mapping to transaction type?

==&gt; Could we imagine the application to enable swarm-defining of labels?  
==&gt; Each user may share the mapping the apply and also apply label-mapping shared by others?

==&gt; Consider to use a shared bittorrent file for label mappings?  
==&gt; Is this even possible?  
==&gt; How do we handle conflicting mutations of the file?

==&gt; Consider to define some darwinet-like sharing of label-mappings?  
==&gt; Consider a bittorrent file sharing mechanism for darwinet deltas of label mapping?  
==&gt; Consider sharing Darwinet deltas using mail?

4) Consider to expand the front-end with possibility to automate web-service access?

==&gt; Can we imagine to apply the idea of web-service user interface automation (reflection) to have the application read the data directly from the bank web server?  
...

…

Consider to delve into this idea to open source a parser and analyser of bank account transaction report from a web-service?  
...

## Attachments

- [privat-1505.csv](privat-1505.csv)
- [privat-1506.csv](privat-1506.csv)
- [privat-1507.csv](privat-1507.csv)
- [privat-1508.csv](privat-1508.csv)
- [privat-1509.csv](privat-1509.csv)
- [privat-1510.csv](privat-1510.csv)
- [privat-1511.csv](privat-1511.csv)
- [privat-1512.csv](privat-1512.csv)
- [privat-1601.csv](privat-1601.csv)
- [privat-1602.csv](privat-1602.csv)
- [privat-1604.csv](privat-1604.csv)

{% endraw %}
