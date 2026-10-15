# Todo: programming - Consider C++ string literals as applying yet another text encoding (e.g. in the form of escaped characters)?

```#e7d88061``` *As of 2016-08-10 11:35*

[mail plain/text](mail.txt)

{% raw %}
Could it be valuable to actually see C++ string literal parsing (encoding) as yet a tex encoding form applying escaped-characters?

==&gt; Also see “Todo: Programming - Consider to study and understand u8 (UTF-8) encoded character literals and strange output using cout formatting?”

==&gt; Also “Todo: Programming - Consider to design a String "type" that bridges text "meaning" and text encoding?”

==&gt; Also see “Todo: Programming - Consider to study issues with recognizing text (string) encoding and character set (script) when provided with raw input?"

1) Consider that C++ string literals not only is encoded in the encoding used by the source file, they also applies escaped-character encodings?

==&gt; Consider the C++ string literal “Välkommen\\n” (See “Todo: Programming - Consider to study and understand u8 (UTF-8) encoded character literals and strange output using cout formatting?”)

char\* sHello = “Välkommen\\n”; // sHello == {86, 195, 132, 76, 75, 79, 77, 77, 69, 78, 10}

2) Consider regular expressions adds another layer of encoding in its intermix of its own escaped directives (meaning encoding actual ‘\\’ bus be written as ‘[\\\\'?](smb://'?)

…

…

Consider to delve into this idea that string literals in programming adds another layer of “encoding” to allow writing in readable form “escaped” (no character) values?

...

{% endraw %}
