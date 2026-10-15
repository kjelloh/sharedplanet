# Todo: Consider to check out Meshroom to use it for 3D scanning of objects (to be used in CAD and CAM)?

```#ab1006f4``` *As of 2018-09-23 12:39*

[mail plain/text](mail.txt)

{% raw %}
It seems Meshroom is an open source program that implements “Photogrammetry” to reconstruct points in 3D space from a set of 2D images of the object?

==&gt; Also see “Todo: Consider to design and build an automated 3D scanner using the open source Meshroom application?"

1) Consider this youtube video “How to 3D Photoscan Easy and Free!” that shows how to make a 3D mesh from an object photographed from a lot of angels (<https://youtu.be/k4NTf0hMjtY>)?

2) Meshroom seems to live here (<https://alicevision.github.io/#meshroom>)?

==&gt; It seems to be “based on” the Alice Vision Framework?

> “*Meshroom is a free, open-source 3D Reconstruction Software based on the AliceVision framework.*"

3) Consider to investigate what kind of accuracy we can get from Meshroom on a set of reasonable high resolution camera pictures?

==&gt; It seems Meshroom analyses the provided images to reverse engineer the camera position and angel of each image?

==&gt; It then uses tis information to locate pixels in the image in 3D space?

**Q: What accuracy of these pixel locations in 3D space can we accomplish (e.g., to be used for 3D scanning of objects to capture their dimensions)?**

...

4) Consider to study the tools provided by Alicevision - The team behind Meshroom (<https://alicevision.github.io/#>)?

==&gt; It seems Alice Vision is some form of “Framework”?

> AliceVision

> Photogrammetric Computer Vision Framework

> • 3D Reconstruction  
> • Photomodeling  
> • Camera Tracking

==&gt; Alice Vision seems to be about Camera Tracking and 3D reconstruction?

> “**AliceVision** is a Photogrammetric Computer Vision framework for **3D** **Reconstruction** **and** **Camera** **Tracking**."

==&gt; It seems to be some form of Open Source, EU funded and rooted in research made by several institutions in Europe?

==&gt; Alice Vision seems to be about “**Photogrammetry**” - reconstructing 3D information from 2D images?

> “Photography is the projection of a 3D scene onto a 2D plane, losing depth information. The goal of **photogrammetry** is to reverse this process."

==&gt; It seems to use two ways of 3D reconstruction - “Structure from motion” (SfM) and “Multi View Stereo” (MVS)?

> “*The dense modeling of the scene is the result yielded by chaining two computer vision-based pipelines:*

> *“**Structure-from-Motion**” (SfM) and “**Multi View Stereo**” (MVS).*"

…

5) Meshroom seems to live on Github (<https://github.com/alicevision/meshroom>)?

==&gt; It seems to build and run on **Windows** and **Linux**?

==&gt; But they also indicate that Meshroom may execute on OS X?

> “  
> You need to have [AliceVision](https://github.com/alicevision/AliceVision) installation in your PATH (and LD_LIBRARY_PATH on Linux/**macOS**).  
> "

==&gt; It seems to be licensed under Mozilla Public Licence version 2 (MPLv2) (<https://github.com/alicevision/meshroom/blob/develop/LICENSE-MPL2.md>)?

==&gt; It seems to be written in Python and QML?

==&gt; QML seems to be a “language” used by Qt to define user interfaces (<http://doc.qt.io/archives/qt-4.8/qdeclarativeintroduction.html>)?

> “**QML** is a declarative **language** designed to describe the **user interface** of a program: both what it looks like, and how it behaves. In QML, a user interface is specified as a tree of objects with properties."

…

…

Consider to delve deeper into MeshRoom to see if I can use it to 3D scan objects to get a sufficiently accurate 3D model for Computer Aided design (CAD) and manufacturing (CAM) purposes?

...

{% endraw %}
