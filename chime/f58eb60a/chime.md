# Todo: Programming - Consider a strategy to evolve C++ library code from idea to optionally member of redeemed public library in a "controlled" way?

```#f58eb60a``` *As of 2016-07-20 15:52*

[mail plain/text](mail.txt)

{% raw %}
So, what could be a good strategy to enable a piece of code to evolve from an idea to a final published member of a C++ library?

1) Consider to scope such piece of code in more and more sobering name spaces?

==&gt; Consider the level of braced-scope (e.g. class, function, method, anonymous brace)?

==&gt; Such code is only accessible locally to the braced-scope { …code visible here ...}

> > function/method/if/else/for/while…{

> > }

> > … **this code visible in this scope only** ...

> > …

> > {

> > … **this code visible in this scope only** ...

> > }

==&gt; Consider the scope of anonymous namespace (<http://stackoverflow.com/questions/154469/unnamed-anonymous-namespaces-vs-static-functions>)?

==&gt; Such code is only visible in the scope of the file (i.e. in code located after the namespace definition)?

> > &lt;cpp-file&gt;

> > &lt;included file here&gt;

> > &lt;included file here&gt;

> > namespace {  
> > … **code visible in code of this cpp-file below** ...

> > }  
> > &lt;end cpp-file&gt;

==&gt; Consider the level of “translation unit” (e.g. in cpp-file but possible shared between linked units using header-file or explicit declarations)?

> > &lt;header-file&gt;

  
> > &lt;included file here&gt;

  
> > &lt;included file here&gt;



> > … **code here visible in following code until end of translation unit …**

> > &lt;end header-file&gt;



> > &lt;cpp-file&gt;

> > &lt;included file here&gt;

> > &lt;included file here&gt;

> > … **code here visible in following code until end of translation unit …**

> > &lt;end cpp-file&gt;

==&gt; Consider named local namespace?

==&gt; Consider namespace “local”

==&gt; Consider this would make code quite readable?

> > **local::MyClass**

> > **local::MyFunction**

> > **local::MyTemplate**

> > **...**

==&gt; Consider local namespace “incubator” for code that is identified as possible “library stuff"?

> > **incubator::MyClass**

> > **incubator::MyFunction**

> > **incubator::MyTemplate**

> > **...**



==&gt; Consider as member “experimental” of some existing library?

> > **some_lib::experimental::MyClass**

  
> > **some_lib::experimental****::MyFunction**

  
> > **some_lib::experimental****::MyTemplate**

  
> > **...**



…

…

Consider to elaborate on this idea of having some scope-based-evolution of library-stuff to enable it move from idea to final member of official library in some controlled way?

...

{% endraw %}
