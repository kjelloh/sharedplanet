# Todo: RxCpp Twitter App Example - Consider to document how I got the example application from GitHub to run and consume twitter posts?

```#4e9b0924``` *As of 2017-07-25 21:07*

[mail plain/text](mail.txt)

{% raw %}
It seems I am very close to get the twitter app example by to actually run on my MAC?

1) The twitter app seems to live here (<https://github.com/kirkshoop/twitter>)?

> Kjell-Olovs-MacBook-Pro:GitHub kjell-olovhogdahl$ git clone <https://github.com/kirkshoop/twitter.git> --recursive  
> Cloning into 'twitter'...  
> ...

2) The project had a lot of dependencies that I had to install for the cmake to succeed to generate the Xcode project?

> Kjell-Olovs-MacBook-Pro:GitHub kjell-olovhogdahl$ git clone <https://github.com/Reactive-Extensions/RxCpp.git> --recursive  
> Cloning into 'RxCpp'…  
> …

> Kjell-Olovs-MacBook-Pro:GitHub kjell-olovhogdahl$ git clone <https://github.com/ericniebler/range-v3.git> --recursive  
> Cloning into 'range-v3'…  
> …

> Kjell-Olovs-MacBook-Pro:GitHub kjell-olovhogdahl$ git clone <https://github.com/nlohmann/json.git>  
> Cloning into 'json'...  
> ...

> Kjell-Olovs-MacBook-Pro:build kjell-olovhogdahl$ brew install liboauth  
> …

> Kjell-Olovs-MacBook-Pro:build kjell-olovhogdahl$ brew install glew  
> …

> Kjell-Olovs-MacBook-Pro:build kjell-olovhogdahl$ brew install sdl2  
> …

> Kjell-Olovs-MacBook-Pro:build kjell-olovhogdahl$ brew install sdl2_mixer  
> ...

> Kjell-Olovs-MacBook-Pro:build kjell-olovhogdahl$ brew install pkgconfig  
> …

3) It seems the cloned app was missing some files and settings I need to provide to get it to build?

==&gt; It seems to build ok after I added two wav-files dash.wav and dot.wav.

==&gt; The first problem was that cmake could not find dash.wav

> > CMake Error at CMakeLists.txt:123 (add_executable):

> > Cannot find source file:

> > /Users/kjell-olovhogdahl/Documents/GitHub/twitter/dash.wav

==&gt; The second problem was that the CMakeLists.txt was missing to define dot.wav that the application actually required on execution.

==&gt; I edited CMakeLists.txt

> > # define the resources  
> > set(SAMPLE_RESOURCES  
> > ${CMAKE_CURRENT_SOURCE_DIR}/imgui.ini  
> > ${CMAKE_CURRENT_SOURCE_DIR}/NotoMono-Regular.ttf  
> > ${CMAKE_CURRENT_SOURCE_DIR}/NotoSansSymbols-Regular.ttf  
> > ${CMAKE_CURRENT_SOURCE_DIR}/dash.wav  
> > **${CMAKE_CURRENT_SOURCE_DIR}/dot.wav**  
> > )

==&gt; Then I simply fetched a free wav-file (<http://www.wavsource.com/snds_2017-06-18_4861080274558637/sfx/arrow2.wav>) and renamed it dot.wav and dash.wav.

==&gt; I placed the files in the cloned project root (see “/Users/kjell-olovhogdahl/Documents/GitHub/twitter”)

==&gt; This made Xcode (later) being able to assemble a package with these files ok on build of the application.

4) After some fixes I was able to use cmake to generate Xcode project for the twitter application

==&gt; It seems I had been able to populate my MAC to comply with all dependencies if the CMakeLists.txt file (see log output in bold below)?

> Kjell-Olovs-MacBook-Pro:build kjell-olovhogdahl$ cmake -G"Xcode" ..  
> -- Location: /Users/kjell-olovhogdahl/Documents/GitHub/twitter  
> -- CMAKE_CXX_COMPILER_ID: AppleClang  
> -- using clang settings  
> **-- LIBOAUTH_INCLUDE_DIRS: /usr/local/include**  
> **-- CURL_INCLUDE_DIRS: /usr/include**  
> **-- OPENGL_INCLUDE_DIRS: **  
> **-- GLEW_INCLUDE_DIRS: /usr/local/include**  
> **-- SDL2_INCLUDE_DIRS: /usr/local/Cellar/sdl2/2.0.5/include/SDL2**  
> **-- SDL2_LIBRARIES: -L/usr/local/Cellar/sdl2/2.0.5/lib -lSDL2**  
> **-- SDLMIXER_INCLUDE_DIR: /usr/local/include/SDL2**  
> **-- range-v3_INCLUDE_DIRS: /Users/kjell-olovhogdahl/Documents/GitHub/twitter/build/src/range-v3/include**  
> **-- rxcpp_INCLUDE_DIRS: /Users/kjell-olovhogdahl/Documents/GitHub/twitter/build/src/rxcpp/Rx/v2/src**  
> **-- jsoncpp_INCLUDE_DIR: /Users/kjell-olovhogdahl/Documents/GitHub/twitter/build/src/jsoncpp/src**  
> -- Boost version: 1.60.0  
> -- Found the following Boost libraries:  
> -- thread  
> -- chrono  
> -- system  
> -- date_time  
> -- atomic  
> -- Boost_VERSION: 106000  
> -- Configuring done  
> -- Generating done  
> -- Build files have been written to: /Users/kjell-olovhogdahl/Documents/GitHub/twitter/build  
> Kjell-Olovs-MacBook-Pro:build kjell-olovhogdahl$

5) It seemed I had to explicitly build the dependent targets in Xcode to be able to build the twitter target?

==&gt; If I tried ALL_BUILD it seems to start with “twitter” and then the dependent source from rxcpp, range-v3 etc. was missing.

![](<RxCpp Twitter App targets.png>)

==&gt; Building the targets rxcpp, range-v3, jsoncpp seems sufficient to then build twitter ok.

==&gt; Note: Through some Xcode project magic the source was fetched to “/Users/kjell-olovhogdahl/Documents/GitHub/twitter/build/src”.

==&gt; NOTE: Xcode builds a package for this application (and the application runs in that package)

==&gt; This means we cant open the folder of the application in finder without some tricks.

==&gt; To open the Package, right click the file “/Users/kjell-olovhogdahl/Documents/GitHub/twitter/build/Debug/twitter.app” and select &lt;Show Package Contents&gt;

![](<RxCpp Twitter App exe folder contents.tiff>)

![](<RxCpp Twitter App Resources folder contents.tiff>)

==&gt; Note how Xcode has populated Resources with the two wav-files we created to fix that they where missing from the GitHub project.

==&gt; At this stage I was able to make the application run (BUT it fails to Authorise at (<https://stream.twitter.com/1.1/statuses/>)

6) Consider to get an Authorisation key and private data to be able to connect to “<https://stream.twitter.com/1.1/statuses/>“?

==&gt; This seems to be the twitter page where we can read about how to get an Application key and credentials to be able to authorise to access the twitter stream (<https://dev.twitter.com/streaming/overview>)?

==&gt; It seems we first have to “create” an application and register it with Twitter (<https://apps.twitter.com/app/new>)?

…

…

Consider to get the application to work to actually filter twitter feeds and then study the application and optionally publish my findings on how to make this example work (a gist or a github fork with the missing files added)?

...

{% endraw %}
