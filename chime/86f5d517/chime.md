# Todo: Programming - Remember how to install c++ boost for Visual Studio 2015

```#86f5d517``` *As of 2015-12-03 21:42*

[mail plain/text](mail.txt)

{% raw %}
I wanted to compile c++ boost examples with Visual Studio 2015 but by default no boost seem to be available in the environment?

1) Found information on boost web-site about ready-to-install files for windows (<http://sourceforge.net/projects/boost/files/boost-binaries/1.59.0/>)

==&gt; A dependcy text file stated that for Visual studio 2015 i was to install the file post-fixed msvs-14 (<http://sourceforge.net/projects/boost/files/boost-binaries/1.59.0/DEPENDENCY_VERSIONS.txt/download>)

2) I downloaded and ran the file boost_1_59_0-msvc-14.0-64.exe (<http://sourceforge.net/projects/boost/files/boost-binaries/1.59.0/boost_1_59_0-msvc-14.0-64.exe/download>)

3) The boost library 1.59 was installed by default to "C:\\local\\boost_1_59_0”

4) This was the lead I followed to install and configure for Visual Studio (<http://stackoverflow.com/questions/2629421/how-to-use-boost-in-visual-studio-2010>)

==&gt; I added "C:\\local\\boost_1_59_0” to VC Include directory to all targets and all platfroms

![](Boost_VS_Include_Add.tiff)

![](boost_VS_Include_Setting_2.tiff)

…

These steps seem to work. Consider to update when needed for future versions of Visual Studio?

{% endraw %}
