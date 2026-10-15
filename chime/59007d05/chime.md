# Todo: consider to understand video rendering, streaming, encoding, compressing and persistent storage?

```#59007d05``` *As of 2019-03-06 14:43*

[mail plain/text](mail.txt)

{% raw %}
It seems I should look into video representations to get a better understanding of how video is represented in different stages of usage?

1) Consider how a vide frame is represented in size and encoding in different screen resolutions?

==&gt; Consider good leads on this video size calculator (<https://www.omnicalculator.com/other/video-frame-size#how-to-calculate-the-video-frame-size> )?

==&gt; It seems the frame size in bytes are simply Pixel Count x Pixel Colour bit depth?

> "The higher the color depth, the bigger the data size of every pixel. If you use 8-bit colors, each pixel has to store 8 bits of information (equivalent to 1 [byte](https://www.omnicalculator.com/conversion/byte-converter)). 16-bit colors need 2 bytes of information per pixel, 24-bit need 3 bytes.

> Once you know the resolution and color depth, you can find the frame size according to the following equation:

> `frame size = V \* H \* CD`

> where

- V is the vertical resolution,
- H is the horizontal resolution, and
- CD is the color depth."

==&gt; And then uncompressed video is simply the frame size times the frame rate times the length of the video?

> "video size = frame size \* fps \* time

> where

- time is the duration of the video, and
- fps is the number of frames displayed per second. This number can range from 12 fps to even 60 fps; the most common value, however, is 24 frames per second."

2) consider how we may find good ways to enhance video encoding on an Apple OS X machine (e.g. my mac pro 2013)?

==&gt; Consider Apple Compressor would support any hardware accelerator with Metal 2 support?

Hm... No actually it does not seem Metal 2 is strongly correlated with hardware (GPU) accelerated video encoding?

==&gt; Consider this blog post "Optimize Apple Compressor for Greater Speed" (<https://larryjordan.com/articles/optimize-apple-compressor-for-greater-speed/> )?

==&gt; It seems mainly on OS X we can choose to compress through Apple Compressor or Adobe Media Encode?

> "I know of only two high-quality software tools specifically designed for media compression – Adobe Media Encoder and Apple Compressor – that run on a Mac."

==&gt; It seems in 2019 Apple will remove transcoding ability for codecs implemented as 32 bit applications (<https://larryjordan.com/blog/important-dont-lose-access-to-older-media/> )

> "With the release of macOS Mojave (10.14), Apple is continuing its conversion to 64-bit applications that it first began many years ago. In the next major version of macOS after Mojave, this conversion will affect media which relies on older 32-bit codecs."

==&gt; It seems FFMeg has issues for future applications (there are reasons to find more future proof compression applications on OS X)?

> "**WHY THIS IS IMPORTANT**
- Telestream Episode is no longer available.
- Sorensen Squeeze is no longer available.
- ffMPEG has significant legal/licensing issues."

3) Consider good resources on how Macs interacts with an eGPU for video tasks?

==&gt; It seems we should be able to use an eGPU with the Mac Pro 2013 by using Apples Thunderbolt 2 to Thunderbolt 3 cable and supported AMD Solaris graphics card external enclosure?

==&gt; Consider (<https://www.reddit.com/r/eGPU/comments/9mw57r/thunderbolt_2_to_thunderbolt_3_for_egpu/> )?

> "thunderbolt 2 should be just fine. you will need the official apple thunderbolt 3 to 2 adapter though: <https://www.apple.com/ca/shop/product/MMEL2AM/A/thunderbolt-3-usb-c-to-thunderbolt-2-adapter>  
> to figure out how to make it work: go to <http://egpu.io/build-guides/> and find a build that is similar to yours and see how they did it."

==&gt; Consider (<https://egpu.io/build-guides/> )?

==&gt; Consider this youtube video "The Best Mac... Apple Doesn't Make!" (<https://www.youtube.com/watch?v=pNd5_kxpPc4> )?

==&gt; He seems to use a Mac Pro 2013 with an external AMD RX 480?

==&gt; he seems to conclude that Apple natively supports AMD Polaris architecture due to Macbook Pro late 2016 base model supporting (Mobile) ADM Radeon Pro 450 or 455 or a configured model with 460.

## Attachments

- [H.264 for the rest of us (recreated by print to pdf).pdf](<H.264 for the rest of us (recreated by print to pdf).pdf>)

{% endraw %}
