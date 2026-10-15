# Todo: Consider to write a teleprompter app for Android (Chrome)?

```#5d76445d``` *As of 2018-09-23 02:05*

[mail plain/text](mail.txt)

{% raw %}
What would it take to write a teleprompter app for Android and/or Chrome?

1) Consider how bad all existing Teleprompter apps are?

==&gt; Almost all are “free” and thus comes with ads! (I really like to use my app in private and undisturbed!)

==&gt; All the paid ones I tried failed to read pdfs from Google Docs (Google Drive)

==&gt; Many paid Teleprompter apps provided editing (which you totally want to do on a Desktop device)

…

2) What does it take to write an Android App?

==&gt; Consider I can write Android Apps in C++ in Embarcadero RAD Studio 10.2 (Tokyo)?

180922 - Installed Tokyo 10.2 on my Windows 10 machine

==&gt; Consider I can use Android Studio in OS X (<https://developer.android.com/studio/>)?

180922 - I Installed Android Studio on my Macbook Pro 2014

**TODO: Consider to make a “Hello World” to run on my CAT S60 using Embarcadero RAD Studio and Android Studio?**

==&gt; It seems Java is the “Official” Android app language but C++, JS and many more can also be used (<https://www.androidauthority.com/develop-android-apps-languages-learn-391008/>)?

> “The languages you might consider learning for Android development include:

> • Java – Java is the official language of Android development and is supported by Android Studio. It has a steep learning curve however.  
> • **Kotlin** – Kotlin was recently introduced as a secondary “official” Java language. It is similar to Java in many ways but is a little easier to get your head around.  
> • C/C++ — Android Studio also supports C++ with the use of the Java NDK. This allows for native coding applications, which can be handy for things like games. C++ is more complicated though.  
> • C# — C# is a slightly more beginner-friendly alternative to C or C++ that obfuscates more code. It’s supported by some very handy tools like Unity and Xamarin which are great for game development and for cross-platform development.  
> • BASIC – A bonus option is to learn BASIC and try the B4A IDE from Anywhere Software. This is an easy but powerful tool, though definitely much more niche!  
> • Corona/LUA – Another cross-platform tool build on LUA. It massively simplifies the app-building process and allows you to call native libraries.  
> • PhoneGap (HTML, CSS, JavaScript) – If you already know how to build interactive web pages, then you can use this knowledge with PhoneGap to build a more basic cross-platform app."

==&gt; It seems C/C++ is supported in Android Studio (through Android NDK)?

==&gt; Consider to check out Kotlin - that seems to be the next upcoming preferred and supported language for Android (and it runs on the java VM)

==&gt; Consider to build a simple app as recommended by the Android Studio docs (<https://developer.android.com/training/basics/firstapp/>)?

180923 - Succeeded to install and run - and **created an Android Studio app project** (wow, so much downloading and installing that went on to get to this state - **CRAZY**)

![](<Screen Shot 2018-09-23 at 00.48.08.png>)

180923 - Seems I succeeded to run the dummy first application on a simulated Android Phone?

![](<Screen Shot 2018-09-23 at 02.03.55.png>)

==&gt; It seems Android API provides speech recognition (<https://developer.android.com/reference/android/speech/SpeechRecognizer>)?

==&gt; But this API is NOT to be used for continuous speech recognition (like dictation and in our case to scroll the script)?

> “*The implementation of this API is likely to stream audio to remote servers to perform speech recognition. As such this API is not intended to be used for continuous recognition, which would consume a significant amount of battery and bandwidth.*"

==&gt; It seems google provides a speech-recognition-streaming-service we can use (although it will require a web-connection and significant web traffic) (?

> “Real-time Streaming or Prerecorded Audio Support  
> Audio input can be **streamed** from an application’s microphone or sent from a prerecorded audio file (inline or **through Google Cloud Storage**). Multiple audio encodings are supported, including FLAC, AMR, PCMU, and Linear-16."

==&gt; Its free up to 60 minutes, Then there is a fee (<https://cloud.google.com/speech-to-text/pricing>)?

...

3) Consider the design goals of my Teleprompter App?

==&gt; Consider it must NOT invade the privacy of the user (No access to contacts or any other personal data)

==&gt; Consider it should read pdf.s from Google Docs (From Google Drive OR from public shared link)?

==&gt; Consider it should be able to engage with device Speech Recognition to automatically scroll the teleprompter text?

==&gt; Consider it should be able to flash light into the camera to mark takes?

==&gt; Consider we can pair the device with a Bluetooth light or flash to enable sending flashes into the recording camera?

==&gt; Consider to design and make a small display we may light up into the camera to mark takes?

==&gt; Could be just a small simple one or two row LED display?

…

==&gt; Consider it should work with scripts stored in IPFS ([https://docs.ipfs.io](https://docs.ipfs.io/))?

4) Consider if there is any Speech Recognition API on iOS, Android, Chrome or Windows?

…

{% endraw %}
