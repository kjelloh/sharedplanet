# Todo: It seems Freecad 'weekly build' for apple silicone requires a CLI to 'unlock' the security check (remove 'damaged' error)?

```#618ac822``` *As of 2025-02-28 13:06*

[mail plain/text](mail.txt)

{% raw %}
I tried Freecad weekly build to see if unstability on my macOS apple silicone may become fixed.

1) Consider this thread "weekly builds are not signed and are shown as "damaged" on arm64 macOS #291" (<https://github.com/FreeCAD/FreeCAD-Bundle/issues/291> )?

> ![Screenshot 2024-08-19 at 8 52 00 AM.png](<Screenshot 2024-08-19 at 8 52 00 AM.png>)

2) It seems the command 'sudo xattr -r -d com.apple.quarantine /Applications/FreeCAD.app' removes the error?

> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/freecad-bim-example-0 % **sudo xattr -r -d com.apple.quarantine /Applications/FreeCAD.app**

> Password:

> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/freecad-bim-example-0 %



==&gt; Now Freecad 1.1 (weekly build) starts just fine on ma apple silicone macbook Pro M3 14" 18GB machine.

..

{% endraw %}
