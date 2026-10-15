# Todo: programming - Consider a printf-design using C++ template "magic" to create lazy-fixed-size range-tree and fully parallelised string-from-variable generators?

```#26902720``` *As of 2016-05-04 15:52*

[mail plain/text](mail.txt)

{% raw %}
So, can we imagine to implement sprintf-functionality using compile-time fixed-size-range tree and lazy evaluation for fully paralleled generation of output string from source variables?

-3) Consider to elaborate on a design based on safe-bud-size formatting followed by compress into final output?

==&gt; What would it mean performance-wise to format in two steps?

==&gt; Step1: Format into temporary buffer of safe-sized-buffer using safe-sized format specifier sub-range targets.

==&gt; Step2: Compress each sub-range target to actual size and move to output buffer.

==&gt; Note: Selecting a safe step-1 size is possible only for non-string types (strings are allowed to be any-size null-terminated)?

==&gt; Consider this approach on an example sprintf (<http://www.cplusplus.com/reference/cstdio/sprintf/>)?

> ```
> /* sprintf example */
> ```

  
> ```
> #include <stdio.h>
> ```

  
> ```

> ```

  
> ```
> int main ()
> ```

  
> ```
> {
> ```

  
> ```
>   char buffer [50];
> ```

  
> ```
>   int n, a=5, b=3;
> ```

  
> ```
>   n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
> ```

  
> ```
>   printf ("[%s] is a string %d chars long\n",buffer,n);
> ```

  
> ```
>   return 0;
> ```

  
> ```
> }
> ```



==&gt; Step-1: Consider safe-target-size for %d to be 10 characters?

sprintf (buffer, "%d plus %d is %d", a, b, a+b);

01234567890123456789012345678901234567890123456789

“__________ plus __________ is __________ “

| | | | |

&#91;0…9&#93; &#91;10…15&#93; &#91;16…25&#93;&#91;26…29&#93; &#91;30…39&#93; &#91;40…40&#93;

r1 “ plus " r2 “ is “ r3 ‘\\0’ // Compile-time bound

| | |

“5 “ “3 “ “8 “ // Run-time formatted (safe targets)

&#91;1…9&#93; &#91;17…25&#93; &#91;31…39&#93; // Run-time “dead” ranges to remove

==&gt; Step-2: Now compress “dead” ranges

…

**WE ARE HERE...**

==&gt; Consider to leverage the insight fromKenny Kerr (below) that a sprintf is really a printf into a designated target?

==&gt; All is then to make printf “safe” and then add “safeness” of detecting target buffer overrun (when buffer is not printf-created?

**WE ARE HERE...**

-2) Consider to compare with cppformat on github (<https://github.com/cppformat/cppformat>)

==&gt; It seems to support drop-in replacement for sprintf (<http://cppformat.github.io/latest/api.html#printf-formatting-functions>)?

> std::string message = **fmt::sprintf**("The answer is %d", 42);

==&gt; Seems though, we must add catch of exceptions for run-time formatting failures?

*“The library is fully type safe, automatic memory management prevents buffer overflow, errors in format strings are reported using exceptions..."*

==&gt; Seems we just need to add the h- and cpp-file to our project to use it?

“To use the C++ Format library, add format.h and [format.cc](http://format.cc) from a release archive or the Git repository to your project. Alternatively, you can build the library with CMake."

==&gt; The sprintf seem to be defined header-only by including cc-file in the h-file (<https://github.com/cppformat/cppformat/blob/master/cppformat/format.h>)?

> // <https://github.com/cppformat/cppformat/blob/master/cppformat/format.h>

> // A printf formatter.  
> template &lt;typename Char&gt;  
> class PrintfFormatter : private FormatterBase {  
> private:  
> void parse_flags(FormatSpec &spec, const Char \*&s);

> // Returns the argument with specified index or, if arg_index is equal  
> // to the maximum unsigned value, the next argument.  
> Arg get_arg(const Char \*s,  
> unsigned arg_index = (std::numeric_limits&lt;unsigned&gt;::max)());

> // Parses argument index, flags and width and returns the argument index.  
> unsigned parse_header(const Char \*&s, FormatSpec &spec);

> public:  
> explicit PrintfFormatter(const ArgList &args) : FormatterBase(args) {}  
> FMT_API void format(BasicWriter&lt;Char&gt; &writer,  
> BasicCStringRef&lt;Char&gt; format_str);  
> };

> template &lt;typename Char&gt;  
> void printf(BasicWriter&lt;Char&gt; &w, BasicCStringRef&lt;Char&gt; format, ArgList args) {  
> internal::PrintfFormatter&lt;Char&gt;(args).format(w, format);  
> }

> inline std::string sprintf(CStringRef format, ArgList args) {  
> MemoryWriter w;  
> printf(w, format, args);  
> return w.str();  
> }  
> ...

> #ifdef FMT_HEADER_ONLY  
> # include "[format.cc](http://format.cc)"  
> #endif  
> ...

> // <https://github.com/cppformat/cppformat/blob/master/cppformat/format.cc>

> template &lt;typename Char&gt;  
> void fmt::internal::PrintfFormatter&lt;Char&gt;::format(  
> BasicWriter&lt;Char&gt; &writer, BasicCStringRef&lt;Char&gt; format_str) {  
> ...  
> // printf formatter parsing here…  
> ...  
> }

…

-1) Consider to delve into Kenny Kerr proposals for a “modernised” printf (<https://kennykerr.ca/2015/03/03/using-printf-with-modern-c/>)?

==&gt; He seem to have published in may 2015 in msdn magazine (<https://msdn.microsoft.com/en-us/magazine/dn913181.aspx>)?

==&gt; This article was mentioned by Kenny Kerr at 31:30 in this CppCast episode (<http://cppcast.com/2015/05/kenny-kerr/>)

==&gt; And later this one in the same magazine (<https://msdn.microsoft.com/en-us/magazine/dn973010.aspx>)?

==&gt; He proposes only % signs are required (as printf relies on the order of provided arguments, not identity)?

> printf("%s %d\\n", "Hello", 2015);  
> Write("% %\\n", "Hello", 2015); // Equals the above

==&gt; He notes that sprintf is actually a printf into a designated target?

==&gt; Consider to leverage his proposal to using range-fixation-step before formatting to enable full format parallelisation and pre-format overflow detection?

**WE ARE HERE...**

==&gt; These articles seem to pre-date the one above?

==&gt; Consider his defence of printf here (<https://kennykerr.ca/2014/12/08/in-defense-of-printf/>)?

==&gt; Consider his follow-up with compile-time type-checking of printf here (<https://kennykerr.ca/2015/05/04/adding-compile-time-type-checking-to-printf/>)

==&gt; Consider related article on classy type system for modern C++ (<https://kennykerr.ca/2015/04/07/a-classy-type-system-for-modern-c/>)?

==&gt; Hm, it seems he stick to printf so he actually does not have a problem with buffer overrun (there is no contained output buffer)?

==&gt; So, he focuses (only?) on making passing of parameters safe (they match the format string)?

==&gt; Or, he simply realises that sprintf is actually a printf into an existing buffer (instead of one created as result)?

...

1) It seems the format string of sprintf really defines more-or-less a fixed (or at least retrained) sized text range with sub-ranges where formatted variable values shall go?

==&gt; Can we imagine to build at compile time a lazy “encoder” for that format string that at runtime fills the ranges to format?

==&gt; Consider this approach from an example sprintf (<http://www.cplusplus.com/reference/cstdio/sprintf/>)?

> ```
> /* sprintf example */
> ```

  
> ```
> #include <stdio.h>
> ```

  
> ```

> ```

  
> ```
> int main ()
> ```

  
> ```
> {
> ```

  
> ```
>   char buffer [50];
> ```

  
> ```
>   int n, a=5, b=3;
> ```

  
> ```
>   n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
> ```

  
> ```
>   printf ("[%s] is a string %d chars long\n",buffer,n);
> ```

  
> ```
>   return 0;
> ```

  
> ```
> }
> ```



sprintf (buffer, "%d plus %d is %d", a, b, a+b);

01234567890123456789012345678901234567890123456789

“_ plus _ is _ “

| | |

0…0 7…7 12…12

r1 r2 r3

==&gt; This corresponds to a runtime range tree (each sub-range r1, r2 and r3 are all 1 character due to input runtime value &lt; 10)

&#91;0…49&#93; buffer range

|

&#91;0…0&#93; &#91;1…6&#93; &#91;7…7&#93; &#91;8…11&#93; &#91;12…12&#93; &#91;13…13&#93; format string sub-ranges

| | | | | |

a “ plus “ b “ is “ a+b “/0” compile-time bound rvalues

==&gt; Consider to have this implemented as lazy-evaluated sprintf:s for each sub-range?

sprintf(&buffer&#91;0&#93;, "%d", a);

sprintf(&buffer&#91;1&#93;, " plus ");

sprintf(&buffer&#91;7&#93;, "%d",b);

sprintf(&buffer&#91;8&#93;, " is ");

sprintf(&buffer&#91;12&#93;,"%d", a, b, a+b);

==&gt; Note that this is somewhat in-efficiwent as each sprintf will add a redundant ‘\\0’

==&gt; On the other hand we can compose of existing sprintf functionality?

…

2) Consider how to genaret code that may parallelise formatting of each runtime bound value formatting?

==&gt; The design should exploit the fact that once the size of each sub-range to encode the actual encoding may run in true parallel?

==&gt; Note that we may design this parallelism by spawning a new “thread” each tome we reach a format specifier and has determined the formatted size?

==&gt; Q: How may we determine the size without actually calling the sprintf for that format specifier?

==&gt; Consider the simple example above?

Encode &#91;0…?&#93; bound to a

get value of a.

value &lt; 10 ==&gt; range size is 1

spawn thread to continue with next sub-range below.

call sprintf(&buffer&#91;0&#93;, "%d", a); on this thread, then done.

Encode &#91;1…6&#93; bound to “ plus “

size of this range set at compile time (static text 4 chars)

spawn thread to encode next range below.

call sprintf(&buffer&#91;1&#93;, " plus “); on this thread, then done.

Encode &#91;7…7&#93; bound to b

get value of b.

value &lt; 10 ==&gt; range size is 1

spawn thread to encode next range below.

call sprintf(&buffer&#91;7&#93;, "%d",b); on this thread, then done.  
sprintf(&buffer&#91;8&#93;, " is ");  
sprintf(&buffer&#91;12&#93;,"%d", a, b, a+b);

NOTE: Seems using sprintf we must still sequence the calls so that each ‘\\0’ generated by preceding call is overwritten by the following?

==&gt; Consider if an how we could make all sprints-calls but the last one generate the ‘\\0’?

**NO: spring, nsprintf and vsnprintf always writes a terminating ‘\\0’!**

2) Consider to find code on the web that addresses this same idea in some form?

==&gt; Consider this github doc (<https://gist.github.com/en4bz/f07ef13706c3ae3a4fb2>)?

==&gt; No, seems to replace all format specifiers in the string with &lt;&lt; get&lt;i&gt;(t) (i.e. just streaming the provided value)

==&gt; It does not seem to parse the implication of possible printf-formats?

==&gt;

2) Consider what we can do at compile time to ensure the generated code is fast but still safe (no buffer overrun)?

==&gt; If a and b where const we could specialise at compile-time for the known size of provided values?

==&gt; In example passing runtime variables we can generate runtime-checked range generator (contained to size of 50)?

3) Consider how we could parse the format string at compile-time?

==&gt; Can we imagine identifying the format specifier fields without having to actually implement the full sprintf parser (<http://www.cplusplus.com/reference/cstdio/printf/>)?

A format specifier follows this prototype: &#91;see compatibility note below&#93;

%&#91;flags&#93;&#91;width&#93;&#91;.precision&#93;&#91;length&#93;specifier

Where the specifier character at the end is the most significant component

==&gt; So, it seems each format specifier starts with ‘%’ and ends with &lt;non-specifier character&gt; (e.g. ‘.’) ?

==&gt; Note that ‘.’ is valid between ‘%’ and &lt;specifier&gt; so parsing requires identifying single ‘%’ up to ending specifier (d,i,u,o,x,X,f,F,e,E,g,E,a,A,c,s,p,n,%)?

==&gt; Q: And we do NOT have to parse for escaped characters as this is taken care of for us by the compiler?

4) Consider to define a constexpr sprintf that returns a lazy text view using provided buffer as storage?

constexpr text_view sprintf(C\* buffer,T… vars);

==&gt; Can we make this possible?

5) Or, consider a template function sprintf?

template &lt;typename C,T… Args&gt;

text_view sprintf(C\* buffer,Args… args);

==&gt; Is this possible?

…

Consider to delve into this to see if we can imagine combining range-trees and text_view to define a runtime specialised, safe and efficient sprintf-replacement?

==&gt; Consider such a sprintf to also handle text encoding correctly (Optional)?

...

{% endraw %}
