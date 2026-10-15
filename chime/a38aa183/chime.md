# Todo: Programming - Consider to learn and understand RAD Studio Firemonkey 3D Application Programming?

```#a38aa183``` *As of 2016-04-02 18:36*

[mail plain/text](mail.txt)

{% raw %}
So, what can we do with RAD Studio Firemonkey 3D user interface components?

1) Consider this to be a good start to learn the concepts and idioms (<http://docwiki.embarcadero.com/RADStudio/Seattle/en/Tutorial:_Creating_a_FireMonkey_3D_Application>)?

==&gt; See “V:\\workplace\\RAD_Studio\\MyFmxPandoraPlayground"

==&gt; First phase is “Creating the User Interface” (<http://docwiki.embarcadero.com/RADStudio/Seattle/en/Creating_the_User_Interface_(FireMonkey_3D_Tutorial))>

==&gt; When creating a 3D Multidevice Application the main form inherits from TForm3D.

class TMainForm : public TForm3D

==&gt; The example suggests adding a TCube and a TLight to the form thus indicating and object and a light is the basic building blocks?

==&gt; At this point the application with a default cube and a default light has already some interesting properties.

==&gt; When resizing the Form the member cube and light are scaled to fit the new size.

==&gt; The light seem to always be relative the cube (moving the light also moves the cube)?

==&gt; NO - It was just because i happened to place the cube as a child to the light object :)

==&gt; Running the application shows the cube but is has no visible structure (no sider or edges can be seen (it is all uniform red)

==&gt; The visible object (the cube) has rotate handles on each side and a corner handle for resizing.

==&gt; The rotate x,y,z are located at each z,y,z face.

==&gt; The resize handle has an x,y,z face for resizing that face (plane).

==&gt; Resizing applies to selected face (i.e. both with and height of each face can be resized).

==&gt; Objects textures seem to be added as invisible Fmx components?

==&gt; Adding a TTextureMaterialSource (as the example suggests) does not show the added components in the visual form?

==&gt; If copied a jpeg from the internet and saved to bitmap using Windows Paint (got an 1536 x 864 bitmap image)

==&gt; NOTE_ Later discovered we may load any image-format (jpeg, tiff, gif…)

==&gt; Set the “MaterialSource” property of one cube to the added TTextureMaterialSource object.

==&gt; Q: Why doe the added texture only cover 1/10:th of each corner of the cube (I mean, it is 1536x864 pixels)?

==&gt; Q: How can I make the selected texture scale to the surface of the cube?

==&gt; Q: What is the purpose of “WrapMode” (none of the modes fit, scale, wrap, stretch) seem to make the structure cover the cube surface?

==&gt; It seems if I load a jpeg image it w i l l wrap the whole cube (strange)?

==&gt; Seems we need a TLightMaterialSource to make lightening have any effect on the view of the object (make structure/texture visible)?

==&gt; Added TLightMaterialSource

==&gt; The design at this stage looked like this (two cubes and one light source)

![](MyFmxPandoraPlayground_design_1.tiff)

==&gt; And running it looks like this.

![](MyFmxPandoraPlayground_run_1.tiff)

==&gt; Second phase is “Creating a 2D Interface in a 3D Application” (<http://docwiki.embarcadero.com/RADStudio/Seattle/en/Creating_a_2D_Interface_in_a_3D_Application_(FireMonkey_3D_Tutorial))>

==&gt; Added a TLayer3D to the form.

==&gt; It seems any 2D fire monkey controls to be added to it?

==&gt; Adding a TButton as child to the TLayer3D object and setting its “Projection” to “Screen” seem to make it appear as if a normal 2D panel?

==&gt; The TTextLayer3D does not seem to allow multiple lines of text?

==&gt; To show Pandora View of Source Code we need a 2D Richtext Control on a TLayer3D?

==&gt; No, there seem to be no Richest component (we need to use a plain TMemo component)?

=&gt;= Also see (<https://forums.embarcadero.com/message.jspa?messageID=700498&tstart=0>)?

==&gt; The final application according to the example needed up like below.

![](MyFmxPandoraPlayground_run_2.tiff)

==&gt; Note that TMemo with source-code in the middle.

==&gt; Q: Can we make some visual concept images of Pandora C++ Soucre code view in this way (although TMemo does not allow text colouring)?

**WE ARE HERE...**

{% endraw %}
