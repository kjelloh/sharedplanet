# Todo: Programming - Consider to implement Code Point and Encode aware "strings" as a C++ library?

```#1c192a58``` *As of 2016-07-14 20:22*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to try and implement Code Point and Encode Aware (CPEA) “strings” as a C++ library?

1) Consider a good name for the Code Point and Encode Aware (CPEA) “strings”?

==&gt; Consider the name “babel” (referring to babels tower in the bible)?  
==&gt; Consider the technical name “cpea” (as an acronym for Code Pont and Encoding Aware string)?  
…

2) Consider to have the library interact with “raw” strings and be layered into one Code Point and Encode aware layer and one Code Point adapting layer?

==&gt; Consider the Code Point and Encode Aware layer is the one that interacts with “raw” strings (literals, std::string and different flavours of existing string classes)?

==&gt; Consider a good name of the namespace for the Code Point and Encode Aware strings?

==&gt; Consider this layer only operates on CPEA of the same type (explicit conversion or adaptors are required)

==&gt; Consider the sub-namespace “babel::string” (to refer to being able to interact with “raw” string whilst being Code Point and Encode Aware?

==&gt; &lt;cpea&gt;::string&lt;Code_Point_Set,Encoding&gt; can only inter-operate on objects of the same type as itself?  
==&gt; &lt;cpea&gt;::string&lt;Code_Point_Set,Encoding&gt; can inter-operate with objects that applies a Code Point range and Encoding that is a sub-range of itself (i.e., an ISO-LATIN1,UTF-8 may interoperate with an ASCII, ASCII)?

==&gt; Consider the layer on top of that that is able to inter-operate on CPEA of different Cope Points and Encodings?

==&gt; Consider a good name of the namespace for the Code Point and?

==&gt; Consider the sub-namespace “&lt;cpea&gt;::text” (to refer to being able to operate on any known text)?

==&gt; &lt;cpea&gt;::text&lt;Code_Point_Set_x&gt; is able to interoperate with any babel::text&lt;Code_Point_Set_y&gt; (implicit conversion IS applied)?  
…  
…

Consider to elaborate on this idea of a C++ library for enhanced text processing?  
...

{% endraw %}
