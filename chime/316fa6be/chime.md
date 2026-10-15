# Todo: Programming - Consider to make an HTML page "automation client" to navigate and "sniff" for user data (e.g. skatteverkets e-services)?

```#316fa6be``` *As of 2016-04-29 19:01*

[mail plain/text](mail.txt)

{% raw %}
Could we imagine to make a component that is able to interface with e-services user interfaces to navigate, trigger services and ”sniff” for user data output (e.g. skatteverkets e-services, Facebook client, cooperation user interfaces)?

==&gt; Also see ”[Todo: Darwinet - Design a mechanism to synch. Web-info with Darwinet stored data](../7c517b26/chime.md)”  
==&gt; Also see ”[Todo: Write an app that auto-enters invoices on Nordea web-bank page](../3d0ac5d8/chime.md)”  
==&gt; Also see ”[Todo: API-fy Web page user interfaces to enable programatic access](../7842208f/chime.md)”

1) Consider to ”sniff” Skatteverkets e-servies to automate fetching of tax declaration data and optionally send finalized declaration digitally to skatteverket?

==&gt; Consider to component to use a shared (e.g. bittorrent, darwinet) template that defines how the current skatteverket e-service user interface is designed?  
==&gt; Consider to have the component suggest URL:s to visit (once logged in) and to detect when data is available and parse it into the client application (e.g., skattekonto transactions)?  
==&gt; Consider to have the component automate the NE form user interface to automatically enter the data into the form?

2) Consider to implement a template to automate Facebook through existing Web browser user interface?

3) Consider to implement a template to automate other social network Web Browser user interfaces?

4) Elaborate on how south an automation component may implement deferred log-in (automate the log-in using locally stored credentials, i.e. password)?

5) Consider if we can add two-factor authorization for local password retrieval using e.g. Yubikey (https://www.yubico.com)?

==&gt; How can we allow automation of Web-swervices with Yubikey log-in (is it even a problem)?

...

Consider to elaborate on this idea of being able to automate existing We services user interfaces based on shared (and crowd-updated) template for popular Web services?

{% endraw %}
