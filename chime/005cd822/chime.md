# Todo: Programming - Consider to study BitTorrent over WebRTC as in WebTorrent?

```#005cd822``` *As of 2016-02-21 19:36*

{% raw %}
Seems there are work going on to use WebRTC instead of TCP/UDP over uTP Protocol?

1) This seem to be the home of the WebTorrent Project (<https://webtorrent.io/faq>)?

“WebTorrent is the first step in the journey to redecentralize the Web”

> *"Who is using WebTorrent today?*

> *WebTorrent is still pretty new, but it's already being used in cool ways:*

> *• [Instant.io](http://instant.io) – Streaming file transfer over WebTorrent (source code *<https://github.com/feross/instant.io>*)*  
> *• GitTorrent - Decentralized GitHub using BitTorrent and Bitcoin (source code )*  
> *• File.pizza - Free peer-to-peer file transfers in your browser (source code)*  
> *• PeerCloud - Serverless websites via WebTorrent*  
> *• Webtorrentapp – Platform for launching web apps from torrents*  
> *• Fastcast – Gallery site with some videos (source code)*  
> *• Colored Coins - Open protocol for creating digital assets on the Bitcoin blockchain (source code)*  
> *• Tokenly Pockets - Digital token issuance with WebTorrent-based metadata (source code)*  
> *• βTorrent - Fully-featured browser WebTorrent client (source code)*  
> *• Your app here – Send a PR with your URL!"*

2) This seem top be the Githome home of WebTorrent (<https://github.com/feross/instant.io>)?

“Powered by WebTorrent, the first torrent client that works in the browser without plugins”

==&gt; **SideNote**: WebTorrent uses Bitcoin-like blockchain to authenticate users as “distributed consensus”!

“We need a method of “distributed consensus” to give out *usernames* and know who their owners are. The method I find most promising is actually Bitcoin’s blockchain — the shared consensus that makes this cryptocurrency possible."

3) This seem to be the home of GitTorrent (<http://blog.printf.net/articles/2015/05/29/announcing-gittorrent-a-decentralized-github/>)

==&gt; Seems to be a Git-Hub on a BitTorrent file sharing network using WebRTC P2P protocol?

4) This seem to be the home of peercloud, a Webtorrent based web (<https://github.com/jhiesey/peercloud>)?

“With Peercloud, you can host and view static websites without servers. You download the site's resources from other regular web browsers just like yours!

For this to work, you need a browser that supports WebRTC and service workers. Currently this only includes Chrome, although Firefox is adding support for service workers soon.”

“Simply paste the infohash of a torrent (seeded with WebTorrent) that contains the site you want to visit and click go.”

==&gt; This is the reason Torrent based DNS makes sense - so you can lookup the torrent hash using the URL of the Webtorrent page you want to visit?

==&gt; 160221 - This is EXITING. I feel several pieces needed to move existing web-infrastructures to the post-server era (to a distributed P2P network)?!!

a) Bittorrent provides the backbone for a post-server distributed and anonymous data storage?

b) Bitcoin blockchain provides the backbone for post-bank “Distributed Consensus” authentication of data (DNS, Users and resources)

5) Consider how Darwinet fits into this post-server movement by adding Private P2P Cloud-based Desktops and server data storage?

==&gt; Consider to elaborate on what Darwinet exactly is in this post-server context?

**WE ARE HERE...**

6) This seem to be Mozilla support and description of WebRTC (<https://developer.mozilla.org/en-US/docs/Web/API/WebRTC_API/Connectivity>)

“Unfortunately WebRTC can’t create connections without some sort of server in the middle. We call this the Signal Channel. It’s any sort of channel of communication to exchange information before setting up a connection, whether by email, post card or a carrier pigeon... it’s up to you.”

==&gt; WebRTC seem to use SDP for the Peers to negotiate what protocol to use (“...whether by email, post card or a carrier pigeon... it’s up to you”)?

==&gt; SDP seems to stand for “Session Description Protocol” (<https://webrtchacks.com/anatomy-webrtc-sdp/>)?

==&gt; This seem to be the wikipedia description on SDP (<https://en.wikipedia.org/wiki/Session_Description_Protocol>)?

“The Session Description Protocol (SDP) is a format for describing streaming media initialization parameters”

==&gt; So, WebRTC uses both STUN and TURN to bridge NAT:s?

==&gt; This may be a good starting point to understand WebRTC and ICE to bridge NATs (<http://www.html5rocks.com/en/tutorials/webrtc/infrastructure/>)?

“Alice and Eve also need to exchange network information. The expression 'finding candidates' refers to the process of finding network interfaces and ports using the ICE framework.”

==&gt; ICE seems to be defined as “Interactive Connectivity Establishment” by the wikipedia page (<https://en.wikipedia.org/wiki/Interactive_Connectivity_Establishment>)?

==&gt; ICE seem to be defined in RFC 5245 “Interactive Connectivity Establishment (ICE): A Protocol for Network Address Translator (NAT) Traversal for Offer/Answer Protocols” (<https://tools.ietf.org/html/rfc5245>)?

“This document describes a protocol for Network Address Translator (NAT) traversal for *UDP-based multimedia sessions* established with the offer/answer model"

6) So How does WebRTC relate to iOT (<https://en.wikipedia.org/wiki/Internet_of_Things>)?

==&gt; This effort for standardisation of IoT may provide interesting leads (<http://www.itu.int/en/ITU-T/gsi/iot/Pages/default.aspx>)?

…

Consider to delve deeper into WebRTC usage for the post-server internet?

…

{% endraw %}
