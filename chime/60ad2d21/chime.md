# Todo: Programming - Consider to wrap tag-path based encoding/decoding into stream operator &gt;&gt; and &lt;&lt;?

```#60ad2d21``` *As of 2016-07-07 14:36*

[mail plain/text](mail.txt)

{% raw %}
So, could it be a good idea to enable the tag-path based encoding/decoding of streamed protocol messages to be decoded using &gt;&gt; operator and encoded using operator &lt;&lt;?

1) Consider to implement encoding and decoding as insertion and extraction operators (<http://en.cppreference.com/w/cpp/language/operators>)?

”The overloads of operator&gt;&gt; and operator&lt;&lt; that take a std::istream& or std::ostream& as the left hand argument are known as insertion and extraction operators. Since they take the user-defined type as the right argument (b in a@b), they must be implemented as non-members.”

> ```
> std::ostream<http://en.cppreference.com/w/cpp/io/basic_ostream>& operator<<(std::ostream<http://en.cppreference.com/w/cpp/io/basic_ostream>& os, const T& obj)
> ```

  
> ```
> {
> ```

  
> ```
>     // write obj to stream
> ```

  
> ```
>     return os;
> ```

  
> ```
> }
> ```

  
> ```
> std::istream<http://en.cppreference.com/w/cpp/io/basic_istream>& operator>>(std::istream<http://en.cppreference.com/w/cpp/io/basic_istream>& is, T& obj)
> ```

  
> ```
> {
> ```

  
> ```
>     // read obj from stream
> ```

  
> ```
>     if( /* T could not be constructed */ )
> ```

  
> ```
>         is.setstate(std::ios::failbit);
> ```

  
> ```
>     return is;
> ```

  
> ```
> }
> ```



==&gt; Consider to defined them as friend functions if required for them to access private members?

2) Consider what we need to do to enable insert and extract operator to operate on only stream and streamed type?

==&gt; Q: How can we still have a design of four actors (Encoded data, recorded data, codec and model)?

==&gt; Consider we need the encoded data (stream) and the decoded data (type instance) to aggregate the encoder/decoder and the model?

Model Encoder/Decoder

|  |

stream &lt;&lt; object

==&gt; Consider the stream (encoded data) to aggregate the model to encode and the object (type instance) aggregate the Encoder and Decoder?

==&gt; Q: This would require the operator&lt;&lt; to be friends of the stream and the object to be able to engage private model and decider/encoder?

...

3) Consider to compare with Nibblers Range library (<https://github.com/ericniebler/range-v3>)?

==&gt; It seems Ranges v3 uses the | operator (the pipe operator of Posix command line environments) to process streams lazily (<https://stackoverflow.com/questions/38097685/best-way-to-do-flattening-of-nested-getter-result-inside-getter>)?

==&gt; This would suggest that using nibblers ranges the transform would be to/from a range (a pair of iterators)?

==&gt; Also, Range v3 range adaptors are lazy in that they consume data only on access, not on call?

==&gt; Then again, it seems we could wrap a stream operator on top of a range adaptor (simply streaming the resulting range to/from the stream)?

4) Consider to again look into the possibility of having the tag-path based encoding/decoing use composite-range-trees (ranges or ranges of ranges…)?

==&gt; Consider this would map better to the intone that the Model plus the encoding actually defines ranges in the encoded data to/from we may transform values?

==&gt; Q: Does Ranges v3 allow adaptors that in fact implement composite-range-trees?

==&gt; Q: Or put another way, does Ranges v3 allow concurrent processing of separate ranges (i.e., encode/decode ranges of values in the encoded data)?

...

…

Consider to elaborate on this idea to see what we can learn about the best design of the tag-path based encoder decoder?

{% endraw %}
