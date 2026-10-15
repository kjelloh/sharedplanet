# Todo: Programming - Consider to understand u8 encoded character literals and strange output using cout formatting?

```#3bc0202e``` *As of 2016-07-09 15:41*

[mail plain/text](mail.txt)

{% raw %}
Tinning the code below in Xcode on Macbook Air I get strange outputs (some chars seem to be &gt; 255)?

1) Q: Why does this code generate the strange output of characters with values &gt; 255?

auto myNullTerminatedUnicodeString = u8"VÄLKOMMEN";

auto iter = &myNullTerminatedUnicodeString&#91;0&#93;;

std::cout &lt;&lt; "\*iter type is " &lt;&lt; typeid(\*iter).name() &lt;&lt; "\\n";

std::cout &lt;&lt; "\*iter size is " &lt;&lt; sizeof(\*iter) &lt;&lt; "\\n";

std::cout &lt;&lt; "\\nListing \*iter values" &lt;&lt; "\\n";

do {

std::cout &lt;&lt; \*iter &lt;&lt; "\\n";

++iter;

} while (\*iter != 0);

iter = &myNullTerminatedUnicodeString&#91;0&#93;;

std::cout &lt;&lt; "\\nListing int ch = \*iter values" &lt;&lt; "\\n";

do {

int ch = \*iter;

std::cout &lt;&lt; ch &lt;&lt; "\\n";

++iter;

} while (\*iter != 0);

iter = &myNullTerminatedUnicodeString&#91;0&#93;;

std::cout &lt;&lt; "\\nListing unsigned \*iter values" &lt;&lt; "\\n";

do {

unsigned int ch = \*iter;

std::cout &lt;&lt; ch &lt;&lt; "\\n";

++iter;

} while (\*iter != 0);

Output:

> **\*iter type is c**  
> **\*iter size is 1**

> **Listing \*iter values**  
> **V**  
> **\\303**  
> **\\204**  
> **L**  
> **K**  
> **O**  
> **M**  
> **M**  
> **E**  
> **N**

> **Listing int ch = \*iter values**  
> **86**  
> **-61**  
> **-124**  
> **76**  
> **75**  
> **79**  
> **77**  
> **77**  
> **69**  
> **78**

> **Listing unsigned \*iter values**  
> **86**  
> **4294967235**  
> **4294967172**  
> **76**  
> **75**  
> **79**  
> **77**  
> **77**  
> **69**  
> **78**  
> **Program ended with exit code: 0**

==&gt; Q: How can we get out put ”\\303”?

==&gt; How can we get output ”-61” and ”-124”?

==&gt; How can we get output ” 4294967235” and ” 4294967172"

2) Consider to test this code in Visual Studio on Windows 10 (will we get the same result)?

…

3) Also consider to try the same code on Linux Mate (same output)?

...

{% endraw %}
