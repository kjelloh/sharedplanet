# Todo: C++ - Consider the API to write C++ Iteratable data types (iterate example, Iteratable class using MyIterator)?

```#3137903f``` *As of 2021-11-22 23:15*

[mail plain/text](mail.txt)

{% raw %}
1) It seems this code at least compiles?

> struct MyIterator {  
> bool operator!=(MyIterator& other) {return false;}  
> MyIterator& operator++() {return \*this;}  
> char operator\*() {return '0';}  
> };

> struct Iteratable {  
> MyIterator begin() {return MyIterator{};}  
> MyIterator end() {return MyIterator{};}  
> };

> void iterate(Iteratable& iteratable) {  
> for (auto const& e : iteratable) {}  
> }

{% endraw %}
