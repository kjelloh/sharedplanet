# Todo: Einhell 2025 Table Saw - Consider I can replace the motor with a brushless outrunner dc motor?

```#31db3b0c``` *As of 2018-09-21 12:52*

[mail plain/text](mail.txt)

{% raw %}
Could it be possible to modify my Einhell 2025 table saw to use a brushless outrunner motor instead?

==&gt; Also see “[Todo: Consider to document and understand brushless motors physics (torque, kv value...)?](../85bc3a7b/chime.md)"

==&gt; Also see “[Todo: Consider to study Rotary Controllers for servo motors and what we can use them for?](../fc55f824/chime.md)”

==&gt; Also see “[Todo: Consider to follow up on components and products used and described on the Macro Reps youtube channel?](../b24a430d/chime.md)"

1) Consider the Chineese outrunner motor N5065 (<https://www.aliexpress.com/item/Brushless-Outrunner-Motor-N5065-270KV-1665W-For-DIY-Electric-Skate-Board/32795443468.html>)?

![](<Screen Shot 2018-04-20 at 18.56.43.png>)

==&gt; Consider ways to design a drive train to get the blade to turn 5000 rpm?

==&gt; What rpm can we expect from this motor based on “Rotational Speed:270 (kv) RPM/V”?

==&gt; Consider this page on RC nomenclature (<https://rogershobbycenter.com/lipoguide/>)?

> > “*Voltage directly influences the RPM of the electric motor (brushless motors are rated by kV, which means 'RPM per Volt'). So if you have a brushless motor with a rating of 3,500kV, that motor will spin 3,500 RPM for every volt you apply to it. On a 2S LiPo battery, that motor will spin around 25,900 RPM. On a 3S, it will spin a whopping 38,850 RPM. So the more voltage you have, the faster you're going to go.*"

> > “*A LiPo cell has a nominal voltage of 3.7V*"

> > “*sometimes why you will hear people talk about a "2S" battery pack - it means that there are 2 cells in Series. So a two-cell (2S) pack is 7.4V, a three-cell (3S) pack is 11.1V, a*nd so on."

==&gt; “Input voltage: 3-8Cells lipo” suggests max 8S, i.e., 8 \* 3.7 = 29,6V

==&gt; 270 kV suggest 270 rpm/V \* 29,6 V = 7992 rpm MAX.

==&gt; But this would define the free spinning rpm (zero torque)?

==&gt; Consider this Brushless Motor Efficiency calculator (<http://www.radiocontrolinfo.com/brushless-motor-efficiency/#2>)?

![](<Screen Shot 2018-04-20 at 20.37.21.png>)

==&gt; Also see Appendix below (Kt = 1/Kv \* 60/2\*pi where the 60/2\*pi is to convert rpm to rad/s)

2) Consider to use the ODrive to drive the brushless motor for the saw?

==&gt; Consider this youtube video on ODrive as an ESC for an electric skateboard (<https://www.youtube.com/watch?v=vvgma1lW7A0>)?

3) Consider the Odrive brushless motor settings (<https://docs.google.com/spreadsheets/d/12vzz7XVEK6YNIOqH0jAz51F5VUpc-lJEs3mmkWP1H4Y/edit#gid=0>)?

![](<Screen Shot 2018-04-20 at 21.19.37.png>)

==&gt; Consider the KEDA 63-64 190KV 10S Brushless 2000W motor (<https://hobbyking.com/en_us/kd-53-30-high-voltage-brushless-outrunner-190kv.html?___store=en_us>)?

![](<Screen Shot 2018-04-20 at 21.22.28.png>)

{% endraw %}
