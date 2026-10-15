# Todo: Consider to understand the C++20 support for coroutines (and what we can expect in C++23 standard library support)?

```#2e3bc152``` *As of 2022-01-26 19:21*

[mail plain/text](mail.txt)

{% raw %}
I like coroutines but want to know how to use the C++20 support to be C++23 ready.

-1) Consider the complete C++20 standard in this draft that was eventually released (<https://isocpp.org/files/papers/N4860.pdf> )?

> Table 5: Keywords

> 17.12 Coroutines

0) Consider cppreference C++20 language support page (<https://en.cppreference.com/w/cpp/20> )?

==&gt; It seems P0912 is the paper about merging coroutines into C++20 (<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p0912r5.html> )?

1) Consider cppreference documentation for C++20 coroutine support (<https://en.cppreference.com/w/cpp/language/coroutines> )

2) Consider the C++20 standard library support for coroutines (<https://en.cppreference.com/w/cpp/coroutine> )?

==&gt; It seems the library support in C++20 for coroutines are quite sparse?

> ### Coroutine traits

  
> Defined in header `[&lt;coroutine&gt;](https://en.cppreference.com/w/cpp/header/coroutine)`  
> [coroutine_traits](https://en.cppreference.com/w/cpp/coroutine/coroutine_traits)  
> (C++20)  
> trait type for discovering coroutine promise types  
> (class template)

> ### Coroutine handle

  
> Defined in header `[&lt;coroutine&gt;](https://en.cppreference.com/w/cpp/header/coroutine)`  
> [coroutine_handle](https://en.cppreference.com/w/cpp/coroutine/coroutine_handle)  
> (C++20)  
> used to refer to a suspended or executing coroutine  
> (class template)

> ### No-op coroutines

  
> Defined in header `[&lt;coroutine&gt;](https://en.cppreference.com/w/cpp/header/coroutine)`  
> [noop_coroutine](https://en.cppreference.com/w/cpp/coroutine/noop_coroutine)  
> (C++20)  
> creates a coroutine handle that has no observable effects when resumed or destroyed  
> (function)  
> [noop_coroutine_promise](https://en.cppreference.com/w/cpp/coroutine/noop_coroutine_promise)  
> (C++20)  
> used for coroutines with no observable effects  
> (class)  
> [noop_coroutine_handle](https://en.cppreference.com/w/cpp/coroutine/coroutine_handle)  
> (C++20)  
> [std::coroutine_handle](http://en.cppreference.com/w/cpp/coroutine/coroutine_handle)&lt;[std::noop_coroutine_promise](http://en.cppreference.com/w/cpp/coroutine/noop_coroutine_promise)&gt;, intended to refer to a no-op coroutine  
> (typedef)

> ### Trivial awaitables

  
> Defined in header `[&lt;coroutine&gt;](https://en.cppreference.com/w/cpp/header/coroutine)`  
> [suspend_never](https://en.cppreference.com/w/cpp/coroutine/suspend_never)  
> (C++20)  
> indicates that an await-expression should never suspend  
> (class)  
> [suspend_always](https://en.cppreference.com/w/cpp/coroutine/suspend_always)  
> (C++20)  
> indicates that an await-expression should always suspend  
> (class)

3) Consider this CppReference sugested etxernal link for a coroutine tutorial (<https://www.scs.stanford.edu/~dm/blog/c++-coroutines.html> )?

4) Consider this (copy?) of the C++20 standard on Github (<https://timsong-cpp.github.io/cppwp/n4861/dcl.fct.def.coroutine> )?

5) Consider current support for C++20 coroutines in compilers and standard libraries?

==&gt; This seems to be the home of Gcc C++ status (<https://gcc.gnu.org/projects/cxx-status.html> )?

> C++20 features are available since GCC 8. To enable C++20 support, add the command-line parameter -std=c++20 (use -std=c++2a in GCC 9 and earlier) to your g++ command line. Or, to enable GNU extensions in addition to C++20 features, add -std=gnu++20.

> 10 (requires -fcoroutines)

==&gt; This seems to be the home of gnu C++ standard library status (<https://gcc.gnu.org/onlinedocs/libstdc++/> )?

> 10.1  __cpp_lib_coroutines &gt;= 201902L

==&gt; This seems to be the home of clang C++ status (<https://clang.llvm.org/cxx_status.html> )?

> You can use Clang in C++20 mode with the -std=c++20 option.

> The optimizer does not yet handle TLS with \`__attribute__((const))\` attribute correctly. There can be issues where the coroutine may resume on a different thread.  
> This feature requires further analysis of the C++ Standard to determine what work is necessary for conformance.

==&gt; This seems to be the home of llvm/clang libc++ C?+ standard library status (<https://libcxx.llvm.org> )?

==&gt; This seems to be the home of C++20 support in llvm/clang libc++ library (<https://libcxx.llvm.org/Status/Cxx20.html> )?

> 3393 Missing/incorrect feature test macro for coroutines Prague Complete 14.0

==&gt; It seems we can track each libc++ version status on this main llvm status page (<https://releases.llvm.org> )?

==&gt; It seems libc++ 12 is the first version stating a n y C++20 support <https://releases.llvm.org/12.0.0/projects/libcxx/docs/index.html> )?

...

{% endraw %}
