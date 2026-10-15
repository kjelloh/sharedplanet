# Todo: Consider to experiment with and understand the "EGS002 Sinusoid Inverter Driver Board"

```#f33ae727``` *As of 2018-11-18 17:36*

[mail plain/text](mail.txt)

{% raw %}
It seems it could be fund to see if I can use the EGS002 Sinusoid Inverter Driver Board I bought on eBay from China to build a pure sine inverter or a single phase motor speed controller?

1) Consider the data sheets of the EGS002 and the onboard components?

==&gt; The data sheet of the EGS002 driver board seems to live here (<https://www.egmicro.com/download/EGS002_manual_en.pdf>)?

![](<Screenshot 2018-11-18 at 17.16.00.png>)

==&gt; The onboard IR2110/IR2113 high voltage, high speed power MOSFET and IGBT driver data sheet seems to live here (<https://www.infineon.com/dgdl/ir2110.pdf?fileId=5546d462533600a4015355c80333167e>)?

![](<Screenshot 2018-11-18 at 17.13.59.png>)

==&gt; The EG8010 Single Phase Sinusoid Inverter ASIC data sheet seems to live here (<https://www.lz2gl.com/data/power-inverter-3kw/eg8010_datasheet_en.pdf>)?

![](<Screenshot 2018-11-18 at 17.15.36.png>)

2) Consider Greatscott youtube video “Does it suck? Chinese DIY Pure Sine Wave Inverter || Sinusoidal PWM (SPWM) Tutorial” (<https://www.youtube.com/watch?v=Dn2PFebi2ww>)?

==&gt; He seem to argue that the EGS002 is NOT really great to use for a decent pure sine inverter?

> “ I will create a DIY pure sine wave inverter with it and show you why it is not really a decent alternative to commercial inverters."

==&gt; He seems to use the bare board “EGP1000W Pure Sine Wave Inverter Power Board PCB Bare Board” like this one on AliExpress (<https://www.aliexpress.com/item/1x-EGP1000W-Pure-Sine-Wave-Inverter-Power-Board-PCB-Bare-Board-New/32704045448.html>)?

![](<Screenshot 2018-11-18 at 17.29.13.png>)

==&gt; It seems GreatScott did not achieve a tuned 1000W inverter due to the lack of a good english user manual (and had to reverse engineer and guess)?

…

…

Consider to delve deeper into this circuit to see if I can find information on how to use the EGS002 in a pure sine inverter with acceptable performance?

{% endraw %}
