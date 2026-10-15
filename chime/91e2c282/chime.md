# Todo: Programming - Consider to investigate what Code Point(s) a character 'Ä' or string "Ä" gets in runtime and compile time scenarios in C++?

```#91e2c282``` *As of 2016-05-15 17:17*

[mail plain/text](mail.txt)

{% raw %}
So, what can we tell about C++ character literals regarding the Code Point used for them?

1) Can ‘Ä’ be stored in a char or wchar_t (<http://en.cppreference.com/w/cpp/language/character_literal>)?

==&gt; Assuming ‘Ä’ will be UTF-8 encoded it should not be possible?

char c8 = ‘Ä’; // Does this compile?

wchar_t c16 = ‘Ä’; // Does this compile?

2) What value is encoded into a C++ character literal string in C++ for “Ä” ()?

const char\* sz8 = “Ä”; // What bytes gets encoded into sz8?

std::string s8 = “Ä”;

const whar_t\* sz16 = “Ä”; // What values are encoded into sz16?

std::wstring s16 = “Ä”; // (<http://www.cplusplus.com/reference/string/wstring/>)

…

3) Consider to investigate how the pre-processor and C++ compiler are to treat text encoding of the actual source file?

==&gt; So, how does the compiler know how characters in the source code file are encoded?

...

4) Consider to investigate how compile-time template and constexpr processes character and strings?

==&gt; What gets passed to Boost Metatarse for BOOST_METAPARSE_STRING(“Hallå Världen") (<http://www.boost.org/doc/libs/1_61_0/doc/html/metaparse.html>)?

==&gt; Also compare with boost::metatarsi::string&lt;‘H’,’a’,’l’,’l’,’å’,’ ‘,’V’,’ä’,’r’,’l’,’d’,’e’,’n’&gt;?

==&gt; What gets passed to Boost Hana string literals for swedish letters (<http://www.boost.org/doc/libs/1_61_0/libs/hana/doc/html/namespaceboost_1_1hana_1_1literals.html#a325859c7db2c3f8e6a4bfab5a81a6dcb>)?

==&gt; It seems Hana only supports “narrow” string (byte strings)?

“Only narrow string literals are supported right now; support for fancier types of string literals like wide or UTF-XX might be added in the future if there is a demand for it.”

==&gt; Consider to test the Hana example code but with Swedish letters?

> // By default, this is disabled  
> #ifdef BOOST_HANA_CONFIG_ENABLE_STRING_UDL  
> constexpr auto str = “Hallå Världen!"_s;  
> BOOST_HANA_CONSTANT_CHECK(str == hana::string_c&lt;'H', ‘a', 'l', 'l', ‘å', ' ',  
> ‘V', ‘ä', 'r', 'l', 'd', ‘e’, ’n’, '!'&gt;);  
> BOOST_HANA_CONSTANT_CHECK(hana::is_a&lt;hana::string_tag&gt;(str));  
> BOOST_HANA_CONSTANT_CHECK(hana::length(str) == hana::size_c&lt;??&gt;); // What size is it?  
> #endif

==&gt; It seems Hana macros expands to Hana strings just as BOOST_METAPARSE_STRING does?

...

…

Consider to write code to investigate how C++ character and string literals encodes into C++ variable values?

...

{% endraw %}
