# Todo: Programming - Consider to refactor RADLib DataRepresentationFrameWork using boost and C++11?

```#5e4ffb42``` *As of 2015-12-06 23:33*

[mail plain/text](mail.txt)

{% raw %}
The RADLib Datarepresentation framework does its job but it seems it may be greatly refactored using boost and C++11?

1) The naming is to long. Consider to name the namespace something shorter?  
2) Look over the representation transforms to see if we can make the design more compact and efficient (e.g. using std::transform and boost__lexical_cast and such)?  
3) What can we do with the encoding-aware string types?

==&gt; Somewhere Testbench “leaks” (fails to keep åäö-encoding) in logging (how come)?  
==&gt; Is encoding-aware strings even a good idea (only overhead, no actual benefits)?  
==&gt; How may we handle 8-bit &lt;—&gt; 16-bit char string conversion as sparse as possible?  
…

Delve into this, study the code and propose some easy-to-do refactoring to get going?

{% endraw %}
