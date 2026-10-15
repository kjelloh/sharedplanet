# todo: Darwinet multi device print service

```#a81a186c``` *As of 2015-07-24 19:02*

[mail plain/text](mail.txt)

{% raw %}
Consider to design a printing service using Darwinet shared printer. (Needs more thinking. The pros and cons are stil unfavoribale)

1. Assign printer to darwinet domain.
2. Print to pdf and save to printer domain print folder.
3. Printer service supervice the printer domain print folder and when new pdf is delivered (synchronized) it automatically prints it.

Pros:

\* Works with any device with darwinet support and print-to-pdf and local storage support (does not include iOS devices?)  
\* pdf enables to ”print what you see”. All print formatting is defined by the pdf. (How to solve single, double side printing?)

Cons:

\* Needs a dedicated printer service (a computer with darwinet, darwinet printing app and a printer driver). Can take some time before the printer implements darwinet support (the goal)

{% endraw %}
