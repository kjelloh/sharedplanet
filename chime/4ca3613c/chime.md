# Todo: Programming languages - Consider a receiver type dispatching mechanism (choose what function to call based on the required return type and structure)?

```#4ca3613c``` *As of 2021-12-06 14:20*

[mail plain/text](mail.txt)

{% raw %}
*I want to be able to write a string tokeniser where I can have the compiler choose the correct tokeniser based on the type of the varaible into which I assign the result.*

*If I could do that I could use e.g., a split(range) function and have it return a pair or a vector depending on whether I assign the result to such a type. With that behaviour I could provide semantics about if I expect the split range to be a comma separated list or a key value pair.*

{% endraw %}
