# Todo: Programming - Consider to delve into "Keeping it Simple With Go - Erik Engheim" to get a good introduction to Go versus C++, Java, C#?

```#2f237f2f``` *As of 2017-08-03 14:01*

[mail plain/text](mail.txt)

{% raw %}
This talk “Keeping it Simple With Go - Erik Engheim” really gave me some good insights into language mechanics as well as an overview of Go.

1) The talk “Keeping it Simple With Go - Erik Engheim” seems to live here (<https://www.youtube.com/watch?v=zJVtpkxq_X0>)?

2) Consider the high lights of this talk?

==&gt; Go uses “Duck Typing” that seems to be type inference where the inferred type only contains the stuff you really use?

==&gt; It seems with Duck Typing you can use objects through an interface as long as they implement the part of the interface you are really using?

==&gt; It like “if it behaves like a Duck we can treat it as a Duck” (The Duck being what we actually call)?

==&gt; See wikipedia on Duck Typing (<https://en.wikipedia.org/wiki/Duck_typing>)?

==&gt; Go seems to allow structs to be defined with unnamed members (at 30:26 into <https://youtu.be/zJVtpkxq_X0?t=1826>)?

==&gt; In Go “Embedding” seems to mean I define member types without naming them - and still be able to access members members (that is named)?

==&gt; So, having these types…

![](<Go Embedding - If I have these types.tiff>)

==&gt; I can Embed these types unnamed in a struct (Note members have no names but the types are known)...

![](<Go Embedding - I can define a Struct with unnanmed members (types only).tiff>)

==&gt; I can still instantiate an Embedding struct (only type constructors. i.e. type names, required for this)

![](<Go Embedding - I can still instantiate the Embedding struct.tiff>)

==&gt; And now I can still access the members members either using embedded type names - or by inferring type names through using accessed type member names?

![](<Go Embedding - Through Embedding struct I get members members accessible (without Embedding class members being named).tiff>)

==&gt; Note: Go uses “:=“ to mean type inference (e.g., like auto in C++)?

==&gt; Thus, x := r.Point.X refers to member X of r’s member with type Point.

==&gt; And x := r.X means The member named X of the member in r that has such a member name?

==&gt; Hm… This would suggest we get a compiler error if two or more embedded types has the same member name (infer fails to know which one to choose)?

…

…

Consider to remember this Todo as a good lead into the Go language?

...

{% endraw %}
