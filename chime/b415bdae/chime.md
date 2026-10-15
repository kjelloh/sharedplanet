# Todo: Programming - Consider to learn and document about regular expression coding?

```#b415bdae``` *As of 2016-07-31 16:48*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to understand and document how regular expressions work and may be used?

1) Consider ages that are good resources to understand regular expressions?

==&gt; Consider this one as a good tutorial on regular expressions (<http://www.regular-expressions.info/tutorial.html>)?

“there are 12 characters with special meanings: the backslash \\, the caret ^, the dollar sign $, the period or dot ., the vertical bar or pipe symbol |, the question mark ?, the asterisk or star \*, the plus sign +, the opening parenthesis (, the closing parenthesis ), the opening square bracket &#91;, and the opening curly brace {, These special characters are often called "metacharacters". Most of them are errors when used alone.”

==&gt; Shorthand character classes seems good to know (<http://www.regular-expressions.info/shorthand.html>)?

“\\d" is short for &#91;0-9&#93;

“\\w" stands for "word character". It always matches the ASCII characters &#91;A-Za-z0-9_&#93;.

2) Consider good online regular expression testers?

==&gt; This seem to be a good one to text javascript regular expressions (<http://www.regexpal.com/>)?

==&gt; Note: It does not support look-behind?

3) Consider to understand how to design a regular expression that matches the file name (without extension) in a file path?

Given: “C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\Darwinet\\build\\src\\Hello.exe”

“.\*” - matches everything (‘.’ matches any character and ‘\*’ means zero-or-more)

“\\\\&#91;^\\\\&#93;+$” - Matches “\\Hello.exe”

“\\w\*(?=.exe$)” - matches “Hello” (matches any word character before excluded “.exe” at end of line ‘$’)

…

Consider to update this documentation when appropriate for new good-to-know regular expression knowledge?

...

{% endraw %}
