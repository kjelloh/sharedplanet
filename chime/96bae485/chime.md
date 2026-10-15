# Todo: C++ Programming - Consider to try out Microsoft Casablanca REST SDK (cpprestsdk) on GitHub

```#96bae485``` *As of 2018-04-24 13:22*

[mail plain/text](mail.txt)

{% raw %}
It seems it could be a good idea to see what Microsoft REST SDK C++ library on GitHub can do?

==&gt; Also see “[Todo: Consider to document how to install and maintain C++ Boost libraries in Xcode and OS X?](../49f65c96/chime.md)"

-1) Consider to use only brew-installed libraries (and thus only brew-cellar search paths in Xcode)?

==&gt; This Xcode header search path seems to work (after brew install of required packages)

![](<Screen Shot 2018-04-24 at 12.49.14.png>)

**/usr/local/Cellar/cpprestsdk/2.10.2/include /usr/local/Cellar/openssl/1.0.2o_1/include/ /usr/local/Cellar/boost/1.67.0_1/include/**

==&gt; This Xcode library search path seems t0 make link work (after brew installed required packages)?

![](<Screen Shot 2018-04-24 at 12.49.27.png>)

**/usr/local/Cellar/cpprestsdk/2.10.2/lib /usr/local/Cellar/openssl/1.0.2o_1/lib/ /usr/local/Cellar/boost/1.67.0_1/lib/**

NOTE: Paths **separated by space** (and “” to required for paths as they do not contain any spaces themselves)

1) The Microsoft cpprestsdk project seems to live here on GitHub (<https://github.com/Microsoft/cpprestsdk/wiki/Getting-Started-Tutorial>)?

…

2) It seems we can install the cpprestsdk on OS X using brew?

> Kjell-Olovs-MacBook-Pro-2014:~ kjell-olovhogdahl$ brew install cpprestsdk  
> Updating Homebrew...  
> ==&gt; **Auto-updated Homebrew!**  
> Updated 2 taps (homebrew/core, caskroom/cask).  
> ==&gt; **Updated Formulae**  
> adplug hadolint perl  
> apache-drill heroku radare2  
> armadillo inspircd scrcpy  
> aspectj jenkins-job-builder scw  
> atari800 json-fortran siril  
> baresip libetonyek snapcraft  
> bento4 libfaketime subversion  
> cake libre tgui  
> convox librem travis  
> cpanminus liquibase twarc  
> exim mg unpaper  
> ffmpeg mgba unrar  
> ffmpeg2theora mikutter valabind  
> ffmpegthumbnailer minidlna vim  
> ffms2 mpd vim@7.4  
> fluent-bit mpv webp  
> fn opencv wp-cli  
> freeling opencv@2 wpcli-completion  
> freeradius-server openfortivpn xmrig  
> gifski openimageio  
> grib-api percona-toolkit

> ==&gt; **Downloading <https://homebrew.bintray.com/bottles/cpprestsdk-2.10.2.high_sier>**  
> ==&gt; **Downloading from <https://akamai.bintray.com/d1/d14bed2a2b49d91649d9fc8aa9708>**  
> ######################################################################## 100.0%  
> ==&gt; **Pouring cpprestsdk-2.10.2.high_sierra.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/cpprestsdk/2.10.2: 51 files, 5MB  
> Kjell-Olovs-MacBook-Pro-2014:~ kjell-olovhogdahl$

==&gt; It seems to be installed to brew “Cellar” path /usr/local/Cellar/cpprestsdk/2.10.2 with subfolders /include and /lib?

> Kjell-Olovs-MacBook-Pro-2014:MyCppRestDSKPlayGround kjell-olovhogdahl$ **brew list** cpprestsdk  
> **/usr/local/Cellar/cpprestsdk/2.10.2/include**/cpprest/ (33 files)  
> /usr/local/Cellar/cpprestsdk/2.10.2/include/pplx/ (8 files)  
> **/usr/local/Cellar/cpprestsdk/2.10.2/lib**/libcpprest.2.10.dylib  
> /usr/local/Cellar/cpprestsdk/2.10.2/lib/cpprestsdk/ (3 files)  
> /usr/local/Cellar/cpprestsdk/2.10.2/lib/libcpprest.dylib  
> Kjell-Olovs-MacBook-Pro-2014:MyCppRestDSKPlayGround kjell-olovhogdahl$ brew info cpprestsdk  
> cpprestsdk: stable 2.10.2 (bottled), HEAD  
> C++ libraries for cloud-based client-server communication  
> <https://github.com/Microsoft/cpprestsdk>  
> /usr/local/Cellar/cpprestsdk/2.10.2 (51 files, 5MB) \*  
> Poured from bottle on 2018-04-22 at 17:56:56  
> From: <https://github.com/Homebrew/homebrew-core/blob/master/Formula/cpprestsdk.rb>  
> ==&gt; **Dependencies**  
> Build: **cmake ****✘**  
> Required: **boost ****✔**, **openssl ****✔**  
> ==&gt; **Options**  
> --HEAD  
> Install HEAD version  
> Kjell-Olovs-MacBook-Pro-2014:MyCppRestDSKPlayGround kjell-olovhogdahl$

3) It seems I needed to add openssl-stuff to my CMake file?

==&gt; This CMakeLists.txt at least worked on OS X

> cmake_minimum_required(VERSION 3.7)  
> project(main)  
> SET(OPENSSL_ROOT_DIR "/usr/local/Cellar/openssl/1.0.2o_1")

> find_package(cpprestsdk REQUIRED)  
> find_package(openssl REQUIRED)

> add_executable(main main.cpp)  
> target_link_libraries(main PRIVATE cpprestsdk::cpprest)

==&gt; Green lines added by me (the rest is according to cpprestsdk GitHub instructions)

4) It seems I need to force cmake to actually generate Xcode tool chain (by default it created Unix make files)?

==&gt; See “/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyCppRestDSKPlayGround"

> Kjell-Olovs-MacBook-Pro-2014:build kjell-olovhogdahl$ **cmake -G Xcode ..**  
> -- The C compiler identification is AppleClang 9.1.0.9020039  
> -- The CXX compiler identification is AppleClang 9.1.0.9020039  
> -- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang  
> -- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang -- works  
> -- Detecting C compiler ABI info  
> -- Detecting C compiler ABI info - done  
> -- Detecting C compile features  
> -- Detecting C compile features - done  
> -- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++  
> -- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ -- works  
> -- Detecting CXX compiler ABI info  
> -- Detecting CXX compiler ABI info - done  
> -- Detecting CXX compile features  
> -- Detecting CXX compile features - done  
> -- Found ZLIB: /usr/lib/libz.dylib (found version "1.2.11")  
> -- Found OpenSSL: /usr/local/Cellar/openssl/1.0.2o_1/lib/libcrypto.dylib (found version "1.0.2o")  
> -- Configuring done  
> -- Generating done  
> -- Build files have been written to: /Users/kjell-olovhogdahl/Resilio Sync/XCode/MyCppRestDSKPlayGround/MyCppRestDSKPlayGround/build  
> Kjell-Olovs-MacBook-Pro-2014:build kjell-olovhogdahl$

==&gt; It seems I need to manually configure Xcode project to use cpprestsdk brew-installed includes and libraries?

![](<Screen Shot 2018-04-24 at 11.55.46.png>)

==&gt; It seems I need to manually configure Xcode to use openssl brew-installed include and libraries?

![](<Screen Shot 2018-04-24 at 12.28.36.png>)

==&gt; It seems I have to annually configure Xcode to actually link with “ssl” and “crypto” (parts of the openssl library

![](<Screen Shot 2018-04-24 at 12.24.45.png>)

==&gt; It seems I manually have to configure Xcode header search path to find boost libraries

![](<Screen Shot 2018-04-24 at 12.40.35.png>)

==&gt; NOTE: I later decided to use paths to brew-cellar paths (to use **brew installed boost**). - See appendix and -1) above.

==&gt; NOTE: The /usr/local/linclude and /usr/local/lib works for boost install NOT using brew (e.g.,

==&gt; It seems I manually need to configure Xcode to actually link with boost library

![](<Screen Shot 2018-04-24 at 12.52.20.png>)

==&gt; Now I could generate an Xcode tool chain using cmake, configure Xcode manually and build a simple C++ console application ok

![](<Screen Shot 2018-04-24 at 13.19.51.png>)

==&gt; NOTE: It took me a very LONG time to figure out all the small settings to get the code build in Xcode (read 4-5 hours)!

**\*SUCKS\* - Why is the feed back from cmake (or the information from GitHub Project) so bad that this can even happen?**

**NOTE: Getting the project and tool-chain into a correct state SHOULD NOT be a manual process (and not a guessing game)!**

6) It seems we can use “brew list” to query where it has installed different libraries we need to access to build cpprestsdk -dependent code?

==&gt; Brew seem to install openssl to path “/usr/local/Cellar/openssl"

> Kjell-Olovs-MacBook-Pro-2014:MyCppRestDSKPlayGround kjell-olovhogdahl$ **brew list openssl**  
> **/usr/local/Cellar/openssl**/1.0.2o_1/.bottle/etc/ (8 files)  
> /usr/local/Cellar/openssl/1.0.2o_1/bin/c_rehash  
> /usr/local/Cellar/openssl/1.0.2o_1/bin/openssl  
> /usr/local/Cellar/openssl/1.0.2o_1/include/openssl/ (74 files)  
> /usr/local/Cellar/openssl/1.0.2o_1/lib/libcrypto.1.0.0.dylib  
> /usr/local/Cellar/openssl/1.0.2o_1/lib/libssl.1.0.0.dylib  
> /usr/local/Cellar/openssl/1.0.2o_1/lib/engines/ (12 files)  
> /usr/local/Cellar/openssl/1.0.2o_1/lib/pkgconfig/ (3 files)  
> /usr/local/Cellar/openssl/1.0.2o_1/lib/ (4 other files)  
> /usr/local/Cellar/openssl/1.0.2o_1/share/man/ (1680 files)  
> Kjell-Olovs-MacBook-Pro-2014:MyCppRestDSKPlayGround kjell-olovhogdahl$

==&gt; It seems brew installs boost libraries to its Cellar path “/usr/local/Cellar/boost”

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

…

Consider to continue to delve into how the Microsoft C++ REST SDK can actually work for me?

...

{% endraw %}
