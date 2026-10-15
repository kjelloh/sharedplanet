# Todo: Programming - Consider to follow up on C++ talk on "Flow Interface" builders and monads?

```#d0331bf6``` *As of 2016-08-19 18:08*

[mail plain/text](mail.txt)

{% raw %}
Consider it could be a good idea to understand and document (as gist?) the flow interface (operator+ chaining style), the builder design pattern and a simple C++ Maybe-Monad described in May Clion C++ video talk?

1) The talk seems to live here (<https://www.youtube.com/watch?v=j9arNRRoPe8>)?

2) Consider to try the code in Xcode project?

==&gt; Created Xcode project “/Users/kjell-olovhogdahl/Documents/XCode/FlowIfcBuilderAndMonads”

==&gt; Note that C++14 support is required (and Xcode has C++11 support as standard)

![](<XCode Enable C++14.tiff>)

…

3) Consider the design patterns we may recognise in this talk?

==&gt; Consider the “Flow Interface” design pattern (operator/methid returns reference to \*this to allow call chains)?

==&gt; Consider the Builder design pattern (builder aggregates built object as result and only builder are allowed to create result types)?

==&gt; Consider to identify and understand the Monad pattern (in this case the Maybe-monad that takes care of applying provided function only if target exists)?

...

…

Consider to publish some gists on the design patterns identified in this talk?

{% endraw %}
