# Todo: Programming - Consider the best way to install and keep updated the llvm tool-chain on Linux?

```#1fccd5dd``` *As of 2016-04-13 00:38*

[mail plain/text](mail.txt)

{% raw %}
So, what is actually the best way to install and keep updated the latest llvm-tool-chain on linux?

-1) Consider the gihub mirror of llvm parts (<https://github.com/llvm-mirror>)?

==&gt; Q: If we pull - how do we keep pulled repository updated?

==&gt; Q: Do we need to rebuild our downloaded source?

==&gt; Consider to try out github mirrored clang “install” instructions (<https://github.com/llvm-mirror/clang/blob/master/INSTALL.txt>)?

==&gt; git Pull clang to local “$LLVM_SRC_ROOT/tools/clang”?

<https://github.com/llvm-mirror/clang.git>

==&gt; Build root llvm or just clang sub-directory as instructed in “$LLVM_SRC_ROOT/GettingStarted.htm”?

==&gt; $LLVM_SRC_ROOT/tools/clang$ **make install**

==&gt; It seems we should regularly do “git pull —rebase” from github to update (merge) local llvm repositories (<https://www.atlassian.com/git/tutorials/syncing/git-fetch>)?

==&gt; It seems the best way to synchronise is to do a “git pull —rebase” automatically?

$LLVM_SRC_ROOT/tools/clang$ git config --global **branch.autosetuprebase** always

$LLVM_SRC_ROOT/tools/clang$ **git pull **

==&gt; Note: The “always” configuration makes “git pull” default to “git pull --rebase"

“This simply moves your local changes onto the top of what everybody else has already contributed."

==&gt; Pull is a fetch followed by a merge (fetch updates local repository with remote branches and merge makes local HEAD reference last remote commit)?

==&gt; Consider this tutorial (<https://www.atlassian.com/git/tutorials/syncing/git-pull>)

“You can think of git pull as Git's version of svn update.”

==&gt; The “git pull” in a git repository tree seem to default to pulling from remote repository remembered by git from last pull?

==&gt; This test in bash shell on windows 10.

> kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 /c/git/GSL (master)  
> $ **git pull**  
> Already up-to-date.

> kjell-olovhogdahl@KJELL-OLOVHA74E MINGW64 /c/git/GSL (master)  
> $

1) Consider the official package distributions of Debian 16.04?

{% endraw %}
