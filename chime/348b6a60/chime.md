# Todo: Consider to document how to fix "Xcode 1.5 not supported" error when running cmake -G Xcode on macOS?

```#348b6a60``` *As of 2022-01-27 18:25*

[mail plain/text](mail.txt)

{% raw %}
1) It seems we get error "Xcode 1.5 not supported" if the macOS for some reason can't find what Xcode installation we are using?

==&gt; If cmake finds the "wrong" Xcode (or npone at all) it seems to produce the error ""

> ```
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro build % cmake -G Xcode ..
> CMake Error:
>   Xcode 1.5 not supported.
> ```

> ```
> ...
> ```

  
==&gt; This seems to be the fix for me to have cmake use my installed Xcode-beta?

  
> ```
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro build %sudo /usr/bin/xcode-select --switch /Applications/Xcode-beta.app
> ```



2) Consider the Gist I created that shows the console output and fix of this error (<https://gist.github.com/kjelloh/409c16dc395c97c2df4aa458a00976eb> )?

{% endraw %}
