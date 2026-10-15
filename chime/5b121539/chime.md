# Todo: FCPX XML - Consider to generate the smallest XML file that FCPX can open as a project file to render a video?

```#5b121539``` *As of 2021-07-30 17:02*

[mail plain/text](mail.txt)

{% raw %}
==&gt; Also see "Todo: Consider to understand how I may write plugins to automate Final Cut Pro X (FCPX) tasks more to my liking?"

1) It seems the FCPX XML reference lives here (<https://developer.apple.com/documentation/professional_video_applications/fcpxml_reference> )?

==&gt; It seems FCPXML is used to communicate in both directions between plugins and FCPX itself (<https://developer.apple.com/documentation/professional_video_applications/fcpxml_reference/creating_fcpxml_documents> )?

> *"**FCPXML describes Final Cut Pro items in a way your app understands. Your app uses FCPXML to send data to Final Cut Pro, and Final Cut Pro uses it to describe the data your app receives.*  
> *FCPXML describes data from your app in terms that correlate to Final Cut Pro objects — clips and project sequences, along with their media assets, often organized in events. FCPXML captures editing decisions, including the order of clips, as well as audio or video effects and transitions. It also captures metadata associated with the media assets, as well as ratings, keywords, and markers that Final Cut Pro uses to organize and annotate data.**"*

==&gt; Consider this example of a FCPX project XML file (<https://developer.apple.com/documentation/professional_video_applications/fcpxml_reference/describing_final_cut_pro_items_in_fcpxml> )?

> &lt;fcpxml version="1.9"&gt;  
> &lt;import-options&gt;  
> &lt;option key="library location" value="<file:///Volumes/FCPXLibraries/MyLibrary.fcpbundle>"/&gt;  
> &lt;/import-options&gt;  
> &lt;!-- Resources --&gt;  
> &lt;resources&gt;  
> &lt;format id="r1" name="FFVideoFormat1080p30"/&gt;  
> &lt;asset id="r2" start="0s" duration="10s" hasVideo="1" hasAudio="1" format="r1" audioSources="1" audioChannels="2" audioRate="48000"&gt;  
> &lt;media-rep kind="original-media" src="<file:///Volumes/Media/MyMovie1.mov>"/&gt;  
> &lt;/asset&gt;  
> &lt;asset id="r3" start="0s" duration="20s" hasVideo="1" hasAudio="1" format="r1" audioSources="1" audioChannels="2" audioRate="48000"&gt;  
> &lt;media-rep kind="original-media" src="<file:///Volumes/Media/MyMovie2.mov>"/&gt;  
> &lt;/asset&gt;  
> &lt;asset id="r4" start="10s" duration="40s" hasVideo="1" hasAudio="1" format="r1" audioSources="1" audioChannels="2" audioRate="48000"&gt;  
> &lt;media-rep kind="original-media" src="<file:///Volumes/Media/MyMovie3.mov>"/&gt;  
> &lt;/asset&gt;  
> &lt;/resources&gt;  
> &lt;project name="MyProjectWithMarkers"&gt;  
> &lt;!-- Project Story Elements --&gt;  
> &lt;sequence format="r1"&gt;  
> &lt;spine&gt;  
> &lt;asset-clip name="MyMovie1" ref="r2" start="0s" duration="5s" audioRole="dialogue"&gt;  
> &lt;marker start="2s" duration="1000/30000s" value="My Marker 1"/&gt;  
> &lt;/asset-clip&gt;  
> &lt;asset-clip name="MyMovie3" ref="r4" offset="5s" start="15s" duration="5s" audioRole="dialogue"&gt;  
> &lt;chapter-marker start="18s" duration="1000/30000s" value="Chapter 2" posterOffset="19s"/&gt;  
> &lt;/asset-clip&gt;  
> &lt;asset-clip name="MyMovie1" ref="r2" offset="10s" start="5s" duration="5s" audioRole="dialogue"&gt;  
> &lt;marker start="8s" duration="1000/30000s" value="My Marker 2"/&gt;  
> &lt;/asset-clip&gt;  
> &lt;asset-clip name="MyMovie2" ref="r3" offset="15s" start="5s" duration="5s" audioRole="dialogue"&gt;  
> &lt;marker start="6s" duration="1000/30000s" value="My To Do 1" completed="0"/&gt;  
> &lt;marker start="8s" duration="1000/30000s" value="My To Do 2" completed="1"/&gt;  
> &lt;/asset-clip&gt;  
> &lt;asset-clip name="MyMovie1" ref="r2" offset="20s" start="0s" duration="5s" audioRole="dialogue"&gt;  
> &lt;marker start="4s" duration="1000/30000s" value="My Marker 3"/&gt;  
> &lt;/asset-clip&gt;  
> &lt;/spine&gt;  
> &lt;/sequence&gt;  
> &lt;/project&gt;  
> &lt;!-- Clips --&gt;  
> &lt;asset-clip name="MyMovie1" ref="r2" format="r1" start="0s" duration="10s" audioRole="dialogue"/&gt;  
> &lt;asset-clip name="MyMovie2" ref="r3" format="r1" start="0s" duration="20s" audioRole="dialogue"/&gt;  
> &lt;asset-clip name="MyMovie3" ref="r4" format="r1" start="10s" duration="40s" audioRole="dialogue"/&gt;  
> &lt;/fcpxml&gt;

...

{% endraw %}
