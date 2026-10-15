# Todo: Consider to try to build Freecad 1.1.3 20260807

```#3276d074``` *As of 2026-08-07 17:55*

[mail plain/text](mail.txt)

{% raw %}
So maybe it is time to see if I can make Freecad build on macOS Apple Silicon?

1) It seems Freecad still lives on Github (<https://github.com/freecad/freecad> )?

==&gt; It seems cloning the repo works just fine?

> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub % git clone git@github.com:FreeCAD/FreeCAD.git  
> Cloning into 'FreeCAD'...  
> remote: Enumerating objects: 610640, done.  
> remote: Counting objects: 100% (213/213), done.  
> remote: Compressing objects: 100% (124/124), done.  
> remote: Total 610640 (delta 140), reused 89 (delta 89), pack-reused 610427 (from 4)  
> Receiving objects: 100% (610640/610640), 2.59 GiB | 7.61 MiB/s, done.  
> Resolving deltas: 100% (522808/522808), done.  
> Updating files: 100% (13115/13115), done.  
> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub %

2) The documentation now seems to recommend using 'pixi' (<https://freecad.github.io/DevelopersHandbook/gettingstarted/> )?

==&gt; It seems Pixi installs just fine from direct download and shell execute?



> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub % **curl -fsSL https://pixi.sh/install.sh | bash**  
> This script will automatically download and install Pixi (latest) for you.  
> Getting it from this url: https://github.com/prefix-dev/pixi/releases/latest/download/pixi-aarch64-apple-darwin.tar.gz  
> % Total % Received % Xferd Average Speed Time Time Time Current  
> Dload Upload Total Spent Left Speed  
> 0 0 0 0 0 0 0 0 --:--:-- --:--:-- --:--:-- 0  
> 0 0 0 0 0 0 0 0 --:--:-- --:--:-- --:--:-- 0  
> 100 27.3M 100 27.3M 0 0 6067k 0 0:00:04 0:00:04 --:--:-- 7501k  
> The 'pixi' binary is installed into '/Users/kjell-olovhogdahl/.pixi/bin'  
> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub %

==&gt; It seems pixi installs to a hidden folder in my user folder?

> The 'pixi' binary is installed into '/Users/kjell-olovhogdahl/.pixi/bin'

==&gt; It seems 'pixi run configure' works just fine in the freecad repo folder?

> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/FreeCAD % pixi run configure  
> ✨ **Pixi task (****initialize****): ****git submodule update --init --recursive**  
> WARN Skipped running the post-link scripts because \`**run-post-link-scripts**\` = \`false\`  
> - bin/.librsvg-pre-unlink.sh

> To enable them, run:  
> pixi config set --local run-post-link-scripts insecure

> More info:  
> https://pixi.sh/latest/reference/pixi_configuration/#run-post-link-scripts

> Submodule 'src/3rdParty/GSL' (https://github.com/microsoft/GSL) registered for path 'src/3rdParty/GSL'  
> Submodule 'src/3rdParty/OndselSolver' (https://github.com/FreeCAD/OndselSolver.git) registered for path 'src/3rdParty/OndselSolver'  
> Submodule 'src/3rdParty/coin' (https://github.com/FreeCAD/coin.git) registered for path 'src/3rdParty/coin'  
> Submodule 'src/3rdParty/pivy' (https://github.com/FreeCAD/pivy.git) registered for path 'src/3rdParty/pivy'  
> Submodule 'src/Mod/AddonManager' (https://github.com/FreeCAD/AddonManager.git) registered for path 'src/Mod/AddonManager'  
> Cloning into '/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/GSL'...  
> Cloning into '/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/OndselSolver'...  
> Cloning into '/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/coin'...  
> Cloning into '/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy'...  
> Cloning into '/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/Mod/AddonManager'...  
> Submodule path 'src/3rdParty/GSL': checked out '543d0dd3fe966ddf20e884b44e5fdbf12cb43784'  
> Submodule path 'src/3rdParty/OndselSolver': checked out '3afcb30353084d402e3c34760cd662cf22d88759'  
> Submodule path 'src/3rdParty/coin': checked out 'a9e04146606f5e922ab0364a36f28e4b083b4a93'  
> Submodule 'cpack.d' (https://github.com/coin3d/cpack.d) registered for path 'src/3rdParty/coin/cpack.d'  
> Submodule 'docs/doxygen-awesome' (https://github.com/coin3d/doxygen-awesome-css.git) registered for path 'src/3rdParty/coin/docs/doxygen-awesome'  
> Cloning into '/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/coin/cpack.d'...  
> Cloning into '/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/coin/docs/doxygen-awesome'...  
> Submodule path 'src/3rdParty/coin/cpack.d': checked out '118ac5a21bcf57f0f90e2b0e681c9dcbf07074c2'  
> Submodule path 'src/3rdParty/coin/docs/doxygen-awesome': checked out '6217657eef6aec24a0e4ecea4695031c1a622cf3'  
> Submodule path 'src/3rdParty/pivy': checked out 'c42d938aec005efda5f0ff114298d7ecb0a494b8'  
> Submodule path 'src/Mod/AddonManager': checked out '537abae661db20b9ccde72e9caba53cef322f340'

> ✨ **Pixi task (****configure-debug****): ****cmake --preset conda-macos-debug ""**  
> CMake Warning:  
> Ignoring empty string ("") provided on the command line.

> -- Using ccache found at: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/ccache  
> -- The C compiler identification is Clang 18.1.8  
> -- The CXX compiler identification is Clang 18.1.8  
> -- Detecting C compiler ABI info  
> -- Detecting C compiler ABI info - done  
> -- Check for working C compiler: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/arm64-apple-darwin20.0.0-clang - skipped  
> -- Detecting C compile features  
> -- Detecting C compile features - done  
> -- Detecting CXX compiler ABI info  
> -- Detecting CXX compiler ABI info - done  
> -- Check for working CXX compiler: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/arm64-apple-darwin20.0.0-clang++ - skipped  
> -- Detecting CXX compile features  
> -- Detecting CXX compile features - done  
> -- Compiler: Clang, version: 18.1.8  
> -- Check for STD namespace  
> -- Check for STD namespace - found  
> -- Force BOOST_PP_VARIADICS=1 for clang  
> -- prefix: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default  
> -- bindir: bin  
> -- datadir: share  
> -- docdir: share/doc/FreeCAD  
> -- includedir: include  
> -- libdir: lib  
> -- cmake: 4.2.3  
> -- Compiling with Qt 6  
> -- Found Doxygen: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/doxygen (found version "1.13.2") found components: doxygen dot  
> -- Found nlohmann_json: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/share/cmake/nlohmann_json/nlohmann_jsonConfig.cmake (found version "3.12.0")  
> -- Found ICU: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/include (found version "75.1") found components: uc i18n  
> -- Found Python3: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/python3.11 (found version "3.11.14") found components: Interpreter Development Development.Module Development.Embed  
> CMake Warning (dev) at .pixi/envs/default/share/pcl-1.15/Modules/FindFLANN.cmake:45 (find_package):  
> Policy CMP0144 is not set: find_package uses upper-case &lt;PACKAGENAME&gt;_ROOT  
> variables. Run "cmake --help-policy CMP0144" for policy details. Use the  
> cmake_policy command to set the policy and suppress this warning.

> CMake variable FLANN_ROOT is set to:

> /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default

> For compatibility, find_package is ignoring the variable, but code in a  
> .cmake module might still use it.  
> Call Stack (most recent call first):  
> .pixi/envs/default/share/pcl-1.15/PCLConfig.cmake:241 (find_package)  
> .pixi/envs/default/share/pcl-1.15/PCLConfig.cmake:286 (find_flann)  
> .pixi/envs/default/share/pcl-1.15/PCLConfig.cmake:558 (find_external_library)  
> cMake/FreeCAD_Helpers/SetupPCL.cmake:11 (find_package)  
> CMakeLists.txt:119 (SetupPCL)  
> This warning is for project developers. Use -Wno-dev to suppress it.

> -- Found flann version 1.9.2  
> -- Found OpenMP_CXX: -fopenmp=libomp (found version "5.1")  
> -- Found OpenMP: TRUE (found version "5.1") found components: CXX  
> -- Found Qhull version 8.0.2  
> -- Found Threads: TRUE  
> -- Found GLEW: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libGLEW.dylib  
> -- Found OpenGL: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework found components: OpenGL  
> -- Found utf8cpp: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/include  
> -- Found ZLIB: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libz.dylib (found version "1.3.1")  
> -- Found PNG: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libpng.dylib (found version "1.6.54")  
> -- Found OpenGL: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework  
> -- Found WrapOpenGL: TRUE  
> -- Found Eigen3: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/include/eigen3 (found version "3.4.0")  
> -- Found EXPAT: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libexpat.dylib (found version "2.7.3")  
> -- Found double-conversion: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libdouble-conversion.dylib  
> -- Found LZ4: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/liblz4.dylib (found version "1.10.0")  
> -- Could NOT find LZMA (missing: LZMA_INCLUDE_DIR)  
> -- Found JPEG: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libjpeg.dylib (found version "80")  
> -- Found TIFF: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libtiff.dylib (found version "4.7.1")  
> -- Could NOT find freetype (missing: freetype_DIR)  
> -- Found Freetype: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libfreetype.dylib (found version "2.14.1")  
> -- Found OpenGL: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework found components: OpenGL  
> -- Could NOT find LZMA (missing: LZMA_INCLUDE_DIR)  
> -- Could NOT find freetype (missing: freetype_DIR)  
> -- looking for PCL_COMMON  
> -- Found PCL_COMMON: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libpcl_common.dylib  
> -- looking for PCL_KDTREE  
> -- Found PCL_KDTREE: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libpcl_kdtree.dylib  
> -- looking for PCL_OCTREE  
> -- Found PCL_OCTREE: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libpcl_octree.dylib  
> -- looking for PCL_SEARCH  
> -- Found PCL_SEARCH: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libpcl_search.dylib  
> -- looking for PCL_2D  
> -- Found PCL_2D: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/include/pcl-1.15  
> -- looking for PCL_FEATURES  
> -- Found PCL_FEATURES: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libpcl_features.dylib  
> -- looking for PCL_SURFACE  
> -- Found PCL_SURFACE: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libpcl_surface.dylib  
> -- looking for PCL_IO_PLY  
> -- Found PCL_IO_PLY: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libpcl_io_ply.dylib  
> -- looking for PCL_IO  
> -- Found PCL_IO: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libpcl_io.dylib  
> -- looking for PCL_FILTERS  
> -- Found PCL_FILTERS: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libpcl_filters.dylib  
> -- looking for PCL_GEOMETRY  
> -- Found PCL_GEOMETRY: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/include/pcl-1.15  
> -- looking for PCL_ML  
> -- Found PCL_ML: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libpcl_ml.dylib  
> -- looking for PCL_SEGMENTATION  
> -- Found PCL_SEGMENTATION: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libpcl_segmentation.dylib  
> -- looking for PCL_SAMPLE_CONSENSUS  
> -- Found PCL_SAMPLE_CONSENSUS: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libpcl_sample_consensus.dylib  
> -- Found PCL: pcl_common;pcl_kdtree;pcl_octree;pcl_search;pcl_features;pcl_surface;pcl_io_ply;pcl_io;pcl_filters;pcl_ml;pcl_segmentation;pcl_sample_consensus;Boost::system;Boost::iostreams;Boost::filesystem;Boost::serialization;VTK::ChartsCore;VTK::CommonColor;VTK::CommonComputationalGeometry;VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::CommonMath;VTK::CommonMisc;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersExtraction;VTK::FiltersGeneral;VTK::FiltersGeometry;VTK::FiltersModeling;VTK::FiltersSources;VTK::ImagingCore;VTK::ImagingSources;VTK::InteractionImage;VTK::InteractionStyle;VTK::InteractionWidgets;VTK::IOCore;VTK::IOGeometry;VTK::IOImage;VTK::IOLegacy;VTK::IOPLY;VTK::RenderingAnnotation;VTK::RenderingCore;VTK::RenderingContext2D;VTK::RenderingLOD;VTK::RenderingFreeType;VTK::ViewsCore;VTK::ViewsContext2D;VTK::RenderingOpenGL2;VTK::RenderingContextOpenGL2;VTK::GUISupportQt;FLANN::FLANN;QHULL::QHULL  
> -- Found pybind11: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/include (found version "3.0.1")  
> -- Found XercesC: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libxerces-c.dylib (found version "3.3.0")  
> -- PyCXX found:  
> -- Headers: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/PyCXX  
> -- Sources: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/PyCXX/CXX  
> -- Version: 7.1.11  
> -- Found OCC: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/include/opencascade (found version "7.8.1")  
> -- Found OpenCASCADE version: 7.8.1 (dev)  
> -- OpenCASCADE include directory: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/include/opencascade  
> -- OpenCASCADE shared libraries directory: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib  
> -- Found OpenGL: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework  
> -- Found OpenGLU: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework  
> -- VTK components: CommonCore;CommonDataModel;FiltersVerdict;IOXML;FiltersCore;FiltersGeneral;IOLegacy;FiltersExtraction;FiltersSources;FiltersGeometry;WrappingPythonCore;hdf5;FiltersParallelDIY2;RenderingCore;InteractionStyle;RenderingFreeType;RenderingOpenGL2  
> -- Found Python3: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/python3.11 (found suitable version "3.11.14", minimum required is "3.11") found components: Interpreter Development.Module Development.Embed  
> -- Found OpenGL: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework found components: OpenGL  
> -- Found HDF5: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libhdf5.dylib;/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libcrypto.dylib;/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libcurl.dylib;/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/lib/libpthread.tbd;/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libsz.dylib;/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libz.dylib;/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/lib/libdl.tbd;/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/lib/libm.tbd (found version "1.14.3") found components: C HL  
> -- Could NOT find LZMA (missing: LZMA_INCLUDE_DIR)  
> -- Could NOT find freetype (missing: freetype_DIR)  
> -- VTK python wrapper: available  
> -- Skipping SWIG/Pivy runtime compatibility check for bundled Pivy  
> -- swig binary version building bundled pivy: 4.3.1  
> -- Found Eigen3: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/include/eigen3 (found suitable version "3.4.0", minimum required is "3.4.0")  
> -- Found Cups: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/lib/libcups.tbd (found version "2.3.4")  
> -- Set up to compile with Qt 6.8.3  
> -- Bundled Coin will use system Expat 2.7.3  
> -- Setting C++ standard: '20', which is the minimum needed to compile Coin.  
> -- Found OpenGL: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework  
> -- Using system Expat  
> --  
> -- OpenGL::GL;Threads::Threads;EXPAT::EXPAT;Freetype::Freetype  
> -- Found SWIG: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/swig4.0 (found suitable version "4.3.1", minimum required is "4.0.0")  
> -- Found Python: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/python3.11 (found version "3.11.14") found components: Interpreter Development Development.Module Development.Embed  
> -- Python_FOUND: TRUE  
> -- PIVY_PACKAGE_INSTALL_DIR: Mod/pivy  
> -- COIN_FOUND: TRUE  
> -- COIN_INCLUDE_DIR: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/coin/include  
> -- COIN_LIB_DIR: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/lib  
> -- COIN_VERSION: 4.0.10  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbMatrix.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbVec4f.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SoSceneManager.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SoOffscreenRenderer.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbViewportRegion.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbVec2d.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbXfBox3f.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbBox2d.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbName.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbVec3d.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbPlane.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbColor.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SoRenderManager.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbViewVolume.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbTime.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SoInput.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbVec3s.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbVec4d.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbBox3s.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbString.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbVec2s.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SoFullPath.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbBox2s.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbRotation.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SoNodeKitPath.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SoType.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbBox2f.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbVec2f.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbDPMatrix.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbDict.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbImage.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbBox3f.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SoPath.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbDPRotation.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbColor4f.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbVec3f.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/SbDPPlane.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/misc/SoBase.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/sensors/SoAlarmSensor.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/sensors/SoDelayQueueSensor.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/sensors/SoNodeSensor.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/sensors/SoFieldSensor.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/sensors/SoSensorManager.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/sensors/SoIdleSensor.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/sensors/SoSensor.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/sensors/SoPathSensor.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/sensors/SoTimerQueueSensor.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/sensors/SoOneShotSensor.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/sensors/SoTimerSensor.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/sensors/SoDataSensor.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/scxml/ScXMLStateMachine.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/lists/SoTypeList.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/lists/SoActionMethodList.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/lists/SoDetailList.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/lists/SoEngineOutputList.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/lists/SbVec3fList.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/lists/SoPathList.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/lists/SoBaseList.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/lists/SbIntList.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/lists/SoFieldList.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/lists/SoPickedPointList.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/lists/SbPList.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/lists/SbStringList.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/lists/SoNodeList.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/lists/SoEngineList.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/nodes/SoCallback.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/nodes/SoGroup.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/nodes/SoMarkerSet.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/nodes/SoEventCallback.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/nodes/SoSelection.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/elements/SoDiffuseColorElement.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/elements/SoLazyElement.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/engines/SoEngine.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/draggers/SoDragger.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/actions/SoGLRenderAction.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/actions/SoCallbackAction.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFMatrix.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFVec2f.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFUInt32.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoFieldContainer.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFUInt32.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFVec3f.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFInt32.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFRotation.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFRotation.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFMatrix.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMField.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFInt32.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFEngine.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFVec3f.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFImage.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFVec2f.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFImage3.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFTrigger.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFEngine.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFEnum.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFNode.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFPath.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFUShort.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFString.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFName.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFShort.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFFloat.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFVec4f.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFString.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFColor.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFVec3d.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFPlane.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFBool.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFUShort.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFTime.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFName.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFPath.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFNode.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFVec4f.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFColor.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFEnum.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFPlane.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoField.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFFloat.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoSFTime.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFShort.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/fields/SoMFBool.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/nodekits/SoBaseKit.h  
> create swigified header: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/pivy/Inventor/collision/SoIntersectionDetectionAction.h  
> CMake Warning at src/3rdParty/pivy/CMakeLists.txt:180 (message):  
> stubgen is not available; Pivy .pyi stubs will not be generated

> -- Could NOT find Spnav (missing: SPNAV_LIBRARY SPNAV_INCLUDE_DIR)  
> -- Shiboken6Config: Using default python: .cpython-311-darwin  
> -- Found Python: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/python3.11 (found suitable version "3.11.14", minimum required is "3") found components: Interpreter Development Development.Module Development.Embed  
> -- PYTHON_LIMITED_LIBRARIES:  
> -- SHIBOKEN_PYTHON_INCLUDE_DIRS computed to value: '/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/include/python3.11'  
> -- SHIBOKEN_PYTHON_LIBRARIES computed to value: '-undefined dynamic_lookup'  
> -- libshiboken built for Release  
> -- PYTHON_CONFIG_SUFFIX: .cpython-311-darwin  
> -- libshiboken built for Release  
> -- Qt version: 6.8.3  
> -- PySide version: 6.8.3  
> -- PySide/Qt version check passed (6.8)  
> -- Found PYSIDE6 tools: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/qt6/uic, /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/qt6/rcc  
> -- PySide 6.8.3 Python module found at /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/python3.11/site-packages/PySide6.

> -- Found Matplotlib: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/python3.11/site-packages/matplotlib (found version "3.10.8")  
> -- FindLark: Using Python3_EXECUTABLE = /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/python3.11  
> -- Found LARK: 1.3.1 (found version "1.3.1")  
> -- Found Lark: version 1.3.1  
> WARNING: Package(s) not found: ifcopenshell  
> CMake Warning at cMake/FreeCadMacros.cmake:400 (message):  
> Could not find ifcopenshell Python package runtime dependency. IFC files  
> support disabled.  
> Call Stack (most recent call first):  
> CMakeLists.txt:157 (find_python_runtime_dep)

> -- Found pip-installed av in /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/python3.11/site-packages/av  
> -- Found pip-installed pillow in /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/python3.11/site-packages/pillow  
> -- Platform is 64-bit, set -D_OCC64  
> -- Using CMake 4.2.3  
> -- Found XercesC: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libxerces-c.dylib (found suitable version "3.3.0", minimum required is "3.2")  
> -- &#91;E57Format&#93; Revision ID: E57Format-3.3.0-arm64-Clang181  
> -- &#91;E57Format&#93; Building static library  
> -- &#91;E57Format&#93; Setting validation level to 1  
> -- &#91;E57Format&#93; Using ccache: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/ccache  
> -- &#91;E57Format&#93; Using clang-format: /opt/homebrew/bin/clang-format  
> -- &#91;E57Format&#93; CMake files install to /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/cmake/E57Format  
> -- &#91;OndselSolver&#93; Building shared library  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Base/TypePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Base/BaseClassPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Base/BoundBoxPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Base/CoordinateSystemPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Base/PersistencePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Base/VectorPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Base/MatrixPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Base/RotationPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Base/PlacementPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Base/AxisPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Base/UnitPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Base/QuantityPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Base/PrecisionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/ApplicationDirectoriesPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/DepEdgePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/DocumentPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/DocumentSettingsPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/DocumentObjectPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/ExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/ExtensionContainerPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/DocumentObjectExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/GroupExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/LinkBaseExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/DocumentObjectGroupPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/GeoFeaturePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/GeoFeatureGroupExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/SuppressibleExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/MetadataPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/OriginGroupExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/PartPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/StringHasherPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/StringIDPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/ComplexGeoDataPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/PropertyContainerPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/MaterialPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/App/MeasureManagerPy.cpp  
> -- Found PythonInterp: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/python3.11 (found version "3.11.14")  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Assembly/App/AssemblyObjectPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Assembly/App/AssemblyLinkPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Assembly/App/BomObjectPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Assembly/App/BomGroupPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Assembly/App/JointGroupPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Assembly/App/ViewGroupPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Assembly/App/SimulationGroupPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Assembly/App/SnapshotGroupPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Assembly/Gui/ViewProviderAssemblyPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Fem/App/FemMeshPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Fem/App/FemPostObjectPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Fem/App/FemPostPipelinePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Fem/App/FemPostFilterPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Fem/App/FemPostBranchFilterPy.cpp  
> -- Found OpenMP_C: -fopenmp=libomp (found suitable version "5.1", minimum required is "4.0")  
> -- Found OpenMP_CXX: -fopenmp=libomp (found suitable version "5.1", minimum required is "4.0")  
> -- Found OpenMP: TRUE (found suitable version "5.1", minimum required is "4.0")  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Fem/Gui/ViewProviderFemConstraintPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Fem/Gui/ViewProviderFemMeshPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Fem/Gui/ViewProviderFemPostPipelinePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Fem/Gui/ViewProviderFemPostFilterPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Fem/Gui/ViewProviderShapeExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Import/App/StepShapePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Material/App/Array2DPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Material/App/Array3DPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Material/App/MaterialFilterPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Material/App/MaterialFilterOptionsPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Material/App/MaterialLibraryPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Material/App/MaterialManagerPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Material/App/MaterialPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Material/App/ModelManagerPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Material/App/ModelPropertyPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Material/App/MaterialPropertyPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Material/App/ModelPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Material/App/UUIDsPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Material/Gui/MaterialTreeWidgetPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Mesh/App/EdgePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Mesh/App/FacetPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Mesh/App/MeshFeaturePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Mesh/App/MeshPointPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Mesh/App/MeshPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Mesh/Gui/ViewProviderMeshPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ArcPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ArcOfConicPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ArcOfCirclePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ArcOfParabolaPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/BodyBasePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ConicPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/CirclePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ArcOfEllipsePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/EllipsePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/HyperbolaPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ArcOfHyperbolaPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ParabolaPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/OffsetCurvePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/GeometryPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/GeometryExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/GeometryIntExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/GeometryStringExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/GeometryBoolExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/GeometryDoubleExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/GeometryCurvePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/BoundedCurvePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/TrimmedCurvePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/GeometrySurfacePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/LinePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/LineSegmentPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/PointPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/BezierCurvePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/BSplineCurvePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/PlanePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ConePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/CylinderPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/SpherePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ToroidPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/BezierSurfacePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/BSplineSurfacePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/OffsetSurfacePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/PlateSurfacePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/RectangularTrimmedSurfacePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/SurfaceOfExtrusionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/SurfaceOfRevolutionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/PartFeaturePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/AttachExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Part2DObjectPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/AttachEnginePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/TopoShapePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/TopoShapeCompoundPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/TopoShapeCompSolidPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/TopoShapeEdgePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/TopoShapeFacePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/TopoShapeShellPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/TopoShapeSolidPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/TopoShapeVertexPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/TopoShapeWirePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/BRepOffsetAPI_MakePipeShellPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/BRepOffsetAPI_MakeFillingPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/BRepFeat/MakePrismPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ChFi2d/ChFi2d_AnaFilletAlgoPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ChFi2d/ChFi2d_FilletAlgoPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ChFi2d/ChFi2d_ChamferAPIPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ChFi2d/ChFi2d_FilletAPIPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/ArcOfCircle2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/ArcOfConic2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/ArcOfEllipse2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/ArcOfHyperbola2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/ArcOfParabola2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/BezierCurve2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/BSplineCurve2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/Circle2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/Conic2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/Ellipse2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/Geometry2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/Hyperbola2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/Curve2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/Line2dSegmentPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/Line2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/OffsetCurve2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/Geom2d/Parabola2dPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/GeomPlate/BuildPlateSurfacePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/GeomPlate/CurveConstraintPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/GeomPlate/PointConstraintPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/HLRBRep/HLRBRep_AlgoPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/HLRBRep/HLRToShapePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/HLRBRep/HLRBRep_PolyAlgoPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/HLRBRep/PolyHLRToShapePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_RootPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_EdgePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_FacePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_ShapePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_ShellPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_SolidPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_WirePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_WireframePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_WireVertexPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_EdgeConnectPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_FaceConnectPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_FixSmallFacePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_FixSmallSolidPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_FreeBoundsPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_ShapeTolerancePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_SplitCommonVertexPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeFix/ShapeFix_SplitToolPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/App/ShapeUpgrade/UnifySameDomainPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Part/Gui/ViewProviderPartExtPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/PartDesign/App/BodyPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/PartDesign/App/FeaturePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/PartDesign/Gui/ViewProviderPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/CAM/App/CommandPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/CAM/App/PathPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/CAM/App/FeaturePathCompoundPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/CAM/App/AreaPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/CAM/App/FeatureAreaPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/CAM/App/VoronoiPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/CAM/App/VoronoiCellPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/CAM/App/VoronoiEdgePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/CAM/App/VoronoiVertexPy.cpp  
> -- area module (for Path Workbench) will be installed to: lib  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/CAM/PathSimulator/App/PathSimPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/CAM/PathSimulator/AppGL/CAMSimPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Points/App/PointsPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Robot/App/Robot6AxisPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Robot/App/TrajectoryPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Robot/App/WaypointPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Robot/App/RobotObjectPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Sketcher/App/SketchObjectSFPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Sketcher/App/SketchObjectPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Sketcher/App/SketchGeometryExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Sketcher/App/ExternalGeometryExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Sketcher/App/GeometryFacadePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Sketcher/App/ExternalGeometryFacadePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Sketcher/App/ConstraintPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Sketcher/App/SketchPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Sketcher/Gui/ViewProviderSketchGeometryExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Spreadsheet/App/SheetPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Spreadsheet/App/PropertySheetPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Spreadsheet/App/PropertyColumnWidthsPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Spreadsheet/App/PropertyRowHeightsPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Spreadsheet/Gui/ViewProviderSpreadsheetPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Surface/App/Blending/BlendPointPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Surface/App/Blending/BlendCurvePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Measure/App/MeasurementPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Measure/App/MeasureBasePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/Measure/Gui/QuickMeasurePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawHatchPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawViewPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawPagePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawViewPartPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawViewSymbolPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawTemplatePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawParametricTemplatePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawSVGTemplatePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawViewClipPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawViewDimensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawViewDimExtentPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawGeomHatchPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawViewCollectionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawProjGroupPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawProjGroupItemPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawViewAnnotationPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawLeaderLinePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawRichAnnoPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/GeomFormatPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/CenterLinePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/CosmeticEdgePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/CosmeticVertexPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawTilePy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawTileWeldPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawWeldSymbolPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/CosmeticExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Mod/TechDraw/App/DrawBrokenViewPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Gui/DocumentPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Gui/PythonWorkbenchPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Gui/ViewProviderPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Gui/ViewProviderDocumentObjectPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Gui/ViewProviderGeometryObjectPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Gui/ViewProviderExtensionPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Gui/WorkbenchPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Gui/Selection/SelectionObjectPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Gui/LinkViewPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Gui/ViewProviderLinkPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Gui/AxisOriginPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Gui/CommandPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Gui/EditableDatumLabelPy.cpp  
> -- /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/Gui/Navigation/NavigationStylePy.cpp  
> -- CMAKE_OSX_DEPLOYMENT_TARGET not set, using SDK version: 15.2  
> -- Building modern Swift .appex QuickLook extensions (macOS 15.0+)  
> -- Skipping legacy .qlgenerator (not needed for macOS 15.0+)  
> -- Modern QuickLook: Using macOS SDK: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX15.2.sdk  
> -- Modern Swift QuickLook Extensions Configuration:  
> -- Swift Compiler: /usr/bin/swiftc  
> -- Target Architecture: arm64  
> -- Deployment Target: 15.2  
> -- Thumbnail Bundle ID: org.freecad.FreeCAD.quicklook.thumbnail  
> -- Preview Bundle ID: org.freecad.FreeCAD.quicklook.preview  
> -- Extensions Directory: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/MacAppBundle/FreeCAD.app/Contents/PlugIns  
> -- Code Signing: Handled by official macos_sign_and_notarize.sh script  
> -- FreeCAD QuickLook Configuration Summary:  
> -- Generator: Ninja  
> -- Target Architecture: arm64  
> -- Deployment Target: 15.2  
> -- Target FreeCAD.app: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug/src/MacAppBundle/FreeCAD.app  
> -- Modern Extensions (.appex): ON  
> -- Legacy Generator (.qlgenerator): OFF  
> -- Code Signing: Handled by official src/Tools/macos_sign_and_notarize.sh script  
> -- Found GTest: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/cmake/GTest/GTestConfig.cmake (found version "1.17.0")

> ==============  
> System  
> ==============

> -- bindir: bin  
> -- BLAS: -undefined-  
> -- ccache: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/ccache  
> -- CMAKE_VERSION: 4.2.3  
> -- Compiler: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/arm64-apple-darwin20.0.0-clang++ (18.1.8)  
> -- datadir: share  
> -- docdir: share/doc/FreeCAD  
> -- includedir: include  
> -- libdir: lib  
> -- prefix: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default  
> -- Python: 3.11.14 &#91;/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/python3.11&#93; Suffix: &#91;.cpython-311-darwin&#93;

> ==============  
> Config  
> ==============

> -- BUILD_ADDONMGR: ON  
> -- BUILD_ASSEMBLY: ON  
> -- BUILD_BIM: ON  
> -- BUILD_CAM: ON  
> -- BUILD_DRAFT: ON  
> -- BUILD_FEM: ON  
> -- BUILD_GUI: ON  
> -- BUILD_HELP: ON  
> -- BUILD_IMPORT: ON  
> -- BUILD_INSPECTION: ON  
> -- BUILD_JTREADER: OFF  
> -- BUILD_MATERIAL: ON  
> -- BUILD_MATERIAL_EXTERNAL: OFF  
> -- BUILD_MEASURE: ON  
> -- BUILD_MESH: ON  
> -- BUILD_MESH_PART: ON  
> -- BUILD_OPENSCAD: ON  
> -- BUILD_PART: ON  
> -- BUILD_PART_DESIGN: ON  
> -- BUILD_PLOT: ON  
> -- BUILD_POINTS: ON  
> -- BUILD_REVERSEENGINEERING: ON  
> -- BUILD_ROBOT: ON  
> -- BUILD_SHOW: ON  
> -- BUILD_SKETCHER: ON  
> -- BUILD_SMESH: OFF  
> -- BUILD_SPREADSHEET: ON  
> -- BUILD_START: ON  
> -- BUILD_SURFACE: ON  
> -- BUILD_TECHDRAW: ON  
> -- BUILD_TEST: ON  
> -- BUILD_TUX: ON  
> -- BUILD_VR: OFF  
> -- BUILD_WEB: ON  
> -- CMAKE_BUILD_TYPE: Debug  
> -- CMAKE_CXX_FLAGS: -Wall -Wextra -Wpedantic -Wno-write-strings -fdiagnostics-color -Wno-undefined-var-template  
> -- CMAKE_CXX_STANDARD: 20  
> -- CMAKE_INSTALL_PREFIX: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default  
> -- CMAKE_PREFIX_PATH: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default  
> -- ENABLE_DEVELOPER_TESTS: ON  
> -- FREECAD_CREATE_MAC_APP: OFF  
> -- FREECAD_LIBPACK_USE: OFF  
> -- FREECAD_QT_VERSION: Auto  
> -- FREECAD_USE_EXTERNAL_KDL: OFF  
> -- FREECAD_USE_EXTERNAL_SMESH: ON  
> -- FREECAD_USE_FREETYPE: ON  
> -- FREECAD_USE_PYSIDE: ON  
> -- FREECAD_USE_SANITIZER_ASAN: OFF  
> -- FREECAD_USE_SANITIZER_LSAN: OFF  
> -- FREECAD_USE_SANITIZER_MSAN: OFF  
> -- FREECAD_USE_SANITIZER_TSAN: OFF  
> -- FREECAD_USE_SANITIZER_UBSAN: OFF  
> -- FREECAD_USE_SHIBOKEN: ON  
> -- Python3_EXECUTABLE: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/bin/python3.11  
> -- PYTHON_LIBRARY: -undefined-  
> -- USE_CUDA: -undefined-

> ==============  
> Libraries  
> ==============

> -- 3Dconnexion: Building with 3Dconnexion NavLib support  
> -- Boost: 1.86.0  
> -- Coin3D: 4.0.10 &#91;&#93; &#91;&#93;  
> -- Coin3D_DOC: not found  
> -- Coin3D_Expat: external (2.7.3)  
> -- Coin3D_Source: bundled  
> -- DesignerPlugin: not built (BUILD_DESIGNER_PLUGIN is OFF)  
> -- Doxygen: 1.13.2 Language: English  
> -- Eigen3: 3.4.0  
> -- fmt: 12.1.0  
> -- Freetype: 2.14.1  
> -- GTest: 1.17.0  
> -- ICU: 75.1  
> -- IfcOpenShell: not found  
> -- Lark: 1.3.1  
> -- Matplotlib: 3.10.8 PathDirs: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/python3.11/site-packages/matplotlib  
> -- NETGEN: not enabled  
> -- OCC: 7.8.1 (dev) &#91;/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib&#93; &#91;/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/include/opencascade&#93;  
> -- OCC_Libs: &#91;TKFillet;TKMesh;TKernel;TKG2d;TKG3d;TKMath;TKShHealing;TKXSBase;TKBool;TKBO;TKBRep;TKTopAlgo;TKGeomAlgo;TKGeomBase;TKOffset;TKPrim;TKHLR;TKFeat;TKDESTEP;TKDEIGES;TKDEGLTF;TKDESTL&#93;  
> -- OpenGL_Lib: &#91;/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework&#93;  
> -- OpenGLU_Incl: &#91;/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework&#93;  
> -- OpenGLU_Lib: &#91;/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework&#93;  
> -- PIL: 12.1.0  
> -- pivy: 0.6.11  
> -- pivy_Source: bundled  
> -- PyAV: 15.1.0  
> -- pybind11: 3.0.1  
> -- PYCXX: 7.1.11 Incl: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/PyCXX Src:/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/src/3rdParty/PyCXX/CXX  
> -- PySide: 6.8.3 &#91;/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/include/PySide6&#93;  
> -- PySideTools: v: 6 uic: &#91;/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/qt6/uic&#93; rcc: &#91;/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/qt6/rcc&#93;  
> -- QtConcurrent: 6.8.3  
> -- QtCore: 6.8.3  
> -- QtNetwork: 6.8.3  
> -- QtOpenGL: 6.8.3  
> -- QtOpenGLWidgets: 6.8.3  
> -- QtPrintSupport: 6.8.3  
> -- QtSvg: 6.8.3  
> -- QtTest: 6.8.3  
> -- QtUiTools: 6.8.3  
> -- QtWidgets: 6.8.3  
> -- QtXml: 6.8.3  
> -- Rift: not enabled (BUILD_VR)  
> -- Shiboken: 6.8.3 &#91;/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/include/shiboken6;/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/include/python3.11&#93;  
> -- SMESH: 9.8.0.2  
> -- SWIG: 4.3.1  
> -- Vtk: 9.3.1  
> -- XercesC: 3.3.0 &#91;/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/lib/libxerces-c.dylib&#93; &#91;/Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/.pixi/envs/default/include&#93;  
> -- yaml-cpp: 0.8.0  
> -- ZLIB: 1.3.1

> =================================================  
> Now run 'cmake --build /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug' to build FreeCAD  
> =================================================

> -- Configuring done (65.2s)  
> -- Generating done (2.5s)  
> -- Build files have been written to: /Users/kjell-olovhogdahl/Documents/GitHub/FreeCAD/build/debug  
> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/FreeCAD %

==&gt; It seems '' builds freecad just fine (with a lot of warnings in third party libraries though)?

## Attachments

- [pixi_run_build.rtf](pixi_run_build.rtf)

{% endraw %}
