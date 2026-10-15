# Todo: Application - Consider to write a Virtual Coach that uses state-machines in e-mails to get things going?

```#5f02cf44``` *As of 2015-12-11 13:32*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to have e-mails carry state-machines for tasks that suggests what to do next?

1) A task may start as a Todo: with proposals on where to focus ones attention in the proposal for direction  
2) The application may capture this Todo as a state machine defining current state and proposed next steps (new states of attention)  
3) When attending the Todo the user gathers information and proposes new directions to move forward (proposes new states for different directions)  
4) The application models this as a state-machine and encodes it into the Todo-mail (e.g. using xml?)  
5) The mail should still be readable by both the user (plain list of information) and the application state machine (xml)  
6) Each iteration (change) results in the message being resent as an e-mail with the same header (allowing history of changes by listing mails with the same header but different dates and contents)  
…

Consider to elaborate on this idea to see if this may be an extension of my existing Todo: approach to interact with myself?

a) Note: The basic idea here may be to explain this Todo: interaction with one-self as making Emdividuals of oneself collaborate “worker space style”?

{% endraw %}
