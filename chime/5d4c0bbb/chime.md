# Todo: Programming - Consider the C++ cross platform tool-chain and front-end/back-end options options?

```#5d4c0bbb``` *As of 2016-07-17 21:22*

[mail plain/text](mail.txt)

{% raw %}
So, what tool chains and application component stack options can we imagine for C++ cross platform development?

-1) Consider to document a “map” of possible tool-chains of major platforms?

windows ------- Visual Studio C++

|  |  |

|  |  |--- cl.exe (Microsoft C++ compiler)

|  |  |--- Clang/C2 (Clang front-end VS codegen and backend)

|  |  |--- clang-cl (Clang cl front-end)

|  |

|  |--- Embarcadero RAD Studio C++

|    |

|    \\-- bcc64/bcc32c (clang frontend windows backend)

| 3.1 (Seattle) 3.3 (Berlin)

|

|----------- MinGW

|   |

|   |--- gcc (GNU C++)

|   |--- clang

|

|----------- Cygwin

|

|--- gcc

\\--- clang (but links with gcc libstdc+ (clang native libc++ not yet provided)

Linux --------- gcc

|

\\---- clang

MacOS --------- Xcode

|

\\---- clang

1) Consider the C++ tool-chains available on Windows?

==&gt; Consider to study Visual Studio 2015 with Clang/C2 (<https://blogs.msdn.microsoft.com/vcblog/2015/12/04/clang-with-microsoft-codegen-in-vs-2015-update-1/>)?

...

==&gt; Consider Visual Studio 2015 with Clang/LLVM (Clang-Cl)

==&gt; Cmake seems to be able to generate Visual Studio 2015 with Clang/LLVM (Clang-Cl) with “LLVM-vs2014” toolset and “Visual Studio 14 2015 Win64” generator (<https://github.com/boostorg/hana/wiki/Setting-up-Clang-on-Windows>)?

&gt;cmake .. -TLLVM-vs2014 -G"Visual Studio 14 2015 Win64”

==&gt; This seems to actually be clang-cl front-end that aims at emulating Visual Studio C++ compiler cl.exe (<http://clang.llvm.org/docs/UsersManual.html#id69>)

==&gt; Cmake reference seems to live here (<https://cmake.org/cmake/help/v3.6/manual/cmake.1.html>)?

==&gt; Consider MinGW64 with native Clang/LLVM

==&gt; Cmake seems to be able to generate MinGW tool-chain for MSYS and clang by setting clang compiler and using generator "MSYS Makefiles"

&gt;cmake .. -DCMAKE_CXX_COMPILER=clang++ -G"MSYS Makefiles"

==&gt; Cygwin64 with native Clang

==&gt; clang on Cygwin64 links with gcc libstdc++ (clang native libc++ not yet provided)?

==&gt; May still work depending on project requirements?

...

==&gt; Consider Embarcadero RAD Studio C++ (<https://www.embarcadero.com/products/cbuilder>)?

2) Consider the cppcon 2015 talk on C++ cross platform development (<https://www.youtube.com/watch?v=2Y47g8xNE1o&index=40&list=PLHTh1InhhwT75gykhs7pqcR_uSiG601oh>)?

==&gt; They talk about the “Silo Approach” as being totally native on each platform (principle no shared code due to different language code-bases)?

==&gt; The talk about “Cross Platform Approach” using some riding tool to write common base code that is then generated into different targets?

![](<C++ cross platform tools.tiff>)

==&gt; Phonegap seems to live here (<http://phonegap.com>)?

==&gt; Seems to be a web-based approach (shared server side code)?

“Reuse existing web development skills to quickly make hybrid applications built with HTML, CSS and JavaScript. Create experiences for multiple platforms with a single codebase so you can reach your audience no matter their device."

==&gt; Seems to be based on Open Source Apache “Cordova” (<https://cordova.apache.org>)?

==&gt; Tamarin seems to live here (<https://www.xamarin.com>)?

==&gt; It seems to be to enable C#/F# development on multiple platforms?

“Xamarin brings open source .NET to mobile development, enabling every developer to build truly native apps for any device in C# and F#”

...

3) Consider this cppcon 2015 talk showing a proposal for Windows, Android and Apple (at 14:45 into <https://www.youtube.com/watch?v=2Y47g8xNE1o&index=40&list=PLHTh1InhhwT75gykhs7pqcR_uSiG601oh>)?

![](<C++ cross platform component stack proposal.tiff>)

==&gt; Seems proposed windows stack is &lt;C++ back end&gt; &lt;—&gt; &lt;Pinvoke C++ wrapper&gt; &lt;—&gt; &lt;C++/CX&gt; &lt;—&gt; &lt;XAML GUI&gt; ==&gt; .appx application

==&gt; Seems proposed Android stask is &lt;C++ back end&gt; &lt;—&gt; &lt;Java&gt; &lt;—&gt; &lt;XML GUI&gt; ==&gt; .apk application

==&gt; Seems proposed apple stack is &lt;&lt;C++ back end&gt; &lt;—&gt; &lt;ObjC Wrapper&gt; &lt;—&gt; &lt;Cocoa Touch GUI&gt; ==&gt; .ipa application

==&gt; Seems on windows the proposed shared binary targets are dll-files and lib-files?

==&gt; Seems on Android the proposed shared binary targets are so-files and a-files (Linux shared objects and archive files)?

==&gt; Seems on apple the proposed shared binary targets are a-files (Linux archive files)?

==&gt; This wikipedia page seems like a good overview of different platforms shared binaries (<https://en.wikipedia.org/wiki/Library_(computing))?>

…

4) Consider the “Silo App"

5) Consider to delve into windows options of having GUI in C++/Cx (<https://msdn.microsoft.com/en-us/library/hh699871.aspx>)

“Use C++/CX to write Windows apps and components in native code that easily interact with Visual C#, Visual Basic, and JavaScript, and other languages that support the Windows Runtime. In those rare cases that require direct access to the raw COM interfaces, or non-exceptional code, you can use the Windows Runtime C++ Template Library (WRL).”

…

Consider to delve deeper into possible approaches for C++ cross platform development?

...

{% endraw %}
