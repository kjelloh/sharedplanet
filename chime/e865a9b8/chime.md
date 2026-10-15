# Todo: Final Cut Pro - Consider if we can automate youtube video creation using Final Cut Pro X XML interchange format (FinalCutProXXMLFormat)?

```#e865a9b8``` *As of 2018-05-07 13:33*

[mail plain/text](mail.txt)

{% raw %}
Maybe we can automate youtube video creation by creating some generator that spits out XML that we then can import into final cut pro?

1) The Final Cut Pro FinalCutProXXMLFormat seems to live here (<https://developer.apple.com/library/content/documentation/FinalCutProX/Reference/FinalCutProXXMLFormat/Introduction/Introduction.html>)?

2) Consider what we can do by interacting with final cut pro using the X XML format?

3) Consider to study an re-engeneer a Final Cut Pro project exported as an X XM file?

==&gt; Consider the empty project “X XML Playground - Empty Project.fcpxml” (Metadata View “General”)

> &lt;?xml version="1.0" encoding="UTF-8"?&gt;  
> &lt;!DOCTYPE fcpxml&gt;

> &lt;fcpxml version="1.8"&gt;  
> &lt;resources&gt;  
> &lt;format id="r1" name="FFVideoFormat1080p25" frameDuration="100/2500s" width="1920" height="1080" colorSpace="1-1-1 (Rec. 709)"/&gt;  
> &lt;/resources&gt;  
> &lt;library location="<file:///Volumes/Kjell-Olovs%20Passport%20Hard%20Drive/Current%20Workspace.fcpbundle/>"&gt;  
> &lt;event name="X XML PlayGround" uid="6EF1C872-1B8B-4146-BCA4-F7FE6CE7C90D"&gt;  
> &lt;project name="X XML Playground - Empty Project" uid="402494D0-518F-43C2-ADD3-11F9449B03AB" modDate="2018-05-07 11:29:20 +0200"&gt;  
> &lt;sequence duration="0s" format="r1" tcStart="0s" tcFormat="NDF" audioLayout="stereo" audioRate="48k"&gt;  
> &lt;spine/&gt;  
> &lt;/sequence&gt;  
> &lt;/project&gt;  
> &lt;/event&gt;  
> &lt;smart-collection name="Projects" match="all"&gt;  
> &lt;match-clip rule="is" type="project"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="All Video" match="any"&gt;  
> &lt;match-media rule="is" type="videoOnly"/&gt;  
> &lt;match-media rule="is" type="videoWithAudio"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Audio Only" match="all"&gt;  
> &lt;match-media rule="is" type="audioOnly"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Stills" match="all"&gt;  
> &lt;match-media rule="is" type="stills"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Favorites" match="all"&gt;  
> &lt;match-ratings value="favorites"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;/library&gt;  
> &lt;/fcpxml&gt;

==&gt; Consider the project “” with three placeholders?

==&gt; In FCP use “ • Choose Edit &gt; Insert Generator &gt; Placeholder (or press **Option-Command-W**)."

> &lt;?xml version="1.0" encoding="UTF-8"?&gt;  
> &lt;!DOCTYPE fcpxml&gt;

> &lt;fcpxml version="1.8"&gt;  
> &lt;resources&gt;  
> &lt;format id="r1" name="FFVideoFormat1080p25" frameDuration="100/2500s" width="1920" height="1080" colorSpace="1-1-1 (Rec. 709)"/&gt;  
> **&lt;effect id="r2" name="Placeholder" uid=".../Generators.localized/Elements.localized/Placeholder.localized/Placeholder.motn"/&gt;**  
> &lt;/resources&gt;  
> &lt;library location="<file:///Volumes/Kjell-Olovs%20Passport%20Hard%20Drive/Current%20Workspace.fcpbundle/>"&gt;  
> &lt;event name="X XML PlayGround" uid="6EF1C872-1B8B-4146-BCA4-F7FE6CE7C90D"&gt;  
> &lt;project name="X XML Playground - One Default placeholder" uid="402494D0-518F-43C2-ADD3-11F9449B03AB" modDate="2018-05-07 11:37:52 +0200"&gt;  
> &lt;sequence duration="3s" format="r1" tcStart="0s" tcFormat="NDF" audioLayout="stereo" audioRate="48k"&gt;  
> &lt;spine&gt;  
> **&lt;video name="Placeholder" offset="0s" ref="r2" duration="3s" start="3600s"/&gt;**  
> &lt;/spine&gt;  
> &lt;/sequence&gt;  
> &lt;/project&gt;  
> &lt;/event&gt;  
> &lt;smart-collection name="Projects" match="all"&gt;  
> &lt;match-clip rule="is" type="project"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="All Video" match="any"&gt;  
> &lt;match-media rule="is" type="videoOnly"/&gt;  
> &lt;match-media rule="is" type="videoWithAudio"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Audio Only" match="all"&gt;  
> &lt;match-media rule="is" type="audioOnly"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Stills" match="all"&gt;  
> &lt;match-media rule="is" type="stills"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Favorites" match="all"&gt;  
> &lt;match-ratings value="favorites"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;/library&gt;  
> &lt;/fcpxml&gt;

==&gt; It seems tow placeholders are chained in &lt;spine&gt; with adjusted offset and duration?

> &lt;?xml version="1.0" encoding="UTF-8"?&gt;  
> &lt;!DOCTYPE fcpxml&gt;

> &lt;fcpxml version="1.8"&gt;  
> &lt;resources&gt;  
> &lt;format id="r1" name="FFVideoFormat1080p25" frameDuration="100/2500s" width="1920" height="1080" colorSpace="1-1-1 (Rec. 709)"/&gt;  
> &lt;effect id="r2" name="Placeholder" uid=".../Generators.localized/Elements.localized/Placeholder.localized/Placeholder.motn"/&gt;  
> &lt;/resources&gt;  
> &lt;library location="<file:///Volumes/Kjell-Olovs%20Passport%20Hard%20Drive/Current%20Workspace.fcpbundle/>"&gt;  
> &lt;event name="X XML PlayGround" uid="6EF1C872-1B8B-4146-BCA4-F7FE6CE7C90D"&gt;  
> &lt;project name="X XML Playground - Two Default placeholders" uid="E1F9DFE5-937A-4B74-A01D-CAF997F94CB6" modDate="2018-05-07 12:29:29 +0200"&gt;  
> &lt;sequence duration="6s" format="r1" tcStart="0s" tcFormat="NDF" audioLayout="stereo" audioRate="48k"&gt;  
> &lt;spine&gt;  
> &lt;video name="Placeholder" offset="0s" ref="r2" **duration="3s"** start="3600s"/&gt;  
> &lt;video name="Placeholder" **offset="3s"** ref="r2" duration="3s" start="3600s"/&gt;  
> &lt;/spine&gt;  
> &lt;/sequence&gt;  
> &lt;/project&gt;  
> &lt;/event&gt;  
> &lt;smart-collection name="Projects" match="all"&gt;  
> &lt;match-clip rule="is" type="project"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="All Video" match="any"&gt;  
> &lt;match-media rule="is" type="videoOnly"/&gt;  
> &lt;match-media rule="is" type="videoWithAudio"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Audio Only" match="all"&gt;  
> &lt;match-media rule="is" type="audioOnly"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Stills" match="all"&gt;  
> &lt;match-media rule="is" type="stills"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Favorites" match="all"&gt;  
> &lt;match-ratings value="favorites"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;/library&gt;  
> &lt;/fcpxml&gt;

==&gt; And with five sequential placeholders we see the chaining even more clearly?

> &lt;?xml version="1.0" encoding="UTF-8"?&gt;  
> &lt;!DOCTYPE fcpxml&gt;

> &lt;fcpxml version="1.8"&gt;  
> &lt;resources&gt;  
> &lt;format id="r1" name="FFVideoFormat1080p25" frameDuration="100/2500s" width="1920" height="1080" colorSpace="1-1-1 (Rec. 709)"/&gt;  
> &lt;effect id="r2" name="Placeholder" uid=".../Generators.localized/Elements.localized/Placeholder.localized/Placeholder.motn"/&gt;  
> &lt;/resources&gt;  
> &lt;library location="<file:///Volumes/Kjell-Olovs%20Passport%20Hard%20Drive/Current%20Workspace.fcpbundle/>"&gt;  
> &lt;event name="X XML PlayGround" uid="6EF1C872-1B8B-4146-BCA4-F7FE6CE7C90D"&gt;  
> &lt;project name="X XML Playground - Five Default placeholders" uid="E1F9DFE5-937A-4B74-A01D-CAF997F94CB6" modDate="2018-05-07 12:33:58 +0200"&gt;  
> &lt;sequence duration="15s" format="r1" tcStart="0s" tcFormat="NDF" audioLayout="stereo" audioRate="48k"&gt;  
> &lt;spine&gt;  
> &lt;video name="Placeholder" **offset="0s"** ref="r2" duration="3s" start="3600s"/&gt;  
> &lt;video name="Placeholder" **offset="3s"** ref="r2" duration="3s" start="3600s"/&gt;  
> &lt;video name="Placeholder" **offset="6s"** ref="r2" duration="3s" start="3600s"/&gt;  
> &lt;video name="Placeholder" **offset="9s"** ref="r2" duration="3s" start="3600s"/&gt;  
> &lt;video name="Placeholder" **offset="12s"** ref="r2" duration="3s" start="3600s"/&gt;  
> &lt;/spine&gt;  
> &lt;/sequence&gt;  
> &lt;/project&gt;  
> &lt;/event&gt;  
> &lt;smart-collection name="Projects" match="all"&gt;  
> &lt;match-clip rule="is" type="project"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="All Video" match="any"&gt;  
> &lt;match-media rule="is" type="videoOnly"/&gt;  
> &lt;match-media rule="is" type="videoWithAudio"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Audio Only" match="all"&gt;  
> &lt;match-media rule="is" type="audioOnly"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Stills" match="all"&gt;  
> &lt;match-media rule="is" type="stills"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Favorites" match="all"&gt;  
> &lt;match-ratings value="favorites"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;/library&gt;  
> &lt;/fcpxml&gt;

==&gt; It seems when adding an actual clip FCP generates some form of complicated bookmark (among other stuff)?

> &lt;?xml version="1.0" encoding="UTF-8"?&gt;  
> &lt;!DOCTYPE fcpxml&gt;

> &lt;fcpxml version="1.8"&gt;  
> &lt;resources&gt;  
> &lt;format id="r1" name="FFVideoFormat1080p25" frameDuration="100/2500s" width="1920" height="1080" colorSpace="1-1-1 (Rec. 709)"/&gt;  
> &lt;effect id="r2" name="Placeholder" uid=".../Generators.localized/Elements.localized/Placeholder.localized/Placeholder.motn"/&gt;  
> &lt;asset id="r3" name="Thumb nail and outro Playground" uid="DCCDAD9F0E92B665FE5AAA1013FF76EA" src="<file:///Volumes/Kjell-Olovs%20Passport%20Hard%20Drive/Current%20Workspace.fcpbundle/X%20XML%20PlayGround/Original%20Media/Thumb%20nail%20and%20outro%20Playground.mov>" start="0s" duration="159/25s" hasVideo="1" format="r1" hasAudio="1" audioSources="1" audioChannels="2" audioRate="48000"&gt;  
> &lt;bookmark&gt;Ym9va6AEAAAAAAQQMAAAALzHA2FgpPSXEB1buSfLJzFyM4VEI0+hw0nPZ3H8TkuywAMAAAQAAAADAwAAABgAKAcAAAABAQAAVm  
> 9sdW1lcwAfAAAAAQEAAEtqZWxsLU9sb3ZzIFBhc3Nwb3J0IEhhcmQgRHJpdmUAGwAAAAEBAABDdXJyZW50IFdvcmtzcGFjZS5mY3BidW5kbGUAEAAAAAEBAABYIFhNTCBQbGF5R3JvdW5kDgAAAAEBAABPcmlnaW5hbCBNZWRpYQAAIwAAAAEBAABUaHVtYiBuYWlsIGFuZCBvdXRybyBQbGF5Z3JvdW5kLm1vdgAYAAAAAQYAABAAAAAgAAAASAAAAGwAAACEAAAAnAAAAAgAAAAEAwAAnzUAAAAAAAAIAAAABAMAAAIAAAAAAAAACAAAAAQDAACq5gUAAAAAAAgAAAAEAwAAcgUGAAAAAAAIAAAABAMAACYHBgAAAAAACAAAAAQDAAAsBwYAAAAAABgAAAABBgAA6AAAAPgAAAAIAQAAGAEAACgBAAA4AQAACAAAAAAEAABBwFAySoAAABgAAAABAgAAAQAAAAAAAAAPAAAAAAAAAAAAAAAAAAAANgAAAAEJAABmaWxlOi8vL1ZvbHVtZXMvS2plbGwtT2xvdnMlMjBQYXNzcG9ydCUyMEhhcmQlMjBEcml2ZS8AAAgAAAAEAwAAAGBPyugAAAAIAAAAAAQAAEG/4HubAAAAJAAAAAEBAABBQjdEMjFCOC1CNkI0LTNCOTItOUNFMS0yRDUxN0NEODIzMzAYAAAAAQIAAAEBAAABAAAA7xMAAAEAAAAAAAAAAAAAACgAAAABAQAAL1ZvbHVtZXMvS2plbGwtT2xvdnMgUGFzc3BvcnQgSGFyZCBEcml2ZQgAAAABCQAAZmlsZTovLy8MAAAAAQEAAE1hY2ludG9zaCBIRAgAAAAEAwAAAPBB6egAAAAIAAAAAAQAAEG5XrHGAAAAJAAAAAEBAAA3OUQ0MzJGNS03Njc4LTMxNDktQkVDRC02OEM2RjI5OUUyRDkYAAAAAQIAAIEAAAABAAAA7xMAAAEAAAAAAAAAAAAAAAEAAAABAQAALwAAAGAAAAD+////APAAAAAAAAAHAAAAAiAAAAQDAAAAAAAABSAAAHQCAAAAAAAAECAAAIQCAAAAAAAAESAAALgCAAAAAAAAEiAAAJgCAAAAAAAAEyAAAKgCAAAAAAAAICAAAOQCAAAAAAAABAAAAAMDAAAA8AAABAAAAAMDAAAAAAAABAAAAAMDAAABAAAAHAAAAAEGAAB4AwAAhAMAAJADAACEAwAAhAMAAIQDAACEAwAAqAAAAP7///8BAAAAEAMAAA0AAAAEEAAAyAAAAAAAAAAFEAAASAEAAAAAAAAQEAAAeAEAAAAAAABAEAAAaAEAAAAAAAAAIAAAnAMAAAAAAAACIAAARAIAAAAAAAAFIAAAmAEAAAAAAAAQIAAAIAAAAAAAAAARIAAA+AEAAAAAAAASIAAA2AEAAAAAAAATIAAA6AEAAAAAAAAgIAAAJAIAAAAAAAAQ0AAABAAAAAAAAAA=&lt;/bookmark&gt;  
> &lt;metadata&gt;  
> &lt;md key="com.apple.proapps.studio.rawToLogConversion" value="0"/&gt;  
> &lt;md key="com.apple.proapps.spotlight.kMDItemProfileName" value="HD (1-1-1)"/&gt;  
> &lt;md key="com.apple.proapps.spotlight.kMDItemCodecs"&gt;  
> &lt;array&gt;  
> &lt;string&gt;Apple ProRes 422&lt;/string&gt;  
> &lt;string&gt;Linear PCM&lt;/string&gt;  
> &lt;/array&gt;  
> &lt;/md&gt;  
> &lt;md key="com.apple.proapps.mio.ingestDate" value="2018-05-07 12:40:52 +0200"/&gt;  
> &lt;/metadata&gt;  
> &lt;/asset&gt;  
> &lt;/resources&gt;  
> &lt;library location="<file:///Volumes/Kjell-Olovs%20Passport%20Hard%20Drive/Current%20Workspace.fcpbundle/>"&gt;  
> &lt;event name="X XML PlayGround" uid="6EF1C872-1B8B-4146-BCA4-F7FE6CE7C90D"&gt;  
> &lt;project name="X XML Playground - Default placeholder + Outro Clip" uid="E1F9DFE5-937A-4B74-A01D-CAF997F94CB6" modDate="2018-05-07 12:43:36 +0200"&gt;  
> &lt;sequence duration="23400/2500s" format="r1" tcStart="0s" tcFormat="NDF" audioLayout="stereo" audioRate="48k"&gt;  
> &lt;spine&gt;  
> &lt;video name="Placeholder" offset="0s" ref="r2" duration="3s" start="3600s"/&gt;  
> **&lt;asset-clip name="Thumb nail and outro Playground" offset="3s" ref="r3" duration="15900/2500s" audioRole="dialogue" tcFormat="NDF"/&gt;**  
> &lt;/spine&gt;  
> &lt;/sequence&gt;  
> &lt;/project&gt;  
> &lt;/event&gt;  
> &lt;smart-collection name="Projects" match="all"&gt;  
> &lt;match-clip rule="is" type="project"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="All Video" match="any"&gt;  
> &lt;match-media rule="is" type="videoOnly"/&gt;  
> &lt;match-media rule="is" type="videoWithAudio"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Audio Only" match="all"&gt;  
> &lt;match-media rule="is" type="audioOnly"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Stills" match="all"&gt;  
> &lt;match-media rule="is" type="stills"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Favorites" match="all"&gt;  
> &lt;match-ratings value="favorites"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;/library&gt;  
> &lt;/fcpxml&gt;

==&gt; This seems to be a project with one default placeholder plus one second default placeholder replaced with a clip range?

> &lt;?xml version="1.0" encoding="UTF-8"?&gt;  
> &lt;!DOCTYPE fcpxml&gt;

> &lt;fcpxml version="1.8"&gt;  
> &lt;resources&gt;  
> &lt;format id="r1" name="FFVideoFormat1080p25" frameDuration="100/2500s" width="1920" height="1080" colorSpace="1-1-1 (Rec. 709)"/&gt;  
> &lt;effect id="r2" name="Placeholder" uid=".../Generators.localized/Elements.localized/Placeholder.localized/Placeholder.motn"/&gt;  
> &lt;asset id="r3" name="Thumb nail and outro Playground" uid="DCCDAD9F0E92B665FE5AAA1013FF76EA" src="<file:///Volumes/Kjell-Olovs%20Passport%20Hard%20Drive/Current%20Workspace.fcpbundle/X%20XML%20PlayGround/Original%20Media/Thumb%20nail%20and%20outro%20Playground.mov>" start="0s" duration="159/25s" hasVideo="1" format="r1" hasAudio="1" audioSources="1" audioChannels="2" audioRate="48000"&gt;  
> &lt;bookmark&gt;Ym9va6AEAAAAAAQQMAAAAP/xziq22EFWEhnMc4qdDWcKXZW+AjFl+g18xRpc/t1EwAMAAAQAAAADAwAAABgAKAcAAAABAQAAVm9sdW1lcwAfAAAAAQEAAEtqZWxsLU9sb3ZzIFBhc3Nwb3J0IEhhcmQgRHJpdmUAGwAAAAEBAABDdXJyZW50IFdvcmtzcGFjZS5mY3BidW5kbGUAEAAAAAEBAABYIFhNTCBQbGF5R3JvdW5kDgAAAAEBAABPcmlnaW5hbCBNZWRpYQAAIwAAAAEBAABUaHVtYiBuYWlsIGFuZCBvdXRybyBQbGF5Z3JvdW5kLm1vdgAYAAAAAQYAABAAAAAgAAAASAAAAGwAAACEAAAAnAAAAAgAAAAEAwAAnzUAAAAAAAAIAAAABAMAAAIAAAAAAAAACAAAAAQDAACq5gUAAAAAAAgAAAAEAwAAcgUGAAAAAAAIAAAABAMAACYHBgAAAAAACAAAAAQDAAAsBwYAAAAAABgAAAABBgAA6AAAAPgAAAAIAQAAGAEAACgBAAA4AQAACAAAAAAEAABBwFAySoAAABgAAAABAgAAAQAAAAAAAAAPAAAAAAAAAAAAAAAAAAAANgAAAAEJAABmaWxlOi8vL1ZvbHVtZXMvS2plbGwtT2xvdnMlMjBQYXNzcG9ydCUyMEhhcmQlMjBEcml2ZS8AAAgAAAAEAwAAAGBPyugAAAAIAAAAAAQAAEG/4HubAAAAJAAAAAEBAABBQjdEMjFCOC1CNkI0LTNCOTItOUNFMS0yRDUxN0NEODIzMzAYAAAAAQIAAAEBAAABAAAA7xMAAAEAAAAAAAAAAAAAACgAAAABAQAAL1ZvbHVtZXMvS2plbGwtT2xvdnMgUGFzc3BvcnQgSGFyZCBEcml2ZQgAAAABCQAAZmlsZTovLy8MAAAAAQEAAE1hY2ludG9zaCBIRAgAAAAEAwAAAPBB6egAAAAIAAAAAAQAAEG5XrHGAAAAJAAAAAEBAAA3OUQ0MzJGNS03Njc4LTMxNDktQkVDRC02OEM2RjI5OUUyRDkYAAAAAQIAAIEAAAABAAAA7xMAAAEAAAAAAAAAAAAAAAEAAAABAQAALwAAAGAAAAD+////APAAAAAAAAAHAAAAAiAAAAQDAAAAAAAABSAAAHQCAAAAAAAAECAAAIQCAAAAAAAAESAAALgCAAAAAAAAEiAAAJgCAAAAAAAAEyAAAKgCAAAAAAAAICAAAOQCAAAAAAAABAAAAAMDAAAA8AAABAAAAAMDAAAAAAAABAAAAAMDAAABAAAAHAAAAAEGAAB4AwAAhAMAAJADAACEAwAAhAMAAIQDAACEAwAAqAAAAP7///8BAAAAEAMAAA0AAAAEEAAAyAAAAAAAAAAFEAAASAEAAAAAAAAQEAAAeAEAAAAAAABAEAAAaAEAAAAAAAAAIAAAnAMAAAAAAAACIAAARAIAAAAAAAAFIAAAmAEAAAAAAAAQIAAAIAAAAAAAAAARIAAA+AEAAAAAAAASIAAA2AEAAAAAAAATIAAA6AEAAAAAAAAgIAAAJAIAAAAAAAAQ0AAABAAAAAAAAAA=&lt;/bookmark&gt;  
> &lt;metadata&gt;  
> &lt;md key="com.apple.proapps.studio.rawToLogConversion" value="0"/&gt;  
> &lt;md key="com.apple.proapps.spotlight.kMDItemProfileName" value="HD (1-1-1)"/&gt;  
> &lt;md key="com.apple.proapps.spotlight.kMDItemCodecs"&gt;  
> &lt;array&gt;  
> &lt;string&gt;Apple ProRes 422&lt;/string&gt;  
> &lt;string&gt;Linear PCM&lt;/string&gt;  
> &lt;/array&gt;  
> &lt;/md&gt;  
> &lt;md key="com.apple.proapps.mio.ingestDate" value="2018-05-07 12:40:52 +0200"/&gt;  
> &lt;/metadata&gt;  
> &lt;/asset&gt;  
> &lt;/resources&gt;  
> &lt;library location="<file:///Volumes/Kjell-Olovs%20Passport%20Hard%20Drive/Current%20Workspace.fcpbundle/>"&gt;  
> &lt;event name="X XML PlayGround" uid="6EF1C872-1B8B-4146-BCA4-F7FE6CE7C90D"&gt;  
> &lt;project name="X XML Playground - One Default placeholder + One range replaced placeholder" uid="8A8B41DC-F0D8-4B4A-83E6-FC443280D2ED" modDate="2018-05-07 13:29:20 +0200"&gt;  
> &lt;sequence duration="6s" format="r1" tcStart="0s" tcFormat="NDF" audioLayout="stereo" audioRate="48k"&gt;  
> &lt;spine&gt;  
> &lt;video name="Placeholder" offset="0s" ref="r2" duration="3s" start="3600s"/&gt;  
> &lt;**asset-clip** name="Thumb nail and outro Playground" **offset="3s"** ref="r3" duration="3s" start="31/25s" audioRole="dialogue" tcFormat="NDF"/&gt;  
> &lt;/spine&gt;  
> &lt;/sequence&gt;  
> &lt;/project&gt;  
> &lt;/event&gt;  
> &lt;smart-collection name="Projects" match="all"&gt;  
> &lt;match-clip rule="is" type="project"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="All Video" match="any"&gt;  
> &lt;match-media rule="is" type="videoOnly"/&gt;  
> &lt;match-media rule="is" type="videoWithAudio"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Audio Only" match="all"&gt;  
> &lt;match-media rule="is" type="audioOnly"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Stills" match="all"&gt;  
> &lt;match-media rule="is" type="stills"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;smart-collection name="Favorites" match="all"&gt;  
> &lt;match-ratings value="favorites"/&gt;  
> &lt;/smart-collection&gt;  
> &lt;/library&gt;  
> &lt;/fcpxml&gt;

==&gt; Consider the Final Cut Project “First Time - Fusion 360 Design and Cetus 3D Print &#91;Episode X 18 April 2018&#93;” exported as an X XML file?

## Attachments

- [First Time - Fusion 360 Design and Cetus 3D Print &#91;Episode X 18 April 2018&#93;.fcpxml.rtf](<First Time - Fusion 360 Design and Cetus 3D Print [Episode X 18 April 2018].fcpxml.rtf>)

{% endraw %}
