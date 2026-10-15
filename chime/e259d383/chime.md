# Todo: Programming - Consider to study and understand u8 (UTF-8) encoded character literals and strange output using cout formatting?

```#e259d383``` *As of 2016-08-05 17:33*

[mail plain/text](mail.txt)

{% raw %}
Tinning the code below in Xcode on Macbook Air I get strange outputs (some chars seem to be &gt; 255)?

1) Consider to list and understand the utf-8 code on MacOS?

> //  
> // main.cpp  
> // MyCppStringPlayground  
> //  
> // Created by Kjell-Olov Högdahl on 2016-07-09.  
> // Copyright © 2016 Kjell-Olov Högdahl. All rights reserved.  
> //

> #include &lt;iostream&gt;

> int main(int argc, const char \* argv&#91;&#93;) {

> {  
> auto myNullTerminatedUnicodeString = u8"VÄLKOMMEN";  
> auto iter = &myNullTerminatedUnicodeString&#91;0&#93;;  
> std::cout &lt;&lt; "\*iter type is " &lt;&lt; typeid(\*iter).name() &lt;&lt; "\\n";  
> std::cout &lt;&lt; "\*iter size is " &lt;&lt; sizeof(\*iter) &lt;&lt; "\\n";  
> std::cout &lt;&lt; "myNullTerminatedUnicodeString = \\"" &lt;&lt; myNullTerminatedUnicodeString &lt;&lt; "\\"\\n"; // cout will fail to interpret UTF-8

> std::cout &lt;&lt; "\\n\*\* Listing \*iter values \*\*" &lt;&lt; "\\n";  
> std::cout &lt;&lt; "&lt;char&gt;" &lt;&lt; '\\t' &lt;&lt; "&lt;signed&gt;" &lt;&lt; '\\t' &lt;&lt; "&lt;unsigned&gt;" &lt;&lt; "\\n";  
> do {  
> std::cout &lt;&lt; \*iter &lt;&lt; '\\t' &lt;&lt; static_cast&lt;int&gt;(\*iter) &lt;&lt; "\\t\\t" &lt;&lt; static_cast&lt;int&gt;(static_cast&lt;unsigned char&gt;(\*iter)) &lt;&lt; "\\n";  
> ++iter;  
> } while (\*iter != 0);  
> }

> return 0;  
> }

Output:

> **\*iter type is c**  
> **\*iter size is 1**  
> **myNullTerminatedUnicodeString = "VÄLKOMMEN"**

> **\*\* Listing \*iter values \*\***  
> **&lt;char&gt; &lt;signed&gt; &lt;unsigned&gt;**  
> **V 86 86**  
> **\\303 -61 195**  
> **\\204 -124 132**  
> **L 76 76**  
> **K 75 75**  
> **O 79 79**  
> **M 77 77**  
> **M 77 77**  
> **E 69 69**  
> **N 78 78**

==&gt; Q: Why do we get the ’\\303' and ’\\204’ outputs?

2) Consider to test this code in Visual Studio on Windows 10 (will we get the same result)?

==&gt; Created “C:\\Users\\kjell-olovhogdahl\\Documents\\Visual Studio 2015\\Projects\\MyCppStringPlayground” on Windows 10 machine

==&gt; The output in Visual Studio win32 console on Windows 10 is slightly different?

==&gt; Note: We probably have a different locale on Windows 10?

> \*iter type is char  
> \*iter size is 1

> Listing \*iter values  
> V  
> ├  
> ä  
> L  
> K  
> O  
> M  
> M  
> E  
> N

> Listing int ch = \*iter values  
> 86  
> -61  
> -124  
> 76  
> 75  
> 79  
> 77  
> 77  
> 69  
> 78

> Listing unsigned \*iter values  
> 86  
> 4294967235  
> 4294967172  
> 76  
> 75  
> 79  
> 77  
> 77  
> 69  
> 78

==&gt; Q: Where does the ‘├’ come from and hos is the ‘ä’ generated (surely -124 is not an ‘ä’)?

==&gt; Realised the erroneous unsigned int assignment and edited the code (See “static_cast&lt;int&gt;(static_cast&lt;unsigned char&gt;(\*iter))” which correctly get the signed byte value of the negative char values).

> // MyCppStringPlayground.cpp : Defines the entry point for the console application.  
> //

> #include "stdafx.h"  
> #include &lt;iostream&gt;

> int main()  
> {  
> auto myNullTerminatedUnicodeString = u8"VÄLKOMMEN";  
> auto iter = &myNullTerminatedUnicodeString&#91;0&#93;;  
> std::cout &lt;&lt; "\*iter type is " &lt;&lt; typeid(\*iter).name() &lt;&lt; "\\n";  
> std::cout &lt;&lt; "\*iter size is " &lt;&lt; sizeof(\*iter) &lt;&lt; "\\n";  
> std::cout &lt;&lt; "myNullTerminatedUnicodeString = \\"" &lt;&lt; myNullTerminatedUnicodeString &lt;&lt; "\\"\\n"; // cout will fail to interpret UTF-8

> std::cout &lt;&lt; "\\n\*\* Listing \*iter values \*\*" &lt;&lt; "\\n";  
> std::cout &lt;&lt; "&lt;char&gt;" &lt;&lt; '\\t' &lt;&lt; "&lt;signed&gt;" &lt;&lt; '\\t' &lt;&lt; "&lt;unsigned&gt;" &lt;&lt; "\\n";  
> do {  
> std::cout &lt;&lt; \*iter &lt;&lt; '\\t' &lt;&lt; static_cast&lt;int&gt;(\*iter) &lt;&lt; "\\t\\t" &lt;&lt; static_cast&lt;int&gt;(static_cast&lt;unsigned char&gt;(\*iter)) &lt;&lt; "\\n";  
> ++iter;  
> } while (\*iter != 0);

> return 0;  
> }

==&gt; The output is now correct.

> \*iter type is char  
> \*iter size is 1  
> myNullTerminatedUnicodeString = "V├äLKOMMEN"

> \*\* Listing \*iter values \*\*  
> &lt;char&gt; &lt;signed&gt; &lt;unsigned&gt;  
> V 86 86  
> ├ -61 195  
> ä -124 132  
> L 76 76  
> K 75 75  
> O 79 79  
> M 77 77  
> M 77 77  
> E 69 69  
> N 78 78

==&gt; Now we can recognise the escape sequence for UTF-8 ‘Ä’ as 195, 132 (i.e., 0xC3, 0x84) (<http://www.utf8-chartable.de>)

…

3) Also consider to try the same code on Linux Mate (same output)?

==&gt; Created project “/home/kjell-olovhogdahl/ClionProjects/myCppStringPlayground”

==&gt; Note: Used my 30 minutes allowance of Clion evaluation license.

==&gt; Using the corrected code from above the output is now correct

> \*iter type is c  
> \*iter size is 1  
> myNullTerminatedUnicodeString = "VÄLKOMMEN"

> \*\* Listing \*iter values \*\*  
> &lt;char&gt; &lt;signed&gt; &lt;unsigned&gt;  
> V 86 86  
> � -61 195  
> � -124 132  
> L 76 76  
> K 75 75  
> O 79 79  
> M 77 77  
> M 77 77  
> E 69 69  
> N 78 78

4) Here is the original code with an erroneous conversion to unsigned int from signed char (which yields a very large number due to erroneous two’s complement application)

==&gt; Q: Why does this code generate the strange output of characters with values &gt; 255?

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

==&gt; How can we get output ”-61” and ”-124”? ==&gt; Because we have values &gt; 127 stored in a signed char (-128…+127)

==&gt; How can we get output ” 4294967235” and ” 4294967172” ==&gt; Because we interpret a signed char as an unsigned int (two’s complement error)

…

Consider to save this expiration for the C++ String talk?

==&gt; Also see (<http://stackoverflow.com/questions/23471935/how-is-u8-literals-suppose-to-work>)?

...

{% endraw %}
