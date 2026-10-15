# Todo: Programming - Consider to understand Git cooperation using e-mailed repositories (bundles)?

```#b93b13f6``` *As of 2016-07-09 20:57*

[mail plain/text](mail.txt)

{% raw %}
It seems possible to actually “zip" a local Git repository and then send it in an e-mail to another user that may then “unzip” it into her locally existing Git repository?

Node A —— e-mail —&gt;  Node B

|  |    |

Git Repository Q  Git Bundle Git Repository Q

1) Consider this blog post about synchronising Git Repositories by mailing Git Bundles (<https://git-scm.com/blog/2010/03/10/bundles.html>)

==&gt; Cooperation using an exchanged Git Bundle seems to correspond to the push/pull commands?

“The scenario is thus: you need to sneakernet a git push. Maybe your network is down and you want to send changes to your co-workers.”

==&gt; One creates a bundle to send with the Git Bundle Create command?

Node A

> $ git bundle create repo.bundle master  
> Counting objects: 6, done.  
> Delta compression using up to 2 threads.  
> Compressing objects: 100% (2/2), done.  
> Writing objects: 100% (6/6), 441 bytes, done.  
> Total 6 (delta 0), reused 0 (delta 0)

|

|

Node A File: **repo.bundle**

==&gt; The receiver of this bundle file may clone to a new Git Repository

Node B

> $ git clone repo.bundle -b master repo  
> Initialized empty Git repository in /private/tmp/bundle/repo/.git/  
> $ cd repo  
> $ git log --oneline  
> 9a466c5 second commit  
> b1ec324 first commit

|

|

Node B repository **./.git/**

==&gt; Lets assume we now make three commits on Node B

Node B

> $ git log --oneline master ^9a466c5  
> **71b84da** last commit - second repo |  
> **c99cf5b** fourth commit - second repo |-&gt; Commits made on Node B  
> **7011d3d** third commit - second repo |

==&gt; Commits made on Node B may now be bundled and sent back to Node A

Node B

> $ git bundle create commits.bundle master ^9a466c5  
> Counting objects: 11, done.  
> Delta compression using up to 2 threads.  
> Compressing objects: 100% (3/3), done.  
> Writing objects: 100% (9/9), 775 bytes, done.  
> Total 9 (delta 0), reused 0 (delta 0)

|

Node B File: **commits.bundle**

*All commits made after* ^9a466c5 *(The last commit made in bundle sent from Node A) in this bundle.*

==&gt; On Node A we can now save the commits.bundle in the folder above the local Git repository and do Git Bundle Verify to check that it contains enough of the history to be able to import it.

Node A

> $ git bundle verify ../commits.bundle  
> The bundle contains 1 ref  
> 71b84daaf49abed142a373b6e5c59a22dc6560dc refs/heads/master  
> The bundle requires these 1 ref  
> 9a466c572fe88b195efd356c3f2bbeccdb504102 second commit  
> ../commits.bundle is okay

|

|

Node A File commits.bundle file carries enough of the history to import it (tie to the history of the local repository)

==&gt; We may now, on Node A, fetch the commits in received bundle to a new branch in the local Git reporitiry

> $ git fetch ../commits.bundle master:other-master  
> From ../commits.bundle  
> \* &#91;new branch&#93; master -&gt; other-master

|

|

Node A: Branch other-master now carries all commits received in bundle from Node B

==&gt; The local repository on Node A now contains both all commits made on Node A plus all commits made on Node B as can be seen using command Git Log

Node A

> $ git log --oneline --decorate --graph --all  
> \* 8255d41 (HEAD, master) third commit - first repo  
> | \* **71b84da** (other-master) last commit - second repo **|**  
> | \* **c99cf5b** fourth commit - second repo **|-&gt; fetched commits**  
> | \* **7011d3d** third commit - second repo **|**  
> |/  
> \* 9a466c5 second commit  
> \* b1ec324 first commit

2) Consider to try this out with a Git project on three of my computers (Windows 10, Linux MATE and MacOS on macbook Air)?

==&gt; Consider to try this on the myCppStringPlauground as defined in “Todo: Programming - Consider to understand u8 encoded character literals and strange output using cout formatting?”

==&gt; We already have a Git repository created by Xcode on Macbook Air?

…

3) Consider to think about how this behaviour can be automised with Darwinet (using e-mailed deltas)?

==&gt; So, what do we need in Darwinet for this kind of synchronisation to happen automatically from e-mailed deltas?

…

…

Consider to delve into this feature of Git to synchronise using e-mailed bundles and how this relates to possible Darwinet mechanism?

...

{% endraw %}
