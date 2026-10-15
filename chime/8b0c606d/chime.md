# Todo: Consider to understand how to design and build my own Brushless DC Motor speed controller driver (for my ducted fan vacuum motor and other motor applications)?

```#8b0c606d``` *As of 2018-09-09 19:43*

[mail plain/text](mail.txt)

{% raw %}
It seems it could be a good (or at least very interesting) idea to understand how I could be able to design and build my own cost effective Brushless Motor speed controller driver?

==&gt; Also see “[Todo: Consider to learn and document how to use the Ducted Fan ESC to drive the fan from some suitable power source?](../28850883/chime.md)"

1) Consider this digikey page on brushless motor driver and control (<https://www.digikey.com/en/articles/techzone/2016/dec/how-to-power-and-control-brushless-dc-motors>)?

![](<Screen Shot 2018-09-09 at 19.27.58.png>)

==&gt; Consider Texas Instrument MSP430 for sensored (hall effect feed-back) BL control (<http://www.ti.com/lit/an/slaa503/slaa503.pdf>)?

![](<Screen Shot 2018-09-09 at 19.25.48.png>)

==&gt; It seems the technique of using magnetic censoring as feedback is called “Anisotropic Magnetoresistive (AMR)”?

> *The ADA4571 uses anisotropic magnetoresistive (**AMR**) technology. A typical implementation is to mount a **diametrically magnetized disc** on the end of the BLDC motor’s shaft (see Figure 7). The disc’s magnetic field passes through the plane of the sensor and the rotor angle is determined without contact between the mechanical and electrical components.*

![](<Screen Shot 2018-09-09 at 19.30.49.png>)

==&gt; It seems the ADA4571 is a sensor for an ARM system (<http://www.analog.com/media/en/technical-documentation/data-sheets/ADA4571.pdf>)?

![](<Screen Shot 2018-09-09 at 19.41.20.png>)

2) Consider Microchip components for sensorless BL motor speed control?

==&gt; It seems Great Scott suggests to use the Microchip MCP8026 chip and MOSFET drivers (<https://youtu.be/NXkLydhRvS0?t=569>)?

![](<Screen Shot 2018-09-09 at 19.08.36.png>)

==&gt; The Microchip MCP8025A family chips seems to live here (<https://www.microchipdirect.com/product/MCP8025A>)?

![](<Screen Shot 2018-09-09 at 19.13.23.png>)

==&gt; Consider the Mouser page on understanding brushless motor speed control (<https://eu.mouser.com/new/microchip/microchip-brushless-dc-motors/>)?

![](<Screen Shot 2018-09-09 at 19.01.14.png>)

> *For Single-Chip Drivers for BLDC Motor Control Start with the: MTD6501  
> For MOSFET Gate Drivers for BLDC Motor Control Start with the: MCP8024*

==&gt;

{% endraw %}
