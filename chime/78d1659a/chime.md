# Todo: Programming - Study the latest threading design idioms using boost ::promise, ::future, ::async and the likes

```#78d1659a``` *As of 2015-12-02 01:11*

[mail plain/text](mail.txt)

{% raw %}
When digging into contemporary c++ threading design idioms I stumbled on what seem to be very neat ways of thread-to-thread messaging.

1) This seem a good site explaining boost::promise and boost::future (<http://theboostcpplibraries.com/boost.thread-futures-and-promises>)?

void accumulate(boost::promise&lt;int&gt; &p)

{

int sum = 0;

for (int i = 0; i &lt; 5; ++i)

sum += i;

p.set_value(sum);

}

int main()

{

boost::promise&lt;int&gt; p;

boost::future&lt;int&gt; f = p.get_future();

boost::thread t{accumulate, std::ref(p)};

std::cout &lt;&lt; f.get() &lt;&lt; '\\n';

}

==&gt; boost::thread t{accumulate, std::ref(p)} seem to invoke thread constructor with c++11 initialiser_list (<http://www.cplusplus.com/reference/initializer_list/initializer_list/>)?

```
struct myclass {
  myclass (int,int);
  myclass (initializer_list<int>);
  /* definitions ... */
};

myclass foo {10,20};  // calls initializer_list ctor
myclass bar (10,20);  // calls first constructor
```

==&gt; But boost::thread t{accumulate, std::ref(p)} is an example of “Uniform Initialisation” (<https://en.wikipedia.org/wiki/C%2B%2B11>)

```
struct BasicStruct {
    int x;
    double y;
};

struct AltStruct {
    AltStruct(int x, double y) : x_{x}, y_{y} {}

    private:
        int x_;
        double y_;
};

BasicStruct var1{5, 3.2};
AltStruct var2{2, 4.3};
```

==&gt; boost::thread t{accumulate, std::ref(p)} would thus translate into boost::thread t(accumulate,p), i.e. thread is started with call to accumulate(p) as defined by thread constructor (function,args …).

…

3) This site conveys that ::promise and ::future is now in (c++11?) std:: (<http://en.cppreference.com/w/cpp/thread/promise>)

Consider to continue to study the ::promise and ::future goodies in std?

...

{% endraw %}
