# Todo: Programming - It seems C++ boost for Visual Studio is available using NuGet package manager?

```#ed3ed911``` *As of 2016-07-10 20:01*

[mail plain/text](mail.txt)

{% raw %}
It seems we may install the boost library into Visual Studio using the NuGet package manager?

1) The NuGet package seem to be defined here (<https://www.nuget.org/packages/boost/>)

==&gt; So, is this a reliable source for boost for Visual Studio?

2) It seems one must be very careful with where the package is installed?

==&gt; It seems if one opens the Package Manager console window it will default to the current open solution folder?

> PM&gt; Install-Package boost  
> Attempting to gather dependency information for package 'boost.1.61.0' with respect to project 'leaf_cpp_in', targeting 'native,Version=v0.0'  
> Attempting to resolve dependencies for package 'boost.1.61.0' with DependencyBehavior 'Lowest'  
> Resolving actions to install package 'boost.1.61.0'  
> Resolved actions to install package 'boost.1.61.0'  
> GET <https://api.nuget.org/packages/boost.1.61.0.nupkg>  
> OK <https://api.nuget.org/packages/boost.1.61.0.nupkg> 12ms  
> Installing boost 1.61.0.  
> Adding package 'boost.1.61.0' to folder 'V:\\workplace\\cross_platform\\leaf_cpp_in\\build\\leaf_cpp_in\\packages'  
> Added package 'boost.1.61.0' to folder 'V:\\workplace\\cross_platform\\leaf_cpp_in\\build\\leaf_cpp_in\\packages'  
> Added package 'boost.1.61.0' to 'packages.config'  
> Successfully installed 'boost 1.61.0' to leaf_cpp_in  
> PM&gt;

==&gt; This frankly **SUCKS**!!

==&gt; How can I install a NuGet package to some project and solution agnostic location (to be used by any Visual Studio project)?

…

3) Information about the NuGet package manager console seem to live here (<https://docs.nuget.org/consume/package-manager-console>)?

==&gt; It seems to explicitly specify that a package is always installed into a solution (WTF)?

“NuGet retrieves the package from the specified package source and installs it in the project that is selected in the Default project drop-down list (unless you specify a different project in the command). Files are copied to the solution, references might be added to the project, the project app.config or web.config file might be updated, etc. "

==&gt; Q: So how do I install a package that is part of the Visual Studio IDE?

…

Consider to study NuGet boost package for Visual Studio to see if I can make use of it or if I have to download a ore-build binary for Visual Studio?

...

{% endraw %}
