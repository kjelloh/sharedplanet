# Todo: Random Orbital Sander - Consider to understand how a random orbital sander moves and behaves to choose what to buy and possibly how to design my own (using a brushless motor)?

```#cdee3b9d``` *As of 2019-05-26 14:47*

[mail plain/text](mail.txt)

{% raw %}
It seems I could benefit from understanding the mechanics and workings of a random orbital sander to understand what to buy and possibly how to design my own (using say a drone brushless motor)?

==&gt; Also see "[Todo: Consider to document and understand brushless motors physics (torque, kv value...)?](../85bc3a7b/chime.md)"

1) Consider this in depth article "The Random Orbital. machine Stroke - How it affects Sanding nd Polishing Performance" (<http://www.buffdaddy.com/files/1519584/uploaded/KBM-Kevin%20Brown%20Method-Machine%20Stroke%20-%20How%20It%20Affects%20Sanding%20and%20Polishing%20Performance.pdf> )?

![](<Screenshot 2019-05-26 at 13.50.21.png>)

*The Random Orbital Sander rotates the backing plate on an offset axis*

![](<Screenshot 2019-05-26 at 13.51.43.png>)

*The Random Orbital Sander oscillates the backing plate while it rotates*

![](<Screenshot 2019-05-26 at 13.53.13.png>)

*The blue backing plate covers a larger white area due to its off-center rotation*

2) Consider I should be able to design my own Random Orbital Sander using a multicopter brushless motor with ESC and micro controller for speed control?

==&gt; Also see "[Todo: Consider to document and understand brushless motors physics (torque, kv value...)?](../85bc3a7b/chime.md)"

==&gt; Consider to understand the power ratings of brushless rc model motors?

> *The RC world is a little weird in that they do not concern themselves with motor output torque or power. Instead they talk about "lift power", max current and Kv values. *

> *But it seems we can get to the torque of a motor at a given current from its rated Kv value from the correlation Torque = I / Kv. From *  
> [*http://learningrc.com/motor-kv/](http://learningrc.com/motor-kv/) we can read this:*

> ![](<Screen Shot 2018-04-22 at 23.18.49.png>)

> *So, for a motor with Kv 270 kV = 270 rpm/V = 270 \* 2\*pi / 60 rad/Vs = 270 \* 0.1 rad/ Vs. We should get Kt = 1/Kv = 1/270 \* 60/2\*pi = 35,38 mNm/A. And thus, with Max 80A rating we get Max Torque = 35,38 mNm/A mNm/A \* 80A = 2,83 Nm (torque).*

> *So there is a tight relationship between the speed, the current and the provided torque for any given brushless motor once assembled. And this kan be expressed through the Kv value.  
> *

==&gt; Consider to mimic the Mirka Ceros 350 W sander performance using a rc model multi rotor brushless motor?

> *If we assume the Mirka Sander is capable of applying 350 W of sanding work onto a surface? And it is using a 5 mm orbit. We know the relationship between output power (J / S) and the torque (Nm) is given by the rotation speed. Let say we are sanding at 5000 rpm? This means that in one minute the disk performs 5000 revolutions. This is 5000/60 = 83,3 revolutions a second... TO BE CONTINUED...*

==&gt; Consider a motor like "Quanum MT Series 5008 335KV Brushless Multirotor Motor Built by DYS" /<https://hobbyking.com/en_us/quanum-mt-series-5008-335kv-brushless-multirotor-motor-built-by-dys.html> )?

![](<Screenshot 2019-05-26 at 14.03.27.png>)

==&gt; Consider a motor like "Multistar Elite 5008-330KV Multi-Rotor Motor" (<https://hobbyking.com/en_us/multistar-elite-5008-330kv-multi-rotor-motor.html?___store=en_us> )?

![](<Screenshot 2019-05-26 at 14.05.05.png>)

...

{% endraw %}
