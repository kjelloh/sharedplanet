# Todo: Consider to document and understand brushless motors physics (torque, kv value...)?

```#85bc3a7b``` *As of 2018-09-21 12:52*

[mail plain/text](mail.txt)

{% raw %}
It seems it could be a good idea to document and understand data and physics about brushless motors?

==&gt; Also see “[Todo: Einhell 2025 Table Saw - Consider I can replace the motor with a brushless outrunner dc motor?](../31db3b0c/chime.md)"

==&gt; Also see “[Todo: DIY Torque Transducer - Consider to experiment with strain gauges to implement torque transducer for wind and bicycle generator power measurement?](../2d597344/chime.md)”

1) Consider this article “BRUSHLESS MOTOR KV CONSTANT EXPLAINED” (<http://learningrc.com/motor-kv/>)?

==&gt; It seems Ke is the back-emf constant V/(rad/s)?

==&gt; It seems Kv is rad/Vs = the reciprocal of Ke (but normally given in rpm/V unit, where 1 rpm = 2\*pi rad/ 60s)?

==&gt; And Kt is the torque constant Nm/A

==&gt; Note: It seems torque is Joule (Nm) but actually torque is has “direction” while energy does not (The torque must be projected onto a distance vector to get the exercised energy)?

![](<Screen Shot 2018-04-22 at 23.18.49.png>)



==&gt; This suggest 270 kV = 270 rpm/V = 270 \* 2\*pi / 60 rad/Vs = 270 \* 0.1 rad/ Vs

==&gt; Which should give us Kt = 1/Kv = 1/270 \* 60/2\*pi = 35,38 mNm/A

==&gt; Thus, with Max 80A rating we get Max Torque = 35,38 mNm/A mNm/A \* 80A = 2,83 Nm (torque)

…

2) Consider this page on RC nomenclature (<https://rogershobbycenter.com/lipoguide/>)?

> > “*Voltage directly influences the RPM of the electric motor (brushless motors are rated by kV, which means 'RPM per Volt'). So if you have a brushless motor with a rating of 3,500kV, that motor will spin 3,500 RPM for every volt you apply to it. On a 2S LiPo battery, that motor will spin around 25,900 RPM. On a 3S, it will spin a whopping 38,850 RPM. So the more voltage you have, the faster you're going to go.*"

> > “*A LiPo cell has a nominal voltage of 3.7V*"

> > “*sometimes why you will hear people talk about a "2S" battery pack - it means that there are 2 cells in Series. So a two-cell (2S) pack is 7.4V, a three-cell (3S) pack is 11.1V, a*nd so on."

==&gt; “Input voltage: 3-8Cells lipo” suggests max 8S, i.e., 8 \* 3.7 = 29,6V

==&gt; 270 kV suggest 270 rpm/V \* 29,6 V = 7992 rpm MAX.

==&gt; But this would define the free spinning rpm (zero torque)?

==&gt; Consider this Brushless Motor Efficiency calculator (<http://www.radiocontrolinfo.com/brushless-motor-efficiency/#2>)?

![](<Screen Shot 2018-04-20 at 20.37.21.png>)

==&gt; Also consider (Kt = 1/Kv \* 60/2\*pi where the 60/2\*pi is to convert rpm to rad/s)

3) Consider the Odrive site brushless motor settings (<https://docs.google.com/spreadsheets/d/12vzz7XVEK6YNIOqH0jAz51F5VUpc-lJEs3mmkWP1H4Y/edit#gid=0>)?

![](<Screen Shot 2018-04-20 at 21.19.37.png>)

4) Consider this thread on ODrive community site (<https://discourse.odriverobotics.com/t/where-does-the-formula-for-calculating-torque-come-from/1169/2>)?

> “The full formula is:  
> T=321√32π60IKv
- Factor 32 is from the brushless motor torque equation (eqn 2.30 of [this paper 2](https://pdfs.semanticscholar.org/e2be/948549aaf744c73b36d303cf7165041222f4.pdf)).
- Factor 1√3 is from converting line-line voltage (which is what is commonly used by hobby motor manufacturers in the determination of the Kv) to phase voltage (see [here](https://electronics.stackexchange.com/a/92826/7346)).
- Factor 2π60 is to convert from rpm to rad/s, which we need to do to get the torque constant from the voltage constant, due to the voltage constant being specified in units of RPM/V. (See [here](https://en.wikipedia.org/wiki/Motor_constants#Motor_Torque_constant)).



> "

...

{% endraw %}
