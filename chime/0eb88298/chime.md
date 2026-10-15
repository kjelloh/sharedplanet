# Todo: Darwinet - propose a contract for node to node communication

```#0eb88298``` *As of 2015-03-29 14:10*

[mail plain/text](mail.txt)

{% raw %}
Intially we propose SMTP sending and IMAP receiving of mailed node to node messaging.

try to state a more protocol independent contract for node to node messing protocol to enable alternative protocols to be applied.

1. Define if node to node messing needs to be queue based (like e-mail servers)
2. Define a protocol selection algorithm. A node sending to another node shall use this protocol to decide on what protocol (or protocols) to use to message the other node.
3. Define how nodes shall exchange messaging protocol abilities (the protocols they accept incoming messages on)
4. Define a Darwinet protocol stack. We seem to have to define at least representation (encryption, text encoding and data encoding), network (addressing) and transport?

{% endraw %}
