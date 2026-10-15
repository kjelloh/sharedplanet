# Todo: Programming - Consider to understand and document how to create and distribute a chocolatey package using tree command tool as working example)?

```#3f3b7f08``` *As of 2016-07-15 18:34*

[mail plain/text](mail.txt)

{% raw %}
Consider to document how to create and distribute a chocolatey package using the tree command line tool as a working example?

-1) NOTE ==&gt; The tree command now seems to be available in windows 10 (<https://technet.microsoft.com/en-us/library/cc771130(v=ws.11).aspx)?>

==&gt; At least, I am able to do tree in any command windows?!!

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree&gt;tree /f  
> Folder PATH listing  
> Volume serial number is D49B-BB89  
> C:.  
> │ tree.0.1.nupkg  
> │ tree.nuspec  
> │  
> └───tools  
> ReadMe.md  
> tree.exe

C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree&gt;

**WE ARE HERE...  
**

1) So, how do we create a chocolate package in the first place?

==&gt; This seem to be a good article on creating chocolatey package (<https://puppet.com/blog/chocolatey-creating-your-own-chocolatey-packages>)?

==&gt; And chocolatey seem to publish their own official documentation on gihub (<https://github.com/chocolatey/choco/wiki/CreatePackages>)?

2) It seems we shall use choco new to create a package?

==&gt; This seems to be the result of the default choice new?

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install&gt;**..\\tree**  
> "C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install"  
> |---"build_package.bat"  
> |---"README.txt"

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install&gt;**choco new --force tree**  
> Creating a new package specification at C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree  
> Generating template to a file  
> at 'C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree\\tree.nuspec'  
> Generating template to a file  
> at 'C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree\\tools\\chocolateyinstall.ps1'  
> Generating template to a file  
> at 'C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree\\tools\\chocolateyuninstall.ps1'  
> Generating template to a file  
> at 'C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree\\tools\\ReadMe.md'  
> Successfully generated tree package specification files  
> at 'C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree'

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install&gt;**..\\tree**  
> "C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install"  
> |---"build_package.bat"  
> |---"README.txt"  
> |---"tree"  
> | |---"tools"  
> | | |---"chocolateyinstall.ps1"  
> | | |---"chocolateyuninstall.ps1"  
> | | |---"ReadMe.md"  
> | |---"tree.nuspec"

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install&gt;

==&gt; The configuration “C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree\\tree.nuspec” seem to contain:

> > &lt;?xml version="1.0" encoding="utf-8"?&gt;

> > &lt;!-- Do not remove this test for UTF-8: if “Ω” doesn’t appear as greek uppercase omega letter enclosed in quotation marks, you should use an editor that supports UTF-8, not this one. --&gt;

> > &lt;package xmlns="<http://schemas.microsoft.com/packaging/2015/06/nuspec.xsd>"&gt;

> > &lt;metadata&gt;

> > &lt;!-- Read this before publishing packages to [chocolatey.org](http://chocolatey.org): <https://github.com/chocolatey/chocolatey/wiki/CreatePackages> --&gt;

> > &lt;id&gt;tree&lt;/id&gt;

> > &lt;title&gt;tree (Install)&lt;/title&gt;

> > &lt;version&gt;__REPLACE__&lt;/version&gt;

> > &lt;authors&gt;__REPLACE_AUTHORS_OF_SOFTWARE_COMMA_SEPARATED__&lt;/authors&gt;

> > &lt;owners&gt;__REPLACE_YOUR_NAME__&lt;/owners&gt;

> > &lt;summary&gt;__REPLACE__&lt;/summary&gt;

> > &lt;description&gt;__REPLACE__MarkDown_Okay

> > &lt;/description&gt;

> > &lt;projectUrl&gt;&lt;/projectUrl&gt;

> > &lt;packageSourceUrl&gt;&lt;/packageSourceUrl&gt;

> > &lt;!--&lt;projectSourceUrl&gt;&lt;/projectSourceUrl&gt;

> > &lt;docsUrl&gt;&lt;/docsUrl&gt;

> > &lt;mailingListUrl&gt;&lt;/mailingListUrl&gt;

> > &lt;bugTrackerUrl&gt;&lt;/bugTrackerUrl&gt;--&gt;

> > &lt;tags&gt;tree admin SPACE_SEPARATED&lt;/tags&gt;

> > &lt;copyright&gt;&lt;/copyright&gt;

> > &lt;licenseUrl&gt;&lt;/licenseUrl&gt;

> > &lt;requireLicenseAcceptance&gt;false&lt;/requireLicenseAcceptance&gt;

> > &lt;!--&lt;iconUrl&gt;[http://cdn.rawgit.com/__REPLACE_YOUR_REPO__/master/icons/tree.png&lt;/iconUrl&gt;--&gt;](<http://cdn.rawgit.com/__REPLACE_YOUR_REPO__/master/icons/tree.png%3C/iconUrl%3E--%3E>)

> > &lt;!--&lt;dependencies&gt;

> > &lt;dependency id="" version="__VERSION__" /&gt;

> > &lt;dependency id="" /&gt;

> > &lt;/dependencies&gt;--&gt;

> > &lt;releaseNotes&gt;__REPLACE_OR_REMOVE__MarkDown_Okay&lt;/releaseNotes&gt;

> > &lt;!--&lt;provides&gt;&lt;/provides&gt;--&gt;

> > &lt;/metadata&gt;

> > &lt;files&gt;

> > &lt;file src="tools\\\*\*" target="tools" /&gt;

> > &lt;/files&gt;

> > &lt;/package&gt;

==&gt; This seem to be the result of creating an —auto package (a package that automatically updates itself)?

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install&gt;**..\\tree**  
> "C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install"  
> |---"build_package.bat"  
> |---"README.txt"

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install&gt;**choco new --auto --force tree**  
> Creating a new package specification at C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree  
> Generating template to a file  
> at 'C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree\\tree.nuspec'  
> Generating template to a file  
> at 'C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree\\tools\\chocolateyinstall.ps1'  
> Generating template to a file  
> at 'C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree\\tools\\chocolateyuninstall.ps1'  
> Generating template to a file  
> at 'C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree\\tools\\ReadMe.md'  
> Successfully generated tree (automatic) package specification files  
> at 'C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree'

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install&gt;**..\\tree**  
> "C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install"  
> |---"build_package.bat"  
> |---"README.txt"  
> |---"tree"  
> | |---"tools"  
> | | |---"chocolateyinstall.ps1"  
> | | |---"chocolateyuninstall.ps1"  
> | | |---"ReadMe.md"  
> | |---"tree.nuspec"

C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install&gt;

==&gt; The configuration “C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree\\tree.nuspec” seem to contain:

> > &lt;?xml version="1.0" encoding="utf-8"?&gt;

> > &lt;!-- Do not remove this test for UTF-8: if “Ω” doesn’t appear as greek uppercase omega letter enclosed in quotation marks, you should use an editor that supports UTF-8, not this one. --&gt;

> > &lt;package xmlns="<http://schemas.microsoft.com/packaging/2015/06/nuspec.xsd>"&gt;

> > &lt;metadata&gt;

> > &lt;!-- Read this before publishing packages to [chocolatey.org](http://chocolatey.org): <https://github.com/chocolatey/chocolatey/wiki/CreatePackages> --&gt;

> > &lt;id&gt;tree&lt;/id&gt;

> > &lt;title&gt;tree (Install)&lt;/title&gt;

> > &lt;version&gt;{{PackageVersion}}&lt;/version&gt;

> > &lt;authors&gt;__REPLACE_AUTHORS_OF_SOFTWARE_COMMA_SEPARATED__&lt;/authors&gt;

> > &lt;owners&gt;__REPLACE_YOUR_NAME__&lt;/owners&gt;

> > &lt;summary&gt;__REPLACE__&lt;/summary&gt;

> > &lt;description&gt;__REPLACE__MarkDown_Okay

> > \*\*Please Note\*\*: This is an automatically updated package. If you find it is

> > out of date by more than a day or two, please contact the maintainer(s) and

> > let them know the package is no longer updating correctly.

> > &lt;/description&gt;

> > &lt;projectUrl&gt;&lt;/projectUrl&gt;

> > &lt;packageSourceUrl&gt;&lt;/packageSourceUrl&gt;

> > &lt;!--&lt;projectSourceUrl&gt;&lt;/projectSourceUrl&gt;

> > &lt;docsUrl&gt;&lt;/docsUrl&gt;

> > &lt;mailingListUrl&gt;&lt;/mailingListUrl&gt;

> > &lt;bugTrackerUrl&gt;&lt;/bugTrackerUrl&gt;--&gt;

> > &lt;tags&gt;tree admin SPACE_SEPARATED&lt;/tags&gt;

> > &lt;copyright&gt;&lt;/copyright&gt;

> > &lt;licenseUrl&gt;&lt;/licenseUrl&gt;

> > &lt;requireLicenseAcceptance&gt;false&lt;/requireLicenseAcceptance&gt;

> > &lt;!--&lt;iconUrl&gt;[http://cdn.rawgit.com/__REPLACE_YOUR_REPO__/master/icons/tree.png&lt;/iconUrl&gt;--&gt;](<http://cdn.rawgit.com/__REPLACE_YOUR_REPO__/master/icons/tree.png%3C/iconUrl%3E--%3E>)

> > &lt;!--&lt;dependencies&gt;

> > &lt;dependency id="" version="__VERSION__" /&gt;

> > &lt;dependency id="" /&gt;

> > &lt;/dependencies&gt;--&gt;

> > &lt;releaseNotes&gt;__REPLACE_OR_REMOVE__MarkDown_Okay&lt;/releaseNotes&gt;

> > &lt;!--&lt;provides&gt;&lt;/provides&gt;--&gt;

> > &lt;/metadata&gt;

> > &lt;files&gt;

> > &lt;file src="tools\\\*\*" target="tools" /&gt;

> > &lt;/files&gt;

> > &lt;/package&gt;

2) These seem to be the options for **choco new** command used to create an initial package folder, files and content?

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\chocolatey&gt;**choco new --help**  
> New Command

> Chocolatey will generate package specification files for a new package.

> Usage

> choco new &lt;name&gt; &#91;&lt;options/switches&gt;&#93; &#91;&lt;property=value&gt; &lt;propertyN=valueN&gt;&#93;

> Possible properties to pass:  
> packageversion  
> maintainername  
> maintainerrepo  
> installertype  
> url  
> url64  
> silentargs

> Examples

> choco new bob  
> choco new bob -a --version 1.2.0 maintainername="This guy"  
> choco new bob silentargs="/S" url="<https://somewhere/out/there.msi>"

> Options and Switches

> -?, --help, -h  
> Prints out the help menu.

> -d, --debug  
> Debug - Run in Debug Mode.

> -v, --verbose  
> Verbose - See verbose messaging.

> --acceptlicense, --accept-license  
> AcceptLicense - Accept license dialogs automatically.

> -y, --yes, --confirm  
> Confirm all prompts - Chooses affirmative answer instead of prompting.  
> Implies --accept-license

> -f, --force  
> Force - force the behavior

> --noop, --whatif, --what-if  
> NoOp - Don't actually do anything.

> -r, --limitoutput, --limit-output  
> LimitOutput - Limit the output to essential information

> --execution-timeout=VALUE  
> CommandExecutionTimeoutSeconds - Override the default execution timeout  
> in the configuration of 2700 seconds.

> -c, --cache, --cachelocation, --cache-location=VALUE  
> CacheLocation - Location for download cache, defaults to %TEMP% or value  
> in chocolatey.config file.

> --allowunofficial, --allow-unofficial, --allowunofficialbuild, --allow-unofficial-build  
> AllowUnofficialBuild - When not using the official build you must set  
> this flag for choco to continue.

> -a, --auto, --automaticpackage  
> AutomaticPackage - Generate automatic package instead of normal.  
> Defaults to false

> -t, --template, --template-name=VALUE  
> TemplateName - Use a named template in  
> C:\\ProgramData\\chocolatey\\templates\\templatename instead of built-in  
> template.

> --name=VALUE  
> Name &#91;Required&#93;- the name of the package. Can be passed as first  
> parameter without "--name=".

> --version=VALUE  
> Version - the version of the package. Can also be passed as the property  
> PackageVersion=somevalue

> --maintainer=VALUE  
> Maintainer - the name of the maintainer. Can also be passed as the  
> property MaintainerName=somevalue

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\chocolatey&gt;

==&gt; It seems one creates the actual package with the command **choco pack** with current directory set to package root directory?

==&gt; It seems a chocolatey package must have a minimum set of configuration variables set to allo choco pack?

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install&gt;**cd tree**  
> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree&gt;**choco pack**  
> LicenseUrl cannot be empty.  
> ProjectUrl cannot be empty.  
> PackageSourceUrl cannot be empty.

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree&gt;

==&gt; Edited configuration file to provide the missing values

> > &lt;projectUrl&gt;[https://github.com/kjelloh/tree&lt;/projectUrl&gt;](https://github.com/kjelloh/tree%3C/projectUrl%3E)

> > &lt;packageSourceUrl&gt;[https://github.com/kjelloh/tree/tree/master/build&lt;/packageSourceUrl&gt;](<https://github.com/kjelloh/tree/tree/master/build%3C/packageSourceUrl%3E>)

> > &lt;licenseUrl&gt;[https://github.com/kjelloh/tree/blob/master/LICENSE&lt;/licenseUrl&gt;](<https://github.com/kjelloh/tree/blob/master/LICENSE%3C/licenseUrl%3E>)

==&gt; It also seems i need to fill in all configuration values marked as _REPLACE_?

==&gt; I edited the configuration file until the pack command succeeded.

3) This seems to be the options for **choco pack** command to create the actual package from the content of the package folder?

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree&gt;choco pack --help  
> Pack Command

> Chocolatey will attempt to package a nuspec into a compiled nupkg. Some  
> may prefer to use \`cpack\` as a shortcut for \`choco pack\`.

> NOTE: \`cpack\` has been deprecated as it has a name collision with CMake. Please  
> use \`choco pack\` instead. The shortcut will be removed in v1.

> Usage

> choco pack &#91;&lt;path to nuspec&gt;&#93; &#91;&lt;options/switches&gt;&#93;  
> cpack &#91;&lt;path to nuspec&gt;&#93; &#91;&lt;options/switches&gt;&#93; (DEPRECATED)

> Examples

> choco pack  
> choco pack --version 1.2.3  
> choco pack path/to/nuspec

> Options and Switches

> -?, --help, -h  
> Prints out the help menu.

> -d, --debug  
> Debug - Run in Debug Mode.

> -v, --verbose  
> Verbose - See verbose messaging.

> --acceptlicense, --accept-license  
> AcceptLicense - Accept license dialogs automatically.

> -y, --yes, --confirm  
> Confirm all prompts - Chooses affirmative answer instead of prompting.  
> Implies --accept-license

> -f, --force  
> Force - force the behavior

> --noop, --whatif, --what-if  
> NoOp - Don't actually do anything.

> -r, --limitoutput, --limit-output  
> LimitOutput - Limit the output to essential information

> --execution-timeout=VALUE  
> CommandExecutionTimeoutSeconds - Override the default execution timeout  
> in the configuration of 2700 seconds.

> -c, --cache, --cachelocation, --cache-location=VALUE  
> CacheLocation - Location for download cache, defaults to %TEMP% or value  
> in chocolatey.config file.

> --allowunofficial, --allow-unofficial, --allowunofficialbuild, --allow-unofficial-build  
> AllowUnofficialBuild - When not using the official build you must set  
> this flag for choco to continue.

> --version=VALUE  
> Version - The version you would like to insert into the package.

> C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree&gt;

4) It seems by placing the exe-file in the package &lt;tools&gt; filed (where the package scrips are) then choco pack will bundle the exe within the package?

==&gt; But then it installs the package to “C:\\ProgramData\\Chocolatey\\bin” (strange)?

==&gt; Thouch both choco install and choco uninstall of “C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree\\tree.0.1.nupkg” now works!

==&gt; It works with the exe-file in the package folder structure (and scrips removed to not be executadet at install)

> > C:\\Users\\kjell-olovhogdahl\\Documents\\GitHub\\tree\\install\\tree&gt;tree /f

> > Folder PATH listing

> > Volume serial number is D49B-BB89

> > C:.

> > │ tree.0.1.nupkg

> > │ tree.nuspec

> > │

> > └───tools

> > ReadMe.md

> > tree.exe

**==&gt; Q: But - How do we provide a location in program files for the installed exe?**

**WE ARE HERE...**

{% endraw %}
