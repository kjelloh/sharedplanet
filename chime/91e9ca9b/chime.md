# Todo: C++ - Consider to investigate and try out good ways to read and parse e-mail messages from an IMAP Server?

```#91e9ca9b``` *As of 2017-02-07 14:08*

[mail plain/text](mail.txt)

{% raw %}
If only we had a good IMAP server e-mail parser we could do some fun stuff with all my Todo-mails (and possibly other IMAP relates stuff)?

==&gt; Also see “[Todo: C++ - Consider ways to turn Callback based asynchronous mechanism into a Reactive Observable model?](../4234851e/chime.md)"

==&gt; Also See “[Todo: Programming - Consider to make an application that processes Todo: mails and generates a cross referenced HTML document?](../9f8b1177/chime.md)”

==&gt; Also see “[Todo: Programming - Consider to make an application that synchronises Mail-Todo:s with in-app Todo:s?](../42890ccc/chime.md)”

1) Consider to try out Embarcadero RAD Studio specific solutions?

==&gt; Consider to try Indy-library IMAP interface components?

==&gt; See “W:\\workplace\\RAD_Studio\\MyMailTodoSynchronizer” on my Windows 10 machine (both Indy and IP\*Works VCL for IMAP)

==&gt; Consider to use IPWORKS\* component library for IMAP interfacing (<http://cc.embarcadero.com/item/30498>)?

==&gt; See “W:\\workplace\\RAD_Studio\\MyMailTodoSynchronizer” on my Windows 10 machine (both Indy and IP\*Works VCL for IMAP)

==&gt; It seems one installs IP\*Works using the Getit installer (<https://forums.embarcadero.com/thread.jspa?messageID=872363>)?

==&gt; NOTE: Works only with Classic bcc32 or 64-bit bcc64 C++ compilers.

**==&gt; NOTE: Does not link if compiled with bcc32c 32-bit C++11 compiler (could be IP\*Works package does not provide 32-bit o-files, or the library path must be modified for bcc32c?)**

==&gt; Using the IP\*Works IMAP component we seem to be able to interact with the [darwin2@itfied.com](mailto:darwin2@itfied.com) account :)

> > CLIENT Direction=2 Message=Connecting to IMAP server.

> > CONNECT:: ConnectionEvent=Remote host connection complete. StatusCode=0 Description=OK

> > SERVER -&gt; CLIENT Direction=1 Message=\* OK &#91;CAPABILITY IMAP4rev1 LITERAL+ SASL-IR LOGIN-REFERRALS ID ENABLE IDLE STARTTLS AUTH=PLAIN&#93; Dovecot (Ubuntu) ready.

> > SERVER &lt;- CLIENT Direction=0 Message=x0000 LOGIN "[darwinet2@itfied.se](mailto:darwinet2@itfied.se)" "darw1n3t2"

> > SERVER -&gt; CLIENT Direction=1 Message=x0000 OK &#91;CAPABILITY IMAP4rev1 LITERAL+ SASL-IR LOGIN-REFERRALS ID ENABLE IDLE SORT SORT=DISPLAY THREAD=REFERENCES THREAD=REFS THREAD=ORDEREDSUBJECT MULTIAPPEND URL-PARTIAL CATENATE UNSELECT CHILDREN NAMESPACE UIDPLUS LIST-EXTENDED I18NLEVEL=1 CONDSTORE QRESYNC ESEARCH ESORT SEARCHRES WITHIN CONTEXT=SEARCH LIST-STATUS SPECIAL-USE BINARY MOVE&#93; Logged in

> > SERVER &lt;- CLIENT Direction=0 Message=x0001 LIST "" "\*"

> > SERVER -&gt; CLIENT Direction=1 Message=\* LIST (\\HasNoChildren) "." "Deleted Messages"

> > LIST:: Mailbox=Deleted Messages Separator=. Flags=(\\HasNoChildren)

> > SERVER -&gt; CLIENT Direction=1 Message=\* LIST (\\HasNoChildren) "." "Sent Messages"

> > LIST:: Mailbox=Sent Messages Separator=. Flags=(\\HasNoChildren)

> > SERVER -&gt; CLIENT Direction=1 Message=\* LIST (\\HasNoChildren) "." INBOX

> > LIST:: Mailbox=INBOX Separator=. Flags=(\\HasNoChildren)

> > SERVER -&gt; CLIENT Direction=1 Message=x0001 OK List completed.

> > SERVER &lt;- CLIENT Direction=0 Message=x0002 EXAMINE "INBOX"

> > SERVER -&gt; CLIENT Direction=1 Message=\* FLAGS (\\Answered \\Flagged \\Deleted \\Seen \\Draft $NotJunk)

> > SERVER -&gt; CLIENT Direction=1 Message=\* OK &#91;PERMANENTFLAGS ()&#93; Read-only mailbox.

> > SERVER -&gt; CLIENT Direction=1 Message=\* 13 EXISTS

> > SERVER -&gt; CLIENT Direction=1 Message=\* 0 RECENT

> > SERVER -&gt; CLIENT Direction=1 Message=\* OK &#91;UIDVALIDITY 1378822323&#93; UIDs valid

> > SERVER -&gt; CLIENT Direction=1 Message=\* OK &#91;UIDNEXT 14&#93; Predicted next UID

> > SERVER -&gt; CLIENT Direction=1 Message=\* OK &#91;HIGHESTMODSEQ 1&#93; Highest

> > SERVER -&gt; CLIENT Direction=1 Message=x0002 OK &#91;READ-ONLY&#93; Examine completed (0.004 secs).

> > SERVER &lt;- CLIENT Direction=0 Message=x0003 FETCH 1 (FLAGS INTERNALDATE RFC822.SIZE ENVELOPE BODYSTRUCTURE)

> > SERVER -&gt; CLIENT Direction=1 Message=\* 1 FETCH (FLAGS (\\Seen $NotJunk) INTERNALDATE "26-Jul-2013 16:01:39 +0200" RFC822.SIZE 1183 ENVELOPE ("Fri, 26 Jul 2013 16:00:37 +0200" "darwinet delta" NIL NIL NIL ((NIL NIL "darwinet2" "[itfied.se](http://itfied.se/)")) NIL NIL NIL NIL) BODYSTRUCTURE ("text" "plain" ("charset" "us-ascii") NIL NIL "7bit" 35 4 NIL NIL NIL NIL))

> > INFO:: Size=35 MessageDate=Fri, 26 Jul 2013 16:00:37 +0200 From= MessageId=1 Flags=(\\Seen $NotJunk) Subject=darwinet delta

> > SERVER -&gt; CLIENT Direction=1 Message=x0003 OK Fetch completed.

> > SERVER &lt;- CLIENT Direction=0 Message=x0004 LOGOUT

> > SERVER -&gt; CLIENT Direction=1 Message=\* BYE Logging out

> > SERVER -&gt; CLIENT Direction=1 Message=x0004 OK Logout completed.

> > CONNECT:: ConnectionEvent=Remote host disconnected. StatusCode=0 Description=OK

2) The Poco C++ library does not seem to support IMAP (<http://pocoproject.org>)

Also see See “Todo: Programming - Consider to study the POCO C++ standard Internet protocol library (ftp, pop3)”

==&gt; For now only VS-project possible as we at the moment know of no way to build Poco-library into .a libraries. We do not have RAD Studio make scripts and have not tried if GCC built files link with XE code)

…

Consider to update this Todo when more information is available?

...

{% endraw %}
