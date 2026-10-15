# Todo: Consider to understand how I may write plugins to automate Final Cut Pro X (FCPX) tasks more to my liking?

```#41a7aa9a``` *As of 2020-09-26 18:47*

[mail plain/text](mail.txt)

{% raw %}
I want a "programmable" (macro style controlled) video editor and maybe it would be possible to automate final cut pro?

-1) It seems I can develop on XCode without an Apple Developer Activated account?

==&gt; See <https://developer.apple.com/support/compare-memberships/>

> "*You can learn how to develop apps for Apple platforms for free without enrolling. With just an Apple ID, you can access Xcode, software downloads, documentation, sample code, forums, and Feedback Assistant, as well as test your apps on devices. If you don’t already have an Apple ID, you can create one here."*

> *"To distribute apps, join the Apple Developer Program.*"

1) Consider this Apple developer article "FxPlug" (<https://developer.apple.com/documentation/professional_video_applications/fxplug> )?

> *"...**use the FxPlug software development kit (SDK) to write your own custom visual effects. FxPlug is a compact, powerful image-processing plug-in architecture that lets you create unique, hardware-accelerated or CPU-based effects plug-ins with customized UI and onscreen controls.**"*

> *"...**FxPlug consists primarily of Objective-C protocol definitions. You create a plug-in by writing code in Objective-C, Objective-C++, or Swift that conforms to these protocols,**"*

> *"FxPlug 4 is required to use Metal rendering or Swift code."*

2) Consider the apple developer article "Setting Up for FxPlug Development" (<https://developer.apple.com/documentation/professional_video_applications/fxplug/setting_up_for_fxplug_development> )?

> *"**Plug-ins can be used in **Final Cut Pro and Motion**, referred to as the **host applications**.**"*

> *"...**in Final Cut Pro, however, you must **wrap plug-ins in a template**, as described in Preparing Plug-ins for Use in Final Cut Pro X.**" (*  
> [*https://developer.apple.com/documentation/professional_video_applications/fxplug/preparing_plug-ins_for_use_in_final_cut_pro_x](https://developer.apple.com/documentation/professional_video_applications/fxplug/preparing_plug-ins_for_use_in_final_cut_pro_x) )*

> *"Install Software*

> *Your system must have the following software installed:*

> *• Xcode 10 or newer  
> *  
> *• FxPlug 4 SDK (download from <https://developer.apple.com/download/more/?=FXPlug> )  
> *  
> *• Motion 5.4.4 or newer  
> *  
> *• Final Cut Pro X 10.4.7 or newer"*

3) Consider the apple developer article "Building an FxPlug Plug-in from an Xcode Template" (<https://developer.apple.com/documentation/professional_video_applications/fxplug/building_an_fxplug_plug-in_from_an_xcode_template> )?

> *"**When you run the FxPlug installation bundle, it makes an FxPlug Xcode template available in Xcode. The template's application bundle contains preconfigured interfaces, source code files, and a Metal renderer that you can use to create a basic filter plug-in for adjusting brightness with Swift or Objective-C. Once you have the brightness plug-in working, you can modify it to make your own plug-in that serves your specific needs.**"*

4) Consider this apple developer article "Content and Metadata Exchanges with Final Cut Pro" (<https://developer.apple.com/documentation/professional_video_applications/content_and_metadata_exchanges_with_final_cut_pro> )?

> *"**FCPXML is a specialized format that uses XML elements to describe the data going between your app and Final Cut Pro. With FCPXML simplifying the data exchange, app users can:*

> *• Send large quantities of media from an asset management tool to be edited in Final Cut Pro.  
> *  
> *• Send media clips—annotated with ratings, keywords, and metadata—and let Final Cut Pro organize the incoming media.  
> *  
> *• Receive rendered media and editing decisions for a project—including lists of media used—from Final Cut Pro for further processing, such as color grading and correction.  
> *  
> *• Receive rendered media (movies) in an app to finish and package for delivery, playout, or archiving.  
> *  
> *• Record an audio/video stream and start editing the media in Final Cut Pro while the file is still being recorded."*

5) Consider the FCPXML Format specification "About Final Cut Pro X XML 1.8" (<https://developer.apple.com/library/archive/documentation/FinalCutProX/Reference/FinalCutProXXMLFormat/Introduction/Introduction.html#//apple_ref/doc/uid/TP40011227> )?

> *"An FCPXML document represents one of the following Final Cut Pro X objects:*

> *• A single library.  
> *  
> *• A set of events.  
> *  
> *• A set of clips, which may contain keywords or smart collections."*

> The root top-level container element is `&lt;fcpxml&gt;`. The root element contains the following:
- An optional `&lt;import-options&gt;` element. See [Import Options](https://developer.apple.com/library/archive/documentation/FinalCutProX/Reference/FinalCutProXXMLFormat/EventsandProjects/EventsandProjects.html#//apple_ref/doc/uid/TP40011227-CH12-SW8).
- A `&lt;resources&gt;` element. See [Resources](https://developer.apple.com/library/archive/documentation/FinalCutProX/Reference/FinalCutProXXMLFormat/Resources/Resources.html#//apple_ref/doc/uid/TP40011227-CH16-SW1).
- One of the following:
  - A `&lt;library&gt;` element. A `&lt;library&gt;` element contains a list of `&lt;event&gt;` elements (see [Table 1-1](https://developer.apple.com/library/archive/documentation/FinalCutProX/Reference/FinalCutProXXMLFormat/EventsandProjects/EventsandProjects.html#//apple_ref/doc/uid/TP40011227-CH12-SW11)).  
>     Note: As of FCPXML 1.4, an FCPXML document is self-contained and allows multiple events, but does not allow references to objects in another library.

  - Or, a series of `&lt;event&gt;` elements. An `&lt;event&gt;` element contains story elements and `&lt;project&gt;` elements discussed in the following bullet (see [Table 1-1](https://developer.apple.com/library/archive/documentation/FinalCutProX/Reference/FinalCutProXXMLFormat/EventsandProjects/EventsandProjects.html#//apple_ref/doc/uid/TP40011227-CH12-SW11)).
  - Or, a combination of story elements and `&lt;project&gt;` elements:
    - Story elements: `&lt;clip&gt;`, `&lt;audition&gt;`, `&lt;mc-clip&gt;`, `&lt;ref-clip&gt;`, `&lt;sync-clip&gt;`, or `&lt;asset-clip&gt;`. See [Story Elements](https://developer.apple.com/library/archive/documentation/FinalCutProX/Reference/FinalCutProXXMLFormat/StoryElements/StoryElements.html#//apple_ref/doc/uid/TP40011227-CH13-SW1).
    - A `&lt;project&gt;` element representing a timeline in a Final Cut Pro X project. A `&lt;project&gt;` element contains a `&lt;sequence&gt;` element (see [Table 1-1](https://developer.apple.com/library/archive/documentation/FinalCutProX/Reference/FinalCutProXXMLFormat/EventsandProjects/EventsandProjects.html#//apple_ref/doc/uid/TP40011227-CH12-SW11) and [Table 2-1](https://developer.apple.com/library/archive/documentation/FinalCutProX/Reference/FinalCutProXXMLFormat/StoryElements/StoryElements.html#//apple_ref/doc/uid/TP40011227-CH13-SW5)).  
>       Note: As of FCPXML 1.4, the `&lt;project&gt;` element now only defines a project timeline; events are now represented by an `&lt;event&gt;` element.

    - Collection elements: `&lt;smart-collection&gt;`, `&lt;keyword-collection&gt;`, or `&lt;collection-folder&gt;`. See [Collections](https://developer.apple.com/library/archive/documentation/FinalCutProX/Reference/FinalCutProXXMLFormat/EventsandProjects/EventsandProjects.html#//apple_ref/doc/uid/TP40011227-CH12-SW7).

...

{% endraw %}
