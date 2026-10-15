# Todo: Programming - Consider to understand the e-mail protocols and authentication methods applied and programming libraries to apply them in code?

```#d565333f``` *As of 2016-03-27 19:26*

[mail plain/text](mail.txt)

{% raw %}
Seems it would be a good idea to delve into understanding available e-mail protocols and C++ libraries available to make use of them in applications?

1) Consider to study the VMime C++ library for e-mail access (<http://www.vmime.org>)?

2) Consider to understand the Indy VCL Library and TIdIMAP4 explicitly (<http://www.indyproject.org/Sockets/Download/svn.EN.aspx>)?

==&gt; It is upgraded for RAD Studio Seattle but new development seem uncertain?

==&gt; Actual Source and project files seem to be accessible here (<https://svn.atozed.com:444/svn/Indy10/tags/Indy%2010.6.2%20-%20Seattle%20RTM/Lib/>)?

==&gt; Log in using User ID: Indy-Public-RO, No Password

==&gt; Indy help for TIdMAP4 seem to live at this site (<http://www.indyproject.org/docsite/html/frames.html?frmname=topic&frmfile=TIdIMAP4.html>)?

==&gt; Here seem to be a copy of RFC for IMAP (<http://tools.ietf.org/html/rfc3501>)

...

3) Consider to study the C++ Poco library that contains web-protocol implementations (<http://pocoproject.org>)?

==&gt; Also see explicit “Todo: Programming - Consider to study the POCO C++ standard Internet protocol library (ftp, pop3)”

4) Consider to compare with 1599$ IP\*Works VCL components (<http://www.nsoftware.com/ipworks/>)?

==&gt; Provided as Third Party extension (but limited functionality)?

…

5) Consider to study and understand the IMAP protocol (<https://sv.wikipedia.org/wiki/Internet_Message_Access_Protocol>)?

==&gt; The RFC “INTERNET MESSAGE ACCESS PROTOCOL - VERSION 4rev1” Seem to be published here (<https://tools.ietf.org/html/rfc3501>)?

+----------------------+

|connection established|

+----------------------+

||

\\/

+--------------------------------------+

| server greeting |

+--------------------------------------+

|| (1) || (2) || (3)

\\/ || ||

+-----------------+ || ||

|Not Authenticated| || ||

+-----------------+ || ||

|| (7) || (4) || ||

|| \\/ \\/ ||

|| +----------------+ ||

|| | Authenticated |&lt;=++ ||

|| +----------------+ || ||

|| || (7) || (5) || (6) ||

|| || \\/ || ||

|| || +--------+ || ||

|| || |Selected|==++ ||

|| || +--------+ ||

|| || || (7) ||

\\/ \\/ \\/ \\/

+--------------------------------------+

| Logout |

+--------------------------------------+

||

\\/

+-------------------------------+

|both sides close the connection|

+-------------------------------+

==&gt; This seem like a good page explaining the basic flow of IMAP mail fetch (<http://www.codeproject.com/Articles/411018/Understanding-the-insides-of-the-IMAP-mail-protoco>)?

==&gt; Open Connection

==&gt; Authenticate (our access to a mailbox)

==&gt; 6.2.3. LOGIN Command

==&gt; Get folder list

==&gt; 6.3.8. LIST Command

==&gt; Select mail folder

==&gt; 6.3.1. SELECT Command

==&gt; Get message

==&gt; 6.4.5. FETCH Command

Consider to compare these libraries and see if to go with one of them or continue to search for a “true” C++11 and beyond sustainable library?

...

{% endraw %}
