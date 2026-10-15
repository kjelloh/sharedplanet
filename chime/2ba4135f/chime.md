# Todo: Programming - Consider to understand and try out c++ boost::mpi for Visual Studio and RAD Studio?

```#2ba4135f``` *As of 2015-12-07 23:47*

[mail plain/text](mail.txt)

{% raw %}
The c++ boost::mip is a helper framework for building multi-process applications with process-to-process messaging support. Consider to understand it and have it work in Visual Studio and RAD Studio?

1) The mpi_xx examples does not compile in Visual Studio 2015 (

2) Here is a lead describing how to build and install in Visual Studio 2012 to enable example compilation (<http://stackoverflow.com/questions/26147564/how-to-build-boost-mpi-for-ms-mpi-with-visual-studio-2012>)

Here is a full description on how to build `boost` mpi version 1.55 for `MS-MPI` using `Visual Studio 2012` on `Windows 7`.

- Get the `MS-MPI` Redistributable Package from <http://msdn.microsoft.com/en-us/library/bb524831%28v=vs.85%29.aspx> and install it in the standard location
- Extract the `boost` 1.55 sources
- Run `bootstrap.bat` in a `Visual Studio 2012` command prompt
-

  Add the following line to `build\\v2\\user-config.jam`

  using mpi ;

-

  Change the following lines in `build\\v2\\tools\\mpi.jam`

  Line 249: Change the value of `cluster_pack_path_relative` to the installation directory of `MS-MPI`. Like this: `local cluster_pack_path_native = "C:[\\\\Program](smb://Program) Files\\\\Microsoft MPI" ;`

  Line 251: Change ...`[\\\\Include](smb://Include) : mpi.h` to ...`[\\\\Inc](smb://Inc) : mpi.h`

  Line 260: Change ...`/Include` to ...`/Inc`

- Run `bjam.exe --with-mpi --toolchain=msvc-11.0` This Should compile now

To create a Visual Studio solution that builds the `boost mpi` example, the newly built `boost mpi`and `serialization` libraries have to be added to the solution as well as the `msmpi.lib` from the `MS-MPI` installation path.

3) RAD Studio comes with boost 1.55. Could it be that boost::mpi works out-of-the-box in RAD Studio?

==&gt; No. It does not (“unable to include mpi.h”)

==&gt; Seems we need to install the microsoft MS-MPI

&lt;fix&gt;

==&gt; Install MS-MPI SDK as described below.

==&gt; Set include search path to “C:\\Program Files (x86)\\Microsoft SDKs\\MPI\\Include” (default install path of SDK include)

4) Note that one needs a helper program to actually launch the built mip-application on-mass (e.g. using microsoft mpiexec.exe in their MS-MPI package)

5) The MS-MPI seem to be described here (<https://msdn.microsoft.com/en-us/library/bb524831(v=vs.85).aspx)?>

==&gt; “Stand-alone, redistributable and SDK installers for Microsoft MPI. “ (<https://www.microsoft.com/en-us/download/details.aspx?id=49926>)

==&gt; NOTE: Don’t forget to download and run also the msmpisdk.msi!

“Windows 10, Windows 8.1, Windows 8, Windows 7, Windows Vista, Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2, Windows Server 2008”

“To install on a workstation computer:

-  • Run MSMpiSetup.exe or msmpisdk.msi.
-  • Follow the steps in the installation wizard.

For redistribution:
-  You must include the entire installation package in your installation media.
-  Your setup program can run the installation package to install MS-MPI, but you may not redistribute any of the individual files separately in your own installer.
-  Please refer to the license agreement for additional information.”

==&gt; The SDK is installed to “C:\\Program Files (x86)\\Microsoft SDKs\\MPI\\”

6) This thread seem to describe how to use MS-MPI without boost (<https://social.microsoft.com/Forums/en-US/e8dd5f2c-5705-4638-881e-bb15514fe33f/link-mpih-to-devc?forum=windowshpcmpi>)

7) After actions above the Visual Studio and RAD Studio fails to link for similar reasons

==&gt; Visual Studion 2015 fails “cannot open file 'libboost_mpi-vc140-mt-gd-1_59.lib’”

==&gt; RAD Studio fails “Unable to open file 'LIBBOOST_MPI-BCB64-MT-SD-1_55.A’"

==&gt; Seems a path to a linkable “library” is missing in both cases?

==&gt; Turns out the distribution installed for Visual Studio does not have this file in “C:\\local\\boost_1_59_0\\lib64-msvc-14.0” (Not built as part of this distribution?).

...

…

Consider to delve into this matter to see if we can get boost::mpi processes up and running in windows?

a) e.g. to try out Darwinet node-to-node messaging?

...

{% endraw %}
