# Todo: Consider to learn and document how to use the Ducted Fan ESC to drive the fan from some suitable power source?

```#28850883``` *As of 2018-09-10 14:13*

[mail plain/text](mail.txt)

{% raw %}
It seems I now have to learn how the ESC is controlled and what power source to use to make some progress in my “Ducted Fan” based indoor shed vacuum?

==&gt; Also see “[Todo: Consider to understand Radio Controllers and if and how to build my own ones?](../f0b82c12/chime.md)”

==&gt; Also see “[Todo: Consider to understand how to design and build my own Brushless DC Motor speed controller driver (for my ducted fan vacuum motor and other motor applications)?](../8b0c606d/chime.md)"

-1) Consider to condense what I have learned so far?

==&gt; It seems the ESC acts as a “Servo” controlled through the “**Servo Wire**”?

==&gt; My (and most) ESC provides the **5V power** to the receiver controlled electronics tryout a built in **BEC** (Battery Eliminator Circuit) **through the Servo Wire**

==&gt; All servo wires are electrically “the same” **plus-ground-signal** but comes in two basic colour schemes (red-black-white and red-brown-orange) with minor variations.

==&gt; All servo wires signal wire uses PWM (Pulse Width Control)!

==&gt;

> If I use my RC ESC I must implement the “standard RC servo PWM signal” (50 Hz 1-2 mS pulse width modulation) AND perform a startup-and-calibration-sequence.

> The ESC-to-transmitter calibration power-up sequence is stated in the manual as transmitter full throttle, ESC power on, transmitter zero-throttle (each step synchronised with acknowledge beeps from the ESC)

> Each start-flying power-up sequence is stated in the manual as transmitter zero-throttle, ESC power on.

1) The manual for my Hobbywing Skywalker 60A ESC seems to live here (<http://www.hobbywing.com/goods.php?id=407&filter_attr=6345.6463>)?

==&gt; Consider to store the pdf in this Todo-mail?

## Attachments

- [SkywalkerV2.pdf](SkywalkerV2.pdf)

{% endraw %}
