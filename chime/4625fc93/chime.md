# Todo: Programming - Consider to use Boost config headers as a "standard" pre-processor library for build environment identification?

```#4625fc93``` *As of 2016-08-02 16:27*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to use the actual Boost config header structure in my own libraries as a pre-processor service to identify the build platform?

1) Consider to compare with how Boost libraries are designed to adopt to cross-platform and feature build environments (<http://www.boost.org/doc/libs/1_61_0/libs/config/doc/html/index.html>)?

“Using boost "as is" without trying to reconfigure is the recommended method for using boost.”

“Boost informational or helper macros are designed for use by Boost users as well as for our own internal use.”

==&gt; This seem to be the boost/config.hpp that both Boost libraries and user code may use to apply boost way of identifying and adopting to build environment (<http://www.boost.org/doc/libs/1_61_0/boost/config.hpp>)?

==&gt; Boost seem to apply three different headers to identify compiler, standard library and platform and mirror them as boost macros?

==&gt; It also seem to apply a (default empty) “user” include before including any of the other config headers (<http://www.boost.org/doc/libs/1_61_0/boost/config/user.hpp>)?

> > “Boost's configuration is structured so that the user-configuration is included first (defaulting to &lt;boost/config/user.hpp&gt; if BOOST_USER_CONFIG is not defined). This sets up any user-defined policies, and gives the user-configuration a chance to influence what happens next.

> > Next the compiler, standard library, and platform configuration files are included. These are included via macros (BOOST_COMPILER_CONFIG etc, see user settable macros), and if the corresponding macro is undefined then a separate header that detects which compiler/standard library/platform is in use is included in order to set these. The config can be told to ignore these headers altogether if the corresponding BOOST_NO_XXX macro is set (for example BOOST_NO_COMPILER_CONFIG to disable including any compiler configuration file - see user settable macros).

  
> > Finally the boost configuration header, includes &lt;boost/config/suffix.hpp&gt;; this header contains any boiler plate configuration code - for example where one boost macro being set implies that another must be set also."

==&gt; Boost seem to provide a “compiler identification” header file (<http://www.boost.org/doc/libs/1_61_0/boost/config/select_compiler_config.hpp>)

==&gt; It seems to be further divided into compiler-specific include files?

==&gt; This seem to be the one for Microsoft Visual Studio compilers (<http://www.boost.org/doc/libs/1_61_0/boost/config/compiler/visualc.hpp>)?

==&gt; NOTE: There seem to be none for CodeGear but NONE for Embarcadero (suggesting official Boost does not target Embarcadero)?

==&gt; Boost seem to provide a “Standard library” identification header file (<http://www.boost.org/doc/libs/1_47_0/boost/config/select_stdlib_config.hpp>)?

==&gt; It seems to be divided into library specific include files?

2) Consider to document the result (in the forms of Boost macros) from the build platform identification header processing?

==&gt; Hm, seems we do not get the macros we want /they seem rather add-hoc)?

…

3) Consider to design a seed to an open source library with a header to include that sets a fix set of macros that identifies the build platform?

...

…

Consider to delve into this idea to use existing boost config headers to generate pre-process macro settings that mirrors the build environment in some “standard” way?

...

{% endraw %}
