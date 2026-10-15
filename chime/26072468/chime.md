# Todo: Programming - Consider to implement a C++ library that provides services that applies tag-path based encoder/decoder idiom to encode packages for popular package managers (e.g. chocolate, NuGet, apt and brew)?

```#26072468``` *As of 2016-07-14 11:30*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to try and use the tag-path based encode/decode idiom to try and encode software packages for popular package managers?

1) Consider to try and encode a chocolate package for windows (https://github.com/chocolatey/choco/wiki/GettingStarted#what-are-chocolatey-packages)?

”Chocolatey packages are known as nupkg files, which is a compiled NuSpec or a fancy zip file that knows about package metadata (including dependencies and versioning). These packages are an enhanced NuGet package, they have additional metadata that is specific to Chocolatey. Chocolatey is also compatible with vanilla NuGet packages. A Chocolatey package can contain embedded software and/or automation scripts.”

==&gt; Consider what a seed to a C++ library could look like to provide chocolate package encoding services?

2) Consider what a good name for such a package encoder C++ library could be?

==&gt; Consider ”santa” (as a reference to christmas and santa Clause)?

…

3) Consider how this C++ library should extend the more general tag-path based encode/decode service library?

==&gt; Consider that ”santa” should just be a specialization of the tag-path based codec services?  
…  
…

Consider to delve into this idea of a ”santa” C++ library to encode software packages using the tag-path based codec idiom?  
...

{% endraw %}
