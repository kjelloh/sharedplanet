# Todo: Programming - Consider to study the Cpr ("C++ Request") open source library for verb-centric HTTP Protocol Client API?

```#d7d54dd9``` *As of 2016-03-22 13:19*

[mail plain/text](mail.txt)

{% raw %}
Stumbled cross this library in a Cppcon talk and thought it could be interesting to study it in relation to the C++ Protocol Library proposal?

1) The Cppcon 2015 talk “C++ Requests” by Huu Nguyen seems to be published here (<https://channel9.msdn.com/Events/CPP/CppCon-2015/CPPConD02V010>)?

2) His project seems to be hosted at Github (<https://github.com/whoshuu/cpr>)?

==&gt; It seem to use libcurl (<https://curl.haxx.se/libcurl/>) under the hood?

“libcurl is a free and easy-to-use client-side URL transfer library, supporting DICT, FILE, FTP, FTPS, Gopher, HTTP, HTTPS, IMAP, IMAPS, LDAP, LDAPS, POP3, POP3S, RTMP, RTSP, SCP, SFTP, SMTP, SMTPS, Telnet and TFTP. libcurl supports SSL certificates, HTTP POST, HTTP PUT, FTP uploading, HTTP form based upload, proxies, cookies, user+password authentication (Basic, Digest, NTLM, Negotiate, Kerberos), file transfer resume, http proxy tunneling and more!”

3) Consider to study the design of the libcurl API with regards to the C++ Protocol Library I propose to build?

==&gt; Is the implementation FSM-based?

==&gt; How is asynchronous messaging implemented?

==&gt; What can we learn from this library in designing a C++14/17 efficient easy to use Protocol Library?

…

4) Consider to study libwww mentioned by libcurl?

==&gt; Libwww seem to be published here (<https://www.w3.org/Library/>)?

==&gt; It seem to be written in C and to be used for testing protocols?

“Libwww is a highly modular, general-purpose client side Web API written in C for Unix and Windows (Win32). It's well suited for both small and large applications, like browser/editors, robots, batch tools, etc. Pluggable modules provided with libwww include complete HTTP/1.1 (with caching, pipelining, PUT, POST, Digest Authentication, deflate, etc), MySQL logging, FTP, HTML/4, XML (expat), RDF (SiRPAC), WebDAV, and much more. The purpose of libwww is to serve as a testbed for protocol experiments.”

5) Consider to study the WinINet API that ships with the Windows operating system (<https://msdn.microsoft.com/en-us/library/windows/desktop/aa383630(v=vs.85).aspx)>

“The Windows Internet (WinINet) application programming interface (API) enables applications to interact with FTP, and HTTP protocols to access Internet resources”

…

Consider to download and study this C++ library to see what we can learn for other related Todos (e.g. DSL-based protocol engine and message encoding implementation)?

...

{% endraw %}
