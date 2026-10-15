# Todo: Git and VSCode - Consider to document how to "untrack" files added to Git by VSCode (or possibly also Visual Studio Code or other IDE automating git adds)?

```#bf7fb623``` *As of 2022-01-04 16:06*

[mail plain/text](mail.txt)

{% raw %}
I tried VSCode CMake extension auto,mation to setup my C++ project for CMake build and it added CMakeLists.txt to git without asking me about it...

1) It seems I can use the git command "rm " to make git "untrack" a file (<https://sufiyanyasa.com/blog/git-untrack-file/> )?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro day22 % **git rm --cached** CMakeLists.txt  
> rm 'day22/CMakeLists.txt'  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro day22 % **git status**  
> On branch main  
> Your branch is up to date with 'origin/main'.

> Changes to be committed:  
> (use "git restore --staged &lt;file&gt;..." to unstage)  
> deleted: CMakeLists.txt

> Changes not staged for commit:  
> (use "git add &lt;file&gt;..." to update what will be committed)  
> (use "git restore &lt;file&gt;..." to discard changes in working directory)  
> modified: .vscode/tasks.json  
> modified: playground.cpp  
> modified: playground.h  
> modified: ../day23/xcode/day23/day23.xcodeproj/project.xcworkspace/xcuserdata/kjell-olovhogdal.xcuserdatad/UserInterfaceState.xcuserstate

> **Untracked files**:  
> (use "git add &lt;file&gt;..." to include in what will be committed)  
> .vscode/settings.json  
> CMakeLists.txt  
> build/  
> ../day23/.vscode/settings.json  
> ../day23/xcode/day23/day23.xcodeproj/xcuserdata/kjell-olovhogdal.xcuserdatad/xcdebugger/  
> ../day24/.vscode/settings.json

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro day22 %

...

{% endraw %}
