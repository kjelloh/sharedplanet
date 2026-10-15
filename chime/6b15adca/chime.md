# Todo: Card Payment Systems - Note that Card Payment System Interfaces inherently are NOT RESTful

```#6b15adca``` *As of 2015-12-11 16:44*

[mail plain/text](mail.txt)

{% raw %}
Thinking a little about it one realises that Card Payment System Interfaces can never be RESTful ones.

1) Each Card Account has a state which case the same request to be processed based on previous requests to it.

==&gt; E.g. After each transaction authorisation the account waits for either a completion or a reversal regarding that transaction.

2) Consider to identify other states that actors and services keep that affect responses to requests?

==&gt; Maybe intermediate systems are in fact RESTful (duplicate request checks does not count as state)?

…

Elaborate more on this are subject to try and identify what parts are RESTful and what are not?  
...

{% endraw %}
