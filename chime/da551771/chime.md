# Todo: Programming - Consider to implement a set of Data Model Investigator services as a C++ library?

```#da551771``` *As of 2016-08-03 15:08*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to implement a set of services to find out how a range of anonymous data is modelled as a C++ library?

==&gt; Also see “Todo: programming - Consider to implement a C++ open source library to compile-time identify the build tool chain and target platform?”

==&gt; Also see “Todo: Programming - Consider to write a C++ cross platform service that can tell the format of object files (ELF, COFF...)?"

1) Consider a good name for a Data Model Investigator library (?name?)?

==&gt; Consider ?name? == “poirot” (as a reference to the Agatha Christie detective Hercule Poirot)?

…

2) Consider some services of ?name? library?

==&gt; Consider it should be used to match a data stream of bytes to a tag-path based model of that data?

==&gt; Consider a service that finds all text ranges of a data range?

==&gt; Consider such a service to be used to use found text ranges as a clue to what the model is?

==&gt; The contents of sound text ranges may be used to identify what model and value that is encoded?

==&gt; Consider this service to be used to try and reverse engineer model and value of the Korg SNG files (See “Todo: Programming - Consider to try tag-path based (musca?) parsing on an OASYS SNG-file”)?

…

3) Consider the ?name? library to produce a proposed tag-path based data (musca?) models?

==&gt; See “Todo: Programming - Consider to implement the tag-path based encode and decode idiom as a C++ library?”

==&gt; Q: Will we go with the name musca for the tag-path based encode/decode library?

…

4) Consider ?name? library to provide service taking a tag-path based (?musca?) model and returns how well it matches?

==&gt; Consider such a service to apply some metric that measures how well the provided model matches the anonymous data range?

…

…

Consider to delve into this idea to implement a C++ library with services to investigate what model a provided data range mat encode?

...

{% endraw %}
