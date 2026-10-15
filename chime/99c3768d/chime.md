# Todo: DIY Metal Casting - Consider to design and build a small home Metal casting shop (foundry)?

```#99c3768d``` *As of 2018-12-11 23:32*

[mail plain/text](mail.txt)

{% raw %}
It seems to me it should be possible to actually build tools to perform small metal casting at home?

==&gt; Also see “Todo: Consider to buy Nichrome (heat wire) on Bauhaus (as heat thread for Proxxon 230)?"

1) Consider to build a small metal furnace?

==&gt; Consider to build and electric furnace (<https://www.youtube.com/watch?v=Cte_LSYflAE>)?

==&gt; It seems one way is to use a propane heated furnace (<https://www.amazon.com/Propane-Melting-Furnace-Silver-Copper/dp/B0108U6OTW/ref=sr_1_1?s=arts-crafts&ie=UTF8&qid=1511776683&sr=1-1&keywords=propane+furnace+steel>)?

==&gt; Men vissa verkar använda vanligt grillkol och en fläkt för att smälta t.ex. aluminium (<https://www.youtube.com/watch?v=qx86T1BD0hk>)?

...

2) Consider good youtube videos on metal casting?

==&gt; Consider “How to Make an Electric Foundry For Metal Casting - Part 1” (<https://www.youtube.com/watch?v=Cte_LSYflAE>)?

==&gt; He seems to use cheap “kiln heating elements” that is designed to be used up to 900 C (<https://www.ebay.com/p/Kiln-Furnace-Heating-Element-Resistance-Wire-220v-2500w/1531360203>)?

==&gt; He seems to be using heat-element made from Nichrome (<https://en.wikipedia.org/wiki/Nichrome>)?

==&gt; “Kiln” actually seems to be the term for a kind of owen (<https://en.wikipedia.org/wiki/Kiln>)?

> “*A kiln (/kɪln/ or /kɪl/,&#91;1&#93; originally pronounced "kill", with the "n" silent) is a thermally insulated chamber, a type of oven, that produces temperatures sufficient to complete some process, such as hardening, drying, or chemical changes. Kilns have been used for millennia to turn objects made from clay into pottery, tiles and bricks. Various industries use rotary kilns for pyroprocessing—to calcinate ores, to calcinate limestone to lime for cement, and to transform many other materials.*"

==&gt; Consider “DIY Electric Foundry Upgrades - 1200°C - Melting Copper” (<https://www.youtube.com/watch?v=p7uSGXR8NDs>)?

==&gt; It seems he used Kanthal heating thread (not “karafnol” as he seems to pronounce it (At 12:11 (<https://www.youtube.com/watch?v=p7uSGXR8NDs>) )?

==&gt; He seems to use thread with 33 Ohm resistance on 250V AC current (At 2:39 (<https://www.youtube.com/watch?v=p7uSGXR8NDs>) )?

![](<DIY Electric Foundry Upgrades - 1200°C - Melting Copper - Kanthal Thread Electrical charachetristics and design.png>)

==&gt; It seems if we use Elfa 1mm Kanthal thread we ([https://www.elfa.se/sv/motstandstrad-mm-72-ohm-kanthal-030211-kanthal-1mmo-17m/p/16080373?q=Kanthal+tråd&filter_Manufacturer=Kanthal&page=5&origPos=5&origPageSize=50&simi=88.11](https://www.elfa.se/sv/motstandstrad-mm-72-ohm-kanthal-030211-kanthal-1mmo-17m/p/16080373?q=Kanthal+tr%C3%A5d&filter_Manufacturer=Kanthal&page=5&origPos=5&origPageSize=50&simi=88.11))?

> > “Resistivitet 1.3 Ohm mm²/m @ +20°C  
> > Temperaturkoefficient 11...15 x 10/K  
> > Temperaturområde max. +1300 °C "

==&gt; At 1300 C the resistance per meter of this thread would be: R = 1,3 + 1,3\*(1300 - (273 + 20) K)\*150 Ohm/K (<https://sv.wikipedia.org/wiki/Temperaturkoefficient>)?

1,3(1 + 1007\*150) Ohm mm2/m = 1,3(1 + 151 000) … Ouups!

==&gt; From Sandviken data sheet (below) we read Kanthal D1 to have 1,450 Ohm mm2/m (Note values uses decimal point, not comma)?

> > R2 = R1 + R1\*alpha\*(T2 - T1)  
> > Rho_2\*(A/L) = Rho_1\*(A/L) + Rho_1\*(A/L)\*alpha\*(1300 - 293) &#91;Ohm&#93;  
> > Rho_2 = Rho_1 + Rho_1\*alpha\*(1300 - 293) &#91;Ohm m / mm2&#93;  
> > Rho_2 - Rho_1 = Rho_1\*alpha\*(1300 - 293) &#91;Ohm m / mm2&#93;  
> > alpha = (Rho_2 - Rho_1) / Rho_1\*(1300 - 293) &#91; / K&#93;  
> > alpha = (1,450 - 1,3) / 1,3\*1007 = 114 \* 10^-6 / K = 114 micro / K?

==&gt; Now compare with ELFA data sheet “Temperaturkoefficient 11...15 x 10/K “?

**==&gt; We are off my 10^6... **

==&gt; Anyhow, at 1300 C the resistance of1 m of 1mm2 thread would be R2 = 1,3\*1 mm2 / 1 m + 1,3\*1 mm2 / 1 m \* 114\*10^-6\*1007 = 1,3 + 0,14 = 1,45 Ohm.

==&gt; To have 33 Ohm (video calculation) we thus should use 33/1,45 = **23 m?**

...

==&gt; It seems we should go for heating elements from “Kanthal”, (<https://en.wikipedia.org/wiki/Kanthal_(alloy)> )?

> “**Kanthal** is the **trademark** for a family of **iron-chromium-aluminium (FeCrAl) alloys** used in a wide range of resistance and high-temperature applications. Kanthal FeCrAl alloys consist of mainly iron, chromium (20–30%) and aluminium (4–7.5 %). The first Kanthal FeCrAl alloy was developed by Hans von Kantzow in Hallstahammar, Sweden. The alloys are known for their ability to withstand high temperatures and having intermediate electric resistance. As such, it is frequently used in heating elements. The trademark Kanthal is owned by **Sandvik** Intellectual Property AB."

==&gt; Consider this pdf from Sandviken that lists alloys for electric heating elements /<https://www.kanthal.com/globalassets/kanthal-global/downloads/materials-in-wire-and-strip-form/resistance-heating-wire-and-strip/s-ka026-b-eng-2012-01.pdf>)?

![](<Kanthal resistance heating alloys – summary Maximum operating temperature per alloy.png>)

![](<Kanthal resistance heating alloys – summary - Resistivity vs. temperature.png>)

==&gt; NOTE: Vertical axes uses decimal-point (i.e., resistivity varies between 1,1 to 1,45 for Kanthal D)?

==&gt; It seems Kanthal wire is available on e-baye (<http://www.ebay.com/bhp/kanthal-wire>)?

==&gt; Det verkar som om Elfa säljer Kanthal-tråd ([https://www.elfa.se/search?q=Kanthal+tråd&filter_Manufacturer=Kanthal](https://www.elfa.se/search?q=Kanthal+tr%C3%A5d&filter_Manufacturer=Kanthal))?

==&gt; På Elfa kostar 17m 1mm Kanthal-tråd C.a 300 SEK ([https://www.elfa.se/sv/motstandstrad-mm-72-ohm-kanthal-030211-kanthal-1mmo-17m/p/16080373?q=Kanthal+tråd&filter_Manufacturer=Kanthal&page=5&origPos=5&origPageSize=50&simi=88.11](https://www.elfa.se/sv/motstandstrad-mm-72-ohm-kanthal-030211-kanthal-1mmo-17m/p/16080373?q=Kanthal+tr%C3%A5d&filter_Manufacturer=Kanthal&page=5&origPos=5&origPageSize=50&simi=88.11))?

==&gt; Det verkar som kanthal-tråd används i (diy) e-cigaretter (<https://www.elekcig.se/kanthal-trad>)?

==&gt; Consider “How To Make The Mini Metal Foundry” (<https://www.youtube.com/watch?v=hHD10DjxM1g>)?

==&gt; It seems a Furnace is the “oven” to melt the metal while a “foundry” is the whole factory for metal casting (<https://en.wikipedia.org/wiki/Foundry>)?

> “A foundry is a factory that produces metal castings..."

==&gt; På svenska det verkar heta “Hytta” (<https://sv.wikipedia.org/wiki/Hytta>)?

> “En hytta (inom metallurgin även masugn) är en smältugn för framställning av metaller eller glas. Termen hytta nyttjas även som benämning på smältugnen och omgivande byggnader vid järnbruk eller glasbruk. Inom bergshantering är skillnaden mellan hytta och masugn att det förstnämnda kan avse en smältugn för inte nödvändigtvis just järnmalm, utan även koppar-, eller silvermalm. Vid en masugn kan däremot endast tillverkning av tackjärn ske."

==&gt; Consider “Casting Brass | Sand Rammer - 3D Printed Pattern” (<https://www.youtube.com/watch?v=18gEaRdC0xY>)?

==&gt; Consider “Sand Casting Comparison Using Delft Clay and Petrobond” (<https://www.youtube.com/watch?v=icwWZnW5GmI>)?

==&gt; Överväg denna video som visar svenskar som ljuter motordelar (<https://www.youtube.com/watch?v=LESRiM09mdI>)?

==&gt; Men vissa verkar använda vanligt grillkol och en fläkt för att smälta t.ex. aluminium (<https://www.youtube.com/watch?v=qx86T1BD0hk>)?

…

3) Consider ways to 3D print the forms or moulds I can use for casting?

==&gt; It seems by 3D printing the shape to cast I can make the mould from Petro Bond (<https://www.youtube.com/watch?v=18gEaRdC0xY>)

4) Consider the materials I need to make the moulds?

==&gt; Consider this online shop for DIY metal casters ([https://www.dykast.com](https://www.dykast.com/))?

==&gt; It seems I can use metro bond sand to make a mould from the 3D printed shape to cast (

==&gt; Petro Bond sand seems to be available on Amazon (<https://www.amazon.com/Petrobond-Affordable-Alternative-Precious-Casting/dp/B00P032D0W>)?

==&gt; It seems to be sand mixed with some form of oil?

==&gt; It seems to be of larger grain size than Delft Clay (<https://www.youtube.com/watch?v=icwWZnW5GmI>)?

5) Consider where to buy the materials and tools to build my compact living metal casting shop equipment?

==&gt; Consider to study amazon metal melting kits like this one (<https://www.amazon.com/dp/B01N9CH4XV/ref=sspa_dk_detail_0?psc=1>)?

==&gt; It seems to be able to melt “ • Designed to melt around 2 to 5 ounces of gold”?

==&gt; It seems 1 ounce = 0.0283495231 kilograms?

==&gt; Thus, 5 ounces = 0,1417475 kg = 142 g?

==&gt; Consider to study this 4 Kg metal melting furnace (<https://www.amazon.com/Propane-Melting-Furnace-Silver-Copper/dp/B0108U6OTW/ref=sr_1_1?s=arts-crafts&ie=UTF8&qid=1511776683&sr=1-1&keywords=propane+furnace+steel>)?

6) Consider to apply some CNC micro controlled automation for the metal casting framework?

==&gt; What steps in the metal casting process can we automate using micro controlled motors and tools?

==&gt; Can we automate the metal furnace (temperature control)?

==&gt; It seems the normal sensors are Thermocouple sensor (<https://en.wikipedia.org/wiki/Thermocouple>)?

> > “*A **thermocouple** produces a temperature-dependent voltage as a result of the **thermoelectric** effect*”  
> > “**Type B, S, R and K** thermocouples are used extensively in the steel and iron industries to monitor temperatures and chemistry throughout the **steel making process**"

==&gt; Consider this “K-type Thermocouple Sensor 215mm for Ceramic Kiln Furnace Digital Thermometers Mayitr 1300C High Temperature Measuring Tools" (<https://www.aliexpress.com/item/K-type-Thermocouple-Sensor-215mm-for-Ceramic-Kiln-Furnace-Digital-Thermometers-Mayitr-1300C-High-Temperature-Measuring/32829575267.html?spm=2114.search0306.3.10.WMbp8l&ws_ab_test=searchweb0_0,searchweb201602_0_10152_10151_10557_10539_10594_10596_10595_10059_10312_10314_10534_10313_10533_10084_100031_10083_10107_10307_10604_10603_10341_10065_10142_10340_10068_10343_10541_10342_10562_10301_10345_10103_10344_10303,searchweb201603_0,ppcSwitch_0&algo_pvid=26b7a25e-ef10-4918-b62c-615510fdb4e3&algo_expid=26b7a25e-ef10-4918-b62c-615510fdb4e3-4>)?

==&gt; Consider this Arduino shield for Thermocouple sensors (<https://www.adafruit.com/product/269>)?

> > “ • -200°C to **+1350°C** output in 0.25 degree increments - note that **K thermocouples** have about ±2°C to ±6°C accuracy"

==&gt; Consider this advanced high precision thermocouple amplifier (

> > “This converter communicates over 4-wire SPI and can interface with **any K, J, N, R, S, T, E, or B type** thermocouple.”  
> > “-210°C to **+1800°C** output in 0.0078125° resolution - note that many thermocouples have about ±2°C to ±6°C accuracy or worse"

==&gt; Elfa verkar sälja termoelement (eng: thermocouples) K-typ up till 1200 C för 480 SEK ([https://www.elfa.se/sv/mantlat-termoelement-type-jumo-00056813/p/17669054?q=\*&sort=Price:asc&filter_Category3=Termoelement&filter_Buyable=1&filter_Mätområde=-200...%2B1200+°C&page=1&origPos=15&origPageSize=50&simi=97.0](https://www.elfa.se/sv/mantlat-termoelement-type-jumo-00056813/p/17669054?q=*&sort=Price:asc&filter_Category3=Termoelement&filter_Buyable=1&filter_M%C3%A4tomr%C3%A5de=-200...%2B1200+%C2%B0C&page=1&origPos=15&origPageSize=50&simi=97.0))?

...

...

==&gt; Consider IR temperature sensor as the one in this IR sensor temperature kit based on Melexis MLX90614ESF-BAA (<https://www.sparkfun.com/products/9570>)?

==&gt; Melexis MLX90614ESF-BAA seems to be available from Elfa from 144 SEK (<https://www.elfa.se/sv/temperatursensor-to-39-melexis-mlx90614esf-baa/p/17321573?channel=b2b&price_afd=144&gclid=Cj0KCQiAjO_QBRC4ARIsAD2FsXPDVHNdva57LtTA8th1VFZssK5DIW8vkGbDyPbnh5VPuH5wgqsHWJkaAvhjEALw_wcB&gclsrc=aw.ds>)?

==&gt; BUT: Melexis MLX90614ESF-BAA only measures up to 380 C!!

==&gt; Can we automate the melted metal movement (to and from furnace, to and from mould…)?

==&gt; Can we automate pouring of metal into mould?

...

7) consider the Elfa sortiment of “Resistor Wire”?

==&gt; It seems Elfa does not rate its Nichrome thread for any specific temperature range?

![](<Screenshot 2018-12-11 at 23.18.34.png>)

==&gt; Consider to compare with Bauhaus 0,2 mm Nichrome thread (Proxxon Thermocut branded) 12 g for 90 SEK (<https://www.bauhaus.se/trad-proxxon-for-thermocut-230-e-30m.html>)?

![](<Screenshot 2018-12-11 at 23.23.27.png>)

==&gt; This is 7.50 / g

==&gt; Elfa 0,5 mm Nichrome thread sells for 413 SEK (inc. VAT) for 100 g = 4,13 SEK / g.

NOTE: It seems Elfa NiChrome threads are “half price” but 10 times the amount (e.g., 0,5 instead of 0,2 mm thread)...

==&gt; It seems all resistor wire rated for up to 1300 degrees C are of FeCrAl (branded Kanthal) ([https://www.elfa.se/en/cable-wire/equipment-wires/resistor-wire/c/cat-DNAV_PL_091206?q=\*&sort=Price%3Aasc&filter_Category3=Motståndstrådar&filter_Category3=Resistor+Wire&filter_Temperaturområde=max.+%2B1300+°C&filter_Buyable=1&filter_Temperature+range=max.+%2B1300+°C](https://www.elfa.se/en/cable-wire/equipment-wires/resistor-wire/c/cat-DNAV_PL_091206?q=*&sort=Price:asc&filter_Category3=Motst%C3%A5ndstr%C3%A5dar&filter_Category3=Resistor+Wire&filter_Temperaturomr%C3%A5de=max.++1300+%C2%B0C&filter_Buyable=1&filter_Temperature+range=max.++1300+%C2%B0C))?

![](<Screenshot 2018-12-11 at 23.12.52.png>)

==&gt; Is seems resistor wire rated for up to 600 degrees C use of Cu-Ni?

![](<Screenshot 2018-12-11 at 23.16.53.png>)

…

Consider to delve deeper into this idea of building and using a small metal casting system for my compact living maker space?

{% endraw %}
