# Todo: Programming - Consider to write C++ coding standard based on the one defined for the Poco project?

```#4d076bbd``` *As of 2016-01-02 13:47*

[mail plain/text](mail.txt)

{% raw %}
I find the coco project coding standard well written and having good coverage. Consider to use it for writing a C++ coding standard of my own?

1) Coco coding standard is published at http://www.appinf.com/download/CppCodingStyleGuide.pdf  
2) Understand the license and see how much I may copy-paste for the structure of my own standard (give proper credit and reference)?  
3) Add my own rules  
==&gt; Have comma separation at beginning of line  
==&gt; return value only at function end (use result variable)  
==&gt; Never use “using” to obscure namespace location of used types (use typedefs instead to enable reader of code to find the redirection)  
Especially in example code it is a nigh mare when the code applies using as the reader has no idea where in the namespace structure used types are defined.  
==&gt; Or, use namespace aliases and name them ”m_xxx” or ”_xxx” to indicate local definition?

...

Delve deeper to see if this could be a way to define coding standard for Testbench, Cuebe and future Darwinet, KeyPath, Protocol?  
...

## Attachments

- [CppCodingStyleGuide.pdf](CppCodingStyleGuide.pdf)

{% endraw %}
