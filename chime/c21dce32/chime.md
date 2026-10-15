# Todo: Consider to investigate and understand the Youtube Video Compression Format (MP4 container with recommended compression settings)?

```#c21dce32``` *As of 2018-06-11 15:29*

[mail plain/text](mail.txt)

{% raw %}
It seems it could be a good idea to try and understand what Youtube recommended video compression formats actually mean (and how to configure Apple Compressor to carry them out)?

1) Consider the default settings of a new setting in Apple Compressor?

![](<Screen Shot 2018-06-11 at 12.39.43.png>)

==&gt; Video H.264

==&gt; Automatic (Frame Size)

==&gt; Progressive (not interlaced frame rendering)

==&gt; Automatic fps

==&gt; Automatic Color Space (e.g., Rec. 601 NTSC/PAL ...)

==&gt; AAC Stereo Audio at 44,1 kHz

==&gt; It seems “Optimize for network use” is to encode files that will start playing by streaming clients as soon as a small part of the file has been downloaded (See compressor help)

> “*Optimize for network use: Select this checkbox to create a file that will start playing after only a small portion of the file has been downloaded from the networ*k."

==&gt; Consider all the video settings of the Apple Compressor MPEG-4 setting?

![](<Screen Shot 2018-06-11 at 12.44.32.png>)

2) Consider what Youtubes recommended settings mean and where we find them in Apple Compressor (<https://support.google.com/youtube/answer/1722171?hl=en>)?

==&gt; It seems “**Edit Lists**” are an Apple extension for Qicktime Movie containers (<https://developer.apple.com/library/archive/documentation/QuickTime/QTFF/QTFFChap2/qtff2.html#//apple_ref/doc/uid/TP40000939-CH204-BBCCFBEF>)?

==&gt; It seems “**moov**” atom is Apple specific (<https://developer.apple.com/library/archive/documentation/QuickTime/QTFF/QTFFChap2/qtff2.html#//apple_ref/doc/uid/TP40000939-CH204-BBCGDJID>)?

> “*QuickTime movie atoms have an atom type of 'moov'. These atoms act as a container for the information that describes a movie’s data. This information, or metadata, is stored in a number of different types of atoms. Generally speaking, only metadata is stored in a movie atom. Sample data for the movie, such as audio or video samples, are referenced in the movie atom, but are not contained in it.*"

**Q: Can we affect “Edit Lists” and the “moov” atom in Apple Compressor?**

==&gt; It seems “Progressive” means frames are to be stored “whole” as opposed to “interlaced frames” where each frame is split into two odd/even line interlaced frames?

==&gt; Consider this youtube video “Interlaced and Progressive Frame Rates Explained! : FRIDAY 101” that seems to give a good explanation of “interlaced” vs “progressive” (<https://www.youtube.com/watch?v=xKMWjRlIvrY>)?

==&gt; **Apple Compressor MPEG-4 setting is by default set to “Progressive” ok. **

==&gt; Youtube recommend AAC-LC Stereo Audio at 48 kHz.

==&gt; Apple compressor MPEG-4 setting uses 44,1 kHz by (NOT 48 kHz) by default.

**==&gt; Change Apple Compressor MPEG-4 Audio setting to use 48 kHz. **

==&gt; It seems Apple Compressor max audio bitrate is 320 kbps and thus can’t generate Audio 384 kbps rate (as youtube recommend)?

Q: Should we use AAC-LC Audio bitrate 128 kbps instead (or max 320 kbps audio bitrate)?

==&gt; It seems 48 kHz at 128 kbps would mean 128000/48000 = 2,7 bit resolution?

==&gt; And youtube recommended 384 kbps at 48 kHz sample rate would mean 8 bit resolution?

==&gt; On the other hand - Audio is compressed so the bit resolution is actually only about being able to represent transients (deltas) sufficiently?

Q: What does “2 consecutive B frames” mean (and how can I affect this setting in Apple Compressor)?

Q: What does “Closed GOP. GOP of half the frame rate.” mean (and how can I affect this setting in Apple Compressor)?

==&gt; **Apple recommends Entropy Mode “CABAC” (Which is default for Apple Compressor MPEG-4 setting) ok.**

==&gt; Youtube recommends minimum (optional) bitrate for 1080p to 8000 kbps.

==&gt; Apple Compressor MPEG-4 setting uses “Automatic” Data bit Rate (which I suppose means it uses the bitrate of the input file)?

==&gt; **Set Apple Compressor Data Bitrate to 8000 kbps.**

Q: What does “Chroma subsampling: 4:2:0” mean (and how can I affect this setting in Apple Compressor)?

==&gt; It seems Youtube supports both SDR (Standard Dynamic Range) and HDR (High Dynamic Range) video?

==&gt; It seems both FCPX and Apple Compressor supports both SDR (as Rec. 709) and HDR (Wide Gamut HDR with Rec. 2020) (<https://support.apple.com/en-us/HT208229>)?

> “For HDR projects, choose Wide Gamut HDR. When you choose Wide Gamut HDR, Final Cut Pro sets the working color space to linear RGB with Rec. 2020 color primaries, a color space with a greater range of colors than Rec. 709."

==&gt; This seems to be the “Color Space” settings in Apple Compressor?

![](<Screen Shot 2018-06-11 at 14.08.35.png>)

==&gt; It seems for FCPX one sets the mode SDR or HDR for the whole library (<https://support.apple.com/en-us/HT208229>)?

![](<Screen Shot 2018-06-11 at 14.13.37.png>)

TODO: Devle deeper into if and when I would like to switch a library into using Wide Gamut HDR (do I have video input with that quality and am I able to use output video in HDR)?

...

3) Consider the source text from youtube page on their recommended video compression settings (<https://support.google.com/youtube/answer/1722171?hl=en>)?

> # Recommended upload encoding settings

  
> Below are recommended upload encoding settings for your videos on YouTube.

  
> [Container: MP4]()
- No Edit Lists (or the video might not get processed correctly)
- moov atom at the front of the file (Fast Start)

  
> [Audio codec: AAC-LC]()
- Channels: Stereo or Stereo + 5.1
- Sample rate 96khz or 48khz

  
> [Video codec: H.264]()
- Progressive scan (no interlacing)
- High Profile
- 2 consecutive B frames
- Closed GOP. GOP of half the frame rate.
- CABAC
- Variable bitrate. No bitrate limit required, though we offer recommended bit rates below for reference
- Chroma subsampling: 4:2:0

  
> [Frame rate]()

> Content should be encoded and uploaded in the same frame rate it was recorded.

> Common frame rates include: 24, 25, 30, 48, 50, 60 frames per second (other frame rates are also acceptable).

> Interlaced content should be deinterlaced before uploading. For example, 1080i60 content should be deinterlaced to 1080p30, going from 60 interlaced fields per second to 30 progressive frames per second.

  
> [Bitrate]()

> The bitrates below are recommendations for uploads. Audio playback bitrate is not related to video resolution.

> #### Recommended video bitrates for SDR uploads

> To view new 4K uploads in 4K, use a browser or device that supports VP9.

> TypeVideo Bitrate, Standard Frame Rate  
> (24, 25, 30)Video Bitrate, High Frame Rate  
> (48, 50, 60)2160p (4k)35-45 Mbps53-68 Mbps1440p (2k)16 Mbps24 Mbps1080p8 Mbps12 Mbps720p5 Mbps7.5 Mbps480p2.5 Mbps4 Mbps360p1 Mbps1.5 Mbps

> #### Recommended video bitrates for HDR uploads

> TypeVideo Bitrate, Standard Frame Rate  
> (24, 25, 30)Video Bitrate, High Frame Rate  
> (48, 50, 60)2160p (4k)44-56 Mbps66-85 Mbps1440p (2k)20 Mbps30 Mbps1080p10 Mbps15 Mbps720p6.5 Mbps9.5 Mbps480p

> Not supported

> Not supported360pNot supportedNot supported

> #### Recommended audio bitrates for uploads

> TypeAudio BitrateMono128 kbpsStereo384 kbps5.1512 kbps  
> [Resolution and aspect ratio]()

> YouTube uses 16:9 aspect ratio players. If you're uploading a non-16:9 file, it will be processed and displayed with either black bars on the left and right (pillar boxes) or black bars at the top and bottom (letter boxes) to make a 16:9 ratio in the player.

> Learn how to [use resolution and aspect ratios](https://support.google.com/youtube/answer/6375112) correctly.



{% endraw %}
