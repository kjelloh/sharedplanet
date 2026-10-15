# Todo: Programming - Consider what is the best way to just track (use) a Github Repository (e.g. for usage by own projects)?

```#6fc10d5b``` *As of 2016-07-15 14:36*

[mail plain/text](mail.txt)

{% raw %}
It is nto evident how one should do to be able to clone a Github project and be able to track updates without accidentally push changes back to Github?

-1) Consider to document current found best practice?

==&gt; It seems to me the way to go is to **clone** to ge the local copy

==&gt; And then **git fetch** + **git reset —hard origin** to update the local files to that of the lastest remote state?

1) It seems git clone from someone else repository does not allow push (so we are safe)?

==&gt; I tried cloning “<https://github.com/boost-experimental/msm-lite>” using GitHub desktop and then tried git push and that was denied (error 403 = access denied)

![](<Github clone in Desktop.tiff>)

![](<Github Clone swith to Desktop Dialog.tiff>)

![](<Github Clone in Desktop - local folder dialog.tiff>)

![](<Github Desktop - Cloned Repository added.tiff>)

==&gt; I now opened “Gitshell” (installed with Github Desktop) and inspected the remote settings of the cloned project

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub&gt; ls

> Directory: C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub

> Mode LastWriteTime Length Name  
> ---- ------------- ------ ----  
> d----- 7/15/2016 1:18 PM msm-lite  
> d----- 7/13/2016 7:34 PM tree

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub&gt; cd .\\msm-lite\\  
> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\msm-lite &#91;master ≡&#93;&gt; git remote -v  
> origin <https://github.com/boost-experimental/msm-lite.git> (fetch)  
> origin <https://github.com/boost-experimental/msm-lite.git> (push)  
> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\msm-lite &#91;master ≡&#93;&gt;

==&gt; It seems git push is not allowed (error 403 = Forbidden)

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\msm-lite &#91;master ≡&#93;&gt; git push  
> remote: Permission to boost-experimental/msm-lite.git denied to kjelloh.  
> fatal: unable to access '<https://github.com/boost-experimental/msm-lite.git/':> The requested URL returned error: 403  
> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\msm-lite &#91;master ≡&#93;&gt;

==&gt; So, at least we are safe fro accidentally update the remote?

2) It seems Github Desktop Sync is safe from updating remote repository (unless it is mine) but will not force revert locally changed files?

==&gt; I changed a file of a remote repository that is not mine (but that I had cloned using Github Desktop)

![](<Tortoise Git show cloned rep file changed.tiff>)

==&gt; It seems Github Desktop Sync operation does nothin although the local file has changed?

==&gt; I clicked &lt;Sync&gt; and it shows progress for a while but it ends without reporting any operations.

==&gt; I now committed the change to the master branch of cloned remote.

![](<Tortoise Git Commit locally chnaged file of romote rep clone.tiff>)

==&gt; The Github Desktop now shows the commit in the changes list.

![](<Github Desktop shows local comit to cloned remote.tiff>)

==&gt; Github fails the Sync operation for local changes to cloned remote repository that is not mine

![](<Github Desktop fails to sync local changes to cloned remote repository that is not mine.tiff>)

==&gt; So it seems we are safe form accidentally Github Desktop Sync local changes to remote that is not mine?

2) It seems the way to ensure local clone exactly mirrors the remote is to **git fetch** and then **git reset —hard origin**?

==&gt; The git fetch seems to just update the local copy of the remote state (all commits updated according to the remote)

  
> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\msm-lite &#91;master ↑&#93;&gt; git fetch

==&gt; The git reset —hard just re-sets the HEAD to the last commit (restoring the working file)

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\msm-lite &#91;master ↑&#93;&gt; git reset --hard  
> HEAD is now at 05d8b49 Test that accidental changes to cloned rep does not Github Desktop Sync back to the remote?

==&gt; Providing the reference “origin” will re-set the HEAD to the last commit of the remote (origin is just an alias to the HEAD commit of the remote copy)?

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\msm-lite &#91;master ↑&#93;&gt; git reset --hard origin  
> HEAD is now at 5dd2691 &#91;thread-safety&#93; Added mutex for thread safe process_event  
> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\msm-lite &#91;master ≡&#93;&gt;

==&gt; The locally changed (but not committed) working file was now silently replaced with the HEAD of the last fetched remote.

==&gt; This post seems to contain some good leads (<https://git-scm.com/blog>)?

==&gt; Note: The images may be good but I seem to not like the way the author explains what is going on?

3) It seems Github Fork is not the way to just use another Github repository?

==&gt; When one forks a project in Github it is cloned to ones account as a new repository but with meta-data to remember where it was forked from?

=&gt;= A fork behaves just as any repository but the local clone uses the Github repository with the fork (NOT the original repository we would like to track and use)?

==&gt; To delet a fork one has to delete the repository of the fork.

==&gt; First enter the repository that contains the fork.

==&gt; In the URL add “/settings” (e.g., to get “<https://github.com/kjelloh/tree/settings>”

==&gt; Then scroll down to “Danger Zone” settings and click “Delete this Repository"

![](<Github repository Danger Zone settings.tiff>)

==&gt; Follow the instructions to delete the repository.

{% endraw %}
