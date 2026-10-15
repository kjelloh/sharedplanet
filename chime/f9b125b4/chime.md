# Todo: Programming - Consider to delve into C++ Guidelines Support Library (GSL) on github?

```#f9b125b4``` *As of 2016-04-04 17:51*

[mail plain/text](mail.txt)

{% raw %}
So, what can we learn from (and perhaps provide to) the current C++ Core Guidelines Library on github?

1) The project seem to live here (<https://github.com/Microsoft/GSL>)

2) The Guideline Support Library on Github does not seem to compile with RAD Studio 10 Seattle Clang C++ Compiler?

&#91;CLANG Error&#93; span.h(163): functions that differ only in their return type cannot be overloaded

163: constexpr const_reference operator&#91;&#93;(size_t component_idx) const noexcept

span.h(156): previous declaration is here

156: constexpr reference operator&#91;&#93;(size_t component_idx)

==&gt; Consider this is due to RAD Studio using Clang 3.3 (See “Todo: Programming - Consider tro build c++ boost libraries from source?” and <http://docwiki.embarcadero.com/RADStudio/Seattle/en/Clang-enhanced_C%2B%2B_Compilers>)

==&gt; It seems Clang 3.3 is C++11 compliant (some experimental C++14) but we need 3.4 for C++14 draft compliance (<http://clang.llvm.org/cxx_status.html>)?

==&gt; Seems the GSL /Guidline Support Library) requires C++14 compliance (<https://github.com/Microsoft/GSL>)?

“The implementation generally assumes a platform that implements C++14 support”

==&gt; So, when will RAD Studio get C++14 support (C++14 the official standard since dec 2014)?

**WE ARE HERE...**

3) Consider the benefits of Git Cloning the project rather than just download and unzip?

==&gt; Cloned to Windows 10 machine “**C:\\git\\GSL**” using TortoiseGit

==&gt; Note: Right-click in C:\\git and select “Git Clone” from TortoiseGit list of services (subfolder GSL assumed by service)

![](gsl_pull_160404.tiff)

![](Git_gsl_directory.tiff)

**WE ARE HERE...**

{% endraw %}
