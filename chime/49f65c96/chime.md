# Todo: Consider to document how to install and maintain C++ Boost libraries in Xcode and OS X?

```#49f65c96``` *As of 2018-04-24 13:02*

[mail plain/text](mail.txt)

{% raw %}
I suppose it should be a good idea to keep track of the best ways to install and maintain the C++ boost libraries on Xcode and OS X?

==&gt; Also see “[Todo: Programming - Consider to document how to configure Xcode to use boost?](../d228368b/chime.md)”

==&gt; Also see “[Todo: C++ Programming - Consider to try out Microsoft Casablanca REST SDK (cpprestsdk) on GitHub](../96bae485/chime.md)"

1) Consider to use brew?

==&gt; It seems if I use “brew upgrade” I actually get the latest version of boost (in this case 1.67)?

> Kjell-Olovs-MacBook-Pro-2014:build kjell-olovhogdahl$ **brew upgrade boost**  
> Updating Homebrew...  
> ==&gt; **Auto-updated Homebrew!**  
> Updated 2 taps (homebrew/core, caskroom/cask).  
> ==&gt; **Updated Formulae**  
> amazon-ecs-cli erlang kubeless presto  
> annie feh libgsf qmmp  
> atlassian-cli fn mysql sdcc  
> blueutil ghc mysql@5.5 silk  
> caddy gpgme mysql@5.6 spotbugs  
> cake haproxy node-build txr  
> calicoctl heroku nudoku typescript  
> dockviz kotlin osrm-backend wireguard-tools  
> ==&gt; **Renamed Formulae**  
> geth -&gt; ethereum

> ==&gt; **Upgrading 1 outdated package, with result:**  
> boost 1.60.0_1 -&gt; 1.67.0_1  
> ==&gt; **Upgrading ****boost**  
> ==&gt; **Downloading <https://homebrew.bintray.com/bottles/boost-1.67.0_1.high_sierra>.**  
> ==&gt; **Downloading from <https://akamai.bintray.com/26/265ab8beaa6fa26a7c305ef2e6aec>**  
> ######################################################################## 100.0%  
> ==&gt; **Pouring boost-1.67.0_1.high_sierra.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/boost/1.67.0_1: 13,506 files, 450.9MB  
> Kjell-Olovs-MacBook-Pro-2014:build kjell-olovhogdahl$

==&gt; One may then use “brew list” to get the include and lib paths where brew has placed the installed files?

> Kjell-Olovs-MacBook-Pro-2014:~ kjell-olovhogdahl$ brew list boost  
> /usr/local/Cellar/boost/1.67.0_1/include/boost/ (13368 files)  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_atomic-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_chrono-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_chrono.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_container-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_container.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_context-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_contract-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_contract.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_coroutine-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_coroutine.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_date_time-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_date_time.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_fiber-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_filesystem-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_filesystem.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_graph-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_graph.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_iostreams-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_iostreams.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_locale-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_log-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_log.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_log_setup-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_log_setup.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_math_c99-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_math_c99.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_math_c99f-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_math_c99f.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_math_c99l-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_math_c99l.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_math_tr1-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_math_tr1.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_math_tr1f-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_math_tr1f.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_math_tr1l-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_math_tr1l.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_prg_exec_monitor-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_prg_exec_monitor.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_program_options-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_program_options.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_random-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_random.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_regex-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_regex.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_serialization-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_serialization.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_signals-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_signals.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_stacktrace_addr2line-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_stacktrace_addr2line.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_stacktrace_basic-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_stacktrace_basic.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_stacktrace_noop-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_stacktrace_noop.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_system-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_system.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_thread-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_timer-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_timer.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_type_erasure-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_type_erasure.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_unit_test_framework-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_unit_test_framework.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_wave-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_wserialization-mt.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/libboost_wserialization.dylib  
> /usr/local/Cellar/boost/1.67.0_1/lib/ (70 other files)  
> Kjell-Olovs-MacBook-Pro-2014:~ kjell-olovhogdahl$

==&gt; To make Xcode link with brew-installed boost it seems we need to provide both brew-cellar paths to include and lib AND state the actual libraries to link to

-1) Consider to use only brew-installed libraries (and thus only brew-cellar search paths in Xcode)?

==&gt; This Xcode header search path seems to work (after brew install of required packages)

![](<Screen Shot 2018-04-24 at 12.49.14.png>)

**/usr/local/Cellar/boost/1.67.0_1/include/**

==&gt; This Xcode library search path seems to make link work (after brew installed required packages)?

![](<Screen Shot 2018-04-24 at 12.49.27.png>)

**/usr/local/Cellar/boost/1.67.0_1/lib/**

NOTE: Paths **separated by space** (and enclosed in “” for any paths that contain spaces)

==&gt; This Xcode link flag (argument -l , “minus ell”) seem to make link with boost library “system” work?

![](<Screen Shot 2018-04-24 at 12.59.08.png>)

**-lboost_system**

…

Consider to keep this Todo up to date when I discover new relevant information on boost libraries and Xcode integration?

{% endraw %}
