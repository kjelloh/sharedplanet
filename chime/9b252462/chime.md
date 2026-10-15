# Todo: iRealPro file format - Consider to experiment with ways to crawl forums and download iRealPro songs with a C++ console app?

```#9b252462``` *As of 2017-07-27 20:29*

[mail plain/text](mail.txt)

{% raw %}
Could it be fun, productive and informative to try and write a simple C++ Console App to crawl iRealPro forums for songs and download them for later use?

1) Consider to use Christopher Kohlhoff &lt;[chris@kohlhoff.com](mailto:chris@kohlhoff.com)&gt; Networking TS implementation to interact with the iRealPro Web forums (<https://github.com/chriskohlhoff/networking-ts-impl>)?

==&gt; This seems to be a somewhat trusted implementation as it was used in talk C++Now 2017: Michael Caisse “Networking TS Workshop (part 2 of 2)" (<https://www.youtube.com/watch?v=5H-hI98TYIE>)?

2) Consider to use the Networking TS with the RxCpp (Reactive Extensions for C++) (

==&gt; Also see “/Users/kjell-olovhogdahl/BitTorrent Sync/XCode/MyRxCppWebCrawler"

==&gt; Consider this talk C++Now 2017: Kirk Shoop “Networking TS w/Algorithms” for leads (<https://www.youtube.com/watch?v=3p5w4un9YAI&index=5&list=PL_AKIMJc4roV-ATm4VQH5Tc78_0bruUuI>)?

==&gt; The example code that uses RxCpp with the Networking TS implementation by Chris seems to live here (<https://github.com/kirkshoop/networkingts>)?

…

3) Consider to try and find Krk Shoop RxCpp extensions for http request and response implementation?

==&gt; Consider to find the code he refers to at about 41:00 into “C++Now 2017: Kirk Shoop "No raw std::thread! - Live Tweet Analysis in C++"” (<https://youtu.be/1-8gxwGN3S8?t=2462>)?

==&gt; Consider if he has provided the LibCurl adaption in the twitter application he has published here (<https://github.com/kirkshoop/twitter>)?

==&gt; Also see “[Todo: RxCpp Twitter App Example - Consider to document how I got the example application from GitHub to run and consume twitter posts?](../4e9b0924/chime.md)"

==&gt; Also see my downloaded and working version here “/Users/kjell-olovhogdahl/Documents/GitHub/twitter”?

==&gt; He seems to be referring to http request and response processing here (<https://kirkshoop.github.io/introductionToRxcpp/#37>)?

> auto requesttwitterstream = defer(&#91;=&#93;(){  
> auto url = **oauth2SignUrl**("<https://stream.twitter>...");  
> return http.create(**http_request**{url, method, {}, {}}) |  
> map(&#91;&#93;(**http_response** r){  
> return r.body.chunks;  
> }) | ...

==&gt; Could it be that he finds such implementations trivial so he has not published (nor standardised) any such code?

...

…

Consider to continue to delve into ways to

{% endraw %}
