# Todo: Programming - Consider to write (blog) about enumeration of for n, for m loops (and a possible combinatorics C++ library)?

```#89148a0f``` *As of 2017-03-11 17:00*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to write about ways to enumerate nested loops of n,m combinations from two ranges of integers n: 0…N-1 and m: 0…M-1?

1) Consider to study how replace nested loops with C++ std::generate_n?

==&gt; To be able to use std::generate and std__generate_n we need a generator capable of generating {n,m} pairs from a call counter (given N and M range definitions)?

> // (1) Imperative code  
> for (int n=0; n&lt;N; ++n) {  
> for (int m=0; m&lt;M; ++m) {  
> // Here we may operate on pair {n,m}  
> }  
> }

> // (2) Generator Code  
> std::generate_n(OutputIterator iter,N\*M, NMGenerator());

2) Consider how we may design an NMGenerator that works both with std::generate_n and std::generate as well as with InputIterator-based algorithms (e.g., std::for_each)?

==&gt; It seems if we model the NPGenerator both as a lazy iteratable container and a callable we can use it with most std range algorithms?

> struct NMGenerator {  
> int seq_no{-1}; // default -1 indicate an ”end” iterator  
> NMPair& operator()() {  
> // Here we generate pair {n,m} as callable (generator = we must ++ us)  
> return combinatorics::permutation&lt;N,M&gt;(seq_no++);  
> }  
> NMPair& operator\*() {  
> // Here we generate pair {n,m} as InputIterator (Client will ++ us)  
> return combinatorics::permutation&lt;N,M&gt;(seq_no);  
> }  
> }

> // (2) Generator Code  
> std::for_each(NMGenerator::begin(),NMGenerator.end(),&#91;&#93;(const NMPair& nm) {  
> // Here we may operate on pair {n,m}  
> });

==&gt; Consider the complexity of implementing a Generator that provides the InputIterator concept (<http://en.cppreference.com/w/cpp/concept/InputIterator>)?

..

==&gt; Consider the std input-range algorithms makes our code more expressive in that the ”sink” appears at the end of the expression (allowing for convenient lambda do be appended)?

> struct NMGenerator {  
> // Implement InputIterator concept <http://en.cppreference.com/w/cpp/concept/InputIterator>  
> };  
> // (2) Generator Code  
> std::for_each(NMGenerator::begin(),NMGenerator.end(),&#91;&#93;(const NMPair& nm) {  
> // Here we may operate on pair {n,m}  
> });

==&gt; Note how this looks much nicer that for std::iterate_n where any lamda would appear in first (the sink expression) instead of the last parameter (the applied function)

...

3) Consider to enumerate NM-pairs using modulo calculus?

==&gt; Also see (<https://betterexplained.com/articles/fun-with-modular-arithmetic/>)?

==&gt; See ”/Users/kjell-olovhogdahl/Resilio Sync/XCode/MySetCombinationEnumerators/MySetCombinationEnumerators"

> template &lt;int N,int M&gt;  
> std::tuple&lt;int,int&gt; to_nm_pair(int seq_no) {  
> return {seq_no/M,seq_no%M};  
> }

> template &lt;int N, int M&gt;  
> long to_seq_no(const std::tuple&lt;int,int,int&gt;& c) {  
> return std::get&lt;0&gt;(c)\*(M) + std::get&lt;1&gt;(c);  
> };

==&gt; Consider we may expand this to triplets?

> template &lt;int O, int N, int M&gt;  
> std::tuple&lt;int,int,int&gt; to_onm_tuple(int seq_no) {  
> int o = seq_no / (N\*M);  
> int n = (seq_no % (N\*M)) / M;  
> int m = (seq_no % (N\*M)) % M;  
> return {o,n,m};  
> }

> template &lt;int O, int N, int M&gt;  
> long to_seq_no(const std::tuple&lt;int,int,int&gt;& c) {  
> return std::get&lt;0&gt;(c)\*(N\*M) + std::get&lt;1&gt;(c)\*(M) + std::get&lt;2&gt;(c);  
> };

**==&gt; Consider to discuss how the NM algorithm actually only depend on M and the ONM algorithm only depends on NM?**

...

4) Consider how std algorithms lacks support of ”functional” composability (e.g., Generators and Iterators are all state-ful)?

==&gt; It seems to be no algorithms that allows the ”generator” to be called with an enumeration (e.g., neither std::generate nor std::generate_n calls the Generator with the sequence number to generate for)?

...

5) Consider how we may design suitable NMPair sinks to be used with std range algorithms?

==&gt; Consider how we can’t make the called OutputIterator ”lazy" (it must consume provided values when called)?

> // See <http://en.cppreference.com/w/cpp/concept/OutputIterator>  
> struct NMPairSink {

> // must implement ++ operator here

> // Models OutputIterator meaning operator\* will only be used for assignment and called only once for each written value

> void operator\*(const NMPair& nm) {

> // Here we may operate on pair {n,m}

> ++(\*this);

> }

  
> }

==&gt; Consider we may make the NMPairSink take a callable to parameterize what processing to actually perform?

> template &lt;typename F&gt;  
> struct NMPairSink {  
> F f;  
> NMPairSink& operator\*(const NMPair& nm) {

> f(nm); // Delegate processing of pair {n,m} to f

> return this;

> }  
> }

> // (2) Generator Code  
> std::generate_n(NMPairSink{&#91;&#93;(const NMPair& nm) { /\* Here we may operate on pair {n,m} \*/ }},N\*M, NMGenerator());

==&gt; Consider how awkward this code will look (not very expressive in it intentions)?

==&gt; Consider to provide a specialized NMPairSink that knows what to do?

==&gt; Consider to design NMPairSink to implement push_back so that we can use std::back_insert_iterator for convenience (we don’t need to implement any iterator members)?

> // See <http://en.cppreference.com/w/cpp/iterator/back_insert_iterator>  
> struct NMPairSink {  
> // To be called by std::back_inserter  
> void push_back(const NMPair& nm) {

> // Here we may operate on pair {n,m}

> }

> }

> NMPairSink result;

> // (2) Generator Code  
> std::generate(std::back_inserter(result),N\*M, NMGenerator());

==&gt; Note that this code also becomes quite obscure (or does it not)?

==&gt; Consider how to design NPSink to work as an OutputIterator (e.g., for std::generate_n)?

> std::generate(OutputIterator iter, OutputIterator end_iter, NMGenerator());

==&gt; Consider how having NMPairSink as a ”lazy” OutputIterator enables us to use it with std::generate (as long as our sink knows N and M that defines the range)?

6) Consider most flexible solution is an InputIterator and Callable NMGenerator and an OutputIterator and Callable NMSink?

> struct NMGenerator {  
> int seq_no{0};  
> NMPair& operator()() {  
> // Here we generate pair {n,m} as callable (generator = we must ++ us here)  
> return combinatorics::permutation&lt;N,M&gt;(seq_no++);  
> }  
> NMPair& operator\*() {  
> // Here we generate pair {n,m} as InputIterator (Client will ++ us)  
> return combinatorics::permutation&lt;N,M&gt;(seq_no);  
> }  
> }

> struct NMSink {  
> void operator()(const NMPair& nm) {  
> // Here we operate on pair {n,m} as callable  
> }  
> void operator\*(const NMPair& nm) {  
> // Here we operate on pair {n,m} as OutputIterator  
> }  
> }

…

Consider to write a blog post about this?

{% endraw %}
