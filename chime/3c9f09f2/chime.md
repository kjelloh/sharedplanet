# Todo: Programming - Consider to implement Encoding Aware String types based on C++ Template runtime zero-overhead Metafunctionality?

```#3c9f09f2``` *As of 2016-05-25 18:12*

[mail plain/text](mail.txt)

{% raw %}
Consider to go for C++ Meta-function types to implement Encoding Aware string types to enable writing error free runtime string handling in apps handling strings of different encoding?

-6) Consider to enable Code Point Set aware types to restrict the range of Code Point Values to a sub-set langues(s)?

==&gt; Could we imagine that we would like to be able to restrict a Code Point set (e.g. Unicode Cope Point Set) to allow only ta sub-range (e.g., a language(s))?

==&gt; If so, consider to use the Bounded Integer library by David Stone mentioned in this Cppcast episode (<http://cppcast.com/2015/08/david-stone/>)?

==&gt; The actual library seem to live here (<http://doublewise.net/c++/bounded/>)?

==&gt; The actual code seem to live on Bitbucket here (<https://bitbucket.org/davidstone/bounded_integer>)?

==&gt; So, can we imagine a text type defined to represent a Code Point sub-set (e.g. a Unicode script)?

==&gt; Note: It seems all western languages fits in range 0…FFFF?

==&gt; But still, Unicode defines Latin-1 as a “script” with a range 0…FF which would allow internal optimisations to store in byte Code Units?

==&gt; Can we imagine some hisser script to be offset down to say a 0…FFFF range (although the actual Code Points are &gt; FFFF)?

==&gt; Consider emoticons script range 01F600…01F64F may store as offset 01F600 and range 0…4F (<http://www.unicode.org/charts/PDF/U1F600.pdf>)?

==&gt; Using Bounded Integers in the API we could get compile-time and runtime check that only valid emoji Code Points gets assigned?

...

-5 Consider to study the “ICU - International Components for Unicode” c++ libraries (<http://site.icu-project.org>)?

-4 Consider new STL template std::text&lt;Container Type, Code_Point_Set&gt;

==&gt; Consider std::text to be a lazy-view is provided with a container that already exist?

==&gt; Consider std::text to create storage if created from scratch?

==&gt; Enable std::text to be constructible from all existing standard string storages (char&#91;&#93;, std::string and wchar_t counterparts)?

==&gt; Enable std::text to be constructible from user-defined string types using user namespace defined “factories”?

==&gt; Enable std__text to be constructible from encode-aware string literals (i.e. UTF-8 string literals)?

==&gt; Enable std::text to be used in STL library (optimally by piggy-back on library support for Niebler range proposal)?

==&gt; Consider std::text semantic to focus on “meaning” of vowed text (not the encoded value)?

std::text&lt;char&#91;&#93;,ASCII&gt; == std::text&lt;std::string, UTF-16&gt; shall return true if the represented texts are equal (sequence of Code Points match)?

==&gt; Q: How do we do this whilst still NOT allowing implicit (invisible conversion costs) type conversion?

==&gt; Q: Should we define semantcis that allow both implicit or require explicit type conversion semantics?

==&gt; Q: To what degree can we have std::text to perform compile-time optimisations?

==&gt; Q: How can we use std::text as compile-time template parameters (can we piggy back on some C++17 langue features)?

...

...

-3) Consider to focus on local text encoding only (not serialisation issues like BOM-prefixing, byte-ordering, bit-streaming)?

==&gt; We should assume BOM-prefixes to be part of a streaming protocol (it has nothing to do with encoding a text of known encoding)?

==&gt; We should be able to argue that byte ordering (and similar issues regarding serialised representation of Code Units) are out of scope to local text representation?

==&gt; Thus the ogonek github project is astray when it tries to adress also byte-ordering-issues of streamed text?

Plain Text Agnostic classes std::text??

|  |

&lt;streamed text&gt; —&gt; &lt;Stream to vector decoding&gt; —&gt; stream&lt;Code Unit&gt; —&gt; &lt;Text aware API&gt; ———&gt; stream&lt;Code Points&gt;

|  vector&lt;Code Unit&gt; vector&lt;Code Points&gt;

|  |

Handle optional BOM prefix New add-on Text-aware code?

Handle Bit and byte order

Generate vector/stream of Data Units

-2) Consider to use this article for leads to the confusion and lack of clear encode-aware string objects and operations (<http://www.italiancpp.org/2016/04/20/unicode-localization-and-cpp-support/>)?

==&gt; Consider especially the lack of understanding that the “meaning” of a stored text is not well represented in code?

...

-1) Consider encode-aware text to be available at compile time and run-time?

==&gt; Consider future constexpr strings to be encode-aware?

==&gt; Consider encode-awareness to be used at compile-time (be expressed as concepts or types) to allow template metaprogramming for encode-aware implementation of code?

==&gt; Q: What mechanism can we imagine to allow extension of existing strings to encode-aware string types and operations?

==&gt; Q: How do we allow this mechanism to slip-right-in with existing code?

...

1) Consider this a follow up (replacement) of previous Todo: regarding these types of strings

==&gt; See “[Todo: Consider to refactor encoding-aware string types as "dimension aware" meta-data?](../97702e7d/chime.md)”

==&gt; See “Todo: Testbench - Consider to use the icu-project C++ library for UTF string conversions?”

...

2) Consider to first understand how we should model the text meaning separated from the text encoding?

==&gt; Consider to real this blog post on String encodings (<http://www.joelonsoftware.com/articles/Unicode.html>)

==&gt; It seems to state that Unicode encoding is about “platonically” existing characters (the “idea” of A, not a specific A)?

==&gt; The Unicode committee has already taken care of what characters we need in the “idea world”?

==&gt; Consider to relate this thinking to the discussion of what a C++ “Value” actually is?

==&gt; Consider we would like the text “Välkommen” to be the “same” regardless of how it is encoded?

==&gt; Consider text “sameness” could be if it maps to the same Unicode Code Points?

==&gt; If so, how do we express this in C++ code where current strcmp and operator== works on encoding, not meaning?

**WE ARE HERE...**

3) Consider to base the design on the insight of “encode agnostic” operations versus “text aware” operations?

==&gt; Seems we would benefit from understanding that strings may be manipulated both as plain ranges of data or ranges of code points?

s1&#91;23&#93; = s2&#91;45&#93;; // encode agnostic (raW9 data manipulation

s1 = find(21, “Hello”); // text aware operation

==&gt; Consider to define encode-agnostic and semantic-aware as two different APIs to a string?

==&gt; Consider all existing string class operations (e.g. char\*, char&#91;&#93;, std::string) as encode-agnostic?

==&gt; Consider to try to add semantic-aware operations through “String Views” (Based on Range Views)?

==&gt; How do we add String Types to capture all encode-agnostic operations to force the programmer to define which should be turned into semantic-aware operations (wrap into string-views)?

==&gt; How do we add these types so that encode-agnostic operations are without overhead compared to existing string code?

==&gt; Can we imagine adding semantic-aware representation to actually make existing code more efficient?

==&gt; Consider lazy-evaluation String views are more efficient than some existing string code (eliminate redundant string copy)?

...

4) Consider to list some string examples in different encodings to use as examples?

==&gt; Consider special symbol texts from “Todo: Programming - Consider to understand and apply "Denotational Semantics" to design C++ Programs?”

==&gt; Mathematical left white box square bracket seem to be unicode U + 27E6 (<http://xahlee.info/comp/unicode_matching_brackets.html>)?

µ⟦e1 + e2⟧ = µ⟦e1⟧ + µ⟦e2⟧

==&gt; Consider a Swedish text?

“Hallå Världen"

…

5) Consider to define the motivation for compile time and runtime behaviour of Encode Aware String Types?

==&gt; Consider to turn Compile Time incompatibility into compile errors?

==&gt; Consider to turn runtime incompatibility into runtime errors?

==&gt; So, what compile time errors can we imagine?

==&gt; Code Unit A Type &lt;&gt; Code Unit Type B (Encoded Range element operation)

==&gt; Consider to identify this as operations on Ranges of Code Unit Values (The Range of Elements of the Encoded Range)

==&gt; E.g. a char_t&#91;100&#93; versus a what_t&#91;100&#93;.

==&gt; The first may hold an UTF-8 string and the second an UTF-16 string.

==&gt; But both may encode UFC 32 bit code points?

==&gt; Code Point A Type &lt;&gt; Code Point B Type (String API char operation)

==&gt; Consider to identify this as operations on Range Views of Code Point Values (a Range View of Code Points)

==&gt; Should we implement this as adaptors when needed.

==&gt; Consider that a Code Point Range Adaptor would express nicely on the code that two String Types are not compatible (adaption needed)

==&gt; Using a lazy adaptor would enable runtime optimisation in that only actually processed Code Points needs to be adapted (e.g. in find skipping trailing Code Points)

==&gt; Code Point A Type Size &lt;&gt; Code Point B Type Size (String API char operation)

==&gt; Consider an ASCII String that exposes 8-bit Code Points and a Unicode String exposing Plane 0 (16-bit) Unicode Code Points?

==&gt; Consider to allow passthrough mapping from 7-bit ASCII to any Unicode Code Point Range (0…127 maps without change)

==&gt; What other passthrough mappings should we allow (7-bit ASCII to iso-latin, windows-1252 etc)?

==&gt; So, what runtime errors can we imagine

==&gt; BOM detection reveals incompatible Encoding (<https://en.wikipedia.org/wiki/Byte_order_mark>)

==&gt; BOM presence not expected (The BOM presence is an error)

==&gt; The Range carries invalid encodings (An ASCII range carries UTF-8 escape sequences)

==&gt; Seem we would like to have runtime checking of the Code Unit Range?

==&gt; Is this even possible without trying to Decode the Code Points?

==&gt; Seem we would like to have runtime check that a Range Decodes to only valid Code Points (this should always be possible although not 100% proof of correct decoding)?

==&gt; Consider this tweet about a banking system failure due to user putting emoji in account nice name (<https://twitter.com/ajlobster/status/735240869859753985>)?

==&gt; This indicates the code on the banking side assumed ASCII strings and got fed with an UTF-8 string encoding an Emoji character?

...

...

6) Consider how Encode Aware String Types must be able to operate with existing code?

==&gt; Easy interaction with C++ String Literals?

==&gt; Easy Interaction with Windows API:s (wchar_t\*)?

==&gt; Easy interaction with char\* in any old API?

==&gt; Consider the iPOSLog DLL API as a case-study?

==&gt; Consider the UKPTServer DLL API as a case-study?

==&gt; Easy interaction with (and possible fix of) File System Path in u8””, u”” (<http://en.cppreference.com/w/cpp/experimental/fs/path/string>)

==&gt; Consider to use this example to show how encode-aware and encode-agnostic strings are mixed in current standard library?

> > template&lt; class CharT, class Traits = std::char_traits&lt;CharT&gt; (1) (filesystem TS)  
> > class Alloc = std::allocator&lt;CharT&gt; &gt;  
> > std::basic_string&lt;CharT,Traits,Alloc&gt;  
> > string( const Alloc& a = Allocator() ) const;

> > std::string string() const; (2) (filesystem TS)  
> > std::wstring wstring() const;  
> > std::string u8string() const;  
> > std::u16string u16string() const;  
> > std::u32string u32string() const;

==&gt; Above: The operator u8string() returns an UTF-8 encoded. All the others are encode-agnostic?

==&gt; Above: How does operator u8string() work when the internal storage of the path is encode-agnostic?

==&gt; Consider to use the provided example to point out the lack of encode-awareness of texts?



> > #include &lt;cstdio&gt;

> > #include &lt;clocale&gt;

> > #include &lt;fstream&gt;

> > #include &lt;iostream&gt;

> > #include &lt;experimental/filesystem&gt;

> > namespace fs = std::experimental::filesystem;

> > int main()

> > {

> > std::setlocale(LC_ALL, "en_US.utf8");

> > std::locale::global(std::locale("en_US.utf8"));

> > fs::path p = fs::u8path(u8"要らない.txt");

> > // native string representation can be used with OS APIs

> > std::ofstream(p) &lt;&lt; "File contents"; // this uses operator string()

> > if(std::FILE\* f = std::fopen(p.c_str(), "r")) {

> > int ch;

> > while((ch=fgetc(f))!= EOF) putchar(ch);

> > std::fclose(f);

> > }

> > // multibyte and wide representation can be used for output

> > std::cout.imbue(std::locale());

> > std::cout &lt;&lt; "\\nFile name in narrow multibyte encoding: "

> > &lt;&lt; p.string() &lt;&lt; '\\n';

> > std::wcerr.imbue(std::locale());

> > std::wcerr &lt;&lt; "File name in wide encoding: "

> > &lt;&lt; p.wstring() &lt;&lt; '\\n';

> > fs::remove(p);

> > }

==&gt; Note: The example uses fgetc to read bytes (not code points) from the file?

==&gt; Note: The example shows an editor able to represent unicode strings in literals (probably UTF-8 encoded source code file)?

7) Consider to list sources of input to get a grip on what we would like to have for Encode Aware string types?

==&gt; This seem like a good page of information talking about Visual Stuiso support for String encodings (<https://blogs.msdn.microsoft.com/vcblog/2016/02/22/new-options-for-managing-character-sets-in-the-microsoft-cc-compiler/>)

==&gt; Consider to list the String encodings the Swedbank test bench needs to cope with?

==&gt; ASCII/ISO-Latin (or confused) in SPDH, iPOS, EMV, PPL?

==&gt; WideString in GUI?

==&gt; What String Encoding does the Testbench use in its own Text Files?

==&gt; Can Testbench understand BOM in read test files?

==&gt; How can we cope with text files provided in mails (do we need a way to assume/set encoding for those)?

...

==&gt; Consider to study the interface of RAD Studio VCL Strings?

==&gt; UnicodeString

==&gt; AnsiString

==&gt; Consider to Study the Microsoft Windows OS String Types?

==&gt; What encoding is assumed for API taking char\* ?

==&gt; What encoding is assumed for API taking wchar_t\* ?

==&gt; Consider to study the C++11 String Literal types?

==&gt; Consider e-mail text encodings (and optionally all web-protocol text encodings)?

==&gt; Consider the examples of failure when I mail with my accountant firm?

![](email-fail-for-swedish-letters.tiff)

==&gt; For some reasons is the ‘Å’ translated to some eastern language symbol (why)?

...

8) Consider to study existing Encode-aware string operations in code (best practices)?

==&gt; This seem like good thread on UTF8 &lt;—&gt; UTF16 transform (<http://stackoverflow.com/questions/7153935/how-to-convert-utf-8-stdstring-to-utf-16-stdwstring>)

==&gt; Note how both-ways transforms goes through a unicode value?

…

==&gt; Consider the Gnome Project Glib C-approach to Unocide String Processing (<https://people.gnome.org/~gcampagna/docs/GLib-2.0/index.html>)

==&gt; These lists were generated these lists using OS X terminal and command line curl and egrep commands.

==&gt; The -o option makes grep only return the matching part (instead of the whole matching line)

Kjell-Olovs-MacBook-Pro:~ kjell-olovhogdahl$ **curl** <https://people.gnome.org/~gcampagna/docs/GLib-2.0/index.html> | **egrep -o** -e'title="GLib.utf8(.\*)"'

> title="GLib.utf8_collate"  
> title="GLib.utf8_collate_key"  
> title="GLib.utf8_collate_key_for_filename"  
> title="GLib.utf8_find_next_char"  
> title="GLib.utf8_find_prev_char"  
> title="GLib.utf8_get_char"  
> title="GLib.utf8_get_char_validated"  
> title="GLib.utf8_normalize"  
> title="GLib.utf8_prev_char"  
> title="GLib.utf8_strchr"  
> title="GLib.utf8_strdown"  
> title="GLib.utf8_strlen"  
> title="GLib.utf8_strncpy"  
> title="GLib.utf8_strrchr"  
> title="GLib.utf8_strreverse"  
> title="GLib.utf8_strup"  
> title="GLib.utf8_substring"  
> title="GLib.utf8_to_ucs4"  
> title="GLib.utf8_to_ucs4_fast"  
> title="GLib.utf8_to_utf16"  
> title=“GLib.utf8_validate"

Kjell-Olovs-MacBook-Pro:~ kjell-olovhogdahl$ **curl** <https://people.gnome.org/~gcampagna/docs/GLib-2.0/index.html> | **egrep -o** 'title="(.\*)utf16(.\*)”'

> title="GLib.ucs4_to_utf16"  
> title="GLib.utf16_to_ucs4"  
> title="GLib.utf16_to_utf8"  
> title=“GLib.utf8_to_utf16"

Kjell-Olovs-MacBook-Pro:~ kjell-olovhogdahl$ **curl** <https://people.gnome.org/~gcampagna/docs/GLib-2.0/index.html> | **egrep -o** 'title="(.\*)ucs4(.\*)”'

> title="GLib.ucs4_to_utf16"  
> title="GLib.ucs4_to_utf8"  
> title="GLib.utf16_to_ucs4"  
> title="GLib.utf8_to_ucs4"  
> title="GLib.utf8_to_ucs4_fast"

9) Consider to try and list the most used character encodings to learn what we need to capture incompatibility and compile-time and runtime?

==&gt; UTF-8 seems to be well described here (<https://en.wikipedia.org/wiki/UTF-8>)?

==&gt; Its RFC seem to be published here (<https://tools.ietf.org/html/rfc3629>)?

==&gt; Consider that the "Universal Character Set” is not the same as “Unicode"?

==&gt; Unicode seems to be about encoding several aspects of text (<https://en.wikipedia.org/wiki/Unicode>)?

*“Unicode is developed in conjunction with the International Organization for Standardization and shares the character repertoire with ISO/IEC 10646: the Universal Character Set.”*

*"Unicode and ISO/IEC 10646 function equivalently as character encodings, but The Unicode Standard contains much more information for implementers, covering—in depth—topics such as bitwise encoding, collation and rendering.”*

*"The Unicode Standard enumerates a multitude of character properties, including those needed for supporting bidirectional text. The two standards do use slightly different terminology."*

==&gt; The Universal Coded Character Set (UCS) seems to be the base for (match) the Unicode standard (<https://en.wikipedia.org/wiki/Universal_Coded_Character_Set>)?

*"ISO 10646 and Unicode have an identical repertoire and numbers—the same characters with the same numbers exist on both standards, although Unicode releases new versions and adds new characters more often.”*

*"Unicode has rules and specifications outside the scope of ISO 10646.”*

*"ISO 10646 is a simple character map, an extension of previous standards like ISO 8859. In contrast, Unicode adds rules for collation, normalization of forms, and the bidirectional algorithm for right-to-left scripts such as Arabic and Hebrew.” *

*"For interoperability between platforms, especially if bidirectional scripts are used, it is not enough to support ISO 10646; Unicode must be implemented.”*

==&gt; The “International Standard ISO/IEC 10646” seems to be the publication of the Universal Coded Character Set (<http://standards.iso.org/ittf/PubliclyAvailableStandards/index.html>)?

- ISO/IEC 10646:2014 Information technology -- Universal Coded Character Set (UCS) JTC1/SC02 (<http://standards.iso.org/ittf/PubliclyAvailableStandards/c063182_ISO_IEC_10646_2014.zip>)
- ISO/IEC 10646:2014/Amd 1:2015  Information technology -- Universal Coded Character Set (UCS) -- Amendment 1: Cherokee supplement and other characters JTC1/SC02 (<http://standards.iso.org/ittf/PubliclyAvailableStandards/c065047_ISO_IEC_10646_2014_Amd_1_2015.zip>)
- ISO/IEC 10646:2014/Amd 2:2016  Information technology -- Universal Coded Character Set (UCS) -- Amendment 2: Bhaiksuki, Marchen, Tangut and other characters JTC1/SC02 (<http://standards.iso.org/ittf/PubliclyAvailableStandards/c066791_IEC_10646_2014_Amd_2_2016.zip>)



10) Consider to relate with this talk “Extreme Type Safety with Opaque Typedefs” by Kyle Markley that applies the same thinking to dress-types (<https://channel9.msdn.com/Events/CPP/CppCon-2015/CPPConD02V011>)?

==&gt; Consider to study his approach to re-use concepts by inheriting form base-types providing these concepts (multiple inheritance to get multiple concept support)

==&gt; He actually refers to possible application of his scheme to Strings (although not about encoding issues, rather user input strings)

11) Consider what traits of String content we need to capture by the different types?

==&gt; Consider to capture Code Unit Size in the type (the size of code in the stream (e.g. 8-bit for UTF8 and ASCII, and 16-bit for UTF-16)

==&gt; Consider to capture Code Point size in the type (e.g. 8-bit for ASCII and ISO-Latin, and 32-bit for UTF characters in UTF-8, UTF-16…)

==&gt; Note: How do we capture the Code Point Size of the String Representation (e.g. an UTF-8 String that iterates over char but actually is capable of encoding UTF 32 bit code-points)?

…

==&gt; Seems we thus have five aspects?

a) The encoded range Code Unit Size (the size of ints in the encoded range)

b) The Encoded Code Point size (the size of the Character Code)

c) The size of the Character Code as represented by the API of String Type (e.g. a String type that provides an interface to a range of 16-bit chars but actually encodes 32-bit UTF Code Points)?

d) The Character Set encoded?

e) The Encoding method?

==&gt; Hm… These concepts are not orthogonal, are they (they can be reduced in some smart way)?

==&gt; E.g. EBCDIC implies 8-bit Code Unit Size, Code Point Size and API Character Size?

==&gt; UTF-16 implies 16-bit Code Unit Size, UTF Code Point Size and possibly 16-bit (whar_t) API character size?

...

12) Consider to design the strings type by inheriting form base types that capture the applied concept of Code Unit Size, Code Point Size and API Character Size?

==&gt; See Kyle Markley approach to do this for adress types (capturing Adress, offset concepts using base classes that provides or omits operators to capture comp abilities)?

==&gt; Consider base class encode_aware_string&lt;int Code_Unit_Size, int Code_Point_Size, int API_Character_Size&gt;?

==&gt; We will then be able to specialise for known combinations?

==&gt; Hm…makes a lot of combinations?

==&gt; Better to specialise member operators (e.g. SFINAE present operator+ for compatible sizes)?

...

13) Consider to compare with existing string classes that adress the problem of different text encodings?

==&gt; Consider this (three year old!) Github project (<https://github.com/rmartinho/ogonek>)?

==&gt; What can we learn from the approach taken in this project?

==&gt; it seems the tests includes byte-ordering (but which should be of interest to serialisation only, not actual local encoding)?

==&gt; Test filed (e.g. <https://github.com/rmartinho/ogonek/blob/devel/test/encoding_scheme.c%2B%2B>) seem to indicate that project tries to cover BOM prefixes also (which we should assume to be part of serialisation traits, not actual Code Point encodings)?

==&gt; Note that home page <https://ogonek.io> no longer seem to exist?

…

Consider to delve into this approach to capture and represent String Types to enable code that detects incompatible String operations based on expressed String Types (concepts)?

...

{% endraw %}
