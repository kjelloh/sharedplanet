# Todo: Consider to participate in C++ boost for Embarcadero XE 10 cross platform development?

```#11ebd4ec``` *As of 2015-12-08 12:15*

[mail plain/text](mail.txt)

{% raw %}
The reason boost does not list iOS and Android (among others) as supported platforms seems to be that no one is running regular regression tests for these platforms?

1) Consider to setup a regression test platform for RAD Studio cross-platform (iOS and Android) as defined by boost (http://beta.boost.org/development/running_regression_tests.html)?

2) Is it possible to modify the defined cross platform regression test framework to work with Embarcadero cross platform framework? We may need to tweak it as the boost test framework is cross platform in itself (using scripts and tools available at different platforms). But we want to run the test from a single source using the IDE in windows but still produce cross platform targets. So another way to phrase the question is if it is possible to run single source cross platform target tests using the boost regression test framework?

…

Consider to elaborate on this idea and find out more what is needed and possible to make this work?

{% endraw %}
