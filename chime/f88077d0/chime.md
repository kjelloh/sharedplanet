# Todo Tha C++ - Consider we want to be able to write meta-lambdas (to conveniently inject anonymous meta-code)?

```#f88077d0``` *As of 2017-08-06 00:46*

[mail plain/text](mail.txt)

{% raw %}
Consider if we could apply anonymous meta-lambdas we could do very compact and powerful programming in a clear and readable way?

1) Consider meta-lambdas re-uses lama syntax with “meta" keyword prefix?

meta auto &#91;user_type_1&#93;(auto some_type) { if (some_type == int) return float; else return void_t;}

hm… How can we imagine to provide a meta lambda as a type constructor?

…

Consider to elaborate on this idea to re-use lambda syntax and application also to meta-code execution?  
...

{% endraw %}
