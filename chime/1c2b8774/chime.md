# Todo: Darwinet - Consider how darwinet domain plus application could work as a pack manager?

```#1c2b8774``` *As of 2016-07-16 18:30*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to look into how a Darwinet domain combined with appropriate applications could work as a replacement (or alternative) for existing package managers?

==&gt; See ”Todo: Programming - Consider to understand and document how to create and distribute a chocolatey package using tree command tool as working example)?”

==&gt; See ”Todo: Programming - Consider a tool to 3D visualise Network Data Synchronisation (e.g. Linux package managing and Windows Installer)?”

==&gt; See ”Todo: Programming - Consider to distribute the tree command line tool through the package managers of each of the major platforms (chocolatey, apt and brew)?”

==&gt; See ”Todo: Programming - Consider to implement a C++ library that provides services that applies tag-path based encoder/decoder idiom to encode packages for popular package managers (e.g. chocolate, NuGet, apt and brew)?”

==&gt; See ”Todo: Programming - It seems C++ boost for Visual Studio is available using NuGet package manager?"

1) Consider such domain to be able to synchronize installed packages on all nodes that are a member of the domain?

==&gt; The package can be stored on the file system of the domain?

==&gt; The domain must provide some synchronization mechanism to mirror changes onto the operating system of the node (update installed package)?

==&gt; Consider if a Darwinet file system can be mounted onto the host-os of the node (no need to actually ”install”)?

==&gt; Seems we then need some synchronization mechanism with a complete ”transaction” so that files are not accessed in the middle of the update?

2) Consider how we can solve mirroring a transacted package onto the state of the hos environment (in effect perform ”install” as required)?

==&gt; Can we imagine Darwinet Domain events to be mapped to hos-envrionment actions (e.g. trigger windows installer.msi or just update registry settings)?

==&gt; Consider it may be best to do the mirroring by triggering scripts and tools as if the update was made using ”manual” download?

==&gt; If so, the Darwinet File System is just a way to push the changes onto the Node and trigger attention from the user to ”install” it?

Node A Node n —&gt; View —&gt; ”Execute Update” —&gt; User

|  |

update package On Package State

|  |

File System ==&gt; Transaction {d,d,d,d,d} ==&gt; File System

==&gt; Or imagine the receiving node to be able to bind actions to state changes as defined by the domain and domain tools?

==&gt; Domain tools can be just exe-files in the file system of the domain?

==&gt; Domain tools can be hooks to existing tools on the host environment (e.g. bat command shell on windows or Linus shell commands)?

…

3) Consider a Darwinet Package domain must have sub-domains for different host platforms (e.g. MacOS, Linux, Windows)?

==&gt; Consider a cross-platform package may have platform unique files on platform sub-domain but also share common files in parent package domain?

==&gt; Consider the file system of a sub-domain is a specialization of the main domain file system in that it overrides files as required for the target platform?

==&gt; Consider source code to be shared (binary the same on all platforms)?

==&gt; Consider tooling to differ (e.g. install-tool-chain is msg-files on windows, apt-get on Linux and Brew on MacOS)?

==&gt; Consider text files can be transformed between main and sub-platforms (e.g. to handle CR/LF differences)?

…

…

4) Consider to base the Darwinet Design on the ”Digital World” idiom (domain, sub-domain and tools are ”worlds”)?

==&gt; See ”Todo: Programming - Consider to implement a C++ library that provides "Digital World" entity and object interaction services?”

==&gt; See ”Todo: Darwinet - Consider to apply the "digital worlds" idiom to administrate what gets synced and viewed where and when?”

==&gt; See ”Todo: Programming - Consider to design views of tool-defined "Digital Worlds" populated with entities (tool operations) that understands objects (data, scripts and files defined by these tools)? ”

==&gt; See ”Todo: Programming - Consider to elaborate on what "life simplifier" applications we can create from building blocks like "digital worlds", "digital diety", darwinet and cross platform GUI:s?”

...

…

Consider to elaborate on this idea to make a Darwinet Domain solve the ”package hell” problem of todays digital reality?

...

{% endraw %}
