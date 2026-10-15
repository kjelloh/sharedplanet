# Todo: Programming - Consider to understand and try out the CMake environment for Windows?

```#56dd375e``` *As of 2015-12-12 15:48*

[mail plain/text](mail.txt)

{% raw %}
Make seem to be the currently most popular cross platform make tool for C-like languages (C++ explicitly)

1) It seem to enable intelligent (local system service and file discovery) cross platform make utility (<https://cmake.org/>)?

2) CMake for windows seem to be available as win32 installer (<https://cmake.org/download/>)?

==&gt; Downloaded and installed cmake-3.4.1-win32-x86.exe.

==&gt; The installer is not signed (trust anyways)

![](CMake_installer_unknown_publisher.tiff)

==&gt; Made installer add CMake to PATH (for convenient use)

![](Cmake_add_to_path.tiff)

==&gt; Installed to default “C:\\Program Files (x86)\\CMake”

==&gt; The installer failed to add CMake to PATH (PATH variable to long)

![](CMake_install_unable_to_update_PATH.tiff)

==&gt; Added “C:\\Program Files (x86)\\CMake\\bin” to PATH manually (no problem)

==&gt; Note: Error could be due to having a folder property dialog open in windows finder?

==&gt; make now works in windows command prompt :)

3) Consider to download the source code and build using Visual Studio ()?

{% endraw %}
