# Todo: Programming - Consider to design an example to expose the patterns of the Future Monad to accomplish co-routine "asynchronization" of a socket reading and processing procedure?

```#f4d60a0c``` *As of 2017-01-16 19:15*

[mail plain/text](mail.txt)

{% raw %}
Consider to design an example where we have a procedure that we want to make asynchronous by turning each operation in the se sequence into calls returning a std::future?

1) Consider to ”async-ify” a sequence of functions in two ways and ask how we enable changing of the ”gluing code”?

Result f_combined(Type_0 in_value) {

Type_1 result_1 = f1(in_value);

Type_2 result_2 = f2(result_1);

Type_3 result_3 = f2(result_2);

...

Type_n result_n = fn(result_n);

return result_n;

}

==&gt; Consider to async-ify having each function return a future?

...

...

{% endraw %}
