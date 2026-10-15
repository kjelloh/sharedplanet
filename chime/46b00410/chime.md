# Todo: Consider noise modulated bright controller for flicker free video lights?

```#46b00410``` *As of 2018-02-15 20:18*

[mail plain/text](mail.txt)

{% raw %}
Could we imagine using a “random”, i.e., noise based, PWM LED lights bright controller to get flicker free video lights?

1) Consider we first generate a random bit stream to be used as the PWM signal to the LED lights?

==&gt; It seems this bit stream would modulate a steady mean LED brightness with a random flickering?  
==&gt; But then, how do we enable control of the actual LED brightness?

2) Consider we can pick bit stream frames with a specific mean one/zero ratio and use only those?

==&gt; Consider to cache the bit stream in a bit stream buffer of sufficient length to be able to pick specific ranges?  
==&gt; Consider with sufficient buffer length we will always find new bit stream ranges with the required on/off ratio?  
==&gt; Thus, we may continuously pick ranges from the random bit stream with required on/off ration to feed to the PWM of the LED lights?  
==&gt; Consider we can now create different brightness with random PWM by changing what random bit stream snippets to use?  
…

3) Consider we actually only need a PWM that is random for a specific time period and then just loop that one (without causing video recording flickering)?

==&gt; Consider the length of the random bit stream required to inhibit flickering for fps 24, 30, 60 (and any other common video frame rate)?  
==&gt; Consider what criteria we must apply to ensure the PWM is sufficiently “out of sync” with the frame rate to inhibit any flickering?  
==&gt; Then consider an algorithm that picks a random bit stream of sufficient length to loop for each brightness level?  
…

==&gt; It seems we need to define how many steps of brightness we want to control (e.g., is 1024 levels enough)?  
…

…

Consider to elaborate on this idea to create a flicker free LED video light bright controller that uses noise PWM?  
...

{% endraw %}
