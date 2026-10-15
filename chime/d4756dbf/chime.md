# Todo: Darwinet - Consider to learn about the CRDT LSeq algorithm to P2P synchronise ordered data (text and other sequences)

```#d4756dbf``` *As of 2017-08-02 16:02*

[mail plain/text](mail.txt)

{% raw %}
Consider there is actually a CRDT for making operational transformation to an ordered set of data eventually consistent, the LSeq algorithm?

==&gt; Also see “Todo: Darwinet - Consider the work of Christopher Meiklejohn on Declarative, Convergent Edge Computation is in fact a variant of the Darwinet Network?”

==&gt; Also see “Todo: Darwinet - Consider to follow up on research by Lindsey Kuper about LVars and its correlation with CRDTs?”

==&gt; Also see “Todo: Darwinet - Consider to make a Darwinet REPL?”

==&gt; Also see “Todo: Darwinet - It seems Darwinet Deltas are in fact the same thing as "Conflict-free replicated data type" or CFRD?”

==&gt; Also see “Todo: Darwinet - Consider to motivate survival-of-fittest-view with the argument that views always shows meaningful state where a merge algorithm will always create an invalid state?"

1) Consider this talk “What CRDTs, distributed editing and the speed of light means to your writer friends- Jonathan Martin" (<https://www.youtube.com/watch?v=pMMDVphop40&index=152&list=PL03Lrmd9CiGewi0lbnahxEpisoP5WZocX>)?

==&gt; He seems to start of by arguing Digital Nomads as users that need P2P self synchronised data sharing (regularity offline + low bandwidth exchange)

==&gt; At 22:30 he gives what seems to be a good explanation of “tombstone based” operational transformation of text editing (<https://youtu.be/pMMDVphop40?list=PL03Lrmd9CiGewi0lbnahxEpisoP5WZocX&t=1350>)?

==&gt; At 27:35 he seems to give a good description of Conflict Free Replicated Data Types (CRDT) (<https://youtu.be/pMMDVphop40?list=PL03Lrmd9CiGewi0lbnahxEpisoP5WZocX&t=1657>)?

==&gt; At 28:35 he starts to refer to and describe the LSEQ CRDT Algorithm for ordered data (<https://youtu.be/pMMDVphop40?list=PL03Lrmd9CiGewi0lbnahxEpisoP5WZocX&t=1719>)?

==&gt; He starts of with normal string as vector

![](<Text sandwich as vector example.tiff>)

==&gt; Then shows a tree representation of a text (a trie?)

![](<Text sandwich as tree.tiff>)

==&gt; And here is the LSEQ data structure for a text

![](<Text sandwich LSEQ tree represantation.tiff>)

==&gt; The LSEQ data structure seems to be a relaxed tree (it leaves room for inserts and deletes between characters without violating existing character locations, i.e. paths)?

==&gt; Thus, the LSEQ makes member paths persistent (mutations to the tree can be applied without violating the unmated data)?

==&gt; Note: The algorithm seems to require that the path of deleted members i NOT re-used by new inserts (deletes keeps structure persistent)?

==&gt; It seems LSEQ uses branch paths as indices to members (e.g. 3.7.7 is the path to the letter ‘d’ between ‘a’ and ’s’)?

![](<LSEQ insert using persistent path index - example.tiff>)

==&gt; And after adding all existing nodes have persistent indices (paths)

![](<LSEQ add element example.tiff>)

==&gt; At 33:05 he states that the crux of the LSEQ algorithm is about how to create the paths of now elements to keep the tree depth down (<https://youtu.be/pMMDVphop40?list=PL03Lrmd9CiGewi0lbnahxEpisoP5WZocX&t=1988>)?

==&gt; At 38:34 he seems to refer to this paper “” on LSEQ data structure (<https://youtu.be/pMMDVphop40?list=PL03Lrmd9CiGewi0lbnahxEpisoP5WZocX&t=2314>)?

==&gt; The paper seems to be available as pdf here (<https://arxiv.org/abs/1608.03960v2>)?

  
> > A Conflict-Free Replicated JSON Datatype Martin Kleppmann and Alastair R. Beresford

  
==&gt; Also Consider this older (original LSEQ?) article “LSEQ: an adaptive structure for sequences in distributed collaborative editing” from 2013 (<http://dl.acm.org/citation.cfm?id=2494278&dl=ACM&coll=DL&CFID=792717758&CFTOKEN=58612481>)

==&gt; But it costs 15$ here?

==&gt; He seems to refer to this gitbub scala implementation of the JSon CRDT (<https://github.com/fthomas/crjdt>)?

==&gt; At 40:50 he starts a survey of base technologies available to build P2P networks (<https://youtu.be/pMMDVphop40?list=PL03Lrmd9CiGewi0lbnahxEpisoP5WZocX&t=2451>)?

![](<Base Technologies to build P2P networks (example).tiff>)

==&gt; At 41:05 he lists some of the core mechanisms for a P2P network to operate in a good way (<https://youtu.be/pMMDVphop40?list=PL03Lrmd9CiGewi0lbnahxEpisoP5WZocX&t=2468>)?

![](<Basic P2P mechanisms to get right - example.tiff>)

==&gt; Consider to propose a Darwinet Topology Factory (a mechanism to try and apply different network topologies and not have a fixed one)?

==&gt; Consider to propose a Darwinet Discovery Engine Factory (a mechanism to try abut and apply different discovery mechanisms and not have a fixed one)?

==&gt; Consider to propose a Darwinet Transport Factor and Selector (to enable DArwinet Nodes to implement and use a set of Transports and negotiate what to use in different situations)?

==&gt; Consider to propose a set of Darwinet Security idioms and mechanisms (to not have a fixed implementation but negotiate what to use e.g., ssl style)?

…

==&gt; At 43:00 he makes the observation that Internet itself is constructed kind-of as a P2P network resilient to routing cut-offs (<https://youtu.be/pMMDVphop40?list=PL03Lrmd9CiGewi0lbnahxEpisoP5WZocX&t=2578>)?

==&gt; At 43:40 he lists some libraries/technologies that implements P2P networking (<https://youtu.be/pMMDVphop40?list=PL03Lrmd9CiGewi0lbnahxEpisoP5WZocX&t=2622>)?

![](<P2P Netwroking frameworks - example.tiff>)

==&gt; Scuttlebutt seems to be a slang word for “gossip” (<https://en.wikipedia.org/wiki/Scuttlebutt>)

==&gt; Scuttlebutt seems to live at github here (<https://github.com/ssbc>)?

==&gt; It seems to be a Javascript based P2P social network platform?

> > “*A distributed and secure peer to peer social network*"

==&gt; Scuttlebutt seems to live here (<https://www.scuttlebutt.nz>)?

==&gt; It seems to refer to a list of noteworthy decentralised (dec) projects?

- [Matrix](http://matrix.org/)
- [Bitcoin](https://bitcoin.org/)
- [Ethereum](https://www.ethereum.org/)
- [Zerocoin](http://zerocoin.org/)
- [MaidSafe](http://maidsafe.net/)
- [IPFS](https://ipfs.io/)
- [Dat](http://datproject.org/)
- [Solid](https://github.com/solid/solid)
- [cjdns](https://github.com/cjdelisle/cjdns)
- [Syncthing](https://syncthing.net/)
- [Indie](https://ind.ie/)
- [Twister](http://twister.net.co/)
- [WebTorrent](https://webtorrent.io/)
- [StrongLink](https://github.com/btrask/stronglink)
- [RetroShare](http://retroshare.sourceforge.net/)
- [ZeroNet](http://zeronet.io/)



==&gt; This seems to be wikipedia take on Gossip protocols (<https://en.wikipedia.org/wiki/Gossip_protocol>)?

==&gt; There seem to be a long list of Javascript based packages that implements/uses Gossip protocol networks (<https://www.npmjs.com/browse/keyword/gossip>)?

==&gt; Hyperlog seems to be a database Log replication based on scuttlebutt P2P networks (<https://github.com/mafintosh/hyperlog>)?

==&gt; Libp2p seems to be a modulo p2p stack framework used by IPFS and available as Go and Javascript frameworks (<https://github.com/libp2p>)?

> > “*Modular peer-to-peer networking stack (used by IPFS and others)*"

==&gt; And IPFS seems to be a globally distributed P2P (hypermedia?) file system (<https://ipfs.io>)?

> > “*A peer-to-peer hypermedia protocol to make the web faster, safer, and more open.*"

==&gt; IPFS seems to be written in Go (<https://youtu.be/8CMxDNuuAiQ>)?

==&gt; Also refers to in “Todo: Darwinet - Consider the work of Christopher Meiklejohn on Declarative, Convergent Edge Computation is in fact a variant of the Darwinet Network?"

==&gt; At 44:20 he refers to this github project that list a large set of p2p projects and resources (<https://github.com/kgryte/awesome-peer-to-peer>)?

==&gt; At 45:20 he shows a web browser editor App.

==&gt; He seems top state it is based on node.js extension mDNS that seem to live here (<https://github.com/agnat/node_mdns>)?

> > “*mdns adds multicast DNS service discovery, also known as zeroconf or bonjour to Node.js*"

==&gt; It seems mDNS is about service discovery on TCP networks?

> > ```
> > // advertise a http server on port 4321
> > var ad = mdns.createAdvertisement(mdns.tcp('http'), 4321);
> > ad.start();

> > // watch all http servers
> > var browser = mdns.createBrowser(mdns.tcp('http'));
> > browser.on('serviceUp', function(service) {
> >   console.log("service up: ", service);
> > });
> > browser.on('serviceDown', function(service) {
> >   console.log("service down: ", service);
> > });
> > browser.start();

> > // discover all available service types
> > var all_the_types = mdns.browseThemAll(); // all_the_types is just another browser...
> > ```



==&gt; Hm… “browser” here is not a web-browser but an entity (process) that continuously observes the status of available services on the local network?

==&gt; So, with msdn we can “advertise”, watch and discover tcp based services (http, ftp, …)?

...

==&gt; Jonathan Martin seems to be “nybblr” on Github and the example editor seems to be available here (<https://github.com/nybblr/p2p-experiments>)?

==&gt; It seems to be based on Electron and of course node.js and npm of course?

...

==&gt; Consider to try out his electron based collaborative editor?

==&gt; I downloaded and installed pre-built framework “quick-start” from here (<https://electron.atom.io>)

==&gt; Also see “Todo: Consider to document installation of Electron development and run-time environment on my different machines?”

==&gt; On my Macbook Pro 2015 electron hets installed to “**/Users/kjell-olovhogdahl/Documents/GitHub/electron-quick-start/node_modules/.bin**”

==&gt; Compare installation in the Todo where it got installed to “/Users/kjell-olovhogdahl/Documents/GitHub/electron/electron-quick-start/node_modules/.bin” (I used an electron root folder)!

==&gt; The actual electron application does not seem to be the editor?

> > Kjell-Olovs-MacBook-Pro:GitHub kjell-olovhogdahl$ cd p2p-experiments/  
> > Kjell-Olovs-MacBook-Pro:p2p-experiments kjell-olovhogdahl$ pwd  
> > /Users/kjell-olovhogdahl/Documents/GitHub/p2p-experiments  
> > Kjell-Olovs-MacBook-Pro:p2p-experiments kjell-olovhogdahl$ /Users/kjell-olovhogdahl/Documents/GitHub/electron-quick-start/node_modules/.bin/**electron** .  
> > ^C  
> > Kjell-Olovs-MacBook-Pro:p2p-experiments kjell-olovhogdahl$

==&gt; At 47:00 he refers to even more exciting technologies that will enable even more p2p applications (<https://youtu.be/pMMDVphop40?list=PL03Lrmd9CiGewi0lbnahxEpisoP5WZocX&t=2821>)?

![](<Examples of coming technologies thet may enable even more existing p2p netwrok abilities.tiff>)

==&gt; LTE Direct seems to be a qaulcom initiative (<http://www.techradar.com/news/world-of-tech/could-device-to-device-be-the-next-big-thing-1302974>)?

==&gt; Qualcom seems to write about it here (<https://www.qualcomm.com/invention/technologies/lte/direct>)?

2) Consider that LSeq actually does NOT resolve the state into the correct one?

==&gt; Consider that although LSeq will make the state eventually consistent (but that state is not usable)?

==&gt; Also see “Todo: Darwinet - Consider to motivate survival-of-fittest-view with the argument that views always shows meaningful state where a merge algorithm will always create an invalid state?"

==&gt; The algorithm solves the problem that two or more actors delete and add text at the same location by protecting the order or these changes?

==&gt; But although the final merged state contains both the operations, the merged result is NOT what either actor intended?

==&gt; Se the example at 34:42 for LSEQ resolution of two conflicting edits to a text (<https://youtu.be/pMMDVphop40?list=PL03Lrmd9CiGewi0lbnahxEpisoP5WZocX&t=1988>)?

==&gt; So, we have two conflicting edits by Alex and Beth

Alex: “sandwich” -&gt; “sand**y**wich"

Beth: “sandwich” -&gt; “sandw**h**ich”

![](<LSEQ conficing edits example.tiff>)

==&gt; Which LSEQ handles as commutative operational transforms (character paths persist)

==&gt; I.e., LSEQ allows Alex:s and Beth:s edits in any order (the same end state will be produced)

![](<LSEQ conflicting edits commute example.tiff>)

==&gt; BUT - The end state is NOT what Alex not Beth intended!

==&gt; So, although the end state is consistent, Alex and Beth must still agree on what the true end result should be?

Alex: “sandwich” -&gt;   “sand**y**wich"

Beth: “sandwich” -&gt;  “sandw**h**ich”

--------------------------------------------

= “sand**y**w**h**ich"

![](<LSEQ conflicting edits result example.tiff>)

3) Consider this Javascript GitHub project implementing an LSEQ Tree (<https://github.com/Chat-Wane/LSEQTree>)?

==&gt; It seems to refer to this Clojure LSETree (that has not been updated for a long time (<https://github.com/Tavistock/lseq-tree>)?

==&gt; It seems to refer to this paper “” (<http://hal.upmc.fr/file/index/docid/555588/filename/techreport.pdf>)?

> A comprehensive study of Convergent and Commutative Replicated Data Types  
> Marc Shapiro, Nuno Pregui ̧ca, Carlos Baquero, Marek Zawirski

  
==&gt; Also mentioned in “Todo: Darwinet - Consider the work of Christopher Meiklejohn on Declarative, Convergent Edge Computation is in fact a variant of the Darwinet Network?”

==&gt; Also mentioned in “Todo: Darwinet - It seems Darwinet Deltas are in fact the same thing as "Conflict-free replicated data type" or CFRD?"

4) Consider papers relating to the LSEQ algorithm?

==&gt; Consider “” (<https://arxiv.org/abs/1608.03960v2>)?

…

…

Consider to really follow up on all the leads from the NDC talk by Jonathan Martin and how we can relate it to Darwinet to make that idea fly?

...

{% endraw %}
