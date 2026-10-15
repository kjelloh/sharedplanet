# Todo: Programming - Consider to set up and run regression tests for boost on VS 2015 and RAD Studio XE7 (10)?

```#20eb2a57``` *As of 2015-12-08 13:42*

[mail plain/text](mail.txt)

{% raw %}
The boost site does not list any regression tests for Visual Studio 2015 nor RAD Studio (any version).

\* Also see “Todo: Consider to participate in C++ boost for Embarcadero XE 10 cross platform development?"

1) How to run regression tests seem to be defined here (<http://www.boost.org/development/running_regression_tests.html>)

2) Consider to try out this using Visual Studio as a start?

3) has anyone made any work to build boost libraries with RAD Studio in the boost regression test framework?

4) Seems the main boost environment is the same independent on compiler used (we may use the same root directory for testing with Visual Studio and RAD Studio)?

Requirements

-  • Python (2.3 ≤ version &lt; 3.0). (<https://www.python.org/downloads/windows/>)
-  • Git (recent version). (<https://git-scm.com/downloads>)
-  • At least 5 gigabytes of disk space per compiler to be tested.

The regression run procedure will:

-  • Download the most recent regression scripts.
-  • Download the designated testing tool sources including Boost.Jam, Boost.Build, and the various regression programs.
-  • Download the most recent from the Boost Git Repository into the subdirectory boost.
-  • Build b2 and process_jam_log if needed. (process_jam_log is a utility, which extracts the test results from the log file produced by Boost.Build).
-  • Run regression tests, process and collect the results.
-  • Upload the results to a common FTP server.

5) Installed Python and Git using default settings

==&gt; Chose latest Python 2.7 (not 3.5) as boost requirements stated &lt; 3.0 version.

==&gt; Installed latest Git using default settings (unknowing if any other settings is required to work with boost)?

6) Made a bat-file with the command to run the python core script

python run.py —runner=ITfied --toolsets=msvc-15.0 --tag=develop

==&gt; toolsets are somewhat explain here (<http://forums.codeguru.com/showthread.php?404688-bjam-error-warning-no-toolsets-are-configured>)

==&gt; Supported tools seems to be listed here, although the list seem incomplete (<http://www.boost.org/build/doc/html/bbv2/reference/tools.html>)?

“Boost.Build V2 requires you to configure toolsets you will use in user-config.jam file located at Boost.Build root. Without this configuration, toolset names won't be recognized and you'll get "invalid value for toolset feature" and/or "cannot compile C++ code" errors when you build a project.”

7) I had to update the PATH environment variable

==&gt; Added “;C:\\Python27” so that I was able to call on python command processor without having to explicitly define the path.

Note: You need to start a new command prompt window for the setting to take effect.

\*) Current state - error “run.py: error: no such option: -r” when running the script.

…

Consider to continue finding a way to make regression tests run for Visual Studio 2015 and RAD Studio XE7 (10)?

{% endraw %}
