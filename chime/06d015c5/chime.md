# Todo: Consider to check out the GeoTIFF format and C/C++ Open Source Projects for Public Domain Satellite imaging?

```#06d015c5``` *As of 2017-05-03 13:39*

[mail plain/text](mail.txt)

{% raw %}
It seems from an OpenVis talk ”Our Planet Seen from Space - Christine Waigl” that satellite images are publicaly available to download and use in the GeoTIFF format and Open Source GDAL can be used to process such information?

1) The talk ”Our Planet Seen from Space - Christine Waigl” seems to live here (<https://www.youtube.com/watch?v=XW9kPCOfEbQ&list=PLlgxAbM67lYKz_NssZ1DdDwIRIWbkDlN-&index=20>)?

==&gt; At 08:15 she discusses data and tools available to visualize the earth from space.

==&gt; !t 10:45 she states that Landsat imagery is the easiest to acquire and use.

==&gt; It is in GeoTIFF, Public Domain, covers the whole earth in 30 m square resolution.

==&gt; At 11:30 she talks about gaining data from Data Portals.

==&gt; She seem to recommend <https://earthexplorer.usgs.gov> as the largest one (and being by scientists for scientists)?

==&gt; One creates an account using a e-mail address and will then be allowed to select and download datasets.

==&gt; At 13:35 she refers to the ESA Sentinel Data

==&gt; She states the data is in JPEG2000 (but also in GeoTIFF)?

==&gt; She refers to MODIS and VIIRS as tools to be able to do Global Mappings from this data?

==&gt; MODIS seems to stand for ”Moderate-resolution imaging spectroradiometer” (<https://en.wikipedia.org/wiki/Moderate-resolution_imaging_spectroradiometer>)?

==&gt; It seems to be an instrument launched into space on board several satellites in the past?

> > ”*The moderate-resolution imaging spectroradiometer (MODIS) is a payload scientific instrument built by Santa Barbara Remote Sensing&#91;1&#93; that was launched into Earth orbit by NASA in 1999 on board the Terra (EOS AM) Satellite, and in 2002 on board the Aqua (EOS PM) satellite.*"

==&gt; VIIRS seems to stand for ”Visible Infrared Imaging Radiometer Suite” (<https://en.wikipedia.org/wiki/Visible_Infrared_Imaging_Radiometer_Suite>)?

> > ”*The Visible Infrared Imaging Radiometer Suite (VIIRS) is a sensor designed and manufactured by the Raytheon Company on board the Suomi National Polar-orbiting Partnership (Suomi NPP) weather satellite.&#91;1&#93; VIIRS is one of five key instruments associated with the Suomi NPP that was launched on October 28, 2011.&#91;2&#93; VIIRS is a whiskbroom scanning radiometer&#91;3&#93; that collects imagery and radiometric measurements of the land, atmosphere, cryosphere, and oceans in the visible and infrared bands of the electromagnetic spectrum.*"

==&gt; She seems to state that MODIS and VIIRS produced data are in HDF4/HDF5 data formats?

==&gt; HDF4/HDF5 seems to stand for ”Hierarchical Data Format” (<https://en.wikipedia.org/wiki/Hierarchical_Data_Format>)?

==&gt; This seems to be the home of ESA Sentinel Online (<https://sentinel.esa.int/web/sentinel/home>)?

==&gt; This seem to be a Youtube clip on how to download ESA Sentinel data (<https://www.youtube.com/watch?v=AFXfh7zCBxY>)?

==&gt; This seems to be the Copernicus Open Access Hub (<https://scihub.copernicus.eu>)?

==&gt; This seems to be a blog with good leads into satellite imaging from free data (<http://blog.imagico.de/about/>)?

==&gt; At 16:15 she defines that when download of GeoTIFF one gets a TIFF file for each band and one file with the meta data (and one needs to parse and merge those files to generate a view)

==&gt; At 18:05 she lists a couple of C++ and Python tools and libraries to help process geo imagery.

==&gt; The GEOS C++ Project seems to live here (<https://trac.osgeo.org/geos/>)?

==&gt; The GDAL C/C++ Open Source for GeoTIFF processing seems to live here (<http://www.gdal.org>)?

==&gt; Pre-built binaries seem to be available for download here (<https://trac.osgeo.org/gdal/wiki/DownloadSource>)?

==&gt; Daily builds seems to be available here (<http://www.gdal.org/daily/>)?

==&gt; Source code in Subversion seems to be browsable here (<https://trac.osgeo.org/gdal/browser>)?

==&gt; GDAL seems to have a Github mirror here (<https://github.com/OSGeo/gdal>)?

==&gt; PROJ4 seems to live here (<http://proj4.org>)?

==&gt; She seems to state that GDAL provides command line tools that enables scripting to process files?

3) Consider to download and try to build just to see what I can learn from this?

==&gt; It seems to be cross platform and cross compiler enabled (<https://trac.osgeo.org/gdal/wiki/BuildHints>)?

==&gt; It seems to use Travis to build and test the different targets (<https://travis-ci.org/OSGeo/gdal> and <https://github.com/OSGeo/gdal>)?

==&gt; It seems to target Ubuntu, Mac OS and Windows (Visual Studio and MingGW)

==&gt; It seems to support Clang, GCC, MSVC (<https://trac.osgeo.org/gdal/wiki/SupportedCompilers>)?

4) This seems to be the Wikipedia on GeoTIFF (<https://en.wikipedia.org/wiki/GeoTIFF>)?

5) The GeoTIFF specification and organisation seems to live here (<https://trac.osgeo.org/geotiff/>)?

==&gt; And this seems to be the GeoTIFF version 1.0 specification (<http://web.archive.org/web/20160403164508/http://www.remotesensing.org/geotiff/spec/geotiffhome.html>)?

…

6) Consider to find some satellite images to download and play with using the GDAL library?

==&gt; Data and tools seems to be published here by the US Government ”U.S. Geological Survey” (<https://www.usgs.gov>)?

7) US Government Landsat programm seems to live here (<https://landsat.usgs.gov>)?

==&gt; And data seems to be available for download here (<https://earthexplorer.usgs.gov>)?

==&gt; This seems to be a service data mirrors free GIS data and provides links to data sources (<https://freegisdata.rtwilson.com>)?

8) Consider what Darwinet Model should be able to define to be able to share raw and processed satellite imagery data?

==&gt; Is it even usable to diff satellite data into Darwinte Deltas (or does data always change so it is better to just store data as immutable)?

...

…

Consider to delve into available satellite data and tools to process them to see what I can learn had for what I can use this kind of data?

{% endraw %}
