# Todo: C++ Text - Consider ways to detect at compile time the encoding of source code string literals?

```#b63406af``` *As of 2016-11-02 16:05*

[mail plain/text](mail.txt)

{% raw %}
Is there a way in C++ to determine at compile time the encoding used for string literals?

1) Consider two source code files where one is encoded in UTF-8 and one in ISO Latin-1?

==&gt; Then the string literal R”(Hallå Världen)” would be encoded differently in the two translation units?

==&gt; Consider to make a test C?+ program to show this?

…

2) Consider an encode defined string literal in two source code files where one is encoded in UTF-8 and one in ISO Latin-1?

==&gt; Q: Will the the string literal u8”Hallå Världen” be encoded differently in the two translation units (i.e. UTF-8)?

==&gt; Q: Will the the string literal u”Hallå Världen” be encoded differently in the two translation units (i.e., UTF-16)?

==&gt; Q: Will the the string literal U”Hallå Världen” be encoded differently in the two translation units (i.e., UTF-32)?

3) Consider the variations of how ”narrow” and ”wide” string literals are encoded (<http://en.cppreference.com/w/cpp/language/string_literal>)?

> *”The encoding of narrow multibyte string literals (1) and wide string literals (2) is implementation-defined. For example, gcc selects them with the commandline options -fexec-charset and -fwide-exec-charset.”*

==&gt; This would mean the source code file encoding could be overridden by compile switches?

…

4) Consider to investigate to what degree C++ allows compile-time awareness of string literal encoding?

==&gt; Q: Is it possible to apply compile-time knowledge of string literal encodings?

==&gt; Q: Is it possible to apply compile-time knowledge of ”execution character set” encoding?

...

5) Consider to study and understand the implications of the C++ translation phases regarding handling of character set (<http://en.cppreference.com/w/cpp/language/translation_phases>)?

> ### Phase 1

  
> 1) The individual bytes of the source code file are mapped (in implementation defined manner) to the characters of the *basic source character set*. In particular, OS-dependent end-of-line indicators are replaced by newline characters. The *basic source character set* consists of 96 characters:  
> a) 5 whitespace characters (space, horizontal tab, vertical tab, form feed, new-line)  
> b) 10 digit characters from '0' to '9'  
> c) 52 letters from 'a' to 'z' and from 'A' to 'Z'  
> d) 29 punctuation characters: _ { } &#91; &#93; # ( ) &lt; &gt; % : ; . ? \* + - / ^ & | ~ ! = , \\ " '  
> 2) Any source file character that cannot be mapped to a character in basic source character set is replaced by its [universal character name](http://en.cppreference.com/w/cpp/language/escape) (escaped with `\\u` or `\\U`) or by some internal form that is handled equivalently.

==&gt; It seems the standard defines al non-basic character are processed as its unicode equivalent?

==&gt; Does this mean the compiler must be source file encode aware?

> ### Phase 5

  
> 1) All characters in [character literals](http://en.cppreference.com/w/cpp/language/character_literal) and [string literals](http://en.cppreference.com/w/cpp/language/string_literal) are converted from the source character set to the *execution character set* (which may be a multibyte character set such as UTF-8, as long as the 96 characters of the *basic source character set* listed in phase 1 have single-byte representations).  
> 2) [Escape sequences](http://en.cppreference.com/w/cpp/language/escape) and universal character names in character literals and non-raw string literals are expanded and converted to the *execution character set*. If the character specified by a universal character name isn't a member of the execution character set, the result is implementation-defined, but is guaranteed not to be a null (wide) character.  
> Note: the conversion performed at this stage can be controlled by command line options in some implementations: gcc and clang use -finput-charset to specify the encoding of the source character set, -fexec-charset and -fwide-exec-charset to specify the encodings of the execution character set in the string and character literals that don't have an encoding prefix (since C++11).

==&gt; The standard seem to define an ”execution character set” (whatever that is)?

==&gt; It seems one may control the execution character set with compiler switches for some compilers?

6) Consider to study Visual Studio 2015 specification about C++ compiler character set handling (<https://msdn.microsoft.com/en-us/library/mt589696.aspx>)?

==&gt; It seems C++ defines minimum support for ”basic source character set” and ”basic execution character set”?

> *”The C++ standard specifies a basic source character set for source files and a basic execution character set for compiled files. Visual C++ allows an additional set of locale-specific characters to be used in source files and compiled files."*

==&gt; It seems Visual Studio allows for extended locale defined source and execution character sets?

> *”By default, Visual Studio stores source files by using the default codepage. When source files are saved by using a locale-specific codepage or a Unicode codepage, Visual C++ allows you to use any of the characters of that code page in your source code, "*

7) Consider to find web-refernces to discussions about C++ source code and execution character set issues?

==&gt; Consider this SO thread that seems to give a quite extensive interpretation of the standard (<http://stackoverflow.com/questions/3768363/character-sets-not-clear>)?

==&gt; Consider this SO thread which also includes some observations (<http://stackoverflow.com/questions/22033039/what-is-execution-wide-character-set-and-its-encoding>)?

...

…

Consider to delve into this subject and investigate to what degree C++ allows compile-time awareness of the encoding of string literals in the source code?

...

{% endraw %}
