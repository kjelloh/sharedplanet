# Todo: Programming - Consider to make an application that synchronises Mail-Todo:s with in-app Todo:s?

```#42890ccc``` *As of 2016-01-02 13:57*

[mail plain/text](mail.txt)

{% raw %}
Would it now be nice to extend current approach of having Mail-Todo:s with a richer Todo application interface and operations?

==&gt; Also see “[Todo: Make the Todo-focus-app although the Force Layout is not yet in place](../09088181/chime.md)”

==&gt; Also See “[Todo: Consider to make the Todo-mentor app relate Todos and generate force-directed graphs](../257904c6/chime.md)”

==&gt; Also see “[Todo: Application - Consider to write a Virtual Coach that uses state-machines in e-mails to get things going?](../5f02cf44/chime.md)”

==&gt; Also See “[Todo: buy a server for virtual secretary](../22505f9f/chime.md) "

1) The application should be able to have an internal representation of Todo:s to be able to work asynchronously with mail-Todo:s (i.e. offline)

2) It must be able to synchronise to and from mail-Todo:s.

3) In its simplest form all edit is done in Mail-Todo:s but the application provides better and different views of them?

4) It must use IMAP interface to be able to read mail-Todo:s from mail-boxes without removing them from the box and without mutating other non-Todo mail.

5) The application should at least be able to list the Todo:s based on second grouping like “Todo: Programming”, “Todo: Eget AB”, “Todo: Darwinet” etc.

6) An extended application should be able to relate Todo:s based on text in the mail “…See…&lt;caption of other Todo&gt;”?

…

Consider to make a simple application that reads mail-Todo:s using IMAP and presents them as a list possibly grouped and related as parses from heading and text?

a) Consider to try Poco c++ library for IMAP protocol (See “Todo: Programming - Consider to study the POCO C++ standard Internet protocol library (ftp, pop3)”?

==&gt; For now only VS-project possible as we at the moment know of no way to build Poco-library into .a libraries. We do not have RAD Studio make scripts and have not tried if GCC built files link with XE code)

b) Consider to try Indy-library IMAP interface components?

c) Consider to use IPWORKS\* component library for IMAP interfacing?

d) What other reliably and maintain IMAP components are there we can consider to use?

…

==&gt;

A) In WIndows 8 mchine, Created project “C:\\Users\\kjell-olov\\Documents\\Embarcadero\\Studio\\Projects\\MyMailTodoSynchronizer\\build”

**WE ARE HERE...**

{% endraw %}
