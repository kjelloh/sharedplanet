# Todo: Darwinet - Consider Darwinet will make cooperation reactive (new states are pushed) rather than imperative (new state are fetched/updated)

```#a6a7a93a``` *As of 2017-03-07 19:15*

[mail plain/text](mail.txt)

{% raw %}
Consider one way of understanding the Darwinet paradigm shift is that current paradigm for synchronizing data (state) is imperative (using package managers and installers) while with Darwinet synchronization is reactive (new state is pushed and applied)?

1) Consider how Darwinet shared package domains makes the user experience different compared to current manual package managers?

...

2) Consider how Darwinet could be able to engage Windows installers on detected installer updates?

==&gt; Consider a Darwinet Domain may contain a Windows Installer to be used to install files on the users computer?  
==&gt; Consider the Darwinet Domain contains an application that negotiates between the Installer state change and the user (to make installer execution a good experience)?

==&gt; Consider the Darwinet Installer Negotiator shows a notification to the user that there is a pending Installer update to apply?  
==&gt; Consider the user should be able to just press some button to engage the installer to do its ”magic”?

==&gt; Consider Darwinet implements a ”Reactive Chain” installer-state-change —&gt; Notification of pedning installer —&gt; User asks Darwinet to engage installer —&gt; Installer is executed —&gt; Darwinet Domain sets ”Installed” flag (to signal and remember synchronization)?  
…

…

Consider to design some Darwinet Mechanism to enable existing ”Imperative Synchronization Mechanisms” to be applied through Darwinet Domain State Change Reactions?  
...

{% endraw %}
