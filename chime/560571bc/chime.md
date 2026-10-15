# Todo: Programming - Consider a C++ API defined using a std::variant of API function pointers?

```#560571bc``` *As of 2016-05-19 16:48*

[mail plain/text](mail.txt)

{% raw %}
Can we imagine a C++ API to be defined using a Variant of API function pointers?

1) Consider the API of member functions that all return void and takes no parameters?

==&gt; Then we may define a do-function that takes a variant carrying the member function call and then call it?

std::variant&lt;std::function&lt;void (??)&gt; member_func;

class MyAPI {  
public:  
void do(member_func f) {  
return f(); // call it and return  
};  
};

// Client code  
MyAPI server;  
server.do(std::bind(??));

==&gt; Hm… Seems like we will not gain anything from this approach?

a) the variant of function pointers may only differ on function signature, not actual different function members?  
b) We must still bind to actual API member functions so what is the gain of first creating a variant carrying that value?  
…

…

Consider to try out this in actual code to at least learn more about function pointers and what it would mean to carry them round using variants?  
...

{% endraw %}
