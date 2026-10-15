# Todo: Programming - Consider to generate CMake C++ Console project cross platform MacOS, Linix MAKET and Microsoft Visual Studio?

```#06fb30da``` *As of 2016-07-11 18:01*

[mail plain/text](mail.txt)

{% raw %}
So, what do we get if we write a C++ main() console application and generate a build environment using CMake for the three major platforms?

==&gt; Compare with “Todo: Programming - Consider to design a C++ console application source and environment setup that will cross compile on Windows, MacOS and Linux?”

1) Consider to find out the absolute minimum CMake input and generated make environment of the three environments?

==&gt; Q: What CMake inout script file do we need for each platform (can we design a common one)?

2) Consider to document below the generated build environment for the three platforms?

==&gt; Q: What Visual Studio Project is generated on Windows 10?

==&gt; Q: What Xcode project is generated on MacOS?

==&gt; What make-script is generated on Linus MATE?

3) Consider to compare these build environments with the default one found in previous Todo?

==&gt; See “Todo: Programming - Consider to design a C++ console application source and environment setup that will cross compile on Windows, MacOS and Linux?”

==&gt; Consider to digg the text-files for each platform that defines the build environment?

==&gt; The vcproj-file for Visual Studio?

==&gt; The pbxproj-file (xml) in folder .xcodeproj (yes, this is a folder although finder shows it as a file)

> > Kjell-Olovs-MacBook-Pro:MyDEfaultCOmmandLineTool.xcodeproj kjell-olovhogdahl$ pwd

> > /Shared/workplace/Xcode/MyDEfaultCOmmandLineTool/MyDEfaultCOmmandLineTool.xcodeproj

> > Kjell-Olovs-MacBook-Pro:MyDEfaultCOmmandLineTool.xcodeproj kjell-olovhogdahl$ cat project.pbxproj

==&gt; the make-file on Linus MATE.

==&gt; Consider to also investigate if Clion keeps an IDE project file ot its own?

...

==&gt; What differs between CMake generated and default one for Visual Studio?

==&gt; What differs between CMake generated and default one for Xcode?

==&gt; What differs between CMake generated and Clion generated default one for Linus MATE?

…

Consider to investigate the platform build environments from the angel of having the same CMake script generate on for each one of them?

...

{% endraw %}
