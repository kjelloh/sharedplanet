# Todo: Programming - Consider to try out and document GitHub best practices for own and external Project collaboration?

```#76b89511``` *As of 2016-07-28 17:13*

[mail plain/text](mail.txt)

{% raw %}
Consider to try out and document some best (or working) practices on how to collaborate with projects on GitHub?

1) Consider how to work with Projects I own?

==&gt; Consider to use GitHub Desktop on Windows?

==&gt; Consider to document how to update local Git repository using different tools?

==&gt; Clion seems to be able to recognise and update local Git repository?

==&gt; GitHub Desktop seems to add knowledge to be able to Sync. with cloned GitHub repository?

WE ARE HERE…

==&gt; It seems on Linux one has to use Git command line (No GitHub Desktop available)?

==&gt; This seems to be a good post on working with Github repositories (<https://help.github.com/categories/managing-remotes/>)?

==&gt; It seems we should clone using HTTPS (Recommended) and possibly use a “Credential Helper” to clone-and-push without having to log in every time (<https://help.github.com/articles/which-remote-url-should-i-use/#cloning-with-https-urls-recommended>)?

==&gt; It seems the workflow consists of "git clone", "git fetch", "git pull", or "git push”

==&gt; "git clone” seems to be to download and bind to a remote repository (<https://help.github.com/articles/cloning-a-repository/>)

> > > “When you create a repository on GitHub, it exists as a remote repository. You can clone your repository to create a local copy on your computer and sync between the two locations”

![](<GitHub HTTPS Clone URL.tiff>)

> > > kjell-olovhogdahl@ubuntu:~/GitHub$ pwd

> > > **/home/kjell-olovhogdahl/GitHub**

> > > kjell-olovhogdahl@ubuntu:~/GitHub$ git **clone** <https://github.com/kjelloh/>**cratchit.git**

> > > Cloning into 'cratchit'...

> > > remote: Counting objects: 31, done.

> > > remote: Compressing objects: 100% (28/28), done.

> > > remote: Total 31 (delta 11), reused 17 (delta 2), pack-reused 0

> > > Unpacking objects: 100% (31/31), done.

> > > Checking connectivity... done.

> > > kjell-olovhogdahl@ubuntu:~/GitHub$ ls

> > > **cratchit**

> > > kjell-olovhogdahl@ubuntu:~/GitHub$

==&gt; "git fetch” seems to be the way to sync. with changes made by others to a remote repository (<https://help.github.com/articles/fetching-a-remote/#fetch>)

> > > “Use git fetch to retrieve new work done by other people. Fetching from a repository grabs all the new remote-tracking branches and tags without merging those changes into your own branches"

==&gt; "git pull” seems to be fetch+merge (<https://help.github.com/articles/fetching-a-remote/#pull>)?

> > > “Because pull performs a merge on the retrieved changes, you should ensure that your local work is committed before running the pull command. If you run into a merge conflict you cannot resolve, or if you decide to quit the merge, you can use git merge --abort to take the branch back to where it was in before you pulled”

"git push” seems to be the way to update remote repository with local commits on a specified branch (<https://help.github.com/articles/pushing-to-a-remote/>)?

> > > “Use git push to push commits made on your local branch to a remote repository”

> > > “The git push command takes two arguments:

> > > • A remote name, for example, origin

> > > • A branch name, for example, master”

2) Consider this GitHub tutorial on workflow best practice (<https://guides.github.com/introduction/flow/>)?

…

…

Consider to delve into this job of documenting GitHub best practices using local tools (GitHub Desktop/svn GIT, Git on Windows and Git on Linux)?

...

{% endraw %}
