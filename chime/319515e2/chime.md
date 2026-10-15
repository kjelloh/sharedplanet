# Todo: Programming - Consider to distribute the tree command line tool through the package managers of each of the major platforms (chocolatey, apt and brew)?

```#319515e2``` *As of 2016-07-14 13:06*

[mail plain/text](mail.txt)

{% raw %}
So, what can we learn by trying to distribute the tree command line tool to each major platform using the preferred package manager on that platform?

==&gt; Also see ”[Todo: Programming - Consider to write a tree command line application for windows and distribute it as a chocolatey package?](../98b91233/chime.md)"

1) Consider to create a chocolatey package for Windows?

==&gt; This seem to be the home of chocolate (<https://chocolatey.org>)?

==&gt; It seems they promote hosting a package manager server of once own (<https://github.com/chocolatey/choco/wiki/How-To-Host-Feed>)?

==&gt; Chocolate does not seem to support build-from-source idiom (which we don’t care about on windows)?

”...Chocolatey does not support the idea of source packages, which are packages that must be built to be used. For someone interested in that, check out <https://github.com/coapp>.” (<https://github.com/chocolatey/choco/wiki/ChocolateyFAQs#how-iswill-chocolatey-be-different-than-apt>)

==&gt; This seem to be a good explanation of what a chocolate package is (<https://github.com/chocolatey/choco/wiki/GettingStarted#what-are-chocolatey-packages>)?

”Chocolatey packages are known as nupkg files, which is a compiled NuSpec or a fancy zip file that knows about package metadata (including dependencies and versioning). These packages are an enhanced NuGet package, they have additional metadata that is specific to Chocolatey. Chocolatey is also compatible with vanilla NuGet packages. A Chocolatey package can contain embedded software and/or automation scripts."

2) Consider to create an apt package on Linux?

3) Consider to create a brew package on MacOS?

4) Consider what the common model of all there package managers are?

==&gt; Consider to model what each package manager does using the ”Digital World” model?

==&gt; &lt;source&gt; ==&gt; &lt;executable&gt;

==&gt; &lt;executable&gt; ==&gt; &lt;distributable&gt;

==&gt; &lt;distributable&gt; ==&gt; &lt;package&gt;

==&gt; &lt;package&gt; ==&gt; &lt;package manager&gt;

…

==&gt; Consider how the chocolatey package manager can turn an installer exe into a chocolatey package (in effect transforming from msi ”world” to chocolate ”world”)?

==&gt; Consider to implement a C++ library to encode packages for e.g., chocolatey package managers?

==&gt; See ”[Todo: Programming - Consider to implement a C++ library that provides services that applies tag-path based encoder/decoder idiom to encode packages for popular package managers (e.g. chocolate, NuGet, apt and brew)?](../26072468/chime.md)”

…

Consider to continue to try and genaret and distribute the tree command line tool to major platforms using the package manager on that platform?

...

{% endraw %}
