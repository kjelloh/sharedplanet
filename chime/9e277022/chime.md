# Todo: Programming - Consider to understand the different Git Workflows?

```#9e277022``` *As of 2016-04-05 20:47*

[mail plain/text](mail.txt)

{% raw %}
It seems there are a number of different applied workflows when using Git for version control of source code?

1) Consider to study the Github workflow leads here (<https://help.github.com/articles/what-is-a-good-git-workflow/>)

==&gt; Github flow seem to be a branched based workflow (<https://guides.github.com/introduction/flow/>)?

![](Github_flow_create_branch.tiff)

“When you create a branch in your project, you're creating an environment where you can try out new ideas.”

![](Github_workflow_Commit_to_branch.tiff)

“Whenever you add, edit, or delete a file, you're making a commit, and adding them to your branch.”

![](Github_workflow_open_pull_request.tiff)

“Pull Requests initiate discussion about your commits. “

==&gt; Q: Where does the pull-request discussion live (on the Github server)?

==&gt; Q: Is it possible to e-mail a pull-request (as it seem possible to mail git repositories round)?

“If you're using a Fork & Pull Model, Pull Requests provide a way to notify project maintainers about the changes you'd like them to consider.”

==&gt; Q: What is the “Fork & Pull Model”?

==&gt; A “Fork” seem to be detached copy of a Git repository (<https://help.github.com/articles/fork-a-repo/>)

“"

“If you're using a Shared Repository Model, Pull Requests help start code review and conversation about proposed changes before they're merged into the master branch.”

==&gt; Q: What is the “Shared Repository Model”?

![](Github_workflow_discuss_pull_requests.tiff)

“If someone comments that you forgot to do something or if there is a bug in the code, you can fix it in your branch and push up the change.”

==&gt; Seems one then uses Github server to push/pull to exchange changes to the branch?

==&gt; Q: As the whole repository is always stored together the push/pull always transfer the while repository around (possibly piggy-backing the branches of other developers)?

![](Github_workflow_deploy.tiff)

“Once your pull request has been reviewed and the branch passes your tests, you can deploy your changes to verify them in production. If your branch causes issues, you can roll it back by deploying the existing master into production.”

==&gt; Q: What does “deploy” imply (it does not seem to involve merge)?

==&gt; Q: What does mean to rollback by “deploying existing master” into production?

![](Github_workfloe_merge_to_master.tiff)

“Once merged, Pull Requests preserve a record of the historical changes to your code.”

==&gt; Q: Why is it the pull-request-comments and not the commit comments that preserve the record of changes in the branch (commits on the branch does not survive the merge)?

2) Consider to understand the “rebase workflow” as described here (<http://randyfay.com/content/rebase-workflow-git>)?

a) Sidenote: Consider what we can learn from these workflows in relation to how darwinet should behave for shared file folders?

==&gt; Consider that Darwinet should apply some default “workflow” in how it handles branching and merging of conflicting Delta-trails?

...

…

Consider to study interesting Git Workflows to see what we can learn, how they relate to possible Darwinet File-folder-behavior and what workflow to use for myself?

...

{% endraw %}
