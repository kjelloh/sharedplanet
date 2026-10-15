# Todo: Programming - Consider to design Odysseus (C++ library) mechanism that Tris (C++ Library) may use to populating the namespace with available &lt;filesystem&gt;?

```#6a74982d``` *As of 2016-08-04 14:46*

[mail plain/text](mail.txt)

{% raw %}
Consider what mechanism to use to have Odysseus populate its namespace with something that This may then use compile-time to populate its namespace with the available &lt;filesystem&gt;?

1) Consider we want a mechanism that produces a readable compile-time error if there is no &lt;filesystem&gt; available?

==&gt; Consider what alternative &lt;filesystem&gt; we should be able to detect and use?

==&gt; Boost Filesystem (<http://www.boost.org/doc/libs/1_61_0/libs/filesystem/doc/index.htm>)

> > #define BOOST_FILESYSTEM_NO_DEPRECATED // prevents inadvertent use of old features, particularly legacy function names, that have been replaced and are going to go away in the future.

> > #include &lt;boost/filesystem.hpp&gt; // provides access to all features of the library, except file streams.

> > #include &lt;boost/filesystem/fstream.hpp&gt; // inherits the same components as the C++ Standard Library's fstream header, but files are identified by const path& arguments rather that const char\* arguments.

> > using namespace boost::filesystem;

==&gt; Visual Studio C++ &lt;filesystem&gt; (<https://msdn.microsoft.com/en-us/library/hh874694.aspx>)

> > #include &lt;filesystem&gt;

> > using namespace std::tr2::sys;

2) )Consider we want a mechanism that can be used compile-time to investigate what features the found &lt;filesystem&gt; provides?

==&gt; Consider &lt;filesystem&gt; to be experimental until C++17 and thus its compile-time interface may vary with the available implementation?

==&gt; Consider ways to bring filesystem members into Tris namespace using Odysseus mechanism?

==&gt; Pros: Exposes the whole content of available &lt;filesystem&gt; into namespace (and client may expose it to its namespaces)

==&gt; Cons: Client code is not protected from incompatible &lt;filesystem&gt; (must interpret compile errors that may be hard to reason about)?

> namespace tris {  
> using namespace odysseus::platform::filesystem; // Odysseus has populated its namespace with available filesystem?  
> }

Consider ways to create a tris struct with SFIANE conditioned members picking selected members of filesystem (in effect defining an API to filesystem members)?

==&gt; See ”Todo: Programming - Consider to understand std::enable_if and the SFINAE idiom and what to use it for?”

==&gt; Pros: Members of &lt;filesystem&gt; are exposed in a very controlled way (has to be explicitly made member in struct)

==&gt; Cons: Can get tedious to keep filesystem struct members compliant with available standard?

==&gt; Consider Odysseus provides a stdlib type tag that Tris may define filesystem trait meta-functions for?

…

3) Consider the Odysseus mechanism should use the defined C++ standard library headers (<http://en.cppreference.com/w/cpp/header>)?

==&gt; Consider how and when Odysseus should try to include C++ standard library headers to detect &lt;filesystem&gt; presens?

4) Consider Odysseus may use the pre-defined macros of the used C++ Standard library implementation?

==&gt; Consider the Odysseus mechanism should use the C++ standard library pre-defined macros (<http://www.cplusplus.com/doc/tutorial/preprocessor/>)?

==&gt; Consider the Odysseus may use implementation specific pre-designed C++ standard library macros?

…

Consider to elaborate on different ways to have odysseus provide compile time mechanisms to enable Tris to bring the available &lt;filesystem&gt; into its namespace in a ”controlled” way?

...

{% endraw %}
