# Todo: C++ Text - Consider to follow up on James McNellis talks on text encodings?

```#2b834824``` *As of 2016-11-18 13:12*

[mail plain/text](mail.txt)

{% raw %}
1) His talk seems to live here (<https://www.youtube.com/watch?v=MW884pluTw8>)?

==&gt; Consider to follow up on the C++ standard proposal N3336 he mentioned at 1:18:30?

==&gt; Consider to follow up on the C++ standard proposal N3572 he mentioned at 1:19:00?

![](<N3572 Proposal Summary.tiff>)

==&gt; Consider to follow up on his references?

![](<McNellis BoostCon2014 C++ Unicode References.tiff>)

==&gt; Consider to follow up on 1:21:45 Q&A about source file encodings?

2) He seems to be scheduled to hold the same talk on Meeting C++ in Berlin 2016 (<http://www.meetingcpp.com/index.php/tv16/items/31.html>)?

==&gt; Hopefully it will be recorded and posted to youtube?

…

3) There seem to be some C++ standard proposals to adress Unicode support?

==&gt; The N3336 (<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3336.html>)

==&gt; The N3572 (<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3572.html>)?

4) Consider to decompose his talk into my hunch of layering Text processing into ”Semantics” (meaning), Script (Character Set), Encoding (representation) and Storage (Code Units)?

==&gt; Could we argue that things like to_upper, to_lower, sort, search etc. belongs to the semantics /meaning) domain (we need to know what the characters we process actually mean)?

==&gt; Could we argue that Unicde, Iso-latin-1, ASCII belongs to the script domain (defines what characters to represent and how (what code points) to represent them)?

==&gt; Could we argue that UCS2, UTF-8, UTF-16 etc. belong to the encode domain (how we represent the code points in code units)?

==&gt; Could we argue that std::string, std::wstring, char&#91;&#93;, char_t etc. belongs to the storage domain (what data structures used to represent the code units)?

…

{% endraw %}
