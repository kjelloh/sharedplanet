# Todo: Programming - Consider to make an application that processes Todo: mails and generates a cross referenced HTML document?

```#9f8b1177``` *As of 2017-02-04 18:45*

[mail plain/text](mail.txt)

{% raw %}
So, can we imagine we can with a small effort make an application that fetches all Todo-mails from my mail account and turns them all into a cross referenced HTML document?

1) Consider to find a good open source library to be able to iterate and fetch mails from my IMAP mail account?

==&gt; Consider vmime GPL open source (<https://www.vmime.org>)?

==&gt; This seesm to be vmime on github (<https://github.com/kisli/vmime>)?

==&gt; This seems to be the book with leads into understanding vmime library (<https://www.vmime.org/public/documentation/book/vmime-book.pdf>)?

==&gt; It seems to support TLS access using OpenSSL (<https://www.vmime.org/about.html>)?

==&gt; This seemx to be a console source code to connect to an IMAP server (TLS support built in) (<https://github.com/kisli/vmime/blob/master/examples/example6.cpp>)?

…

==&gt; Consider ”Todo: Programming - Consider to study the POCO C++ standard Internet protocol library (ftp, pop3)”

==&gt; This seems to be the Poco home (<http://pocoproject.org>)?

==&gt; It seems to support reading of mails from POP3 server (<https://pocoproject.org/docs/Poco.Net.MailInputStream.html>)?

==&gt; This seems to be a Poco add-on for imap (<https://github.com/kmribti/imap>)?

==&gt; Good enough for a simple proof-of-concept?

==&gt; Poco seems to support SMTP sending of e-mails (<https://pocoproject.org/docs/Poco.Net.SMTPClientSession.html>)?

2) Consider what commercial C++ libraries there are with IMAP support?

==&gt; Chilcat seems to be a proven commercial C++ library that supports IMAP (<https://www.example-code.com/vcpp/imap_fetchMimeIndividually.asp>)?

==&gt; This seems to be a stackoverflow thread that lists some MIME options (<http://stackoverflow.com/questions/3038074/parsing-simple-mime-files-from-c-c>)?

==&gt; Possibly these libraries also support IMAP?

==&gt; IP\*Works seem to support IMAP (<https://www.nsoftware.com/ipworks/>)?

==&gt; IP\*Works seem to be available in Embarcadero RAD Studio (<http://cc.embarcadero.com/item/30498>)?

==&gt; It seems one installs it using the Getit installer (<https://forums.embarcadero.com/thread.jspa?messageID=872363>)?

==&gt; Full standard C++ IP\*Works library (With S/IMAP support) seems very expensive (<https://www.nsoftware.com/ipworks/smime/order.aspx>)?

==&gt; This ”Clever Internet Suite v.8.4” seems to be a commercial C++ library for RAD Studio (<http://torry.net/authorsmore.php?id=3059>)?

==&gt; Priced to $552?

3) Consider to design the application as a Functional Reactive Program (piping Todo-mails through a chain of transformations)?

html document =

mail_stream(”[kjell-olov.hogdahl@itfied.se](mailto:kjell-olov.hogdahl@itfied.se)”)

| filter(”Todo:”)

| to_html

| format_section

| append

| cross_reference;

…

Consider to elaborate and try out what imap C++ library to use to get a first version of Todo-mail transform into HTML document application using Reactive Programming?

...

{% endraw %}
