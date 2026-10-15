# Todo: Programming - Consider co-routines can be used as a stateful generator that represents state in code instead of in data?

```#59bf6445``` *As of 2017-03-12 22:57*

[mail plain/text](mail.txt)

{% raw %}
Consider to delve into the idea that a co-routine is in fact a stateful generator that stores state as an execution point rather that in state as value?

1) Consider nested for-loops as an example of sate-in-code that we may use in co-routine as a generator?

for (int n=0;n&lt;N;++n) {  
for (int m=0;m&lt;M;++m) {  
// Do processing based on state {n,m}  
}  
}

auto co_routine f() {  
for (int n=0;n&lt;N;++n) {  
for (int m=0;m&lt;M;++m) {  
// yeld to client to process on state {n,m}  
co_yield {n,m}  
}  
}  
}

2) Consider to follow up on cppchat 14 round 28:00 about co-rouitines as stat-in-code generators (https://www.youtube.com/watch?v=-nQwpmmEDzI&t=26s)?

…

…

Consider to experiment with this idea and see if I can come to some conclusion about how this view on co-routines can be valuable (and viable)?  
...

{% endraw %}
