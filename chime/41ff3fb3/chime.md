# Todo: Darwinet - Ensure file system knows when applications opens up and closes down

```#41ff3fb3``` *As of 2015-08-13 12:55*

[mail plain/text](mail.txt)

{% raw %}
For Darwinet to recognize main delta steps (and application MIV session transactions) it is important that the MIV is made aware of when an application opens up and when it closes down. If the MIV knows when an application closes down it is able to know that at that point the state of the MIV will be consistent with the changed made by the app. Whilst an application is open it may create inconsistent changes (not yet finalized and possibly not of long term interest to the user or app).

1) Make the API require an app to announce itself by opening a kind of ”session”. This may be implicitly accomplished by requiring the app to acquire a view. Or maybe we should require the application to actually open a session first and then within that session open one or more views?  
2) Make Darwinet record the event of opening a session and views. These events (deltas) may then later be used to identify these main milestones in the delta trail. One may for example speculate that Darwinet should when a session is closed compress all deltas from start to end of the session into a transaction. When later traveling the delta trail one should not be allowed to go to a view within the session as these states can’t be secured to be consistent (MIV sate and application state not synchronized and of no interest for later time travel).  
3) Especially the Darwinet file system must be aware of session open and close. Now file close may serve as consistent delta trail states but a file may be opened and closed several time during a session. So Darwinet should compress all file changes to only one transaction from session open to close. Any file states within a session may not be consistent with the activity of the application although they are consistent with the save point. Word for example autosaves regularly although these auto-save points may or may not be delta states we like to later go back to as they are part of the Word file history mechanism and may not mix well with Darwinet delta trail application. For example, movie a Darwinet view to one of the autosave states within a word session may confuse Word as the file state and the word recorded state may be inconsistent (word may use the registry to remember states?).

{% endraw %}
