# Todo: Programming - Consider to get the grips on how Git version control works?

```#77205aac``` *As of 2016-04-04 14:59*

[mail plain/text](mail.txt)

{% raw %}
The version control tool Git is developed for distributed development of source code projects and is very popular. But what do I need to know to actually use it correct and in the most beneficial way as possible?

1) Locally Git seem to store a local copy of the whole project repository with all the change history (<https://git-scm.com/blog/2010/04/11/environment.html>)?

“... just one .gitdirectory in the root of your project.”

==&gt; The “.git” local folder seems to be the “repository” (<https://git-scm.com/book/en/v2/Git-Basics-Getting-a-Git-Repository>)?

“You can get a Git project using two main approaches. The first takes an existing project or directory and imports it into Git. The second clones an existing Git repository from another server.”

==&gt; Sidenote: Already here a newbie will be confused as to what is a “project”, what is a “Repository” and what is a “Directory”?

2) Consider this site to find leads to Git concepts (<https://www.sbf5.com/~cduan/technical/git/git-1.shtml>)?

“The purpose of Git is to manage a project, or a set of files, as they change over time. Git stores this information in a data structure called a repository.”

“The Git repository is stored in the same directory as the project itself, in a subdirectory called .git. Note differences from central-repository systems like CVS or Subversion:

• There is only one .git directory, in the root directory of the project.

• The repository is stored in files alongside the project. There is no central server repository.”

“A git repository contains, among other things, the following:

• A set of commit objects.

• A set of references to commit objects, called heads.”

“A head is simply a reference to a commit object. Each head has a name."

“A commit object contains three things:

• A set of files, reflecting the state of a project at a given point in time.

• References to parent commit objects.”

==&gt; Side note: A Git Commit seem to correspond to a Darwinet Delta (parent defines the previous state or states in case of a merge)?

> > “----&gt; time -----&gt;

> > (A) &lt;-- (B) &lt;-- (C)

> > ^

> > |

> > master

> > ^

> > |

> > HEAD

where (A), (B), and (C) are the first, second, and third commits, respectively.”

==&gt; Seems “HEAD” is the reserved name of the current head (in effect the current state of the project as defined by the commit HEAD is referencing?

==&gt; Seems if we only work locally we may create a git project/repository in any folder using “project-folder&gt;git init”?

> “ &gt;mkdir &#91;project&#93;  
> &gt;cd &#91;project&#93;  
> &gt;**git init**

> This will create a .git directory in the &#91;project&#93; directory."

==&gt;  Consider this page to understand branching (<https://www.sbf5.com/~cduan/technical/git/git-2.shtml>)?

“The terms “branch” and “head” are nearly synonymous in Git. Every branch is represented by one head, and every head represents one branch.”

==&gt; Seems “head” (referencing a “commit”) corresponds to darwinet “state” in a delta-trail?

> > “(A) -- (B) ------- (C)

> > | |

> > fix-headers master

> > |

> > HEAD”

==&gt; Seems the “branch” fix-headers is simply a named “head” currently referencing the (B) commit?

==&gt; Seems “git branch” just creates a named “head” (in effect enabling commits to use the named head as parent)?

==&gt; Syntax seem to be "git branch &#91;new-head-name&#93; &#91;reference-to-(B)&#93;”

&gt;**git branch** fix-headers HEAD^

==&gt; Seem to mean create named head “fix-headers” and make it refer to the parent of the commit referenced by current HEAD (See tree above)?

==&gt; Seems “git checkout” sets the commit the HEAD references and updates the local folder file states as defined by the state of that commit?

&gt;**git checkout** fix-headers

> ------------------  
> / |  
> (A) -- (B) -- (C) |  
> | |  
> master fix-headers  
> |  
> HEAD

&gt;**git commit** -a

> “ +-------------- (D)  
> / |  
> (A) -- (B) -- (C) |  
> | |  
> master fix-headers  
> |  
> HEAD"

==&gt; Seems “git commit” stores a new commit object (D) an links it into the trail of commits ( D-parent set to B and fix-headers set to D)

**WE AER HERE…**

3) Consider to understand TortoiseGit Log Graph feature?

==&gt; Consider to understand this snapshot of the Grapg in the log of cloned github GSL library?

![](TortosieGit_log_graph.tiff)

==&gt; Seems the lines to the left just applies enumerated colours to branch-line 1…8 (<http://stackoverflow.com/questions/6198277/what-do-the-colours-mean-in-the-tortoisegit-log-window>)

“The colors of the branch lines on the left aren't significant and don't correspond to the branch bar colors:

• BranchLine1: Black

• BranchLine2: Red

• BranchLine3: Green

• BranchLine4: Blue

• BranchLine5: Gray

• BranchLine6: Olive

• BranchLine7: Teal

• BranchLine8: Purple”

...

{% endraw %}
