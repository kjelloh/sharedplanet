# Todo: Darwinet - Consider to delve into available C++ information and solutions to implement the MIV as a Confluent Persistent (Immutable) Data Structure?

```#1eb47a76``` *As of 2017-01-30 19:36*

[mail plain/text](mail.txt)

{% raw %}
The more I delve into the world of functional programming and Persistent (Immutable) Data Structures it seems to me that the Darwinet MIV is actually a Confluent Persistent Data Structure and we may thus implement it using solutions available in C++ or other languages where these data types already occur?

1) Consider good talks on the subject?

==&gt; Consider this seemingly really good lecture ”1. Persistent Data Structures, MIT OpenCourseWare” (<https://www.youtube.com/watch?v=T0yzrZL1py0>)

==&gt; The lecture is about Partially and Confluent Persistence and touching on Functional Data Structures.

**==&gt; They are mostly about concepts and cost (not about actual implementation)**

==&gt; In Functional Persistence we require old versions to be referentially the same (change requires references to change) while basic persistence only require ”query equality” (same query returns same result in perserved state)

==&gt; At 23:50 he actually defines a ”modification” as (version, field, value) which is exactly a MIV Delta (state, element path, operation) :)

==&gt; At 1:04:30 he starts on Confluent Persistence.

==&gt; All lectures in the same course ”Advanced Data Structures” seems to be here (<https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-851-advanced-data-structures-spring-2012/lecture-videos/>)?

==&gt; Consider ”Functional C++ for Fun and Profit by Phil Nash”, the author of test framework Catch (<https://www.youtube.com/watch?v=YgcUuYCCV14>)?

==&gt; Consider this talk by Any Wingo ”Optimizing with persistent data structures - LLVM Cauldron 2016” (<https://www.youtube.com/watch?v=KYoDyM6l_5s>)?

==&gt; Consider this talk by Bartosz Milewski’s ”Functional Data Structures in C++” (<https://www.youtube.com/watch?v=OsB09djvfl4>)?

…

2) Consider good papers and web-posts on the subject?

==&gt; Consider the fameous and often referred to paper ”Purely Functional Data Structures, Chris Okasaki, September 1996 CMU-CS-96-177” (<http://www.cs.cmu.edu/~rwh/theses/okasaki.pdf>)?

==&gt; Consider this paper on a Confluent Trie for version control of file directory structures ”Confluently Persistent Tries for Efficient Version Control, Erik D. Demaine, Stefan Langerman, Eric Price” (<http://erikdemaine.org/papers/ConfluentTries_Algorithmica/paper.pdf>)?

==&gt; Consider this paper ”Making Data Structures Persistent, JAMES R. DRISCOLL, NEIL SARNAK, DANIEL D. SLEATOR, ROBERT E. TARJAN, Received August 5, 1986” (<http://www.cs.cmu.edu/~sleator/papers/making-data-structures-persistent.pdf>)

3) Consider good web-pages and posts on the subject?

==&gt; Consider wikipedia ”Purely functional data structure” (<https://en.wikipedia.org/wiki/Purely_functional_data_structure>)?

==&gt; Seems a Purely Functional Data Structure requires an implementation that ensures immutability in all circumstances (multi-threading, in-memory access, type casting, const removal etc.)?

==&gt; Seems one way is to encapsulate the data structure so that access must go through function calls that ensure immutability under all conditions?

==&gt; Consider to follow up on the list published on stackexchange (<http://cstheory.stackexchange.com/questions/1539/whats-new-in-purely-functional-data-structures-since-okasaki#answer-1550>)?

...

3) Consider open source projects implementing Presistent Data Structures?

==&gt; Consider ”Immutable++” (<https://github.com/rsms/immutable-cpp>)?

…

…

Consider to update these lists of sources for Confluent Persistent Data Structures in C++

{% endraw %}
